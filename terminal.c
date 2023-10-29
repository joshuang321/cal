typedef
struct
{
	char *start;
} SourceRange;

typedef
struct
{
	char *buffer;
	char *start;
	char *end;
} BufferRange;

typedef
struct
{
	int x;
	int y;
} Cursor;

typedef
struct
{
	int w;
	int h;
} Font;

typedef
struct
{
	BufferRange buf;
	SourceRange src;
    
	Cursor cursor;
	Font fnt;
    
	int offset;
	int x;
	int y;
	int w;
	int h;
	int line;
} Terminal;


#define ALLOC_SZ 8912

void
InitTerminal(Terminal *term, HWND hWnd, int x, int y, int w, int h)
{
	HDC hdc=GetDC(hWnd);
	TEXTMETRICA tm;
	GetTextMetricsA(hdc, &tm);
	term->fnt.w = tm.tmAveCharWidth;
	term->fnt.h = tm.tmHeight;
    
	term->x =x;
	term->y =y;
	term->w =w;
	term->h =h;
	term->buf.buffer =VirtualAlloc(NULL, ALLOC_SZ, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
	assert(term->buf.buffer);
	term->buf.start =term->buf.buffer;
	term->buf.end =term->buf.buffer;
    
	term->src.start =term->buf.buffer;
	term->cursor.x =0;
	term->cursor.y =0;
	ReleaseDC(hWnd, hdc);
}

void
UnInitTerminal(Terminal *term)
{
	VirtualFree(term->buf.buffer, 0, MEM_FREE);
}

char *
IncrementCircular(char *baseptr, char *ptr)
{
	if (++ptr == (baseptr +ALLOC_SZ))
	{
		ptr =baseptr;
	}
	return ptr;
}

char *
DecrementCircular(char *baseptr, char *ptr)
{
	if (--ptr == (baseptr-1))
	{
		ptr =baseptr +ALLOC_SZ-1;
	}
	return ptr;
}

void
UpdateTerminal(Terminal *term, int w, int h)
{
    int width = w/term->fnt.w;
	BufferRange buf_cpy =term->buf;
    int line=0;
    int count=0;
    
	while (line !=term->line)
	{
		buf_cpy.start = IncrementCircular(buf_cpy.buffer, buf_cpy.start);
        count++;
		while (*buf_cpy.start != '\n'
               && count <width)
        {
            count ++;
			buf_cpy.start = IncrementCircular(buf_cpy.buffer, buf_cpy.start);
		}
        if (*buf_cpy.start =='\n')
        {
            buf_cpy.start = IncrementCircular(buf_cpy.buffer, buf_cpy.start);
        }
        count=0;
		line++;
	}
    
	term->w =w;
    term->h =h;
}

void
IncrementBuffer(Terminal *term)
{
    int width =term->w /term->fnt.w;
	term->buf.start = IncrementCircular(term->buf.buffer, term->buf.start);
    int count =1;
    
	while (*term->buf.start != '\n'
           && count <width)
	{
        count++;
		term->buf.start = IncrementCircular(term->buf.buffer, term->buf.start);
	}
    if (*term->buf.start =='\n')
    {
        term->buf.start = IncrementCircular(term->buf.buffer, term->buf.start);
    }
	term->line--;
}

void
AddToBuffer(Terminal *term, char c)
{
	char *buf_start =term->buf.start;
	char *buf_end =term->buf.end;
    
	*buf_end =c;
    
	term->buf.end =IncrementCircular(term->buf.buffer, term->buf.end);
	if (term->buf.end ==term->buf.start)
	{
		IncrementBuffer(term);
		if (buf_start ==term->src.start)
		{
			term->src.start =term->buf.start;
		}
	}
}

void
IncrementLine(Terminal *term)
{
	term->src.start = IncrementCircular(term->buf.buffer, term->src.start);
	int count= term->w /term->fnt.w;
	int c=0;
	while (c++ != count
           && *term->src.start != '\n')
	{
		term->src.start = IncrementCircular(term->buf.buffer, term->src.start);
	}
	term->src.start = IncrementCircular(term->buf.buffer, term->src.start);
	term->line++;
}

void
AddLine(Terminal *term)
{
	term->cursor.x =0;
    
	term->cursor.y += term->fnt.h;
	if ((term->cursor.y +term->fnt.h) > term->h)
	{
		term->offset += term->h - term->cursor.y  -term->fnt.h;
		term->cursor.y = term->h -term->fnt.h;
        
		if ((-term->offset) > term->fnt.h)
		{
			term->offset += term->fnt.h;
			IncrementLine(term);
		}
	}
}

void
InputTermChar(Terminal *term, char c)
{
    if (c == '\n')
    {
        AddLine(term);
    }
    AddToBuffer(term, c);
    term->cursor.x += term->fnt.w;
}

void
InputTermBuffer(Terminal *term, char *str, int c)
{
    if (c!=-1)
    {
        while (c--)
        {
            InputTermChar(term, *str++);
        }
    }
    else
    {
        while (*str)
        {
            InputTermChar(term, *str++);
        }
    }
}

void
InputTerminal(Terminal *term, char *str, int c)
{
    static char _buf[256];
    c=snprintf(_buf, 256, ">> %.*s\n",c, str);
    InputTermBuffer(term, _buf, c);
#if 0
    if (ret.type == RET_VAL)
    {
        c =snprintf(_buf, 256, "%f\n", ret.val);
        InputTermBuffer(term, _buf, c);
    }
    else if (ret.type ==RET_ERROR)
    {
        c =GetErrorDesc(ret.error, _buf);
        InputTermBuffer(term, _buf, c);
    }
#endif
}

void
PaintTerminal(HDC hdc, Terminal *term)
{
    RECT rcFill = { term->x , term->y, term->x +term->w, term->y +term->h };
    FillRect(hdc, &rcFill, (HBRUSH)GetStockObject(BLACK_BRUSH));
    
    int prevMode=SetBkMode(hdc, TRANSPARENT);
    int prevColor =SetTextColor(hdc, RGB(255, 255, 255));
    SourceRange src_cpy =term->src;
    Cursor cursor = { .x = term->x, .y =term->y+term->offset };
    
    
    while (term->buf.end !=src_cpy.start
           && cursor.y < term->h)
    {
        if (*src_cpy.start =='\n'
            || (cursor.x +term->fnt.w) > term->w)
        {
            cursor.x =0;
            cursor.y += term->fnt.h;
        }
        if (*src_cpy.start !='\n')
        {
            TextOutA(hdc, cursor.x, cursor.y, src_cpy.start, 1);
            cursor.x += term->fnt.w;
        }
        src_cpy.start =IncrementCircular(term->buf.buffer, src_cpy.start);
    }
    SetBkMode(hdc, prevMode);
    SetTextColor(hdc, prevColor);
}
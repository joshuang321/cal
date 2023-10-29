typedef
struct
{
    int x;
    int y;
} Pos;

typedef
struct
{
    HDC hdc;
    HBITMAP hbitmap;
    HFONT hfont;
} Draw;

typedef
struct
{
    Pos center;
    Draw draw;
    Terminal term;
    Lang *lang;
    SynTree *synTree;
    
    int w;
    int h;
    HWND edit;
    HWND button;
} App;

void
InitDraw(Draw *draw, HWND hWnd, int w, int h)
{
    RECT rc;
    HDC hdc =GetDC(hWnd);
    GetClientRect(hWnd, &rc);
    
    assert(hdc);
    draw->hdc =CreateCompatibleDC(hdc);
    draw->hbitmap =(HBITMAP)SelectObject(draw->hdc, CreateCompatibleBitmap(hdc, rc.right, rc.bottom));
    draw->hfont =(HFONT)SelectObject(draw->hdc, CreateFontA(-MulDiv(11, GetDeviceCaps(hdc, LOGPIXELSY), 72), 0 , 0, 0, FW_REGULAR, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_MODERN, "Courier New"));
    ReleaseDC(hWnd, hdc);
}

void
UnInitDraw(Draw *draw)
{
    DeleteObject(SelectObject(draw->hdc, draw->hbitmap));
    DeleteObject(SelectObject(draw->hdc, draw->hfont));
    DeleteDC(draw->hdc);
}

void
UpdateDraw(Draw *draw, int w, int h)
{
    DeleteObject(SelectObject(draw->hdc, CreateCompatibleBitmap(draw->hdc, w, h)));
}

void
ResizeWindows(App *app)
{
    UpdateDraw(&app->draw, app->w, app->h);
    UpdateTerminal(&app->term, app->w, app->h);
    MoveWindow(app->edit, 0, 0, app->w - 100, 25, TRUE);
    MoveWindow(app->button, app->w-100, 0, 100, 25, TRUE);
}

void
PaintWindow(HWND hWnd, App *app, HDC hdc)
{
    PatBlt(app->draw.hdc, 0, 0, app->w, app->h, WHITENESS);
    PaintTerminal(app->draw.hdc, &app->term);
    //PaintSynTree(app->draw.hdc, app->synTree, 0, app->term.y+app->term.h, app->w, app->h);
    BitBlt(hdc, 0, 0, app->w, app->h, app->draw.hdc, 0, 0, SRCCOPY);
}

App *
InitApp(void)
{
    App *app =VirtualAlloc(NULL, sizeof(App), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    app->center.x =0;
    app->center.y =0;
    app->lang =InitLang();
    app->synTree =NULL;
    return app;
}

void
UnInitApp(App* app)
{
    UnInitTerminal(&app->term);
    UnInitLang(app->lang);
    VirtualFree(app, 0, MEM_FREE);
}
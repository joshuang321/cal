#include <Windows.h>
#include <assert.h>
#include <CommCtrl.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include "lang_v2.h"
#include "lang_v2_functions.c"
#include "lang_v2_signatures.c"

Lang *
InitLang(void)
{
    Lang *lang =(Lang *)VirtualAlloc(NULL, sizeof(Lang), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    
    lang->allocCount =0;
    return lang;
}

void
UnInitLang(Lang *lang)
{
    VirtualFree(lang, 0, MEM_FREE);
}

_u32
GetHash(VString name)
{
    _u32 offs=0;
    _u32 hash=0;
    while (offs < MAX_VAR_NAME_LEN
           && name[offs])
    {
        hash =hash<<2 +name[offs++];
    }
    return hash;
}

HshNode *
NewHshNode(Lang *lang)
{
    return &lang->nodes[lang->allocCount++];
}

void
AddSynTreeChild(SynTree *parent, SynTree *child)
{
    child->next =parent->children;
    parent->children =child;
}

_bool
IsVStringEqual(VString str0, VString str1)
{
    _u32 count=0;
    while (str0[count]
           && str1[count]
           && str0[count] ==str1[count])
    {
        count++;
    }
    
    _bool result =(str0[count]==str1[count]);
    return result;
}

void
CopyVString(VString dest, VString src)
{
    while (*dest++ =*src++);
}

void
CopyVar(Var *dest, Var *src)
{
    dest->vtype =src->vtype;
    switch (src->vtype)
    {
        case VT_CONST:
        dest->_const =src->_const;
        break;
        case VT_VAR:
        CopyVString(dest->varName, src->varName);
        break;
    }
}

void
CopyVariable(_Variable *dest, _Variable *src)
{
    CopyVString(dest->name, src->name);
    dest->data =src->data;
}

void
StoreVariable(Lang *lang, _Variable variable)
{
    _u32 hashIdx =GetHash(variable.name);
    
    if (lang->varTbl[hashIdx])
    {
        HshNode **phshNode =&lang->varTbl[hashIdx];
        while (*phshNode)
        {
            if (IsVStringEqual((*phshNode)->var.name, variable.name))
            {
                (*phshNode)->var.data =variable.data;
                phshNode =NULL;
                return;
            }
            phshNode = &(*phshNode)->next;
        }
        HshNode *newNode =NewHshNode(lang);
        CopyVariable(&newNode->var, &variable);
        *phshNode =newNode;
    }
    else
    {
        HshNode *newNode =NewHshNode(lang);
        CopyVariable(&newNode->var, &variable);
        lang->varTbl[hashIdx] =newNode;
    }
}

_Variable *
GetVariable(Lang *lang, VString varName)
{
    _u32 hashIdx =GetHash(varName);
    HshNode *node =lang->varTbl[hashIdx];
    _Variable *result=NULL;
    
    while (node)
    {
        if (IsVStringEqual(node->var.name, varName))
        {
            result =&node->var;
            break;
        }
        node =node->next;
    }
    return result;
}

char *
OpToString(char op)
{
    static char *strsToOps[] =
    {
        "OP_NONE",
        "OP_ADD",
        "OP_SUB",
        "OP_MUL",
        "OP_DIV",
        "OP_PWR",
        "OP_SR",
        "OP_SL",
        "OP_BAND",
        "OP_AND",
        "OP_BOR",
        "OP_OR",
        "OP_CMT",
        "OP_CLT",
        "OP_CMTEQ",
        "OP_CLTEQ",
        "OP_CEQ",
        "OP_CNEQ",
        "OP_EQ",
        "OP_ASG",
        "OP_FUNC",
        "OP_OBRAK",
        "OP_CBRAK"
    };
    return strsToOps[op];
}

char
CosumeOperand(const char *statement, int *offs)
{
    char result=OP_NONE;
    int offset =*offs;
    switch (statement[offset])
    {
        case '+': result =OP_ADD; break;
        case '-': result= OP_SUB; break;
        case '*': result=OP_MUL; break;
        case '/': result=OP_DIV; break;
        case '^': result=OP_PWR; break;
        case '<': offset++;
        switch (statement[offset])
        {
            case '<': result=OP_SR;break;
            case '=': result=OP_CLTEQ; break;
            default: offset--; result=OP_CLT;break;
        }
        break;
        
        case '>':offset++;
        switch (statement[offset])
        {
            case '>': result=OP_SL;break;
            case '=': result=OP_CMTEQ; break;
            default: offset--; result=OP_CMT;break;
        }
        break;
        
        case '&':
        if (statement[offset+1] =='&')
        {
            result =OP_AND;
            offset++;
        }
        else {
            result =OP_BAND;
        }
        break;
        
        case '|':
        if (statement[offset+1] =='|')
        {
            result =OP_OR;
            offset++;
        }
        else {
            result =OP_BOR; 
        }
        break;
        case '=':
        if (statement[offset+1] =='=')
        {
            result =OP_CEQ;
            offset++;
        }
        else {
            result =OP_NONE;
        }
        break;
        case '!':offset++;
        if (statement[offset] =='=')
        {
            result=OP_CNEQ;
        }
        else {
            result=OP_NONE;
        }
        break;
        case ':':
        if (statement[offset+1] =='=')
        {
            offset++;
            result =OP_ASG;
        }
        else {
            result =OP_NONE;
        }
        break;
        case '(': result=OP_OBRAK;break;
        case ')': result=OP_CBRAK;break;
        case ',': result=OP_COMMA;break;
    }
    if (result!=OP_NONE)
    {
        offset++;
    }
    *offs=offset;
    return result;
}

int GetOpPred(char op)
{
    int result;
    switch (op)
    {
        case OP_FUNC: result =0; break;
        case OP_OBRAK: result =0;break;
        case OP_ASG: result=1;break;
        
        case OP_OR: result =2;break;
        case OP_AND: result =3; break;
        case OP_BOR: result =4; break;
        case OP_BAND: result =5; break;
        
        case OP_CEQ:
        case OP_CNEQ: result =6; break;
        
        case OP_CMT:
        case OP_CMTEQ:
        case OP_CLT:
        case OP_CLTEQ: result =7; break;
        
        case OP_SL:
        case OP_SR: result =8; break;
        
        case OP_ADD:
        case OP_SUB: result=9; break;
        
        
        case OP_DIV:
        case OP_MUL: result=10; break;
        
        case OP_PWR: result=11; break;
    }
    return result;
}

int GetOpPred2(char op2)
{
    int result;
    switch (op2)
    {
        case OP_OBRAK:
        result =13;
        break;
        case OP_FUNC:
        case OP_COMMA:
        result =12;
        break;
        
        case OP_CBRAK:
        result=1;
        break;
        
        case OP_PWR:
        result=GetOpPred(op2);
        result++;
        break;
        
        default:
        result=GetOpPred(op2);
        break;
    }
    return result;
}

int GetOpArgCount(char op)
{
    int result;
    result=2;
    
    return result;
}

_bool 
IsBiggerOrEqPred(char op0, char op1)
{
    _bool result =(GetOpPred(op0) >=GetOpPred2(op1));
    return result;
}

VarResult
CosumeConstant(char *statement, int *offs)
{
    VarResult result ={.var.vtype =VT_CONST, .var._const.type=TREAL };
    char *endptr;
    result.var._const.real =strtod(&statement[*offs], &endptr);
    if (statement==endptr)
    {
        result.success =0;
        result.err.type =ERR_CONST;
        result.err.loc =statement;
    }
    else
    {
        result.success =1;
        *offs += endptr-&statement[*offs];
    }
    return result;
}

_bool
CharInStr(char *str, char c)
{
    while (*str
           && *str !=c)
    {
        str++;
    }
    _bool result =(*str !='\0');
    return result;
}

VarResult
CosumeVariable(char *statement, int *offs, int cOffset)
{
    VarResult result={ .var.vtype =VT_VAR };
    
    char *illegal=" =-+*$#@!^&():\'\"<>?,./;\\|}{[]-";
    int offset =*offs;
    int c=0;
    
    while (cOffset !=offset
           && statement[offset]
           && !CharInStr(illegal, statement[offset]))
    {
        result.var.varName[c++] =statement[offset++];
    }
    result.var.varName[c]='\0';
    
    if (offset == *offs)
    {
        result.success =0;
        result.err.type = ERR_VAR;
        result.err.loc =&statement[offset];
    }
    else
    {
        *offs =offset;
        result.success =1;
    }
    
    return result;
}

void
EatWhitespace(char *statement, int *offs)
{
    int offset =*offs;
    while (statement[offset++] ==' ');
    *offs =offset-1;
}

int
GetSyntaxHint(char c)
{
    char *opChars ="!:=-+*/^&|()<>.-,";
    int result=H_NONE;
    if (c >= '0'
        && c <= '9')
    {
        result=H_CONST;
    }
    else if (c == ' ')
    {
        result=H_WSPACE;
    }
    else if (CharInStr(opChars, c))
    {
        result =H_OP;
    }
    else
    {
        result=H_VAR;
    }
    return result;
}

_bool
PopNumVars(Lang *lang, SynTree *parent, StackContext *cxt, char *statement, int numVars)
{
    _bool result;
    while (numVars--
           && cxt->vCount!=-1)
    {
        SynTree *child;
        if (lang->varStk[cxt->vCount].vtype !=VT_SYNTREE)
        {
            child =&lang->synTrees[cxt->synTreeAllocated++];
            child->children =NULL;
            child->next=NULL;
            child->stype =ST_VAR;
            CopyVar(&child->var, &lang->varStk[cxt->vCount--]);
        }
        else
        {
            child =(SynTree *)lang->varStk[cxt->vCount--].synTree;
        }
        AddSynTreeChild(parent, child);
    }
    result =numVars==-1;
    
    lang->varStk[++cxt->vCount].synTree =(void *)parent;
    lang->varStk[cxt->vCount].vtype =VT_SYNTREE;
    
    return result;
}

_bool
PopOperand(Lang *lang, StackContext *cxt, char *statement)
{
    _bool result;
    
    char op1 =lang->opStk[cxt->oCount--];
    int opArgCount =GetOpArgCount(op1);
    SynTree *parent=&lang->synTrees[cxt->synTreeAllocated++];
    
    parent->op =op1;
    parent->stype =ST_OP;
    parent->children =NULL;
    parent->next =NULL;
    
    result =PopNumVars(lang, parent, cxt, statement, opArgCount);
    
    return result;
}

void
PushOperand(Lang *lang, StackContext *cxt, char *statement, char op)
{
    while (cxt->oCount!=-1
           && IsBiggerOrEqPred(lang->opStk[cxt->oCount], op))
    {
        if (!PopOperand(lang, cxt, statement))
        {
            break;
        }
    }
    if (op !=OP_CBRAK
        && op!=OP_COMMA)
    {
        lang->opStk[++cxt->oCount] =op;
    }
    else if (op ==OP_CBRAK)
    {
        --cxt->oCount;
    }
}

SyntaxResult
BuildSyntaxTree(Lang *lang, char *statement, int c)
{
    SyntaxResult result ={.success=1};
    VarResult varResult ={0};
    Var var;
    int hint;
    int prevState=H_NONE;
    
    StackContext stkcxt =
    {
        .oCount=-1,
        .vCount=-1,
        .offset =0,
        .ofCount=-1,
        .synTreeAllocated=0
    };
    
    while (stkcxt.offset <c)
    {
        hint =GetSyntaxHint(statement[stkcxt.offset]);
        switch (hint)
        {
            case H_CONST:
            if (prevState !=H_OP
                && prevState !=H_NONE)
            {
                result.success =0;
                result.err.type =ERR_CONST;
                result.err.loc =&statement[stkcxt.offset];
                goto BuildSynTree_Exit;
            }
            varResult =CosumeConstant(statement, &stkcxt.offset);
            if (varResult.success)
            {
                CopyVar(&lang->varStk[++stkcxt.vCount], &varResult.var);
            }
            prevState =hint;
            break;
            
            case H_OP:
            if (prevState ==H_NONE)
            {
                result.success =0;
                result.err.type =ERR_OPERAND;
                result.err.loc =&statement[stkcxt.offset-1];
                goto BuildSynTree_Exit;
            }
            char op=CosumeOperand(statement, &stkcxt.offset);
            if (op==OP_NONE)
            {
                result.success =0;
                result.err.type =ERR_OPERAND;
                result.err.loc =&statement[stkcxt.offset-1];
                goto BuildSynTree_Exit;
            }
            else if (op ==OP_COMMA
                     && stkcxt.ofCount==-1)
            {
                result.success =0;
                result.err.type =ERR_OPERAND;
                result.err.loc =&statement[stkcxt.offset-1];
                goto BuildSynTree_Exit;
            }
            else if (op ==OP_OBRAK)
            {
                if (prevState ==H_CONST)
                {
                    PushOperand(lang, &stkcxt, statement, OP_MUL);
                }
                else if (prevState ==H_VAR)
                {
                    stkcxt.varOffsets[++stkcxt.ofCount] =stkcxt.vCount;
                    PushOperand(lang, &stkcxt, statement, OP_FUNC);
                }
            }
            PushOperand(lang, &stkcxt, statement, op);
            
            if (op ==OP_CBRAK
                && lang->opStk[stkcxt.oCount] ==OP_FUNC)
            {
                int numVars =stkcxt.vCount- stkcxt.varOffsets[stkcxt.ofCount--]+1;
                SynTree *parent=&lang->synTrees[stkcxt.synTreeAllocated++];
                
                parent->op =OP_FUNC;
                parent->stype =ST_OP;
                parent->children =NULL;
                parent->next =NULL;
                
                PopNumVars(lang, parent, &stkcxt, statement, numVars);
                
                stkcxt.oCount--;
            }
            prevState =(op ==OP_CBRAK) ? H_CONST :hint;
            break;
            
            case H_VAR:
            if (prevState ==H_CONST)
            {
                PushOperand(lang, &stkcxt, statement, OP_MUL);
                if (!result.success)
                {
                    goto BuildSynTree_Exit;
                }
            }
            else if (prevState !=H_OP
                     && prevState !=H_NONE)
            {
                result.success =0;
                result.err.type =ERR_CONST;
                result.err.loc =&statement[stkcxt.offset];
                goto BuildSynTree_Exit;
            }
            varResult =CosumeVariable(statement, &stkcxt.offset, c);
            if (varResult.success)
            {
                CopyVar(&lang->varStk[++stkcxt.vCount], &varResult.var);
            }
            prevState =hint;
            break;
            
            case H_WSPACE:
            EatWhitespace(statement, &stkcxt.offset);
            break;
        }
    }
    BuildSynTree_Exit:
    if (result.success)
    {
        while (stkcxt.oCount!=-1
               && stkcxt.vCount !=-1)
        {
            if (lang->opStk[stkcxt.oCount] ==OP_OBRAK)
            {
                result.success =0;
                result.err.type =ERR_OPERAND;
                result.err.loc =&statement[stkcxt.offset-1];
                break;
            }
            if (!PopOperand(lang, &stkcxt, statement))
            {
                result.success =0;
                result.err.type =ERR_OPERAND;
                result.err.loc =&statement[stkcxt.offset-1];
            }
        }
        if (result.success
            && stkcxt.vCount !=-1)
        {
            if (lang->varStk[stkcxt.vCount].vtype !=VT_SYNTREE)
            {
                result.tree =&lang->synTrees[stkcxt.synTreeAllocated++];
                result.tree->stype =ST_VAR;
                result.tree->var =lang->varStk[stkcxt.vCount--];
            }
            else
            {
                result.tree =lang->varStk[stkcxt.vCount--].synTree;
            }
            if (stkcxt.vCount !=-1)
            {
                result.success =0;
                result.err.type =ERR_VAR;
                result.err.loc =&statement[stkcxt.offset-1];
            }
        }
    }
    return result;
}

void
DrawRectangledText(HDC hdc, char *str, int slen, int x, int y, SIZE *stringSize)
{
    GetTextExtentPoint32A(hdc, str, slen, stringSize);
    stringSize->cx+=10;
    stringSize->cy+=10;
    
    Rectangle(hdc, x, y, x+stringSize->cx, y+stringSize->cy);
    TextOutA(hdc, x+5, y+5, str, slen);
}

void
PaintSynTree(HDC hdc, SynTree *tree, int x, int y, int cx, int cy)
{
    x+=10;
    y+=10;
    char *opString=NULL;
    size_t slen;
    
    SIZE stringSize;
    SynTree *ptrStack[256];
    int pCount=-1;
    
    int xCenter[256];
    int yCenter[256];
    int xOffset[256];
    char buf[257];
    
    int c;
    
    if (tree)
    {
        int prevMode =SetBkMode(hdc, TRANSPARENT);
        ptrStack[++pCount] =tree;
        xCenter[pCount] =x;
        yCenter[pCount] =y;
        xOffset[pCount] =0;
        
        
        while (pCount!=-1)
        {
            if (!tree)
            {
                tree =ptrStack[pCount--];
                if (x < xOffset[pCount])
                {
                    x= xOffset[pCount];
                }
                y -=stringSize.cy +10;
                continue;
            }
            switch (tree->stype)
            {
                case ST_OP:
                opString =OpToString(tree->op);
                slen =strlen(opString);
                
                DrawRectangledText(hdc, opString, slen, x, y, &stringSize);
                
                MoveToEx(hdc, xCenter[pCount], yCenter[pCount], NULL);
                LineTo(hdc, x+stringSize.cx/2, y);
                
                ptrStack[++pCount] =tree->next;
                xCenter[pCount] =x+stringSize.cx/2;
                yCenter[pCount] =y+stringSize.cy;
                xOffset[pCount] =x+stringSize.cx+10;
                
                y +=stringSize.cy +10;
                
                tree =tree->children;
                break;
                
                case ST_VAR:
                switch (tree->var.vtype)
                {
                    case VT_VAR:
                    slen =strlen(tree->var.varName);
                    DrawRectangledText(hdc, tree->var.varName, slen, x, y, &stringSize);
                    break;
                    
                    case VT_CONST:
                    c = snprintf(buf, 257, "%f", tree->var._const.real);
                    DrawRectangledText(hdc, buf, c, x, y, &stringSize);
                    break;
                }
                MoveToEx(hdc, xCenter[pCount], yCenter[pCount], NULL);
                LineTo(hdc, x+stringSize.cx/2, y);
                tree =tree->next;
                x+= stringSize.cx +10;
                break;
            }
        }
        
        SetBkMode(hdc, prevMode);
    }
}

Type
EvalSyntaxTree(Lang *lang, SynTree *synTree, LogicResult *lr)
{
    Type ts[17];
    int tCount=-1;
    Type result={.type=TNONE};
    _bool reqsLValue =0;
    SynTree *iter;
    
    if (lr->success
        && synTree!=NULL)
    {
        if (synTree->stype ==ST_OP)
        {
            if (synTree->op ==OP_NONE)
            {
                lr->success=0;
                lr->err =LR_OP;
            }
            else if (synTree->op ==OP_ASG)
            {
                reqsLValue =1;
            }
            iter =synTree->children;
            if ((iter->stype ==ST_OP
                 && reqsLValue)
                &&
                (iter->stype ==ST_VAR
                 && iter->var.vtype ==VT_CONST))
            {
                lr->success=0;
                lr->err=LR_VAR;
            }
            else
            {
                Function *func;
                CalcFunction calcFunc =NULL;
                if (synTree->op ==OP_FUNC)
                {
                    func =LookupFunction(iter->var.varName);
                    if (!func)
                    {
                        lr->success=0;
                        lr->err=LR_FUNC;
                    }
                    iter =iter->next;
                }
                else if (synTree->op ==OP_ASG)
                {
                    iter =iter->next;
                }
                while (iter)
                {
                    ts[++tCount] =EvalSyntaxTree(lang, iter, lr);
                    if (!lr->success)
                    {
                        break;
                    }
                    iter =iter->next;
                }
                if (lr->success)
                {
                    if (synTree->op ==OP_FUNC)
                    {
                        if (func->numArgs !=(tCount+1))
                        {
                            lr->success=0;
                            lr->err =LR_VAR;
                        }
                        else
                        {
                            calcFunc =func->function;
                        }
                    }
                    else if (synTree->op !=OP_ASG)
                    {
                        if (tCount ==1)
                        {
                            calcFunc =LookupOp(synTree->op, ts[0].type, ts[1].type);
                        }
                        
                        else
                        {
                            lr->success=0;
                            lr->err= LR_OP;
                        }
                    }
                    else
                    {
                        _Variable variable;
                        CopyVString(variable.name, synTree->children->var.varName);
                        variable.data =ts[0];
                        StoreVariable(lang, variable);
                        
                        result =ts[0];
                    }
                    if (lr->success
                        && synTree->op !=OP_ASG)
                    {
                        CalcResult calcResult=calcFunc(&ts[0],&ts[1],&ts[2],&ts[3],&ts[4],&ts[5],&ts[6],&ts[7],&ts[8]
                                                       ,&ts[9],&ts[10],&ts[11],&ts[12],ts[13],ts[14],&ts[15], &ts[16]);
                        if (calcResult.success)
                        {
                            result =calcResult._const;
                        }
                        else
                        {
                            lr->success =0;
                            lr->err =LR_CALC;
                        }
                    }
                }
            }
        }
        else if (synTree->stype ==ST_VAR)
        {
            if (synTree->var.vtype ==VT_VAR)
            {
                _Variable *variable =GetVariable(lang, synTree->var.varName);
                if (variable)
                {
                    result =variable->data;
                    if (result.type ==TNONE)
                    {
                        lr->success =0;
                        lr->err =LR_VAR;
                    }
                }
                else
                {
                    lr->success =0;
                    lr->err =LR_VAR;
                }
            }
            else if (synTree->var.vtype ==VT_CONST)
            {
                result =synTree->var._const;
            }
        }
    }
    return result;
}

char *_err_strings[] = {"Unkown operation between with two types or something.\n", "Using unknown variable, or missing arguements or something.\n", "Using unknown function or something.\n", "Calculation failed due to wrong type or something.\n"};

void
PrintError(Terminal *term, int lr)
{
    InputTermBuffer(term, _err_strings[lr], -1);
}

Type
InterpStatement(Lang *lang, char *statement, int c, int* success)
{
    Type result ={.type=TNONE};
    SyntaxResult synResult =BuildSyntaxTree(lang, statement, c);
    
    if (synResult.success)
    {
        LogicResult logicResult={.success=1};
        result =EvalSyntaxTree(lang, synResult.tree, &logicResult);
        
        if (!logicResult.success)
        {
            *success =logicResult.err;
#if defined (DO_TC)
            printf(_err_strings[logicResult.err]);
#endif
        }
    }
#if defined (DO_TC)
    else
    {
        printf("Syntax Error: unexpected or expected \'%c\' found.\r\n", *synResult.err.loc);
    }
#endif
    return result;
}

#if defined(DO_TC)

void
main(int argc, char *argv[])
{
    char buf[257];
    char rbuf[257];
    HANDLE hStdin =GetStdHandle(STD_INPUT_HANDLE);
    DWORD dwRead;
    
    Lang *lang =InitLang();
    while (ReadConsoleA(hStdin, rbuf, 257, &dwRead, NULL))
    {
        dwRead -=2;
        Type t =InterpStatement(lang, rbuf, dwRead);
        TypeToString(buf, 257, &t);
        printf("Return value: %s\r\n", buf);
    }
    UnInitLang(lang);
}
#endif
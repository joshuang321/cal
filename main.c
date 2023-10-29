#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <assert.h>
#include <CommCtrl.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define WNDCLASS_ "cal_wndclass"
#define WNDNAME_ "cal"

#include "terminal.c"
#include "lang_v2.c"
#include "graph.c"

LRESULT WINAPI
WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static App *app;
    switch (uMsg)
    {
        case WM_CREATE:
        app =((App *)((LPCREATESTRUCT)lParam)->lpCreateParams);
        app->edit =CreateWindowExA(0, WC_EDITA, "Type something here ..", WS_VISIBLE|WS_CHILD|ES_AUTOHSCROLL, 0, 0, 0, 0, hWnd, NULL, GetModuleHandleA(NULL), NULL);
        app->button =CreateWindowExA(0, WC_BUTTONA, "Submit", WS_VISIBLE|WS_CHILD|BS_PUSHBUTTON, 0, 0, 0, 0, hWnd, NULL, GetModuleHandleA(NULL), NULL);
        SendMessageA(app->edit, EM_LIMITTEXT, 256, 0);
        InitDraw(&app->draw, hWnd, 1, 1);
        return 0;
        
        case WM_COMMAND:
        if ((HWND)lParam ==app->button)
        {
            static char buf[257];
            int c =GetWindowTextA(app->edit, buf, 257);
            if (c >0)
            {
                InputTerminal(&app->term, buf, c);
                int success =-1;
                Type t =InterpStatement(app->lang, buf, c, &success);
                if (success!=-1)
                {
                    PrintError(&app->term, success);
                }
                c =TypeToString(buf, 257, &t);
                buf[c++] ='\n';
                buf[c] ='\0';
                InputTermBuffer(&app->term, buf, c);
                InvalidateRect(hWnd, NULL, TRUE);
            }
        }
        return 0;
        
        case WM_SIZE:
        app->w =LOWORD(lParam);
        app->h =HIWORD(lParam);
        ResizeWindows(app);
        return 0;
        
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            BeginPaint(hWnd, &ps);
            PaintWindow(hWnd, app, ps.hdc);
            EndPaint(hWnd, &ps);
        }
        return 0;
        
        case WM_CTLCOLOREDIT:
        SetBkColor((HDC)wParam, RGB(200, 200, 200));
        return 0;
        
        case WM_DESTROY:
        UnInitDraw(&app->draw);
        PostQuitMessage(0);
    }
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int nCmdShow)
{
    SetProcessDPIAware();
    App *app =InitApp();
    
    WNDCLASSA wc =
    {
        .style =CS_HREDRAW,
        .hInstance =hInstance,
        .hIcon =LoadIconA(NULL, MAKEINTRESOURCEA(IDI_APPLICATION)),
        .hCursor =LoadCursorA(NULL, MAKEINTRESOURCEA(IDC_ARROW)),
        .hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH),
        .lpfnWndProc =WindowProc,
        .lpszClassName =WNDCLASS_
    };
    assert(RegisterClassA(&wc));
    HWND hWnd =CreateWindowExA(0, WNDCLASS_, WNDNAME_, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 600, NULL, NULL, hInstance, app);
    assert(hWnd);
    InitTerminal(&app->term, hWnd, 0, 30, app->w, 600);
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
    
    MSG msg;
    
    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    UnInitApp(app);
    
    return 0;
}
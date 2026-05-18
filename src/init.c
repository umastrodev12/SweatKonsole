#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>

#define COLOR_RESET   "\x1b[0m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"

int wdith_janela = 800;
int height_janela = 600;

char* getUser() {
    char *user = NULL;

    #ifdef _WIN32
        user = getenv("USERNAME");
    #else
        user = getenv("USER");
    #endif

    if (user == NULL) {
        return "user";
    }

    return user;
}

int init_message() {
    printf("[INIT SYSTEM] Starting Niro Console...", COLOR_RESET);
    printf("[INIT SYSTEM] Welcome", getUser, "!");
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void drawConsole(HDC hdc, HWND hwnd) {
    RECT rectangle;
    GetClientRect(hwnd, &rectangle);

    HBRUSH wallpaper_brush = CreateSolidBrush(RGB(35, 38, 41));
    FillRect(hdc, &rectangle, wallpaper_brush);
    DeleteObject(wallpaper_brush);

    char *user = getenv("USERNAME");
    if (user == NULL) {
        user = "user";
    }

    char cwd[260];
    char *actual_dir = "sys";
    if (GetCurrentDirectoryA(sizeof(cwd), cwd) > 0) {
        actual_dir = strrchr(cwd, '\\');
        if (actual_dir != NULL && strlen(actual_dir) > 1) {
            actual_dir++; 
        } else {
           actual_dir = cwd;
        }
    }
    char user_input[512] = "";
    char all_prompt[1024];
    snprintf(all_prompt, sizeof(all_prompt), "%s@konsole:[%s]> %s_", 
            user, actual_dir, user_input);

    
    SetTextColor(hdc, RGB(0, 255, 128)); 
    SetBkMode(hdc, TRANSPARENT);

    
    HFONT hFont = CreateFontA(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, 
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
                              DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Consolas");
    HFONT hVelhaFont = (HFONT)SelectObject(hdc, hFont);

    
    TextOutA(hdc, 20, 20, all_prompt, strlen(all_prompt));

   
    SelectObject(hdc, hVelhaFont);
    DeleteObject(hFont);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
            
        case WM_SIZE:
            height_janela = LOWORD(lParam);
            wdith_janela  = HIWORD(lParam);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            drawKonsole(hdc, hwnd);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProcA(hwnd, uMsg, wParam, lParam);

    init_message();
}

start();
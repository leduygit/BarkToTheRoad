#include "AsphaltLane.h"
#include "Character.h"
#include "Entity.h"
#include "Global.h"
#include "GrassLane.h"
#include "InputHandler.h"
#include "Map.h"
#include "MoveUpCommand.h"
#include "RailLane.h"
#include "RenderState.h"
#include "Shape.h"
#include "renderer.h"
#include "Button.h"
#include "ScreenRegistry.h"
#include "Gameplay.h"
#include "GameScreen.h"
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <Mfreadwrite.h>
#include <audioclient.h>

Gameplay* gameplay = nullptr;
Screen* s;
ScreenRegistry sr{};

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;

    switch (uMsg) {
    case WM_CLOSE:
    case WM_DESTROY:
        Global::window_should_close = true;
        break;
    case WM_LBUTTONUP:
        sr.getCurrentScreen()->clickButton();
        break;
    case WM_KEYDOWN:
        gameplay->command = gameplay->ih.handleInput(wParam, *gameplay->character);
        break;
    case WM_SIZE: {
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        Global::default_render_state = RenderState(clientRect.bottom - clientRect.top,
            clientRect.right - clientRect.left + 30);
    } break;
    default:
        result = DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    srand(time(NULL));
    WNDCLASS window_class{};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpszClassName = L"My Window Class";
    window_class.lpfnWndProc = Wndproc;

    RegisterClass(&window_class);

    Global::window = CreateWindowA("My Window Class", "My First Game",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX | WS_VISIBLE, CW_USEDEFAULT,
        CW_USEDEFAULT, WINDOW_WIDTH - 5, 720 + 40, 0, 0, hInstance, 0);
    HDC hdc = GetDC(Global::window);
    PlaySound(L"sound/music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    // Global init
    Global::drawer.set_render_state(Global::default_render_state);
    initShape();
    HICON icon = LoadIcon(hInstance, MAKEINTRESOURCE(129));
    SendMessage(Global::window, WM_SETICON, ICON_BIG, (LPARAM)icon);
    int* offset = new int{0}, speed = 1;

    gameplay = new Gameplay();
    gameplay->setOffset(offset);
    sr.initialize();
    sr.addScreen(new GameScreen{gameplay});

    while (!Global::window_should_close) {
        MSG message;
        while (PeekMessage(&message, Global::window, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        sr.getCurrentScreen()->render();

    StretchDIBits(hdc, 0, 0, Global::default_render_state.getWidth(), Global::default_render_state.getHeight(),
                  0, 0, Global::default_render_state.getWidth(), Global::default_render_state.getHeight(),
                  Global::default_render_state.getMemoryPointer(),
                  Global::default_render_state.getBitmapPointer(), DIB_RGB_COLORS, SRCCOPY);
    //Sleep(2.5);
    //if (gameplay->isStart())
        *offset += speed;
  }
}
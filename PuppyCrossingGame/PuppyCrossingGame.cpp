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



bool window_should_close = false;

RenderState render_state;
InputHandler ih;
Command* command = nullptr;
Character* c = new Character;

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  LRESULT result = 0;

  switch (uMsg) {
    case WM_CLOSE:
    case WM_DESTROY:
      window_should_close = true;
      break;
    case WM_KEYDOWN:
      command = ih.handleInput(wParam, *c);
      break;
    case WM_SIZE: {
      RECT clientRect;
      GetClientRect(hWnd, &clientRect);
      render_state = RenderState(clientRect.bottom - clientRect.top,
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

  HWND window = CreateWindowA("My Window Class", "My First Game",
                                WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX | WS_VISIBLE, CW_USEDEFAULT,
                                CW_USEDEFAULT, WINDOW_WIDTH - 5, 720 + 40, 0, 0, hInstance, 0);
  HDC hdc = GetDC(window);
  //Lane lane[10];
  initShape();
  Shape* moving = new Shape[3]{*MyShape[DOG_STAY_1], *MyShape[DOG_JUMP_1], *MyShape[DOG_JUMP_2] };
  Shape* staying = new Shape[2]{ *MyShape[DOG_STAY_1], *MyShape[DOG_STAY_2] };
  SummerLaneFactory fact;
  Map m(&fact);
  m.addLane();
  PlaySound(L"sound/music.wav", NULL, SND_FILENAME | SND_ASYNC);

  Global::drawer.set_render_state(render_state);
  c = new Character{ {1170, 90}, staying, moving, 3 };

  while (!window_should_close) {
    MSG message;
    while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }


    //DWORD currentTime = GetTickCount();  // Get the current time in milliseconds

    
    m.addObstacle();
    m.moveObstacle(*c);
    m.removeObstacle();

    m.render();
    c->render();

    if (command != nullptr) {
        if (command->isValidMove(*c, m)) {
            command->execute(*c, m);
        }
        command = nullptr;
    }

    if (m.checkCollision(*c)) {
        int rand = randomInt(1, 13);
        c->setPos({ static_cast<short>(90 * rand), 0 });
    }

    StretchDIBits(hdc, 0, 0, render_state.getWidth(), render_state.getHeight(),
                  0, 0, render_state.getWidth(), render_state.getHeight(),
                  render_state.getMemoryPointer(),
                  render_state.getBitmapPointer(), DIB_RGB_COLORS, SRCCOPY);
    Sleep(2);
  }
}
#include "AsphaltLane.h"
#include "AsphaltObstacleFactory.h"
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
#include "SummerLaneFactory.h"
#include "framework.h"
#include "renderer.h"

bool window_should_close = false;

Shape s("image/dog_stay_1.txt");
Entity e({100, 100}, &s);

RenderState render_state;
InputHandler ih;
Command* command = nullptr;

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  LRESULT result = 0;

  switch (uMsg) {
    case WM_CLOSE:
    case WM_DESTROY:
      window_should_close = true;
      break;
    case WM_KEYDOWN:
      command = ih.handleInput(wParam);
      break;
    case WM_SIZE: {
      RECT clientRect;
      GetClientRect(hWnd, &clientRect);
      render_state = RenderState(clientRect.bottom - clientRect.top,
                                 clientRect.right - clientRect.left);
    } break;
    default:
      result = DefWindowProc(hWnd, uMsg, wParam, lParam);
  }
  return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
            int nShowCmd) {
  srand(time(NULL));
  WNDCLASS window_class{};
  window_class.style = CS_HREDRAW | CS_VREDRAW;
  window_class.lpszClassName = L"My Window Class";
  window_class.lpfnWndProc = Wndproc;

  RegisterClass(&window_class);

  HWND window = CreateWindowA("My Window Class", "My First Game",
                              WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                              CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
  HDC hdc = GetDC(window);
  Shape s("image/dog_stay_1.txt");
  // Entity e({ 100, 100 }, &s);
  // ObstacleFactory* AsphaltFactory = new AsphaltObstacleFactory();
  Lane lane[10];
  for (SHORT i = 0; i < 6; ++i) {
    // lane[i] = Lane({ 0, 100 * i }, "image/road.txt", AsphaltFactory);
  }
  DWORD lastAddObstacleTime = 0;
  SummerLaneFactory fact;
  Map m(&fact);
  m.addLane();

  GrassLane gL({0, 100});
  AsphaltLane aL({0, 0});

  Global::drawer.set_render_state(render_state);
  Character c{{100, 100}, &s};

  while (!window_should_close) {
    MSG message;
    while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }

    unsigned int* pixels = render_state.getMemoryPointer();
    for (int i = 0; i < render_state.getWidth(); i++) {
      for (int j = 0; j < render_state.getHeight(); j++) {
        *pixels++ = 0xFFFFFF55;
      }
    }
    DWORD currentTime = GetTickCount();  // Get the current time in milliseconds
    // s.render(100, 100);

    // e.move({ 100, 500 });
    // e.render();
    // DWORD currentTime = GetTickCount(); // Get the current time
    // in milliseconds

    m.render();
    c.render();
    if (command != nullptr) {
        command->execute(c);
    }
    // aL.render();
    // gL.render();

    StretchDIBits(hdc, 0, 0, render_state.getWidth(), render_state.getHeight(),
                  0, 0, render_state.getWidth(), render_state.getHeight(),
                  render_state.getMemoryPointer(),
                  render_state.getBitmapPointer(), DIB_RGB_COLORS, SRCCOPY);
  }
}
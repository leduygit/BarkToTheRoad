#include "framework.h"
#include "Entity.h"
#include "Shape.h"
#include "RenderState.h"
#include "Global.h"
#include "renderer.h"
#include "AsphaltObstacleFactory.h"
#include "AsphaltLane.h"
#include "GrassLane.h"

bool window_should_close = false;

Shape s("image/dog_stay_1.txt");
Entity e({ 100, 100 }, & s);

RenderState render_state;


LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	switch (uMsg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		window_should_close = true;
	case WM_SIZE:
	{
		RECT clientRect;
		GetClientRect(hWnd, &clientRect);
		render_state = RenderState(clientRect.bottom - clientRect.top, clientRect.right - clientRect.left);
	}
	break;
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

	HWND window = CreateWindowA("My Window Class", "My First Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);

	unsigned int a[SPRITE_SIZE][SPRITE_SIZE];
	for (int i = 0; i < SPRITE_SIZE; i++) {
		for (int j = 0; j < SPRITE_SIZE; j++) {
			a[i][j] = 0xFF0000FF;
		}
	}
	//Shape s("image/dog_stay_1.txt");
	//Entity e({ 100, 100 }, &s);
	ObstacleFactory* AsphaltFactory = new AsphaltObstacleFactory();
	Lane lane[10];
	for (SHORT i = 0; i < 5; ++i)
	{
		lane[i] = Lane({ 0, 100 * i }, "image/road.txt", AsphaltFactory);
	}
	DWORD lastAddObstacleTime = 0;

	Global::drawer.set_render_state(render_state);

	while (!window_should_close) {
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		unsigned int* pixels = render_state.getMemoryPointer();
		for (int i = 0; i < render_state.getWidth(); i++) {
			for (int j = 0; j < render_state.getHeight(); j++) {
				*pixels++ = 0xFFFF5500;
			}
		}

		DWORD currentTime = GetTickCount(); // Get the current time in milliseconds

		

		for (int i = 0; i < 5; ++i)
		{
			lane[i].moveObstacle();
			lane[i].render();
			/*if (currentTime - lastAddObstacleTime >= 3000) {
				lane[i].addObstacle();
				lastAddObstacleTime = currentTime; // Update the last call time
			}*/
		}

		if (currentTime - lastAddObstacleTime >= 2000)
		{
			int id = randomInt(0, 100);
			id %= 5;
			lane[id].addObstacle();
			lastAddObstacleTime = currentTime; // Update the last call time
		}

		//e.move({ 100, 500 });
		//e.render();

		
		StretchDIBits(hdc, 0, 0, render_state.getWidth(), render_state.getHeight(), 0, 0, render_state.getWidth(), render_state.getHeight(), render_state.getMemoryPointer(), render_state.getBitmapPointer(), DIB_RGB_COLORS, SRCCOPY);
	}
}
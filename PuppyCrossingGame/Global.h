#pragma once
#include "renderer.h"
#include "RenderState.h"
#include "vector"
#include "Shape.h"
#include "ScreenId.h"

namespace Global {
	extern HWND window;
	extern RenderState default_render_state;
	extern Renderer drawer;
	extern ScreenId current_screen;
	extern int LOW_SPEED;
	extern int MEDIUM_SPEED;
	extern int HIGH_SPEED;
}
#pragma once
#include "renderer.h"
#include "RenderState.h"
#include "vector"
#include "Shape.h"

namespace Global {
	extern HWND window;
	extern RenderState default_render_state;
	extern Renderer drawer;
	extern int LOW_SPEED;
	extern int MEDIUM_SPEED;
	extern int HIGH_SPEED;
}
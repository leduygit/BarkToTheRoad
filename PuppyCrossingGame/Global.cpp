#include "Global.h"
#include "RenderState.h"
#include <vector>
#include "Shape.h"
RenderState Global::default_render_state = RenderState{WINDOW_WIDTH, 720};
Renderer Global::drawer = Renderer{ default_render_state };
int Global::VERY_HIGH_SPEED = 1;
int Global::HIGH_SPEED = 5;
int Global::MEDIUM_SPEED = 6;
int Global::LOW_SPEED = 30;
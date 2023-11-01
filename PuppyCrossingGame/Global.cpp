#include "Global.h"
#include "RenderState.h"
#include <vector>
#include "Shape.h"
RenderState Global::default_render_state = RenderState{1280, 720};
Renderer Global::drawer = Renderer{ default_render_state };
int Global::HIGH_SPEED = 5;
int Global::MEDIUM_SPEED = 15;
int Global::LOW_SPEED = 30;
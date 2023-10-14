#include "Global.h"
#include "RenderState.h"
RenderState Global::default_render_state = RenderState{1280, 720};
Renderer Global::drawer = Renderer{ default_render_state };
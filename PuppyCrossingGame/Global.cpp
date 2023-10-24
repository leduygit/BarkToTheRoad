#include "Global.h"
#include "RenderState.h"
#include <vector>
#include "Shape.h"
RenderState Global::default_render_state = RenderState{1280, 720};
Renderer Global::drawer = Renderer{ default_render_state };
#include "Global.h"
#include "RenderState.h"
#include <vector>
#include "Shape.h"
HWND Global::window = 0;
RenderState Global::default_render_state = RenderState{WINDOW_WIDTH, 720};
Renderer Global::drawer = Renderer{ default_render_state };
ScreenId Global::current_screen{ MENU_SCREEN };
HDC Global::hdc = 0;
bool Global::window_should_close = false;
bool Global::is_music_muted = false;
bool Global::is_sound_muted = false;
int Global::VERY_HIGH_SPEED = 1;
int Global::HIGH_SPEED = 7;
int Global::MEDIUM_SPEED = 10;
int Global::LOW_SPEED = 35;
#include "engine.h"

//TODO: Move to game struct or create struct;

//feedback: this file looks like a storage place for some variables, it doesn't contain any functionality. I'd rather voate for moving those to Game class, main file or
// elsewhere.
SDL_Window* window;
SDL_Renderer* renderer;

bool keys[SDL_NUM_SCANCODES] = { false };

float delta_time = 0.f;
Uint64 previous_ticks = 0;

#include "engine.h"

//TODO: Move to game struct or create struct;
SDL_Window* window;
SDL_Renderer* renderer;

bool keys[SDL_NUM_SCANCODES] = { false };

float delta_time = 0.f;
Uint64 previous_ticks = 0;

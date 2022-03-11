#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern bool keys[SDL_NUM_SCANCODES];

extern Uint64 previous_ticks;
extern float delta_time;


#pragma once

#include "brick.h"

#define MAP_COLS 16
#define MAP_ROWS 20
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)

extern Brick* bricks[MAP_COLS * MAP_ROWS];

struct Level 
{
	void create();
	void reset();
	void draw();
};

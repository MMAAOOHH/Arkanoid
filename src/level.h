#pragma once

#include "brick.h"

#define MAP_COLS 16
#define MAP_ROWS 20
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)

struct Level 
{
	//add int for wincondition int brick_count = 0;
	Brick* bricks[MAP_COLS * MAP_ROWS];
	int brick_count = 0;

	void create();
	void reset();
	void draw();
};


//wincondition
//level has brick_count
//		when brick destroyed brick_count--;
//			if(brick_count == 0)
//					Waho! success!
#pragma once
#include "player.h"
#include "ball.h"
#include "brick.h"
#define BALL_MAX 10

#define MAP_COLS 16
#define MAP_ROWS 20
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)

extern Player player;
extern Ball balls[BALL_MAX];
extern Brick* bricks[MAP_COLS * MAP_ROWS];

void loadMap();

#include "game.h"

const char* LEVEL =
"................"
"................"
"................"
"...##########..."
"..############.."
".##############."
".##############."
"..############.."
"...##########..."
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................";

Player player;
Ball balls[BALL_MAX];
Brick* bricks[MAP_COLS * MAP_ROWS] = { nullptr };

void loadMap()
{
	const char* ptr = LEVEL;
	for (int y = 0; y < MAP_ROWS; ++y)
	{
		for (int x = 0; x < MAP_COLS; ++x, ++ptr)
		{
			if (*ptr != '#')
				continue;

			Brick* brick = new Brick();
			brick->x = x * (brick->w + 1);
			brick->y = y * (brick->h + 1);

			bricks[y * MAP_COLS + x] = brick;
		}
	}
}
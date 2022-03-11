#include "level.h"
#include "game.h"

const char* LEVEL =
"................"
"................"
"................"
".##############."
"..############.."
"...##########..."
"................"
"................"
"................"
".##############."
".##############."
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................";

Brick* bricks[MAP_COLS * MAP_ROWS] = { nullptr };

void Level::create()
{
	//create bricks in level layout
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

void Level::draw()
{
	// Draw all bricks
	for (int i = 0; i < NUM_BRICKS; ++i)
	{
	Brick* brick = bricks[i];
	if (brick == nullptr)
		continue;

	brick->draw();
	}
}

void Level::reset() 
{
	//reset level to starting layout
}

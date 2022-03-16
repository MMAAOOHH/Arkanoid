#include "level.h"
#include "game.h"

const char* LEVEL =
"................"
"................"
"....11111111...."
"...1333333331..."
"..133331133331.."
".13333222233331."
"1333311..2133331"
".13333222233331."
"..133331133331.."
"...1333333331..."
"....11111111...."
"0..............0"
".22222222222222."
"..333333333333.."
"................"
".11111111111111."
".00000000000000."
"................"
"................"
"................"
;

Brick* bricks[MAP_COLS * MAP_ROWS] = { nullptr };

void Level::create()
{
	//create bricks in level layout
	const char* ptr = LEVEL;
	
	//brick_count = 0;
	
	for (int y = 0; y < MAP_ROWS; ++y)
	{
		for (int x = 0; x < MAP_COLS; ++x, ++ptr)
		{
			if (*ptr == '.')
				continue;

			Brick* brick = new Brick();
			brick->x = x * (brick->w);
			brick->y = y * (brick->h);

			//Subtracting with 48 to convert char to int (ascii)
			brick->hit_points = (int)*ptr - '0';

			if (*ptr == '0')
				brick->unbreakable = true;

			bricks[y * MAP_COLS + x] = brick;

			brick_count++; 
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

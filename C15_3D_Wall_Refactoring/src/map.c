#include		"map.h"

static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] =
{
				{1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1 ,1, 1,  1, 1, 1, 1, 1},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  1, 0, 0, 0, 1},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  8, 0, 0, 0, 1},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1},
				{1, 0, 0, 0, 2,  2, 0, 3, 0, 4,  0, 5, 0, 6, 0,  0, 0, 0, 0, 1},

				{1, 0, 0, 0, 0,  0, 0, 3, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0,  0, 0, 3, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 7, 0,  0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 5},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 1, 0, 0,  0, 0, 0, 0, 5},

				{1, 0, 0, 0, 0,  0, 0, 0, 0, 9,  0, 0, 1, 0, 0,  0, 0, 0, 0, 5},
				{1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 1, 0, 0,  0, 0, 0, 0, 5},
				{1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 5,  5, 5, 5, 5, 5}
};

bool				hasWallAt(float posX, float posY)
{
	int				mapIdxX;
	int				mapIdxY;

	if (posX < 0 || posX > MAP_NUM_COLS * TILE_SIZE ||
		posY < 0 || posY > MAP_NUM_ROWS * TILE_SIZE)
		return		(true);
	mapIdxX = floor(posX / TILE_SIZE);
	mapIdxY = floor(posY / TILE_SIZE);
	if (map[mapIdxY][mapIdxX] != 0)
		return (true);
	return (false);
}

bool				isInsideMap(float x, float y)
{
	return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
			y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

void				renderMap(void)
{
	int				tileX;
	int				tileY;
	uint32_t		tileColor;
	for (int i=0; i<MAP_NUM_ROWS; i++)
	{
		for (int j=0; j<MAP_NUM_COLS; j++)
		{
			tileX		= j * TILE_SIZE;
			tileY		= i * TILE_SIZE;
			tileColor	= map[i][j] != 0 ? 0xFFFFFFFF : 0xFF000000;

			drawRect(
				tileX	  * MINIMAP_SCALE_FACTOR,
				tileY	  * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				tileColor
			);
		}
	}
}

int					getMapAt(int i, int j)
{
	return (map[i][j]);
}
#ifndef				DEFS_H
#define				DEFS_H

#include			<math.h>

# define			PI						3.14159265

# define			TILE_SIZE				64

# define			NUM_TEXTURES			9

# define			MINIMAP_SCALE_FACTOR	0.2

# define			WINDOW_WIDTH			1280
# define			WINDOW_HEIGHT			800

# define			FOV_ANGLE				(60 * (PI / 180))

# define			NUM_RAYS				WINDOW_WIDTH

# define			DIST_PROJ_PLANE			((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2))

# define			FPS						500
# define			FRAME_TIME_LENGTH		(1000 / FPS)

# define			color_t					uint32_t

#endif

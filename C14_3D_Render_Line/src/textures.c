#include			"textures.h"

static const char	*textureFileNames[NUM_TEXTURES] =
{
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
	"./images/pikuma.png"
};

void				loadWallTextures()
{
	// TODO: load all the PNG textures from the filepaths
	for (int i=0; i<NUM_TEXTURES; i++)
	{
		upng_t			*upng;

		upng = upng_new_from_file(textureFileNames[i]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{// TODO: stuff with image
				wallTextures[i].upngTexture		= upng;
				wallTextures[i].width			= upng_get_width(upng);
				wallTextures[i].height			= upng_get_height(upng);
				wallTextures[i].texture_buffer	= (uint32_t *)upng_get_buffer(upng);
			}
		}
	}
}

void				freeWallTextures()
{
	for (int i=0; i<NUM_TEXTURES; i++)
		upng_free(wallTextures[i].upngTexture);
}
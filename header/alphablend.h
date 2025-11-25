#ifndef ALPHABLEND_H
#define ALPHABLEND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>

// alpha blend
typedef struct
{
    SDL_Texture *mtexture;
    int mwidth;
    int mheight;
} AlphaBlend;

//Scene texture
extern AlphaBlend gModulatedTexture;

bool LoadABFile(char *path);

void FreeAB();

//Set color modulation
void SetColor( Uint8 red, Uint8 green, Uint8 blue );

//Set blending
void SetBlendMode( SDL_BlendMode blending );

//Set alpha modulation
void SetAlpha( Uint8 alpha );

//Renders texture at given point
void RenderAB( int x, int y, SDL_Rect* clip = NULL );

#endif

#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>

// alpha blend
typedef struct
{
    SDL_Texture *texture;
    int width;
    int height;
} Texture;

//Scene texture
extern Texture texture_record;

void InitTexture(Texture *tex_rec);

void FreeTexture(Texture *tex_rec);

bool LoadTexture(char *path, Texture *tex_rec);

//Set color modulation
//void SetColor( Uint8 red, Uint8 green, Uint8 blue, AlphaBlend *tex );

//Set blending
//void SetBlendMode( SDL_BlendMode blending );

//Set alpha modulation
// void SetAlpha( Uint8 alpha );

//Renders texture at given point
void RenderTexture( int x, int y, Texture *tex_rec );

//Gets image dimensions
int WTexture(Texture *tex_rec);
int HTexture(Texture *tex_rec);

#endif

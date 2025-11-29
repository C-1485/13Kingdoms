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


// master.c LoadMedia call

void InitTexture(Texture *tex_rec);

bool LoadTexture(char *path, Texture *tex_rec);


// master.c Close call

void FreeTexture(Texture *tex_rec);






// helpers: image dimensions

int WTexture(Texture *tex_rec);

int HTexture(Texture *tex_rec);


// main.c loop calls


void AlphaTexture(Texture *tex_rec, Uint8 *alpha);
void BlendTexture(Texture *tex_rec, SDL_BlendMode blend);


//Set color modulation
void ColorTexture( Uint8 red, Uint8 green, Uint8 blue, Texture *tex_rec );

//Renders texture at given point
void RenderTexture( int x, int y, Texture *tex_rec );

#endif

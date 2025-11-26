#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>

#include "../header/textures.h"
#include "../header/master.h"

void InitTexture(Texture *tex_rec)
{
    tex_rec->texture = NULL;
    tex_rec->width = 0;
    tex_rec->height = 0;
}

void FreeTexture(Texture *tex_rec)
{
    if (tex_rec->texture != NULL) {
        SDL_DestroyTexture(tex_rec->texture);
        tex_rec->texture = NULL;
        tex_rec->width = 0;
        tex_rec->height = 0;
    }
}

bool LoadTexture(char *path, Texture *tex_rec)
{
    FreeTexture(tex_rec);

    SDL_Texture* new_texture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        // Create texture from surface pixels
        new_texture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( new_texture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            tex_rec->width = loadedSurface->w;
            tex_rec->height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    tex_rec->texture = new_texture;
    return tex_rec->texture != NULL;
}

/*
void SetColor( Uint8 red, Uint8 green, Uint8 blue, AlphaBlend *tex )
{
    //Modulate texture
    SDL_SetTextureColorMod( tex->mtexture, red, green, blue );
}
*/

void RenderTexture(int x, int y, Texture *tex_rec)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, tex_rec->width, tex_rec->height };
    SDL_RenderCopy( gRenderer, tex_rec->texture, NULL, &renderQuad );
}

int WTexture(Texture *tex_rec)
{
    return tex_rec->width;
}

int HTexture(Texture *tex_rec)
{
    return tex_rec->height;
}

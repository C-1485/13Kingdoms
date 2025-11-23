#ifndef MASTER_H
#define MASTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The surface contained by the window
extern SDL_Surface* gScreenSurface;

//The image we will load and show on the screen
extern SDL_Surface* gHelloWorld;

//The images that correspond to a keypress
extern SDL_Surface* gKeyPressSurfaces[];

//Current displayed image
extern SDL_Surface* gCurrentSurface;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool Init();

//Loads individual image
SDL_Surface* loadSurface( char *path );

bool LoadMedia();

void Close();

#endif

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

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

bool Init();

bool LoadMedia();

void Close();

#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#include "master.h"

/*
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;*/

int main( int argc, char* args[] )
{


    //Start up SDL and create window
    if( !Init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !LoadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {

            //Set default current surface
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

            //Hack to get window to stay up
            SDL_Event e;
            bool quit = false;
            while( quit == false )
            {
                while( SDL_PollEvent( &e ) )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                                break;

                            case SDLK_DOWN:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                                break;

                            case SDLK_LEFT:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                                break;

                            case SDLK_RIGHT:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                                break;

                            default:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                                break;
                        }
                    }
                    //Apply the image
                    SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );

                    //Update the surface
                    SDL_UpdateWindowSurface( gWindow );
                }
            }
        }
    }
    //Free resources and close SDL
    Close();

    return 0;
}

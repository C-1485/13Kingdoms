#include <SDL2/SDL.h>
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
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

            //Update the surface
            SDL_UpdateWindowSurface( gWindow );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }
    //Free resources and close SDL
    Close();

    return 0;
}

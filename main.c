#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#include "header/master.h"
#include "header/textures.h"

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
            //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

            //Hack to get window to stay up
            SDL_Event e;

            //Modulation components
            Uint8 r = 255;
            Uint8 g = 255;
            Uint8 b = 255;


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
                    /*
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

                    */

                    //Clear screen
                    /*
                    SDL_RenderClear( gRenderer );

                    //Render texture to screen
                    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

                    //Update screen
                    SDL_RenderPresent( gRenderer );
                    */

                    /*
                    //Clear screen
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );

                    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                    SDL_RenderFillRect( gRenderer, &fillRect );

                    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
                    SDL_RenderDrawRect( gRenderer, &outlineRect );

                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
                    SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );

                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
                    for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
                    {
                        SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i );
                    }

                    //Update screen
                    SDL_RenderPresent( gRenderer );
                    */

                    //Clear screen
                    /*
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );

                    //Render background texture to screen
                    RenderTexture( 0, 0, &back_texture );
                    RenderTexture(SCREEN_WIDTH / 64, SCREEN_HEIGHT / 64, &front_texture );


                    //Update screen
                    SDL_RenderPresent( gRenderer );
                    */

                    else if( e.type == SDL_KEYDOWN )
                    {
                        switch( e.key.keysym.sym )
                        {
                            //Increase red
                            case SDLK_q:
                                r += 32;
                                break;

                                //Increase green
                            case SDLK_w:
                                g += 32;
                                break;

                                //Increase blue
                            case SDLK_e:
                                b += 32;
                                break;

                                //Decrease red
                            case SDLK_a:
                                r -= 32;
                                break;

                                //Decrease green
                            case SDLK_s:
                                g -= 32;
                                break;

                                //Decrease blue
                            case SDLK_d:
                                b -= 32;
                                break;
                        }
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Modulate and render texture
                ColorTexture( r, g, b, &modulatedtex );
                RenderTexture( 0, 0, &modulatedtex );

                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    //Free resources and close SDL
    Close();

    return 0;
}

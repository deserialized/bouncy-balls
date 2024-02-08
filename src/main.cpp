#include <cstdio>
#include <SDL.h>

// Screen Dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    // The window we'll be rendering to
    SDL_Window* window = nullptr;

    // The surface contained by the window (essentially just a 2D graphic)
    SDL_Surface* screenSurface = nullptr;

    // Initialise SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    //Create window
    window = SDL_CreateWindow( "Hello world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == nullptr ) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, nullptr, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while(!quit){ while( SDL_PollEvent(&e ) ){ if(e.type == SDL_QUIT ) quit = true; } }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

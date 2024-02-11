#include <cstdio>
#include <SDL.h>
#include "../include/InteractiveWindow.h"

struct {
    InteractiveWindow window;
    SDL_Renderer* renderer;
    // TODO: make wrapper object for textures
} State;

int main()
{
    printf("Running");
    return 0;
}

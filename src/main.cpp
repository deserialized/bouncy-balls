#include <cstdio>
#include <SDL.h>
#include "../include/InteractiveWindow.h"

struct {
    InteractiveWindow window;
    SDL_Renderer* renderer{};
    SDL_Texture* texture{};
    bool quit = false;
} State;

/* render()
 * Renders application texture to the window
 */
void render()
{
    // Clear current display
    SDL_SetRenderDrawColor(State.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(State.renderer);

    // Render textures

    // Draw new display
    SDL_RenderPresent(State.renderer);
}

/* handle_event()
 * Handles an event during runtime
 */
void handle_event(SDL_Event e)
{
    // Determine whether application should quit
    State.quit = e.type == SDL_QUIT;

    // Handle any other events
    State.window.handle_event(e);
}

/* step()
 * Handles a single step in runtime
 */
void step()
{
    // Handle queued events
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) { handle_event(e); }

    // Render application
    if (!State.window.is_minimised()) { render(); }
}

/* main()
 * Initialises the application state and runs if successful
 */
int main()
{
    // Initialise window
    if (!State.window.init()) { return 0; }

    // Initialise renderer
    State.renderer = State.window.create_renderer();
    if (!State.renderer) { return 0; }

    // Initialise texture


    // Run the application
    while (!State.quit) { step(); }

    return 0;
}

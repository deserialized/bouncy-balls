#include <iosfwd>
#include "../../include/InteractiveWindow.h"

/* ::InteractiveWindow()
 * Initialises properties to defaults
 */
InteractiveWindow::InteractiveWindow()
{
    window = nullptr;
    renderer = nullptr;
    mouse_focus = false;
    keyboard_focus = false;
    fullscreen = false;
    minimised = false;
    width = 0;
    height = 0;
}

/* ::init()
 * Initialises a new window
 */
bool InteractiveWindow::init()
{
    // Temporary structure to hold sample display data
    struct {
        int w = 400;
        int h = 600;
    } mode;

    // Create and validates new window
    window = SDL_CreateWindow("Bouncy Balls", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mode.w, mode.h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) { return false; }

    // Initialise properties
    mouse_focus = true;
    keyboard_focus = true;
    width = mode.w;
    height = mode.h;

    return true;
}

/* ::create_renderer()
 * Creates a new SDL renderer for the window
 */
SDL_Renderer* InteractiveWindow::create_renderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return renderer;
}

/* ::handle_event()
 * Handles a given window event
 */
void InteractiveWindow::handle_event(SDL_Event &event)
{
    // Toggle fullscreen event
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        if (fullscreen) {
            SDL_SetWindowFullscreen(window, 0);
        }
        else {
            SDL_SetWindowFullscreen(window, 1);
            minimised = false;
        }
        fullscreen = !fullscreen;
        return;
    }

    // Check that the given event related to the window
    if (event.type != SDL_WINDOWEVENT ) { return; }

    // Handle different window events
    switch(event.window.event)
    {
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            width = event.window.data1;
            height = event.window.data2;
            SDL_RenderPresent(renderer);
            break;

        case SDL_WINDOWEVENT_EXPOSED:
            SDL_RenderPresent(renderer);
            break;

        case SDL_WINDOWEVENT_ENTER:
            mouse_focus = true;
            break;

        case SDL_WINDOWEVENT_LEAVE:
            mouse_focus = false;
            break;

        case SDL_WINDOWEVENT_FOCUS_GAINED:
            keyboard_focus = true;
            break;

        case SDL_WINDOWEVENT_FOCUS_LOST:
            keyboard_focus = false;
            break;

        case SDL_WINDOWEVENT_MAXIMIZED:
            minimised = false;
            break;

        case SDL_WINDOWEVENT_MINIMIZED:
            minimised = true;
            break;

        case SDL_WINDOWEVENT_RESTORED:
            minimised = false;
            break;
    }
}

/* ::free()
 * Deallocate memory reserved for window internals
 */
void InteractiveWindow::free()
{
    // lol memory leak loser -> TODO: implement
}

/* ::get_renderer()
 * Returns the window's renderer
 */
SDL_Renderer* InteractiveWindow::get_renderer() { return renderer; }

/* ::get_width()
 * Returns the window's width
 */
int InteractiveWindow::get_width() const { return width; }

/* ::get_height()
 * Returns the window's height
 */
int InteractiveWindow::get_height() const { return height; }

/* ::has_keyboard_focus()
 * Checks if the keyboard is focused on the window
 */
bool InteractiveWindow::has_keyboard_focus() const { return keyboard_focus; }

/* ::has_mouse_focus()
 * Checks if the mouse is focused on the window
 */
bool InteractiveWindow::has_mouse_focus() const { return mouse_focus; }

/* ::is_minimised()
 * Checks if the window is minimised
 */
bool InteractiveWindow::is_minimised() const { return minimised; }
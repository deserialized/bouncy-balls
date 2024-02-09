#ifndef BOUNCY_BALLS_EVENTWINDOW_H
#define BOUNCY_BALLS_EVENTWINDOW_H

#include <SDL.h>

/* EventWindow.h
 * Wrapper object for the default SDL window. Used to handle window events (e.g. window resize)
 */
class EventWindow
{
public:
    // Used to initialise internals
    EventWindow();
    // Creates a new window
    bool init();
    // Creates a new renderer using the internal window
    SDL_Renderer* create_renderer();
    // Handles window manipulation events
    void handle_event( SDL_Event& event );
    // Deallocates internals
    void free();
    // Fetch window dimensions
    int get_width() const;
    int get_height() const;
    // Window foci checks
    bool has_mouse_focus() const;
    bool has_keyboard_focus() const;
    bool is_minimised() const;
private:
    // Window that is being wrapped
    SDL_Window *window;
    // Window dimension data
    int width;
    int height;
    // Window foci
    bool mouse_focus;
    bool keyboard_focus;
    bool fullscreen;
    bool minimised;
};

#endif //BOUNCY_BALLS_EVENTWINDOW_H
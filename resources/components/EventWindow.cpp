#include "../../include/EventWindow.h"

/* ::EventWindow()
 * Initialises properties to defaults
 */
EventWindow::EventWindow()
{
    window = nullptr;
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
bool EventWindow::init()
{

}

/* ::create_renderer()
 * Creates a new SDL renderer for the window
 */
SDL_Renderer* EventWindow::create_renderer()
{

}

/* ::handle_event()
 * Handles a given window event
 */
void EventWindow::handle_event(SDL_Event &event)
{

}

/* ::free()
 * Deallocate memory reserved for window internals
 */
void EventWindow::free()
{

}

/* ::get_width()
 * Returns the window's width
 */
int EventWindow::get_width() const
{
    return width;
}

/* ::get_height()
 * Returns the window's height
 */
int EventWindow::get_height() const
{
    return height;
}

/* ::has_keyboard_focus()
 * Checks if the keyboard is focused on the window
 */
bool EventWindow::has_keyboard_focus() const
{
    return keyboard_focus;
}

/* ::has_mouse_focus()
 * Checks if the mouse is focused on the window
 */
bool EventWindow::has_mouse_focus() const
{
    return mouse_focus;
}

/* ::is_minimised()
 * Checks if the window is minimised
 */
bool EventWindow::is_minimised() const
{
    return minimised;
}
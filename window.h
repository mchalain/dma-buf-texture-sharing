#pragma once

#include <X11/Xlib.h>

#ifndef WINDOW_WIDTH
#define WINDOW_WIDTH 640
#endif
#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT 640
#endif
void create_x11_window(int is_server, Display **x11_display, Window *x11_window)
{
    // Open X11 display and create window
    Display *display = XOpenDisplay(NULL);
    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, WINDOW_WIDTH, WINDOW_HEIGHT, 1,
                                        BlackPixel(display, screen), WhitePixel(display, screen));
    XStoreName(display, window, is_server ? "Server" : "Client");
    XMapWindow(display, window);

    // Return
    *x11_display = display;
    *x11_window = window;
}

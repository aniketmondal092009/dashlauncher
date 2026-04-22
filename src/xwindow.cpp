#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "xwindow.hpp"


bool quited = false;


void on_delete(Display * display, Window window)
{
    XDestroyWindow(display, window);
    quited = true;
}

int xwindow(int width, int height)
{
    Display * display = XOpenDisplay(NULL);
    if (NULL == display) {
        std::cerr << "cannot open display\n";
        return false;
    }

    Window root = DefaultRootWindow(display);
    if (None == root) {
        fprintf(stderr, "No root window found");
        XCloseDisplay(display);
        return EXIT_FAILURE;
    }

    int screen = DefaultScreen(display);
    int screen_width = DisplayWidth(display, screen);
    int screen_height = DisplayHeight(display, screen);


        // Center window
    int x = (screen_width - width) / 2;
    int y = (screen_height - height) / 2;



    // Set window attributes (override_redirect for launcher)
    XSetWindowAttributes attrs;
    attrs.override_redirect = True;
    attrs.background_pixel = BlackPixel(display, screen);
    attrs.event_mask = ExposureMask | KeyPressMask;

    Window window = XCreateWindow(display, RootWindow(display, screen),
                          x, y, width, height, 0,
                          DefaultDepth(display, screen), InputOutput,
                          DefaultVisual(display, screen),
                          CWOverrideRedirect | CWBackPixel | CWEventMask, &attrs);

    if (None == window) {
        std::cerr << "cannot open display\n";
        XCloseDisplay(display);
        return EXIT_FAILURE;
    }

    XMapWindow(display, window);

    Atom wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, & wm_delete_window, 1);

    XEvent event;
    while (!quited) {
        XNextEvent(display, &event);

        switch(event.type) {
        case ClientMessage:
            if((Atom)event.xclient.data.l[0] == wm_delete_window) {
                on_delete(event.xclient.display, event.xclient.window);
            }
            break;
        }
    }

    XCloseDisplay(display);

    return 0;
}

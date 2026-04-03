#include "window.hpp"

#include <iostream>
#include <X11/Xutil.h>

namespace launcher {

XWindow::XWindow() : display(nullptr), window(0), screen(0) {}

XWindow::~XWindow() {
    if (display) {
        XCloseDisplay(display);
    }
}

bool XWindow::init(int width, int height) {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cerr << "Cannot open display\n";
        return false;
    }

    screen = DefaultScreen(display);
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

    window = XCreateWindow(display, RootWindow(display, screen),
                          x, y, width, height, 0,
                          DefaultDepth(display, screen), InputOutput,
                          DefaultVisual(display, screen),
                          CWOverrideRedirect | CWBackPixel | CWEventMask, &attrs);

    // Map (show) the window
    XMapWindow(display, window);

    return true;
}

void XWindow::run() {
    XEvent event;
    while (1) {
        XNextEvent(display, &event);

        if (event.type == Expose) {
            // Window is shown, we could draw something here
        }
        if (event.type == KeyPress) {
            break;
        }
    }
}

} // namespace launcher

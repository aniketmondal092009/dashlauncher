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

    // Create window
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, width, height, 1,
                                 BlackPixel(display, screen), WhitePixel(display, screen));

    // Select kind of events we are interested in
    XSelectInput(display, window, ExposureMask | KeyPressMask);

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

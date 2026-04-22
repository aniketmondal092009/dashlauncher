
#include "window.hpp"
#include <iostream>


MenuWindow::MenuWindow() : display(nullptr), window(0), screen(0) {}


MenuWindow::~MenuWindow() {
    if (display) {
        XCloseDisplay(display);
    }
}


bool MenuWindow::init() {
    std::cout << height << std::endl;
    //
    // display = XOpenDisplay(NULL);
    // if (display == NULL) {
    //     std::cerr << "Cannot open display\n";
    //     return false;
    // }
    //
    // screen = DefaultScreen(display);
    // int screen_width = DisplayWidth(display, screen);
    // int screen_height = DisplayHeight(display, screen);
    //
    // int x = (screen_width - width) / 2;
    // int y = (screen_height - height) / 2;
    //
    //
    // XSetWindowAttributes attrs;
    // attrs.override_redirect = True;
    // attrs.background_pixel = BlackPixel(display, screen);
    // attrs.event_mask = ExposureMask | KeyPressMask;
    //
    // window = XCreateWindow(
    //         display, 
    //         RootWindow(display, screen),
    //         x, y, 
    //         width, height, 
    //         0,
    //         DefaultDepth(display, screen), 
    //         InputOutput,
    //         DefaultVisual(display, screen),
    //         CWOverrideRedirect | CWBackPixel | CWEventMask, 
    //         &attrs
    // );
    //
    // XMapWindow(display, window);
    //
    return true;
}


void MenuWindow::loop() {
    XEvent event;

    while (1) {
        XNextEvent(display, &event);

        if (event.type == Expose) {
        }

        if (event.type == KeyPress) {
            break;
        }
    }

}





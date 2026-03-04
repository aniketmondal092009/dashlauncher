#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

void printhello() {
    printf("Dash launcher\n");
    printf("v1.0.0\n\n");


    printf("Hello fron dash launcher\n\n");
}



int display() {
    Display *display;
    Window window;
    int screen;
    XEvent event;

    /* Open connection to the X server */
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    screen = DefaultScreen(display);

    /* Create a window */
    window = XCreateSimpleWindow(display, RootWindow(display, screen),
                                 100, 100, 400, 300, 1,
                                 BlackPixel(display, screen),
                                 WhitePixel(display, screen));

    /* Select kind of events we are interested in */
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    /* Make the window visible on the screen */
    XMapWindow(display, window);

    /* Event loop */
    while (1) {
        XNextEvent(display, &event);

        /* Draw or handle events */
        if (event.type == Expose) {
            XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 100, 50);
            XDrawString(display, window, DefaultGC(display, screen), 50, 50, "Hello X11", 9);
        }
    }

    /* Close connection to X server */
    XCloseDisplay(display);

    return 0;
}

int main() {
    // printhello();
    display();

    return 0;
}


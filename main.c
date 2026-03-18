
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>


static Display *display;
static Window window;
static int screen;

static XEvent event;

void printhello() {
    printf("Dash launcher\n");
    printf("v1.0.0\n\n");


    printf("Hello fron dash launcher\n\n");
}


static void drawmenu() {
}

static void setup() {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, screen),
                                 100, 100, 400, 300, 1,
                                 BlackPixel(display, screen),
                                 WhitePixel(display, screen));

    XSelectInput(display, window, ExposureMask | KeyPressMask);

    XMapWindow(display, window);

    while (1) {
        XNextEvent(display, &event);

        /* Draw or handle events */
        if (event.type == Expose) {
            XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 100, 50);
            XDrawString(display, window, DefaultGC(display, screen), 50, 50, "Hello X11", 9);
        }
    }

    drawmenu();
}

static void cleanup() {
    XSync(display, False);
    XCloseDisplay(display);
}

int main() {
    setup();
    cleanup();

    return 0;
}


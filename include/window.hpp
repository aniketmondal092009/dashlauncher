#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <X11/Xlib.h>


class MenuWindow {
public:
    int width;
    int height = 600;

    MenuWindow();
    ~MenuWindow();

    bool init();

    void loop();

private:
    Display *display;
    Window window;
    int screen;
};


#endif

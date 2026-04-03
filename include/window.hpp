#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <X11/Xlib.h>

namespace launcher {

class XWindow {
public:
    XWindow();
    ~XWindow();

    /**
     * @brief Initialize and open the X11 window.
     * @return true if successful, false otherwise.
     */
    bool init(int width = 800, int height = 600);

    /**
     * @brief Run the event loop.
     */
    void run();

private:
    Display *display;
    Window window;
    int screen;
};

} // namespace launcher

#endif // WINDOW_HPP

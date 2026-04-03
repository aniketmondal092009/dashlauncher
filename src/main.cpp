#include "args.hpp"
#include "window.hpp"

int main(int argc, char **argv) {
    if (!launcher::get_args(argc, argv)) {
        return 0;
    }

    launcher::XWindow win;
    if (!win.init()) {
        return 1;
    }

    win.run();

    return 0;
}

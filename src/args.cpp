#include "args.hpp"
#include <iostream>
#include <string>

namespace launcher {

bool get_args(int argc, char* argv[]) {
    if (argc == 1) {
        return true;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            std::cout <<
                "dashlauncher\n"
                "v1.0"
                "\n\n"
                "USAGE:\n"
                "    --help: shows this text\n"
                "    --version: shows version\n\n";

            return false;
        } else if (arg == "--version" || arg == "-v") {
            std::cout <<
                "dashlauncher\n"
                "v1.0\n\n"
                "execute '--help' to know more about the usage\n\n";

            return false;
        } else {
            std::cout <<
                "invalid command: " << arg << "\n\n"
                "execute '--help' to know more about the usage\n\n";

            return false;
        }
    }

    return true;
}

} // namespace launcher

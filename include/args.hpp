#ifndef ARGS_HPP
#define ARGS_HPP

#include <string>

namespace launcher {
    /**
     * @brief Parse command line arguments.
     * @return true if the program should continue, false if it should exit (e.g., --help).
     */
    bool get_args(int argc, char* argv[]);
}

#endif // ARGS_HPP

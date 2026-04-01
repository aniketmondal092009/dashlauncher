
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>

#include "string.hpp"

static void printhelp() {
    println("this is help text");
    println("");
}

static void getadditional(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            printhelp();
        }
    }
}

#endif

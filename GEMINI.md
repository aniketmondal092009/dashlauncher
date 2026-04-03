# GEMINI.md

This file provides context and guidelines for developing the `dashlauncher` project.

## Project Overview

**dashlauncher** (binary name: `dash`) is a lightweight X11-based application launcher, inspired by `dmenu` and `tofi`. It prioritizes the "suckless" philosophy of simplicity and speed, while being implemented in C++ for better modularity.

- **Main Technologies:** C++, X11 (Xlib).
- **Architecture:** Modular design with a clear separation between declarations (`include/`) and implementations (`src/`).

### Directory Structure
- `include/`: Header files (`.hpp`).
- `src/`: Source files (`.cpp`).
- `Makefile`: Build configuration.
- `README.md`: Project vision and user-facing documentation.

---

## Building and Running

The project uses a standard `Makefile` for compilation and installation.

### Key Commands
- **Build:** `make`
  - Compiles the source files and links the X11 library to produce the `dash` binary.
- **Clean:** `make clean`
  - Removes object files (`.o`) and the compiled binary.
- **Install:** `sudo make install`
  - Installs the `dash` binary to `/usr/local/bin/`.

---

## Development Conventions

### Coding Style
- **Namespacing:** All core logic should reside within the `launcher` namespace to avoid naming collisions.
- **Header Guards:** Use `#ifndef SYMBOL_HPP` guards in all header files.
- **Modularity:** Encapsulate distinct functionalities (e.g., window management, argument parsing) into separate classes or modules.

### Future Implementation Notes
- **Application Searching:** New logic for scanning `$PATH` or `.desktop` files should be added as a separate module in `src/search.cpp` and `include/search.hpp`.
- **UI Rendering:** Future font support (e.g., Xft) and layout logic should be integrated into the `XWindow` class or a dedicated `Renderer` class.

### Dependencies
- **X11:** Ensure `libx11-dev` (or equivalent) is installed on the development system.

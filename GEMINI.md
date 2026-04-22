# GEMINI.md

This file provides context and guidelines for developing the `dashlauncher` project.

## Project Overview

**dashlauncher** (binary name: `dash`) is a lightweight X11-based application launcher, inspired by `dmenu` and `tofi`. It prioritizes a modular and modern C++ approach for maintainability and scalability.

- **Main Technologies:** C++, X11 (Xlib).
- **Architecture:** Modular structure with separate header and implementation files. The main UI component is the `MenuWindow` class.

### Directory Structure
- `include/`: Header files (`.hpp`).
- `src/`: Implementation files (`.cpp`).
- `main.cpp`: The application entry point.
- `Makefile`: Build configuration.
- `README.md`: Project vision and user-facing documentation.
- `compile_flags.txt`: Used for LSP (like `clangd`) support.

---

## Building and Running

The project uses a standard `Makefile` for compilation and installation.

### Key Commands
- **Build:** `make`
  - Compiles the source files and links the X11 library to produce the `dash` binary.
- **Clean:** `make clean`
  - Removes the compiled binary and temporary files.
- **Install:** `sudo make install`
  - Installs the `dash` binary to `/usr/local/bin/`.

---

## Development Conventions

### Windowing Behavior
- **Centering:** The launcher automatically calculates screen dimensions and centers its window.
- **Override Redirect:** The window bypasses the window manager (`override_redirect = True`), which is standard for launcher applications to ensure it is always on top.

### Coding Style
- **Modular Architecture:** Organize code into logical components using classes and namespaces where appropriate to ensure clean separation of concerns.
- **Header Guards:** Use `#ifndef SYMBOL_HPP` guards in all header files.
- **Modularity:** Encapsulate distinct functionalities into clear classes (e.g., `MenuWindow`) or dedicated source files.

### Future Implementation Notes
- **Application Searching:** New logic for scanning `$PATH` or `.desktop` files should be implemented in `main.cpp` (or a dedicated `src/` file if `main.cpp` exceeds ~500 lines).
- **UI Rendering:** Future font support (e.g., Xft) and advanced layout logic should be integrated into the `MenuWindow` class.

### Dependencies
- **X11:** Ensure `libx11-dev` (or equivalent) is installed on the development system.


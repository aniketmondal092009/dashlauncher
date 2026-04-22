# Architectural Review & Fixes

This document outlines the current issues identified in the `dashlauncher` project and provides a roadmap for aligning with a modern, modular C++ architecture.

## 🚩 Key Problems Found

1.  **Broken Entry Point:** 
    *   `src/main.cpp` calls `win.run()`, but the `MenuWindow` class (in `include/window.hpp`) only defines a `loop()` method. This will cause a compilation error.
2.  **Duplicate/Conflicting Loops:**
    *   **C++ Version:** `MenuWindow::loop()` (in `src/window.cpp`).
    *   **C-style Version:** `src/loop.cpp` (Dead code).
    *   `src/loop.cpp` relies on functions (`cleanup`, `drw_map`, `grabfocus`, `keypress`) that are declared but not implemented anywhere.
3.  **Empty Header:** 
    *   `main.cpp` includes `args.hpp`, but that file is currently empty, even though the `get_args` function is implemented directly in `main.cpp`.
4.  **Architectural Drift:** 
    *   The project structure is inconsistent, with logic scattered across mismatched C and C++ styles.

---

## ✅ Recommended Fixes

### 1. Consolidate Logic
*   **Action:** Transition toward a fully Object-Oriented approach for window management.
*   **Recommendation:** Move all logic into the `MenuWindow` class and delete the procedural `src/loop.cpp` and `include/loop.hpp` files entirely.

### 2. Fix Entry Point
*   **Action:** In `src/main.cpp`, change the call from `win.run()` to `win.loop()`.

### 3. Clean up Argument Handling
*   **Action:** Move the `get_args` implementation into a dedicated `src/args.cpp` and declare it in `include/args.hpp`.

### 4. Modular C++ Alignment
*   **Action:** Ensure each class has its own header/source pair. 
*   **Note:** Use the `Makefile` to compile all `.cpp` files separately and link them, avoiding Unity Builds to maintain clean compilation boundaries.

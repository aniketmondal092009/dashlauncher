# dashlauncher (`dash`)

`dashlauncher` is a lightweight, X11-based application launcher inspired by tools like `dmenu` and `tofi`. It follows the "suckless" philosophy of simplicity and speed, implemented in C++ for a clean, modular codebase.

## Features
- **Minimalist Design:** Focuses on speed and zero bloat.
- **Auto-Centering:** Automatically calculates screen dimensions to center the launcher window.
- **Always on Top:** Uses `override_redirect` to bypass window managers, ensuring it's always accessible.
- **Modular C++:** Designed for easy extension and maintenance.

## Requirements
- `g++` or `clang++` (supporting C++17)
- `X11` development libraries (`libx11-dev` on Debian/Ubuntu)
- `make`

## Installation

### Build
To compile the `dash` binary:
```bash
make
```

### Install
To install the binary to `/usr/local/bin`:
```bash
sudo make install
```

## Usage
Simply run the binary:
```bash
dash
```

### Options
- `-h`, `--help`: Show usage information.
- `-v`, `--version`: Show version information.

## License
MIT

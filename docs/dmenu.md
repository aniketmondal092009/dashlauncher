# dmenu Core Functions

---

## 1. Initialization and Setup

### `main(int argc, char *argv[])`

**Purpose:**  
The entry point of the application.

**Details:**
- Parses command-line arguments to configure `dmenu`'s appearance and behavior 
(e.g., font, colors, prompt, case-insensitivity, monitor selection).
- Initializes the X11 display connection (`XOpenDisplay`).
- Creates a drawing context (`drw_create`).
- Loads fonts using `drw_fontset_create`.
- Reads all potential menu items from standard input using `readstdin()`.
- Grabs the keyboard exclusively for input.
- Calls `setup()` to create the main menu window and its initial UI.
- Finally, enters the `run()` function to start processing X11 events.

---

### `setup(void)`

**Purpose:**  
Initializes the graphical environment and creates the `dmenu` window.

**Details:**
- Sets up color schemes for different UI elements.
- Defines X11 atoms for clipboard operations and UTF-8 strings.
- Calculates the menu's geometry (width, height) based on:
  - Screen resolution
  - Monitor index
  - Font metrics
  - `lines` configuration
- Creates the main menu window (`win`) using Xlib:
  - Uses `override_redirect` so it stays on top and bypasses window managers
- Initializes X Input Method (XIM) for handling international characters.
- Calls:
  - `match()` → filter items
  - `drawmenu()` → render initial UI

---

## 2. Input and Matching Logic

### `readstdin(void)`

**Purpose:**  
Populates the `items` list by reading lines from standard input.

**Details:**
- Reads lines using `getline`.
- For each line:
  - Allocates memory
  - Duplicates the string
  - Stores it in `items` as a `struct item`
- Ensures `lines` does not exceed number of items read.

---

### `match(void)`

**Purpose:**  
Filters the `items` list based on user input (`text`) and builds `matches`.

**Details:**
- Tokenizes input text.
- Iterates through all items.
- Keeps items that match all tokens.
- Matching types:
  - Exact match
  - Prefix match
  - Substring match
- Priority order:
exact → prefix → substring

- Updates:
- `curr` → first visible item
- `sel` → selected item
- Calls `calcoffsets()`.

---

### `insert(const char *str, ssize_t n)`

**Purpose:**  
Inserts text into the input buffer.

**Details:**
- Inserts at current `cursor` position.
- Moves existing text using `memmove`.
- Copies new text using `memcpy`.
- Updates `cursor`.
- Calls `match()` to refresh results.

---

### `keypress(XKeyEvent *ev)`

**Purpose:**  
Handles all keyboard input.

**Details:**
- Converts key events to `KeySym`.
- Handles:
- Normal typing → calls `insert()`
- Control keys (e.g., `Ctrl+a`, `Ctrl+k`)
- Alt key combinations
- Navigation keys:
- `Up`, `Down`, `Left`, `Right`
- `Home`, `End`
- `PageUp`, `PageDown`
- Special behavior:
- `Enter` → prints selected item or input text, then exits
- `Escape` → exits immediately
- Calls `drawmenu()` after handling input.

---

### `movewordedge(int dir)`

**Purpose:**  
Moves cursor by word boundaries.

**Details:**
- Uses `worddelimiters` to detect word edges.
- `dir < 0` → move left  
- `dir > 0` → move right  

---

## 3. Rendering and Display

### `drawmenu(void)`

**Purpose:**  
Renders the entire menu UI.

**Details:**
- Draws:
- Background
- Prompt
- Input text
- Cursor indicator
- Displays visible items (`curr → next`).
- Supports:
- Vertical layout (`lines > 0`)
- Horizontal layout (`lines == 0`)
- Uses `drw_map()` to display on screen.

---

### `drawitem(struct item *item, int x, int y, int w)`

**Purpose:**  
Draws a single item.

**Details:**
- Chooses color scheme:
- `SchemeNorm` → normal
- `SchemeSel` → selected
- `SchemeOut` → marked
- Uses `drw_text()` to render text.

---

### `calcoffsets(void)`

**Purpose:**  
Controls pagination and visible range.

**Details:**
- Calculates:
- `prev`
- `curr`
- `next`
- Ensures selected item is visible.
- Handles scrolling.

---

## 4. Event Loop and Cleanup

### `run(void)`

**Purpose:**  
Main event loop.

**Details:**
- Uses `XNextEvent` to wait for events.
- Dispatches events:
- `KeyPress` → `keypress()`
- `Expose` → redraw window
- `FocusIn` → regain focus
- `SelectionNotify` → paste handling
- `DestroyNotify` → cleanup and exit
- `VisibilityNotify` → raise window if hidden

---

### `cleanup(void)`

**Purpose:**  
Frees resources and exits cleanly.

**Details:**
- Ungrabs keyboard
- Frees:
- Color schemes
- Items and their text
- Drawing context (`drw_free`)
- Closes X display (`XCloseDisplay`)

---

## 📌 Summary

This structure makes `dmenu`:

- ⚡ Fast (linear scan)
- 🧩 Simple (minimal abstractions)
- 🎯 Responsive (instant filtering)
- 🖥️ Native (pure X11)

---

This design is a great example of **minimal, efficient system programming in C**.

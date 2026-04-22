

#include <X11/Xlib.h>

void loop();
void cleanup();
void paste();

struct Drw {
};


static int mh, mw;


void grabfocus();

void keypress(XKeyEvent *ev);

void drw_map(Drw *drw, Window win, int x, int y, unsigned int w, unsigned int h);


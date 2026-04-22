

#include <X11/Xlib.h>
#include "loop.hpp"


static Display *dpy;
static Window win;
static Drw *drw;

static Atom utf8;

#include <stdlib.h>

void loop(void) {
	XEvent event;

	while (!XNextEvent(dpy, &event)) {
		if (XFilterEvent(&event, win))
			continue;
		switch(event.type) {
		case DestroyNotify:
			if (event.xdestroywindow.window != win)
				break;
			cleanup();
			exit(1);
		case Expose:
			if (event.xexpose.count == 0)
				drw_map(drw, win, 0, 0, mw, mh);
			break;
		case FocusIn:
			/* regrab focus from parent window */
			if (event.xfocus.window != win)
				grabfocus();
			break;
		case KeyPress:
			keypress(&event.xkey);
			break;
		case SelectionNotify:
			if (event.xselection.property == utf8)
				paste();
			break;
		case VisibilityNotify:
			if (event.xvisibility.state != VisibilityUnobscured)
				XRaiseWindow(dpy, win);
			break;
		}
	}
}



/* window management */
#ifndef WINDOW_H
#define WINDOW_H

/* gtk */
#include <gtk/gtk.h>

/* to hold a window's properties */
typedef struct {
	int w; /* width */
	int h; /* height */
	char *t; /* title */
	GtkWidget *win; /* window widget pointer */
	GtkWidget *menubar; /* menu bar */
	GtkWidget *filemenu; /* file menu */
	GtkWidget *filelabel; /* file menu label */
	GtkWidget *quitlabel; /* quit label */
	GtkWidget *vbox; /* vertical box */
} window;

/* create a window */
extern void window_create(window *, char *, int, int);

/* add a widget to the window container */
extern void window_add(window *, GtkWidget *, gboolean, gboolean);

/* show a window */
extern void window_show(window *);

/* event to destroy window */
extern void destroy_event(GtkWidget *, gpointer d);

#endif /* WINDOW_H */

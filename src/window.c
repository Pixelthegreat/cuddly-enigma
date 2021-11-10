/* window system */
#include "window.h"
#include <stdio.h>

/* other forward declarations */
extern void destroy_event(GtkWidget *, gpointer); /* destroy window */

/* create a window */
extern void window_create(window *win, char *t, int w, int h) {

	/* set values */
	win->t = t;
	win->w = w;
	win->h = h;

	/* create a window */
	win->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/* create a destroy event */
	g_signal_connect(G_OBJECT(win->win), "destroy", G_CALLBACK(destroy_event), NULL);

	/* create a container */
	gtk_container_set_border_width(GTK_CONTAINER(win->win), 10);
	gtk_widget_set_size_request(win->win, w, h);
	gtk_window_set_resizable(GTK_WINDOW(win->win), FALSE);
	gtk_window_set_title(GTK_WINDOW(win->win), t);

	/* box */
	win->vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(win->win), win->vbox);
}

/* destroy window */
extern void destroy_event(GtkWidget *w, gpointer d) {

	/* just quit */
	gtk_main_quit();
}

/* add a widget */
extern void window_add(window *win, GtkWidget *wx, gboolean expand, gboolean fill) {

	/* add to container */
	gtk_box_pack_start(GTK_BOX(win->vbox), wx, expand, fill, 1);

	/* show widget */
	gtk_widget_show(wx);
}

/* display window */
extern void window_show(window *win) {

	/* show vertical box */
	gtk_widget_show(win->vbox);

	/* show main widget */
	gtk_widget_show(win->win);
}

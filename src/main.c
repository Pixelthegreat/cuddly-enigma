#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

/* window */
#include "window.h"

void hello(GtkWidget *w, gpointer d) {

	/* print message */
	printf("Hello World\n");
}

/* main function */
int main(int argc, char *argv[]) {

	/* initialise gtk */
	gtk_init(&argc, &argv);

	/* create window */
	window w;
	window_create(&w, "Cuddly Enigma", 640, 480);

	/* create toolbar */
	GtkWidget *toolbar = gtk_toolbar_new();
	GtkWidget *ico1 = gtk_image_new_from_file("icons/close32.png");
	GtkToolItem *tb1 = gtk_tool_button_new(ico1, NULL);

	g_signal_connect(G_OBJECT(tb1), "clicked", G_CALLBACK(destroy_event), NULL);

	/* set toolbar attributes */
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tb1, 0);
	gtk_widget_show_all(toolbar);

	/* create text view */
	GtkWidget *text = gtk_text_view_new();

	/* set text view attributes */
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text), GTK_WRAP_WORD);
	gtk_widget_modify_font(text, pango_font_description_from_string("Liberation Serif"));

	/* add widget */
	window_add(&w, toolbar, FALSE, FALSE);
	window_add(&w, text, TRUE, TRUE);

	/* show window */
	window_show(&w);

	gtk_main();

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>


void detruire(GtkWidget *pF, gpointer data){
    gtk_main_quit();
}

int main(int argc, char **argv){
    gtk_init(&argc, &argv);

    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(detruire), NULL);
    gtk_widget_show(window);

    gtk_main();


return EXIT_SUCCESS;
}//end main()
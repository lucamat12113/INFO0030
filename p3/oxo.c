#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

GtkWidget *creer_fenetre(){
  GtkWidget *pF = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(pF), "Un Menu Complexe");
  gtk_window_set_default_size(GTK_WINDOW(pF), 320, 200);

  g_signal_connect(G_OBJECT(pF), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  return pF;
}//fin creer_fenetre()

GtkWidget *creer_menu(GtkWidget *pFenetre){
  //Déclaration des variables
  GtkWidget *barre_menu;
  GtkWidget *menu_fichier;
  GtkWidget *item_fichier;
  GtkWidget *item_nouveau;
  GtkWidget *item_ouvrir;
  GtkWidget *item_quitter;
  GtkWidget *item_separateur;
  GtkAccelGroup *accelerateur = NULL;

  //barre de menu
  barre_menu = gtk_menu_bar_new();

  //le menu "Fichier"
  menu_fichier = gtk_menu_new();

  //accélérateur
  accelerateur = gtk_accel_group_new();
  gtk_window_add_accel_group(GTK_WINDOW(pFenetre), accelerateur);

  //création des items avec images
  item_fichier = gtk_menu_item_new_with_mnemonic("_Fichier");
  item_nouveau = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  item_ouvrir = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
  item_separateur = gtk_separator_menu_item_new();
  item_quitter = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accelerateur);

  gtk_widget_add_accelerator(item_quitter, "activate", accelerateur,
  GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

  //attacher les items
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(item_fichier), menu_fichier);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_nouveau);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_ouvrir);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_separateur);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_quitter);
  gtk_menu_shell_append(GTK_MENU_SHELL(barre_menu), item_fichier);

  //les signaux
  g_signal_connect(G_OBJECT(item_quitter), "activate", G_CALLBACK(gtk_main_quit), NULL);

  return barre_menu;
}//fin creer_menu()

int main( int argc, char **argv){
  GtkWidget *pFenetre;
  GtkWidget *pBarreMenu;
  GtkWidget *vBox;

  gtk_init(&argc, &argv);

  pFenetre = creer_fenetre();
  pBarreMenu = creer_menu(pFenetre);

  vBox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(pFenetre), vBox);

  gtk_box_pack_start(GTK_BOX(vBox), pBarreMenu, FALSE, FALSE, 3);

  gtk_widget_show_all(pFenetre);

  gtk_main();

  return EXIT_SUCCESS;
}//fin main()

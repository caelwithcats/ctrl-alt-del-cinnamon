// CAD: Ctrl + Alt + Delete
// Compile Using: g++ cad.cpp  `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`  -std=gnu++17

#include <iostream>
#include <gtk/gtk.h>
GtkWidget* lockBtn;
GtkWidget* logoutBtn;
GtkWidget* sysMonitorBtn;
GtkWidget* window;
void lockEvent(GtkWidget *widget, gpointer data){
gtk_widget_destroy(window);
system("cinnamon-screensaver-command -l; xset dpms force off;");
}
void logoutEvent(GtkWidget *widget, gpointer data){
gtk_widget_destroy(window);
system("pkill -KILL -u $(whoami)");
}
void sysMonitorEvent(GtkWidget *widget, gpointer data){
gtk_widget_destroy(window);

system("gnome-system-monitor");
}
int main(){
gtk_init(NULL,NULL);
GtkBuilder* gladeBuilder;
gladeBuilder = gtk_builder_new();
gtk_builder_add_from_file(gladeBuilder, "ctrl+alt+del.glade",NULL);
lockBtn = GTK_WIDGET(gtk_builder_get_object(gladeBuilder, "lockBtn"));
logoutBtn = GTK_WIDGET(gtk_builder_get_object(gladeBuilder, "logoutBtn"));
sysMonitorBtn = GTK_WIDGET(gtk_builder_get_object(gladeBuilder, "lockBtn"));
window = GTK_WIDGET(gtk_builder_get_object(gladeBuilder, "window"));
g_object_unref(G_OBJECT(gladeBuilder));
gtk_widget_show(window);

g_signal_connect(G_OBJECT(lockBtn), "clicked", G_CALLBACK(lockEvent), NULL);
g_signal_connect(G_OBJECT(logoutBtn), "clicked", G_CALLBACK(logoutEvent), NULL);
g_signal_connect(G_OBJECT(sysMonitorBtn), "clicked", G_CALLBACK(sysMonitorEvent), NULL);
g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
gtk_main();
}

#include <gtk/gtk.h>
#include <iostream>

int main() {
	
	GtkApplication* app;
	app = gtk_application_new("in.id", G_APPLICATION_FLAGS_NONE);

	//g_signal_connect();

	std::cout << "ug\n" ;
}
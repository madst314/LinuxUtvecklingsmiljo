#include <stdlib.h>
#include <gtk/gtk.h>

#define UNUSED(x) (void)(x)

typedef struct UserInput {
   GtkSpinButton *total_voltage;
   GtkSpinButton *resistance_component1;
   GtkSpinButton *resistance_component2;
   GtkSpinButton *resistance_component3;
} UserInput;

static void compute_callback(GtkWidget *widget, gpointer data)
{
   UserInput* user_input = (UserInput*)data;
   gdouble voltage = gtk_spin_button_get_value(user_input->total_voltage);
   gdouble resistance1 = gtk_spin_button_get_value(user_input->resistance_component1);
   gdouble resistance2 = gtk_spin_button_get_value(user_input->resistance_component2);
   gdouble resistance3 = gtk_spin_button_get_value(user_input->resistance_component3);
   printf("value is %d \n", voltage);
   UNUSED(widget);
}

static void quit_callback()
{
   g_print ("You quit the program. Thank you\n");
}

static gboolean delete_event()
{
   /* If you return FALSE in the "delete-event" signal handler,
    * will emit the "destroy" signal. Returning TRUE means
    * you don't want the window to be destroyed.
    * This is useful for popping up 'are you sure you want to quit?'
    * type dialogs. */

   g_print ("delete event occurred\n");

   /* Change TRUE to FALSE and the main window will be destroyed with
    *  a "delete-event". */

   return TRUE;
}

/* Another callback */
static void destroy()
{
   gtk_main_quit ();
}

int main( int   argc,
          char *argv[] )
{
   /* Declaration of widgets */
   GtkWidget *window;
   GtkWidget *button_quit;
   GtkWidget *button_compute;
   GtkWidget *table;

   GtkObject *adjust_voltage;
   GtkObject *adjust_comp1;
   GtkObject *adjust_comp2;
   GtkObject *adjust_comp3;

   GtkWidget *entry_voltage;
   GtkWidget *entry_comp1;
   GtkWidget *entry_comp2;
   GtkWidget *entry_comp3;

   GtkWidget *label_voltage;
   GtkWidget *label_comp1;
   GtkWidget *label_comp2;
   GtkWidget *label_comp3;
   GtkWidget *box = gtk_hbox_new(0,0);

   UserInput *user_input = malloc(4 * sizeof(GtkWidget));
   gtk_init (&argc, &argv);

   /* create a new window */
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_widget_set_size_request (GTK_WIDGET (window), 1000, 500);
   gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
   gtk_container_set_border_width (GTK_CONTAINER (window), 10);

   /* When the window is given the "delete-event" signal (this is given
    * by the window manager, usually by the "close" option, or on the
    * titlebar), we ask it to call the delete_event () function
    * as defined above. The data passed to the callback
    * function is NULL and is ignored in the callback function. */
   g_signal_connect (window, "delete-event",
                     G_CALLBACK (delete_event), NULL);

   /* Here we connect the "destroy" event to a signal handler.
    * This event occurs when we call gtk_widget_destroy() on the window,
    * or if we return FALSE in the "delete-event" callback. */
   g_signal_connect (window, "destroy",
                     G_CALLBACK (destroy), NULL);

   /* create table */
   table = gtk_table_new(5, 3, TRUE);

   /* crate labels */
   label_voltage = gtk_label_new("Total Voltage");
   label_comp1 = gtk_label_new("Component 1");
   label_comp2 = gtk_label_new("Component 2");
   label_comp3 = gtk_label_new("Component 3");

   /* create entries for user input */
   adjust_voltage = gtk_adjustment_new(0, 0, 1000, 1, 1, 10);
   adjust_comp1 = gtk_adjustment_new(0, 0, 1000, 1, 1, 10);
   adjust_comp2 = gtk_adjustment_new(0, 0, 1000, 1, 1, 10);
   adjust_comp3 = gtk_adjustment_new(0, 0, 1000, 1, 1, 10);

   entry_voltage = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_voltage), 0.1, 0);
   entry_comp1 = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_comp1), 0.1, 0);
   entry_comp2 = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_comp2), 0.1, 0);
   entry_comp3 = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_comp3), 0.1, 0);

   button_quit = gtk_button_new_with_label ("Quit");
   button_compute = gtk_button_new_with_label ("Compute");

   user_input->total_voltage = (GtkSpinButton*)entry_voltage;
   user_input->resistance_component1 = (GtkSpinButton*)entry_comp1;
   user_input->resistance_component2 = (GtkSpinButton*)entry_comp2;
   user_input->resistance_component3 = (GtkSpinButton*)entry_comp3;

   /* When the button receives the "clicked" signal, it will call the
    * callback adn passing it NULL as its argument.
    */
   g_signal_connect (button_quit, "clicked",
                     G_CALLBACK (quit_callback), NULL);
   g_signal_connect (button_compute, "clicked",
                     G_CALLBACK(compute_callback),
                     user_input);

   /* This will cause the window to be destroyed by calling
    * gtk_widget_destroy(window) when "clicked".
    */
   g_signal_connect_swapped (button_quit, "clicked",
                             G_CALLBACK (gtk_widget_destroy),
                             window);

   /* Add to widgets to table*/
   gtk_table_attach(GTK_TABLE(table), label_voltage, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), label_comp1, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), label_comp2, 0, 1, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), label_comp3, 0, 1, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);

   gtk_table_attach(GTK_TABLE(table), entry_voltage, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), entry_comp1, 1, 2, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), entry_comp2, 1, 2, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), entry_comp3, 1, 2, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);

   gtk_table_attach(GTK_TABLE(table), button_quit, 2, 3, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), button_compute, 2, 3, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);

   /* Add box to window and table to box */
   gtk_container_add(GTK_CONTAINER(window), box);
   gtk_container_add (GTK_CONTAINER (box), table);

   /* Display widgets. */
   //gtk_widget_show (button_quit);
   //gtk_widget_show (window);
   //gtk_widget_show (entry_voltage);
   gtk_widget_show_all(window);

   gtk_main ();

   free(user_input);

   return 0;
}

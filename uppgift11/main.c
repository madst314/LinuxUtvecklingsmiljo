#include <stdlib.h>
#include <gtk/gtk.h>

#include "libcomponent.h"
#include "libresistance.h"
#include "libpower.h"

#define UNUSED(x) (void)(x)

typedef struct UserInput {
   GtkSpinButton *gtk_spin_buttons[4];
   GtkToggleButton *button_parallel;
   GtkTextBuffer *buffer;
} UserInput;

static void compute_callback(GtkWidget *widget, gpointer data)
{
   float resistances[3] = {0};
   float e12_resistances[3] = {0};
   int numComponents = 0;
   int num_e12 = 0;
   char circuitType = 'p';
   float total_resistance = 0.f;
   float power = 0;
   int idx;

   UserInput* user_input = (UserInput*)data;
   const gdouble voltage = gtk_spin_button_get_value(user_input->gtk_spin_buttons[0]);
   const gboolean isParallel =  gtk_toggle_button_get_active(user_input->button_parallel);

   /* set circuit type */
   if (!isParallel)
   {
      circuitType = 's';
   }

   /* get num of components and their resistances*/
   for (idx = 0; idx < 3; idx++)
   {
      const float resistance = gtk_spin_button_get_value(user_input->gtk_spin_buttons[idx + 1]);
      if (resistance > 0)
      {
         resistances[numComponents] = resistance;
         numComponents++;
      }
   }

   if (numComponents!=0)
   {
      /* calculate resulting resistance */
      total_resistance = calc_resistance(numComponents, circuitType, &resistances[0]);

      /* calculate power */
      power = calc_power_r(voltage, total_resistance);

      /* calculate E12 resistances */
      num_e12 = e_resistance(total_resistance, &e12_resistances[0]);
   }

   gtk_text_buffer_set_text (user_input->buffer, "Hello, this is some text", -1);
   printf("Components are: %f, %f, %f \n", resistances[0], resistances[1], resistances[2]);
   printf("Number of components: %d \n", numComponents);
   printf ("calculated res is %f\n", total_resistance);
   printf("POwer is %f \n", power);

   printf("E12 %d %f, %f, %f \n", num_e12, e12_resistances[0], e12_resistances[1], e12_resistances[2]);
   UNUSED(widget);
}

static void quit_callback()
{
   g_print ("You quit the program. Thank you\n");
}

static gboolean delete_event()
{
   return FALSE;
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
   GtkWidget *button_parallel;
   GtkWidget *button_serial;
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

   GtkWidget *view;
   GtkTextBuffer *buffer;

   UserInput *user_input = malloc(sizeof(UserInput));
   gtk_init (&argc, &argv);

   /* create a new window */
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_widget_set_size_request (GTK_WIDGET (window), 700, 500);
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
   table = gtk_table_new(6, 4, TRUE);

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

   /* Entries for voltage and resistances */
   entry_voltage = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_voltage), 0.1, 0);
   entry_comp1 = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_comp1), 0.1, 0);
   entry_comp2 = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_comp2), 0.1, 0);
   entry_comp3 = gtk_spin_button_new(GTK_ADJUSTMENT(adjust_comp3), 0.1, 0);
   gtk_spin_button_set_digits ((GtkSpinButton*)entry_voltage, 1);
   gtk_spin_button_set_digits ((GtkSpinButton*)entry_comp1, 1);
   gtk_spin_button_set_digits ((GtkSpinButton*)entry_comp2, 1);
   gtk_spin_button_set_digits ((GtkSpinButton*)entry_comp3, 1);

   /* Buttons */
   button_quit = gtk_button_new_with_label ("Quit");
   button_compute = gtk_button_new_with_label ("Compute");

   /* Radio Buttons */
   button_parallel =
      gtk_radio_button_new_with_label_from_widget(
         NULL, "parallel");
   button_serial =
      gtk_radio_button_new_with_label_from_widget(
         GTK_RADIO_BUTTON(button_parallel), "serial");
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button_parallel), TRUE);

   /* Set up output text window */
   view = gtk_text_view_new ();
   buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));


   /* set UserInput struct */
   user_input->gtk_spin_buttons[0] = (GtkSpinButton*)entry_voltage;
   user_input->gtk_spin_buttons[1] = (GtkSpinButton*)entry_comp1;
   user_input->gtk_spin_buttons[2] = (GtkSpinButton*)entry_comp2;
   user_input->gtk_spin_buttons[3] = (GtkSpinButton*)entry_comp3;
   user_input->button_parallel = GTK_TOGGLE_BUTTON(button_parallel);
   user_input->buffer = buffer;

   /* When the button receives the "clicked" signal, it will call the
    * callback and passing it NULL as its argument.
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
   gtk_table_attach(GTK_TABLE(table), button_parallel, 0, 1, 4, 5, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), button_serial, 1, 2, 4, 5, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);
   gtk_table_attach(GTK_TABLE(table), view, 2, 4, 2, 6, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK,5, 5);

   /* Add box to window and table to box */
   gtk_container_add(GTK_CONTAINER(window), box);
   gtk_container_add (GTK_CONTAINER (box), table);

   /* Display widgets. */
   gtk_widget_show_all(window);

   gtk_main ();

   free(user_input);

   return 0;
}

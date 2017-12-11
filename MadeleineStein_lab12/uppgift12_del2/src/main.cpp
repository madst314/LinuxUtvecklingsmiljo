

//============================================================================
// Name        : Fractal.cpp
// Author      : S. Ronnback
// Version     : v 0.1
// Copyright   :
// Description : Mandelbrot calculator using GTK+
//============================================================================


#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <glib.h>

#include "ComplexZ.h"
#include "mandelbrot.h"
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif


// Structure that holds the default size of the fractal window

struct sFRACTAL
{
	GdkVisual* pGDKvisual2;
	GdkImage* pGDKimage2;
	GtkWidget *pWindow2;
	GtkWidget* pImage2;

} sFractal={0,0,0,0};


/*
static gboolean on_expose_event(GtkWidget *pWidget, GdkEventExpose *pEvent, gpointer data)
{
  printf("Exposed\n"); // %f,%f\n",pEvent->x, pEvent->y);
  return FALSE;
}
 */


/**
 *  Function that tracks the mouse pointer on the screen
 *
 * @param widget
 * @return
 */
static gboolean time_handler( GtkWidget *widget)
{

	GdkDisplay *pDisplay = gdk_display_get_default ();
	//  GdkScreen *pScreen= gdk_display_get_default_screen (pDisplay);

	/* get cursor position */
	int iX,iY;
	gdk_display_get_pointer(pDisplay, NULL, &iX, &iY, NULL);
	printf("X:%d Y:%d\n",iX,iY);

	return TRUE;
}


/*
static GtkWidget* create_image (void)
{
  GtkWidget *pImage = gtk_image_new_from_file ("/home/sr/boulevard.jpg");
  GtkWidget *pEvent_box = gtk_event_box_new ();
  gtk_container_add (GTK_CONTAINER (pEvent_box), pImage);

  //g_signal_connect (G_OBJECT (pEvent_box),"button_press_event",G_CALLBACK (button1_press_callback),pImage);
  return pImage;
}
 */

/**
 *
 */
static void fractal_destroy(void)
{
	gtk_main_quit();
}


/**
 *	Function is called when the fractal window is called.
 *
 * @param widget	Calling widget. Box widget.
 * @param data
 */
void fractal_clicked(GtkWidget *widget, gpointer data)
{

	printf("Fraktalen klickades.\n");
	/*
  if (event->type == GDK_BUTTON_PRESS)
   {
     if (event->button == 1) {
  //     gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)),event->button,
 //	  event->x_root,
 //	  event->y_root,
 //	  event->time);
     }
   }
	 */

}


/**
 *	Function that calculates a fractal and shows it in a GTK+ pixbuf
 *
 * @param[in] 	_oZmid		Center coordinate for the Mandelbrot fractal
 * @param[in] 	_oZxy		Size of the Mandelbrot window
 * @param[in] 	_rZoomFactor	Zoom factor ( Deduces the size of the window)
 * @return		Returns true success, otherwise false
 */
bool
bCalc_Fractal( ComplexZ &_oZmid, ComplexZ &_oZxy, double _rScale)
{
	// Create fractal
	int iSizeX=800;
	int iSizeY=800;
	Fractal  *poFractal= new Cmandelbrot( iSizeX, iSizeY);
	//Fractal  *poFractal= new Fractal( iSizeX, iSizeY);

	if(!poFractal)
			return false;

	bool bRet=poFractal->bCalc(_oZmid,_oZxy,_rScale, 255);

	if (sFractal.pGDKimage2 == NULL ) {
		sFractal.pGDKvisual2 = gdk_visual_get_system();
		sFractal.pGDKimage2= gdk_image_new( GDK_IMAGE_NORMAL, sFractal.pGDKvisual2, poFractal->iSizeX,poFractal->iSizeY);
	}

	if (sFractal.pGDKimage2 == NULL ) {
		fprintf( stderr, "Not able to create gdkimage object\n");
		return FALSE;
	}

	if(sFractal.pWindow2== NULL){
		sFractal.pWindow2= gtk_window_new(GTK_WINDOW_TOPLEVEL);
	}
	if(sFractal.pImage2==NULL){
		sFractal.pImage2= gtk_image_new_from_image( sFractal.pGDKimage2, NULL );
	}

	for (int i=0; i<poFractal->iSizeX; i++) {
		for (int j=0; j<poFractal->iSizeY; j++) {
			unsigned int uiColor = poFractal->uiGetPixBufColor(i,j);
			gdk_image_put_pixel( sFractal.pGDKimage2, i, j,(int) uiColor); //65535*rAbsSqr/rMax);
		}
	}
	GtkWidget *pEvent_box = gtk_event_box_new ();
	gtk_container_add (GTK_CONTAINER (pEvent_box), sFractal.pImage2);


	gtk_container_add(GTK_CONTAINER (sFractal.pWindow2), pEvent_box);

	gtk_widget_show_all(sFractal.pWindow2);
	gtk_window_set_title (GTK_WINDOW (sFractal.pWindow2), "Mandelbrotfraktal?");

	gtk_signal_connect(GTK_OBJECT (sFractal.pWindow2), "destroy",GTK_SIGNAL_FUNC (fractal_destroy), NULL);
	g_timeout_add(500, (GSourceFunc) time_handler, (gpointer) sFractal.pWindow2);

	g_signal_connect (G_OBJECT (pEvent_box),"button_press_event",G_CALLBACK (fractal_clicked),sFractal.pImage2);

	if(poFractal)
		delete poFractal;

	return bRet;
}





/**
 *	Function that creates a GTK+ GUI for the fractal.
 *
 * @return	Returns TRUE of GUI is created
 */

int iMakeFractalGUIControls(void)
{
	return TRUE;
}


/**
 *	Main function of Fractal program
 *
 * @param argc		Holds number of arguments
 * @param argv		String array with arguments
 * @return			returns 0 in success
 */

int main(int argc,char *argv[])
{

	gtk_init(&argc, &argv);

	ComplexZ oZmid(-0.6,.4);
	ComplexZ oZxy(2,2);

/*
	ComplexZ oZmid(-0.759856,.125547);
	ComplexZ oZxy(0.05179,0.03);
	*/
//	bool bRet=bCalc_Fractal(oZmid,oZxy,10.0);
	bool bRet=bCalc_Fractal(oZmid,oZxy,1.0);


	int iRet= iMakeFractalGUIControls();

	gtk_main();


	//	iOpenCV_Capture();
	return bRet?0:1;
}


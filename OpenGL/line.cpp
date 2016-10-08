// include the GLUT header file so we can access all the GLUT calls
#include <glut.h>
#include <string>
#include <iostream>
#include "movingQuad.h"

using namespace std;

movingQuad *quad1 = new movingQuad(15, 60, 150, 1);
movingQuad *quad2 = new movingQuad(10, 25, 20, 1);

int MAXHEIGHT = 237;
int MINHEIGHT = 13;
int MAXWIDTH = 237;
int MINWIDTH = 13;


void moveCheck(movingQuad* curQuad) {
	if (curQuad->getMaxX() >= MAXWIDTH) {
		curQuad->xGain = -1;
	}
	else if (curQuad->getMinX() <= MINWIDTH) {
		curQuad->xGain = 1;
	}

	if (curQuad->getMaxY() >= MAXHEIGHT) {
		curQuad->yGain = -1;
	}
	else if (curQuad->getMinY() <= MINHEIGHT) {
		curQuad->yGain = 1;
	}
}

// Create a method to hold all our drawing calls
// This function must be declared before the MAIN call so that MAIN knows it exists
// NOTE: read the contents of MAIN first, before reading the DISPLAY method. It will make more sense that way !
void display(void)
{
	// glClear sets the colour of the window to the colour previously define by
	// glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum
	glClear(GL_COLOR_BUFFER_BIT);
	// et the colour of any future objects we create
	// This colour will remain the active draw colour until we change it
	glColor3f(0.0, 0.0, 0.0);
	///////////////////////////////////////////////////
	//draw a line - START
	///////////////////////////////////////////////////
	//Start to crete a line primitive
	glLineWidth(6);
	glBegin(GL_LINES);
	// Now add in the vertices of the line
	glVertex2i(10, 10);
	glVertex2i(10, 240);
	glEnd(); 
	//declare that the line is now finished primitive

	glBegin(GL_LINES);
		glVertex2i(240, 10);
		glVertex2i(10, 10);
	glEnd();

	glBegin(GL_LINES);
		glVertex2i(240, 10);
		glVertex2i(240, 240);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(240, 240);
	glVertex2i(10, 240);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0, 1.0, 0.0, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(quad1->getMinX(), quad1->getMaxY()); //Top left
	glVertex2i(quad1->getMinX(), quad1->getMinY()); // Bottom left
	glVertex2i(quad1->getMaxX(), quad1->getMinY()); // Bottom right
	glVertex2i(quad1->getMaxX(), quad1->getMaxY()); // Top Right
	glEnd();

	moveCheck(quad1);
	quad1->move();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 0.0, 0.0, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(quad2->getMinX(), quad2->getMaxY()); //Top left
	glVertex2i(quad2->getMinX(), quad2->getMinY()); // Bottom left
	glVertex2i(quad2->getMaxX(), quad2->getMinY()); // Bottom right
	glVertex2i(quad2->getMaxX(), quad2->getMaxY()); // Top Right
	glEnd();

	moveCheck(quad2);
	quad2->move();
	
	glDisable(GL_BLEND);
	// Now process all the OpenGL commands as quickly as possible
	glutSwapBuffers();
}


void Timer(int iUnused) {
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 119: 
			std::cout << "test";
		break;
	}
}

// Create our windows applciation
void main(int argc, char *argv[])
{
	//Start the GLUT windowing system
	glutInit(&argc, argv);
	// Define settings for the display
	// GLUT_SINGLE = use a single rerfesh buffer
	// GLUT_RGB = use the RGB colour space
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Set the dimensions of all future windows.
	glutInitWindowSize(500, 500);
	// Set the position of the window. Origin is top left of screen
	glutInitWindowPosition(100, 100);
	// Create a window with a title
	glutCreateWindow("My Line");
	// Set the background colour of the window to white (red, green, blue, alpha)
	// RGB values in range of 0 to 1
	// Alpha channel used to blend two overlapping objects
	glClearColor(0.20, 0.20, 0.20, 0.0);
	// OpenGL assumes you are working with 3D graphcis by default
	// If we want to work in just 2D we have to tell OpenGL that we want to do this
	// We therefore tell OpenGL to 'project' the image onto a 2D plane.
	glMatrixMode(GL_PROJECTION);
	// Now setup the coordinate system for the projected image
	// (x min, x max, y min, y max)
	// Bottom left = (0,0) top right = (250,250)
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);


	// Process the 'display' method and pass the results to DisplayFunc
	// which will pass the results to the display window, ready to be displayed.
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);

	Timer(0);
	// The contents of the display window are not drawn immediately.
	// The following function displays the content.
	// This must be the last function in the program
	glutMainLoop();
}


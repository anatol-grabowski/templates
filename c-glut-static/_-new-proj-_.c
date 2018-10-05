#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define TIMERMSECS 33

void initialize(void);
void keyboardFunc(unsigned char key, int x, int y);
void displayFunc(void);
void animate(int value);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
	glutInitWindowSize(600, 200);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow("GLUT Test");
	initialize();
  glutKeyboardFunc(&keyboardFunc);
  glutDisplayFunc(&displayFunc);
	glutTimerFunc(TIMERMSECS, &animate, 0);
  glutMainLoop();
  return EXIT_SUCCESS;
}

void initialize() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 100.0, -1.1, 1.1, -1.0, 1.0);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void keyboardFunc(unsigned char key, int x, int y)
{
  switch (key)
  {
    case '\x1B':
      exit(EXIT_SUCCESS);
      break;
		case 'r':
      displayFunc();
      break;
  }
}

void animate(int value)
{
	glutTimerFunc(TIMERMSECS, &animate, 0);

	

	glutPostRedisplay();
}

void displayFunc()
{
	static double x0 = 0.0;
  glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(0.5);
  glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(-x0, 0.0f, 0.0f);
	
  glBegin(GL_LINE_STRIP);
		double x = x0;
		double y = 0;
		while (x < x0+100) {
			y = sin(x);
			glVertex2f(x, y);
			x += 0.01;
		}
		x0 += 0.1;
  glEnd();
	
	glPopMatrix();
  glutSwapBuffers();
}
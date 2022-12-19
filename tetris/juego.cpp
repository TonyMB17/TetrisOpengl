#include"juego.h"

int juego::w = 800, juego::h = 600;
float juego::fps = 60.f;

juego::juego()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(50, 50);

	glutInitWindowSize(w, h);

	glutCreateWindow("Tetris extremo");

	glutDisplayFunc(dibujar);

	glutKeyboardFunc(preocesar_teclado);

	glutIdleFunc(actualizar);

	iniciar();

}

void juego::iniciar()
{
	glClearColor(0, 0, 0, 1);

	glOrtho(w, 0, h, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void juego::dibujar()
{

}

void juego::preocesar_teclado(unsigned char c, int x, int y)
{

}

void juego::actualizar()
{

	glutPostRedisplay();

}
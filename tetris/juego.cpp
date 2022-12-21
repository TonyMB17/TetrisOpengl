#include"juego.h"

int juego::w = 800, juego::h = 600;
float juego::fps = 60.f;
figura juego::pieza(1);

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
	glClearColor(0.0, 0.0, 1.0, 0.0);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, w, 0, h, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(400, 300, 0);
	dibujar_tablero();
	pieza.dibujar();
	glPopMatrix();
	glutSwapBuffers();
}

void juego::preocesar_teclado(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'A': case 'a':
		pieza.set_x(-30);
		break;
	case 'D': case 'd':
		pieza.set_x(30);
		break;

	case 'S': case 's':
		pieza.set_y(-30);
		break;
	case ' ':
		pieza.rotar();
		break;
	}
}

void juego::actualizar()
{
	static float tiempo_transcurrido = 0;
	static float actualizar_cuadrado = 0;
	if (glutGet(GLUT_ELAPSED_TIME) > tiempo_transcurrido + 1.f / fps)
	{
		if (glutGet(GLUT_ELAPSED_TIME) > actualizar_cuadrado + 1000.f)
		{
			actualizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
			pieza.actualizar();

		}
		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();
	}


}

void juego::dibujar_tablero()
{
	glPushMatrix();

	glTranslatef(-150, 300, 0);
	glColor3f(0, 0, 0);

	glBegin(GL_QUAD_STRIP);

	glVertex2f(0, 0);
	glVertex2f(300, 0);
	glVertex2f(0, -600);
	glVertex2f(300, -600);

	glEnd();

	glPopMatrix();
}

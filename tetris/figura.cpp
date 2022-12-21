#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;
	rotacion = 1;
	pos_x = 0;
	pos_y = 330;

	switch (id)
	{
	case 1:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-30);
		cuadrados[3].set_y(30);
		break;

	case 2:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;

	case 3:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 4:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 5:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-60);
		break;

	case 6:
		cuadrados[1].set_x(-30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;
	}
}

void figura::actualizar()
{
	pos_y -= 30;
}

void figura::dibujar()
{	
	
	switch (id)
	{
	case 1:
		glColor3f(1, 1, 0);
		break;

	case 2:
		glColor3f(1, 1, 0);
		break;

	case 3:
		glColor3f(1, 0, 1);
		break;

	case 4:
		glColor3f(0, 0, 1);
		break;

	case 5:
		glColor3f(1, 0, 0);
		break;

	case 6:
		glColor3f(0, 1, 0);
		break;
	}

	glPushMatrix();
	glTranslatef(pos_x, pos_y, 0);

	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}

	glPopMatrix();
}

void figura::set_x(double x)
{
	pos_x += x;
}

void figura::set_y(double y)
{
	pos_y += y;
}

void figura::rotar()
{
	rotacion++;
	if (rotacion > 4) rotacion = 1;

	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_rotacion(rotacion);
	}

}
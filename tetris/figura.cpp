#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;
	rotacion = 1;
	pos_x = 15;
	pos_y = 345;

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

bool figura::actualizar()
{
	bool colisiono = false;

		if (pos_y > -280)
		{
			pos_y -= 30;
		}
		else
		{
			colisiono = true;
		}
	

	return colisiono;
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
	if (pos_y > -285)
	{
		pos_y += y;
	}
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

double figura::get_angulo_cuadradito(unsigned short num) {
	double angulo_cuadrado = atan2f(cuadrados[num].get_x(), cuadrados[num].get_y());

	cout << rad2deg(angulo_cuadrado) << endl;

	double rotacion_local = (rotacion - 1) * 90;

	return angulo_cuadrado + rotacion_local;


}
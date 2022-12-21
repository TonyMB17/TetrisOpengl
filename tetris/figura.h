#pragma once
#include "cuadrado.h"
#include <cmath>
#include <iostream>

using namespace std;

class figura
{
public:
	figura(unsigned short num); //1 Ele, 2 Ele invetida, 3 Cubo, 4 Triangulo, 5 el Palo
	bool actualizar();
	void dibujar();
	void set_x(double x);
	void set_y(double y);
	double get_x(unsigned short num) { return cuadrados[num].get_x() + pos_x; }
	double get_y(unsigned short num) { return cuadrados[num].get_y() + pos_y; }
	void rotar();

private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion; 
	double pos_x;
	double pos_y;
};


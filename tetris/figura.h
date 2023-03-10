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
	double get_angulo_cuadradito(unsigned short int);
	double calcular_posicion_x(unsigned short num); //Cuadradito
	double calcular_posicion_y(unsigned short num); //Cuadradito
	float rad2deg(float radianes) { return radianes * 180 / 3.14; }
	float deg2rad(float grados) { return grados * 3.14 / 180; }

private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
	double pos_x;
	double pos_y;
};

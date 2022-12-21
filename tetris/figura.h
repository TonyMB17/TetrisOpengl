#pragma once
#include "cuadrado.h"
#include <cmath>
#include <iostream>

using namespace std;

class figura
{
public:
	figura(unsigned short num); //1 Ele, 2 Ele invetida, 3 Cubo, 4 Triangulo, 5 el Palo
	void actualizar();
	void dibujar();

private:
	cuadrado cuadrados[4];
	unsigned short id;
};


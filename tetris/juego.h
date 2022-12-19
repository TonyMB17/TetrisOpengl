#pragma once

#include "GL\glut.h"
#include "cuadrado.h"
#include <iostream>

using namespace std;

class juego
{
public:
	juego();
	static void dibujar();
	static void preocesar_teclado(unsigned char c, int x, int y);
	static void actualizar();
	static void iniciar();
	static void dibujar_tablero();



private:
	static int w, h;
	static float fps;
	static cuadrado obj1;
};

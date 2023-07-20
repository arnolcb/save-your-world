#pragma once
#include "Personaje.h"

class Aliado : public Personaje
{
	int destinoX;
	int destinoY;
	bool agregarPuntaje;
public:
	Aliado(int x, int y, int mapa, int destinoX, int destinoY);
	~Aliado();
	void mover_aliado(Graphics^ g, Bitmap^ bmpAliado, int** matriz, int* puntaje);
	void set_puntaje(bool p);
};

Aliado::Aliado(int x, int y, int mapa, int destinoX, int destinoY)
{
	this->destinoX = destinoX;
	this->destinoY = destinoY;
	agregarPuntaje = false;

	visible = false;
	this->x = x;
	this->y = y;
	nMapa = mapa;

	movimientoX = 0;
	movimientoY = 0;

	indiceX = 0;
	indiceY = 0;

	direccion = Direcciones::Ninguna;
}

void Aliado::mover_aliado(Graphics^ g, Bitmap^ bmpAliado, int** matriz, int* puntaje)
{
	// suma de puntaje +10
	if (x == destinoX && y == destinoY)
	{
		direccion = Ninguna;
		visible = false;
		if (agregarPuntaje == false)
		{
			*puntaje = *puntaje + 10;
			agregarPuntaje = true;
		}
	}
	int velocidad = 6;
	if (visible == true)
	{
		//buscar destino
		if (x < destinoX)
		{
			direccion = Derecha;
		}
		else if (x > destinoX)
		{
			direccion = Izquierda;
		}
		if (y < destinoY)
		{
			direccion = Abajo;
		}
		else if (y > destinoY)
		{
			direccion = Arriba;
		}
	}

	int maximoColumna = (nMapa == 1) ? 3 : 2;
	switch (direccion)
	{
	case Direcciones::Arriba:

		indiceY = 3;
		if (indiceX >= 1 && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = 0;
		movimientoY = -velocidad;

		break;

	case Direcciones::Abajo:

		indiceY = 0;
		if (indiceX >= 1 && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = 0;
		movimientoY = +velocidad; //

		break;

	case Direcciones::Izquierda:

		indiceY = 1;
		if (indiceX >= 1 && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = -velocidad;
		movimientoY = 0;

		break;
	case Direcciones::Derecha:

		indiceY = 2;
		if (indiceX >= 1 && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = +velocidad;   //
		movimientoY = 0;

		break;
	case Direcciones::Ninguna:
		indiceY = 0;
		indiceX = 1;
		movimientoX = 0;
		movimientoY = 0;
	}

	double aumento;
	aumento = (nMapa == 1) ? 1 : 1.5;
	ancho = (nMapa == 1) ? bmpAliado->Width / 4 : bmpAliado->Width / 3;
	alto = bmpAliado->Height / 4;

	int distanciaX = (nMapa == 1) ? 20 : 20;
	int distanciaY = (nMapa == 1) ? 45 : 30;
	int reduceHitbox = (nMapa == 1) ? 1 : 0;
	hitbox_personaje(g, distanciaX, distanciaY, reduceHitbox, aumento);
	dibujar_personaje(g, bmpAliado, aumento);
}

void Aliado::set_puntaje(bool p)
{
	agregarPuntaje = p;
}
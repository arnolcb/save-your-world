#pragma once
#include "Personaje.h"
class Jugador : public Personaje
{
	Direcciones ultimaTecla;
public:
	Jugador(int x, int y, int mapa);
	~Jugador();
	void mover_jugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz);
	void validar_movimiento(int** matriz);
};

Jugador::Jugador(int x, int y, int mapa)
{ //posicion
	this->x = x;
	this->y = y;
	nMapa = mapa;
	//movimiento
	movimientoX = 0;
	movimientoY = 0;
	// animacion
	indiceX = 0;
	indiceY = 0;

	direccion = Direcciones::Ninguna;
	ultimaTecla = Direcciones::Abajo;
}

void Jugador::mover_jugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz)
{
	int velocidad = 20;
	switch (direccion)
	{
	case Direcciones::Arriba:

		indiceY = 3;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = 0;

		movimientoY = (y - velocidad > 0) ? -velocidad : 0;

		ultimaTecla = Arriba;
		break;

	case Direcciones::Abajo:

		indiceY = 0;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = 0;
		movimientoY = (y + (alto * 2) + velocidad < g->VisibleClipBounds.Bottom / 1.16) ? +velocidad : 0; //  1.16 divsion de la pantalla
		ultimaTecla = Abajo;

		break;

	case Direcciones::Izquierda:

		indiceY = 1;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = (x - velocidad > 0) ? -velocidad : 0;
		movimientoY = 0;
		ultimaTecla = Izquierda;

		break;
	case Direcciones::Derecha:

		indiceY = 2;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		movimientoX = (x + (ancho * 2) + velocidad < g->VisibleClipBounds.Right) ? +velocidad : 0;   // *2 = aumentodelaimagen
		movimientoY = 0;
		ultimaTecla = Derecha;

		break;

	case Direcciones::Ninguna:
		movimientoX = movimientoY = 0;
		if (ultimaTecla == Direcciones::Abajo)
		{
			indiceX = 0;
			indiceY = 0;
		}
		if (ultimaTecla == Direcciones::Arriba)
		{
			indiceX = 0;
			indiceY = 3;
		}
		if (ultimaTecla == Direcciones::Derecha)
		{
			indiceX = 0;
			indiceY = 2;
		}
		if (ultimaTecla == Direcciones::Izquierda)
		{
			indiceX = 0;
			indiceY = 1;
		}
		break;
	}
	double aumento;
	aumento = (nMapa == 1) ? 1.3 : 1.2; // tamano del personaje
	ancho = bmpJugador->Width / 4;
	alto = bmpJugador->Height / 4;

	int distanciaX = (nMapa == 1) ? 10 : 10;
	int distanciaY = (nMapa == 1) ? 30 : 30;
	int reduceHitbox = (nMapa == 1) ? 0 : 0.5;
	hitbox_personaje(g, distanciaX, distanciaY, reduceHitbox, aumento);
	validar_movimiento(matriz);
	dibujar_personaje(g, bmpJugador, aumento);
}
void Jugador::validar_movimiento(int** matriz)
{
	int X, Y = 0;
	for (int i = 0; i < FILAS; i++)
	{
		X = 0;
		for (int j = 0; j < COLUMNAS; j++)
		{
			Rectangle rangoObjeto = Rectangle(X, Y, 30, 30); /// rango del PISO (ancho por altura)
			if (nMapa == 1)//obstaculos mapa1
			{
				if (matriz[i][j] == 4 || matriz[i][j] == 9 || matriz[i][j] == 6)
				{
					if (horizontalHitbox.IntersectsWith(rangoObjeto)) movimientoX = 0;
					if (verticalHitbox.IntersectsWith(rangoObjeto)) movimientoY = 0;
				}
			}
			if (nMapa == 2) //obstaculos mapa2
			{
				if (matriz[i][j] == 1 || matriz[i][j] == 4 || matriz[i][j] == 9)
				{
					if (horizontalHitbox.IntersectsWith(rangoObjeto)) movimientoX = 0;
					if (verticalHitbox.IntersectsWith(rangoObjeto)) movimientoY = 0;
				}
			}

			X += 37;
		}
		Y += 37;
	}
}
#pragma once
#include "Personaje.h"

class Habitante : public Personaje
{
	int spriteTipo;
	int intervalo;
	int contadorTiempo;
	bool detener;
	int tipoGlobo;

	int inicioX, inicioY;
	int finalX, finalY;
	int tempX, tempY;
public:
	Habitante(int x, int y, int fx, int fy, int mapa, int sprite, int intervalo);
	~Habitante();
	void dibujar_globoTexto(Graphics^ g);
	void validar_detenerHabitante(int tiempo);
	void mover_habitante(Graphics^ g, Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos, int** matriz, int tiempo);
};
Habitante::Habitante(int x, int y, int fx, int fy, int mapa, int sprite, int intervalo)
{
	System::Random r;
	tipoGlobo = r.Next(0, 4);

	spriteTipo = sprite;
	this->intervalo = intervalo;
	contadorTiempo = 0;
	detener = false;

	inicioX = x;
	inicioY = y;

	finalX = fx;
	finalY = fy;

	tempX = finalX;
	tempY = finalY;

	visible = true;
	this->x = x;
	this->y = y;
	nMapa = mapa;

	movimientoX = 0;
	movimientoY = 0;

	indiceX = 0;
	indiceY = 0;

	//direccion = Direcciones::Ninguna;
	//direccion = Direcciones::Arriba;
}
Habitante::~Habitante() {}

void  Habitante::dibujar_globoTexto(Graphics^ g)
{
	if (detener == true)
	{
		Bitmap^ globo;
		if (nMapa == 1)
		{
			switch (tipoGlobo)
			{
			case 0:
				globo = gcnew Bitmap("imagenes\\globo1.png"); break;
			case 1:
				globo = gcnew Bitmap("imagenes\\globo2.png"); break;
			case 2:
				globo = gcnew Bitmap("imagenes\\globo3.png"); break;
			case 3:
				globo = gcnew Bitmap("imagenes\\globo6.png"); break;
			}
		}
		if (nMapa == 2)
		{
			switch (tipoGlobo)
			{
			case 0:
				globo = gcnew Bitmap("imagenes\\globo2.png"); break;
			case 1:
				globo = gcnew Bitmap("imagenes\\globo3.png"); break;
			case 2:
				globo = gcnew Bitmap("imagenes\\globo4.png"); break;
			case 3:
				globo = gcnew Bitmap("imagenes\\globo5.png"); break;
			}
		}
		globo->MakeTransparent(globo->GetPixel(0, 0));
		Rectangle ParteAUsar = Rectangle(0, 0, globo->Width, globo->Height);
		Rectangle AumentarImagen = Rectangle(x + 20, y - 100, globo->Width / 1.4, globo->Height / 1.4);
		g->DrawImage(globo, AumentarImagen, ParteAUsar, GraphicsUnit::Pixel);
	}
}

void Habitante::mover_habitante(Graphics^ g, Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos, int** matriz, int tiempo)
{
	validar_detenerHabitante(tiempo);
	// ir a final XY
	if (x == finalX && y == finalY)
	{
		finalX = inicioX;
		finalY = inicioY;
	}
	if (x == inicioX && y == inicioY)
	{
		finalX = tempX;
		finalY = tempY;
	}
	if (visible == true && detener == false)
	{
		//buscar destino
		if (x < finalX)
		{
			direccion = Derecha;
		}
		else if (x > finalX)
		{
			direccion = Izquierda;
		}
		else if (y < finalY)
		{
			direccion = Abajo;
		}
		else if (y > finalY)
		{
			direccion = Arriba;
		}
	}

	int velocidad = 4;
	int maximoColumna = (nMapa == 1) ? 2 : 3;
	int minimoColumna = (nMapa == 1) ? 0 : 1;
	switch (direccion)
	{
	case Direcciones::Arriba:

		indiceY = 3;
		if (indiceX >= minimoColumna && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = minimoColumna;

		movimientoX = 0;
		movimientoY = (y - velocidad > 0) ? -velocidad : 0;

		break;

	case Direcciones::Abajo:

		indiceY = 0;
		if (indiceX >= minimoColumna && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = minimoColumna;

		movimientoX = 0;
		movimientoY = (y + (alto * 1) + velocidad < g->VisibleClipBounds.Bottom / 1.16) ? +velocidad : 0; //  1.16 divsion de la pantalla

		break;

	case Direcciones::Izquierda:

		indiceY = 1;
		if (indiceX >= minimoColumna && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = minimoColumna;

		movimientoX = (x - velocidad > 0) ? -velocidad : 0;
		movimientoY = 0;

		break;
	case Direcciones::Derecha:

		indiceY = 2;
		if (indiceX >= minimoColumna && indiceX < maximoColumna)
			indiceX++;
		else
			indiceX = minimoColumna;

		movimientoX = (x + (ancho * 1) + velocidad < g->VisibleClipBounds.Right) ? +velocidad : 0;   // *2 = aumentodelaimagen
		movimientoY = 0;

		break;
	case Direcciones::Ninguna:
		indiceY = 0;
		indiceX = (nMapa == 1) ? 1 : 0;
		movimientoX = 0;
		movimientoY = 0;
	}
	Bitmap^ habitante = (spriteTipo == 0) ? bmpHabitante : bmpHabitanteDos;
	double aumento;
	aumento = (nMapa == 1) ? 0.9 : 1.2;
	ancho = (nMapa == 1) ? habitante->Width / 3 : habitante->Width / 4;
	alto = habitante->Height / 4;

	dibujar_personaje(g, habitante, aumento);
}

void Habitante::validar_detenerHabitante(int tiempo)
{
	int tiempoEspera = 45;

	// parar cada cierto tiempo
	if (tiempo % intervalo == 0 && detener != true)
	{
		detener = true;
	}
	if (detener == true)
	{
		direccion = Ninguna;
		contadorTiempo++;
	}
	if (contadorTiempo == tiempoEspera)
	{
		contadorTiempo = 0;
		detener = false;
	}
	System::Random r;
	if (detener == false)
		tipoGlobo = r.Next(0, 4);
}
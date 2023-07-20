#pragma once
class Enemigo : public Personaje
{
public:
	Enemigo(int x, int y, int mapa);
	~Enemigo();
	void mover_enemigo(Graphics^ g, Bitmap^ bmpEnemigo, Jugador* jugador, Aliado* aliado, int* puntaje);
	void validar_movimiento(Jugador* jugador, Aliado* aliado, int* puntaje);
};

Enemigo::Enemigo(int x, int y, int mapa)
{
	visible = true;
	this->x = x;
	this->y = y;
	nMapa = mapa;

	movimientoX = 0;
	movimientoY = 0;

	indiceX = 0;
	indiceY = 0;

	direccion = Direcciones::Ninguna;
}

void Enemigo::mover_enemigo(Graphics^ g, Bitmap^ bmpEnemigo, Jugador* jugador, Aliado* aliado, int* puntaje)
{
	int velocidad = 3;
	///buscar aliados
	if (x == aliado->get_x() && y == aliado->get_y())
		direccion = Ninguna;
	if (aliado->get_visible() == true)
	{
		if (x < aliado->get_x())
		{
			//movimientoX = velocidad;
			x += velocidad;
			direccion = Derecha;
		}
		else if (x > aliado->get_x())
		{
			//movimientoX = -velocidad;
			x -= velocidad;
			direccion = Izquierda;
		}
		if (y + velocidad < aliado->get_y())
		{
			//movimientoY = +velocidad;
			y += velocidad;
			direccion = Abajo;
		}
		else if (y - velocidad > aliado->get_y())
		{
			//movimientoY = -velocidad;
			y -= velocidad;
			direccion = Arriba;
		}
	}
	else
		direccion = Ninguna;

	switch (direccion)
	{
	case Direcciones::Arriba:

		indiceY = 3;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		//movimientoX = 0;
		//movimientoY = (y - velocidad > 0) ? -velocidad : 0;

		break;

	case Direcciones::Abajo:

		indiceY = 0;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		//movimientoX = 0;
		//movimientoY = (y + (alto * 1 * 3) + velocidad < g->VisibleClipBounds.Bottom / 1.16) ? +velocidad : 0; //  1.16 divsion de la pantalla

		break;

	case Direcciones::Izquierda:

		indiceY = 1;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		///movimientoX = (x - velocidad > 0) ? -velocidad : 0;
		//movimientoY = 0;

		break;
	case Direcciones::Derecha:

		indiceY = 2;
		if (indiceX >= 1 && indiceX < 3)
			indiceX++;
		else
			indiceX = 1;

		//movimientoX = (x + (ancho * 1 * 3) + velocidad < g->VisibleClipBounds.Right) ? +velocidad : 0;   // *2 = aumentodelaimagen
		//movimientoY = 0;

		break;
	case Direcciones::Ninguna:
		indiceY = 2;
		indiceX = 1;
		movimientoX = 0;
		movimientoY = 0;
	}

	double aumento;
	aumento = (nMapa == 1) ? 1.1 : 1.1;
	ancho = bmpEnemigo->Width / 4;
	alto = bmpEnemigo->Height / 4;

	int distanciaX = (nMapa == 1) ? 20 : 25;
	int distanciaY = (nMapa == 1) ? 45 : 35;
	int reduceHitbox = (nMapa == 1) ? 1 : 1;
	hitbox_personaje(g, distanciaX, distanciaY, reduceHitbox, aumento);
	validar_movimiento(jugador, aliado, puntaje);
	dibujar_personaje(g, bmpEnemigo, aumento);
}
void Enemigo::validar_movimiento(Jugador* jugador, Aliado* aliado, int* puntaje)
{
	//COLISION DEL JUGADOR
	int empujeDistancia = 70;
	if (horizontalHitbox.IntersectsWith(jugador->get_horizontalHitbox()))
	{
		if (jugador->get_direccion() == Ninguna)
		{
			if (direccion == Izquierda)
				x += empujeDistancia;
			if (direccion == Derecha)
				x -= empujeDistancia;
		}
		if (jugador->get_direccion() == Derecha)
			x += empujeDistancia;
		if (jugador->get_direccion() == Izquierda)
			x -= empujeDistancia;
	}
	if (verticalHitbox.IntersectsWith(jugador->get_verticalHitbox()))
	{
		if (jugador->get_direccion() == Ninguna)
		{
			if (direccion == Arriba)
				y += empujeDistancia;
			if (direccion == Abajo)
				y -= empujeDistancia;
		}
		if (jugador->get_direccion() == Abajo)
			y += empujeDistancia;
		if (jugador->get_direccion() == Arriba)
			y -= empujeDistancia;
	}
	// COLISION DEL ALIADO
	if (aliado->get_visible() == true)
	{
		if (horizontalHitbox.IntersectsWith(aliado->get_horizontalHitbox()))
		{
			aliado->set_x(0);
			aliado->set_y(-200);
			aliado->set_visible(false);
			if (*puntaje != 0)
				*puntaje = *puntaje - 5;
		}
		if (verticalHitbox.IntersectsWith(aliado->get_verticalHitbox()))
		{
			aliado->set_x(0);
			aliado->set_y(-200); // fuera del mapa
			aliado->set_visible(false);
		}
	}
}
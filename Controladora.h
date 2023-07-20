///////
//en esta clase recibiremos las imagenes del la clase Juego.h y las imprimimos
#pragma once
#include "Aliado.h"
#include "Escenario.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Habitante.h"
class Controladora
{
	int disponibles;
	int tiempo;
	int* puntaje;
	int nMapa;
	int nEnemigos, nHabitantes, nAliados;
	Escenario* escenario;
	Jugador* jugador;
	Enemigo** enemigos;
	Habitante** habitantes;
	Aliado** aliados;

public:
	Controladora(int mapa, int enemigos, int habitante, int aliado);
	~Controladora();

	void dibujar_Mapa1(Graphics^ graphic, Bitmap^ bmpBase, Bitmap^ bmpPiedra, Bitmap^ bmpJugador,
		Bitmap^ bmpCama, Bitmap^ bmpCajon, Bitmap^ bmpSillon, Bitmap^ bmpPlanta, Bitmap^ bmpEnemigo,
		Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos, Bitmap^ bmpAliado);

	void dibujar_Mapa2(Graphics^ graphic, Bitmap^ bmpBase, Bitmap^ bmpPiedra, Bitmap^ bmpJugador,
		Bitmap^ bmpArbol, Bitmap^ bmpArbol2, Bitmap^ bmpCartel, Bitmap^ bmpArbusto, Bitmap^ bmpCasa, Bitmap^ bmpCasa2,
		Bitmap^ bmpEnemigo, Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos, Bitmap^ bmpAliado);

	void capa_habitantes(Graphics^ graphic, Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos);
	void capa_enemigos(Graphics^ graphic, Bitmap^ bmpEnemigo);
	void capa_aliados(Graphics^ graphic, Bitmap^ bmpAliado);
	void agregar_enemigo(int i);
	void agregar_habitante(int i, int iX, int iY, int fX, int fY, int spriteTipo, int intervaloEspera);
	void agregar_aliado(int i);
	void revisar_visibles();
	int redondear_posicion(int multiplo, int numero);
	Jugador* getJugador();
	int get_puntaje();
	void set_tiempo(int t);
	int get_disponibles();
};

Controladora::Controladora(int mapa, int agente, int habitante, int aliado)
{
	disponibles = aliado;
	System::Random r;
	tiempo = 59;
	puntaje = new int;
	*puntaje = 0;
	nMapa = mapa;
	nEnemigos = agente;
	nHabitantes = habitante;
	nAliados = aliado;
	escenario = new Escenario(nMapa);
	jugador = new Jugador(600, 500, nMapa);

	enemigos = new Enemigo * [nEnemigos];
	habitantes = new Habitante * [nHabitantes];
	aliados = new Aliado * [nAliados];

	for (int i = 0; i < nEnemigos; i++)
		agregar_enemigo(i);

	for (int i = 0; i < nAliados; i++)
		agregar_aliado(i);

	for (int i = 0; i < nHabitantes; i++)
		agregar_habitante(i, r.Next(4, 1140), r.Next(200, 520), r.Next(4, 1140),
			r.Next(200, 520), r.Next(2), r.Next(14, 40));
}

void Controladora::dibujar_Mapa1(Graphics^ graphic, Bitmap^ bmpBase, Bitmap^ bmpPiedra, Bitmap^ bmpJugador,
	Bitmap^ bmpCama, Bitmap^ bmpCajon, Bitmap^ bmpSillon, Bitmap^ bmpPlanta, Bitmap^ bmpEnemigo,
	Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos, Bitmap^ bmpAliado)
{
	//capa 1
	escenario->pintar_base(graphic, bmpBase, bmpPiedra);
	//capa 2
	capa_habitantes(graphic, bmpHabitante, bmpHabitanteDos);
	capa_aliados(graphic, bmpAliado);
	capa_enemigos(graphic, bmpEnemigo);
	escenario->pintar_obstaculos_Mapa(graphic, bmpCama, bmpCajon, bmpSillon, bmpPlanta);
	jugador->mover_jugador(graphic, bmpJugador, escenario->get_matriz());
	//capa 3
	for (int i = 0; i < nHabitantes; i++)
	{
		habitantes[i]->dibujar_globoTexto(graphic);
	}
}

void Controladora::dibujar_Mapa2(Graphics^ graphic, Bitmap^ bmpBase, Bitmap^ bmpPiedra, Bitmap^ bmpJugador,
	Bitmap^ bmpArbol, Bitmap^ bmpArbol2, Bitmap^ bmpCartel, Bitmap^ bmpArbusto, Bitmap^ bmpCasa, Bitmap^ bmpCasa2,
	Bitmap^ bmpEnemigo, Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos, Bitmap^ bmpAliado)
{
	//capa 1
	escenario->pintar_base(graphic, bmpBase, bmpPiedra);
	//capa 2
	capa_habitantes(graphic, bmpHabitante, bmpHabitanteDos);
	jugador->mover_jugador(graphic, bmpJugador, escenario->get_matriz());
	escenario->pintar_obstaculos_Mapa2(graphic, bmpArbol, bmpArbol2, bmpCartel, bmpArbusto, bmpCasa, bmpCasa2);
	capa_aliados(graphic, bmpAliado);
	capa_enemigos(graphic, bmpEnemigo);
	//capa 3
	for (int i = 0; i < nHabitantes; i++)
	{
		habitantes[i]->dibujar_globoTexto(graphic);
	}
}
Jugador* Controladora::getJugador()
{
	return jugador;
}

void Controladora::agregar_enemigo(int i)
{
	enemigos[i] = new Enemigo(30, 100 * (i + 1), nMapa);
}
void Controladora::agregar_aliado(int i)
{
	int  multiplo = 6;
	aliados[i] = new Aliado(600, 800, nMapa,
		redondear_posicion(multiplo, 180 * (i + 1)), redondear_posicion(multiplo, 150));
}
void Controladora::agregar_habitante(int i, int iX, int iY, int fX, int fY, int spriteTipo, int intervaloEspera)
{
	//redondear a multiplo de 5
	int multiplo = 4;
	iX = redondear_posicion(multiplo, iX);
	iY = redondear_posicion(multiplo, iY);
	fX = redondear_posicion(multiplo, fX);
	fY = redondear_posicion(multiplo, fY);

	habitantes[i] = new Habitante(iX, iY, fX, fY, nMapa, spriteTipo, intervaloEspera);
}

// al presionar espacio buscara aliados no visibles para que aparezcan en el juego
void Controladora::revisar_visibles()
{
	int multiplo = 6;
	for (int i = 0; i < nAliados; i++)
	{
		if (aliados[i]->get_visible() == false)
		{
			aliados[i]->set_x(redondear_posicion(multiplo, 1100));
			aliados[i]->set_y(redondear_posicion(multiplo, 500));
			aliados[i]->set_visible(true);
			aliados[i]->set_puntaje(false);
			break;
		}
	}
}

void Controladora::capa_habitantes(Graphics^ graphic, Bitmap^ bmpHabitante, Bitmap^ bmpHabitanteDos)
{
	for (int i = 0; i < nHabitantes; i++)
	{
		if (habitantes[i]->get_visible() == true)
			habitantes[i]->mover_habitante(graphic, bmpHabitante, bmpHabitanteDos, escenario->get_matriz(), tiempo);
	}
}

void Controladora::capa_enemigos(Graphics^ graphic, Bitmap^ bmpEnemigo)
{
	int a = 0;
	for (int i = 0; i < nEnemigos; i++)
	{
		if (aliados[a]->get_visible() == false)
		{
			for (int i = 0; i < nAliados; i++)
			{
				if (aliados[i]->get_visible() == true)
					a = i;
			}
		}

		enemigos[i]->mover_enemigo(graphic, bmpEnemigo, jugador, aliados[a], puntaje);

		a++;
		if (a == nAliados)
			a = 0;
	}
}

void Controladora::capa_aliados(Graphics^ graphic, Bitmap^ bmpAliado)
{
	int cantidad = 0;
	for (int i = 0; i < nAliados; i++)
	{
		aliados[i]->mover_aliado(graphic, bmpAliado, escenario->get_matriz(), puntaje);
		if (aliados[i]->get_visible() == false)
			cantidad++;
	}
	disponibles = cantidad;
}

int Controladora::redondear_posicion(int multiplo, int numero)
{
	numero = ((numero + multiplo / 2) / multiplo) * multiplo;
	return numero;
}

int Controladora::get_puntaje()
{
	int score = *puntaje;
	return score;
}

void Controladora::set_tiempo(int t)
{
	tiempo = t;
}

int Controladora::get_disponibles()
{
	return disponibles;
}
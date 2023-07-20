#pragma once
#define FILAS 16 // arriba - abajo
#define COLUMNAS 34  // izq - derecha
using namespace System::Drawing;

class Escenario
{
	int nMapa;
	//creacion del mapa 1
	//Leyenda: 0 = pasto ,1 =suelo , 4 = arbol, 5 = cajon , 9 = bloque invisible (no se puede cruzar)
	int** matrizPrincipal;
	int mapaUno[FILAS][COLUMNAS] = {
									{0,0,0,0,0,5,9,0,0,0,0,0,0,5,9,0,0,0,0,0,0,5,9,0,0,5,9,0,0,0,0,0,0,0},
									{0,0,0,4,9,9,9,4,9,0,0,4,9,9,9,4,9,0,0,4,9,9,9,4,9,9,9,4,0,0,0,4,0,0},
									{0,0,0,9,9,0,0,9,9,0,0,9,9,0,0,9,9,0,0,9,9,0,0,9,9,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,6,9,9,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	//Leyenda: 0 = piso  ,1 = arbol1 , 2 = arbol2 , 3 = pisoPiedra , 4 = cartel, 5 = casa1, 6= casa2 ,9 = bloque invisible (no se puede cruzar)
	int mapaDos[FILAS][COLUMNAS] = {
									{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
									{0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0},
									{0,0,0,3,3,0,0,5,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,1},
									{1,0,0,3,3,0,0,9,9,9,9,9,0,0,0,0,0,0,0,3,3,0,0,6,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,3,3,0,0,9,9,9,9,9,0,0,0,0,0,0,0,3,3,0,0,9,9,9,9,9,0,0,0,0,0,1},
									{1,0,0,3,3,0,0,4,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,9,9,9,9,9,0,0,0,0,0,0},
									{0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,4,0,0,0,0,0,1},
									{1,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1} };
public:
	Escenario(int mapa);
	~Escenario();
	int** get_matriz();
	void generar_matriz();
	void pintar_base(Graphics^ graphic, Bitmap^ bmpBase, Bitmap^ bmpPiedra);
	void pintar_obstaculos_Mapa(Graphics^ graphic, Bitmap^ bmpCama, Bitmap^ bmpCajon, Bitmap^ bmpSillon, Bitmap^ bmpPlanta);
	void pintar_obstaculos_Mapa2(Graphics^ graphic, Bitmap^ bmpArbol1, Bitmap^ bmpArbol2, Bitmap^
		bmpCartel, Bitmap^ bmparbusto, Bitmap^ bmpCasa1, Bitmap^ bmpCasa2);
};

Escenario::Escenario(int mapa)
{
	nMapa = mapa;
	matrizPrincipal = new int* [FILAS];
	generar_matriz();
}
void Escenario::generar_matriz()
{
	for (int i = 0; i < FILAS; i++)
	{
		matrizPrincipal[i] = new int[COLUMNAS];
	}
	// set variables
	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			if (nMapa == 1)
				matrizPrincipal[i][j] = mapaUno[i][j];
			else if (nMapa == 2)
				matrizPrincipal[i][j] = mapaDos[i][j];    // seleccion del mapa
		}
	}
}

void Escenario::pintar_base(Graphics^ graphic, Bitmap^ bmpBase, Bitmap^ bmpPiedra)
{
	int X = 0, Y = 0;
	for (int fil = 0; fil < FILAS; fil++)
	{
		X = 0;
		for (int col = 0; col < COLUMNAS; col++)
		{
			graphic->DrawImage(bmpBase, X, Y, 37, 37);
			if (nMapa == 2 && matrizPrincipal[fil][col] == 3)
			{
				graphic->DrawImage(bmpPiedra, X, Y, 37, 37);
			}

			X += 37;// *1.3;
		}
		Y += 37;// *1.3;
	}
}

void Escenario::pintar_obstaculos_Mapa(Graphics^ graphic, Bitmap^ bmpCama, Bitmap^ bmpCajon, Bitmap^ bmpSillon, Bitmap^ bmpPlanta)
{
	int X = 0, Y = 0;
	for (int fil = 0; fil < FILAS; fil++)
	{
		X = 0;
		for (int col = 0; col < COLUMNAS; col++)
		{
			if (matrizPrincipal[fil][col] == 4)
			{
				graphic->DrawImage(bmpCama, X + 10, Y, bmpCama->Width / 1.2, bmpCama->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 5)
			{
				graphic->DrawImage(bmpCajon, X, Y, bmpCajon->Width / 1.2, bmpCajon->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 6)
			{
				graphic->DrawImage(bmpSillon, X, Y, bmpSillon->Width / 1.2, bmpSillon->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 7)
			{
				graphic->DrawImage(bmpPlanta, X, Y, bmpPlanta->Width / 1.2, bmpPlanta->Height / 1.2);
			}

			X += 37;// *1.3;
		}
		Y += 37;// *1.3;
	}
}

void Escenario::pintar_obstaculos_Mapa2(Graphics^ graphic, Bitmap^ bmpArbol1, Bitmap^ bmpArbol2, Bitmap^ bmpCartel, Bitmap^ bmparbusto,
	Bitmap^ bmpCasa1, Bitmap^ bmpCasa2)
{
	int X = 0, Y = 0;
	for (int fil = 0; fil < FILAS; fil++)
	{
		X = 0;
		for (int col = 0; col < COLUMNAS; col++)
		{
			if (matrizPrincipal[fil][col] == 1)
			{
				if (X == 0 && Y > 0)
					graphic->DrawImage(bmpArbol1, X - 37, Y - 50, bmpArbol1->Width / 1.2, bmpArbol1->Height / 1.2);
				else
					graphic->DrawImage(bmpArbol1, X, Y - 50, bmpArbol1->Width / 1.2, bmpArbol1->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 2)
			{
				graphic->DrawImage(bmpArbol2, X, Y, bmpArbol2->Width / 1.2, bmpArbol2->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 4)
			{
				graphic->DrawImage(bmpCartel, X, Y - 5, bmpCartel->Width / 1.2, bmpCartel->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 5)
			{
				graphic->DrawImage(bmpCasa1, X, Y - 25, bmpCasa1->Width / 1.2, bmpCasa1->Height / 1.2);
			}
			if (matrizPrincipal[fil][col] == 6)
			{
				graphic->DrawImage(bmpCasa2, X, Y - 25, bmpCasa2->Width / 1.2, bmpCasa2->Height / 1.2);
			}
			X += 37;
		}
		Y += 37;
	}
}

int** Escenario::get_matriz()
{
	return matrizPrincipal;
}

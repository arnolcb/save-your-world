#pragma once
using namespace System::Drawing;
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna };
class Personaje
{
protected:
	int nMapa;
	int x = 0, y = 0;
	int movimientoX, movimientoY;
	int ancho, alto;
	int indiceX, indiceY;
	Direcciones direccion;
	Rectangle horizontalHitbox, verticalHitbox;
	bool visible;
public:
	Personaje();
	~Personaje();
	void dibujar_personaje(Graphics^ g, Bitmap^ bmpSprite, double aumento);
	void hitbox_personaje(Graphics^ g, int distanciaX, int distanciaY, int reduceHitbox, double aumento);

	int get_x();
	void set_x(int x);

	int get_y();
	void set_y(int y);

	int get_movimientoX();
	void set_movimientoX(int movX);

	int get_movimientoY();
	void set_movimientoY(int movY);

	int get_indiceX();
	void set_indiceX(int indiceX);

	int get_indiceY();
	void set_indiceY(int indiceY);

	bool get_visible();
	void set_visible(bool i);

	Direcciones get_direccion();
	void set_direccion(Direcciones direccion);

	Rectangle get_horizontalHitbox();
	void set_horizontalHitbox(Rectangle rect);
	Rectangle get_verticalHitbox();
	void set_verticalHitbox(Rectangle rect);
};
Personaje::Personaje()
{
}
Personaje::~Personaje()
{
}

void Personaje::dibujar_personaje(Graphics^ g, Bitmap^ bmpSprite, double aumento)
{
	Rectangle ParteAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle AumentarImagen = Rectangle(x, y, ancho * aumento, alto * aumento);
	g->DrawImage(bmpSprite, AumentarImagen, ParteAUsar, GraphicsUnit::Pixel);
	x += movimientoX;
	y += movimientoY;
}
void Personaje::hitbox_personaje(Graphics^ g, int distanciaX, int distanciaY, int reduceHitbox, double aumento)
{
	horizontalHitbox = Rectangle(x + distanciaX / aumento + movimientoX, y + distanciaY * aumento,
		(ancho - 4) / (aumento + reduceHitbox), (alto - 15) / (aumento + reduceHitbox));
	verticalHitbox = Rectangle(x + distanciaX / aumento, y + distanciaY * aumento + movimientoY,
		(ancho - 4) / (aumento + reduceHitbox), (alto - 15) / (aumento + reduceHitbox));
	//g->DrawRectangle(Pens::Red, horizontalHitbox); // Mostrar hitbox derecha-izquierda
	//g->DrawRectangle(Pens::Orange, verticalHitbox);// Mostrar hitbox arriba - abajo
}
int Personaje::get_x()
{
	return x;
}
void Personaje::set_x(int x)
{
	this->x = x;
}
int Personaje::get_y()
{
	return y;
}
void Personaje::set_y(int y)
{
	this->y = y;
}
int Personaje::get_movimientoX()
{
	return movimientoX;
}
void Personaje::set_movimientoX(int movX)
{
	movimientoX = movX;
}
int Personaje::get_movimientoY()
{
	return movimientoY;
}
void Personaje::set_movimientoY(int movY)
{
	movimientoY = movY;
}
int Personaje::get_indiceX()
{
	return indiceX;
}
void Personaje::set_indiceX(int indiceX)
{
	this->indiceX = indiceX;
}
int Personaje::get_indiceY()
{
	return indiceY;
}
void Personaje::set_indiceY(int indiceY)
{
	this->indiceY = indiceY;
}
Direcciones Personaje::get_direccion()
{
	return direccion;
}
void Personaje::set_direccion(Direcciones direccion)
{
	this->direccion = direccion;
}
Rectangle Personaje::get_horizontalHitbox()
{
	return horizontalHitbox;
}
void Personaje::set_horizontalHitbox(Rectangle rect)
{
	horizontalHitbox = rect;
}
void Personaje::set_verticalHitbox(Rectangle rect)
{
	verticalHitbox = rect;
}
Rectangle Personaje::get_verticalHitbox()
{
	return verticalHitbox;
}

bool Personaje::get_visible()
{
	return visible;
}
void Personaje::set_visible(bool i)
{
	visible = i;
}
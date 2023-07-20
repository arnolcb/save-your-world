//el juego empieza en la bienvenida
#include "Bienvenida.h"
using namespace UPCJuego;
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew UPCJuego::Bienvenida()); //Project 1 es el nombre del proyecto
	return 0;
}
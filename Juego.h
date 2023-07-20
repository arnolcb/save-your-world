#pragma once
#include <iostream>

#include "Controladora.h"
#include "Creditos.h"

namespace UPCJuego {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media; // musica

	/// <summary>
	/// Summary for Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
		Controladora* oControladora;
		Form^ bienvenida;
		SoundPlayer^ musica;
		SoundPlayer^ musicaJuego;

		int milisegundos;

		int tiempoMinutos;
		int tiempoSegundos;

		int nMapa;
		int tiempo;
		int nEnemigo;
		int nAliado;
		int nHabitante;

	public:
		/// almacenamiento de imagenes (sprite)
		Bitmap^ bmpPuntaje;
		Bitmap^ bmpSuelo;
		Bitmap^ bmpJugador;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpAliado;
		Bitmap^ bmpHabitanteUno;
		Bitmap^ bmpHabitanteDos;

		///OBJETOS Hospital
		Bitmap^ bmpCama = gcnew Bitmap("imagenes\\cama_verde.png");
		Bitmap^ bmpCajon = gcnew Bitmap("imagenes\\cajon.png");
		Bitmap^ bmpSillon = gcnew Bitmap("imagenes\\sillonAzul.png");
		Bitmap^ bmpPlanta = gcnew Bitmap("imagenes\\planta.png");
		///OBJETOS Ambiente
		Bitmap^ bmpPiedra = gcnew Bitmap("imagenes\\pisoPiedra.png");
		Bitmap^ bmpArbol = gcnew Bitmap("imagenes\\arbolAmbiente.png");
		Bitmap^ bmpArbol2 = gcnew Bitmap("imagenes\\arbolAmbiente2.png");
		Bitmap^ bmpCartel = gcnew Bitmap("imagenes\\cartelAmbiente.png");
		Bitmap^ bmpArbusto = gcnew Bitmap("imagenes\\arbusto.png");
		Bitmap^ bmpCasa = gcnew Bitmap("imagenes\\casa1.png");
		Bitmap^ bmpCasa2 = gcnew Bitmap("imagenes\\casa2.png");
		//OVERLAY
		Bitmap^ bmpBordeJuego = gcnew Bitmap("imagenes\\border3.png");

	private: System::Windows::Forms::PictureBox^ pantallaJuego;
	private: System::Windows::Forms::PictureBox^ panelAtributos;
	private: System::Windows::Forms::Label^ tSegundos;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox5;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ disponiblesAliado;
	private: System::Windows::Forms::PictureBox^ mute2;
	private: System::Windows::Forms::PictureBox^ mute;

	private: System::Windows::Forms::Label^ scorePuntaje;

	public:
		Juego(Form^ obj, SoundPlayer^ sonido1, int mapa, int tiempo, int enemigo, int aliado, int habitante)
		{
			musicaJuego = gcnew SoundPlayer("sonido\\juego.wav");

			nMapa = mapa;
			this->tiempo = tiempo;
			nEnemigo = enemigo;
			nAliado = aliado;
			nHabitante = habitante;

			tiempoMinutos = tiempo - 1;
			tiempoSegundos = 59;
			milisegundos = 0;

			bienvenida = obj;
			musica = sonido1;

			bmpJugador = (mapa == 1) ? gcnew Bitmap("imagenes\\liderHospital.png") : gcnew Bitmap("imagenes\\liderAmbiental9.png");
			bmpSuelo = (mapa == 1) ? gcnew Bitmap("imagenes\\pisoHospital.png") : gcnew Bitmap("imagenes\\pisoAmbiente.png");
			bmpPuntaje = (mapa == 1) ? gcnew Bitmap("imagenes\\scoreHospital.png") : gcnew Bitmap("imagenes\\scoreAmbiente.png");
			bmpEnemigo = (mapa == 1) ? gcnew Bitmap("imagenes\\enemigoHospital.png") : gcnew Bitmap("imagenes\\enemigoAmbiente.png");
			bmpAliado = (mapa == 1) ? gcnew Bitmap("imagenes\\aliadoHospital.png") : gcnew Bitmap("imagenes\\ivysaur.png");
			bmpHabitanteUno = (mapa == 1) ? gcnew Bitmap("imagenes\\habitanteHospital.png") : gcnew Bitmap("imagenes\\habitanteAmbiente.png");
			bmpHabitanteDos = (mapa == 1) ? gcnew Bitmap("imagenes\\habitanteHospital2.png") : gcnew Bitmap("imagenes\\habitanteAmbiente2.png");

			// QUITAR FONDO OBJETOS MAPA 1
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(1, 1));  // eliminar fondo del personaje
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(1, 1));  // eliminar fondo del personaje
			bmpAliado->MakeTransparent(bmpAliado->GetPixel(1, 1));
			bmpHabitanteUno->MakeTransparent(bmpHabitanteUno->GetPixel(1, 1));
			bmpHabitanteDos->MakeTransparent(bmpHabitanteDos->GetPixel(1, 1));

			bmpCama->MakeTransparent(bmpCama->GetPixel(1, 1));  // eliminar fondo del personaje
			bmpSillon->MakeTransparent(bmpSillon->GetPixel(1, 1));  // eliminar fondo del personaje
			bmpPlanta->MakeTransparent(bmpPlanta->GetPixel(1, 1));  // eliminar fondo del personaje
			// QUITAR FONDO OBJETOS MAPA 2
			bmpPiedra->MakeTransparent(bmpPiedra->GetPixel(1, 1));
			bmpArbol->MakeTransparent(bmpArbol->GetPixel(1, 1));
			bmpArbol2->MakeTransparent(bmpArbol2->GetPixel(1, 1));
			bmpCartel->MakeTransparent(bmpCartel->GetPixel(1, 1));
			bmpArbusto->MakeTransparent(bmpArbusto->GetPixel(1, 1));
			bmpCasa->MakeTransparent(bmpCasa->GetPixel(1, 1));
			bmpCasa2->MakeTransparent(bmpCasa2->GetPixel(1, 1));
			//
			bmpBordeJuego->MakeTransparent(bmpBordeJuego->GetPixel(0, 0));
			InitializeComponent();
		}
		Juego(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pantallaJuego = (gcnew System::Windows::Forms::PictureBox());
			this->panelAtributos = (gcnew System::Windows::Forms::PictureBox());
			this->tSegundos = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->scorePuntaje = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->disponiblesAliado = (gcnew System::Windows::Forms::Label());
			this->mute2 = (gcnew System::Windows::Forms::PictureBox());
			this->mute = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pantallaJuego))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelAtributos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute))->BeginInit();
			this->SuspendLayout();
			//
			// timer1
			//
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			//
			// pantallaJuego
			//
			this->pantallaJuego->Location = System::Drawing::Point(0, 121);
			this->pantallaJuego->Name = L"pantallaJuego";
			this->pantallaJuego->Size = System::Drawing::Size(1251, 591);
			this->pantallaJuego->TabIndex = 0;
			this->pantallaJuego->TabStop = false;
			this->pantallaJuego->Click += gcnew System::EventHandler(this, &Juego::pantallaJuego_Click);
			//
			// panelAtributos
			//
			this->panelAtributos->BackColor = System::Drawing::Color::PapayaWhip;
			this->panelAtributos->Location = System::Drawing::Point(0, -4);
			this->panelAtributos->Name = L"panelAtributos";
			this->panelAtributos->Size = System::Drawing::Size(1251, 141);
			this->panelAtributos->TabIndex = 1;
			this->panelAtributos->TabStop = false;
			//
			// tSegundos
			//
			this->tSegundos->BackColor = System::Drawing::Color::White;
			this->tSegundos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold));
			this->tSegundos->ForeColor = System::Drawing::Color::Black;
			this->tSegundos->Location = System::Drawing::Point(485, 37);
			this->tSegundos->Name = L"tSegundos";
			this->tSegundos->Size = System::Drawing::Size(122, 58);
			this->tSegundos->TabIndex = 2;
			this->tSegundos->Text = L"00:00";
			this->tSegundos->Click += gcnew System::EventHandler(this, &Juego::label1_Click);
			//
			// pictureBox1
			//
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImageLocation = L"";
			this->pictureBox1->InitialImage = nullptr;
			this->pictureBox1->Location = System::Drawing::Point(413, 23);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(73, 71);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			//
			// pictureBox2
			//
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(610, 21);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(80, 71);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Juego::pictureBox2_Click);
			//
			// scorePuntaje
			//
			this->scorePuntaje->BackColor = System::Drawing::Color::White;
			this->scorePuntaje->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold));
			this->scorePuntaje->ForeColor = System::Drawing::Color::Black;
			this->scorePuntaje->Location = System::Drawing::Point(688, 38);
			this->scorePuntaje->Name = L"scorePuntaje";
			this->scorePuntaje->Size = System::Drawing::Size(177, 45);
			this->scorePuntaje->TabIndex = 2;
			this->scorePuntaje->Text = L"0/100";
			this->scorePuntaje->Click += gcnew System::EventHandler(this, &Juego::label1_Click);
			//
			// pictureBox5
			//
			this->pictureBox5->BackColor = System::Drawing::Color::PapayaWhip;
			this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(1092, 27);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(148, 75);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Juego::pictureBox5_Click);
			//
			// pictureBox3
			//
			this->pictureBox3->BackColor = System::Drawing::Color::PapayaWhip;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(373, -9);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(519, 129);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			//
			// disponiblesAliado
			//
			this->disponiblesAliado->AutoSize = true;
			this->disponiblesAliado->BackColor = System::Drawing::Color::White;
			this->disponiblesAliado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
			this->disponiblesAliado->Location = System::Drawing::Point(24, 33);
			this->disponiblesAliado->Name = L"disponiblesAliado";
			this->disponiblesAliado->Padding = System::Windows::Forms::Padding(2);
			this->disponiblesAliado->Size = System::Drawing::Size(177, 62);
			this->disponiblesAliado->TabIndex = 0;
			this->disponiblesAliado->Text = L"Aliados\r\nDisponibles : ";
			//
			// mute2
			//
			this->mute2->BackColor = System::Drawing::Color::PapayaWhip;
			this->mute2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mute2.Image")));
			this->mute2->Location = System::Drawing::Point(936, 19);
			this->mute2->Name = L"mute2";
			this->mute2->Size = System::Drawing::Size(150, 98);
			this->mute2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mute2->TabIndex = 9;
			this->mute2->TabStop = false;
			this->mute2->Visible = false;
			this->mute2->Click += gcnew System::EventHandler(this, &Juego::mute2_Click);
			//
			// mute
			//
			this->mute->BackColor = System::Drawing::Color::PapayaWhip;
			this->mute->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mute.Image")));
			this->mute->Location = System::Drawing::Point(933, 27);
			this->mute->Name = L"mute";
			this->mute->Size = System::Drawing::Size(152, 90);
			this->mute->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mute->TabIndex = 10;
			this->mute->TabStop = false;
			this->mute->Click += gcnew System::EventHandler(this, &Juego::mute_Click);
			//
			// Juego
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1252, 713);
			this->Controls->Add(this->mute);
			this->Controls->Add(this->mute2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->disponiblesAliado);
			this->Controls->Add(this->pantallaJuego);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->scorePuntaje);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tSegundos);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->panelAtributos);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Juego::Juego_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::MantenerTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::UltimaTeclaPresionada);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pantallaJuego))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelAtributos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		disponiblesAliado->Text = " Aliados \n Disponibles: " + Convert::ToString(oControladora->get_disponibles());
		oControladora->set_tiempo(tiempoSegundos);
		// imprimir a pantalla principal
		Graphics^ g = pantallaJuego->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		// cada 100 ms sobre-imprimira todos las imagenes
		//ACA AGREGAR LOS SPRITES BITMAP^
		if (nMapa == 1)
			oControladora->dibujar_Mapa1(buffer->Graphics, bmpSuelo, bmpPiedra, bmpJugador, bmpCama, bmpCajon, bmpSillon, bmpPlanta,
				bmpEnemigo, bmpHabitanteUno, bmpHabitanteDos, bmpAliado);
		else if (nMapa == 2)
			oControladora->dibujar_Mapa2(buffer->Graphics, bmpSuelo, bmpPiedra, bmpJugador,
				bmpArbol, bmpArbol2, bmpCartel, bmpArbusto, bmpCasa, bmpCasa2, bmpEnemigo, bmpHabitanteUno, bmpHabitanteDos, bmpAliado);

		buffer->Render(g);
		delete buffer, espacio, g;
		//TEMPORIZADOR
		if (milisegundos == 1000 && tiempoSegundos != 0)
		{
			milisegundos = 0;
			tiempoSegundos -= 1;
		}
		if (tiempoSegundos == 0 && tiempoMinutos != 0)
		{
			tiempoMinutos -= 1;
			tiempoSegundos = 59;
		}
		tSegundos->Text = ((tiempoMinutos < 10) ? "0" : "") + Convert::ToString(tiempoMinutos) + ":"
			+ ((tiempoSegundos < 10) ? "0" : "") + Convert::ToString(tiempoSegundos);

		milisegundos += 100;
		//PUNTAJE
		scorePuntaje->Text = Convert::ToString(oControladora->get_puntaje()) + "/100";
		//FIN DEL JUEGO
		if ((tiempoMinutos == 0 && tiempoSegundos == 0) || oControladora->get_puntaje() >= 100)
		{
			this->timer1->Enabled = false; // detiene el juego
			//message box
			if (MessageBox::Show((tiempoMinutos == 0 && tiempoSegundos == 0()) ? "HAS PERDIDO :( " : "HAS GANADO :) ",
				"Fin del Juego", MessageBoxButtons::OK, MessageBoxIcon::Exclamation) == System
				::Windows::Forms::DialogResult::OK)
			{
				Creditos^ abrirCreditos = gcnew Creditos(oControladora->get_puntaje());
				this->Close();
				bienvenida->Hide();
				abrirCreditos->Show();
			}
		}
	}

	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
		musicaJuego->PlayLooping();
		this->pictureBox3->Image = bmpBordeJuego;
		oControladora = new Controladora(nMapa, nEnemigo, nHabitante, nAliado);
		this->pictureBox2->Image = bmpPuntaje;
	}
	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//pulsacion de una tecla
		switch (e->KeyCode)
		{
		case Keys::Up:
		case Keys::W:
			oControladora->getJugador()->set_direccion(Direcciones::Arriba);
			break;
		case Keys::Down:
		case Keys::S:
			oControladora->getJugador()->set_direccion(Direcciones::Abajo);
			break;
		case Keys::Left:
		case Keys::A:
			oControladora->getJugador()->set_direccion(Direcciones::Izquierda);
			break;
		case Keys::Right:
		case Keys::D:
			oControladora->getJugador()->set_direccion(Direcciones::Derecha);
			break;
		case Keys::Space:
			oControladora->revisar_visibles();
		}
	}
	private: System::Void UltimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//cuando no se presiona una tecla
		switch (e->KeyCode)
		{
		default:
			oControladora->getJugador()->set_direccion(Direcciones::Ninguna);
			break;
		}
	}
	private: System::Void pantallaJuego_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		bienvenida->Show();
		bienvenida->BringToFront();
		musica->PlayLooping();
		this->Close();
	}
	private: System::Void Juego_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		bienvenida->Show();
		bienvenida->BringToFront();
		musica->PlayLooping();
	}
	private: System::Void mute_Click(System::Object^ sender, System::EventArgs^ e) {
		musicaJuego->Stop();
		mute->Visible = false;
		mute2->Visible = true;
	}
	private: System::Void mute2_Click(System::Object^ sender, System::EventArgs^ e) {
		musicaJuego->PlayLooping();
		mute->Visible = true;
		mute2->Visible = false;
	}
	};
}

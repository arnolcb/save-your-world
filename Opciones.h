#pragma once
#include "Juego.h"
namespace UPCJuego {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Opciones
	/// </summary>
	public ref class Opciones : public System::Windows::Forms::Form
	{
		Form^ obj;
		int mapa;
		int tiempo;
		int enemigo;
		int aliado;
		int habitante;
		SoundPlayer^ musica;
		bool parpadeo;
	private: System::Windows::Forms::NumericUpDown^ tiempoWheel1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ mapaSeleccion;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ aliadosWheel;
	private: System::Windows::Forms::NumericUpDown^ enemigoWheel;
	private: System::Windows::Forms::NumericUpDown^ habitanteWheel;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::PictureBox^ mapaAmbiente;
	private: System::Windows::Forms::PictureBox^ fondoAmbiente;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ fondoHospital;

	public:

		Opciones(void)
		{
			InitializeComponent();
		}
		Opciones(Form^ obj2, SoundPlayer^ sonido, SoundPlayer^ sonido2)
		{
			InitializeComponent();
			obj = obj2;
			musica = sonido2;
			mapa = 1;
			tiempo = 1;
			enemigo = 1;
			aliado = 1;
			habitante = 1;
			parpadeo = false;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Opciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ mapaHospital;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Opciones::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->mapaHospital = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tiempoWheel1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mapaSeleccion = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->aliadosWheel = (gcnew System::Windows::Forms::NumericUpDown());
			this->enemigoWheel = (gcnew System::Windows::Forms::NumericUpDown());
			this->habitanteWheel = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->mapaAmbiente = (gcnew System::Windows::Forms::PictureBox());
			this->fondoAmbiente = (gcnew System::Windows::Forms::PictureBox());
			this->fondoHospital = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapaHospital))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tiempoWheel1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aliadosWheel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemigoWheel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->habitanteWheel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapaAmbiente))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fondoAmbiente))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fondoHospital))->BeginInit();
			this->SuspendLayout();
			//
			// pictureBox1
			//
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(935, 582);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Opciones::pictureBox1_Click);
			//
			// pictureBox2
			//
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(779, 493);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(143, 62);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Opciones::pictureBox2_Click);
			//
			// mapaHospital
			//
			this->mapaHospital->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mapaHospital->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mapaHospital.Image")));
			this->mapaHospital->Location = System::Drawing::Point(88, 89);
			this->mapaHospital->Name = L"mapaHospital";
			this->mapaHospital->Size = System::Drawing::Size(331, 209);
			this->mapaHospital->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mapaHospital->TabIndex = 3;
			this->mapaHospital->TabStop = false;
			this->mapaHospital->Click += gcnew System::EventHandler(this, &Opciones::pictureBox3_Click);
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(121)), static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(335, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 55);
			this->label2->TabIndex = 4;
			this->label2->Text = L"OPCIONES";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// label4
			//
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(227, 376);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(230, 25);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Mapa seleccionado :\r\n";
			//
			// pictureBox5
			//
			this->pictureBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(12, 495);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(121, 62);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 6;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Opciones::pictureBox5_Click);
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(359, 417);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Tiempo :";
			//
			// tiempoWheel1
			//
			this->tiempoWheel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tiempoWheel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->tiempoWheel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->tiempoWheel1->Location = System::Drawing::Point(500, 412);
			this->tiempoWheel1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->tiempoWheel1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->tiempoWheel1->Name = L"tiempoWheel1";
			this->tiempoWheel1->ReadOnly = true;
			this->tiempoWheel1->Size = System::Drawing::Size(63, 35);
			this->tiempoWheel1->TabIndex = 8;
			this->tiempoWheel1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->tiempoWheel1->ValueChanged += gcnew System::EventHandler(this, &Opciones::tiempoWheel_ValueChanged);
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(570, 418);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"minutos";
			this->label3->Click += gcnew System::EventHandler(this, &Opciones::label3_Click);
			//
			// mapaSeleccion
			//
			this->mapaSeleccion->AutoSize = true;
			this->mapaSeleccion->BackColor = System::Drawing::Color::Transparent;
			this->mapaSeleccion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mapaSeleccion->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->mapaSeleccion->Location = System::Drawing::Point(499, 376);
			this->mapaSeleccion->Name = L"mapaSeleccion";
			this->mapaSeleccion->Size = System::Drawing::Size(68, 25);
			this->mapaSeleccion->TabIndex = 9;
			this->mapaSeleccion->Text = L"[      ]";
			this->mapaSeleccion->Click += gcnew System::EventHandler(this, &Opciones::label3_Click);
			//
			// label6
			//
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(335, 458);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"#Aliados :";
			//
			// label7
			//
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(323, 499);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(142, 25);
			this->label7->TabIndex = 5;
			this->label7->Text = L"#Enemigos :";
			//
			// label8
			//
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(299, 540);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(152, 25);
			this->label8->TabIndex = 5;
			this->label8->Text = L"#Habitantes :";
			//
			// aliadosWheel
			//
			this->aliadosWheel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->aliadosWheel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aliadosWheel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->aliadosWheel->Location = System::Drawing::Point(500, 453);
			this->aliadosWheel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->aliadosWheel->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->aliadosWheel->Name = L"aliadosWheel";
			this->aliadosWheel->ReadOnly = true;
			this->aliadosWheel->Size = System::Drawing::Size(63, 35);
			this->aliadosWheel->TabIndex = 8;
			this->aliadosWheel->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->aliadosWheel->ValueChanged += gcnew System::EventHandler(this, &Opciones::tiempoWheel_ValueChanged);
			//
			// enemigoWheel
			//
			this->enemigoWheel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->enemigoWheel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->enemigoWheel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->enemigoWheel->Location = System::Drawing::Point(500, 494);
			this->enemigoWheel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->enemigoWheel->Name = L"enemigoWheel";
			this->enemigoWheel->ReadOnly = true;
			this->enemigoWheel->Size = System::Drawing::Size(63, 35);
			this->enemigoWheel->TabIndex = 8;
			this->enemigoWheel->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->enemigoWheel->ValueChanged += gcnew System::EventHandler(this, &Opciones::tiempoWheel_ValueChanged);
			//
			// habitanteWheel
			//
			this->habitanteWheel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->habitanteWheel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->habitanteWheel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->habitanteWheel->Location = System::Drawing::Point(500, 535);
			this->habitanteWheel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->habitanteWheel->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->habitanteWheel->Name = L"habitanteWheel";
			this->habitanteWheel->ReadOnly = true;
			this->habitanteWheel->Size = System::Drawing::Size(63, 35);
			this->habitanteWheel->TabIndex = 8;
			this->habitanteWheel->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->habitanteWheel->ValueChanged += gcnew System::EventHandler(this, &Opciones::tiempoWheel_ValueChanged);
			//
			// label9
			//
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(131, 307);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(241, 29);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Problematica Salud";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// label10
			//
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(554, 307);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(290, 29);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Problematica Ambiental";
			this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// mapaAmbiente
			//
			this->mapaAmbiente->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mapaAmbiente->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mapaAmbiente.Image")));
			this->mapaAmbiente->Location = System::Drawing::Point(537, 89);
			this->mapaAmbiente->Name = L"mapaAmbiente";
			this->mapaAmbiente->Size = System::Drawing::Size(331, 209);
			this->mapaAmbiente->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mapaAmbiente->TabIndex = 3;
			this->mapaAmbiente->TabStop = false;
			this->mapaAmbiente->Click += gcnew System::EventHandler(this, &Opciones::mapaAmbiente_Click);
			//
			// fondoAmbiente
			//
			this->fondoAmbiente->BackColor = System::Drawing::Color::RoyalBlue;
			this->fondoAmbiente->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->fondoAmbiente->Location = System::Drawing::Point(521, 78);
			this->fondoAmbiente->Name = L"fondoAmbiente";
			this->fondoAmbiente->Size = System::Drawing::Size(363, 235);
			this->fondoAmbiente->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->fondoAmbiente->TabIndex = 10;
			this->fondoAmbiente->TabStop = false;
			this->fondoAmbiente->Visible = false;
			//
			// fondoHospital
			//
			this->fondoHospital->BackColor = System::Drawing::Color::RoyalBlue;
			this->fondoHospital->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->fondoHospital->Location = System::Drawing::Point(75, 78);
			this->fondoHospital->Name = L"fondoHospital";
			this->fondoHospital->Size = System::Drawing::Size(360, 235);
			this->fondoHospital->TabIndex = 10;
			this->fondoHospital->TabStop = false;
			//
			// timer1
			//
			this->timer1->Enabled = true;
			this->timer1->Interval = 800;
			this->timer1->Tick += gcnew System::EventHandler(this, &Opciones::timer1_Tick);
			//
			// Opciones
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(934, 579);
			this->Controls->Add(this->mapaAmbiente);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->mapaHospital);
			this->Controls->Add(this->fondoHospital);
			this->Controls->Add(this->fondoAmbiente);
			this->Controls->Add(this->mapaSeleccion);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->habitanteWheel);
			this->Controls->Add(this->enemigoWheel);
			this->Controls->Add(this->aliadosWheel);
			this->Controls->Add(this->tiempoWheel1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Opciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Opciones";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Opciones::Opciones_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Opciones::Opciones_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapaHospital))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tiempoWheel1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aliadosWheel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemigoWheel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->habitanteWheel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapaAmbiente))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fondoAmbiente))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fondoHospital))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		obj->Show();
		obj->BringToFront();
		this->Close();
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		//obtener valores
		tiempo = Convert::ToInt32(tiempoWheel1->Value);
		enemigo = Convert::ToInt32(enemigoWheel->Value);
		aliado = Convert::ToInt32(aliadosWheel->Value);
		habitante = Convert::ToInt32(habitanteWheel->Value);

		this->Hide();
		Juego^ abrirJuego = gcnew Juego(obj, musica, mapa, tiempo, enemigo, aliado, habitante);
		abrirJuego->Show();
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tiempoWheel_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Opciones_Load(System::Object^ sender, System::EventArgs^ e) {
		mapaSeleccion->Text = "HOSPITAL";
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		//mapa hospital click
		fondoHospital->Visible = true;
		fondoAmbiente->Visible = false;
		mapaSeleccion->Text = "HOSPITAL";
		mapa = 1;
	}
	private: System::Void mapaAmbiente_Click(System::Object^ sender, System::EventArgs^ e) {
		//mapa ambiente click
		fondoHospital->Visible = false;
		fondoAmbiente->Visible = true;
		mapaSeleccion->Text = "BOSQUE";
		mapa = 2;
	}
	private: System::Void Opciones_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		obj->Show();
		obj->BringToFront();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (mapa == 1)
		{
			if (parpadeo == false)
			{
				parpadeo = true;
				fondoHospital->Visible = true;
			}

			else if (parpadeo == true)
			{
				parpadeo = false;
				fondoHospital->Visible = false;
			}
		}
		if (mapa == 2)
		{
			if (parpadeo == false)
			{
				parpadeo = true;
				fondoAmbiente->Visible = true;
			}

			else if (parpadeo == true)
			{
				parpadeo = false;
				fondoAmbiente->Visible = false;
			}
		}
	}
	};
}

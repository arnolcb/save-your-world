#pragma once
#include "Instrucciones.h"
#include "Opciones.h"

namespace UPCJuego {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media; // sonidos

	/// <summary>
	/// Summary for Bienvenida
	/// </summary>
	public ref class Bienvenida : public System::Windows::Forms::Form
	{
	public:
		SoundPlayer^ sonidoBienvenida = gcnew SoundPlayer("sonido\\bienvenida.wav");
	private: System::Windows::Forms::PictureBox^ mute;
	private: System::Windows::Forms::PictureBox^ mute2;
	private: System::Windows::Forms::Timer^ timer1;

	public:

	public:
		SoundPlayer^ sonidoClick = gcnew SoundPlayer("sonido\\click_sonido.wav");
		Bienvenida(void)
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
		~Bienvenida()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ playButton;
	private: System::Windows::Forms::PictureBox^ helpButton;
	private: System::Windows::Forms::PictureBox^ exitButton;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Bienvenida::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->playButton = (gcnew System::Windows::Forms::PictureBox());
			this->helpButton = (gcnew System::Windows::Forms::PictureBox());
			this->exitButton = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mute = (gcnew System::Windows::Forms::PictureBox());
			this->mute2 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->helpButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exitButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(738, 65);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(98, 98);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// playButton
			// 
			this->playButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playButton.Image")));
			this->playButton->Location = System::Drawing::Point(713, 297);
			this->playButton->Name = L"playButton";
			this->playButton->Size = System::Drawing::Size(157, 73);
			this->playButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->playButton->TabIndex = 1;
			this->playButton->TabStop = false;
			this->playButton->Click += gcnew System::EventHandler(this, &Bienvenida::playButton_Click);
			this->playButton->MouseLeave += gcnew System::EventHandler(this, &Bienvenida::playButton_MouseLeave);
			this->playButton->MouseHover += gcnew System::EventHandler(this, &Bienvenida::playButton_MouseHover);
			// 
			// helpButton
			// 
			this->helpButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->helpButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"helpButton.Image")));
			this->helpButton->Location = System::Drawing::Point(724, 364);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(131, 69);
			this->helpButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->helpButton->TabIndex = 1;
			this->helpButton->TabStop = false;
			this->helpButton->Click += gcnew System::EventHandler(this, &Bienvenida::helpButton_Click);
			this->helpButton->MouseLeave += gcnew System::EventHandler(this, &Bienvenida::helpButton_MouseLeave);
			this->helpButton->MouseHover += gcnew System::EventHandler(this, &Bienvenida::helpButton_MouseHover);
			// 
			// exitButton
			// 
			this->exitButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exitButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitButton.Image")));
			this->exitButton->Location = System::Drawing::Point(792, 553);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(110, 52);
			this->exitButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->exitButton->TabIndex = 1;
			this->exitButton->TabStop = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &Bienvenida::exitButton_Click);
			this->exitButton->MouseLeave += gcnew System::EventHandler(this, &Bienvenida::exitButton_MouseLeave);
			this->exitButton->MouseHover += gcnew System::EventHandler(this, &Bienvenida::exitButton_MouseHover);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(-1, -12);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(651, 628);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 1;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Bienvenida::pictureBox5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(673, 192);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 78);
			this->label1->TabIndex = 2;
			this->label1->Text = L"SAVE YOUR \r\nWORLD";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Bienvenida::label1_Click);
			// 
			// mute
			// 
			this->mute->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mute.Image")));
			this->mute->Location = System::Drawing::Point(802, -5);
			this->mute->Name = L"mute";
			this->mute->Size = System::Drawing::Size(122, 68);
			this->mute->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mute->TabIndex = 3;
			this->mute->TabStop = false;
			this->mute->Click += gcnew System::EventHandler(this, &Bienvenida::pictureBox2_Click);
			// 
			// mute2
			// 
			this->mute2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mute2.Image")));
			this->mute2->Location = System::Drawing::Point(801, -13);
			this->mute2->Name = L"mute2";
			this->mute2->Size = System::Drawing::Size(134, 81);
			this->mute2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mute2->TabIndex = 4;
			this->mute2->TabStop = false;
			this->mute2->Visible = false;
			this->mute2->Click += gcnew System::EventHandler(this, &Bienvenida::pictureBox2_Click_1);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Bienvenida::timer1_Tick);
			// 
			// Bienvenida
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(913, 613);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->mute2);
			this->Controls->Add(this->mute);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->playButton);
			this->Controls->Add(this->helpButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->pictureBox5);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Bienvenida";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bienvenida";
			this->Load += gcnew System::EventHandler(this, &Bienvenida::Bienvenida_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->helpButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exitButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mute2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void playButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Opciones^ abrirOpciones = gcnew Opciones(this, sonidoClick, sonidoBienvenida);
		abrirOpciones->Show();
	}
	private: System::Void helpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Instrucciones^ abrirInstrucciones = gcnew Instrucciones();
		abrirInstrucciones->ShowDialog();
	}
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Bienvenida_Load(System::Object^ sender, System::EventArgs^ e) {
		sonidoBienvenida->PlayLooping();
	}
	private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void playButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->playButton->Location = System::Drawing::Point(707, 290);
		this->playButton->Size = System::Drawing::Size(157 * 1.1, 73 * 1.1);
	}
	private: System::Void playButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->playButton->Location = System::Drawing::Point(713, 297);
		this->playButton->Size = System::Drawing::Size(157, 73);
	}
	private: System::Void helpButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->helpButton->Location = System::Drawing::Point(720, 360);
		this->helpButton->Size = System::Drawing::Size(131 * 1.1, 69 * 1.1);
	}
	private: System::Void helpButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->helpButton->Location = System::Drawing::Point(724, 364);
		this->helpButton->Size = System::Drawing::Size(131, 69);
	}
	private: System::Void exitButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->exitButton->Location = System::Drawing::Point(787, 550);
		this->exitButton->Size = System::Drawing::Size(110 * 1.1, 52 * 1.1);
	}
	private: System::Void exitButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->exitButton->Location = System::Drawing::Point(792, 553);
		this->exitButton->Size = System::Drawing::Size(110, 52);
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		sonidoBienvenida->Stop();
		mute->Visible = false;
		mute2->Visible = true;
	}
	private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		sonidoBienvenida->PlayLooping();
		mute->Visible = true;
		mute2->Visible = false;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Random r;

		switch (r.Next(0, 10))
		{
		case 0: label1->ForeColor = System::Drawing::Color::LightGreen; break;
		case 1:label1->ForeColor = System::Drawing::Color::Red; break;
		case 2:label1->ForeColor = System::Drawing::Color::Blue; break;
		case 4:label1->ForeColor = System::Drawing::Color::Cyan; break;
		case 5:label1->ForeColor = System::Drawing::Color::Pink; break;
		case 6:label1->ForeColor = System::Drawing::Color::Black; break;
		case 7:label1->ForeColor = System::Drawing::Color::Orange; break;
		case 8: label1->ForeColor = System::Drawing::Color::Indigo; break;
		case 9:label1->ForeColor = System::Drawing::Color::Aqua; break;
		}
	}
	};
}

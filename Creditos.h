#pragma once

namespace UPCJuego {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
		SoundPlayer^ sonidoCreditos = gcnew SoundPlayer("sonido\\creditos.wav");
		int puntaje;
		int lugarY;
		double upcX, upcY;
		double crediX, creditY;
		double n1X, n1Y;
		double n2X, n2Y;
		double n3X, n3Y;
		double n4X, n4Y;

		double graciasX, graciasY;
	private: System::Windows::Forms::Label^ n4;

	private: System::Windows::Forms::PictureBox^ exitButton;

	public:
		Creditos(void)
		{
		}
		Creditos(int puntaje)
		{
			this->puntaje = puntaje;

			lugarY = 700;
			upcX = 201;
			upcY = 49 + lugarY;
			crediX = 177;
			creditY = 171 + lugarY;
			n1X = 88;
			n1Y = 231 + lugarY;
			n2X = 117;
			n2Y = 314 + lugarY;
			n3X = 74;
			n3Y = 395 + lugarY;
			n4X = 68;
			n4Y = 470 + lugarY;;
			graciasX = 168;
			graciasY = 560 + lugarY;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelScore;
	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ labelCreditos;
	private: System::Windows::Forms::Label^ labelN1;
	private: System::Windows::Forms::Label^ labelN2;
	private: System::Windows::Forms::Label^ labelN3;
	private: System::Windows::Forms::Label^ labelGracias;

	private: System::Windows::Forms::PictureBox^ picUPC;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Creditos::typeid));
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelCreditos = (gcnew System::Windows::Forms::Label());
			this->labelN1 = (gcnew System::Windows::Forms::Label());
			this->labelN2 = (gcnew System::Windows::Forms::Label());
			this->labelN3 = (gcnew System::Windows::Forms::Label());
			this->labelGracias = (gcnew System::Windows::Forms::Label());
			this->picUPC = (gcnew System::Windows::Forms::PictureBox());
			this->exitButton = (gcnew System::Windows::Forms::PictureBox());
			this->n4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picUPC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exitButton))->BeginInit();
			this->SuspendLayout();
			//
			// labelScore
			//
			this->labelScore->AutoSize = true;
			this->labelScore->BackColor = System::Drawing::Color::White;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold));
			this->labelScore->Location = System::Drawing::Point(291, 0);
			this->labelScore->Margin = System::Windows::Forms::Padding(0);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(234, 39);
			this->labelScore->TabIndex = 5;
			this->labelScore->Text = L"SCORE : 100";
			this->labelScore->Click += gcnew System::EventHandler(this, &Creditos::label2_Click);
			//
			// timer1
			//
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Creditos::timer1_Tick);
			//
			// pictureBox1
			//
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(525, 800);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Creditos::pictureBox1_Click);
			//
			// labelCreditos
			//
			this->labelCreditos->AutoSize = true;
			this->labelCreditos->BackColor = System::Drawing::Color::Black;
			this->labelCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->labelCreditos->ForeColor = System::Drawing::Color::White;
			this->labelCreditos->Location = System::Drawing::Point(177, 166);
			this->labelCreditos->Name = L"labelCreditos";
			this->labelCreditos->Padding = System::Windows::Forms::Padding(5);
			this->labelCreditos->Size = System::Drawing::Size(155, 39);
			this->labelCreditos->TabIndex = 6;
			this->labelCreditos->Text = L"CREDITOS";
			this->labelCreditos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// labelN1
			//
			this->labelN1->AutoSize = true;
			this->labelN1->BackColor = System::Drawing::Color::Black;
			this->labelN1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->labelN1->ForeColor = System::Drawing::Color::White;
			this->labelN1->Location = System::Drawing::Point(98, 233);
			this->labelN1->Name = L"labelN1";
			this->labelN1->Padding = System::Windows::Forms::Padding(3);
			this->labelN1->Size = System::Drawing::Size(335, 35);
			this->labelN1->TabIndex = 6;
			this->labelN1->Text = L"Anderson Raul Ore Aleman";
			this->labelN1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// labelN2
			//
			this->labelN2->AutoSize = true;
			this->labelN2->BackColor = System::Drawing::Color::Black;
			this->labelN2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->labelN2->ForeColor = System::Drawing::Color::White;
			this->labelN2->Location = System::Drawing::Point(127, 314);
			this->labelN2->Name = L"labelN2";
			this->labelN2->Padding = System::Windows::Forms::Padding(3);
			this->labelN2->Size = System::Drawing::Size(266, 35);
			this->labelN2->TabIndex = 6;
			this->labelN2->Text = L"Arnol Caceres Bueno";
			this->labelN2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// labelN3
			//
			this->labelN3->AutoSize = true;
			this->labelN3->BackColor = System::Drawing::Color::Black;
			this->labelN3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->labelN3->ForeColor = System::Drawing::Color::White;
			this->labelN3->Location = System::Drawing::Point(88, 393);
			this->labelN3->Name = L"labelN3";
			this->labelN3->Padding = System::Windows::Forms::Padding(3);
			this->labelN3->Size = System::Drawing::Size(348, 35);
			this->labelN3->TabIndex = 6;
			this->labelN3->Text = L"Jean Carlos Alberco Medina";
			this->labelN3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// labelGracias
			//
			this->labelGracias->AutoSize = true;
			this->labelGracias->BackColor = System::Drawing::Color::Black;
			this->labelGracias->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->labelGracias->ForeColor = System::Drawing::Color::White;
			this->labelGracias->Location = System::Drawing::Point(165, 560);
			this->labelGracias->Name = L"labelGracias";
			this->labelGracias->Padding = System::Windows::Forms::Padding(3);
			this->labelGracias->Size = System::Drawing::Size(192, 64);
			this->labelGracias->TabIndex = 6;
			this->labelGracias->Text = L"GRACIAS POR\r\nJUGAR !!!";
			this->labelGracias->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// picUPC
			//
			this->picUPC->BackColor = System::Drawing::Color::Black;
			this->picUPC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picUPC.Image")));
			this->picUPC->Location = System::Drawing::Point(205, 49);
			this->picUPC->Margin = System::Windows::Forms::Padding(0);
			this->picUPC->Name = L"picUPC";
			this->picUPC->Size = System::Drawing::Size(98, 98);
			this->picUPC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picUPC->TabIndex = 7;
			this->picUPC->TabStop = false;
			//
			// exitButton
			//
			this->exitButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->exitButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exitButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitButton.Image")));
			this->exitButton->Location = System::Drawing::Point(406, 742);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(109, 52);
			this->exitButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->exitButton->TabIndex = 8;
			this->exitButton->TabStop = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &Creditos::exitButton_Click);
			this->exitButton->MouseLeave += gcnew System::EventHandler(this, &Creditos::exitButton_MouseLeave);
			this->exitButton->MouseHover += gcnew System::EventHandler(this, &Creditos::exitButton_MouseHover);
			//
			// n4
			//
			this->n4->AutoSize = true;
			this->n4->BackColor = System::Drawing::Color::Black;
			this->n4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.75F, System::Drawing::FontStyle::Bold));
			this->n4->ForeColor = System::Drawing::Color::White;
			this->n4->Location = System::Drawing::Point(68, 466);
			this->n4->Name = L"n4";
			this->n4->Padding = System::Windows::Forms::Padding(3);
			this->n4->Size = System::Drawing::Size(392, 35);
			this->n4->TabIndex = 6;
			this->n4->Text = L"Luis Estefano Mederos Sanchez";
			this->n4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			//
			// Creditos
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(522, 800);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->picUPC);
			this->Controls->Add(this->labelGracias);
			this->Controls->Add(this->n4);
			this->Controls->Add(this->labelN3);
			this->Controls->Add(this->labelN2);
			this->Controls->Add(this->labelN1);
			this->Controls->Add(this->labelCreditos);
			this->Controls->Add(this->labelScore);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Creditos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Creditos";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Creditos::Creditos_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Creditos::Creditos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picUPC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exitButton))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		labelScore->Text = "SCORE: " + Convert::ToString(puntaje);

		this->picUPC->Location = System::Drawing::Point(upcX, upcY);
		this->labelCreditos->Location = System::Drawing::Point(crediX, creditY);
		this->labelN1->Location = System::Drawing::Point(n1X, n1Y);
		this->labelN2->Location = System::Drawing::Point(n2X, n2Y);
		this->labelN3->Location = System::Drawing::Point(n3X, n3Y);
		this->n4->Location = System::Drawing::Point(n4X, n4Y);
		this->labelGracias->Location = System::Drawing::Point(graciasX, graciasY);

		upcY = upcY - 6;
		creditY = creditY - 6;
		n1Y = n1Y - 6;
		n2Y = n2Y - 6;
		n3Y = n3Y - 6;
		n4Y = n4Y - 6;
		graciasY = graciasY - 6;
	}
	private: System::Void Creditos_Load(System::Object^ sender, System::EventArgs^ e) {
		sonidoCreditos->Play();
	}
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void exitButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->exitButton->Location = System::Drawing::Point(400, 737);
		this->exitButton->Size = System::Drawing::Size(110 * 1.1, 52 * 1.1);
	}
	private: System::Void exitButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->exitButton->Location = System::Drawing::Point(406, 742);
		this->exitButton->Size = System::Drawing::Size(110, 52);
	}
	private: System::Void Creditos_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Application::Exit();
	}
	};
}

#pragma once
#include "NeuralNetwork.h"
#include <msclr\marshal_cppstd.h>

int numberOfFiles(string path)
{
	fstream plik;
	int number = 0;

	for (int i=0;;i++)
	{
		string a = to_string(i);

		plik.open(path + a + ".txt", ios::in || ios::app);

		if (plik.good()) number++;
		else break;

		plik.close();
		plik.clear();
	}

	return number;
}

bool is_number(const string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

NeuralNetwork neuralnetwork;

namespace NeuralNetworkProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button11;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button12;



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::ProgressBar^  progressBar3;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::Label^  label16;
	private: System::ComponentModel::IContainer^  components;











	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(15, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(341, 39);
			this->label1->TabIndex = 5;
			this->label1->Text = L"NEURAL NETWORK";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(110, 73);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 50);
			this->button4->TabIndex = 9;
			this->button4->Text = L"CREATE NEW";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MenuForm::button4_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(110, 128);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 50);
			this->button1->TabIndex = 10;
			this->button1->Text = L"LOAD";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(110, 183);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 50);
			this->button2->TabIndex = 11;
			this->button2->Text = L"LEARN";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MenuForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(110, 238);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 50);
			this->button3->TabIndex = 12;
			this->button3->Text = L"RECOGNIZE";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MenuForm::button3_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(110, 293);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 50);
			this->button5->TabIndex = 13;
			this->button5->Text = L"EXIT";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MenuForm::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(105, 399);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(160, 26);
			this->textBox1->TabIndex = 14;
			this->textBox1->Text = L"Name of Network";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(105, 428);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(160, 26);
			this->textBox2->TabIndex = 15;
			this->textBox2->Text = L"Number of Layers";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox3->Location = System::Drawing::Point(105, 457);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(160, 26);
			this->textBox3->TabIndex = 16;
			this->textBox3->Text = L"Neurons in each layer";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(282, 421);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(40, 40);
			this->button6->TabIndex = 17;
			this->button6->Text = L"OK";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuForm::button6_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::LawnGreen;
			this->label2->Location = System::Drawing::Point(70, 346);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 20);
			this->label2->TabIndex = 18;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::MediumAquamarine;
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->button10);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(397, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(290, 454);
			this->panel1->TabIndex = 19;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(113, 346);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 20);
			this->label9->TabIndex = 28;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(66, 63);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(38, 26);
			this->textBox4->TabIndex = 27;
			this->textBox4->Text = L"%";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(96, 400);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(133, 17);
			this->label5->TabIndex = 1;
			this->label5->Text = L"AVERAGE COST:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(96, 382);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 17);
			this->label4->TabIndex = 0;
			this->label4->Text = L"EFFECTIVENESS:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->checkBox1->Location = System::Drawing::Point(135, 206);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(100, 21);
			this->checkBox1->TabIndex = 26;
			this->checkBox1->Text = L"Auto-Save";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::White;
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button10->Location = System::Drawing::Point(111, 287);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(150, 50);
			this->button10->TabIndex = 25;
			this->button10->Text = L"BACK";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MenuForm::button10_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::White;
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button9->Location = System::Drawing::Point(111, 233);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(150, 50);
			this->button9->TabIndex = 24;
			this->button9->Text = L"STATISTICS";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MenuForm::button9_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(110, 63);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(150, 25);
			this->comboBox1->TabIndex = 23;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MenuForm::comboBox1_SelectedIndexChanged);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::White;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button8->Location = System::Drawing::Point(110, 152);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(151, 50);
			this->button8->TabIndex = 22;
			this->button8->Text = L"SAVE";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MenuForm::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::White;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(110, 98);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(151, 50);
			this->button7->TabIndex = 21;
			this->button7->Text = L"START LEARNING";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MenuForm::button7_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(119, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 39);
			this->label3->TabIndex = 20;
			this->label3->Text = L"LEARN";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Crimson;
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->button12);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->button11);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Location = System::Drawing::Point(692, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(290, 399);
			this->panel2->TabIndex = 20;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MenuForm::panel2_Paint);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::White;
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button12->Location = System::Drawing::Point(110, 217);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(150, 33);
			this->button12->TabIndex = 28;
			this->button12->Text = L"Load the example";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MenuForm::button12_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(83, 258);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(195, 20);
			this->label6->TabIndex = 27;
			this->label6->Text = L"RECOGNIZED NUMBER:";
			this->label6->Click += gcnew System::EventHandler(this, &MenuForm::label6_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::White;
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button11->Location = System::Drawing::Point(110, 287);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(150, 50);
			this->button11->TabIndex = 26;
			this->button11->Text = L"BACK";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MenuForm::button11_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(110, 58);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 151);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Location = System::Drawing::Point(74, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(221, 39);
			this->label8->TabIndex = 20;
			this->label8->Text = L"RECOGNIZE";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(70, 48);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 20);
			this->label7->TabIndex = 22;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::MediumAquamarine;
			this->panel3->Controls->Add(this->label15);
			this->panel3->Controls->Add(this->label14);
			this->panel3->Controls->Add(this->label12);
			this->panel3->Controls->Add(this->progressBar3);
			this->panel3->Controls->Add(this->progressBar2);
			this->panel3->Controls->Add(this->button13);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->progressBar1);
			this->panel3->Controls->Add(this->label13);
			this->panel3->Location = System::Drawing::Point(692, 405);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(331, 391);
			this->panel3->TabIndex = 29;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->ForeColor = System::Drawing::Color::White;
			this->label15->Location = System::Drawing::Point(102, 240);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(147, 20);
			this->label15->TabIndex = 32;
			this->label15->Text = L"Current/target ratio:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(102, 195);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(109, 20);
			this->label14->TabIndex = 31;
			this->label14->Text = L"Current result:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(102, 150);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(139, 20);
			this->label12->TabIndex = 30;
			this->label12->Text = L"The highest result:";
			// 
			// progressBar3
			// 
			this->progressBar3->Location = System::Drawing::Point(95, 264);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(179, 23);
			this->progressBar3->TabIndex = 29;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(95, 218);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(179, 23);
			this->progressBar2->TabIndex = 28;
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::White;
			this->button13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button13->Enabled = false;
			this->button13->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button13->Location = System::Drawing::Point(110, 310);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(150, 50);
			this->button13->TabIndex = 27;
			this->button13->Text = L"BACK";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MenuForm::button13_Click_1);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::DarkGray;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->label11);
			this->panel4->Controls->Add(this->label10);
			this->panel4->Location = System::Drawing::Point(95, 70);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(179, 70);
			this->panel4->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(18, 34);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 20);
			this->label11->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(16, 10);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(148, 20);
			this->label10->TabIndex = 0;
			this->label10->Text = L"LEARNING MODE:";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(95, 173);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(179, 23);
			this->progressBar1->TabIndex = 21;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label13->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label13->Location = System::Drawing::Point(88, 10);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(193, 39);
			this->label13->TabIndex = 20;
			this->label13->Text = L"LEARNING";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(93, 347);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 20);
			this->label16->TabIndex = 30;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(984, 792);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->Text = L"Neural Network";
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		MenuForm::Width = 270;
		MenuForm::Height = 370;
		label2->Text = "";
	}
private: System::Void MenuForm_Load(System::Object^  sender, System::EventArgs^  e) {
	MenuForm::Width = 270;
	MenuForm::Height = 290;
	comboBox1->Items->Add("Linear Learning");
	comboBox1->Items->Add("Random Learning");
	comboBox1->Items->Add("Advanced Learning");
	comboBox1->SelectedIndex = 0;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	MenuForm::Width = 270;
	MenuForm::Height = 290;

	msclr::interop::marshal_context context;
	size_t layers = atoi((context.marshal_as<string>(textBox2->Text)).c_str());
	string name = context.marshal_as<string>(textBox1->Text);
	string neurons = context.marshal_as<string>(textBox3->Text);
	vector<size_t> numbers;
	string number = "";

	for (int i = 0; i < neurons.size(); i++)
	{
		if (((neurons[i] != ' ')&&(i != neurons.size() - 1))|| ((neurons[i] != ' ') && (i == neurons.size() - 1)))
		{
			number += neurons[i];
		}
		else
		{
			if((number!="") && (number != "0") && (is_number(number)))numbers.push_back(atoi(number.c_str()));
			number = "";
		}

		if ((i == neurons.size() - 1) && (number != ""))
		{
			numbers.push_back(atoi(number.c_str()));
		}
	}

	if (!is_number(context.marshal_as<string>(textBox2->Text)))
	{
		label2->Location = System::Drawing::Point(72, 225);
		label2->ForeColor = System::Drawing::Color::Red;
		label2->Text = "Wrong layers value!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label2->Text = "";
	}
	else if (layers > 10)
	{
		label2->Location = System::Drawing::Point(20, 225);
		label2->ForeColor = System::Drawing::Color::Red;
		label2->Text = "The network can't have more than 10 layers!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label2->Text = "";
	}
	else if (layers < 2)
	{
		label2->Location = System::Drawing::Point(20, 225);
		label2->ForeColor = System::Drawing::Color::Red;
		label2->Text = "The network can't have less than 2 layers!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label2->Text = "";
	}
	else if (numbers.size() != layers)
	{
		label2->Location = System::Drawing::Point(50, 225);
		label2->ForeColor = System::Drawing::Color::Red;
		label2->Text = "Incorrect number of neurons!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label2->Text = "";
	}
	else
	{
		neuralnetwork.clear();
		string bufor = "";

		for (int i = 0; i < name.size(); i++)
		{
			if (name[i] != ' ') bufor += name[i];
		}
		name = bufor;

		neuralnetwork.CREATE(name, layers, numbers);
		label7->ForeColor = System::Drawing::Color::White;
		label7->Text = "Layers: " + layers + " Neurons: " + textBox3->Text;
		label2->Location = System::Drawing::Point(50, 225);
		label2->ForeColor = System::Drawing::Color::LawnGreen;
		label2->Text = "The network has been created!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label2->Text = "";
	}	
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	MenuForm::Width = 270;
	MenuForm::Height = 290;
	label7->Visible = false;
	panel1->Height = 290;
	panel1->Width = 270;
	panel1->Location = System::Drawing::Point(0, 0);
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	MenuForm::Width = 270;
	MenuForm::Height = 290;
	label7->Visible = true;
	panel1->Location = System::Drawing::Point(500, 500);
	label2->Location = System::Drawing::Point(50, 225);
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	msclr::interop::marshal_context context;
	string path;

	FolderBrowserDialog^ folderBrowserDialog1;
	folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

	folderBrowserDialog1->Description = "Select a package with examples!";

	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

	path = context.marshal_as<string>(folderBrowserDialog1->SelectedPath);

	if (path == "")
	{
		label9->Location = System::Drawing::Point(90, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "Wrong path!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else if (!neuralnetwork.verify())
	{
		label9->Location = System::Drawing::Point(40, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "There is no network in the memory!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else
	{
		if (path[path.size() - 1] != '\\') path += '\\';

		if (numberOfFiles(path) == 0)
		{
			label9->Location = System::Drawing::Point(65, 225);
			label9->ForeColor = System::Drawing::Color::White;
			label9->Text = "There are no examples!";
			Application::DoEvents();
			System::Threading::Thread::Sleep(2000);
			label9->Text = "";
		}
		else
		{
			label4->Text = "EFFECTIVENESS: " + neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) + "%";
			label5->Text = "AVERAGE COST: " + neuralnetwork.averageCost(path, numberOfFiles(path));

			MenuForm::Width = 270;
			MenuForm::Height = 320;
		}
	}
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	MenuForm::Width = 270;
	MenuForm::Height = 290;
	label7->Visible = false;
	panel2->Height = 290;
	panel2->Width = 270;
	panel2->Location = System::Drawing::Point(0, 0);
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	MenuForm::Width = 270;
	MenuForm::Height = 290;
	panel2->Location = System::Drawing::Point(500, 500);
	label2->Location = System::Drawing::Point(50, 225);
	label7->Visible = true;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	msclr::interop::marshal_context context;
	string path;

	FolderBrowserDialog^ folderBrowserDialog1;
	folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

	folderBrowserDialog1->Description = "Select the network to load!";

	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

	path = context.marshal_as<string>(folderBrowserDialog1->SelectedPath);

	if (path != "")
	{
		neuralnetwork.clear();
		if (path[path.size() - 1] != '\\') path += '\\';
		bool check = neuralnetwork.LOAD(path);

		if (!check)
		{
			label2->Location = System::Drawing::Point(90, 225);
			label2->ForeColor = System::Drawing::Color::Red;
			label2->Text = "Wrong path!";
			Application::DoEvents();
			System::Threading::Thread::Sleep(2000);
			label2->Text = "";
		}
		else
		{
			string numneu="";
			for (int i = 0; i < neuralnetwork.layers; i++)
				numneu = numneu + to_string(neuralnetwork.numberOfNeurons[i]) + " ";

			String ^ NumNeu = gcnew String(numneu.c_str());

			label2->Location = System::Drawing::Point(50, 225);
			label2->ForeColor = System::Drawing::Color::LawnGreen;
			label2->Text = "The network has been loaded!";
			label7->ForeColor = System::Drawing::Color::White;
			label7->Text = "Layers: " + neuralnetwork.layers + " Neurons: " + NumNeu;
			Application::DoEvents();
			System::Threading::Thread::Sleep(2000);
			label2->Text = "";
		}
	}
	else
	{
		label2->Location = System::Drawing::Point(90, 225);
		label2->ForeColor = System::Drawing::Color::Red;
		label2->Text = "Wrong path!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label2->Text = "";
	}
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	msclr::interop::marshal_context context;
	string path;

	FolderBrowserDialog^ folderBrowserDialog1;
	folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

	folderBrowserDialog1->Description = "Select a folder to write!";

	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

	path = context.marshal_as<string>(folderBrowserDialog1->SelectedPath);
	
	if (path == "")
	{
		label9->Location = System::Drawing::Point(90, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "Wrong path!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else if (!neuralnetwork.verify())
	{
		label9->Location = System::Drawing::Point(40, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "There is no network in the memory!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else
	{
		if (path[path.size() - 1] != '\\') path += '\\';

		neuralnetwork.SAVE(path);
		label9->Location = System::Drawing::Point(50, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "The network has been saved!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	
	msclr::interop::marshal_context context;
	string path, path2;

	FolderBrowserDialog^ folderBrowserDialog1;
	folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

	folderBrowserDialog1->Description = "Select a package with examples!";

	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

	path = context.marshal_as<string>(folderBrowserDialog1->SelectedPath);

	if (checkBox1->Checked == true)
	{
		FolderBrowserDialog^ folderBrowserDialog2;
		folderBrowserDialog2 = gcnew System::Windows::Forms::FolderBrowserDialog;

		folderBrowserDialog2->Description = "Select a folder to Auto-Save!";

		System::Windows::Forms::DialogResult result = folderBrowserDialog2->ShowDialog();

		path2 = context.marshal_as<string>(folderBrowserDialog2->SelectedPath);

		if (path2 != "")
		{
			if (path2[path2.size() - 1] != '\\') path2 += '\\';
		}
	}
	
	if (path == "" || (path2 == "" && checkBox1->Checked==true))
	{
		label9->Location = System::Drawing::Point(90, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "Wrong path!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else if (!neuralnetwork.verify())
	{
		label9->Location = System::Drawing::Point(40, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "There is no network in the memory!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else if ((!(atoi((context.marshal_as<string>(textBox4->Text)).c_str()) >= 0 && atoi((context.marshal_as<string>(textBox4->Text)).c_str()) <= 100))||((!is_number(context.marshal_as<string>(textBox4->Text)))))
	{
		label9->Location = System::Drawing::Point(55, 225);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Text = "Incorrect effectiveness target!";
		Application::DoEvents();
		System::Threading::Thread::Sleep(2000);
		label9->Text = "";
	}
	else
	{
		MenuForm::Width = 270;
		MenuForm::Height = 290;
		panel3->Height = 290;
		panel3->Width = 270;
		panel3->Location = System::Drawing::Point(0, 0);
		if (path[path.size() - 1] != '\\') path += '\\';

		label14->Text = "Current result: ";
		label12->Text = "The highest result : ";
		label15->Text = "Highest/target ratio: ";
		progressBar1->Value = 0;
		progressBar2->Value = 0;
		progressBar3->Value = 0;

		Application::DoEvents();
		System::Threading::Thread::Sleep(100);

		if (comboBox1->Text == "Linear Learning")
		{
			label11->Location = System::Drawing::Point(12, 22);
			label11->Text = "Linear Learning";

			float max = 0;
			fstream plik5; 
			plik5.open("C:\\Users\\Maksim\\Desktop\\Reszta\\Fuzja\\Statystyki.txt", ios::out | ios::app);
			Application::DoEvents();
			System::Threading::Thread::Sleep(100);

			while (true)
			{
				for (int i = 0; i < numberOfFiles(path); i++)
				{
					string a;
					a = to_string(i);
					neuralnetwork.loadActivations(path + a + ".txt");
					neuralnetwork.enumerationOfActivation();
					if(i==0)neuralnetwork.backPropagation(0);
					else neuralnetwork.backPropagation(i % 10);
				}

				Application::DoEvents();
				System::Threading::Thread::Sleep(100);

				progressBar2->Value = neuralnetwork.effectivenessStudy(path, numberOfFiles(path));
				label14->Text = "Current result: " + neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) + "%";
				plik5 << neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) << endl;
				if (checkBox1->Checked == true && neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) > max)
				{
					neuralnetwork.SAVE(path2);
				}
				if (neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) > max)
				{
					max = neuralnetwork.effectivenessStudy(path, numberOfFiles(path));
					label12->Text = "The highest result : " + max + "%";
					progressBar1->Value = max;
					if ((max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f <= 100)progressBar3->Value = (max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f;
					else progressBar3->Value = 100;
					label15->Text = "Highest/target ratio: " + ((max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f) + "%";
				}
				if (neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) >= atoi((context.marshal_as<string>(textBox4->Text)).c_str())) break;
			}
			plik5.close();
		}
		else if (comboBox1->Text == "Random Learning")
		{
			label11->Location = System::Drawing::Point(7, 22);
			label11->Text = "Random Learning";

			float max = 0;

			Application::DoEvents();
			System::Threading::Thread::Sleep(100);

			while (true)
			{
				for (int i = 0; i < numberOfFiles(path); i++)
				{
					size_t tmp = rand() % numberOfFiles(path);
					string a;
					a = to_string(tmp);
					neuralnetwork.loadActivations(path + a + ".txt");
					neuralnetwork.enumerationOfActivation();
					if(tmp==0)neuralnetwork.backPropagation(0);
					else neuralnetwork.backPropagation(tmp % 10);
				}
				Application::DoEvents();
				System::Threading::Thread::Sleep(100);

				progressBar2->Value = neuralnetwork.effectivenessStudy(path, numberOfFiles(path));
				label14->Text = "Current result: " + neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) + "%";
				if (checkBox1->Checked == true && neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) > max)
				{
					neuralnetwork.SAVE(path2);
				}
				if (neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) > max)
				{
					max = neuralnetwork.effectivenessStudy(path, numberOfFiles(path));
					label12->Text = "The highest result : " + max + "%";
					progressBar1->Value = max;
					if ((max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f <= 100)progressBar3->Value = (max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f;
					else progressBar3->Value = 100;
					label15->Text = "Highest/target ratio: " + ((max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f) + "%";
				}
				if (neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) >= atoi((context.marshal_as<string>(textBox4->Text)).c_str())) break;
			}
		}
		else if (comboBox1->Text == "Advanced Learning")
		{
			label11->Location = System::Drawing::Point(2, 22);
			label11->Text = "Advanced Learning";
			
			float max = 0;

			Application::DoEvents();
			System::Threading::Thread::Sleep(100);

			vector<vector<int>>stacksOfExamples;
			vector<int>singleStack;
			vector<int>tmp;

			float activationBufor = 0;
			vector<float> singleLayerSum;
			vector<vector<float>> sum;

			vector<vector<float>> layersOfWeightsBP;
			vector<float> singleLayerOfWeightsBP;

			vector<vector<float>> layersOfBiasesBP;
			vector<float> singleLayerOfBiasesBP;

			vector<vector<float>> layersOfCosts;
			vector<float> singleLayerOfCosts;
			float singleCost = 0;
			float check;

			while (true)
			{
				for (int i = 0; i < ceil(numberOfFiles(path) / 30.0f); i++)
				{
					for (int j = 0; j < 30; j++)
					{
						if (tmp.size() == 0)
						{
							for (int q = 0; q < numberOfFiles(path); q++)
							{
								tmp.push_back(q);
							}
						}
						int k = rand() % tmp.size();
						singleStack.push_back(tmp[k]);
						tmp.erase(tmp.begin() + k);
					}
					stacksOfExamples.push_back(singleStack);
					singleStack.clear();
				}

				for (int g = 0; g < stacksOfExamples.size(); g++)
				{
					for (int g1 = 0; g1 < 30; g1++)
					{
						string a;
						a = to_string(stacksOfExamples[g][g1]);
						neuralnetwork.loadActivations(path + a + ".txt");
						neuralnetwork.enumerationOfActivation();

						//BACKPROPAGATION
						for (size_t i = 1; i < neuralnetwork.neuralLayers.size(); i++)
						{
							for (size_t j = 0; j < neuralnetwork.neuralLayers[i].size(); j++)
							{
								for (size_t k = 0; k < neuralnetwork.neuralLayers[i][j].weight.size(); k++)
									activationBufor += neuralnetwork.neuralLayers[i][j].weight[k] * neuralnetwork.neuralLayers[i - 1][k].activation;

								activationBufor -= neuralnetwork.neuralLayers[i][j].bias;
								singleLayerSum.push_back(activationBufor);
								activationBufor = 0;
							}
							sum.push_back(singleLayerSum);
							singleLayerSum.clear();
						}
						for (size_t i = 0; i < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1].size(); i++)
						{
							if (i == 0 && stacksOfExamples[g][g1] % 10==10)
								check = 1;
							else if (i == stacksOfExamples[g][g1] % 10)
								check = 1;
							else
								check = 0;

							for (size_t j = 0; j < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 2].size(); j++)
							{
								singleLayerOfWeightsBP.push_back(neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 2][j].activation*neuralnetwork.sigmoidDerivative(sum[sum.size() - 1][i])*2.0f*(neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1][i].activation - check));
							}
						}
						if (g1 == 0)layersOfWeightsBP.push_back(singleLayerOfWeightsBP);
						else
						{
							for (int l = 0; l < layersOfWeightsBP[0].size(); l++)
							{
								layersOfWeightsBP[0][l] += singleLayerOfWeightsBP[l];
							}
						}
						singleLayerOfWeightsBP.clear();
						for (size_t i = 0; i < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1].size(); i++)
						{
							if (i == 0 && stacksOfExamples[g][g1] % 10 == 10)
								check = 1;
							else if (i == stacksOfExamples[g][g1] % 10)
								check = 1;
							else
								check = 0;

							singleLayerOfBiasesBP.push_back(neuralnetwork.sigmoidDerivative(sum[sum.size() - 1][i])*2.0f*(neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1][i].activation - check));
						}
						if (g1 == 0)layersOfBiasesBP.push_back(singleLayerOfBiasesBP);
						else
						{
							for (int l = 0; l < layersOfBiasesBP[0].size(); l++)
							{
								layersOfBiasesBP[0][l] += singleLayerOfBiasesBP[l];
							}
						}
						singleLayerOfBiasesBP.clear();
						for (size_t i = 0; i < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 2].size(); i++)
						{
							for (size_t j = 0; j < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1].size(); j++)
							{
								if (i == 0 && stacksOfExamples[g][g1] % 10 == 10)
									check = 1;
								else if (i == stacksOfExamples[g][g1] % 10)
									check = 1;
								else
									check = 0;

								singleCost += neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1][j].weight[i] * neuralnetwork.sigmoidDerivative(sum[sum.size() - 1][j])*2.0f*(neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 1][j].activation - check);
							}
							singleLayerOfCosts.push_back(singleCost);
							singleCost = 0;
						}
						layersOfCosts.push_back(singleLayerOfCosts);
						singleLayerOfCosts.clear();
						if (neuralnetwork.neuralLayers.size() > 2)
						{
							for (size_t q = 0; q < neuralnetwork.neuralLayers.size() - 2; q++)
							{
								for (size_t i = 0; i < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - (q + 2)].size(); i++)
								{
									for (size_t j = 0; j < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - (q + 3)].size(); j++)
									{
										singleLayerOfWeightsBP.push_back(neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - (q + 3)][j].activation*neuralnetwork.sigmoidDerivative(sum[sum.size() - (q + 2)][i])*2.0f*layersOfCosts[q][i]);
									}
								}
								if (g1 == 0)layersOfWeightsBP.push_back(singleLayerOfWeightsBP);
								else
								{
									for (int l = 0; l < layersOfWeightsBP[q + 1].size(); l++)
									{
										layersOfWeightsBP[q + 1][l] += singleLayerOfWeightsBP[l];
									}
								}
								singleLayerOfWeightsBP.clear();

								for (size_t i = 0; i < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - (q + 2)].size(); i++)
								{
									singleLayerOfBiasesBP.push_back(neuralnetwork.sigmoidDerivative(sum[sum.size() - (q + 2)][i])*2.0f*layersOfCosts[q][i]);
								}
								if (g1 == 0)layersOfBiasesBP.push_back(singleLayerOfBiasesBP);
								else
								{
									for (int l = 0; l < layersOfBiasesBP[q + 1].size(); l++)
									{
										layersOfBiasesBP[q + 1][l] += singleLayerOfBiasesBP[l];
									}
								}
								singleLayerOfBiasesBP.clear();

								if (q < (neuralnetwork.neuralLayers.size() - 1))
								{
									for (size_t i = 0; i < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - (q + 3)].size(); i++)
									{
										for (size_t j = 0; j < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - (q + 2)].size(); j++)
										{
											singleCost += neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - 2 - q][j].weight[i] * neuralnetwork.sigmoidDerivative(sum[sum.size() - (q + 2)][j])*2.0f*layersOfCosts[q][j];
										}
										singleLayerOfCosts.push_back(singleCost);
										singleCost = 0;
									}
									layersOfCosts.push_back(singleLayerOfCosts);
									singleLayerOfCosts.clear();
								}
							}
						}
						//BACKPROPAGATION
					}
					for (size_t i = 1; i < neuralnetwork.neuralLayers.size(); i++)
					{
						for (size_t j = 0; j < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - i].size(); j++)
						{
							for (size_t k = 0; k < neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - i][j].weight.size(); k++)
							{
								neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - i][j].weight[k] -= (layersOfWeightsBP[i - 1][k + (j*neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - i][j].weight.size())]) / 30;
							}
							neuralnetwork.neuralLayers[neuralnetwork.neuralLayers.size() - i][j].bias -= (layersOfBiasesBP[i - 1][j]) / 30;
						}
					}
					layersOfWeightsBP.clear();
					layersOfBiasesBP.clear();
				}

				stacksOfExamples.clear();

				Application::DoEvents();
				System::Threading::Thread::Sleep(100);

				progressBar2->Value = neuralnetwork.effectivenessStudy(path, numberOfFiles(path));
				label14->Text = "Current result: " + neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) + "%";
				if (checkBox1->Checked == true && neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) > max)
				{
					neuralnetwork.SAVE(path2);
				}
				if (neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) > max)
				{
					max = neuralnetwork.effectivenessStudy(path, numberOfFiles(path));
					label12->Text = "The highest result : " + max + "%";
					progressBar1->Value = max;
					if((max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f<=100)progressBar3->Value = (max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f;
					else progressBar3->Value = 100;
					label15->Text = "Highest/target ratio: " + ((max / atoi((context.marshal_as<string>(textBox4->Text)).c_str()))*100.0f) + "%";
				}

				if (neuralnetwork.effectivenessStudy(path, numberOfFiles(path)) >= atoi((context.marshal_as<string>(textBox4->Text)).c_str())) break;
			}
		}
	}
	button13->Enabled = true;
}
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button13_Click_1(System::Object^  sender, System::EventArgs^  e) {
	panel3->Location = System::Drawing::Point(500, 500);
	label11->Text = "";
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	
	msclr::interop::marshal_context context;
	
	string path="";
	string file="";
	string bufor="";

	OpenFileDialog^ openFileDialog1;
	openFileDialog1 = gcnew System::Windows::Forms::OpenFileDialog;


	if (!neuralnetwork.verify())
	{
	label16->Location = System::Drawing::Point(40, 225);
	label16->ForeColor = System::Drawing::Color::White;
	label16->Text = "There is no network in the memory!";
	Application::DoEvents();
	System::Threading::Thread::Sleep(2000);
	label16->Text = "";
	}
	else if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		path = context.marshal_as<string>(openFileDialog1->FileName);

		if (path[path.size() - 1] != 'g' && path[path.size() - 2] != 'n' && path[path.size() - 3] != 'p')
		{
			label16->Location = System::Drawing::Point(60, 225);
			label16->ForeColor = System::Drawing::Color::White;
			label16->Text = "Wrong file! Select .png file!";
			Application::DoEvents();
			System::Threading::Thread::Sleep(2000);
			label16->Text = "";
		}
		else
		{
			pictureBox1->ImageLocation = openFileDialog1->FileName;
			pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

			for (int i = path.size() - 1; i > 0; i--)
			{
				if (path[i] == '\\') break;
				file += path[i];
				path.erase(path.size() - 1, 1);
			}
			for (int i = file.size() - 1; i >= 0; i--)
				bufor += file[i];

			size_t found = bufor.find(".png");
			bufor.erase(found, 4);

			string wynik;

			wynik = to_string(neuralnetwork.RECOGNIZE(path + bufor + ".txt"));

			String ^ X = gcnew String(wynik.c_str());

			label6->Text = "RECOGNIZED NUMBER: " + X;
		}
	}
}
};
}

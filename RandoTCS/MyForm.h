#pragma once
#include "Defines.h"
#include "Randomize.h"
#include <msclr\marshal_cppstd.h>
#include <thread>

bool collectable = false;
bool character = false;
bool extog = false;
bool greenVeh = false;

bool extra = false;
bool panelOp = false;
bool hatOp = false;
bool colorOp = false;
bool enemyOp = false;
//bool enemy = false;
bool unlockAll = false;
LogicType logicType = casual;
std::string out = "out";
std::string vanillaDirectory = "";

//std::unique_ptr<std::ofstream> loggingIt;

namespace RandoTCS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	///<summary>
	///Summary for MyForm
	///</summary>
  public

	ref class MyForm : public System::Windows::Forms::Form {
	  public:
		MyForm(void) {
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	  protected:
		///<summary>
		///Clean up any resources being used.
		///</summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}

	  private:
		System::Windows::Forms::Button ^ button1;

	  private:
		System::Windows::Forms::Label ^ label1;

	  private:
		System::Windows::Forms::CheckBox ^ randCharacters;

	  private:
		System::Windows::Forms::CheckBox ^ IncludeExtog;

	  private:
		System::Windows::Forms::CheckBox ^ includeGreen;

	  private:
		System::Windows::Forms::CheckBox ^ randExtras;

	  private:
		System::Windows::Forms::CheckBox ^ randCollect;

	  private:
		System::Windows::Forms::CheckBox ^ randPanel;

	  private:
		System::Windows::Forms::CheckBox ^ randHat;

	  private:
		System::Windows::Forms::RadioButton ^ logCasual;

	  private:
		System::Windows::Forms::RadioButton ^ logGlitch;

	  private:
		System::Windows::Forms::RadioButton ^ logSupGl;

	  private:
		System::Windows::Forms::Label ^ label2;

	  private:
		System::Windows::Forms::TextBox ^ textBox1;

	  private:
		System::Windows::Forms::Label ^ label3;

	  private:
		System::Windows::Forms::Button ^ button2;

	  private:
		System::Windows::Forms::FolderBrowserDialog ^ folderBrowserDialog1;

	  protected:
	  private:
		///<summary>
		///Required designer variable.
		///</summary>
		System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

		///<summary>
		///Required method for Designer support - do not modify
		///the contents of this method with the code editor.
		///</summary>
		void InitializeComponent(void) {
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->randCharacters = (gcnew System::Windows::Forms::CheckBox());
			this->IncludeExtog = (gcnew System::Windows::Forms::CheckBox());
			this->includeGreen = (gcnew System::Windows::Forms::CheckBox());
			this->randExtras = (gcnew System::Windows::Forms::CheckBox());
			this->randCollect = (gcnew System::Windows::Forms::CheckBox());
			this->randPanel = (gcnew System::Windows::Forms::CheckBox());
			this->randHat = (gcnew System::Windows::Forms::CheckBox());
			this->logCasual = (gcnew System::Windows::Forms::RadioButton());
			this->logGlitch = (gcnew System::Windows::Forms::RadioButton());
			this->logSupGl = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 255);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(319, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Randomize";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 303);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 1;
			// 
			// randCharacters
			// 
			this->randCharacters->AutoSize = true;
			this->randCharacters->Location = System::Drawing::Point(139, 77);
			this->randCharacters->Name = L"randCharacters";
			this->randCharacters->Size = System::Drawing::Size(133, 17);
			this->randCharacters->TabIndex = 2;
			this->randCharacters->Text = L"Randomize Characters";
			this->randCharacters->UseVisualStyleBackColor = true;
			// 
			// IncludeExtog
			// 
			this->IncludeExtog->AutoSize = true;
			this->IncludeExtog->Location = System::Drawing::Point(160, 100);
			this->IncludeExtog->Name = L"IncludeExtog";
			this->IncludeExtog->Size = System::Drawing::Size(178, 17);
			this->IncludeExtog->TabIndex = 3;
			this->IncludeExtog->Text = L"Include Extra Toggle Characters";
			this->IncludeExtog->UseVisualStyleBackColor = true;
			// 
			// includeGreen
			// 
			this->includeGreen->AutoSize = true;
			this->includeGreen->Location = System::Drawing::Point(160, 123);
			this->includeGreen->Name = L"includeGreen";
			this->includeGreen->Size = System::Drawing::Size(136, 17);
			this->includeGreen->TabIndex = 4;
			this->includeGreen->Text = L"Include Green Vehicles";
			this->includeGreen->UseVisualStyleBackColor = true;
			// 
			// randExtras
			// 
			this->randExtras->AutoSize = true;
			this->randExtras->Location = System::Drawing::Point(139, 143);
			this->randExtras->Name = L"randExtras";
			this->randExtras->Size = System::Drawing::Size(111, 17);
			this->randExtras->TabIndex = 5;
			this->randExtras->Text = L"Randomize Extras";
			this->randExtras->UseVisualStyleBackColor = true;
			// 
			// randCollect
			// 
			this->randCollect->AutoSize = true;
			this->randCollect->Location = System::Drawing::Point(139, 166);
			this->randCollect->Name = L"randCollect";
			this->randCollect->Size = System::Drawing::Size(139, 17);
			this->randCollect->TabIndex = 6;
			this->randCollect->Text = L"Randomize Collectables";
			this->randCollect->UseVisualStyleBackColor = true;
			// 
			// randPanel
			// 
			this->randPanel->AutoSize = true;
			this->randPanel->Location = System::Drawing::Point(139, 189);
			this->randPanel->Name = L"randPanel";
			this->randPanel->Size = System::Drawing::Size(114, 17);
			this->randPanel->TabIndex = 7;
			this->randPanel->Text = L"Randomize Panels";
			this->randPanel->UseVisualStyleBackColor = true;
			// 
			// randHat
			// 
			this->randHat->AutoSize = true;
			this->randHat->Location = System::Drawing::Point(139, 212);
			this->randHat->Name = L"randHat";
			this->randHat->Size = System::Drawing::Size(148, 17);
			this->randHat->TabIndex = 8;
			this->randHat->Text = L"Randomize Hat Machines";
			this->randHat->UseVisualStyleBackColor = true;
			// 
			// logCasual
			// 
			this->logCasual->AutoSize = true;
			this->logCasual->Location = System::Drawing::Point(25, 100);
			this->logCasual->Name = L"logCasual";
			this->logCasual->Size = System::Drawing::Size(57, 17);
			this->logCasual->TabIndex = 10;
			this->logCasual->TabStop = true;
			this->logCasual->Text = L"Casual";
			this->logCasual->UseVisualStyleBackColor = true;
			// 
			// logGlitch
			// 
			this->logGlitch->AutoSize = true;
			this->logGlitch->Location = System::Drawing::Point(25, 119);
			this->logGlitch->Name = L"logGlitch";
			this->logGlitch->Size = System::Drawing::Size(64, 17);
			this->logGlitch->TabIndex = 11;
			this->logGlitch->Text = L"Glitched";
			this->logGlitch->UseVisualStyleBackColor = true;
			// 
			// logSupGl
			// 
			this->logSupGl->AutoSize = true;
			this->logSupGl->Location = System::Drawing::Point(25, 138);
			this->logSupGl->Name = L"logSupGl";
			this->logSupGl->Size = System::Drawing::Size(95, 17);
			this->logSupGl->TabIndex = 12;
			this->logSupGl->Text = L"Super Glitched";
			this->logSupGl->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Logic:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 42);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(225, 20);
			this->textBox1->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(182, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Unmodified game files with GOG exe:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(256, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 322);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->logSupGl);
			this->Controls->Add(this->logGlitch);
			this->Controls->Add(this->logCasual);
			this->Controls->Add(this->randHat);
			this->Controls->Add(this->randPanel);
			this->Controls->Add(this->randCollect);
			this->Controls->Add(this->randExtras);
			this->Controls->Add(this->includeGreen);
			this->Controls->Add(this->IncludeExtog);
			this->Controls->Add(this->randCharacters);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"TCSrandomizer1.5";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load_1);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	  private:

		System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
			button1->Enabled = false;

			randCharacters->Enabled = false;
			IncludeExtog->Enabled = false;
			includeGreen->Enabled = false;
			randExtras->Enabled = false;
			randCollect->Enabled = false;
			randPanel->Enabled = false;
			randHat->Enabled = false;

			logCasual->Enabled = false;
			logGlitch->Enabled = false;
			logSupGl->Enabled = false;

			textBox1->Enabled = false;
			button2->Enabled = false;

			label2->Enabled = false;
			label3->Enabled = false;

			character = randCharacters->Checked;
			extog = randExtras->Checked;
			greenVeh = includeGreen->Checked;
			extra = IncludeExtog->Checked;
			collectable = randCollect->Checked;
			panelOp = randPanel->Checked;
			hatOp = randHat->Checked;

			if (logCasual->Checked) logicType = casual;
			else if (logGlitch->Checked) logicType = glitched;
			else if (logSupGl->Checked) logicType = superGlitched;

			vanillaDirectory = msclr::interop::marshal_as<std::string>(textBox1->Text);

			std::remove("files/data");
			std::ofstream dat("files/data");
			dat << vanillaDirectory << '\n';
			dat << std::to_string(logicType);
			dat << std::to_string(character);
			dat << std::to_string(extog);
			dat << std::to_string(greenVeh);

			dat << std::to_string(extra);
			dat << std::to_string(collectable);
			dat << std::to_string(panelOp);
			dat << std::to_string(hatOp);
			dat.close();

			label1->Text = "Randomizing. . .";
			Refresh();
			//std::thread Rand(Randomize);
			//Rand.join();
			Randomize();
			label1->Text = "Done.";
		}

	  private:
		System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e) {
			folderBrowserDialog1->ShowDialog();
			textBox1->Text = folderBrowserDialog1->SelectedPath;
		}
	private: System::Void MyForm_Load_1(System::Object^ sender, System::EventArgs^ e) {
			this->randCharacters->Checked = character;
			this->IncludeExtog->Checked = extog;
			this->includeGreen->Checked = greenVeh;
			this->randExtras->Checked = extra;
			this->randCollect->Checked = collectable;
			this->randPanel->Checked = panelOp;
			this->randHat->Checked = hatOp;

			if (logicType == casual) this->logCasual->Checked = true;
			if (logicType == glitched) this->logGlitch->Checked = true;
			if (logicType == superGlitched) this->logSupGl->Checked = true;

			this->textBox1->Text = msclr::interop::marshal_as<System::String ^>(vanillaDirectory.c_str());

	}
};
} //namespace RandoTCS

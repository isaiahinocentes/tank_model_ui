#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <msclr\marshal_cppstd.h>

//#include "TankFunctions.h"


namespace TankModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;


	

	string rmse ="Root Squared Mean Error, RMSE";
	string mae = "Mean Absolute Error, MAE";
	string r =   "Correlation Coefficient, R";

	/// <summary>
	/// Summary for form_menu
	/// </summary>
	public ref class form_menu : public System::Windows::Forms::Form
	{
	public:
		form_menu(void)
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
		~form_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_reset;
	private: System::Windows::Forms::Button^  btn_upload;
	protected:

	private: System::Windows::Forms::Button^  btn_read;
	private: System::Windows::Forms::Button^  btn_init;
	private: System::Windows::Forms::Button^  btn_display;
	private: System::Windows::Forms::Button^  btn_optimize;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cbx_oef;
	private: System::Windows::Forms::PictureBox^  pic_oef;
	private: System::Windows::Forms::TextBox^  txt_debug;
	private: System::Windows::Forms::OpenFileDialog^  uploadFileDialog;
	private: System::Windows::Forms::TextBox^  Log;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form_menu::typeid));
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->btn_upload = (gcnew System::Windows::Forms::Button());
			this->btn_read = (gcnew System::Windows::Forms::Button());
			this->btn_init = (gcnew System::Windows::Forms::Button());
			this->btn_display = (gcnew System::Windows::Forms::Button());
			this->btn_optimize = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbx_oef = (gcnew System::Windows::Forms::ComboBox());
			this->pic_oef = (gcnew System::Windows::Forms::PictureBox());
			this->txt_debug = (gcnew System::Windows::Forms::TextBox());
			this->uploadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Log = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_oef))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_reset
			// 
			this->btn_reset->BackColor = System::Drawing::Color::LightBlue;
			this->btn_reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reset->Location = System::Drawing::Point(520, 319);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(90, 41);
			this->btn_reset->TabIndex = 0;
			this->btn_reset->Text = L"RESET";
			this->btn_reset->UseVisualStyleBackColor = false;
			// 
			// btn_upload
			// 
			this->btn_upload->BackColor = System::Drawing::Color::YellowGreen;
			this->btn_upload->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_upload->Location = System::Drawing::Point(18, 110);
			this->btn_upload->Name = L"btn_upload";
			this->btn_upload->Padding = System::Windows::Forms::Padding(10);
			this->btn_upload->Size = System::Drawing::Size(97, 44);
			this->btn_upload->TabIndex = 1;
			this->btn_upload->Text = L"Upload File";
			this->btn_upload->UseVisualStyleBackColor = false;
			this->btn_upload->Click += gcnew System::EventHandler(this, &form_menu::btn_upload_Click);
			// 
			// btn_read
			// 
			this->btn_read->BackColor = System::Drawing::Color::SpringGreen;
			this->btn_read->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_read->Location = System::Drawing::Point(138, 110);
			this->btn_read->Name = L"btn_read";
			this->btn_read->Size = System::Drawing::Size(153, 55);
			this->btn_read->TabIndex = 2;
			this->btn_read->Text = L"READ DATA";
			this->btn_read->UseVisualStyleBackColor = false;
			this->btn_read->Click += gcnew System::EventHandler(this, &form_menu::read_click);
			// 
			// btn_init
			// 
			this->btn_init->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_init->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_init->Location = System::Drawing::Point(138, 171);
			this->btn_init->Name = L"btn_init";
			this->btn_init->Size = System::Drawing::Size(153, 66);
			this->btn_init->TabIndex = 3;
			this->btn_init->Text = L"Initialize Water Levels";
			this->btn_init->UseVisualStyleBackColor = false;
			// 
			// btn_display
			// 
			this->btn_display->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_display->Location = System::Drawing::Point(138, 243);
			this->btn_display->Name = L"btn_display";
			this->btn_display->Size = System::Drawing::Size(153, 62);
			this->btn_display->TabIndex = 4;
			this->btn_display->Text = L"Display Results";
			this->btn_display->UseVisualStyleBackColor = true;
			// 
			// btn_optimize
			// 
			this->btn_optimize->BackColor = System::Drawing::Color::MediumOrchid;
			this->btn_optimize->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_optimize->Location = System::Drawing::Point(380, 315);
			this->btn_optimize->Name = L"btn_optimize";
			this->btn_optimize->Size = System::Drawing::Size(97, 48);
			this->btn_optimize->TabIndex = 5;
			this->btn_optimize->Text = L"OPTIMIZE";
			this->btn_optimize->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(704, 31);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Tank Model with Multi-Optional Objective Error Function";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(14, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"SOURCE:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(320, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(347, 19);
			this->label3->TabIndex = 8;
			this->label3->Text = L"SELECT OBJECTIVE ERROR FUNCTIONS (OEF):";
			// 
			// cbx_oef
			// 
			this->cbx_oef->FormattingEnabled = true;
			this->cbx_oef->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Root Squared Mean Error, RMSE", L"Mean Absolute Error, MAE",
					L"Correlation Coefficient, R"
			});
			this->cbx_oef->Location = System::Drawing::Point(324, 144);
			this->cbx_oef->Name = L"cbx_oef";
			this->cbx_oef->Size = System::Drawing::Size(343, 21);
			this->cbx_oef->TabIndex = 9;
			this->cbx_oef->Text = L"-- SELECT OEF FUNCTION --";
			this->cbx_oef->MouseLeave += gcnew System::EventHandler(this, &form_menu::show_formula);
			this->cbx_oef->MouseHover += gcnew System::EventHandler(this, &form_menu::show_formula);
			// 
			// pic_oef
			// 
			this->pic_oef->Location = System::Drawing::Point(380, 180);
			this->pic_oef->Name = L"pic_oef";
			this->pic_oef->Size = System::Drawing::Size(230, 76);
			this->pic_oef->TabIndex = 11;
			this->pic_oef->TabStop = false;
			this->pic_oef->MouseHover += gcnew System::EventHandler(this, &form_menu::show_formula);
			// 
			// txt_debug
			// 
			this->txt_debug->AcceptsTab = true;
			this->txt_debug->Location = System::Drawing::Point(324, 82);
			this->txt_debug->Name = L"txt_debug";
			this->txt_debug->Size = System::Drawing::Size(182, 20);
			this->txt_debug->TabIndex = 12;
			this->txt_debug->Visible = false;
			// 
			// uploadFileDialog
			// 
			this->uploadFileDialog->FileName = L"Data File";
			this->uploadFileDialog->Title = L"Select Text or CSV File";
			// 
			// Log
			// 
			this->Log->Location = System::Drawing::Point(673, 81);
			this->Log->Multiline = true;
			this->Log->Name = L"Log";
			this->Log->ReadOnly = true;
			this->Log->Size = System::Drawing::Size(228, 279);
			this->Log->TabIndex = 13;
			// 
			// form_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(913, 375);
			this->Controls->Add(this->Log);
			this->Controls->Add(this->txt_debug);
			this->Controls->Add(this->pic_oef);
			this->Controls->Add(this->cbx_oef);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_optimize);
			this->Controls->Add(this->btn_display);
			this->Controls->Add(this->btn_init);
			this->Controls->Add(this->btn_read);
			this->Controls->Add(this->btn_upload);
			this->Controls->Add(this->btn_reset);
			this->Name = L"form_menu";
			this->Text = L"form_menu";
			this->Load += gcnew System::EventHandler(this, &form_menu::form_menu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_oef))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void form_menu_Load(System::Object^  sender, System::EventArgs^  e) {
		this->pic_oef->Visible = false;
	}
private: System::Void show_formula(System::Object^  sender, System::EventArgs^  e) {
	this->pic_oef->Visible = true;

	if (this->cbx_oef->SelectedText == "Root Squared Mean Error, RMSE") {
		this->pic_oef->ImageLocation = "..\\..\\..\\..\\Dropbox\\Freelance - Gab\\Images\\oef_rmse.PNG";
	}
	else if (this->cbx_oef->SelectedText == "Correlation Coefficient, R") {
		this->pic_oef->ImageLocation = "..\\..\\..\\..\\Dropbox\\Freelance - Gab\\Images\\oef_r.PNG";
	}
	else if (this->cbx_oef->SelectedText == "Mean Absolute Error, MAE") {
		this->pic_oef->ImageLocation = "..\\..\\..\\..\\Dropbox\\Freelance - Gab\\Images\\oef_mae.PNG";
	}
}
private: System::Void read_click(System::Object^  sender, System::EventArgs^  e) {
	/*
	this->Open_File->DefaultExt = ".txt";
	this->Open_File->Filter = "Text Files|*.txt";
	this->Open_File->ShowDialog();
	if (this->Open_File->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::IO::StreamReader ^ sr = gcnew
			System::IO::StreamReader(Open_File->FileName);
		MessageBox::Show(sr->ReadToEnd));
		sr->Close();
	}

	if (Open_File->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		this->Cursor = gcnew System::Windows::Forms::Cursor(Open_File->OpenFile());
	}*/
}
private: System::Void btn_upload_Click(System::Object^  sender, System::EventArgs^  e) {
	
	//Open as stream
	/*if (uploadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::IO::StreamReader ^ sr = gcnew
			System::IO::StreamReader(uploadFileDialog->FileName);
		MessageBox::Show(sr->ReadToEnd());
		sr->Close();
	}*/

	
	//Open as Filea
	//uploadFileDialog->Filter = "Text Files|.txt";
	/*if (uploadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Cursor = gcnew System::Windows::Forms::Cursor(
				uploadFileDialog->OpenFile());

	}*/
	
	// Displays an OpenFileDialog so the user can select a Cursor.  
	OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
	openFileDialog1->Filter = "Cursor Files|*.cur|Text Files|*.txt";
	openFileDialog1->Title = "Select a Cursor or Text File";


	// Show the Dialog.  
	// If the user clicked OK in the dialog and  
	// a .CUR file was selected, open it.  
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		string path = marshal_as<string>(openFileDialog1->FileName) + "HAHAHA";
		String ^managed;
		ifstream file(path);
		printf("FILE PATH: ");
		managed = marshal_as<String^>(path);
		cout << "FILE PATH: " << path;
		this->Log->Text = managed;
		MessageBox::Show(openFileDialog1->FileName, "Path:");
		// Assign the cursor in the Stream to  
		// the Form's Cursor property.  
		//this->Cursor = gcnew
		//	System::Windows::Forms::Cursor(
		//		openFileDialog1->OpenFile());
	}

}
};
}

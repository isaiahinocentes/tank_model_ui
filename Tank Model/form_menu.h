#pragma once
#include <iostream>	//cout cin
#include <cstring>	//String Functions
#include <fstream>	//Filestream
#include <msclr\marshal_cppstd.h> //convert string^ to string
#include "Functions.h"
#include "Model.h"
#include "Compute.h"
#include "OEF.h"	

#define NL "\r\n"

namespace TankModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;
	using namespace System::IO;
	using namespace System::Reflection;

	string rmse ="Root Squared Mean Error, RMSE";
	string mae = "Mean Absolute Error, MAE";
	string r =   "Correlation Coefficient, R";
	string r2 = "Coefficient of determination, R2";

	static int method;

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



		private: System::Windows::Forms::Button^  btn_display;
		private: System::Windows::Forms::Button^  btn_optimize;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::ComboBox^  cbx_oef;
		private: System::Windows::Forms::PictureBox^  pic_oef;

		private: System::Windows::Forms::OpenFileDialog^  uploadFileDialog;
		private: System::Windows::Forms::TextBox^  Log;
		private: System::Windows::Forms::Button^  btn_predict;

		private: Assembly ^_assembly;
		private: Stream ^_imageStream;






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
			void InitializeComponent(void){
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form_menu::typeid));
				this->btn_reset = (gcnew System::Windows::Forms::Button());
				this->btn_upload = (gcnew System::Windows::Forms::Button());
				this->btn_display = (gcnew System::Windows::Forms::Button());
				this->btn_optimize = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->cbx_oef = (gcnew System::Windows::Forms::ComboBox());
				this->pic_oef = (gcnew System::Windows::Forms::PictureBox());
				this->uploadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->Log = (gcnew System::Windows::Forms::TextBox());
				this->btn_predict = (gcnew System::Windows::Forms::Button());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_oef))->BeginInit();
				this->SuspendLayout();
				// 
				// btn_reset
				// 
				this->btn_reset->BackColor = System::Drawing::Color::LightBlue;
				this->btn_reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btn_reset->Location = System::Drawing::Point(6, 364);
				this->btn_reset->Name = L"btn_reset";
				this->btn_reset->Size = System::Drawing::Size(103, 62);
				this->btn_reset->TabIndex = 0;
				this->btn_reset->Text = L"RESET";
				this->btn_reset->UseVisualStyleBackColor = false;
				this->btn_reset->Click += gcnew System::EventHandler(this, &form_menu::btn_reset_Click);
				// 
				// btn_upload
				// 
				this->btn_upload->BackColor = System::Drawing::Color::YellowGreen;
				this->btn_upload->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btn_upload->Location = System::Drawing::Point(12, 110);
				this->btn_upload->Name = L"btn_upload";
				this->btn_upload->Padding = System::Windows::Forms::Padding(10);
				this->btn_upload->Size = System::Drawing::Size(97, 44);
				this->btn_upload->TabIndex = 1;
				this->btn_upload->Text = L"Upload File";
				this->btn_upload->UseVisualStyleBackColor = false;
				this->btn_upload->Click += gcnew System::EventHandler(this, &form_menu::btn_upload_Click);
				// 
				// btn_display
				// 
				this->btn_display->Enabled = false;
				this->btn_display->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btn_display->Location = System::Drawing::Point(177, 214);
				this->btn_display->Name = L"btn_display";
				this->btn_display->Size = System::Drawing::Size(153, 62);
				this->btn_display->TabIndex = 4;
				this->btn_display->Text = L"Save Results";
				this->btn_display->UseVisualStyleBackColor = true;
				this->btn_display->Click += gcnew System::EventHandler(this, &form_menu::btn_display_Click);
				// 
				// btn_optimize
				// 
				this->btn_optimize->BackColor = System::Drawing::Color::MediumOrchid;
				this->btn_optimize->Enabled = false;
				this->btn_optimize->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btn_optimize->Location = System::Drawing::Point(12, 160);
				this->btn_optimize->Name = L"btn_optimize";
				this->btn_optimize->Size = System::Drawing::Size(97, 48);
				this->btn_optimize->TabIndex = 5;
				this->btn_optimize->Text = L"OPTIMIZE";
				this->btn_optimize->UseVisualStyleBackColor = false;
				this->btn_optimize->Click += gcnew System::EventHandler(this, &form_menu::btn_optimize_Click);
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
				this->label2->Location = System::Drawing::Point(14, 87);
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
				this->label3->Location = System::Drawing::Point(111, 86);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(347, 19);
				this->label3->TabIndex = 8;
				this->label3->Text = L"SELECT OBJECTIVE ERROR FUNCTIONS (OEF):";
				// 
				// cbx_oef
				// 
				this->cbx_oef->FormattingEnabled = true;
				this->cbx_oef->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
					L"Root Squared Mean Error, RMSE", L"Mean Absolute Error, MAE",
						L"Correlation Coefficient, R", L"Coefficient of determination, R2"
				});
				this->cbx_oef->Location = System::Drawing::Point(115, 108);
				this->cbx_oef->Name = L"cbx_oef";
				this->cbx_oef->Size = System::Drawing::Size(311, 21);
				this->cbx_oef->TabIndex = 9;
				this->cbx_oef->Text = L"-- SELECT OEF FUNCTION --";
				this->cbx_oef->MouseLeave += gcnew System::EventHandler(this, &form_menu::show_formula);
				this->cbx_oef->MouseHover += gcnew System::EventHandler(this, &form_menu::show_formula);
				// 
				// pic_oef
				// 
				this->pic_oef->Location = System::Drawing::Point(115, 135);
				this->pic_oef->Name = L"pic_oef";
				this->pic_oef->Size = System::Drawing::Size(186, 73);
				this->pic_oef->TabIndex = 11;
				this->pic_oef->TabStop = false;
				this->pic_oef->MouseHover += gcnew System::EventHandler(this, &form_menu::show_formula);
				// 
				// uploadFileDialog
				// 
				this->uploadFileDialog->FileName = L"Data File";
				this->uploadFileDialog->Title = L"Select Text or CSV File";
				// 
				// Log
				// 
				this->Log->Location = System::Drawing::Point(495, 53);
				this->Log->Multiline = true;
				this->Log->Name = L"Log";
				this->Log->ReadOnly = true;
				this->Log->ScrollBars = System::Windows::Forms::ScrollBars::Both;
				this->Log->Size = System::Drawing::Size(404, 373);
				this->Log->TabIndex = 13;
				// 
				// btn_predict
				// 
				this->btn_predict->BackColor = System::Drawing::Color::YellowGreen;
				this->btn_predict->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btn_predict->Location = System::Drawing::Point(330, 364);
				this->btn_predict->Name = L"btn_predict";
				this->btn_predict->Size = System::Drawing::Size(159, 61);
				this->btn_predict->TabIndex = 14;
				this->btn_predict->Text = L"Predict QC";
				this->btn_predict->UseVisualStyleBackColor = false;
				this->btn_predict->Click += gcnew System::EventHandler(this, &form_menu::btn_predict_Click);
				// 
				// form_menu
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				this->ClientSize = System::Drawing::Size(911, 438);
				this->Controls->Add(this->btn_predict);
				this->Controls->Add(this->Log);
				this->Controls->Add(this->pic_oef);
				this->Controls->Add(this->cbx_oef);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->btn_optimize);
				this->Controls->Add(this->btn_display);
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
				try
				{
					String ^path;
					//_assembly = Assembly::GetExecutingAssembly();
					if (this->cbx_oef->SelectedText == "Root Squared Mean Error, RMSE") {
						path = ".\\img\\oef_rmse.bmp";
					}
					else if (this->cbx_oef->SelectedText == "Correlation Coefficient, R") {
						path = ".\\img\\oef_coeff.bmp";
					}
					else if (this->cbx_oef->SelectedText == "Mean Absolute Error, MAE") {
						path = ".\\img\\oef_mae.bmp";
					}
					//_imageStream = _assembly->GetManifestResourceStream(path);
					//this->pic_oef->Image = gcnew Bitmap(_imageStream);
					this->pic_oef->ImageLocation = path;
				}
				catch (Exception ^ex)
				{
					MessageBox::Show(ex->Message, "Error accessing resources!");
				}
			}
			
			private: System::Void btn_upload_Click(System::Object^  sender, System::EventArgs^  e) {
	
				// Displays an OpenFileDialog so the user can select a Cursor.  
				OpenFileDialog ^openFileDialog1 = gcnew OpenFileDialog();
				openFileDialog1->Filter = "Text Files|*.txt";
				openFileDialog1->Title = "Select a Text File";

				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					string path = marshal_as<string>(openFileDialog1->FileName);
					//Read file and Initialize Drainage Area, Tank Height, P and QO Series
					read_file_init(path);
					getFromFile(this->Log);

					//Initialize Tank heights here too
					init_Heights(QO_ave);
					//
					/*this->Log->Text += "-------------" + NL;
					this->Log->Text += "Tank Height: " + TankHeight + NL;
					this->Log->Text += "YA1: " + YA1 + NL;
					this->Log->Text += "YA2: " + YA2 + NL;
					this->Log->Text += "YB1: " + YB1 + NL;
					this->Log->Text += "YC1: " + YC1 + NL;
					this->Log->Text += "YD1: " + YD1 + NL;
					this->Log->Text += "-------------" + NL;*/
		
					//Show Dialog of FilePath
					/*
					String ^managed = marshal_as<String^>(path);
					this->Log->Text += managed;
					MessageBox::Show(openFileDialog1->FileName, "Path:");
					*/

					//Show Dialog of A,TA,P,QO
					MessageBox::Show("File Read", "Success");
					btn_optimize->Enabled = true;
				}

			}
			
			private: System::Void btn_optimize_Click(System::Object^  sender, System::EventArgs^  e) {
				//VALIDATIONS || Check if EOF is chosen
				if (this->cbx_oef->Text == "Root Squared Mean Error, RMSE") {
					method = 1;
				} else if (this->cbx_oef->Text == "Correlation Coefficient, R") {
					method = 2;
				} else if (this->cbx_oef->Text == "Mean Absolute Error, MAE") {
					method = 3;
				} else if (this->cbx_oef->Text == "Coefficient of determination, R2") {
					method = 4;
				}
				else {
					MessageBox::Show("Please Select OEF", "Error:");
					return;
				}
				//Check if text file is chosen
				if (vPrecipitation.empty()) {
					MessageBox::Show("Please text file", "Error:");
					return; }
				//---

				this->Log->Text += "-------------" + NL;
				this->Log->Text += "Tank Height: " + TankHeight + NL;
				this->Log->Text += "YA1: " + YA1 + NL;
				this->Log->Text += "YA2: " + YA2 + NL;
				this->Log->Text += "YB1: " + YB1 + NL;
				this->Log->Text += "YC1: " + YC1 + NL;
				this->Log->Text += "YD1: " + YD1 + NL;
				this->Log->Text += "-------------" + NL;
				compute(this->Log);
				switch(method) {
					case 1:
						OEFv = RMSE(vQCalculated, vQObserved);
						this->Log->Text += "OEF | RMSE: " + OEFv;
						break;
					case 2:
						OEFv = COEFFCORREL(vQCalculated, vQObserved);
						this->Log->Text += "OEF | R: " + OEFv;
						break;
					case 3:
						OEFv = MAE(vQCalculated, vQObserved);
						this->Log->Text += "OEF | MAE: " + OEFv;
						break;
					case 4:
						OEFv = R2(vQCalculated, vQObserved);
						this->Log->Text += "OEF | R2: " + OEFv;
						break;
				}
				btn_display->Enabled = true;
			}

			private: System::Void btn_display_Click(System::Object^  sender, System::EventArgs^  e) {
				if (save_file(method)) {
					MessageBox::Show("File Saved: Model.txt", "Success!");
				}
				else {
					MessageBox::Show("Unable to Save File!", "Error!");
				}
			}

			private: System::Void btn_reset_Click(System::Object^  sender, System::EventArgs^  e) {
				String ^managed;
				resetValues();
				if (vPrecipitation.empty()) {
					this->Log->Text = "";
					MessageBox::Show("Values Cleared", "Success:");
					btn_optimize->Enabled = false;
					btn_optimize->Enabled = false;
				}
				else {
					MessageBox::Show("Can't Clear Values", "Error:");
				}
			}
			
			private: System::Void btn_predict_Click(System::Object^  sender, System::EventArgs^  e) {
				// Displays an OpenFileDialog so the user can select a Cursor.  
				OpenFileDialog ^openFileDialog1 = gcnew OpenFileDialog();
				openFileDialog1->Filter = "Text Files|*.txt";
				openFileDialog1->Title = "Select a Text File with Tank Configuration";

				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					string path = marshal_as<string>(openFileDialog1->FileName);
					//Read file and Initialize Drainage Area, Tank Height, P and QO Series
					
					file_tank_config(path);
					//getFromFile(this->Log);
					this->Log->Text = "---Predicting Rainfall---\r\n";
					this->Log->Text += "Tank Height: " + TankHeight + NL;
					this->Log->Text += "YA1: " + YA1 + NL;
					this->Log->Text += "YA2: " + YA2 + NL;
					this->Log->Text += "YB1: " + YB1 + NL;
					this->Log->Text += "YC1: " + YC1 + NL;
					this->Log->Text += "YD1: " + YD1 + NL;
					
					//Open Precipitation Files
					openFileDialog1->Filter = "Text Files|*.txt";
					openFileDialog1->Title = "Select a Text File with Precipitations";
					if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

						string path = marshal_as<string>(openFileDialog1->FileName);
						read_prec(path);

						//this->Log->Text += "Precipitations:" + NL;

						//Clear QC
						vQCalculated.clear();
						for each (double prec in vPrecipitation) {
							vQCalculated.push_back(predictQC(prec));
							//this->Log->Text += NL;
						}

						this->Log->Text += "-------------" + NL;
						this->Log->Text += "Precipitation \t QCs" + NL;
						for (int i = 0; i < vQCalculated.size(); i++) {
							this->Log->Text += vPrecipitation.at(i)
								+ "\t" + vQCalculated.at(i) + NL;
						}

						MessageBox::Show("File Read", "Success Predict");
					}
					
				}
			}
	};
}

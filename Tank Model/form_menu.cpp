#include "form_menu.h"

//Use Forms and UI functions
using namespace System;
using namespace System::Windows::Forms;



/*
Set Linker
SubSystem = Windows
Entry Point = Main
*/
[STAThread]
void Main(cli::array<String^>^ args)
{
	//Set Application Settings
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Make an object of the Form
	TankModel::form_menu form;

	//Run a form in the Main thread
	Application::Run(%form);

	
}

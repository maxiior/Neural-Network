#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NeuralNetworkProject::MenuForm formularz;
	Application::Run(%formularz);
	return 0;
}

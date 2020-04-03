#include "MyForm.h"





[STAThreadAttribute]
void Main(array<String^>^ args) {



	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyTool::MyForm form;
	Application::Run(%form);
}


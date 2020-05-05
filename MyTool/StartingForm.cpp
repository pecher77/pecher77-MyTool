#include "StartingForm.h"




[STAThreadAttribute]
void Main(array<String^>^ args) {



	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyTool::StartingForm form;
	Application::Run(%form);
}


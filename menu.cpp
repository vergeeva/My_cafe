#include "menu.h"
using namespace Mycafe; // ��� �������.
[STAThreadAttribute]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew menu()); // ��� �����.
	return 0;
}


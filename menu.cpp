#include "menu.h"
using namespace Mycafe; // Имя проекта.
[STAThreadAttribute]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew menu()); // Имя формы.
	return 0;
}


#include "MyForm.h"
#include <filesystem>

using namespace System;
using namespace System::Windows::Forms;
//using std::cout; using std::cin;
//using std::endl; using std::string;
//using std::filesystem::recursive_directory_iterator;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Thread::MyForm form;
	Application::Run(% form);
}




#include "MyForm.h"

//public delegate System::Void play_music();

//[STAThreadAttribute]
int
main(array<System::String^>^ args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	TypingNoviceLive::MyForm^ inst = gcnew TypingNoviceLive::MyForm();

	/*play_music^ static_play_music = gcnew play_music(inst, &TypingNoviceLive::MyForm::play_music);
	System::Threading::Thread^ back_music = gcnew System::Threading::Thread(static_play_music);*/

	System::Windows::Forms::Application::Run(inst);

	return 0;
}
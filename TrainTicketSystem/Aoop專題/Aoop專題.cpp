// Aoop�M�D.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include "selling_form.h"
#include "Train_system.h"
#include "Form1.h"

//Train_system A;
using namespace Aoop�M�D;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �إߥD�����ð���
	Application::Run(gcnew Form1());
	
	return 0;
}

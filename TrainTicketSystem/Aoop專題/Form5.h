#pragma once
#include "Form6.h"
#include "Form7.h"

namespace Aoop�M�D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form5 ���K�n
	/// </summary>
	public ref class Form5 : public System::Windows::Forms::Form
	{
	public:
		Form5(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
			
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  trainbutton;
	protected: 
	private: System::Windows::Forms::Button^  salarybutton;

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->trainbutton = (gcnew System::Windows::Forms::Button());
			this->salarybutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// trainbutton
			// 
			this->trainbutton->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->trainbutton->Location = System::Drawing::Point(100, 75);
			this->trainbutton->Name = L"trainbutton";
			this->trainbutton->Size = System::Drawing::Size(168, 63);
			this->trainbutton->TabIndex = 0;
			this->trainbutton->Text = L"�W�[�C��";
			this->trainbutton->UseVisualStyleBackColor = true;
			this->trainbutton->Click += gcnew System::EventHandler(this, &Form5::trainbutton_Click);
			// 
			// salarybutton
			// 
			this->salarybutton->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->salarybutton->Location = System::Drawing::Point(100, 180);
			this->salarybutton->Name = L"salarybutton";
			this->salarybutton->Size = System::Drawing::Size(168, 71);
			this->salarybutton->TabIndex = 1;
			this->salarybutton->Text = L"���t�~��";
			this->salarybutton->UseVisualStyleBackColor = true;
			this->salarybutton->Click += gcnew System::EventHandler(this, &Form5::salarybutton_Click);
			// 
			// Form5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(357, 345);
			this->Controls->Add(this->salarybutton);
			this->Controls->Add(this->trainbutton);
			this->Name = L"Form5";
			this->Text = L"�Ҧ����";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void trainbutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Form7 ^frm = gcnew Form7();
				 frm->Enabled=true;
				 frm->Visible=true;
			 }
	private: System::Void salarybutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Form6 ^frm = gcnew Form6();
				 frm->Enabled=true;
				 frm->Visible=true;
			 }
	};
}

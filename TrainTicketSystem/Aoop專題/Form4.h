#pragma once
#include "Form5.h"

namespace Aoop�M�D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form4 ���K�n
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:
		Form4(void)
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
		~Form4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  accountbox;
	private: System::Windows::Forms::TextBox^  passwordbox;


	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  errorlabel;

	private: System::Windows::Forms::Button^  surebutton;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->accountbox = (gcnew System::Windows::Forms::TextBox());
			this->passwordbox = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->errorlabel = (gcnew System::Windows::Forms::Label());
			this->surebutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�з���", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(151, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�п�J�b���K�X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(98, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 28);
			this->label2->TabIndex = 1;
			this->label2->Text = L"�b��";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(98, 193);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 28);
			this->label3->TabIndex = 2;
			this->label3->Text = L"�K�X";
			// 
			// accountbox
			// 
			this->accountbox->Location = System::Drawing::Point(188, 140);
			this->accountbox->Name = L"accountbox";
			this->accountbox->Size = System::Drawing::Size(193, 25);
			this->accountbox->TabIndex = 3;
			// 
			// passwordbox
			// 
			this->passwordbox->Location = System::Drawing::Point(188, 195);
			this->passwordbox->Name = L"passwordbox";
			this->passwordbox->PasswordChar = '*';
			this->passwordbox->Size = System::Drawing::Size(193, 25);
			this->passwordbox->TabIndex = 4;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->checkBox1->Location = System::Drawing::Point(188, 255);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(115, 23);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"�O��K�X";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form4::checkBox1_CheckedChanged);
			// 
			// errorlabel
			// 
			this->errorlabel->AutoSize = true;
			this->errorlabel->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->errorlabel->ForeColor = System::Drawing::Color::Red;
			this->errorlabel->Location = System::Drawing::Point(124, 292);
			this->errorlabel->Name = L"errorlabel";
			this->errorlabel->Size = System::Drawing::Size(288, 28);
			this->errorlabel->TabIndex = 6;
			this->errorlabel->Text = L"��J���~ �Э��s��J";
			this->errorlabel->Visible = false;
			// 
			// surebutton
			// 
			this->surebutton->Font = (gcnew System::Drawing::Font(L"�з���", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->surebutton->Location = System::Drawing::Point(415, 161);
			this->surebutton->Name = L"surebutton";
			this->surebutton->Size = System::Drawing::Size(75, 37);
			this->surebutton->TabIndex = 7;
			this->surebutton->Text = L"�n�J";
			this->surebutton->UseVisualStyleBackColor = true;
			this->surebutton->Click += gcnew System::EventHandler(this, &Form4::surebutton_Click);
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(533, 381);
			this->Controls->Add(this->surebutton);
			this->Controls->Add(this->errorlabel);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->passwordbox);
			this->Controls->Add(this->accountbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form4";
			this->Text = L"�޲z�Ҧ�";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void surebutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if((accountbox->Text!="123456789")||(passwordbox->Text!="123456789"))
				 {
					 errorlabel->Visible=true;
				 }
				 else
				 {
					 Form5 ^frm = gcnew Form5();
					 this->Enabled=false;
					 this->Visible=false;
					 frm->Enabled=true;
					 frm->Visible=true;
				 }
			 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 passwordbox->Text = "123456789";
		 }
};
}

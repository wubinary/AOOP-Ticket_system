#pragma once

namespace Aoop�M�D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// selling_form ���K�n
	/// </summary>
	public ref class selling_form : public System::Windows::Forms::Form
	{
	public:
		selling_form()
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
		~selling_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_test;
	protected: 

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
			this->button_test = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_test
			// 
			this->button_test->Location = System::Drawing::Point(74, 85);
			this->button_test->Name = L"button_test";
			this->button_test->Size = System::Drawing::Size(145, 64);
			this->button_test->TabIndex = 0;
			this->button_test->Text = L"button_test";
			this->button_test->UseVisualStyleBackColor = true;
			this->button_test->Click += gcnew System::EventHandler(this, &selling_form::button_test_Click);
			// 
			// selling_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 435);
			this->Controls->Add(this->button_test);
			this->Name = L"selling_form";
			this->Text = L"selling_form";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_test_Click(System::Object^  sender, System::EventArgs^  e) {
				
			 }
	};
}

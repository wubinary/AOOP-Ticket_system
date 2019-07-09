#pragma once
#include "Form6.h"
#include "Form7.h"

namespace Aoop專題 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form5 的摘要
	/// </summary>
	public ref class Form5 : public System::Windows::Forms::Form
	{
	public:
		Form5(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->trainbutton = (gcnew System::Windows::Forms::Button());
			this->salarybutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// trainbutton
			// 
			this->trainbutton->Font = (gcnew System::Drawing::Font(L"標楷體", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->trainbutton->Location = System::Drawing::Point(100, 75);
			this->trainbutton->Name = L"trainbutton";
			this->trainbutton->Size = System::Drawing::Size(168, 63);
			this->trainbutton->TabIndex = 0;
			this->trainbutton->Text = L"增加列車";
			this->trainbutton->UseVisualStyleBackColor = true;
			this->trainbutton->Click += gcnew System::EventHandler(this, &Form5::trainbutton_Click);
			// 
			// salarybutton
			// 
			this->salarybutton->Font = (gcnew System::Drawing::Font(L"標楷體", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->salarybutton->Location = System::Drawing::Point(100, 180);
			this->salarybutton->Name = L"salarybutton";
			this->salarybutton->Size = System::Drawing::Size(168, 71);
			this->salarybutton->TabIndex = 1;
			this->salarybutton->Text = L"分配薪水";
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
			this->Text = L"模式選擇";
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

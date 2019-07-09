#pragma once
#include "Train_system.h"
namespace Aoop�M�D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form3_show_ticket ���K�n
	/// </summary>
	public ref class Form3_show_ticket : public System::Windows::Forms::Form
	{
	public:
		Train_system *train_system;

		Form3_show_ticket(Train_system *ts,String ^ti,int a,int b,String ^t0,String ^t1,String ^mm)
		{
			//Form3_show_ticket form = gcnew Form3_show_ticket(train_system,train_index,aa,bb,str_time0,str_time1,str_money);
			train_system = ts;
			label1_day->Text = Convert::ToString(train_system->tmp_year)+"/"+Convert::ToString(train_system->tmp_month)+"/"+Convert::ToString(train_system->tmp_day);
			label1_time0->Text = Convert::ToString(t0);
			label1_time1->Text = Convert::ToString(t1);
			label1_train_num->Text = Convert::ToString(ti);
			label1_money->Text = Convert::ToString(mm);
			if(a==0)
			{
				label1_departure_place->Text = "�x�_";
			}
			else if(a==1)
			{
				label1_departure_place->Text = "�O��";
			}
			else if(a==2)
			{
				label1_departure_place->Text = "���";
			}
			else if(a==3)
			{
				label1_departure_place->Text = "�s��";
			}
			else if(a==4)
			{
				label1_departure_place->Text = "�x��";
			}
			else if(a==5)
			{
				label1_departure_place->Text = "�x�n";
			}
			else if(a==6)
			{
				label1_departure_place->Text = "����";
			}


			if(b=0)
			{
				label1_arrive_place->Text = "�x�_";
			}
			else if(b=1)
			{
				label1_arrive_place->Text = "�O��";
			}
			else if(b=2)
			{
				label1_arrive_place->Text = "���";
			}
			else if(b=3)
			{
				label1_arrive_place->Text = "�s��";
			}
			else if(b=4)
			{
				label1_arrive_place->Text = "�x��";
			}
			else if(b=5)
			{
				label1_arrive_place->Text = "�x�n";
			}
			else if(b=6)
			{
				label1_arrive_place->Text = "����";
			}
			
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form3_show_ticket()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1_day;
	protected: 
	private: System::Windows::Forms::Label^  label1_train_num;
	private: System::Windows::Forms::Label^  label1_departure_place;
	private: System::Windows::Forms::Label^  label1_arrive_place;
	private: System::Windows::Forms::Label^  label1_time0;
	private: System::Windows::Forms::Label^  label1_time1;
	private: System::Windows::Forms::Label^  label1_money;

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
			this->label1_day = (gcnew System::Windows::Forms::Label());
			this->label1_train_num = (gcnew System::Windows::Forms::Label());
			this->label1_departure_place = (gcnew System::Windows::Forms::Label());
			this->label1_arrive_place = (gcnew System::Windows::Forms::Label());
			this->label1_time0 = (gcnew System::Windows::Forms::Label());
			this->label1_time1 = (gcnew System::Windows::Forms::Label());
			this->label1_money = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1_day
			// 
			this->label1_day->AutoSize = true;
			this->label1_day->Location = System::Drawing::Point(32, 37);
			this->label1_day->Name = L"label1_day";
			this->label1_day->Size = System::Drawing::Size(33, 12);
			this->label1_day->TabIndex = 0;
			this->label1_day->Text = L"label1";
			// 
			// label1_train_num
			// 
			this->label1_train_num->AutoSize = true;
			this->label1_train_num->Location = System::Drawing::Point(213, 37);
			this->label1_train_num->Name = L"label1_train_num";
			this->label1_train_num->Size = System::Drawing::Size(33, 12);
			this->label1_train_num->TabIndex = 1;
			this->label1_train_num->Text = L"label1";
			// 
			// label1_departure_place
			// 
			this->label1_departure_place->AutoSize = true;
			this->label1_departure_place->Location = System::Drawing::Point(34, 76);
			this->label1_departure_place->Name = L"label1_departure_place";
			this->label1_departure_place->Size = System::Drawing::Size(33, 12);
			this->label1_departure_place->TabIndex = 2;
			this->label1_departure_place->Text = L"label1";
			// 
			// label1_arrive_place
			// 
			this->label1_arrive_place->AutoSize = true;
			this->label1_arrive_place->Location = System::Drawing::Point(215, 75);
			this->label1_arrive_place->Name = L"label1_arrive_place";
			this->label1_arrive_place->Size = System::Drawing::Size(33, 12);
			this->label1_arrive_place->TabIndex = 3;
			this->label1_arrive_place->Text = L"label1";
			// 
			// label1_time0
			// 
			this->label1_time0->AutoSize = true;
			this->label1_time0->Location = System::Drawing::Point(36, 112);
			this->label1_time0->Name = L"label1_time0";
			this->label1_time0->Size = System::Drawing::Size(33, 12);
			this->label1_time0->TabIndex = 4;
			this->label1_time0->Text = L"label1";
			// 
			// label1_time1
			// 
			this->label1_time1->AutoSize = true;
			this->label1_time1->Location = System::Drawing::Point(217, 111);
			this->label1_time1->Name = L"label1_time1";
			this->label1_time1->Size = System::Drawing::Size(33, 12);
			this->label1_time1->TabIndex = 5;
			this->label1_time1->Text = L"label1";
			// 
			// label1_money
			// 
			this->label1_money->AutoSize = true;
			this->label1_money->Location = System::Drawing::Point(57, 156);
			this->label1_money->Name = L"label1_money";
			this->label1_money->Size = System::Drawing::Size(33, 12);
			this->label1_money->TabIndex = 6;
			this->label1_money->Text = L"label1";
			// 
			// Form3_show_ticket
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(491, 236);
			this->Controls->Add(this->label1_money);
			this->Controls->Add(this->label1_time1);
			this->Controls->Add(this->label1_time0);
			this->Controls->Add(this->label1_arrive_place);
			this->Controls->Add(this->label1_departure_place);
			this->Controls->Add(this->label1_train_num);
			this->Controls->Add(this->label1_day);
			this->Name = L"Form3_show_ticket";
			this->Text = L"Form3_show_ticket";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

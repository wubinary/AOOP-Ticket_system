#pragma once
#include"Train_system.h"

namespace Aoop�M�D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace std;

	/// <summary>
	/// Form6 ���K�n
	/// </summary>
	public ref class Form6 : public System::Windows::Forms::Form
	{
	public:
		Form6(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
			server="localhost";
			userID="root";
			password="1234567890";
			connectstr = "Network Address="+server+";"+"Persist Security Info=no;"+"User Name="+userID+";"+"Password="+password+";";
			connect = gcnew MySqlConnection( connectstr );

			connect->Open();	
			strSQL = "use project;"; //MySQL command you want to use
			cmd = gcnew MySqlCommand( strSQL , connect );	
			reader = cmd->ExecuteReader();
			connect->Close();
			delete cmd;

			connect->Open();
			strSQL = "select * from ���u�~���� ;"; //MySQL command you want to use
			cmd = gcnew MySqlCommand( strSQL , connect );	
			reader = cmd->ExecuteReader();

			while(reader->Read())
			{
				String ^str0 = reader->GetString(1)+"�@";
				String ^str1 = reader->GetString(2)+"�@";
				String ^str2 = reader->GetString(3)+"  ";
				dataGridView1->Rows->Add(str0,str1,str2);
			}
			connect->Close();
			delete cmd;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ���u�m�W;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ¾��;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ���~;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  NamecomboBox;

	private: System::Windows::Forms::ComboBox^  workcomboBox;
	private: System::Windows::Forms::TextBox^  SalaryBox;
	private: System::Windows::Forms::Button^  Surebutton;



	protected: 

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;
		/* MySQL�s�����B���O�ǰe�B���Ū�� */
		MySqlConnection ^connect,^connect2; 
		MySqlCommand ^cmd,^cmd2;     
		MySqlDataReader ^reader,^reader2; 
		/* Used to input the MySQL message */
		String ^strSQL;
		String ^connectstr;  
		String ^server;  
		String ^userID;
		 String ^password;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->���u�m�W = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->¾�� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->���~ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->NamecomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->workcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SalaryBox = (gcnew System::Windows::Forms::TextBox());
			this->Surebutton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->���u�m�W, this->¾��, 
				this->���~});
			this->dataGridView1->Location = System::Drawing::Point(107, 292);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->Size = System::Drawing::Size(433, 168);
			this->dataGridView1->TabIndex = 0;
			// 
			// ���u�m�W
			// 
			this->���u�m�W->HeaderText = L"���u�m�W";
			this->���u�m�W->Name = L"���u�m�W";
			// 
			// ¾��
			// 
			this->¾��->HeaderText = L"¾��";
			this->¾��->Name = L"¾��";
			// 
			// ���~
			// 
			this->���~->HeaderText = L"���~";
			this->���~->Name = L"���~";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(26, 230);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"�{�����u/�~��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(26, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"���t�~��";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(79, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"���u�m�W";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(289, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"¾��";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(479, 79);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 20);
			this->label5->TabIndex = 5;
			this->label5->Text = L"�~��(���~)";
			// 
			// NamecomboBox
			// 
			this->NamecomboBox->FormattingEnabled = true;
			this->NamecomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"���|��", L"�i�p��", L"���p��", L"�L����", L"������", L"�L���w", 
				L"���W��", L"�\�o�a", L"������", L"�j�V��"});
			this->NamecomboBox->Location = System::Drawing::Point(59, 119);
			this->NamecomboBox->Name = L"NamecomboBox";
			this->NamecomboBox->Size = System::Drawing::Size(133, 23);
			this->NamecomboBox->TabIndex = 6;
			this->NamecomboBox->Text = L"�п�ܩm�W";
			// 
			// workcomboBox
			// 
			this->workcomboBox->FormattingEnabled = true;
			this->workcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"�g�z", L"����", L"���ȭ�", L"���ȤH��", L"�M��u"});
			this->workcomboBox->Location = System::Drawing::Point(247, 119);
			this->workcomboBox->Name = L"workcomboBox";
			this->workcomboBox->Size = System::Drawing::Size(140, 23);
			this->workcomboBox->TabIndex = 7;
			this->workcomboBox->Text = L"�п��¾��";
			// 
			// SalaryBox
			// 
			this->SalaryBox->Location = System::Drawing::Point(483, 119);
			this->SalaryBox->Name = L"SalaryBox";
			this->SalaryBox->Size = System::Drawing::Size(100, 25);
			this->SalaryBox->TabIndex = 8;
			// 
			// Surebutton
			// 
			this->Surebutton->Font = (gcnew System::Drawing::Font(L"�з���", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Surebutton->Location = System::Drawing::Point(247, 173);
			this->Surebutton->Name = L"Surebutton";
			this->Surebutton->Size = System::Drawing::Size(158, 34);
			this->Surebutton->TabIndex = 9;
			this->Surebutton->Text = L"�T�w�ܧ�";
			this->Surebutton->UseVisualStyleBackColor = true;
			this->Surebutton->Click += gcnew System::EventHandler(this, &Form6::Surebutton_Click);
			// 
			// Form6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 499);
			this->Controls->Add(this->Surebutton);
			this->Controls->Add(this->SalaryBox);
			this->Controls->Add(this->workcomboBox);
			this->Controls->Add(this->NamecomboBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form6";
			this->Text = L"���t�~��";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Surebutton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 String ^name = NamecomboBox->Text;
				 String ^employee = workcomboBox->Text;
				 String ^salary = SalaryBox->Text;
				 connect->Open();
				 strSQL = "update ���u�~���� set ¾��="+"\'"+employee+"\',"+"���~="+"\'"+salary+"\'"+"where ���u�m�W="+"\'"+name+"\'"+";"; //MySQL command you want to use
				 cmd = gcnew MySqlCommand( strSQL , connect );	
				 reader = cmd->ExecuteReader();
				 connect->Close();
				 delete cmd;
			 }
};
}

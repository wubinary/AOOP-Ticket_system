#pragma once
#include"Train_system.h"

namespace Aoop專題 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace std;

	/// <summary>
	/// Form6 的摘要
	/// </summary>
	public ref class Form6 : public System::Windows::Forms::Form
	{
	public:
		Form6(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
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
			strSQL = "select * from 員工薪水表 ;"; //MySQL command you want to use
			cmd = gcnew MySqlCommand( strSQL , connect );	
			reader = cmd->ExecuteReader();

			while(reader->Read())
			{
				String ^str0 = reader->GetString(1)+"　";
				String ^str1 = reader->GetString(2)+"　";
				String ^str2 = reader->GetString(3)+"  ";
				dataGridView1->Rows->Add(str0,str1,str2);
			}
			connect->Close();
			delete cmd;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  員工姓名;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  職位;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  月薪;
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
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		/* MySQL連接器、指令傳送、資料讀取 */
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
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->員工姓名 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->職位 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->月薪 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->員工姓名, this->職位, 
				this->月薪});
			this->dataGridView1->Location = System::Drawing::Point(107, 292);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->Size = System::Drawing::Size(433, 168);
			this->dataGridView1->TabIndex = 0;
			// 
			// 員工姓名
			// 
			this->員工姓名->HeaderText = L"員工姓名";
			this->員工姓名->Name = L"員工姓名";
			// 
			// 職位
			// 
			this->職位->HeaderText = L"職位";
			this->職位->Name = L"職位";
			// 
			// 月薪
			// 
			this->月薪->HeaderText = L"月薪";
			this->月薪->Name = L"月薪";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"標楷體", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(26, 230);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"現有員工/薪水";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"標楷體", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(26, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"分配薪水";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"標楷體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(79, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"員工姓名";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"標楷體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(289, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"職位";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"標楷體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(479, 79);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 20);
			this->label5->TabIndex = 5;
			this->label5->Text = L"薪水(月薪)";
			// 
			// NamecomboBox
			// 
			this->NamecomboBox->FormattingEnabled = true;
			this->NamecomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"李尚恩", L"張小翔", L"陳小銓", L"林阿牛", L"蔡市場", L"林阿德", 
				L"中鋒睿", L"許廢軒", L"挖哩勒", L"大丈夫"});
			this->NamecomboBox->Location = System::Drawing::Point(59, 119);
			this->NamecomboBox->Name = L"NamecomboBox";
			this->NamecomboBox->Size = System::Drawing::Size(133, 23);
			this->NamecomboBox->TabIndex = 6;
			this->NamecomboBox->Text = L"請選擇姓名";
			// 
			// workcomboBox
			// 
			this->workcomboBox->FormattingEnabled = true;
			this->workcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"經理", L"車長", L"乘務員", L"站務人員", L"清潔工"});
			this->workcomboBox->Location = System::Drawing::Point(247, 119);
			this->workcomboBox->Name = L"workcomboBox";
			this->workcomboBox->Size = System::Drawing::Size(140, 23);
			this->workcomboBox->TabIndex = 7;
			this->workcomboBox->Text = L"請選擇職稱";
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
			this->Surebutton->Font = (gcnew System::Drawing::Font(L"標楷體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Surebutton->Location = System::Drawing::Point(247, 173);
			this->Surebutton->Name = L"Surebutton";
			this->Surebutton->Size = System::Drawing::Size(158, 34);
			this->Surebutton->TabIndex = 9;
			this->Surebutton->Text = L"確定變更";
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
			this->Text = L"分配薪水";
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
				 strSQL = "update 員工薪水表 set 職位="+"\'"+employee+"\',"+"月薪="+"\'"+salary+"\'"+"where 員工姓名="+"\'"+name+"\'"+";"; //MySQL command you want to use
				 cmd = gcnew MySqlCommand( strSQL , connect );	
				 reader = cmd->ExecuteReader();
				 connect->Close();
				 delete cmd;
			 }
};
}

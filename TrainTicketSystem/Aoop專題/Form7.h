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
	/// Form7 ���K�n
	/// </summary>
	public ref class Form7 : public System::Windows::Forms::Form
	{
	public:
		Form7(void)
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
			strSQL = "select * from �C���d�ߪ� ;"; //MySQL command you want to use
			cmd = gcnew MySqlCommand( strSQL , connect );	
			reader = cmd->ExecuteReader();

			while(reader->Read())
			{
				String ^str0 = reader->GetString(1)+"�@";
				String ^str1 = reader->GetString(2)+"�@";
				String ^str2 = reader->GetString(3)+"  ";
				String ^str3 = reader->GetString(4)+"�@";
				String ^str4 = reader->GetString(5)+"�@";
				String^	str8 = reader->GetString(14)+"�@";
				dataGridView1->Rows->Add(str0,str1,str2,str3,str4,str8);

			}
			connect->Close();
			delete cmd;
		
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form7()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  traincomboBox;
	private: System::Windows::Forms::TextBox^  numberBox;


	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  startBox;
	private: System::Windows::Forms::ComboBox^  arriveBox;
	private: System::Windows::Forms::TextBox^  priceBox;




	private: System::Windows::Forms::Label^  label9;






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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ���;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �_��;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ���I��;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ����;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::TextBox^  timeBox;







			 String ^password;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->��� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�_�� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->���I�� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->traincomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->numberBox = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->startBox = (gcnew System::Windows::Forms::ComboBox());
			this->arriveBox = (gcnew System::Windows::Forms::ComboBox());
			this->priceBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timeBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->����, this->����, 
				this->���, this->�_��, this->���I��, this->����});
			this->dataGridView1->Location = System::Drawing::Point(37, 277);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->Size = System::Drawing::Size(812, 290);
			this->dataGridView1->TabIndex = 0;
			// 
			// ����
			// 
			this->����->HeaderText = L"����";
			this->����->Name = L"����";
			// 
			// ����
			// 
			this->����->HeaderText = L"����";
			this->����->Name = L"����";
			// 
			// ���
			// 
			this->���->HeaderText = L"���";
			this->���->Name = L"���";
			// 
			// �_��
			// 
			this->�_��->HeaderText = L"�_��";
			this->�_��->Name = L"�_��";
			// 
			// ���I��
			// 
			this->���I��->HeaderText = L"���I��";
			this->���I��->Name = L"���I��";
			// 
			// ����
			// 
			this->����->HeaderText = L"����";
			this->����->Name = L"����";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"���W�[�Z��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(52, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"����";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(52, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 19);
			this->label3->TabIndex = 3;
			this->label3->Text = L"����";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(52, 177);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 19);
			this->label4->TabIndex = 4;
			this->label4->Text = L"���";
			// 
			// traincomboBox
			// 
			this->traincomboBox->FormattingEnabled = true;
			this->traincomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"��", L"�C"});
			this->traincomboBox->Location = System::Drawing::Point(109, 85);
			this->traincomboBox->Name = L"traincomboBox";
			this->traincomboBox->Size = System::Drawing::Size(97, 23);
			this->traincomboBox->TabIndex = 5;
			this->traincomboBox->Text = L"�п�ܨ���";
			// 
			// numberBox
			// 
			this->numberBox->Location = System::Drawing::Point(109, 130);
			this->numberBox->Name = L"numberBox";
			this->numberBox->Size = System::Drawing::Size(100, 25);
			this->numberBox->TabIndex = 6;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(109, 170);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 25);
			this->dateTimePicker1->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(357, 86);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 19);
			this->label5->TabIndex = 8;
			this->label5->Text = L"�_��";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(563, 85);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 19);
			this->label6->TabIndex = 9;
			this->label6->Text = L"���I��";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(357, 150);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 19);
			this->label8->TabIndex = 11;
			this->label8->Text = L"����";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(508, 195);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 35);
			this->button1->TabIndex = 12;
			this->button1->Text = L"�T�w�s�W";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form7::button1_Click);
			// 
			// startBox
			// 
			this->startBox->FormattingEnabled = true;
			this->startBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"�x�_", L"�O��", L"���", L"�s��", L"�x��", L"�Ÿq", L"�x�n", 
				L"����"});
			this->startBox->Location = System::Drawing::Point(417, 84);
			this->startBox->Name = L"startBox";
			this->startBox->Size = System::Drawing::Size(121, 23);
			this->startBox->TabIndex = 13;
			this->startBox->Text = L"�п�ܯ��W";
			// 
			// arriveBox
			// 
			this->arriveBox->FormattingEnabled = true;
			this->arriveBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"�x�_", L"�O��", L"���", L"�s��", L"�x��", L"�Ÿq", L"�x�n", 
				L"����"});
			this->arriveBox->Location = System::Drawing::Point(641, 84);
			this->arriveBox->Name = L"arriveBox";
			this->arriveBox->Size = System::Drawing::Size(121, 23);
			this->arriveBox->TabIndex = 14;
			this->arriveBox->Text = L"�п�ܯ��W";
			// 
			// priceBox
			// 
			this->priceBox->Location = System::Drawing::Point(417, 144);
			this->priceBox->Name = L"priceBox";
			this->priceBox->Size = System::Drawing::Size(100, 25);
			this->priceBox->TabIndex = 16;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"�з���", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(12, 232);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(128, 28);
			this->label9->TabIndex = 17;
			this->label9->Text = L"�{���Z��";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(563, 144);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 20);
			this->label7->TabIndex = 18;
			this->label7->Text = L"�X�o�ɶ�";
			// 
			// timeBox
			// 
			this->timeBox->Location = System::Drawing::Point(663, 138);
			this->timeBox->Name = L"timeBox";
			this->timeBox->Size = System::Drawing::Size(100, 25);
			this->timeBox->TabIndex = 19;
			// 
			// Form7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 579);
			this->Controls->Add(this->timeBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->priceBox);
			this->Controls->Add(this->arriveBox);
			this->Controls->Add(this->startBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->numberBox);
			this->Controls->Add(this->traincomboBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form7";
			this->Text = L"�W�[�C��";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void MarshalString ( String ^ s, string& os ) 
			 {
				 using namespace Runtime::InteropServices;
				 const char* chars = 
					 (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 int x,y;
				 
				 String ^str0 = "\'"+traincomboBox->Text+"\'";
				 String ^str1 = "\'"+numberBox->Text+"\'";
				 String ^str2 = "\'"+dateTimePicker1->Text+"\'";
				 String ^str3 = "\'"+startBox->Text+"\'";
				 String ^str4 =	"\'"+arriveBox->Text+"\'";
				 String ^str5 = "\'"+priceBox->Text+"\'";
				 String ^str6 = timeBox->Text;
				 //int r = Convert::ToInt32(str6[5]+str6[6]);
				 connect->Open();
				 strSQL = "insert into �C���d�ߪ�(����,����,���,�_��,���I��,�x�_,�O��,���,�s��,�x��,�Ÿq,�x�n,����,����)values("+str0+","+str1+","+str2+","+str3+","+str4+","; //MySQL command you want to use
					 if(str3=="\'�x�_\'")
						 x=0;
					 else if(str3=="\'�O��\'")
						 x=1;
					 else if(str3=="\'���\'")
						 x=2;
					 else if(str3=="\'�s��\'")
						 x=3;
					 else if(str3=="\'�x��\'")
						 x=4;
					 else if(str3=="\'�Ÿq\'")
						 x=5;
					 else if(str3=="\'�x�n\'")
						 x=6;
					 else if(str3=="\'����\'")
						 x=7;

					 if(str4=="\'�x�_\'")
						 y=0;
					 else if(str4=="\'�O��\'")
						 y=1;
					 else if(str4=="\'���\'")
						 y=2;
					 else if(str4=="\'�s��\'")
						 y=3;
					 else if(str4=="\'�x��\'")
						 y=4;
					 else if(str4=="\'�Ÿq\'")
						 y=5;
					 else if(str4=="\'�x�n\'")
						 y=6;
					 else if(str4=="\'����\'")
						 y=7;
			
				 
				 for(int i=0;i<8;i++)
				 {
					 for(int j=1;j<8;j++)
					 {
						 if(x==i&&y==j)
						 {
							 for(int a=0;a<i;a++)
							 {
								 strSQL+="\'X\',";
							 }
							 for(int a=0;a<(j-i+1);a++)
							 {
								 strSQL+="\'"+str6+"\',";
								 if(str0=="\'��\'")
								 {
									 if(Convert::ToInt32(str6->Substring(3,2))+15<60)
										 str6 = str6->Substring(0,3)+Convert::ToString(Convert::ToInt32(str6->Substring(3,2))+15);
									 else if(Convert::ToInt32(str6->Substring(3,2))+15>=60&&Convert::ToInt32(str6->Substring(3,2))-45<10)
										 str6 = Convert::ToString(Convert::ToInt32(str6->Substring(0,2))+1)+str6->Substring(2,1)+"0"+Convert::ToString(Convert::ToInt32(str6->Substring(3,2))-45);
									 else
										 str6 = Convert::ToString(Convert::ToInt32(str6->Substring(0,2))+1)+str6->Substring(2,1)+Convert::ToString(Convert::ToInt32(str6->Substring(3,2))-45);
								 }
								 else if(str0=="\'�C\'")
								 {
									 if(Convert::ToInt32(str6->Substring(3,2))+30<60)
										 str6 = str6->Substring(0,3)+Convert::ToString(Convert::ToInt32(str6->Substring(3,2))+30);
									 else if(Convert::ToInt32(str6->Substring(3,2))+15>=60&&Convert::ToInt32(str6->Substring(3,2))-30<10)
										 str6 = Convert::ToString(Convert::ToInt32(str6->Substring(0,2))+1)+str6->Substring(2,1)+"0"+Convert::ToString(Convert::ToInt32(str6->Substring(3,2))-30);
									 else
										 str6 = Convert::ToString(Convert::ToInt32(str6->Substring(0,2))+1)+str6->Substring(2,1)+Convert::ToString(Convert::ToInt32(str6->Substring(3,2))-30);
								 }
								 
							 }
							 for(int a=j+1;a<8;a++)
							 {
								 strSQL+="\'X\',";
							 }
						 }
					 }
				 }
				 strSQL+=str5+");";
				 cmd = gcnew MySqlCommand( strSQL , connect );	
				 reader = cmd->ExecuteReader();
				 connect->Close();
				 delete cmd;
			 }
};
}

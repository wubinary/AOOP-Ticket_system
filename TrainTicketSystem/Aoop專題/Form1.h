#pragma once
#include "Train_system.h"
#include "selling_form.h"
#include "Form2.h"
#include "Form4.h"
namespace Aoop�M�D {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	
	using namespace MySql::Data::MySqlClient;
	/// <summary>
	/// Form1 ���K�n
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Train_system *train_system;      // �Хߪ��� (�W�w�n�Ϋ��ЧΦ�)	
		
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
			train_system = new Train_system;
			
		}
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		int *choose_train_tmp;
		String ^date_picked;
		String ^connectstr;  
		String ^server;  
		String ^userID;
		String ^password;
		String ^outputText;
		String ^table_name;
		/* MySQL�s�����B���O�ǰe�B���Ū�� */
		MySqlConnection ^connect; 
		MySqlCommand ^cmd;     
		MySqlDataReader ^reader; 
		/* Used to input the MySQL message */
		String ^strSQL;
	private: System::ComponentModel::IContainer^  components;
	public: 

	private:
	private: System::Windows::Forms::Button^  sellingformbutton;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  search_botton;







	private: System::Windows::Forms::ComboBox^  arrive_station_comboBox;
	private: System::Windows::Forms::ComboBox^  start_station_comboBox;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;	
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;











	private: System::Windows::Forms::Button^  managerbutton;
	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::Label^  label10;



















	private: System::Windows::Forms::Button^  button_connect;
	 /// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->search_botton = (gcnew System::Windows::Forms::Button());
			this->arrive_station_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->start_station_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->button_connect = (gcnew System::Windows::Forms::Button());
			this->managerbutton = (gcnew System::Windows::Forms::Button());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// search_botton
			// 
			this->search_botton->Enabled = false;
			this->search_botton->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->search_botton->Location = System::Drawing::Point(564, 427);
			this->search_botton->Name = L"search_botton";
			this->search_botton->Size = System::Drawing::Size(96, 36);
			this->search_botton->TabIndex = 3;
			this->search_botton->Text = L"�d��";
			this->search_botton->UseVisualStyleBackColor = true;
			this->search_botton->Click += gcnew System::EventHandler(this, &Form1::search_botton_Click);
			// 
			// arrive_station_comboBox
			// 
			this->arrive_station_comboBox->Enabled = false;
			this->arrive_station_comboBox->FormattingEnabled = true;
			this->arrive_station_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"�x�_", L"�O��", L"���", L"�s��", L"�x��", 
				L"�Ÿq", L"�x�n", L"����"});
			this->arrive_station_comboBox->Location = System::Drawing::Point(149, 158);
			this->arrive_station_comboBox->Name = L"arrive_station_comboBox";
			this->arrive_station_comboBox->Size = System::Drawing::Size(121, 20);
			this->arrive_station_comboBox->TabIndex = 4;
			this->arrive_station_comboBox->Text = L"�п�ܯ��W";
			this->arrive_station_comboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &Form1::arrive_station_comboBox_SelectionChangeCommitted);
			// 
			// start_station_comboBox
			// 
			this->start_station_comboBox->FormattingEnabled = true;
			this->start_station_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"�x�_", L"�O��", L"���", L"�s��", L"�x��", 
				L"�Ÿq", L"�x�n", L"����"});
			this->start_station_comboBox->Location = System::Drawing::Point(149, 100);
			this->start_station_comboBox->Name = L"start_station_comboBox";
			this->start_station_comboBox->Size = System::Drawing::Size(121, 20);
			this->start_station_comboBox->TabIndex = 3;
			this->start_station_comboBox->Text = L"�п�ܯ��W";
			this->start_station_comboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &Form1::start_station_comboBox_SelectionChangeCommitted);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(61, 158);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"��F��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(61, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"�_�{��";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�з���", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(235, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(369, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"<�w��ϥΰ��q�K��>";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Enabled = false;
			this->monthCalendar1->Location = System::Drawing::Point(42, 265);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 18;
			this->monthCalendar1->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Form1::monthCalendar1_DateChanged);
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Form1::monthCalendar1_DateSelected);
			// 
			// button_connect
			// 
			this->button_connect->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_connect->Location = System::Drawing::Point(110, 466);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(104, 41);
			this->button_connect->TabIndex = 29;
			this->button_connect->Text = L"connect";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &Form1::button_connect_Click);
			// 
			// managerbutton
			// 
			this->managerbutton->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->managerbutton->Location = System::Drawing::Point(759, 54);
			this->managerbutton->Name = L"managerbutton";
			this->managerbutton->Size = System::Drawing::Size(123, 61);
			this->managerbutton->TabIndex = 31;
			this->managerbutton->Text = L"�޲z�Ҧ�";
			this->managerbutton->UseVisualStyleBackColor = true;
			this->managerbutton->Click += gcnew System::EventHandler(this, &Form1::managerbutton_Click);
			// 
			// webBrowser1
			// 
			this->webBrowser1->AllowNavigation = false;
			this->webBrowser1->AllowWebBrowserDrop = false;
			this->webBrowser1->CausesValidation = false;
			this->webBrowser1->Location = System::Drawing::Point(338, 108);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(563, 290);
			this->webBrowser1->TabIndex = 32;
			this->webBrowser1->Url = (gcnew System::Uri(L"https://www.youtube.com/watch\?v=jCnN0cgZb9s", System::UriKind::Absolute));
			this->webBrowser1->WebBrowserShortcutsEnabled = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(290, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(650, 12);
			this->label4->TabIndex = 33;
			this->label4->Text = resources->GetString(L"label4.Text");
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(271, 123);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(656, 12);
			this->label5->TabIndex = 34;
			this->label5->Text = resources->GetString(L"label5.Text");
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(312, 138);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(647, 12);
			this->label6->TabIndex = 35;
			this->label6->Text = resources->GetString(L"label6.Text");
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"�s�ө���", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(276, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(2300, 48);
			this->label7->TabIndex = 36;
			this->label7->Text = L"                                                                                 " 
				L"                                                                                " 
				L"                             ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"�з���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(19, 223);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(93, 16);
			this->label8->TabIndex = 37;
			this->label8->Text = L"�п�ܤ��";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"�з���", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(334, 129);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(185, 24);
			this->label10->TabIndex = 39;
			this->label10->Text = L"���q�K���p����";
			// 
			// Form1
			// 
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(927, 557);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->managerbutton);
			this->Controls->Add(this->button_connect);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->search_botton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->arrive_station_comboBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->start_station_comboBox);
			this->Name = L"Form1";
			this->Text = L"Welcome to Ghost Island Railway";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button_sellingform_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
			 }
public: System::Void search_botton_Click(System::Object^  sender, System::EventArgs^  e) 
		     {
				 Form2 ^frm = gcnew Form2(start_station_comboBox->SelectedIndex,arrive_station_comboBox->SelectedIndex,server,userID,password,connectstr,choose_train_tmp,train_system,Convert::ToString(start_station_comboBox->SelectedItem),Convert::ToString(arrive_station_comboBox->SelectedItem));
				 frm->Enabled=true;
				 frm->Visible=true;

		     }
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
		     {
			

			 }
private: System::Void start_station_comboBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
		 {
			 train_system->start_station_tmp=start_station_comboBox->SelectedIndex;
			 arrive_station_comboBox->Enabled = true;
		 }
private: System::Void arrive_station_comboBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
		 {
			 train_system->arrive_station_tmp=arrive_station_comboBox->SelectedIndex;
			 monthCalendar1->Enabled = true;
		 }
private: System::Void monthCalendar1_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) 
		 {
			//DateTime date =  System::Convert::ToDateTime(monthCalendar1->DateSelected);					
		 }
private: System::Void comboBox_select_year_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //comboBox_select_month->Enabled = true;
		 }
private: System::Void comboBox_select_month_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
		 {		
			 /*comboBox_select_day->Enabled = true;
			 int tmp_month = Convert::ToInt32(comboBox_select_month->SelectedItem);
			 if( Convert::ToInt32(comboBox_select_year->SelectedItem) %4 == 0 && tmp_month == 2 )
			 {
				 comboBox_select_day->Items->Clear();
				 comboBox_select_day->BeginUpdate();
				 for(int i=1;i<30;i++)
				 {
					 //comboBox_select_day->Items[i]=i;
					 comboBox_select_day->Items->Add(Convert::ToString(i));

				 }
				 comboBox_select_day->EndUpdate();
			 }
			 else if(Convert::ToInt32(comboBox_select_year->SelectedItem) %4 != 0 && tmp_month == 2 )
			 {
				 comboBox_select_day->Items->Clear();
				 comboBox_select_day->BeginUpdate();
				 for(int i=1;i<29;i++)
				 {
					 comboBox_select_day->Items->Add(Convert::ToString(i));
				 }
				 comboBox_select_day->EndUpdate();
			 }
			 else if(tmp_month==1 || tmp_month==3 || tmp_month==5 || tmp_month==7 || tmp_month==8 || tmp_month==10 || tmp_month==12 )
			 { 
				 comboBox_select_day->Items->Clear();
				 comboBox_select_day->BeginUpdate();
				 for(int i=1;i<32;i++)
				 {
					 comboBox_select_day->Items->Add(Convert::ToString(i));
				 }
				 comboBox_select_day->EndUpdate();
			 }
			 else
			 {
				 comboBox_select_day->Items->Clear();
				 comboBox_select_day->BeginUpdate();
				 for(int i=1;i<31;i++)
				 {
					 comboBox_select_day->Items->Add(Convert::ToString(i));
				 }
				 comboBox_select_day->EndUpdate();
			 }*/
		 }
private: System::Void monthCalendar1_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {
			
			 String ^str = Convert::ToString(monthCalendar1->SelectionStart);
			 train_system->tmp_year = (str[0]-'0')*1000+(str[1]-'0')*100+(str[2]-'0')*10+(str[3]-'0')*1;
			 train_system->tmp_month = (str[5]-'0');
			 if(str[6]<='9' && str[6]>='0')
			 {
				 train_system->tmp_month = train_system->tmp_month*10 + (str[6]-'0');
				 train_system->tmp_day =  (str[8]-'0');
				 if(str[9]<='9' && str[9]>='0')
				 {
					 train_system->tmp_day = train_system->tmp_day*10 + (str[9]-'0');
				 }
			 }
			 else
			 {
				 train_system->tmp_day =  (str[7]-'0');
				 if(str[8]<='9' && str[8]>='0')
				 {
					 train_system->tmp_day = train_system->tmp_day*10 + (str[8]-'0');
				 }
			 }			
			 search_botton->Enabled = true;
			// date_picked = Convert::ToString(monthCalendar1->SelectionStart);
			// textBox1->Text = date_picked; 
			// textBox1->Text=Convert::ToString(train_system->tmp_day) + Convert::ToString(train_system->tmp_month) + Convert::ToString(train_system->tmp_year);
		 }
private: System::Void button_connect_Click(System::Object^  sender, System::EventArgs^  e) {
			 /*�n�Jmysql*/
			 server="localhost";
			 userID="root";
			 password="1234567890";
			 connectstr = "Network Address="+server+";"+"Persist Security Info=no;"+"User Name="+userID+";"+"Password="+password+";";
			 connect = gcnew MySqlConnection( connectstr );
			 try			
			 { 
				 /* �s���}�� */
				 connect->Open();	

				 /* �ǰe���O�� MySQL */
				 //
				 strSQL = "use project;"; //MySQL command you want to use
				 //
				 cmd = gcnew MySqlCommand( strSQL , connect );	
				 reader = cmd->ExecuteReader();
				 /* �s������ */
				 connect->Close();
				 delete cmd;
			 } 
			 catch( Exception ^ex )
			 { 					
				 System::Windows::Forms::DialogResult result;
				 result = MessageBox::Show( ex->ToString() );
				 connect->Close();
				 delete cmd;
			 }				
		 }
private: System::Void displaybox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {


		 }
private: System::Void managerbutton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Form4 ^frm = gcnew Form4();
			 frm->Enabled=true;
			 frm->Visible=true;

		 }
		 int tmp=0;
private: System::Void timer_runinghourseled_Tick(System::Object^  sender, System::EventArgs^  e) {
			  textBox1->Text = "";
			 tmp++;
			 for(int i=0;i<tmp;i++)
				 textBox1->Text +="++";
			  textBox1->Text += "<�w��ϥΰ��q�K��>";
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}


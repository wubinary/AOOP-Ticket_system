#pragma once
#include "Train.h"
#include "Form3_show_ticket1.h"
#include <string>
int tmp_train_serial_num[20];
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
	/// Form2 的摘要
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// 設計工具所需的變數。
		
		int aa,bb;
		Train_system *train_system;
		String ^train_index;
		String ^date_picked;
		String ^connectstr;  
		String ^server;  
		String ^userID;
		String ^password;
		String ^outputText;
		String ^table_name;
		
		/* MySQL連接器、指令傳送、資料讀取 */
		MySqlConnection ^connect,^connect2; 
		MySqlCommand ^cmd,^cmd2;     
		MySqlDataReader ^reader,^reader2; 
		/* Used to input the MySQL message */
		String ^strSQL;
		/// </summary>
		String ^Start_station;
		String ^Arrive_station;

	public: 








	private: System::Windows::Forms::TextBox^  textBoxtmp;

	private: System::Windows::Forms::Button^  button_confirm;








	private: System::Windows::Forms::ListBox^  listBox_tmp;
	private: System::Windows::Forms::Button^  surebutton;
	private: System::Windows::Forms::Button^  returnbutton;







	private: System::Windows::Forms::Label^  label_text;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  車種;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  車次;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  出發時間;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  到達時間;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  起站;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  終點站;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  票價;
	private: System::Windows::Forms::Timer^  timer1;









	public:
		int *Choose_train_num;
		Form2(int a,int b,String ^ss,String ^uu,String ^pp,String ^cc,int *ctn,Train_system *trr,String ^sstn,String ^astn)
		{	
			//listBox_tmp->Visible = false;
			//tmp_train_serial_num = new int[20];
			int year,month,day;
			int tmp_i[100],tmp_i_count=0,tmp_count=0;
			tmp_i[0] = -1;
			InitializeComponent();	
			//
			//TODO: 在此加入建構函式程式碼
			//
			dataGridView1->Columns[2]->HeaderText  = "45664"+sstn;
			
			dataGridView1.Columns[1].HeaderText = astn;
			aa = a; bb = b;
			Start_station = sstn;
			Arrive_station = astn;
			Choose_train_num = ctn;
			train_system = trr;
			server="140.113.122.254";
			userID="root";
			password="1234567890";
			connectstr = "Server="+"localhost"+";"+"Persist Security Info=no;"+"User Name="+userID+";"+"Password="+password+";";
			connect = gcnew MySqlConnection( connectstr );

			try			
			{
				//************ connect 1 連線 、 select日期 ************************
				connect->Open();	
				strSQL = "use project;"; //MySQL command you want to use
				cmd = gcnew MySqlCommand( strSQL , connect );	
				reader = cmd->ExecuteReader();
				connect->Close();
				delete cmd;
				connect->Open();
				strSQL = "select * from 列車查詢表;"; //MySQL command you want to use
				cmd = gcnew MySqlCommand( strSQL , connect );	
				reader = cmd->ExecuteReader();
				//************ connect 1 連線 、 select日期 ************************

				while( reader->Read() )
				{	
						if(!reader->IsDBNull(3))
						{
							//-------------抓日期-----------------------
							String ^str = reader->GetString(3)+"---";	
							String ^stra = reader->GetString(6+a) ,^strb = reader->GetString(6+b);
							year = (str[0]-'0')*1000+(str[1]-'0')*100+(str[2]-'0')*10+(str[3]-'0')*1;
							month = (str[5]-'0');
							if(str[6]<='9' && str[6]>='0')
							{
								month = month*10 + (str[6]-'0');
								day =  (str[8]-'0');
								if(str[9]<='9' && str[9]>='0')
								{
									day = day*10 + (str[9]-'0');
								}
							}
							else
							{
								day =  (str[7]-'0');
								if(str[8]<='9' && str[8]>='0')
								{
									day = day*10 + (str[8]-'0');
								}
							}	
							//-------------抓日期------------------------



							//*************是否是想要的日期**************
						/*	if( train_system->tmp_year==year && train_system->tmp_month==month && train_system->tmp_day==day && stra != "X"  && strb != "X")
							{
								tmp_i[tmp_i_count] = tmp_count; // 把是那個日期的火車的 index 存入 tmp_i[]
								tmp_i_count ++ ;
							}*/
							if(  stra != "X"  && strb != "X")
							{
								tmp_i[tmp_i_count] = tmp_count; // 把是那個日期的火車的 index 存入 tmp_i[]
								tmp_i_count ++ ;
							}
							//*************是否是想要的日期**************
							tmp_count ++ ;
						}
					
				}
				/* 連結關閉 */
				connect->Close();
				delete cmd;

				//************ connect 2 連線 、 select 全部資料 ************************
				connect->Open();	
				strSQL = "use project;"; //MySQL command you want to use
				cmd = gcnew MySqlCommand( strSQL , connect );	
				reader = cmd->ExecuteReader();
				connect->Close();
				delete cmd;
				connect->Open();
				strSQL = "select * from 列車查詢表;"; //MySQL command you want to use
				cmd = gcnew MySqlCommand( strSQL , connect );	
				reader = cmd->ExecuteReader();
				//************ connect 1 連線 、 select 全部資料 ************************

				int j=0;
				for(int i=0;i<tmp_count;i++)
				{
					reader->Read();
					if( tmp_i[j] == i )
					{
						if(reader->IsDBNull(0))
							break;
						String ^str0 = reader->GetString(1)+"　";
						String ^str1 = reader->GetString(2)+"　";
						String ^str2 = reader->GetString(4)+"　";
						String ^str3 = reader->GetString(5)+"　";
						String ^str4 = reader->GetString(6+a)+"　";
						String ^str5 = reader->GetString(b+6)+"　";
						String ^str6 = reader->GetString(14); 
						//dataGridView1->;
						dataGridView1->Rows->Add();
						dataGridView1->Rows->Add(str0,str1,str4,str5,str2,str3,str6); // 把火車的詳細資訊加入list
					

						//+++++++++++  站存所有符合客人所要的火車的車次  +++++++++++
						//tmp_train_serial_num[j] = System::Convert::ToInt64(str1);
						
			
						//tmp_train_serial_num[j] = System::Convert::ToInt32(str1);
						//textBoxtmp->Text = str1;


						//+++++++++++  站存所有符合客人所要的火車的車次  +++++++++++


						j ++ ;
					}					
				}
				/* 連結關閉 */
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
	public: 
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
	~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::ComponentModel::IContainer^  components;
protected: 
	private:

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->車種 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->車次 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->出發時間 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->到達時間 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->起站 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->終點站 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->票價 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxtmp = (gcnew System::Windows::Forms::TextBox());
			this->button_confirm = (gcnew System::Windows::Forms::Button());
			this->listBox_tmp = (gcnew System::Windows::Forms::ListBox());
			this->surebutton = (gcnew System::Windows::Forms::Button());
			this->returnbutton = (gcnew System::Windows::Forms::Button());
			this->label_text = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->CausesValidation = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->車種, this->車次, 
				this->出發時間, this->到達時間, this->起站, this->終點站, this->票價});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(21, 44);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->ShowCellToolTips = false;
			this->dataGridView1->Size = System::Drawing::Size(944, 356);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->RowHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form2::dataGridView1_RowHeaderMouseClick);
			// 
			// 車種
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->車種->DefaultCellStyle = dataGridViewCellStyle2;
			this->車種->HeaderText = L"車種";
			this->車種->Name = L"車種";
			this->車種->ReadOnly = true;
			// 
			// 車次
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->車次->DefaultCellStyle = dataGridViewCellStyle3;
			this->車次->HeaderText = L"車次";
			this->車次->Name = L"車次";
			this->車次->ReadOnly = true;
			// 
			// 出發時間
			// 
			this->出發時間->HeaderText = L"出發時間";
			this->出發時間->Name = L"出發時間";
			this->出發時間->ReadOnly = true;
			// 
			// 到達時間
			// 
			this->到達時間->HeaderText = L"到達時間";
			this->到達時間->Name = L"到達時間";
			this->到達時間->ReadOnly = true;
			// 
			// 起站
			// 
			this->起站->HeaderText = L"起站";
			this->起站->Name = L"起站";
			this->起站->ReadOnly = true;
			// 
			// 終點站
			// 
			this->終點站->HeaderText = L"終點站";
			this->終點站->Name = L"終點站";
			this->終點站->ReadOnly = true;
			// 
			// 票價
			// 
			this->票價->HeaderText = L"票價";
			this->票價->Name = L"票價";
			this->票價->ReadOnly = true;
			// 
			// textBoxtmp
			// 
			this->textBoxtmp->Location = System::Drawing::Point(964, 194);
			this->textBoxtmp->Name = L"textBoxtmp";
			this->textBoxtmp->Size = System::Drawing::Size(81, 22);
			this->textBoxtmp->TabIndex = 2;
			this->textBoxtmp->TextChanged += gcnew System::EventHandler(this, &Form2::textBoxtmp_TextChanged);
			// 
			// button_confirm
			// 
			this->button_confirm->Enabled = false;
			this->button_confirm->Location = System::Drawing::Point(970, 239);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(75, 79);
			this->button_confirm->TabIndex = 3;
			this->button_confirm->Text = L"確認";
			this->button_confirm->UseVisualStyleBackColor = true;
			this->button_confirm->Click += gcnew System::EventHandler(this, &Form2::button_confirm_Click);
			// 
			// listBox_tmp
			// 
			this->listBox_tmp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->listBox_tmp->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->listBox_tmp->ForeColor = System::Drawing::Color::Black;
			this->listBox_tmp->FormattingEnabled = true;
			this->listBox_tmp->ItemHeight = 40;
			this->listBox_tmp->Location = System::Drawing::Point(48, 68);
			this->listBox_tmp->Name = L"listBox_tmp";
			this->listBox_tmp->Size = System::Drawing::Size(504, 284);
			this->listBox_tmp->TabIndex = 4;
			this->listBox_tmp->Visible = false;
			// 
			// surebutton
			// 
			this->surebutton->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->surebutton->Location = System::Drawing::Point(650, 225);
			this->surebutton->Margin = System::Windows::Forms::Padding(2);
			this->surebutton->Name = L"surebutton";
			this->surebutton->Size = System::Drawing::Size(95, 43);
			this->surebutton->TabIndex = 5;
			this->surebutton->Text = L"確認";
			this->surebutton->UseVisualStyleBackColor = true;
			this->surebutton->Visible = false;
			this->surebutton->Click += gcnew System::EventHandler(this, &Form2::surebutton_Click);
			// 
			// returnbutton
			// 
			this->returnbutton->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->returnbutton->Location = System::Drawing::Point(650, 130);
			this->returnbutton->Margin = System::Windows::Forms::Padding(2);
			this->returnbutton->Name = L"returnbutton";
			this->returnbutton->Size = System::Drawing::Size(106, 44);
			this->returnbutton->TabIndex = 6;
			this->returnbutton->Text = L"再思考一下";
			this->returnbutton->UseVisualStyleBackColor = true;
			this->returnbutton->Visible = false;
			this->returnbutton->Click += gcnew System::EventHandler(this, &Form2::returnbutton_Click);
			// 
			// label_text
			// 
			this->label_text->AutoSize = true;
			this->label_text->BackColor = System::Drawing::Color::Yellow;
			this->label_text->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_text->ForeColor = System::Drawing::Color::Blue;
			this->label_text->Location = System::Drawing::Point(967, 351);
			this->label_text->Name = L"label_text";
			this->label_text->Size = System::Drawing::Size(161, 16);
			this->label_text->TabIndex = 7;
			this->label_text->Text = L"請選擇要購買的車次";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form2::timer1_Tick);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 411);
			this->Controls->Add(this->label_text);
			this->Controls->Add(this->returnbutton);
			this->Controls->Add(this->surebutton);
			this->Controls->Add(this->listBox_tmp);
			this->Controls->Add(this->button_confirm);
			this->Controls->Add(this->textBoxtmp);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form2";
			this->Text = L"列車班次表";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void listBox_show_train_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void dataGridView1_RowHeaderMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
		/*	 train_index = dataGridView1->CurrentCell->RowIndex;
			 *Choose_train_num = tmp_train_serial_num[train_index];
			 delete tmp_train_serial_num;*/
			train_index = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[1]->Value->ToString();
			textBoxtmp->Text  =  train_index;
			button_confirm->Enabled = true;
		 }
private: System::Void button_confirm_Click(System::Object^  sender, System::EventArgs^  e) {
			 server = "localhost";
			 userID = "root";
			 password = "1234567890";
			 connectstr = "Network Address="+server+";"+"Persist Security Info=no;"+"User Name="+userID+";"+"Password="+password+";";
			 connect = gcnew MySqlConnection( connectstr );
			 try
			 {
				 //************ connect 1 連線 、 select日期 ************************
				connect->Open();	
				strSQL = "use project;"; //MySQL command you want to use
				cmd = gcnew MySqlCommand( strSQL , connect );	
				reader = cmd->ExecuteReader();
				connect->Close();
				delete cmd;
				connect->Open();
				strSQL = "select * from 列車查詢表;"; //MySQL command you want to use
				cmd = gcnew MySqlCommand( strSQL , connect );	
				reader = cmd->ExecuteReader();
				//************ connect 1 連線 、 select日期 ************************

				//------------  抓出客人選定的火車的 詳細資料 ----------------------

				String ^str0;
				while(train_index != str0)
				{
					reader->Read();
					str0 = reader->GetString(2)+"　";
				}
				String ^ str_time0 = reader->GetString(aa+6);
				String ^ str_time1 = reader->GetString(6+bb);
				String ^ str_money = reader->GetString(14);
				textBoxtmp->Text = str0+" "+train_index+" "+str_time0+" "+str_time1+" "+str_money+" ";
				//------------  抓出客人選定的火車的 詳細資料 ----------------------


			//	Form3_show_ticket ^frm = gcnew Form3_show_ticket(train_system,train_index,aa,bb,str_time0,str_time1,str_money);
			//	frm->Visible = true;
			//	frm->Enabled = true;
				
				dataGridView1->Visible = false;
				button_confirm->Visible = false;
				textBoxtmp->Visible = false;
				surebutton->Visible = true;
				returnbutton->Visible = true;
				listBox_tmp->Visible = true;
				listBox_tmp->Items->Add("");
				listBox_tmp->Items->Add(Convert::ToString(train_system->tmp_year)+"/"+Convert::ToString(train_system->tmp_month)+"/"+Convert::ToString(train_system->tmp_day) + "          車次" + train_index + "\n") ;
				listBox_tmp->Items->Add("  " + Start_station+"       →      "+Arrive_station+"\n" );
				listBox_tmp->Items->Add("  " +  str_time0 + "               " + str_time1 + "\n" );
				listBox_tmp->Items->Add("");
				listBox_tmp->Items->Add("    " +  str_money + "元\n" );
					
				
				// 連結關閉 //
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
private: System::Void returnbutton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 dataGridView1->Visible = true;
			 button_confirm->Visible = true;
			 textBoxtmp->Visible = true;
			 surebutton->Visible = false;
			 returnbutton->Visible = false;
			 listBox_tmp->Visible = false;
		 }
private: System::Void surebutton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			this->Close();
		 }
		 int tmp=0;
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 string s="請選擇班次";
			 textBoxtmp->Text += s[0+tmp]+s[1+tmp];
			 tmp++;
			 if(tmp>5)
				 tmp=0;
		 }
private: System::Void textBoxtmp_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

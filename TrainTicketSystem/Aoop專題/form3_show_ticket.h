#pragma once

namespace Aoop盡肈 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// form3_ó布 篕璶
	/// </summary>
	public ref class form3_ó布 : public System::Windows::Forms::Form
	{
	public:
		form3_ó布(void)
		{
			InitializeComponent();
			//
			//TODO: 篶ㄧΑ祘Α絏
			//
		}

	protected:
		/// <summary>
		/// 睲埃ヴㄏノい戈方
		/// </summary>
		~form3_ó布()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 砞璸ㄣ┮惠跑计
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 砞璸ㄣや穿┮惠よ猭 - 叫づㄏノ祘Α絏絪胯竟
		/// э硂よ猭ず甧
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// form3_ó布
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(407, 213);
			this->Name = L"form3_ó布";
			this->Text = L"form3_ó布";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

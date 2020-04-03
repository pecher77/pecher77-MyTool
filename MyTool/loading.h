#pragma once
//#include "Optimize.h"
#include "ChangeCHAttrib.h"

namespace MyTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for loading
	/// </summary>
	public ref class loading : public System::Windows::Forms::Form
	{
	public:
		loading(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		loading(String^ loading_text)
		{	
			//this->loading_text = loading_text;
			
			InitializeComponent();
			this->label1->Text = loading_text;
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~loading()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  label1;
	public: System::String^ loading_text;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(36, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(338, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Loading...";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// loading
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(403, 216);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"loading";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"loading";
			this->Shown += gcnew System::EventHandler(this, &loading::loading_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion

	//private: System::Void loading_Shown(System::Object^  sender, System::EventArgs^  e) 
	//{
	//	//this->label1->Update();
	//	//this->label1->Text = loading_text;
	//	//this->label1->Update();
	//	this->Hide();
	//}
	private: System::Void loading_Shown(System::Object^  sender, System::EventArgs^  e) 
	{	
		this->TopMost = true;
		label1->Update();
	}
	};
}

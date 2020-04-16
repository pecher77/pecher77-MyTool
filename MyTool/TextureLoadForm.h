#pragma once

#ifndef TextureLoadForm_H
#define TextureLoadForm_H


#include "Macro.h"
#include "TextureTableForm.h"
	
namespace MyTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	/// <summary>
	/// Summary for TextureLoadForm
	/// </summary>
	public ref class TextureLoadForm : public System::Windows::Forms::Form
	{
	public:
		static DateTime starttime;
		String^ type;

			Boolean check = false;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	public:


	public:
		static Int32 maxvalue;

		TextureLoadForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TextureLoadForm(String^ typeload)
		{	
			this->type = typeload;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public:

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TextureLoadForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: static System::Windows::Forms::ProgressBar^  progressBar1;
	protected:
	private: static System::Windows::Forms::Label^  label1;
	private: static System::Windows::Forms::Label^  label2;
	private: static System::Windows::Forms::Label^  label3;
	private: static System::Windows::Forms::Button^  button1_cancel;


	private: AutoResetEvent^ _resetEvent = gcnew AutoResetEvent(true);


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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1_cancel = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 103);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(363, 23);
			this->progressBar1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(363, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label2->Location = System::Drawing::Point(12, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(363, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button1_cancel
			// 
			this->button1_cancel->Location = System::Drawing::Point(161, 132);
			this->button1_cancel->Name = L"button1_cancel";
			this->button1_cancel->Size = System::Drawing::Size(75, 23);
			this->button1_cancel->TabIndex = 3;
			this->button1_cancel->Text = L"Cancel";
			this->button1_cancel->UseVisualStyleBackColor = true;
			this->button1_cancel->Click += gcnew System::EventHandler(this, &TextureLoadForm::button1_cancel_Click);
			// 
			// label3
			// 
			this->label3->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label3->Location = System::Drawing::Point(12, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(363, 42);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &TextureLoadForm::backgroundWorker1_DoWork_1);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &TextureLoadForm::backgroundWorker1_RunWorkerCompleted_1);
			// 
			// TextureLoadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 163);
			this->Controls->Add(this->button1_cancel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TextureLoadForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Loading...";
			this->Shown += gcnew System::EventHandler(this, &TextureLoadForm::TextureLoadForm_Shown);
			this->ResumeLayout(false);

		}



#pragma endregion

	private: System::Void Collect_info()
	{
		if (!textures.empty())
		{
			JustShowTextureTable();
			return;
		}

		//получить сет текстур 
		unsigned int start_time = clock();

		label2->Text = "Collecting all textures...";
		label2->Update();
		GetTextureFiles();
		LOG_IN_FILE(std::endl << std::endl << "duration GetTextureFiles:" << '\t' << clock() - start_time);

		if (backgroundWorker1->CancellationPending)

			return;

		MyTool::TextureLoadForm::maxvalue = 0;

		label2->Text = "Estimating datasize...";
		label2->Update();
		MyTool::TextureLoadForm::maxvalue += Count_GameFieldRes();
		if (backgroundWorker1->CancellationPending)
			return;
		MyTool::TextureLoadForm::maxvalue += Count_ObjectLibrary();
		if (backgroundWorker1->CancellationPending)
			return;
		MyTool::TextureLoadForm::maxvalue += Count_ChapterData();
		if (backgroundWorker1->CancellationPending)
			return;
		MyTool::TextureLoadForm::maxvalue += Count_ParticleEffect();
		if (backgroundWorker1->CancellationPending)
			return;

		MyTool::TextureLoadForm::starttime = DateTime::Now;

		MyTool::TextureLoadForm::label1->Show();
		MyTool::TextureLoadForm::label3->Show();
		MyTool::TextureLoadForm::progressBar1->Maximum = maxvalue;
		MyTool::TextureLoadForm::progressBar1->Show();

		start_time = clock();
		//получить из Gamefield_Resources
		Get_GameFieldRes_Info();

		if (backgroundWorker1->CancellationPending)
			return;

		LOG_IN_FILE(std::endl << std::endl << "duration Get_GR_Info:" << '\t' << clock() - start_time);

		start_time = clock();

		////получить из ObjectLibrary имя леера, имя объекта
		Get_ObjectLibrary_Info();
		if (backgroundWorker1->CancellationPending)
			return;

		LOG_IN_FILE(std::endl << std::endl << "duration Get_OL_Info:" << '\t' << clock() - start_time);

		start_time = clock();


		Get_ChapterData_Info();
		if (backgroundWorker1->CancellationPending)
			return;
		//EndProgress();
		LOG_IN_FILE(std::endl << std::endl << "duration Get_CH_Info:" << '\t' << clock() - start_time << std::endl);

		///////////////////получить партикл(не swl) эффекты
		start_time = clock();

		Get_ParticleEffect_Info();
		if (backgroundWorker1->CancellationPending)
			return;
		//EndProgress();
		LOG_IN_FILE(std::endl << std::endl << "duration Get_EF_Info:" << '\t' << clock() - start_time);
		/////////////////////////
		OL_Clusters_in_one_string();
		if (backgroundWorker1->CancellationPending)
			return;
		DeleteOrNot();


	}

	private: System::Void TextureLoadForm_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		MyTool::TextureLoadForm::Start();

	}

	public: System::Void Start()
	{
		cancelExecution = false;
		this->check = false;
		//this->TopMost = true;
		this->BackColor = Color::GhostWhite;

		MyTool::TextureLoadForm::label1->Hide();
		MyTool::TextureLoadForm::label3->Hide();
		MyTool::TextureLoadForm::progressBar1->Hide();

		MyTool::TextureLoadForm::progressBar1->CheckForIllegalCrossThreadCalls = false;
		MyTool::TextureLoadForm::label1->CheckForIllegalCrossThreadCalls = false;
		MyTool::TextureLoadForm::label2->CheckForIllegalCrossThreadCalls = false;


		if (backgroundWorker1->IsBusy != true)
		{
			// Start the asynchronous operation.
			backgroundWorker1->RunWorkerAsync();
		}


	}

	public: System::Void JustShowTextureTable()
	{


		TextureTableForm^ form2 = gcnew TextureTableForm();
		form2->ClosingForm2 += gcnew System::EventHandler(this, &MyTool::TextureLoadForm::OnClosingForm2);
		form2->Show();

		this->Close();
	}

	public: System::Void JustShowEffectTable()
	{

		Effects_table^ eff_table = gcnew Effects_table();
		eff_table->ClosingEffectTable += gcnew System::EventHandler(this, &MyTool::TextureLoadForm::OnClosingEffectTable);
		eff_table->Show();

		this->Close();
	}

	public: static System::Void UpdateProgress(int curr_value, std::string label2, std::string label3)
	{


		float max = 0.00f;
		float val = 0.00f;
		float percent = 0.00f;
		//label1 - время и %, label2 - что грузим
		max = MyTool::TextureLoadForm::maxvalue;
		val = curr_value / max;
		percent = roundf(val * 100) / 100 * 100;

		TimeSpan timespent = DateTime::Now - starttime;
		int secondsremaining = timespent.TotalSeconds / curr_value * (maxvalue - curr_value);

		//loading estimating
		MyTool::TextureLoadForm::label1->Text = curr_value + "/ " + maxvalue + "       " + percent + " %     Time remaining: " + secondsremaining + " seconds";
		MyTool::TextureLoadForm::label1->Update();


		//тип загрузки
		String^ str2 = msclr::interop::marshal_as<String^>(label2);
		MyTool::TextureLoadForm::label2->Text = str2;
		MyTool::TextureLoadForm::label2->Update();


		MyTool::TextureLoadForm::progressBar1->Value = curr_value;
		MyTool::TextureLoadForm::progressBar1->Value = curr_value - 1;

		//тип загрузки
		String^ str3 = msclr::interop::marshal_as<String^>(label3);
		MyTool::TextureLoadForm::label3->Text = str3;
		MyTool::TextureLoadForm::label3->Update();

		MyTool::TextureLoadForm::button1_cancel->Update();

	}

			//отмена загрузки
	private: System::Void button1_cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		backgroundWorker1->CancelAsync();
		cancelExecution = true;
	}

	private: System::Void backgroundWorker1_DoWork_1(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		if (!textures.empty())
		{
			JustShowTextureTable();
			return;
		}

		//получить сет текстур 
		unsigned int start_time = clock();

		label2->Text = "Collecting all textures...";
		label2->Update();
		GetTextureFiles();
		LOG_IN_FILE(std::endl << std::endl << "duration GetTextureFiles:" << '\t' << clock() - start_time);

		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}

		MyTool::TextureLoadForm::maxvalue = 0;

		label2->Text = "Estimating datasize...";
		label2->Update();
		MyTool::TextureLoadForm::maxvalue += Count_GameFieldRes();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		MyTool::TextureLoadForm::maxvalue += Count_ObjectLibrary();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		MyTool::TextureLoadForm::maxvalue += Count_ChapterData();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		MyTool::TextureLoadForm::maxvalue += Count_ParticleEffect();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}

		MyTool::TextureLoadForm::starttime = DateTime::Now;

		MyTool::TextureLoadForm::label1->Show();
		MyTool::TextureLoadForm::label3->Show();
		MyTool::TextureLoadForm::progressBar1->Maximum = maxvalue;
		MyTool::TextureLoadForm::progressBar1->Show();

		start_time = clock();
		//получить из Gamefield_Resources
		Get_GameFieldRes_Info();

		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}

		LOG_IN_FILE(std::endl << std::endl << "duration Get_GR_Info:" << '\t' << clock() - start_time);

		start_time = clock();

		////получить из ObjectLibrary имя леера, имя объекта
		Get_ObjectLibrary_Info();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}

		LOG_IN_FILE(std::endl << std::endl << "duration Get_OL_Info:" << '\t' << clock() - start_time);

		start_time = clock();


		Get_ChapterData_Info();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		//EndProgress();
		LOG_IN_FILE(std::endl << std::endl << "duration Get_CH_Info:" << '\t' << clock() - start_time << std::endl);

		///////////////////получить партикл(не swl) эффекты
		start_time = clock();

		Get_ParticleEffect_Info();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		//EndProgress();
		LOG_IN_FILE(std::endl << std::endl << "duration Get_EF_Info:" << '\t' << clock() - start_time);
		/////////////////////////
		OL_Clusters_in_one_string();
		if (backgroundWorker1->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		DeleteOrNot();
		Get_dead_effects();
	}

	public: event EventHandler^ ClosingForm3;


	private: System::Void backgroundWorker1_RunWorkerCompleted_1(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{
		//backgroundWorker1->CancelAsync();
		if (!e->Cancelled)
			if (type=="texture_table")
				JustShowTextureTable();
			else if (type == "effect_table")
			{
				JustShowEffectTable();
			}
		else
		{
			if (!textures.empty())
				textures.clear();

			if (!GameField_objects.empty())
				GameField_objects.clear();

			if (!ObjLib_layers.empty())
				ObjLib_layers.clear();

			if (!ObjLib_items.empty())
				ObjLib_items.clear();

			if (!CH_objects.empty())
				CH_objects.clear();

			if (!particle_effects.empty())
				particle_effects.clear();

			//cancelExecution = false;
			ClosingForm3(this,nullptr);
			this->Close();
		}
	}
			

	void OnClosingForm2(System::Object ^sender, System::EventArgs ^e)
	{
		ClosingForm3(this, nullptr);
	}

	void MyTool::TextureLoadForm::OnClosingEffectTable(System::Object ^sender, System::EventArgs ^e)
	{
		ClosingForm3(this, nullptr);
	}
};
}


#endif 



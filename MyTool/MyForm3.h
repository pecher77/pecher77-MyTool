#pragma once
#include "MyForm2.h"


	
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
	/// Summary for MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		static DateTime starttime;
		String^ type; //текстуры либо партикл эффекты

			Boolean check = false;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	public:


	public:
		static Int32 resources_value;

		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		MyForm3(String^ typeload)
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
		~MyForm3()
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
			this->button1_cancel->Click += gcnew System::EventHandler(this, &MyForm3::button1_cancel_Click);
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
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm3::backgroundWorker1_DoWork_1);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm3::backgroundWorker1_RunWorkerCompleted_1);
			// 
			// MyForm3
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
			this->Name = L"MyForm3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Loading...";
			this->Shown += gcnew System::EventHandler(this, &MyForm3::MyForm3_Shown);
			this->ResumeLayout(false);

		}



#pragma endregion


	private: System::Void MyForm3_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		MyTool::MyForm3::Start();

	}

	public: System::Void Start()
	{
		cancelExecution = false;
		this->check = false;
		//this->TopMost = true;
		this->BackColor = Color::GhostWhite;

		MyTool::MyForm3::label1->Hide();
		MyTool::MyForm3::label3->Hide();
		MyTool::MyForm3::progressBar1->Hide();

		MyTool::MyForm3::progressBar1->CheckForIllegalCrossThreadCalls = false;
		MyTool::MyForm3::label1->CheckForIllegalCrossThreadCalls = false;
		MyTool::MyForm3::label2->CheckForIllegalCrossThreadCalls = false;


		if (backgroundWorker1->IsBusy != true)
		{
			backgroundWorker1->RunWorkerAsync();
		}
	}

	public: System::Void JustShowTextureTable()
	{


		MyForm2^ form2 = gcnew MyForm2();
		form2->ClosingForm2 += gcnew System::EventHandler(this, &MyTool::MyForm3::OnClosingForm2);
		form2->Show();

		this->Close();
	}

	public: System::Void JustShowEffectTable()
	{

		Effects_table^ eff_table = gcnew Effects_table();
		eff_table->ClosingEffectTable += gcnew System::EventHandler(this, &MyTool::MyForm3::OnClosingEffectTable);
		eff_table->Show();

		this->Close();
	}

	public: static System::Void UpdateProgress(int curr_value, std::string label2, std::string label3)
	{

		float max = 0.00f;
		float val = 0.00f;
		float percent = 0.00f;
		//label1 - время и %, label2 - что грузим
		max = MyTool::MyForm3::resources_value;
		val = curr_value / max;
		percent = roundf(val * 100) / 100 * 100;

		TimeSpan timespent = DateTime::Now - starttime;
		int secondsremaining = timespent.TotalSeconds / curr_value * (resources_value - curr_value);

		//loading estimating
		MyTool::MyForm3::label1->Text = curr_value + "/ " + resources_value + "       " + percent + " %     Time remaining: " + secondsremaining + " seconds";
		MyTool::MyForm3::label1->Update();


		//тип загрузки
		String^ str2 = MRSHL_stdstr_TO_Str(label2);
		MyTool::MyForm3::label2->Text = str2;
		MyTool::MyForm3::label2->Update();


		MyTool::MyForm3::progressBar1->Value = curr_value;
		MyTool::MyForm3::progressBar1->Value = curr_value - 1;

		//тип загрузки
		String^ str3 = MRSHL_stdstr_TO_Str(label3);
		MyTool::MyForm3::label3->Text = str3;
		MyTool::MyForm3::label3->Update();

		MyTool::MyForm3::button1_cancel->Update();

	}

			//отмена загрузки
	private: System::Void button1_cancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		backgroundWorker1->CancelAsync();
		cancelExecution = true;
	}

	private: System::Void backgroundWorker1_DoWork_1(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		if (collected)
		{
			JustShowTextureTable();
			return;
		}

		cancelExecution = false;

		unsigned int start_time;
		unsigned int start_time_full = clock();
		MyTool::MyForm3::resources_value = 0;

		label2->Text = "Estimating datasize...";
		label2->Update();

		start_time = clock();
		//посчитатать текстуры
		auto pair = MyTool::CountTextureFiles();

		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}

		int static_textures_count = pair.first;
		int aura_textures_count = pair.second;

		LOG_IN_FILE("textures :" << static_textures_count + aura_textures_count);
		LOG_IN_FILE("static textures :" << static_textures_count << std::endl << "aura textures :" << aura_textures_count);

		resources_value = static_textures_count + aura_textures_count;

		start_time = clock();
		//посчитатать Gamefield_res
		int count_GameFieldRes = CountGameFieldRes();
		LOG_IN_FILE("GamefieldResouirces :" << count_GameFieldRes);
		resources_value += count_GameFieldRes;
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}

		//посчитатать ParticleEffects
		int count_ParticleEffect = CountParticleEffect();
		LOG_IN_FILE("ParticleEffects :" << count_ParticleEffect);
		resources_value += count_ParticleEffect;
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}

		//посчитатать ObjectLibrary
		int count_ObjectLibraryItems = CountObjectLibrary();
		LOG_IN_FILE("ObjectLibraryItems :" << count_ObjectLibraryItems);
		resources_value += count_ObjectLibraryItems;
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}

		//посчитатать ChapterData
		int count_ChapterData = CountChapterData();
		LOG_IN_FILE("ChaprerObjects :" << count_ChapterData);
		resources_value += count_ChapterData;
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		//LOG_IN_FILE("all data:" << resources_value);
		LOG_IN_FILE("dduration counting data:" << '\t' << clock() - start_time);
		

		MyTool::MyForm3::label1->Show();
		MyTool::MyForm3::label3->Show();
		MyTool::MyForm3::progressBar1->Maximum = resources_value;
		MyTool::MyForm3::progressBar1->Show();


		label2->Text = "Collecting textures...";
		label2->Update();

		MyTool::MyForm3::starttime = DateTime::Now;

		///////////получить все текстуры
		start_time = clock();
		GetTextureFiles();
		//LOG_IN_FILE(std::endl << std::endl << "duration GetTextureFiles:" << '\t' << clock() - start_time);
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		///////////////////////////////////////////
		LOG_IN_FILE(std::endl);
		///////////получить Gamefield_Resources
		start_time = clock();
		GetGameFieldResData();
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		//LOG_IN_FILE(std::endl << std::endl << "duration Get_GR_Info:" << '\t' << clock() - start_time);
		/////////////////////////////////
		LOG_IN_FILE(std::endl);
		///////////////////получить партикл эффекты
		start_time = clock();
		GetParticleEffectData();
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		//LOG_IN_FILE(std::endl << std::endl << "duration Get_EF_Info:" << '\t' << clock() - start_time);
		/////////////////////////
		LOG_IN_FILE(std::endl);
		////получить ObjectLibrary
		start_time = clock();
		GetObjectLibraryData();
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		//LOG_IN_FILE(std::endl << std::endl << "duration Get_OL_Info:" << '\t' << clock() - start_time);
		/////////////////////////
		LOG_IN_FILE(std::endl);
		////получить Chapter-objects
		start_time = clock();
		GetChapterData();
		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		//LOG_IN_FILE(std::endl << std::endl << "duration Get_CH_Info:" << '\t' << clock() - start_time << std::endl);
		/////////////////////////
		LOG_IN_FILE(std::endl);
		////?разобраться
		OL_Clusters_in_one_string(static_textures);
		OL_Clusters_in_one_string(aura_textures);

		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		DeleteOrNot();

		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}

		Get_dead_effects();


		collected = true;

		if (backgroundWorker1->CancellationPending)
		{
			cancelExecution = true;
			return;
		}
		LOG_IN_FILE(std::endl << std::endl << "duration ALL:" << '\t' << clock() - start_time_full << std::endl);
	}

	public: event EventHandler^ ClosingForm3;


	private: System::Void backgroundWorker1_RunWorkerCompleted_1(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{
		if (!e->Cancelled)
			if (collected)
			{
				if (type == "texture_table")
					JustShowTextureTable();
				else if (type == "effect_table")
				{
					JustShowEffectTable();
				}
			}
		else
			{

				static_textures.clear();
				aura_textures.clear();

				GameField_static_textures.clear();
				GameField_aura_textures.clear();

				particle_effects_XML.clear();

				ObjLib_items.clear();

				ObjLib_layer_textures.clear();
				ObjLib_layer_xml_effects.clear();
				ObjLib_layer_swl_effects.clear();
				ObjLib_layer_light_effects.clear();
				ObjLib_layer_light_aura.clear();
				ObjLib_layer_lights.clear();

				CH_objects.clear();


			collected = false;

			//cancelExecution = false;
			ClosingForm3(this,nullptr);
			this->Close();
		}
	}
			

	void OnClosingForm2(System::Object ^sender, System::EventArgs ^e)
	{
		ClosingForm3(this, nullptr);
	}

	void MyTool::MyForm3::OnClosingEffectTable(System::Object ^sender, System::EventArgs ^e)
	{
		ClosingForm3(this, nullptr);
	}
};
}






#pragma once
#include "chapter_editor.h"

namespace MyTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for Effect_detail
	/// </summary>
	public ref class Effect_detail : public System::Windows::Forms::Form
	{
	public:
		DataTable^ EffectDataTable = gcnew DataTable("DataEffectDetails");
		BindingSource^ EffDetailBind = gcnew BindingSource();
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Numdsa;



	public:


	public:

			 String^ effect_path;

		Effect_detail(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Effect_detail(String^ effect_path)
		{
			InitializeComponent();
			this->effect_path = effect_path;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Effect_detail()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView1;
	private: System::Windows::Forms::Label^  label_effect_name;
	private: System::Windows::Forms::Label^  label_total_effects;

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
			this->advancedDataGridView1 = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->label_effect_name = (gcnew System::Windows::Forms::Label());
			this->label_total_effects = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// advancedDataGridView1
			// 
			this->advancedDataGridView1->AllowUserToAddRows = false;
			this->advancedDataGridView1->AllowUserToDeleteRows = false;
			this->advancedDataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView1->FilterAndSortEnabled = true;
			this->advancedDataGridView1->Location = System::Drawing::Point(2, 27);
			this->advancedDataGridView1->Name = L"advancedDataGridView1";
			this->advancedDataGridView1->RowTemplate->Height = 120;
			this->advancedDataGridView1->Size = System::Drawing::Size(1096, 618);
			this->advancedDataGridView1->TabIndex = 0;
			// 
			// label_effect_name
			// 
			this->label_effect_name->Location = System::Drawing::Point(8, 5);
			this->label_effect_name->Name = L"label_effect_name";
			this->label_effect_name->Size = System::Drawing::Size(449, 15);
			this->label_effect_name->TabIndex = 1;
			this->label_effect_name->Text = L"label1";
			// 
			// label_total_effects
			// 
			this->label_total_effects->Location = System::Drawing::Point(525, 4);
			this->label_total_effects->Name = L"label_total_effects";
			this->label_total_effects->Size = System::Drawing::Size(449, 15);
			this->label_total_effects->TabIndex = 1;
			this->label_total_effects->Text = L"Effects: ";
			// 
			// Effect_detail
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1101, 646);
			this->Controls->Add(this->label_total_effects);
			this->Controls->Add(this->label_effect_name);
			this->Controls->Add(this->advancedDataGridView1);
			this->MaximizeBox = false;
			this->Name = L"Effect_detail";
			this->Text = L"Effect_detail";
			this->Load += gcnew System::EventHandler(this, &Effect_detail::Effect_detail_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: array<System::Byte>^ GetImageForData(String^ path)
	{

		Bitmap^ image;
		Bitmap^ bmp;
		FileStream^ stream;
		//image = Bitmap();
		try
		{
			stream = gcnew FileStream(path, System::IO::FileMode::Open);
			bmp = gcnew Bitmap(stream);
			image = (Bitmap^)bmp->Clone();
			return imageToByteArray(image);
		}
		finally
		{
			delete stream;
			delete bmp;
		}

	}

	public: array<System::Byte>^ imageToByteArray(Image^ imageIn)
	{
		MemoryStream^ ms = gcnew MemoryStream();
		imageIn->Save(ms, System::Drawing::Imaging::ImageFormat::Png);
		return ms->ToArray();
	}

	private: System::Void Eff_Detail_CreateDataTable()
	{
		DataColumn^ column;
		//0 number
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.Int32");
		column->ColumnName = "Num";
		column->ReadOnly = false;
		column->Unique = false;
		this->EffectDataTable->Columns->Add(column);

		//1 Image
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.Byte[]");//System.Byte[]
		column->ColumnName = "Texture";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectDataTable->Columns->Add(column);

		//2 name
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "Filename";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectDataTable->Columns->Add(column);

		//3 path
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "Path";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectDataTable->Columns->Add(column);

	}

	private: System::Void Eff_detail_Fill_data()
	{

		Eff_Detail_CreateDataTable();
		String^ s = effect_path;
		std::string str_path = msclr::interop::marshal_as<std::string>(s);
		fs::path eff = str_path;

		ParticleEffect* effect = FindEffect(eff);

		label_effect_name->Text = msclr::interop::marshal_as<String^>(effect->partEff_name_s);

		

		int count = 0;
		for (auto eff_layer : effect->partEff_ParticleEffectLayers)
		{
			count++;
			DataRow^ row = EffectDataTable->NewRow();

			row[0] = count;
			if (eff_layer->effectLayer_file_exist == "-")
				row[1] = GetImageForData("nofile.png");
			else
				row[1] = GetImageForData(msclr::interop::marshal_as<String^>(eff_layer->effectLayer_effectTexture_path_s)); //картинка
			row[2] = msclr::interop::marshal_as<String^>(eff_layer->effectLayer_effectTexture_path_p.filename().string()); //имя

			row[3] = msclr::interop::marshal_as<String^>(eff_layer->effectLayer_effectTexture_path_p.parent_path().string()); //путь

			EffectDataTable->Rows->Add(row);

		}

		EffDetailBind->DataSource = EffectDataTable;
		advancedDataGridView1->DataSource = EffDetailBind;
		

		

		/*DataGridViewTextBoxColumn^ column_path = (DataGridViewTextBoxColumn^)advancedDataGridView1->Columns[3];
		column_path->AutoSizeMode = DataGridViewAutoSizeColumnsMode::DisplayedCells;
		column_path->DefaultCellStyle->WrapMode = DataGridViewTriState::True;*/

		//advancedDataGridView1->AutoResizeColumn(0);
		//advancedDataGridView1->AutoResizeColumn(2);
		//advancedDataGridView1->AutoResizeColumn(3);
		//advancedDataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
		//advancedDataGridView1->Columns[2]->AutoSizeMode = DataGridViewAutoSizeColumnMode::DisplayedCells;
		
		advancedDataGridView1->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::DisplayedCells;
		advancedDataGridView1->Columns[3]->DefaultCellStyle->WrapMode = DataGridViewTriState::True;

		advancedDataGridView1->Columns[1]->Width = 300;
		advancedDataGridView1->AutoResizeColumn(0);
		advancedDataGridView1->AutoResizeColumn(2);
		//advancedDataGridView1->AutoResizeColumn(3);
		DataGridViewImageColumn^ column = (DataGridViewImageColumn^)advancedDataGridView1->Columns[1];
		column->ImageLayout = DataGridViewImageCellLayout::Zoom;

		advancedDataGridView1->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		advancedDataGridView1->DisableFilterAndSort(advancedDataGridView1->Columns[1]);

		//кол-во тотал
		count = this->EffDetailBind->List->Count;
		std::stringstream is;
		is << count;
		std::string s_count;
		is >> s_count;
		s_count = "Total textures: " + s_count;
		label_total_effects->Text = msclr::interop::marshal_as<String^>(s_count);

	}

	private: System::Void Effect_detail_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->EffDetailBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &Effect_detail::SBind_ListChanged);
		Eff_detail_Fill_data();
		//ColorDataGrid(false);

	}

	//private: System::Void ColorDataGrid(Boolean problem)
	//{
	//	for (int i = advancedDataGridView1->Rows->Count - 1; i >= 0; i--)
	//	{
	//		//String^ path_DG = advancedDataGridView1->Rows[i]->Cells[4]->Value->ToString() + "/" + advancedDataGridView2->Rows[i]->Cells[3]->Value->ToString();
	//		//fs::path dg_path = msclr::interop::marshal_as<std::string>(path_DG);

	//		if (advancedDataGridView1->Rows[i]->Cells[1]->Value->ToString())) //если чекбокс
	//		//if (advancedDataGridView2->Rows[i]->Cells[8]->Value->ToString()=="-" || advancedDataGridView2->Rows[i]->Cells[9]->Value == 0 || advancedDataGridView2->Rows[i]->Cells[10]->Value == 0)
	//		{
	//			advancedDataGridView1->Rows[i]->DefaultCellStyle->BackColor = Color::MistyRose;
	//		}
	//		else
	//		{
	//			advancedDataGridView1->Rows[i]->DefaultCellStyle->BackColor = Color::Honeydew;
	//		}


	//	}
	//}

	private: System::Void SBind_ListChanged(System::Object^ sender, ListChangedEventArgs^ e)
	{
		int count = this->EffDetailBind->List->Count;
		std::stringstream is;
		is << count;
		std::string s_count;
		is >> s_count;
		s_count = "Total textures: " + s_count;
		label_total_effects->Text = msclr::interop::marshal_as<String^>(s_count);


		//ColorDataGrid(true);

	}


	};
}

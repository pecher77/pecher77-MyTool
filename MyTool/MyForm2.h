#pragma once
#include "Details.h"



namespace MyTool {

	using namespace System;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>




	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:	BindingSource^ SBind = gcnew BindingSource();
	private: System::Windows::Forms::Button^  button_Select;

	private: System::Windows::Forms::Button^  button_unselect;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label1_progress;
	private: System::Windows::Forms::Button^  button_refresh_table;
	private: System::Windows::Forms::Button^  button_clear_filter;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1_delelte_textures;
	private: Boolean stop_deleting = false;
	private: System::Windows::Forms::Button^  button1_cancel_del;

	private: DataTable^ TexturesDataTable = gcnew DataTable("DataTextures");

	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


		//MyForm2(System::Windows::Forms::Form ^ previousform)
		//{
		//	InitializeComponent();
		//	//
		//	firstform = previousform;
		//	//TODO: Add the constructor code here
		//	//
		//}
	
	//public: System::Windows::Forms::Form^ firstform;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView2;



	private: System::Windows::Forms::Label^  label_total_textures;
	private: System::Windows::Forms::Label^  label_Total_size;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Num;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Delete;
	private: System::Windows::Forms::DataGridViewImageColumn^  Texture;
	private: System::Windows::Forms::Button^  button_delete_selected;

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
			this->advancedDataGridView2 = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->Num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Delete = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Texture = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->label_total_textures = (gcnew System::Windows::Forms::Label());
			this->label_Total_size = (gcnew System::Windows::Forms::Label());
			this->button_delete_selected = (gcnew System::Windows::Forms::Button());
			this->button_Select = (gcnew System::Windows::Forms::Button());
			this->button_unselect = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1_progress = (gcnew System::Windows::Forms::Label());
			this->button_refresh_table = (gcnew System::Windows::Forms::Button());
			this->button_clear_filter = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1_delelte_textures = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1_cancel_del = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// advancedDataGridView2
			// 
			this->advancedDataGridView2->AllowUserToAddRows = false;
			this->advancedDataGridView2->AllowUserToDeleteRows = false;
			this->advancedDataGridView2->AllowUserToResizeRows = false;
			this->advancedDataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Num,
					this->Delete, this->Texture
			});
			this->advancedDataGridView2->FilterAndSortEnabled = true;
			this->advancedDataGridView2->Location = System::Drawing::Point(3, 58);
			this->advancedDataGridView2->Name = L"advancedDataGridView2";
			this->advancedDataGridView2->ReadOnly = true;
			this->advancedDataGridView2->RowTemplate->Height = 120;
			this->advancedDataGridView2->RowTemplate->ReadOnly = true;
			this->advancedDataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::RowHeaderSelect;
			this->advancedDataGridView2->Size = System::Drawing::Size(1700, 741);
			this->advancedDataGridView2->TabIndex = 0;
			this->advancedDataGridView2->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm2::advancedDataGridView2_CellDoubleClick);
			// 
			// Num
			// 
			this->Num->DataPropertyName = L"Num";
			this->Num->HeaderText = L"Num";
			this->Num->MinimumWidth = 22;
			this->Num->Name = L"Num";
			this->Num->ReadOnly = true;
			this->Num->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->Num->Width = 22;
			// 
			// Delete
			// 
			this->Delete->DataPropertyName = L"Delete";
			this->Delete->HeaderText = L"Delete";
			this->Delete->MinimumWidth = 22;
			this->Delete->Name = L"Delete";
			this->Delete->ReadOnly = true;
			this->Delete->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->Delete->Width = 50;
			// 
			// Texture
			// 
			this->Texture->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Texture->DataPropertyName = L"Texture";
			this->Texture->HeaderText = L"Texture";
			this->Texture->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Texture->MinimumWidth = 22;
			this->Texture->Name = L"Texture";
			this->Texture->ReadOnly = true;
			this->Texture->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			// 
			// label_total_textures
			// 
			this->label_total_textures->Location = System::Drawing::Point(1015, 23);
			this->label_total_textures->Name = L"label_total_textures";
			this->label_total_textures->Size = System::Drawing::Size(159, 23);
			this->label_total_textures->TabIndex = 1;
			this->label_total_textures->Text = L"Total Textures";
			// 
			// label_Total_size
			// 
			this->label_Total_size->Location = System::Drawing::Point(704, 23);
			this->label_Total_size->Name = L"label_Total_size";
			this->label_Total_size->Size = System::Drawing::Size(305, 23);
			this->label_Total_size->TabIndex = 1;
			this->label_Total_size->Text = L"Total size";
			// 
			// button_delete_selected
			// 
			this->button_delete_selected->Location = System::Drawing::Point(162, 23);
			this->button_delete_selected->Name = L"button_delete_selected";
			this->button_delete_selected->Size = System::Drawing::Size(106, 26);
			this->button_delete_selected->TabIndex = 2;
			this->button_delete_selected->Text = L"Delete selected";
			this->button_delete_selected->UseVisualStyleBackColor = true;
			this->button_delete_selected->Click += gcnew System::EventHandler(this, &MyForm2::button_delete_selected_Click);
			// 
			// button_Select
			// 
			this->button_Select->Location = System::Drawing::Point(54, 8);
			this->button_Select->Name = L"button_Select";
			this->button_Select->Size = System::Drawing::Size(60, 20);
			this->button_Select->TabIndex = 3;
			this->button_Select->Text = L"Select";
			this->button_Select->UseVisualStyleBackColor = true;
			this->button_Select->Click += gcnew System::EventHandler(this, &MyForm2::button_Select_Click);
			// 
			// button_unselect
			// 
			this->button_unselect->Location = System::Drawing::Point(54, 31);
			this->button_unselect->Name = L"button_unselect";
			this->button_unselect->Size = System::Drawing::Size(60, 20);
			this->button_unselect->TabIndex = 3;
			this->button_unselect->Text = L"UnSelect";
			this->button_unselect->UseVisualStyleBackColor = true;
			this->button_unselect->Click += gcnew System::EventHandler(this, &MyForm2::button_unselect_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(92, 802);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(318, 23);
			this->progressBar1->TabIndex = 4;
			// 
			// label1_progress
			// 
			this->label1_progress->AutoSize = true;
			this->label1_progress->Location = System::Drawing::Point(417, 806);
			this->label1_progress->Name = L"label1_progress";
			this->label1_progress->Size = System::Drawing::Size(54, 13);
			this->label1_progress->TabIndex = 5;
			this->label1_progress->Text = L"Loading...";
			// 
			// button_refresh_table
			// 
			this->button_refresh_table->Location = System::Drawing::Point(274, 23);
			this->button_refresh_table->Name = L"button_refresh_table";
			this->button_refresh_table->Size = System::Drawing::Size(116, 26);
			this->button_refresh_table->TabIndex = 2;
			this->button_refresh_table->Text = L"Refresh table";
			this->button_refresh_table->UseVisualStyleBackColor = true;
			this->button_refresh_table->Click += gcnew System::EventHandler(this, &MyForm2::button_refresh_table_Click);
			// 
			// button_clear_filter
			// 
			this->button_clear_filter->Location = System::Drawing::Point(396, 23);
			this->button_clear_filter->Name = L"button_clear_filter";
			this->button_clear_filter->Size = System::Drawing::Size(116, 26);
			this->button_clear_filter->TabIndex = 2;
			this->button_clear_filter->Text = L"Clear filter";
			this->button_clear_filter->UseVisualStyleBackColor = true;
			this->button_clear_filter->Click += gcnew System::EventHandler(this, &MyForm2::button_clear_filter_Click);
			// 
			// backgroundWorker1_delelte_textures
			// 
			this->backgroundWorker1_delelte_textures->WorkerSupportsCancellation = true;
			this->backgroundWorker1_delelte_textures->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm2::backgroundWorker1_DoWork);
			this->backgroundWorker1_delelte_textures->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm2::backgroundWorker1_RunWorkerCompleted);
			// 
			// button1_cancel_del
			// 
			this->button1_cancel_del->Location = System::Drawing::Point(3, 802);
			this->button1_cancel_del->Name = L"button1_cancel_del";
			this->button1_cancel_del->Size = System::Drawing::Size(75, 23);
			this->button1_cancel_del->TabIndex = 6;
			this->button1_cancel_del->Text = L"Cancel deleting";
			this->button1_cancel_del->UseVisualStyleBackColor = true;
			this->button1_cancel_del->Click += gcnew System::EventHandler(this, &MyForm2::button1_cancel_del_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1709, 829);
			this->Controls->Add(this->button1_cancel_del);
			this->Controls->Add(this->label1_progress);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button_unselect);
			this->Controls->Add(this->button_Select);
			this->Controls->Add(this->button_clear_filter);
			this->Controls->Add(this->button_refresh_table);
			this->Controls->Add(this->button_delete_selected);
			this->Controls->Add(this->label_Total_size);
			this->Controls->Add(this->label_total_textures);
			this->Controls->Add(this->advancedDataGridView2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm2";
			this->Text = L"Textures datatable";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm2::MyForm2_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		public:
			
			
#pragma endregion
	
#pragma region creatingDatagrid 

public: array<System::Byte>^ imageToByteArray(Image^ imageIn)
	{
		MemoryStream^ ms = gcnew MemoryStream();
		imageIn->Save(ms, System::Drawing::Imaging::ImageFormat::Png);
		return ms->ToArray();
	}

public: Image^ byteArrayToImage(array<System::Byte>^ byteArrayIn)
	{
		MemoryStream^ ms = gcnew MemoryStream(byteArrayIn);
		Image^ returnImage = Image::FromStream(ms);
		return returnImage;
	}

private: array<System::Byte>^ GetImageForData(String^ path)
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

private: String^ GetImageResolution(String^ path)
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
		return image->Width + "x" + image->Height;
	}
	finally
	{
		delete stream;
		delete bmp;
		delete image;
	}

}

		 //создать datatable
private: System::Void CreateDataTable()
{
	if (TexturesDataTable != nullptr)
		TexturesDataTable->Reset();

	DataColumn^ column;
	//0 number
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "Num";
	column->ReadOnly = false;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//1 check
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Boolean");
	column->ColumnName = "Delete";
	column->ReadOnly = false;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//2 Image
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Byte[]");//System.Byte[]
	column->ColumnName = "Texture";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//3 filename
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "FileName";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//4 path
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "Path";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//5 resolution
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "Resolution";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//6 atlas
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "Atlas";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//7 Size
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "Size";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//8 Exist_in_GR
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "in_GR";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);


	//9 Exist_in_OL
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "in_OL";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//10 Exist_in_CH
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "ON_META";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//11 Exist_in_Ef
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "in_EF";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);
}

		 //заполнить datatable данными
private: System::Void FillDataTable()
	{	

	TexturesDataTable->Clear();

	loading^ loading_form = gcnew loading("Filling database...");
	loading_form->Show();
	loading_form->label1->Update();

		int count = 0;
		int chapter_size = 0;
		for (auto& it : static_textures)
		{	
			count++;
			DataRow^ row = TexturesDataTable->NewRow();

			row[0] = count;
			row[1] = it->TD_to_delete;
			row[2] = GetImageForData(MRSHL_stdstr_TO_Str(it->TD_texture_name)); //картинка
			row[3] = MRSHL_stdstr_TO_Str(it->TD_path.filename().string()); //имя
			row[4] = MRSHL_stdstr_TO_Str(it->TD_path.parent_path().string());//путь

			String^ res = MRSHL_stdstr_TO_Str(it->TD_texture_name);
			row[5] = GetImageResolution(res);	//разрешение

			std::string atlases;

			if(it->TD_GRs.size() == 1)
			{	
				auto& iter = it->TD_GRs.begin();
				atlases = (*iter)->gameFieldRes_group;
				row[6] = MRSHL_stdstr_TO_Str(atlases); //атлас
			}
			else if (it->TD_GRs.size() > 1)
			{	
				auto& iter = it->TD_GRs.begin();
				atlases = (*iter)->gameFieldRes_group;

				std::advance(iter, 1);

				while (iter != it->TD_GRs.end())
				{
					atlases += ", ";
					atlases += (*iter)->gameFieldRes_group;
					std::advance(iter, 1);
				}

				row[6] = MRSHL_stdstr_TO_Str(atlases); //атлас
			}
			else if (it->TD_GRs.size() == 0)
				row[6] = "";

			row[7] = it->TD_size;


			row[8] = it->TD_GRs.size(); //в скольки объектах GR текстура


			//кол-во items
			if (!it->TD_GRs.empty())
			{	
				std::set<ObjLibItem*> layers;
				int count = 0;
				for (auto& gr : it->TD_GRs)
				{	
					for (auto& layer : gr->gameFieldRes_ObjLibLayers)
						layers.emplace(layer->objLayer_item);
				}
				row[9] = layers.size();
			}
			else row[9] = 0;

			//кол-во объектов на мете
			if (!it->TD_GRs.empty())
			{	
				chapter_size = 0;
				for (auto& gr : it->TD_GRs)
				{
					for (auto& layer : gr->gameFieldRes_ObjLibLayers)
					{
						chapter_size += layer->objLayer_item->objItem_ChapterDatas.size();
					}
				}
				row[10] = chapter_size;
			}
			else row[10] = 0;

			row[11] = it->TD_effects.size();
			
			TexturesDataTable->Rows->Add(row);
		}
		
		for (auto& it : aura_textures)
		{
			count++;
			DataRow^ row = TexturesDataTable->NewRow();

			row[0] = count;
			row[1] = it->TD_to_delete;
			row[2] = GetImageForData(MRSHL_stdstr_TO_Str(it->TD_texture_name)); //картинка
			row[3] = MRSHL_stdstr_TO_Str(it->TD_path.filename().string()); //имя
			row[4] = MRSHL_stdstr_TO_Str(it->TD_path.parent_path().string());//путь

			String^ res = MRSHL_stdstr_TO_Str(it->TD_texture_name);
			row[5] = GetImageResolution(res);	//разрешение

			std::string atlases;

			if (it->TD_GRs.size() == 1)
			{
				auto& iter = it->TD_GRs.begin();
				atlases = (*iter)->gameFieldRes_group;
				row[6] = MRSHL_stdstr_TO_Str(atlases); //атлас
			}
			else if (it->TD_GRs.size() > 1)
			{
				auto& iter = it->TD_GRs.begin();
				atlases = (*iter)->gameFieldRes_group;

				std::advance(iter, 1);

				while (iter != it->TD_GRs.end())
				{
					atlases += ", ";
					atlases += (*iter)->gameFieldRes_group;
					std::advance(iter, 1);
				}

				row[6] = MRSHL_stdstr_TO_Str(atlases); //атлас
			}
			else if (it->TD_GRs.size() == 0)
				row[6] = "";

			row[7] = it->TD_size;


			row[8] = it->TD_GRs.size(); //в скольки объектах GR текстура


			//кол-во items
			if (!it->TD_GRs.empty())
			{
				std::set<ObjLibItem*> items;
				int count = 0;
				for (auto& gr : it->TD_GRs)
				{
					for (auto& layer : gr->gameFieldRes_ObjLibLayers)
						items.emplace(layer->objLayer_item);
				}
				row[9] = items.size();
			}
			else row[9] = 0;

			//кол-во датаайди
			if (!it->TD_GRs.empty())
			{
				chapter_size = 0;
				for (auto& gr : it->TD_GRs)
				{
					for (auto& layer : gr->gameFieldRes_ObjLibLayers)
					{
						chapter_size += layer->objLayer_item->objItem_ChapterDatas.size();
					}
				}
				row[10] = chapter_size;
			}
			else row[10] = 0;

			row[11] = it->TD_effects.size();

			TexturesDataTable->Rows->Add(row);
		}
		

		loading_form->Close();
		
	}

		 //привязать DataTable к биндингу
private: System::Void BindDataTableToBinding()
{
	SBind->DataSource = nullptr;
	SBind->DataSource = TexturesDataTable;
}

		 //привязать биндинг к датагрид
private: System::Void BindBindingToDatagrid()
{
	advancedDataGridView2->DataSource = nullptr;
	advancedDataGridView2->Update();
	advancedDataGridView2->Refresh();
	advancedDataGridView2->DataSource = SBind;
}

		 //размеры столбцов
private: System::Void EditDataGrid()
{
	advancedDataGridView2->AutoResizeColumns();
	advancedDataGridView2->Columns[0]->Width = 50;
	advancedDataGridView2->Columns[1]->Width = 50; //удалить
	advancedDataGridView2->Columns[2]->Width = 300; //картинка
	advancedDataGridView2->Columns[3]->Width = 200; //название
	advancedDataGridView2->Columns[4]->Width = 600; //путь
	advancedDataGridView2->Columns[5]->Width = 100; //разрешение
	advancedDataGridView2->Columns[6]->Width = 100; //атлас
	advancedDataGridView2->Columns[7]->Width = 50; //размер 
	advancedDataGridView2->Columns[8]->Width = 60; //exist GR
	advancedDataGridView2->Columns[9]->Width = 60; //exist OL
	advancedDataGridView2->Columns[10]->Width = 80; //exist CH
	advancedDataGridView2->Columns[11]->Width = 60; //кол-во эффектов
	advancedDataGridView2->DisableFilterAndSort(advancedDataGridView2->Columns[2]);
	advancedDataGridView2->ClearSelection();

	//сумма размера текстур
	int sum = 0;
	for (int i = 0; i < advancedDataGridView2->Rows->Count; i++)
	{
		sum += Convert::ToInt32(advancedDataGridView2->Rows[i]->Cells[7]->Value);
	}
	Double mb = sum / 1000000;
	label_Total_size->Text = "Total size: " + sum.ToString() + " bytes = " + mb.ToString() + " Mbytes";

	label_total_textures->Text = Convert::ToString(this->SBind->List->Count);
}

		 //раскрасить датагрид
private: System::Void ColorDataGrid(Boolean problem)
{
	for (int i = advancedDataGridView2->Rows->Count - 1; i >= 0; i--)
	{	
		String^ path_DG = advancedDataGridView2->Rows[i]->Cells[4]->Value->ToString() + "/" + advancedDataGridView2->Rows[i]->Cells[3]->Value->ToString();
		fs::path dg_path = MRSHL_Str_TO_stdstr(path_DG);
			
		if (Convert::ToBoolean(advancedDataGridView2->Rows[i]->Cells[1]->Value->ToString())) //если чекбокс
		//if (advancedDataGridView2->Rows[i]->Cells[8]->Value->ToString()=="-" || advancedDataGridView2->Rows[i]->Cells[9]->Value == 0 || advancedDataGridView2->Rows[i]->Cells[10]->Value == 0)
		{
			advancedDataGridView2->Rows[i]->DefaultCellStyle->BackColor = Color::MistyRose;
		}
		else
		{
			advancedDataGridView2->Rows[i]->DefaultCellStyle->BackColor = Color::Honeydew;
		}

		if (problem && !problem_textures_path.empty())
		{
			for (int i = 0; i != problem_textures_path.size(); i++)
			{
				if (fs::equivalent(problem_textures_path[i], dg_path))
				{
					advancedDataGridView2->Rows[i]->DefaultCellStyle->BackColor = Color::Red;
					break;
				}
			}
		}
	}
}

		 //переномировать DataTable
private: System::Void ReNumDataTable()
{
	for (int j = 0; j != TexturesDataTable->Rows->Count; j++)
	{
		DataRow^ row = TexturesDataTable->Rows[j];
		row["Num"] = j + 1;
	}
}

		 //удалить строку из DataTable не юзается
private: System::Void DeleteFromDataTable(String^ texture_path)
{
	//std::string s_texture_path = MRSHL_Str_TO_stdstr(texture_path);
	fs::path f_texture_path = MRSHL_Str_TO_stdstr(texture_path);

	for (int j = TexturesDataTable->Rows->Count - 1; j >= 0; j--)
	{
		DataRow^ row = TexturesDataTable->Rows[j];
		String^ path_DT = row["Path"]->ToString() + "/" + row["FileName"]->ToString();
		fs::path dt_path = MRSHL_Str_TO_stdstr(path_DT);

		if (fs::equivalent(f_texture_path, dt_path))
		{
			TexturesDataTable->Rows->Remove(row);
#ifdef DDDEBAG

			LOG_IN_FILE(deleting_count << '\t' << "Deleted" << '\t' << "DATATABLE" << '\t' << "datatable_row" << '\t' << MRSHL_Str_TO_stdstr(texture_path));

#endif
			break;
		}

	}

}



#pragma endregion creatingDatagrid 

private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) 
	{	
		advancedDataGridView2->CheckForIllegalCrossThreadCalls = false;
		//SBind->->CheckForIllegalCrossThreadCalls = false;
		this->SBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &MyForm2::SBind_ListChanged);

		CreateDataTable();
		FillDataTable();
		BindDataTableToBinding();
		BindBindingToDatagrid();
		EditDataGrid();
		ColorDataGrid(false);

		progressBar1->Hide();
		label1_progress->Hide();
		button1_cancel_del->Hide();
	}
	
delegate System::Void Del_DisableDataGrid();

public: event Del_DisableDataGrid^ ev_DisableDataGrid;

/////////////////////////////УДАЛЕНИЕ ТЕКСТУР
private: System::Void DeleteSelectedTextures(DoWorkEventArgs^  e)
{
	button1_cancel_del->Show();
	progressBar1->Value = 0;
	progressBar1->Show();
	label1_progress->Text = "Loading...";
	label1_progress->Show();

	texture_deleted = 0;
	texture_deleted_size = 0;
	resources_texture_deleted = 0;
	resources_texture_deleted_size = 0;
	OL_items_deleted = 0;

	unsigned int start_time = clock();


	error_counter = 0;

	LOG_IN_FILE(std::endl << std::endl << "DELETING textures and records in xml files");
	problem_textures_path.clear();

	DateTime starttime = DateTime::Now;

	int count_chapter_dataid = 0;
	

	for (int i = advancedDataGridView2->Rows->Count - 1; i >= 0; i--)
	{	
		if (backgroundWorker1_delelte_textures->CancellationPending)
		{
			e->Cancel = true;
			return;
		}
		/*if (stop_deleting)
			break;*/
		if (Convert::ToBoolean(advancedDataGridView2->Rows[i]->Cells[1]->Value->ToString())) //если чекбокс удалить
		{
			deleting_count++;
			String^ path_DG = advancedDataGridView2->Rows[i]->Cells[4]->Value->ToString() + "/" + advancedDataGridView2->Rows[i]->Cells[3]->Value->ToString();

			//путь текстуры
			std::string s_path = MRSHL_Str_TO_stdstr(path_DG);
			fs::path path_texture = s_path;

			//найти удаляемую текстуру по пути
			TextureData* td = FindTexture(path_texture, static_textures);
			if (!td)
				td = FindTexture(path_texture, aura_textures);

			assert(td);

			DeleteTexture(td);

			//обновить прогресс бар
			TimeSpan timespent = DateTime::Now - starttime;
			int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
			label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
			label1_progress->Update();
			progressBar1->Value++;
		}
	}

	label1_progress->Text = "Deleting empty items...";
	label1_progress->Update();

	DeleteNoLayersItem();

	
}

private: System::Void button_delete_selected_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	String^ message = "Marked textures and their records in Gamefield_Resources.xml and ObjectLibrary.xml will be deleted. Proceed?";
	String^ caption = "Deleting";

	auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::No)
	{
		return;
	}

	////получить кол-во удаляемых текстур
	int count_delete = (int)Invoke(gcnew Del_CountDeletingTexture(this, &MyForm2::CountDeletingTexture));


	if (count_delete == 0)
	{
		MessageBox::Show("Not selected for deleting", "Result");
		return;
	}

	progressBar1->Maximum = count_delete;

	this->SBind->ListChanged -= gcnew System::ComponentModel::ListChangedEventHandler(this, &MyForm2::SBind_ListChanged);

	advancedDataGridView2->Enabled = false;
	////событие
	ev_DisableDataGrid();

	
	if (backgroundWorker1_delelte_textures->IsBusy != true)
	{
		backgroundWorker1_delelte_textures->RunWorkerAsync();
	}
	
}

#pragma region backgroundWorker

private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{	
	DeleteSelectedTextures(e);
}

private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
{
	label1_progress->Hide();
	progressBar1->Hide();
	button1_cancel_del->Hide();

	RemoveEmptyFolders();

	LOG_IN_FILE("Deleted textures" << '\t' << texture_deleted << '\t' << "total size" << '\t' << texture_deleted_size);
	LOG_IN_FILE("Deleted resource textures" << '\t' << resources_texture_deleted << '\t' << "total size" << '\t' << resources_texture_deleted_size);
	LOG_IN_FILE("Deleted ObjectLibrary items" << '\t' << OL_items_deleted);

	//CreateDataTable();
	FillDataTable();
	BindDataTableToBinding();
	BindBindingToDatagrid();
	EditDataGrid();

	ColorDataGrid(false);

	
	advancedDataGridView2->Enabled = true;
	//событие
	ev_DisableDataGrid();


	this->SBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &MyForm2::SBind_ListChanged);

	if (e->Cancelled)
	{
		MessageBox::Show("Deleting Canceled");
		return;
	}
	
	if (error_counter > 0)
	{	
		Int32 texture_deleted_int32 = texture_deleted;
		Int32 texture_deleted_size_int32 = texture_deleted_size;
		Int32 resources_texture_deleted_int32 = resources_texture_deleted;
		Int32 resources_texture_deleted_size_int32 = resources_texture_deleted_size;
		Int32 OL_items_deleted_int32 = OL_items_deleted;

		MessageBox::Show("Some textures (" + error_counter + ") have not been removed. Check Log_file :" + MRSHL_stdstr_TO_Str(path_LOG), "Result");
		MessageBox::Show("Deleted textures:" + texture_deleted_int32.ToString() + " , total cleaned size: " + texture_deleted_size_int32.ToString() + " b , Deleted resource textures: " + resources_texture_deleted_int32.ToString() + ", total cleaned resources size: " + resources_texture_deleted_size_int32.ToString() + " b ,  Deleted ObjectLibrary items:  " + OL_items_deleted_int32.ToString());

		return;
	}
	if (error_counter == 0)
	{
		MessageBox::Show("All selected textures have been successfully removed", "Result");

		Int32 texture_deleted_int32 = texture_deleted;
		Int32 texture_deleted_size_int32 = texture_deleted_size;
		Int32 resources_texture_deleted_int32 = resources_texture_deleted;
		Int32 resources_texture_deleted_size_int32 = resources_texture_deleted_size;
		Int32 OL_items_deleted_int32 = OL_items_deleted;

		MessageBox::Show("Deleted textures:" + texture_deleted_int32.ToString() + " , total cleaned size: "+ texture_deleted_size_int32.ToString()+", Deleted resource textures: "+resources_texture_deleted_int32.ToString()+", total cleaned resources size: "+ resources_texture_deleted_size_int32.ToString()+",  Deleted ObjectLibrary items:  "+ OL_items_deleted_int32.ToString());
		
		return;
	}
}

private: System::Void button1_cancel_del_Click(System::Object^  sender, System::EventArgs^  e)
{
	
	backgroundWorker1_delelte_textures->CancelAsync();
	stop_deleting = true;

}

#pragma endregion backgroundWorker

delegate System::Void Del_DeleteRow(DataGridViewRow^ row);

delegate System::Void Del();

private: System::Void DeleteRow(DataGridViewRow^ row)
{
	advancedDataGridView2->Rows->Remove(row);

	advancedDataGridView2->Update();
	advancedDataGridView2->Refresh();
}

delegate System::Int32 Del_CountDeletingTexture();

private: System::Int32 CountDeletingTexture()
{
	int count_delete = 0;
	////получить кол-во удаляемых текстур
	for (int i = advancedDataGridView2->Rows->Count - 1; i >= 0; i--)
	{
		if (Convert::ToBoolean(advancedDataGridView2->Rows[i]->Cells[1]->Value->ToString()) == true) //если чекбокс удалить
			count_delete++;
	}
	return count_delete;
}

//ВЫбор чекбокс
private: System::Void button_Select_Click(System::Object^  sender, System::EventArgs^  e) 
{
	for each (DataGridViewRow^ row in advancedDataGridView2->SelectedRows)
		{
			if (row->Cells["Delete"]->Value != true)
			{
				row->Cells["Delete"]->Value = true;
				advancedDataGridView2->Update();
				advancedDataGridView2->Refresh();
				row->DefaultCellStyle->BackColor = Color::MistyRose;
			}
			else
				row->DefaultCellStyle->BackColor = Color::Honeydew;
		}

}

//ВЫбор чекбокс
private: System::Void button_unselect_Click(System::Object^  sender, System::EventArgs^  e) 
{
	for each (DataGridViewRow^ row in advancedDataGridView2->SelectedRows)
	{
		//Convert::ToBoolean(advancedDataGridView2->Rows[i]->Cells[1]->Value->ToString())
		if (Convert::ToBoolean(row->Cells[1]->Value->ToString()))
		{
			row->Cells[1]->Value = false;
			advancedDataGridView2->Update();
			advancedDataGridView2->Refresh();
			row->DefaultCellStyle->BackColor = Color::Honeydew;
		}
	}
}

//рефреш таблицы
private: System::Void button_refresh_table_Click(System::Object^  sender, System::EventArgs^  e) 
{	

	loading^ loading_form = gcnew loading("Refreshing...");
	loading_form->Show();

	loading_form->label1->Update();

	FillDataTable();
	BindDataTableToBinding();
	BindBindingToDatagrid();
	EditDataGrid();
	ColorDataGrid(false);

	//ColorDataGrid(true);
	loading_form->Hide();
}

//Детально
private: System::Void advancedDataGridView2_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{	
	Int32 clicked_column_index = e->ColumnIndex;

	String^ texture_path = advancedDataGridView2->CurrentRow->Cells[4]->Value->ToString() + "/" + advancedDataGridView2->CurrentRow->Cells[3]->Value->ToString();
	std::string s_path = MRSHL_Str_TO_stdstr(texture_path);
	fs::path p_path = s_path;

	TextureData* d = FindTexture(p_path, static_textures);
	if (!d)
		d = FindTexture(p_path, aura_textures);
	

	if (clicked_column_index == 3) //имя
	{
		String^ fileName = MRSHL_stdstr_TO_Str(d->TD_texture_name);
		Process^ photoviewer = gcnew Process();
		photoviewer->Start(fileName);
	}
	else if (clicked_column_index == 4) //путь
	{
		Process^ explorer = gcnew Process();
		//String^ filepath = MRSHL_stdstr_TO_Str(d->TD_s_texture_name);
		String^ filepath = MRSHL_stdstr_TO_Str(d->TD_path.parent_path().string());
		explorer->Start(filepath);

	}
	else
	{
		Details^ detail_form = gcnew Details(d);
		detail_form->Show();
	}
}
		
//тоталы сверху при изменении фильтра
private: System::Void SBind_ListChanged(System::Object^ sender, ListChangedEventArgs^ e)
{
	int count = this->SBind->List->Count;
	std::stringstream is;
	is << count;
	std::string s_count;
	is >> s_count;
	s_count = "Total textures: " + s_count;
	label_total_textures->Text = MRSHL_stdstr_TO_Str(s_count);

	int sum = 0;

	for (int i = 0; i < advancedDataGridView2->Rows->Count; i++)
	{
		sum += Convert::ToInt32(advancedDataGridView2->Rows[i]->Cells[7]->Value);
	}

	Double mb = sum / 1000000;

	label_Total_size->Text = "Total size: " + sum.ToString() + " bytes = " + mb.ToString() + " Mbytes";

	ColorDataGrid(true);
	advancedDataGridView2->ClearSelection();

}

//очистить фильтр
private: System::Void button_clear_filter_Click(System::Object^  sender, System::EventArgs^  e) 
{
	advancedDataGridView2->CleanFilter();

}

public: event EventHandler^ ClosingForm2;

//Событие включения/отключения датагрид
void Onev_DisableDataGrid()
{
			 if (!advancedDataGridView2->Enabled) {
				 advancedDataGridView2->DefaultCellStyle->BackColor = SystemColors::Control;
				 advancedDataGridView2->DefaultCellStyle->ForeColor = SystemColors::GrayText;
				 advancedDataGridView2->ColumnHeadersDefaultCellStyle->BackColor = SystemColors::Control;
				 advancedDataGridView2->ColumnHeadersDefaultCellStyle->ForeColor = SystemColors::GrayText;
				 advancedDataGridView2->CurrentCell = nullptr;
				 advancedDataGridView2->ReadOnly = true;
				 advancedDataGridView2->EnableHeadersVisualStyles = false;
			 }
			 else {
				 advancedDataGridView2->DefaultCellStyle->BackColor = SystemColors::Window;
				 advancedDataGridView2->DefaultCellStyle->ForeColor = SystemColors::ControlText;
				 advancedDataGridView2->ColumnHeadersDefaultCellStyle->BackColor = SystemColors::Window;
				 advancedDataGridView2->ColumnHeadersDefaultCellStyle->ForeColor = SystemColors::ControlText;
				 advancedDataGridView2->ReadOnly = false;
				 advancedDataGridView2->EnableHeadersVisualStyles = true;
			 }
}


private: System::Void MyForm2_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
{
	ClosingForm2(this, nullptr);
}
};



}



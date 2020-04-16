#pragma once



#ifndef TextureTableForm_H
#define TextureTableForm_H

#include "Macro.h"
#include "loading.h"
#include "Optimize.h"
#include "TextureDetailsForm.h"
//#include <msclr\marshal_cppstd.h>

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
	/// Summary for TextureTableForm
	/// </summary>



	public ref class TextureTableForm : public System::Windows::Forms::Form
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
		TextureTableForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	
	//public: System::Windows::Forms::Form^ firstform;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TextureTableForm()
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
			this->advancedDataGridView2->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TextureTableForm::advancedDataGridView2_CellDoubleClick);
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
			this->button_delete_selected->Click += gcnew System::EventHandler(this, &TextureTableForm::button_delete_selected_Click);
			// 
			// button_Select
			// 
			this->button_Select->Location = System::Drawing::Point(54, 8);
			this->button_Select->Name = L"button_Select";
			this->button_Select->Size = System::Drawing::Size(60, 20);
			this->button_Select->TabIndex = 3;
			this->button_Select->Text = L"Select";
			this->button_Select->UseVisualStyleBackColor = true;
			this->button_Select->Click += gcnew System::EventHandler(this, &TextureTableForm::button_Select_Click);
			// 
			// button_unselect
			// 
			this->button_unselect->Location = System::Drawing::Point(54, 31);
			this->button_unselect->Name = L"button_unselect";
			this->button_unselect->Size = System::Drawing::Size(60, 20);
			this->button_unselect->TabIndex = 3;
			this->button_unselect->Text = L"UnSelect";
			this->button_unselect->UseVisualStyleBackColor = true;
			this->button_unselect->Click += gcnew System::EventHandler(this, &TextureTableForm::button_unselect_Click);
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
			this->button_refresh_table->Click += gcnew System::EventHandler(this, &TextureTableForm::button_refresh_table_Click);
			// 
			// button_clear_filter
			// 
			this->button_clear_filter->Location = System::Drawing::Point(396, 23);
			this->button_clear_filter->Name = L"button_clear_filter";
			this->button_clear_filter->Size = System::Drawing::Size(116, 26);
			this->button_clear_filter->TabIndex = 2;
			this->button_clear_filter->Text = L"Clear filter";
			this->button_clear_filter->UseVisualStyleBackColor = true;
			this->button_clear_filter->Click += gcnew System::EventHandler(this, &TextureTableForm::button_clear_filter_Click);
			// 
			// backgroundWorker1_delelte_textures
			// 
			this->backgroundWorker1_delelte_textures->WorkerSupportsCancellation = true;
			this->backgroundWorker1_delelte_textures->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &TextureTableForm::backgroundWorker1_DoWork);
			this->backgroundWorker1_delelte_textures->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &TextureTableForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// button1_cancel_del
			// 
			this->button1_cancel_del->Location = System::Drawing::Point(3, 802);
			this->button1_cancel_del->Name = L"button1_cancel_del";
			this->button1_cancel_del->Size = System::Drawing::Size(75, 23);
			this->button1_cancel_del->TabIndex = 6;
			this->button1_cancel_del->Text = L"Cancel deleting";
			this->button1_cancel_del->UseVisualStyleBackColor = true;
			this->button1_cancel_del->Click += gcnew System::EventHandler(this, &TextureTableForm::button1_cancel_del_Click);
			// 
			// TextureTableForm
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
			this->Name = L"TextureTableForm";
			this->Text = L"Textures datatable";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TextureTableForm::TextureTableForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &TextureTableForm::TextureTableForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		public:
			
			
#pragma endregion
	
#pragma region creatingDatagrid 



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

	//9 Cluster
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "in_cluster";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//10 Exist_in_OL
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "in_OL";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//11 Exist_in_CH
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "in_CH";
	column->ReadOnly = true;
	column->Unique = false;
	this->TexturesDataTable->Columns->Add(column);

	//12 Cluster Ef
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
		for (auto& it : textures)
		{	
			count++;
			DataRow^ row = TexturesDataTable->NewRow();

			row[0] = count;
			row[1] = it.TD_to_delete;
			row[2] = GetImageForData(msclr::interop::marshal_as<String^>(it.TD_texture_name.string())); //картинка
			row[3] = msclr::interop::marshal_as<String^>(it.TD_texture_name.filename().string()); //имя
			row[4] = msclr::interop::marshal_as<String^>(it.TD_texture_name.parent_path().string());//путь

			String^ res = msclr::interop::marshal_as<String^>(it.TD_texture_name.string());
			row[5] = GetImageResolution(res);	//разрешение

			std::string atlases;

			if		(it.TD_GRs.size() == 1)
			{	
				auto& iter = it.TD_GRs.begin();
				atlases = (*iter)->gameFieldRes_texture_group_atlas;
				row[6] = msclr::interop::marshal_as<String^>(atlases); //атлас
			}
			else if (it.TD_GRs.size() > 1)
			{	
				auto& iter = it.TD_GRs.begin();
				atlases = (*iter)->gameFieldRes_texture_group_atlas;

				std::advance(iter, 1);

				while (iter != it.TD_GRs.end())
				{
					atlases += ", ";
					atlases += (*iter)->gameFieldRes_texture_group_atlas;
					std::advance(iter, 1);
				}

				row[6] = msclr::interop::marshal_as<String^>(atlases); //атлас
			}
			else if (it.TD_GRs.size() == 0)
				row[6] = "";

			row[7] = it.TD_size;


			row[8] = it.TD_GRs.size(); //в скольки объектах GR текстура

			row[9] = msclr::interop::marshal_as<String^>(it.TD_clusters_OL);

			//кол-во items
			if (!it.TD_GRs.empty())
			{	
				int count_items = 0;
				for (auto& gr : it.TD_GRs)
				{
					count_items += gr->gameFieldRes_unique_items.size();
				}
				row[10] = count_items; 
			}
			else row[10] = 0;

			//кол-во датаайди
			if (!it.TD_GRs.empty())
			{	
				chapter_size = 0;
				for (auto& gr : it.TD_GRs)
				{
					for (auto& item : gr->gameFieldRes_unique_items)
					{
						chapter_size += item->objItem_ChapterDatas.size();
					}
				}
				row[11] = chapter_size;
			}
			else row[11] = 0;

			row[12] = it.TD_effects.size();
			//row[13] = msclr::interop::marshal_as<String^>(it.TD_EF_exist_in_CH);
			
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
	advancedDataGridView2->Columns[8]->Width = 50; //exist GR
	advancedDataGridView2->Columns[9]->Width = 50; //cluster
	advancedDataGridView2->Columns[10]->Width = 50; //exist OL
	advancedDataGridView2->Columns[11]->Width = 50; //exist CH
	advancedDataGridView2->Columns[12]->Width = 50; //кол-во эффектов
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
		fs::path dg_path = msclr::interop::marshal_as<std::string>(path_DG);
			
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
	//std::string s_texture_path = msclr::interop::marshal_as<std::string>(texture_path);
	fs::path f_texture_path = msclr::interop::marshal_as<std::string>(texture_path);

	for (int j = TexturesDataTable->Rows->Count - 1; j >= 0; j--)
	{
		DataRow^ row = TexturesDataTable->Rows[j];
		String^ path_DT = row["Path"]->ToString() + "/" + row["FileName"]->ToString();
		fs::path dt_path = msclr::interop::marshal_as<std::string>(path_DT);

		if (fs::equivalent(f_texture_path, dt_path))
		{
			TexturesDataTable->Rows->Remove(row);
#ifdef DDDEBAG

			LOG_IN_FILE(deleting_count << '\t' << "Deleted" << '\t' << "DATATABLE" << '\t' << "datatable_row" << '\t' << msclr::interop::marshal_as<std::string>(texture_path));

#endif
			break;
		}

	}

}

#pragma endregion creatingDatagrid 

private: System::Void TextureTableForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{	
		advancedDataGridView2->CheckForIllegalCrossThreadCalls = false;
		//SBind->->CheckForIllegalCrossThreadCalls = false;
		this->SBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &TextureTableForm::SBind_ListChanged);

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
	//deleting_count = 0;
	button1_cancel_del->Show();
	progressBar1->Value = 0;
	progressBar1->Show();
	label1_progress->Text = "Loading...";
	label1_progress->Show();

	error_counter = 0;

	

	LOG_IN_FILE(std::endl << std::endl << "DELETING textures and records");
	//LOG_IN_FILE("Num"<<'\t'<<"deleting_From" << '\t' << "RESULT_del_file" << '\t' << "Texture_name" << '\t' << "path" << '\t' <<  "ID_GR" << '\t' << "ID_OL_item" << '\t' << "instanceClass");
	LOG_IN_FILE("Num" << '\t' << "deleting_RESULT" << '\t' << "deleting_from" << '\t' << "deleting_what" << '\t' << "deleting_what(name)");
	problem_textures_path.clear();

	DateTime starttime = DateTime::Now;

	int count_chapter_dataid = 0;
	boost::system::error_code ec;

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
			std::string s_path = msclr::interop::marshal_as<std::string>(path_DG);
			fs::path path_texture = s_path;


			

			//найти удаляемую текстуру по пути
			TextureData* td = FindTexture(path_texture);
			assert(td != nullptr);

			//проверка есть ли на мете, если да, - то в лог и дальше
			count_chapter_dataid = 0;
			if (!td->TD_GRs.empty())
			{
				for (auto& gr : td->TD_GRs)
				{
					if (!gr->gameFieldRes_unique_items.empty())
					{
						for (auto& item : gr->gameFieldRes_unique_items)
							count_chapter_dataid += item->objItem_ChapterDatas.size();
					}
				}

				if (count_chapter_dataid != 0)
				{
					std::string data;
					error_counter++;

					for (auto& gr : td->TD_GRs)
					{
						for (auto& item : gr->gameFieldRes_unique_items)
						{
							for (auto& chapter_dataid : item->objItem_ChapterDatas)
							{
								data = chapter_dataid->chData_storyInfo_chapter_id + " - " + chapter_dataid->chData_storyInfo_repair + " - " + chapter_dataid->chData_storyInfo_step + " - " + chapter_dataid->chData_id + " - " + chapter_dataid->chData_text_dataid;
								LOG_IN_FILE(deleting_count << '\t' << "canceled - exists on meta: " << data << '\t' << "-" << '\t' << "texture and records" << '\t' << td->TD_texture_name.string());
							}

						}
					}
					continue;
				}
			}
			//проверка есть ли в эффектах, если да, - то в лог и дальше
			if (td->TD_effects.size() != 0)
			{
				std::string data;
				error_counter++;

				for (auto& effect : td->TD_effects)
				{
					LOG_IN_FILE(deleting_count << '\t' << "canceled - exists in effect: " << effect->partEff_name_p.string() << '\t' << "-" << '\t' << "texture and records" << '\t' << td->TD_texture_name.string());
				}

				continue;
			}



			//если не удаляется текстура - дальше из контейнера не удаляем
			fs::remove(td->TD_texture_name, ec);
			LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' << "folder" << '\t' << "texture_file" << '\t' << td->TD_texture_name.string());
			if (ec != 0)
			{
				error_counter++;
				td->TD_problem = true;
				problem_textures_path.push_back(td->TD_texture_name);
				continue;
			}

			
			if (!td->TD_GRs.empty())
			{	
				for (auto& gr : td->TD_GRs)
				{
					if (!gr->gameFieldRes_ObjLibLayers.empty()) //не пустые лееры
					{
						for (auto& layer : gr->gameFieldRes_ObjLibLayers)
						{

							DeleteFromObjectLibrary(td);

							ObjLib_items.erase(layer->objLayer_item); //удалить item из контейнера
							ObjLib_layers.erase(layer); //удалить леер из контейнера
						}
					}
					DeleteFromGamefieldResources(td);
					GameField_objects.erase(gr); //удалить gr из контейнера
				}
			}
			//удаляем текстуру из контейнера
			//auto it = std::find(textures.begin(), textures.end(), *td);

			//assert(it != textures.end());

			textures.erase(*td);
			//textures.erase(it); //удаление из контейнера TextureData - в деструкторе удаляется все остальное

			//удаляем из advancedDataGridView2 через Invoke
			//Invoke(gcnew Del_DeleteRow(this, &TextureTableForm::DeleteRow), row);
				
			//обновить прогресс бар
			TimeSpan timespent = DateTime::Now - starttime;
			int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
			label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
			label1_progress->Update();
			progressBar1->Value++;
		}
	}


}

private: System::Void button_delete_selected_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	String^ message = "Marked textures and their records in Gamefield_Resources.xml and ObjectLibrary.xml will be deleted. Proceed?";
	String^ caption = "Deleting";

	auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == ::DialogResult::No)
	{
		return;
	}

	////получить кол-во удаляемых текстур
	int count_delete = (int)Invoke(gcnew Del_CountDeletingTexture(this, &TextureTableForm::CountDeletingTexture));


	if (count_delete == 0)
	{
		MessageBox::Show("Not selected for deleting", "Result");
		return;
	}

	progressBar1->Maximum = count_delete;

	this->SBind->ListChanged -= gcnew System::ComponentModel::ListChangedEventHandler(this, &TextureTableForm::SBind_ListChanged);

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



	//CreateDataTable();
	FillDataTable();
	BindDataTableToBinding();
	BindBindingToDatagrid();
	EditDataGrid();

	ColorDataGrid(false);

	
	advancedDataGridView2->Enabled = true;
	//событие
	ev_DisableDataGrid();


	this->SBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &TextureTableForm::SBind_ListChanged);

	if (e->Cancelled)
	{
		MessageBox::Show("Deleting Canceled");
		return;
	}
	
	if (error_counter > 0)
	{
		MessageBox::Show("Some textures (" + error_counter + ") have not been removed. Check Log_file :" + msclr::interop::marshal_as<String^>(path_LOG), "Result");
		return;
	}
	if (error_counter == 0)
	{
		MessageBox::Show("All selected textures have been successfully removed", "Result");
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

	



	ColorDataGrid(true);
	loading_form->Hide();
}

//Детально
private: System::Void advancedDataGridView2_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{	
	Int32 clicked_column_index = e->ColumnIndex;

	String^ texture_path = advancedDataGridView2->CurrentRow->Cells[4]->Value->ToString() + "/" + advancedDataGridView2->CurrentRow->Cells[3]->Value->ToString();
	std::string s_path = msclr::interop::marshal_as<std::string>(texture_path);
	fs::path p_path = s_path;
	TextureData* d = FindTexture(p_path);


	if (clicked_column_index == 3) //имя
	{
		String^ fileName = msclr::interop::marshal_as<String^>(d->TD_s_texture_name);
		Process^ photoviewer = gcnew Process();
		photoviewer->Start(fileName);
	}
	else if (clicked_column_index == 4) //путь
	{
		Process^ explorer = gcnew Process();
		//String^ filepath = msclr::interop::marshal_as<String^>(d->TD_s_texture_name);
		String^ filepath = msclr::interop::marshal_as<String^>(d->TD_texture_name.parent_path().string());
		explorer->Start(filepath);

	}
	else
	{
		TextureDetailsForm^ detail_form = gcnew TextureDetailsForm(d);
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
	label_total_textures->Text = msclr::interop::marshal_as<String^>(s_count);

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


private: System::Void TextureTableForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
{
	ClosingForm2(this, nullptr);
}
};



}

#endif 

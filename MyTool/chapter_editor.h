#pragma once
#include "loading.h"


namespace MyTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for chapter_editor
	/// </summary>
	public ref class chapter_editor : public System::Windows::Forms::Form
	{
	public:
		BindingSource^ CHBind = gcnew BindingSource();
		DataTable^ ChapterDataTable = gcnew DataTable("ChapterDataTable");
		chapter_editor(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~chapter_editor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView_chapter;
	protected:
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView_objects;

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
			this->advancedDataGridView_chapter = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->advancedDataGridView_objects = (gcnew Zuby::ADGV::AdvancedDataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_chapter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_objects))->BeginInit();
			this->SuspendLayout();
			// 
			// advancedDataGridView_chapter
			// 
			this->advancedDataGridView_chapter->AllowUserToAddRows = false;
			this->advancedDataGridView_chapter->AllowUserToDeleteRows = false;
			this->advancedDataGridView_chapter->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView_chapter->FilterAndSortEnabled = true;
			this->advancedDataGridView_chapter->Location = System::Drawing::Point(12, 38);
			this->advancedDataGridView_chapter->Name = L"advancedDataGridView_chapter";
			this->advancedDataGridView_chapter->Size = System::Drawing::Size(1046, 561);
			this->advancedDataGridView_chapter->TabIndex = 0;
			this->advancedDataGridView_chapter->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &chapter_editor::advancedDataGridView_chapter_CellEnter);
			// 
			// advancedDataGridView_objects
			// 
			this->advancedDataGridView_objects->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView_objects->FilterAndSortEnabled = true;
			this->advancedDataGridView_objects->Location = System::Drawing::Point(1065, 38);
			this->advancedDataGridView_objects->Name = L"advancedDataGridView_objects";
			this->advancedDataGridView_objects->Size = System::Drawing::Size(315, 561);
			this->advancedDataGridView_objects->TabIndex = 1;
			// 
			// chapter_editor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1392, 611);
			this->Controls->Add(this->advancedDataGridView_objects);
			this->Controls->Add(this->advancedDataGridView_chapter);
			this->Name = L"chapter_editor";
			this->Text = L"chapter_editor";
			this->Load += gcnew System::EventHandler(this, &chapter_editor::chapter_editor_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_chapter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_objects))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void CH_CreateDataTable()
	{	

		DataColumn^ column;
		//0 number
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.Int32");
		column->ColumnName = "Num";
		column->ReadOnly = false;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);


		//1 чаптер
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "chapter";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//2 рипейр
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "repair";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//3 step
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "step";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//4 hash id
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "id";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//5 dataid
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "dataid";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//6 x
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "x";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//7 y
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "y";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//8 m
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "m";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//9 rand
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "rand";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//10 zorder
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "zOrder";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		////11 zOrder_obj
		//column = gcnew DataColumn();
		//column->DataType = System::Type::GetType("System.String");
		//column->ColumnName = "zOrder_obj";
		//column->ReadOnly = true;
		//column->Unique = false;
		//this->ChapterDataTable->Columns->Add(column);

		//11 zOrder_instanceClass
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "zOrder_instanceClass";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//12 instanceClass
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "instanceClass";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//13 isIndoor
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "isIndoor";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//14 noRedesignDeformation
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "noRedesignDeformation";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//15 chapter_iso_uL
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "iso_uL";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//16 chapter_iso_uR
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "iso_uR";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//17 chapter_iso_x
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "iso_x";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//18 chapter_iso_y
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "iso_y";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);

		//19 chapter_iso_z
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "iso_z";
		column->ReadOnly = true;
		column->Unique = false;
		this->ChapterDataTable->Columns->Add(column);
	}

	private: System::Void CH_FillData()
	{

		loading^ loading_form = gcnew loading("Filling database...");
		loading_form->Show();
		loading_form->label1->Update();


		CH_CreateDataTable();


		int count = 0;
		for (auto& it : CH_objects)
		{
			count++;
			DataRow^ row = ChapterDataTable->NewRow();

			row[0] = count;
			row[1] = MRSHL_stdstr_TO_Str(it->chData_storyInfo_chapter_id);
			row[2] = MRSHL_stdstr_TO_Str(it->chData_storyInfo_repair);
			row[3] = MRSHL_stdstr_TO_Str(it->chData_storyInfo_step);
			row[4] = MRSHL_stdstr_TO_Str(it->chData_id);
			row[5] = MRSHL_stdstr_TO_Str(it->chData_text_dataid);
			row[6] = MRSHL_stdstr_TO_Str(it->chData_text_x);
			row[7] = MRSHL_stdstr_TO_Str(it->chData_text_y);
			row[8] = MRSHL_stdstr_TO_Str(it->chData_text_m);
			row[9] = MRSHL_stdstr_TO_Str(it->chData_text_rand);
			row[10] = MRSHL_stdstr_TO_Str(it->chData_text_zOrder);
			//row[11] = ""; //11 zOrder_obj

			row[11] = MRSHL_stdstr_TO_Str(it->chData_ObjLibItem->objItem_defaultZOrder);//11 zOrder_instanceClass
			row[12] = MRSHL_stdstr_TO_Str(it->chData_ObjLibItem->objItem_instanceClass);//12 instanceClass
			row[13] = MRSHL_stdstr_TO_Str(it->chData_ObjLibItem->objItem_isIndoor);//13 OL_isIndoor
			row[14] = MRSHL_stdstr_TO_Str(it->chData_ObjLibItem->objItem_noRedesignDeformation);//12 noRedesignDeformation

			row[15] = MRSHL_stdstr_TO_Str(it->chData_text_iso_uL);
			row[16] = MRSHL_stdstr_TO_Str(it->chData_text_iso_uR);
			row[17] = MRSHL_stdstr_TO_Str(it->chData_text_iso_x);
			row[18] = MRSHL_stdstr_TO_Str(it->chData_text_iso_y);
			row[19] = MRSHL_stdstr_TO_Str(it->chData_text_iso_z);

			ChapterDataTable->Rows->Add(row);

		}

		CHBind->DataSource = ChapterDataTable;
		advancedDataGridView_chapter->DataSource = CHBind;

		
	

			////advancedDataGridView_chapter->AutoResizeColumn(0);
			////advancedDataGridView_chapter->AutoResizeColumn(2);
			////advancedDataGridView_chapter->AutoResizeColumn(3);
		advancedDataGridView_chapter->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
		advancedDataGridView_chapter->Columns[5 ]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		
		loading_form->Close();
			//advancedDataGridView_chapter->Columns[2]->AutoSizeMode = DataGridViewAutoSizeColumnMode::DisplayedCells;
	}


	private: System::Void chapter_editor_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		//this->SBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &chapter_editor::SBind_ListChanged);
		CH_FillData();
		//ColorDataGrid(false);
		//progressBar1->Hide();
		//label1_progress->Hide();
	}
	private: System::Void advancedDataGridView_chapter_CellEnter(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (advancedDataGridView_chapter->CurrentCell->ColumnIndex == 10)  //example-'Column index=4'
		{
			advancedDataGridView_chapter->BeginEdit(true);
		}
	}
};
}

#pragma once
#include "Effect_detail.h"


namespace MyTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Effects_table
	/// </summary>
	public ref class Effects_table : public System::Windows::Forms::Form
	{
	public:
		DataTable^ EffectsDataTable = gcnew DataTable("DataEffects");
		loading^ load;
		Effect_detail^ eff_details;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label1_progress;
	private: System::Windows::Forms::Button^  button_select;
	private: System::Windows::Forms::Button^  button_unselect;
	private: System::Windows::Forms::Button^  button_delete_selected;
	private: System::Windows::Forms::Label^  label_total_effects;
	private: System::Windows::Forms::Button^  button_refresh_table;
	public:

			 BindingSource^ EffBind = gcnew BindingSource();

		Effects_table(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Effects_table(loading^ load)
		{	

			InitializeComponent();

			this->load = load;
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Effects_table()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridViewEf;
	protected:

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
			this->advancedDataGridViewEf = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1_progress = (gcnew System::Windows::Forms::Label());
			this->button_select = (gcnew System::Windows::Forms::Button());
			this->button_unselect = (gcnew System::Windows::Forms::Button());
			this->button_delete_selected = (gcnew System::Windows::Forms::Button());
			this->label_total_effects = (gcnew System::Windows::Forms::Label());
			this->button_refresh_table = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridViewEf))->BeginInit();
			this->SuspendLayout();
			// 
			// advancedDataGridViewEf
			// 
			this->advancedDataGridViewEf->AllowUserToAddRows = false;
			this->advancedDataGridViewEf->AllowUserToDeleteRows = false;
			this->advancedDataGridViewEf->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridViewEf->FilterAndSortEnabled = true;
			this->advancedDataGridViewEf->Location = System::Drawing::Point(24, 46);
			this->advancedDataGridViewEf->Name = L"advancedDataGridViewEf";
			this->advancedDataGridViewEf->Size = System::Drawing::Size(1226, 707);
			this->advancedDataGridViewEf->TabIndex = 0;
			this->advancedDataGridViewEf->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Effects_table::advancedDataGridViewEf_CellDoubleClick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(24, 759);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(381, 23);
			this->progressBar1->TabIndex = 1;
			// 
			// label1_progress
			// 
			this->label1_progress->Location = System::Drawing::Point(423, 759);
			this->label1_progress->Name = L"label1_progress";
			this->label1_progress->Size = System::Drawing::Size(784, 23);
			this->label1_progress->TabIndex = 2;
			this->label1_progress->Text = L"label1";
			// 
			// button_select
			// 
			this->button_select->Location = System::Drawing::Point(24, 2);
			this->button_select->Name = L"button_select";
			this->button_select->Size = System::Drawing::Size(89, 21);
			this->button_select->TabIndex = 3;
			this->button_select->Text = L"select";
			this->button_select->UseVisualStyleBackColor = true;
			this->button_select->Click += gcnew System::EventHandler(this, &Effects_table::button_select_Click);
			// 
			// button_unselect
			// 
			this->button_unselect->Location = System::Drawing::Point(24, 23);
			this->button_unselect->Name = L"button_unselect";
			this->button_unselect->Size = System::Drawing::Size(89, 21);
			this->button_unselect->TabIndex = 3;
			this->button_unselect->Text = L"unselect";
			this->button_unselect->UseVisualStyleBackColor = true;
			this->button_unselect->Click += gcnew System::EventHandler(this, &Effects_table::button_unselect_Click);
			// 
			// button_delete_selected
			// 
			this->button_delete_selected->Location = System::Drawing::Point(119, 12);
			this->button_delete_selected->Name = L"button_delete_selected";
			this->button_delete_selected->Size = System::Drawing::Size(89, 21);
			this->button_delete_selected->TabIndex = 3;
			this->button_delete_selected->Text = L"delete selected";
			this->button_delete_selected->UseVisualStyleBackColor = true;
			this->button_delete_selected->Click += gcnew System::EventHandler(this, &Effects_table::button_delete_selected_Click);
			// 
			// label_total_effects
			// 
			this->label_total_effects->AutoSize = true;
			this->label_total_effects->Location = System::Drawing::Point(598, 9);
			this->label_total_effects->Name = L"label_total_effects";
			this->label_total_effects->Size = System::Drawing::Size(46, 13);
			this->label_total_effects->TabIndex = 4;
			this->label_total_effects->Text = L"Effects: ";
			// 
			// button_refresh_table
			// 
			this->button_refresh_table->Location = System::Drawing::Point(243, 12);
			this->button_refresh_table->Name = L"button_refresh_table";
			this->button_refresh_table->Size = System::Drawing::Size(161, 20);
			this->button_refresh_table->TabIndex = 5;
			this->button_refresh_table->Text = L"refresh table";
			this->button_refresh_table->UseVisualStyleBackColor = true;
			this->button_refresh_table->Click += gcnew System::EventHandler(this, &Effects_table::button_refresh_table_Click);
			// 
			// Effects_table
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1274, 791);
			this->Controls->Add(this->button_refresh_table);
			this->Controls->Add(this->label_total_effects);
			this->Controls->Add(this->button_unselect);
			this->Controls->Add(this->button_delete_selected);
			this->Controls->Add(this->button_select);
			this->Controls->Add(this->label1_progress);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->advancedDataGridViewEf);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Effects_table";
			this->Text = L"Effects_table";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Effects_table::Effects_table_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Effects_table::Effects_table_Load);
			this->Shown += gcnew System::EventHandler(this, &Effects_table::Effects_table_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridViewEf))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void EF_CreateDataTable()
	{
		DataColumn^ column;
		//0 number
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.Int32");
		column->ColumnName = "Num";
		column->ReadOnly = false;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

		//1 delete
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.Boolean");
		column->ColumnName = "Delete";
		column->ReadOnly = false;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

		//2 Effect name
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "EffectName";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

		//3 path
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "Path";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

		//4 textures in effect
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.Int32");
		column->ColumnName = "Textures in effect";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

		//5 Dead effect
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "DEAD";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

		//6 Exist in Ch
		column = gcnew DataColumn();
		column->DataType = System::Type::GetType("System.String");
		column->ColumnName = "Exist on META";
		column->ReadOnly = true;
		column->Unique = false;
		this->EffectsDataTable->Columns->Add(column);

	}

	private: System::Void EF_FillData()
{
	//loading^ loading_form = gcnew loading();
	//loading_form->Show();
		EF_CreateDataTable();

	int count = 0;
	for (auto& effect : particle_effects_XML)
	{
		count++;
		DataRow^ row = EffectsDataTable->NewRow();

		row[0] = count;
		row[1] = effect->partEff_to_delete;
		row[2] = MRSHL_stdstr_TO_Str(effect->partEff_name); //имя
		row[3] = MRSHL_stdstr_TO_Str(effect->partEff_string_path); //путь
		row[4] = effect->partEff_ParticleEffectLayers.size(); //текстур в эффекте
		row[5] = MRSHL_stdstr_TO_Str(effect->partEff_dead);	//мертвый ли эфеект
		row[6] = MRSHL_stdstr_TO_Str(effect->partEff_exist_on_meta? "+" : "-"); //есть ли на мете

		EffectsDataTable->Rows->Add(row);

	}



	EffBind->DataSource = EffectsDataTable;
	advancedDataGridViewEf->DataSource = EffBind;
	
	advancedDataGridViewEf->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
	advancedDataGridViewEf->AutoResizeColumn(0);
	advancedDataGridViewEf->AutoResizeColumn(1);
	advancedDataGridViewEf->AutoResizeColumn(2);
	advancedDataGridViewEf->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

}

	private: System::Void Ef_ColorDataGrid(Boolean problem)
{
	for (int i = advancedDataGridViewEf->Rows->Count - 1; i >= 0; i--)
	{
		

		if (Convert::ToBoolean(advancedDataGridViewEf->Rows[i]->Cells[1]->Value->ToString())) //если чекбокс
		//if (advancedDataGridView2->Rows[i]->Cells[8]->Value->ToString()=="-" || advancedDataGridView2->Rows[i]->Cells[9]->Value == 0 || advancedDataGridView2->Rows[i]->Cells[10]->Value == 0)
		{
			advancedDataGridViewEf->Rows[i]->DefaultCellStyle->BackColor = Color::MistyRose;
		}
		else
		{
			advancedDataGridViewEf->Rows[i]->DefaultCellStyle->BackColor = Color::Honeydew;
		}

	}
}

	private: System::Void Effects_table_Load(System::Object^  sender, System::EventArgs^  e) 
	{	
		this->EffBind->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &Effects_table::SBind_ListChanged);
		load = gcnew loading();
		load->label1->Text = "Filling table...";
		load->Show();
		load->label1->Update();
		
		
		EF_FillData();
		Ef_ColorDataGrid();
		load->Close();
		//Ef_ColorDataGrid(false);
		progressBar1->Hide();
		label1_progress->Hide();
	}

	private: System::Void button_select_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for each (DataGridViewRow^ row in advancedDataGridViewEf->SelectedRows)
		{
			if (row->Cells["Delete"]->Value != true)
			{
				row->Cells["Delete"]->Value = true;
				advancedDataGridViewEf->Update();
				advancedDataGridViewEf->Refresh();
				row->DefaultCellStyle->BackColor = Color::MistyRose;
			}
			else
				row->DefaultCellStyle->BackColor = Color::Honeydew;
		}
	}

	private: System::Void button_unselect_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for each (DataGridViewRow^ row in advancedDataGridViewEf->SelectedRows)
		{
			//Convert::ToBoolean(advancedDataGridView2->Rows[i]->Cells[1]->Value->ToString())
			if (Convert::ToBoolean(row->Cells[1]->Value->ToString()))
			{
				row->Cells[1]->Value = false;
				advancedDataGridViewEf->Update();
				advancedDataGridViewEf->Refresh();
				row->DefaultCellStyle->BackColor = Color::Honeydew;
			}
		}
	}

		 //переномировать DataTable
	private: System::Void ReNumDataTable()
	{
		for (int j = 0; j != EffectsDataTable->Rows->Count; j++)
		{
			DataRow^ row = EffectsDataTable->Rows[j];
			row["Num"] = j + 1;
		}
	}

	private: System::Void Ef_ColorDataGrid()
	{
		for (int i = advancedDataGridViewEf->Rows->Count - 1; i >= 0; i--)
		{
			if (advancedDataGridViewEf->Rows[i]->Cells[5]->Value->ToString() == "fully DEAD") 
				advancedDataGridViewEf->Rows[i]->DefaultCellStyle->BackColor = Color::MistyRose;
			if (advancedDataGridViewEf->Rows[i]->Cells[5]->Value->ToString() == "partially dead") 
				advancedDataGridViewEf->Rows[i]->DefaultCellStyle->BackColor = Color::LemonChiffon;
			if (advancedDataGridViewEf->Rows[i]->Cells[5]->Value->ToString() == "alive")
				advancedDataGridViewEf->Rows[i]->DefaultCellStyle->BackColor = Color::Honeydew;
		}
	}

		///////////////удалить отмеченные эффекты
	private: System::Void button_delete_selected_Click(System::Object^  sender, System::EventArgs^  e) 
	{	

		//int count_delete = 0;
		//////получить кол-во удаляемых текстур
		//for (int i = advancedDataGridViewEf->Rows->Count - 1; i >= 0; i--)
		//{
		//	if (Convert::ToBoolean(advancedDataGridViewEf->Rows[i]->Cells[1]->Value->ToString()) == true) //если чекбокс удалить
		//		count_delete++;
		//}

		//if (count_delete == 0)
		//{
		//	MessageBox::Show("Not selected for deleting", "Result");
		//	return;
		//}

		//String^ message = "Marked effects will be deleted. Proceed?";
		//String^ caption = "Deleting";
		//auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		//if (result == ::DialogResult::No)
		//{
		//	return;
		//}


		//boost::system::error_code ec;
		//progressBar1->Value = 0;
		//progressBar1->Show();
		//label1_progress->Show();
		//progressBar1->Maximum = count_delete;
		//LOG_IN_FILE(std::endl << std::endl<<"DELETING Effects"); 
		//LOG_IN_FILE("Num" << '\t' << "deleting_RESULT" << '\t' << "deleting_from" << '\t' << "deleting_what" << '\t' << "deleting_what(name)");
		//error_counter = 0;
		//
		//deleting_count = 0;
		//DateTime starttime = DateTime::Now;


		//for (int i = advancedDataGridViewEf->Rows->Count - 1; i >= 0; i--)
		//{
		//	if (Convert::ToBoolean(advancedDataGridViewEf->Rows[i]->Cells[1]->Value->ToString())) //если чекбокс удалить
		//	{	
		//		String^ path_DG = advancedDataGridViewEf->Rows[i]->Cells[3]->Value->ToString() + "/" + advancedDataGridViewEf->Rows[i]->Cells[2]->Value->ToString();
		//		std::string s_path = MRSHL_Str_TO_stdstr(path_DG);
		//		std::string eff_name = MRSHL_Str_TO_stdstr(advancedDataGridViewEf->Rows[i]->Cells[2]->Value->ToString());
		//		deleting_count++;

		//		fs::path path_effect = s_path;

		//		/*int a = eff_name.find("Match3");
		//		int u = path_effect.parent_path().stem().string().find("Match3");*/

		//		if (eff_name.find("Match3") != -1 || path_effect.parent_path().stem().string().find("Match3")!=-1)
		//		{	
		//			error_counter++;
		//			LOG_IN_FILE(deleting_count << "abort_deleting - Match3 effect " << '\t' << "direcoty" << '\t' << "effect_xml" << '\t' << s_path);
		//			continue;
		//		}

		//		

		//		if (advancedDataGridViewEf->Rows[i]->Cells[5]->Value->ToString() == "partially dead")
		//		{
		//			LOG_IN_FILE(deleting_count << '\t' << "canceled - partially dead" << '\t' << "-" << '\t' << "-" << '\t' << s_path);
		//			//обновить прогресс бар
		//			TimeSpan timespent = DateTime::Now - starttime;
		//			int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
		//			label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
		//			label1_progress->Update();
		//			progressBar1->Value = deleting_count;
		//			progressBar1->Value = progressBar1->Value - 1;
		//			continue;
		//		}
		//		if (advancedDataGridViewEf->Rows[i]->Cells[5]->Value->ToString() == "alive")
		//		{
		//			LOG_IN_FILE(deleting_count << '\t' << "canceled - alive" << '\t' << "-" << '\t' << "-" << '\t' << s_path);
		//			//обновить прогресс бар
		//			TimeSpan timespent = DateTime::Now - starttime;
		//			int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
		//			label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
		//			label1_progress->Update();
		//			progressBar1->Value = deleting_count;
		//			progressBar1->Value = progressBar1->Value - 1;
		//			continue;
		//		}
		//		if (advancedDataGridViewEf->Rows[i]->Cells[6]->Value->ToString() == "+")
		//		{
		//			LOG_IN_FILE(deleting_count << '\t' << "canceled - exist on meta" << '\t' << "-" << '\t' << "-" << '\t' << s_path);
		//			//обновить прогресс бар
		//			TimeSpan timespent = DateTime::Now - starttime;
		//			int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
		//			label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
		//			label1_progress->Update();
		//			progressBar1->Value = deleting_count;
		//			progressBar1->Value = progressBar1->Value - 1;
		//			continue;
		//		}
		//		DataGridViewRow^ row = advancedDataGridViewEf->Rows[i];

		//	
		//		
		//		
		//		//найти удаляемый эффект в контейнере
		//		ParticleEffect* eff = FindEffect(path_effect);
		//		////удалить файл
		//		fs::remove(path_effect, ec);
		//		LOG_IN_FILE(deleting_count << ec.message() << '\t' << "direcoty" << '\t' << "effect_xml"<<'\t'<< path_effect.string());
		//		if (ec != 0) //если не удалился ничего не делаем
		//		{
		//			error_counter++;
		//			//обновить прогресс бар
		//			TimeSpan timespent = DateTime::Now - starttime;
		//			int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
		//			label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
		//			label1_progress->Update();
		//			progressBar1->Value = deleting_count;
		//			progressBar1->Value = progressBar1->Value - 1;
		//			continue;
		//		}
		//		//удалить из контейнера
		//		auto it = std::find(particle_effects.begin(), particle_effects.end(), *eff);
		//		particle_effects.erase(it);
		//		//удаляем из advancedDataGridViewEf
		//		advancedDataGridViewEf->Rows->Remove(row);

		//		//удалить запись из common ээфекта
		//		DeleteEffectFromCommonFile(path_effect);

		//		//обновить прогресс бар
		//		TimeSpan timespent = DateTime::Now - starttime;
		//		int secondsremaining = timespent.TotalSeconds / progressBar1->Value * (progressBar1->Maximum - progressBar1->Value);
		//		label1_progress->Text = progressBar1->Value + "/" + progressBar1->Maximum + "  seconds remain: " + secondsremaining + "   " + path_DG;
		//		label1_progress->Update();
		//		progressBar1->Value = deleting_count;
		//		progressBar1->Value = progressBar1->Value - 1;

		//	}
		//}


		//RemoveEmptyEffectFolder();
		//ReNumDataTable();
		//
		//advancedDataGridViewEf->DataSource = nullptr;
		//advancedDataGridViewEf->Update();
		//advancedDataGridViewEf->Refresh();
		//
		//EffBind->RemoveFilter();
		//advancedDataGridViewEf->DataSource = EffBind;
		//advancedDataGridViewEf->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
		//advancedDataGridViewEf->AutoResizeColumn(0);
		//advancedDataGridViewEf->AutoResizeColumn(1);
		//advancedDataGridViewEf->AutoResizeColumn(2);
		//advancedDataGridViewEf->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

		//progressBar1->Hide();
		//label1_progress->Hide();

		//Ef_ColorDataGrid();

		//if (error_counter == 0)
		//{
		//	MessageBox::Show("All selected effects have been successfully removed", "Result");
		//}
		//else
		//{
		//	MessageBox::Show("Some effects (" + error_counter + ") have not been removed. Check Log_file :" + MRSHL_stdstr_TO_Str(path_LOG), "Result");
		//}
		

	}

	private: System::Void Effects_table_Shown(System::Object^  sender, System::EventArgs^  e) 
	{
		this->load->Close();
	}

	private: System::Void advancedDataGridViewEf_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{	
		String^ effect_path = advancedDataGridViewEf->CurrentRow->Cells[3]->Value->ToString() + "/" + advancedDataGridViewEf->CurrentRow->Cells[2]->Value->ToString();
		eff_details = gcnew Effect_detail(effect_path);
		eff_details->Show();
	}

	private: System::Void SBind_ListChanged(System::Object^ sender, ListChangedEventArgs^ e)
	{
		int count = this->EffBind->List->Count;
		std::stringstream is;
		is << count;
		std::string s_count;
		is >> s_count;
		s_count = "Total effects: " + s_count;
		label_total_effects->Text = MRSHL_stdstr_TO_Str(s_count);


		//ColorDataGrid(true);

	}

	private: System::Void button_refresh_table_Click(System::Object^  sender, System::EventArgs^  e) 
	{	

		particle_effects_XML.clear();
		CH_objects.clear();
		texture_particle_effect.clear();

		loading^ load1 = gcnew loading();

		load1->label1->Text = "Collecting chapter info...";
		load1->Update();
		load1->Show();
		load1->label1->Update();
		GetChapterData();
	

		load1->label1->Text = "Collecting particle effects...";
		load1->label1->Update();
		load1->Update();

		GetParticleEffectData();

		load1->label1->Text = "detection DEAD effects...";
		load1->label1->Update();
		load1->Update();

		Get_dead_effects();

		load1->Close();

		//effect_form = gcnew Effects_table();
		//effect_form->Show();
	}

	public: System::Void ShowMyself()
	{
		this->Show();
	}

	public: event EventHandler^ ClosingEffectTable;

	private: System::Void Effects_table_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		ClosingEffectTable(this, nullptr);
	}
};
}

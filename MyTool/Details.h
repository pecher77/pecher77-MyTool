#pragma once
#include "Effects_table.h"


namespace MyTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Details
	/// </summary>
	public ref class Details : public System::Windows::Forms::Form
	{
	
	public:	Effect_detail^ eff_details;
	public:	DataTable^ DataTable_GR;
	public:	DataTable^ DataTable_OL;
	public:	DataTable^ DataTable_CH;
	public:	DataTable^ DataTable_EF;

	public:	BindingSource^ Bind_GR;
	public:	BindingSource^ Bind_OL;
	public:	BindingSource^ Bind_CH;
	public:	BindingSource^ Bind_EF;
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView_CH;
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView_EF;
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView_OL;
	private: System::Windows::Forms::Label^  label4;
	private: Zuby::ADGV::AdvancedDataGridView^  advancedDataGridView_GR;
	private: System::Windows::Forms::Label^  label_size;

	private: TextureData* texture;
	public:

		Details(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		Details(String^ texture_path)
		{	
			
			InitializeComponent();

			this->texture_path = texture_path;
			//
			//TODO: Add the constructor code here
			//
		}

		Details(TextureData* d)
		{
			this->texture = d;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Details()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::String^ texture_path;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label_texture_name;
	private: System::Windows::Forms::Label^  label_texture_path;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label_resolution;



	private: System::Windows::Forms::ToolTip^  toolTip1;





	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label_texture_name = (gcnew System::Windows::Forms::Label());
			this->label_texture_path = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_resolution = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->advancedDataGridView_CH = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->advancedDataGridView_EF = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->advancedDataGridView_OL = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->advancedDataGridView_GR = (gcnew Zuby::ADGV::AdvancedDataGridView());
			this->label_size = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_CH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_EF))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_OL))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_GR))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(542, 542);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &Details::pictureBox1_DoubleClick);
			// 
			// label_texture_name
			// 
			this->label_texture_name->Location = System::Drawing::Point(560, 12);
			this->label_texture_name->Name = L"label_texture_name";
			this->label_texture_name->Size = System::Drawing::Size(270, 21);
			this->label_texture_name->TabIndex = 1;
			this->label_texture_name->Text = L"Texture Name";
			this->toolTip1->SetToolTip(this->label_texture_name, L"Texture name");
			// 
			// label_texture_path
			// 
			this->label_texture_path->Location = System::Drawing::Point(560, 30);
			this->label_texture_path->Name = L"label_texture_path";
			this->label_texture_path->Size = System::Drawing::Size(270, 21);
			this->label_texture_path->TabIndex = 1;
			this->label_texture_path->Text = L"Texture Path";
			this->toolTip1->SetToolTip(this->label_texture_path, L"Texture path");
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(563, 192);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ñontained in ObjectLibrary items:";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(563, 313);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(197, 21);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ñontained in repairs:";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(562, 435);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(197, 21);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Ñontained in ParticleEffects:";
			// 
			// label_resolution
			// 
			this->label_resolution->Location = System::Drawing::Point(561, 48);
			this->label_resolution->Name = L"label_resolution";
			this->label_resolution->Size = System::Drawing::Size(197, 21);
			this->label_resolution->TabIndex = 1;
			this->label_resolution->Text = L"Resolution";
			this->toolTip1->SetToolTip(this->label_resolution, L"Resolution");
			// 
			// advancedDataGridView_CH
			// 
			this->advancedDataGridView_CH->AllowUserToAddRows = false;
			this->advancedDataGridView_CH->AllowUserToDeleteRows = false;
			this->advancedDataGridView_CH->AllowUserToResizeRows = false;
			this->advancedDataGridView_CH->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView_CH->FilterAndSortEnabled = true;
			this->advancedDataGridView_CH->Location = System::Drawing::Point(564, 326);
			this->advancedDataGridView_CH->Name = L"advancedDataGridView_CH";
			this->advancedDataGridView_CH->Size = System::Drawing::Size(607, 106);
			this->advancedDataGridView_CH->TabIndex = 3;
			// 
			// advancedDataGridView_EF
			// 
			this->advancedDataGridView_EF->AllowUserToAddRows = false;
			this->advancedDataGridView_EF->AllowUserToDeleteRows = false;
			this->advancedDataGridView_EF->AllowUserToResizeRows = false;
			this->advancedDataGridView_EF->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView_EF->FilterAndSortEnabled = true;
			this->advancedDataGridView_EF->Location = System::Drawing::Point(564, 448);
			this->advancedDataGridView_EF->Name = L"advancedDataGridView_EF";
			this->advancedDataGridView_EF->Size = System::Drawing::Size(607, 106);
			this->advancedDataGridView_EF->TabIndex = 3;
			this->advancedDataGridView_EF->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Details::advancedDataGridView_EF_CellContentDoubleClick);
			// 
			// advancedDataGridView_OL
			// 
			this->advancedDataGridView_OL->AllowUserToAddRows = false;
			this->advancedDataGridView_OL->AllowUserToDeleteRows = false;
			this->advancedDataGridView_OL->AllowUserToResizeRows = false;
			this->advancedDataGridView_OL->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView_OL->FilterAndSortEnabled = true;
			this->advancedDataGridView_OL->Location = System::Drawing::Point(564, 205);
			this->advancedDataGridView_OL->Name = L"advancedDataGridView_OL";
			this->advancedDataGridView_OL->Size = System::Drawing::Size(607, 106);
			this->advancedDataGridView_OL->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(563, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(197, 19);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Ñontained in GemeFieldres ids:";
			// 
			// advancedDataGridView_GR
			// 
			this->advancedDataGridView_GR->AllowUserToAddRows = false;
			this->advancedDataGridView_GR->AllowUserToDeleteRows = false;
			this->advancedDataGridView_GR->AllowUserToResizeRows = false;
			this->advancedDataGridView_GR->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->advancedDataGridView_GR->FilterAndSortEnabled = true;
			this->advancedDataGridView_GR->Location = System::Drawing::Point(565, 104);
			this->advancedDataGridView_GR->Name = L"advancedDataGridView_GR";
			this->advancedDataGridView_GR->Size = System::Drawing::Size(607, 84);
			this->advancedDataGridView_GR->TabIndex = 3;
			// 
			// label_size
			// 
			this->label_size->Location = System::Drawing::Point(562, 67);
			this->label_size->Name = L"label_size";
			this->label_size->Size = System::Drawing::Size(197, 15);
			this->label_size->TabIndex = 1;
			this->label_size->Text = L"Size";
			// 
			// Details
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 556);
			this->Controls->Add(this->advancedDataGridView_EF);
			this->Controls->Add(this->advancedDataGridView_CH);
			this->Controls->Add(this->advancedDataGridView_OL);
			this->Controls->Add(this->advancedDataGridView_GR);
			this->Controls->Add(this->label_size);
			this->Controls->Add(this->label_resolution);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_texture_path);
			this->Controls->Add(this->label_texture_name);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Details";
			this->Text = L"Details";
			this->Load += gcnew System::EventHandler(this, &Details::Details_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_CH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_EF))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_OL))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advancedDataGridView_GR))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

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

	private: Image^ GetImageForData(String^ path)
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
				array<System::Byte>^ arr = imageToByteArray(image);
				return byteArrayToImage(arr);

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
	

			 //ñîçäàòü datatable
private: System::Void CreateDataTable_GR()
{	

	if (DataTable_GR != nullptr)
		DataTable_GR->Reset();

	DataColumn^ column;
	//0 number
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "Num";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_GR->Columns->Add(column);

	//1 id
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "id";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_GR->Columns->Add(column);

	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "filename";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_GR->Columns->Add(column);

	//2 atlas
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "atlas";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_GR->Columns->Add(column);

	//3 path
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "path";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_GR->Columns->Add(column);


}

private: System::Void CreateDataTable_OL()
{

	if (DataTable_OL != nullptr)
		DataTable_OL->Reset();

	DataColumn^ column;
	//0 number
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "Num";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

	//1 item_id
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "item_id";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);
	
	// 2 instanceClass
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "instClass";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

	//3 isIndoor
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "isIndoor";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

	//4 noRedesignDeformation
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "noRedesign";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

	//5 defaultZOrder
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "defZOrder";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

	//6 cluster
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "cluster";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

	//7 layers
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "layers";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_OL->Columns->Add(column);

}

private: System::Void CreateDataTable_CH()
{
	if (DataTable_CH != nullptr)
		DataTable_CH->Reset();


	DataColumn^ column;
	//0 number
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "Num";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

	//1 chapter_id
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "chapter_id";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

	// 2 repair
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "repair";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

	//3 step
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "step";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

	//4 hash_id
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "id";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

	//5 dataid
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "dataid";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

	//6 zOrder
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "zOrder";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_CH->Columns->Add(column);

}

private: System::Void CreateDataTable_EF()
{
	if (DataTable_EF != nullptr)
		DataTable_EF->Reset();


	DataColumn^ column;
	//0 number
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "Num";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_EF->Columns->Add(column);

	//1 filename
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "filename";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_EF->Columns->Add(column);

	// 2 path
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "path";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_EF->Columns->Add(column);


	//3 exist_in_CH
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "exist_in_CH";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_EF->Columns->Add(column);

	//4 dead
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.String");
	column->ColumnName = "dead";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_EF->Columns->Add(column);

	//5 layers
	column = gcnew DataColumn();
	column->DataType = System::Type::GetType("System.Int32");
	column->ColumnName = "layers";
	column->ReadOnly = false;
	column->Unique = false;
	this->DataTable_EF->Columns->Add(column);

	


}

private: System::Void Fill_DataTable_GR()
{
	DataTable_GR->Clear();

	

		int count = 0;
		
		for (auto& gr : texture->TD_GRs)
		{	
			DataRow^ row = DataTable_GR->NewRow();
			count++;
			row[0] = count;
			row[1] = MRSHL_stdstr_TO_Str(gr->gameFieldRes_id); //id
			row[2] = MRSHL_stdstr_TO_Str(gr->gameFieldRes_path_attr); //filename
			row[3] = MRSHL_stdstr_TO_Str(gr->gameFieldRes_texture_group_atlas); //atlas
			row[4] = MRSHL_stdstr_TO_Str(gr->gameFieldRes_path); //path
			DataTable_GR->Rows->Add(row);
		}

		Bind_GR->DataSource = nullptr;
		Bind_GR->DataSource = DataTable_GR;

		advancedDataGridView_GR->DataSource = nullptr;
		advancedDataGridView_GR->Update();
		advancedDataGridView_GR->Refresh();
		advancedDataGridView_GR->DataSource = Bind_GR;

}

private: System::Void Fill_DataTable_OL()
{
	DataTable_OL->Clear();

	//0 number
	//1 item_id
	//2 instanceClass
	//3 isIndoor
	//4 noRedesignDeformation
	//5 defaultZOrder
	//6 cluster
	//7 layers

	int count = 0;
	
	for (auto& gr : texture->TD_GRs)
	{
		for (auto& item : gr->gameFieldRes_unique_items)
		{	
			DataRow^ row = DataTable_OL->NewRow();
			count++;
			row[0] = count;
			row[1] = MRSHL_stdstr_TO_Str(item->objItem_item_id); //item_id
			row[2] = MRSHL_stdstr_TO_Str(item->objItem_instanceClass); //instanceClass
			row[3] = MRSHL_stdstr_TO_Str(item->objItem_isIndoor); //isIndoor
			row[4] = MRSHL_stdstr_TO_Str(item->objItem_noRedesignDeformation); //noRedesignDeformation
			row[5] = MRSHL_stdstr_TO_Str(item->objItem_defaultZOrder); //defaultZOrder
			row[6] = MRSHL_stdstr_TO_Str(item->objItem_cluster); //cluster
			row[7] = item->objItem_layers.size(); //layers

			DataTable_OL->Rows->Add(row);
		}
	}

	Bind_OL->DataSource = nullptr;
	Bind_OL->DataSource = DataTable_OL;

	advancedDataGridView_OL->DataSource = nullptr;
	advancedDataGridView_OL->Update();
	advancedDataGridView_OL->Refresh();
	advancedDataGridView_OL->DataSource = Bind_OL;

}

private: System::Void Fill_DataTable_CH()
{
	DataTable_CH->Clear();

	//0 number
	//1 chapter_id
	//2 repair
	//3 step
	//4 hash_id
	//5 dataid
	//6 zOrder


	int count = 0;
	
	for (auto& gr : texture->TD_GRs)
	{
		for (auto& item : gr->gameFieldRes_unique_items)
		{	
			for (auto& ch : item->objItem_ChapterDatas)
			{
				DataRow^ row = DataTable_CH->NewRow();
				count++;
				row[0] = count;
				row[1] = MRSHL_stdstr_TO_Str(ch->chData_storyInfo_chapter_id); //chapter_id
				row[2] = MRSHL_stdstr_TO_Str(ch->chData_storyInfo_repair); //repair
				row[3] = MRSHL_stdstr_TO_Str(ch->chData_storyInfo_step); //step
				row[4] = MRSHL_stdstr_TO_Str(ch->chData_id); //hash_id
				row[5] = MRSHL_stdstr_TO_Str(ch->chData_text_dataid); //dataid
				row[6] = MRSHL_stdstr_TO_Str(ch->chData_text_zOrder); //zOrder

				DataTable_CH->Rows->Add(row);
			}
		}
	}

	Bind_CH->DataSource = nullptr;
	Bind_CH->DataSource = DataTable_CH;

	advancedDataGridView_CH->DataSource = nullptr;
	advancedDataGridView_CH->Update();
	advancedDataGridView_CH->Refresh();
	advancedDataGridView_CH->DataSource = Bind_CH;

}

private: System::Void Fill_DataTable_EF()
{
	DataTable_EF->Clear();

	//0 number
	//1 filename
	//2 path
	//3 exist_in_CH
	//4 dead
	//5 layers


	int count = 0;
	
	for (auto& eff : texture->TD_effects)
	{
		DataRow^ row = DataTable_EF->NewRow();
				count++;
				row[0] = count;
				row[1] = MRSHL_stdstr_TO_Str(eff->partEff_name_p.filename().string()); //filename
				row[2] = MRSHL_stdstr_TO_Str(eff->partEff_name_p.parent_path().string()); //path
				row[3] = MRSHL_stdstr_TO_Str(eff->partEff_exist_in_CH); //exist_in_CH
				row[4] = MRSHL_stdstr_TO_Str(eff->partEff_dead); //dead
				row[5] = eff->partEff_ParticleEffectLayers.size(); //layers

				DataTable_EF->Rows->Add(row);
			
	}

	Bind_EF->DataSource = nullptr;
	Bind_EF->DataSource = DataTable_EF;

	advancedDataGridView_EF->DataSource = nullptr;
	advancedDataGridView_EF->Update();
	advancedDataGridView_EF->Refresh();
	advancedDataGridView_EF->DataSource = Bind_EF;

}

private: System::Void EditDataGrid_GR()
{
	advancedDataGridView_GR->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
	advancedDataGridView_GR->Columns[4]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
	
}

private: System::Void EditDataGrid_OL()
{
	advancedDataGridView_OL->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
	advancedDataGridView_OL->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
}

private: System::Void EditDataGrid_CH()
{
	advancedDataGridView_CH->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
	advancedDataGridView_CH->Columns[5]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
}

private: System::Void EditDataGrid_EF()
{
	advancedDataGridView_EF->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
	advancedDataGridView_EF->Columns[2]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
}

private: System::Void Details_Load(System::Object^  sender, System::EventArgs^  e)
{	
	pictureBox1->Image = GetImageForData(MRSHL_stdstr_TO_Str(texture->TD_texture_name.string()));


	if (!texture->TD_GRs.empty())
	{	
		this->DataTable_GR = gcnew DataTable("DataTable_GR");
		this->Bind_GR = gcnew BindingSource();
		
		CreateDataTable_GR();
		Fill_DataTable_GR();
		EditDataGrid_GR();

		bool has_items = false;
		bool has_chapters = false;
		for (auto& gr : texture->TD_GRs)
		{
			if (!gr->gameFieldRes_unique_items.empty())
			{
				has_items = true;

				for (auto& item : gr->gameFieldRes_unique_items)
				{
					if (!item->objItem_ChapterDatas.empty())
					{
						has_chapters = true;
					}
				}
			}
		}
		if (has_items)
		{
			this->DataTable_OL = gcnew DataTable("DataTable_OL");
			this->Bind_OL = gcnew BindingSource();
			CreateDataTable_OL();
			Fill_DataTable_OL();
			EditDataGrid_OL();
		}
		if (has_chapters)
		{
			this->DataTable_CH = gcnew DataTable("DataTable_CH");
			this->Bind_CH = gcnew BindingSource();
			CreateDataTable_CH();
			Fill_DataTable_CH();
			EditDataGrid_CH();

		}


	}
	
	if (!texture->TD_effects.empty())
	{
		this->DataTable_EF = gcnew DataTable("DataTable_EF");
		this->Bind_EF = gcnew BindingSource();
		CreateDataTable_EF();
		Fill_DataTable_EF();
		EditDataGrid_EF();
	}


	advancedDataGridView_GR->ClearSelection();
	advancedDataGridView_OL->ClearSelection();
	advancedDataGridView_CH->ClearSelection();
	advancedDataGridView_EF->ClearSelection();
	
	label_texture_name->Text = MRSHL_stdstr_TO_Str(texture->TD_texture_name.filename().string());
	label_texture_path->Text = MRSHL_stdstr_TO_Str(texture->TD_texture_name.string());
	label_resolution->Text = GetImageResolution(MRSHL_stdstr_TO_Str(texture->TD_texture_name.string()));
	std::stringstream is;
	is << texture->TD_size;
	std::string s_size;
	is >> s_size;
	label_size->Text = MRSHL_stdstr_TO_Str(s_size);

}
		
	
private: System::Void advancedDataGridView_EF_CellContentDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	String^ effect_path = advancedDataGridView_EF->CurrentRow->Cells[2]->Value->ToString() + "/" + advancedDataGridView_EF->CurrentRow->Cells[1]->Value->ToString();
	this->eff_details = gcnew Effect_detail(effect_path);
	eff_details->Show();
}

private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
{	
	String^ fileName = MRSHL_stdstr_TO_Str(texture->TD_s_texture_name);
	Process^ photoviewer = gcnew Process();
	photoviewer->Start(fileName);
	//FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
}

};
}

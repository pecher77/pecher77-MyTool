#pragma once
#include "MyForm3.h"


namespace MyTool 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//this->BackColor = Color::Aquamarine;
			//this->Width = 500;

			//
		}

		//MyForm(const MyForm %form):
		//	this(%form)
		//{	

		//
		//	//
		//	//TODO: Add the constructor code here
		//	//this->BackColor = Color::Aquamarine;
		//	//this->Width = 500;

		//	//
		//}
	private: System::Windows::Forms::Button^  button_find_next;
	public:

	public:
		loading^ load;
		int t = 0;
		int nb_result = 0;
		int result_symb = 0;
		int selected_start = 0;
		bool searched;
		Effects_table^ effect_form;
	private: System::Windows::Forms::Button^  button_find_prev;
	private: System::Windows::Forms::Button^  button_minus_chapter;
	private: System::Windows::Forms::Button^  button_plus_chapter;
	private: System::Windows::Forms::Button^  button_clear_list_chapter;

	private: System::Windows::Forms::TextBox^  textBox_LOGFILE;
	private: System::Windows::Forms::Label^  label_LOGFILE;

	private: System::Windows::Forms::Button^  button_define_unused_textures;
	private: System::Windows::Forms::TextBox^  textBox_textures_folder;

	private: System::Windows::Forms::Label^  label_Textures_folder;

	public: MyForm2^ form2_table;
	public: MyForm3^ form3_loading;

	private: System::Windows::Forms::ListBox^  listBox_clusters;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBox_ObLib;
	private: System::Windows::Forms::Button^  button_minus_cluster;
	private: System::Windows::Forms::Button^  button_plus_cluster;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Button^  button_effects_table;
	private: System::Windows::Forms::Button^  button_chapter_editor;
	private: System::Windows::Forms::TabControl^  Tabs;



	private: System::Windows::Forms::TabPage^  tabPage2;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  button_chooseChapter;

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ListBox^  listBox_CH;
	private: System::Windows::Forms::CheckBox^  checkbox_hash_id;
	private: System::Windows::Forms::CheckBox^  checkBox_all;
	private: System::Windows::Forms::TextBox^  textBox_ids;
	private: System::Windows::Forms::TextBox^  textBox_value;
	private: System::Windows::Forms::ComboBox^  comboBox_znak;
	private: System::Windows::Forms::ComboBox^  comboBox_attribute;
	private: System::Windows::Forms::TextBox^  textBox_search;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;

	private: System::Windows::Forms::Button^  button_tab2_choose_ch;
	private: System::Windows::Forms::Button^  button_tab2_plus_ch;
	private: System::Windows::Forms::Button^  button_tab2_minus_ch;
	private: System::Windows::Forms::Button^  button_tab2_clear_ch;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  button_change_attribute;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::ComboBox^  comboBox_repair;
	private: System::Windows::Forms::ComboBox^  comboBox_step;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::Label^  label_repair;
	private: System::Windows::Forms::Label^  label3;




	public:
		int selected_end = 0;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textbox_ProjectPath;
	protected:


	private: System::Windows::Forms::Label^  label_Project;


	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::TextBox^  textBox_GamefieldPath;




	private: System::Windows::Forms::Label^  label_GamefieldPath;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::ListBox^  listBox_Chapters;


	private: System::Windows::Forms::TextBox^  textBox_repairsFolder;

	private: System::Windows::Forms::Label^  label_repairsFolder;



	private: System::Windows::Forms::RichTextBox^  richTextBox_showdata;

	private: System::Windows::Forms::Button^  button_search;
	private: System::ComponentModel::IContainer^  components;


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
			this->label_Project = (gcnew System::Windows::Forms::Label());
			this->label_GamefieldPath = (gcnew System::Windows::Forms::Label());
			this->label_repairsFolder = (gcnew System::Windows::Forms::Label());
			this->textbox_ProjectPath = (gcnew System::Windows::Forms::TextBox());
			this->textBox_GamefieldPath = (gcnew System::Windows::Forms::TextBox());
			this->textBox_repairsFolder = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->listBox_Chapters = (gcnew System::Windows::Forms::ListBox());
			this->richTextBox_showdata = (gcnew System::Windows::Forms::RichTextBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->button_find_next = (gcnew System::Windows::Forms::Button());
			this->button_find_prev = (gcnew System::Windows::Forms::Button());
			this->button_minus_chapter = (gcnew System::Windows::Forms::Button());
			this->button_plus_chapter = (gcnew System::Windows::Forms::Button());
			this->button_clear_list_chapter = (gcnew System::Windows::Forms::Button());
			this->textBox_LOGFILE = (gcnew System::Windows::Forms::TextBox());
			this->label_LOGFILE = (gcnew System::Windows::Forms::Label());
			this->button_define_unused_textures = (gcnew System::Windows::Forms::Button());
			this->textBox_textures_folder = (gcnew System::Windows::Forms::TextBox());
			this->label_Textures_folder = (gcnew System::Windows::Forms::Label());
			this->listBox_clusters = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox_ObLib = (gcnew System::Windows::Forms::ListBox());
			this->button_minus_cluster = (gcnew System::Windows::Forms::Button());
			this->button_plus_cluster = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button_tab2_clear_ch = (gcnew System::Windows::Forms::Button());
			this->button_tab2_minus_ch = (gcnew System::Windows::Forms::Button());
			this->button_tab2_plus_ch = (gcnew System::Windows::Forms::Button());
			this->button_effects_table = (gcnew System::Windows::Forms::Button());
			this->button_chapter_editor = (gcnew System::Windows::Forms::Button());
			this->Tabs = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_chooseChapter = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->listBox_CH = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_tab2_choose_ch = (gcnew System::Windows::Forms::Button());
			this->button_change_attribute = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->comboBox_attribute = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_znak = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_value = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBox_all = (gcnew System::Windows::Forms::CheckBox());
			this->checkbox_hash_id = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->comboBox_repair = (gcnew System::Windows::Forms::ComboBox());
			this->label_repair = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->comboBox_step = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_ids = (gcnew System::Windows::Forms::TextBox());
			this->textBox_search = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Tabs->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_Project
			// 
			this->label_Project->BackColor = System::Drawing::SystemColors::Info;
			this->label_Project->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_Project->Location = System::Drawing::Point(72, 0);
			this->label_Project->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Project->Name = L"label_Project";
			this->label_Project->Size = System::Drawing::Size(85, 29);
			this->label_Project->TabIndex = 2;
			this->label_Project->Text = L"Project Library";
			this->toolTip1->SetToolTip(this->label_Project, L"Choose project path to construct all pathes");
			// 
			// label_GamefieldPath
			// 
			this->label_GamefieldPath->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_GamefieldPath->Location = System::Drawing::Point(72, 29);
			this->label_GamefieldPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_GamefieldPath->Name = L"label_GamefieldPath";
			this->label_GamefieldPath->Size = System::Drawing::Size(85, 29);
			this->label_GamefieldPath->TabIndex = 2;
			this->label_GamefieldPath->Text = L"Resources.xml";
			// 
			// label_repairsFolder
			// 
			this->label_repairsFolder->AutoSize = true;
			this->label_repairsFolder->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_repairsFolder->Location = System::Drawing::Point(69, 87);
			this->label_repairsFolder->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_repairsFolder->Name = L"label_repairsFolder";
			this->label_repairsFolder->Size = System::Drawing::Size(88, 29);
			this->label_repairsFolder->TabIndex = 2;
			this->label_repairsFolder->Text = L"base_mm/repairs";
			// 
			// textbox_ProjectPath
			// 
			this->textbox_ProjectPath->Dock = System::Windows::Forms::DockStyle::Left;
			this->textbox_ProjectPath->Location = System::Drawing::Point(165, 4);
			this->textbox_ProjectPath->Margin = System::Windows::Forms::Padding(4);
			this->textbox_ProjectPath->Name = L"textbox_ProjectPath";
			this->textbox_ProjectPath->Size = System::Drawing::Size(345, 20);
			this->textbox_ProjectPath->TabIndex = 0;
			this->textbox_ProjectPath->TabStop = false;
			this->textbox_ProjectPath->DoubleClick += gcnew System::EventHandler(this, &MyForm::textbox_ProjectPath_DoubleClick);
			this->textbox_ProjectPath->Leave += gcnew System::EventHandler(this, &MyForm::textbox_ProjectPath_Leave);
			// 
			// textBox_GamefieldPath
			// 
			this->textBox_GamefieldPath->Dock = System::Windows::Forms::DockStyle::Left;
			this->textBox_GamefieldPath->Location = System::Drawing::Point(165, 33);
			this->textBox_GamefieldPath->Margin = System::Windows::Forms::Padding(4);
			this->textBox_GamefieldPath->Name = L"textBox_GamefieldPath";
			this->textBox_GamefieldPath->ReadOnly = true;
			this->textBox_GamefieldPath->Size = System::Drawing::Size(345, 20);
			this->textBox_GamefieldPath->TabIndex = 3;
			this->toolTip1->SetToolTip(this->textBox_GamefieldPath, L"click to file to see xml");
			this->textBox_GamefieldPath->Click += gcnew System::EventHandler(this, &MyForm::textBox_GamefieldPath_Click);
			this->textBox_GamefieldPath->DoubleClick += gcnew System::EventHandler(this, &MyForm::textBox_GamefieldPath_DoubleClick);
			this->textBox_GamefieldPath->Leave += gcnew System::EventHandler(this, &MyForm::textBox_GamefieldPath_Leave);
			// 
			// textBox_repairsFolder
			// 
			this->textBox_repairsFolder->Dock = System::Windows::Forms::DockStyle::Left;
			this->textBox_repairsFolder->Location = System::Drawing::Point(165, 91);
			this->textBox_repairsFolder->Margin = System::Windows::Forms::Padding(4);
			this->textBox_repairsFolder->Name = L"textBox_repairsFolder";
			this->textBox_repairsFolder->ReadOnly = true;
			this->textBox_repairsFolder->Size = System::Drawing::Size(345, 20);
			this->textBox_repairsFolder->TabIndex = 3;
			this->textBox_repairsFolder->DoubleClick += gcnew System::EventHandler(this, &MyForm::textBox_repairsFolder_DoubleClick);
			this->textBox_repairsFolder->Leave += gcnew System::EventHandler(this, &MyForm::textBox_repairsFolder_Leave);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// listBox_Chapters
			// 
			this->listBox_Chapters->Dock = System::Windows::Forms::DockStyle::Left;
			this->listBox_Chapters->FormattingEnabled = true;
			this->listBox_Chapters->Location = System::Drawing::Point(165, 120);
			this->listBox_Chapters->Margin = System::Windows::Forms::Padding(4);
			this->listBox_Chapters->Name = L"listBox_Chapters";
			this->listBox_Chapters->Size = System::Drawing::Size(345, 112);
			this->listBox_Chapters->TabIndex = 5;
			this->toolTip1->SetToolTip(this->listBox_Chapters, L"click to file to see xml");
			this->listBox_Chapters->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox_Chapters_SelectedIndexChanged);
			// 
			// richTextBox_showdata
			// 
			this->tableLayoutPanel5->SetColumnSpan(this->richTextBox_showdata, 4);
			this->richTextBox_showdata->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox_showdata->Location = System::Drawing::Point(4, 34);
			this->richTextBox_showdata->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox_showdata->Name = L"richTextBox_showdata";
			this->richTextBox_showdata->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->richTextBox_showdata->Size = System::Drawing::Size(562, 391);
			this->richTextBox_showdata->TabIndex = 7;
			this->richTextBox_showdata->Text = L"Choose file to show data";
			this->richTextBox_showdata->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox_showdata_TextChanged);
			// 
			// button_search
			// 
			this->button_search->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_search->Location = System::Drawing::Point(334, 4);
			this->button_search->Margin = System::Windows::Forms::Padding(4);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(72, 22);
			this->button_search->TabIndex = 8;
			this->button_search->Text = L"search";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MyForm::button_search_Click);
			// 
			// button_find_next
			// 
			this->button_find_next->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_find_next->Location = System::Drawing::Point(414, 4);
			this->button_find_next->Margin = System::Windows::Forms::Padding(4);
			this->button_find_next->Name = L"button_find_next";
			this->button_find_next->Size = System::Drawing::Size(65, 22);
			this->button_find_next->TabIndex = 8;
			this->button_find_next->Text = L"find next";
			this->button_find_next->UseVisualStyleBackColor = true;
			this->button_find_next->Click += gcnew System::EventHandler(this, &MyForm::button_next_search_Click);
			// 
			// button_find_prev
			// 
			this->button_find_prev->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_find_prev->Location = System::Drawing::Point(487, 4);
			this->button_find_prev->Margin = System::Windows::Forms::Padding(4);
			this->button_find_prev->Name = L"button_find_prev";
			this->button_find_prev->Size = System::Drawing::Size(79, 22);
			this->button_find_prev->TabIndex = 8;
			this->button_find_prev->Text = L"find prev";
			this->button_find_prev->UseVisualStyleBackColor = true;
			this->button_find_prev->Click += gcnew System::EventHandler(this, &MyForm::button_find_prev_Click);
			// 
			// button_minus_chapter
			// 
			this->button_minus_chapter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_minus_chapter->Location = System::Drawing::Point(43, 4);
			this->button_minus_chapter->Margin = System::Windows::Forms::Padding(4);
			this->button_minus_chapter->Name = L"button_minus_chapter";
			this->button_minus_chapter->Size = System::Drawing::Size(31, 31);
			this->button_minus_chapter->TabIndex = 9;
			this->button_minus_chapter->Text = L"-";
			this->toolTip1->SetToolTip(this->button_minus_chapter, L"remove chapter file");
			this->button_minus_chapter->UseVisualStyleBackColor = true;
			this->button_minus_chapter->Click += gcnew System::EventHandler(this, &MyForm::button_minus_chapter_Click);
			// 
			// button_plus_chapter
			// 
			this->button_plus_chapter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_plus_chapter->Location = System::Drawing::Point(4, 4);
			this->button_plus_chapter->Margin = System::Windows::Forms::Padding(4);
			this->button_plus_chapter->Name = L"button_plus_chapter";
			this->button_plus_chapter->Size = System::Drawing::Size(31, 31);
			this->button_plus_chapter->TabIndex = 9;
			this->button_plus_chapter->Text = L"+";
			this->toolTip1->SetToolTip(this->button_plus_chapter, L"add chapter file");
			this->button_plus_chapter->UseVisualStyleBackColor = true;
			this->button_plus_chapter->Click += gcnew System::EventHandler(this, &MyForm::button_plus_chapter_Click);
			// 
			// button_clear_list_chapter
			// 
			this->button_clear_list_chapter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_clear_list_chapter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_clear_list_chapter->Location = System::Drawing::Point(82, 4);
			this->button_clear_list_chapter->Margin = System::Windows::Forms::Padding(4);
			this->button_clear_list_chapter->Name = L"button_clear_list_chapter";
			this->button_clear_list_chapter->Size = System::Drawing::Size(39, 31);
			this->button_clear_list_chapter->TabIndex = 9;
			this->button_clear_list_chapter->Text = L"clear";
			this->toolTip1->SetToolTip(this->button_clear_list_chapter, L"remove all");
			this->button_clear_list_chapter->UseVisualStyleBackColor = true;
			this->button_clear_list_chapter->Click += gcnew System::EventHandler(this, &MyForm::button_clear_list_chapter_Click);
			// 
			// textBox_LOGFILE
			// 
			this->textBox_LOGFILE->Dock = System::Windows::Forms::DockStyle::Left;
			this->textBox_LOGFILE->Location = System::Drawing::Point(164, 388);
			this->textBox_LOGFILE->Name = L"textBox_LOGFILE";
			this->textBox_LOGFILE->Size = System::Drawing::Size(346, 20);
			this->textBox_LOGFILE->TabIndex = 11;
			this->textBox_LOGFILE->Text = L"D:\\LOG_FILE.txt";
			this->toolTip1->SetToolTip(this->textBox_LOGFILE, L"extended program execution result");
			this->textBox_LOGFILE->Leave += gcnew System::EventHandler(this, &MyForm::textBox_LOGFILE_Leave);
			// 
			// label_LOGFILE
			// 
			this->label_LOGFILE->AutoSize = true;
			this->label_LOGFILE->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_LOGFILE->Location = System::Drawing::Point(86, 385);
			this->label_LOGFILE->Name = L"label_LOGFILE";
			this->label_LOGFILE->Size = System::Drawing::Size(72, 35);
			this->label_LOGFILE->TabIndex = 12;
			this->label_LOGFILE->Text = L"LOG_file path";
			this->toolTip1->SetToolTip(this->label_LOGFILE, L"extended program execution result");
			// 
			// button_define_unused_textures
			// 
			this->button_define_unused_textures->Location = System::Drawing::Point(188, 3);
			this->button_define_unused_textures->Name = L"button_define_unused_textures";
			this->button_define_unused_textures->Size = System::Drawing::Size(130, 27);
			this->button_define_unused_textures->TabIndex = 14;
			this->button_define_unused_textures->Text = L"define unused textures";
			this->button_define_unused_textures->UseVisualStyleBackColor = true;
			this->button_define_unused_textures->Click += gcnew System::EventHandler(this, &MyForm::button_define_unused_textures_Click);
			// 
			// textBox_textures_folder
			// 
			this->textBox_textures_folder->Dock = System::Windows::Forms::DockStyle::Left;
			this->textBox_textures_folder->Location = System::Drawing::Point(165, 62);
			this->textBox_textures_folder->Margin = System::Windows::Forms::Padding(4);
			this->textBox_textures_folder->Name = L"textBox_textures_folder";
			this->textBox_textures_folder->ReadOnly = true;
			this->textBox_textures_folder->Size = System::Drawing::Size(345, 20);
			this->textBox_textures_folder->TabIndex = 3;
			this->textBox_textures_folder->DoubleClick += gcnew System::EventHandler(this, &MyForm::textBox_textures_folder_DoubleClick);
			this->textBox_textures_folder->Leave += gcnew System::EventHandler(this, &MyForm::textBox_textures_folder_Leave);
			// 
			// label_Textures_folder
			// 
			this->label_Textures_folder->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_Textures_folder->Location = System::Drawing::Point(6, 58);
			this->label_Textures_folder->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_Textures_folder->Name = L"label_Textures_folder";
			this->label_Textures_folder->Size = System::Drawing::Size(151, 29);
			this->label_Textures_folder->TabIndex = 2;
			this->label_Textures_folder->Text = L"base_mm/textures/Gamefield/static";
			// 
			// listBox_clusters
			// 
			this->listBox_clusters->Dock = System::Windows::Forms::DockStyle::Left;
			this->listBox_clusters->FormattingEnabled = true;
			this->listBox_clusters->Location = System::Drawing::Point(165, 240);
			this->listBox_clusters->Margin = System::Windows::Forms::Padding(4);
			this->listBox_clusters->Name = L"listBox_clusters";
			this->listBox_clusters->Size = System::Drawing::Size(345, 54);
			this->listBox_clusters->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->tableLayoutPanel3->SetColumnSpan(this->label1, 2);
			this->label1->Location = System::Drawing::Point(4, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"base_mm/%clusters";
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Right;
			this->label2->Location = System::Drawing::Point(76, 298);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 48);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ObjectLibrary.xml";
			// 
			// listBox_ObLib
			// 
			this->listBox_ObLib->Dock = System::Windows::Forms::DockStyle::Left;
			this->listBox_ObLib->FormattingEnabled = true;
			this->listBox_ObLib->Location = System::Drawing::Point(165, 302);
			this->listBox_ObLib->Margin = System::Windows::Forms::Padding(4);
			this->listBox_ObLib->Name = L"listBox_ObLib";
			this->listBox_ObLib->Size = System::Drawing::Size(345, 40);
			this->listBox_ObLib->TabIndex = 5;
			this->toolTip1->SetToolTip(this->listBox_ObLib, L"click to file to see xml");
			this->listBox_ObLib->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox_ObLib_SelectedIndexChanged);
			// 
			// button_minus_cluster
			// 
			this->button_minus_cluster->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_minus_cluster->Location = System::Drawing::Point(59, 26);
			this->button_minus_cluster->Margin = System::Windows::Forms::Padding(4);
			this->button_minus_cluster->Name = L"button_minus_cluster";
			this->button_minus_cluster->Size = System::Drawing::Size(45, 26);
			this->button_minus_cluster->TabIndex = 9;
			this->button_minus_cluster->Text = L"-";
			this->toolTip1->SetToolTip(this->button_minus_cluster, L"remove cluster folder");
			this->button_minus_cluster->UseVisualStyleBackColor = true;
			this->button_minus_cluster->Click += gcnew System::EventHandler(this, &MyForm::button_minus_cluster_Click);
			// 
			// button_plus_cluster
			// 
			this->button_plus_cluster->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_plus_cluster->Location = System::Drawing::Point(4, 26);
			this->button_plus_cluster->Margin = System::Windows::Forms::Padding(4);
			this->button_plus_cluster->Name = L"button_plus_cluster";
			this->button_plus_cluster->Size = System::Drawing::Size(47, 26);
			this->button_plus_cluster->TabIndex = 9;
			this->button_plus_cluster->Text = L"+";
			this->toolTip1->SetToolTip(this->button_plus_cluster, L"add cluster folder");
			this->button_plus_cluster->UseVisualStyleBackColor = true;
			this->button_plus_cluster->Click += gcnew System::EventHandler(this, &MyForm::button_plus_cluster_Click);
			// 
			// button_tab2_clear_ch
			// 
			this->button_tab2_clear_ch->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_tab2_clear_ch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_tab2_clear_ch->Location = System::Drawing::Point(70, 4);
			this->button_tab2_clear_ch->Margin = System::Windows::Forms::Padding(4);
			this->button_tab2_clear_ch->Name = L"button_tab2_clear_ch";
			this->button_tab2_clear_ch->Size = System::Drawing::Size(97, 19);
			this->button_tab2_clear_ch->TabIndex = 13;
			this->button_tab2_clear_ch->Text = L"clear";
			this->toolTip1->SetToolTip(this->button_tab2_clear_ch, L"remove all");
			this->button_tab2_clear_ch->UseVisualStyleBackColor = true;
			this->button_tab2_clear_ch->Click += gcnew System::EventHandler(this, &MyForm::button_tab2_clear_ch_Click);
			// 
			// button_tab2_minus_ch
			// 
			this->button_tab2_minus_ch->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_tab2_minus_ch->Location = System::Drawing::Point(37, 4);
			this->button_tab2_minus_ch->Margin = System::Windows::Forms::Padding(4);
			this->button_tab2_minus_ch->Name = L"button_tab2_minus_ch";
			this->button_tab2_minus_ch->Size = System::Drawing::Size(25, 19);
			this->button_tab2_minus_ch->TabIndex = 12;
			this->button_tab2_minus_ch->Text = L"-";
			this->toolTip1->SetToolTip(this->button_tab2_minus_ch, L"remove chapter file");
			this->button_tab2_minus_ch->UseVisualStyleBackColor = true;
			this->button_tab2_minus_ch->Click += gcnew System::EventHandler(this, &MyForm::button_tab2_minus_ch_Click);
			// 
			// button_tab2_plus_ch
			// 
			this->button_tab2_plus_ch->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_tab2_plus_ch->Location = System::Drawing::Point(4, 4);
			this->button_tab2_plus_ch->Margin = System::Windows::Forms::Padding(4);
			this->button_tab2_plus_ch->Name = L"button_tab2_plus_ch";
			this->button_tab2_plus_ch->Size = System::Drawing::Size(25, 19);
			this->button_tab2_plus_ch->TabIndex = 10;
			this->button_tab2_plus_ch->Text = L"+";
			this->toolTip1->SetToolTip(this->button_tab2_plus_ch, L"add chapter file");
			this->button_tab2_plus_ch->UseVisualStyleBackColor = true;
			this->button_tab2_plus_ch->Click += gcnew System::EventHandler(this, &MyForm::button_tab2_plus_ch_Click);
			// 
			// button_effects_table
			// 
			this->button_effects_table->Location = System::Drawing::Point(3, 3);
			this->button_effects_table->Name = L"button_effects_table";
			this->button_effects_table->Size = System::Drawing::Size(160, 27);
			this->button_effects_table->TabIndex = 14;
			this->button_effects_table->Text = L"define unused particle effects";
			this->button_effects_table->UseVisualStyleBackColor = true;
			this->button_effects_table->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button_chapter_editor
			// 
			this->button_chapter_editor->BackColor = System::Drawing::SystemColors::Highlight;
			this->button_chapter_editor->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_chapter_editor->Location = System::Drawing::Point(64, 349);
			this->button_chapter_editor->Name = L"button_chapter_editor";
			this->button_chapter_editor->Size = System::Drawing::Size(94, 33);
			this->button_chapter_editor->TabIndex = 14;
			this->button_chapter_editor->Text = L"chapter editor (в разработке)";
			this->button_chapter_editor->UseVisualStyleBackColor = false;
			this->button_chapter_editor->Click += gcnew System::EventHandler(this, &MyForm::button_chapter_editor_Click);
			// 
			// Tabs
			// 
			this->Tabs->Controls->Add(this->tabPage2);
			this->Tabs->Controls->Add(this->tabPage1);
			this->Tabs->Location = System::Drawing::Point(9, 4);
			this->Tabs->Name = L"Tabs";
			this->Tabs->SelectedIndex = 0;
			this->Tabs->Size = System::Drawing::Size(986, 451);
			this->Tabs->TabIndex = 15;
			this->Tabs->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Tabs_SelectedIndexChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tableLayoutPanel1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(978, 425);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Pathes";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				161)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				440)));
			this->tableLayoutPanel1->Controls->Add(this->label_repairsFolder, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_Project, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->textbox_ProjectPath, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_GamefieldPath, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_LOGFILE, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->label_LOGFILE, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox_GamefieldPath, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_textures_folder, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_Textures_folder, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_repairsFolder, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->listBox_Chapters, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->listBox_clusters, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->listBox_ObLib, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->button_chapter_editor, 0, 7);
			this->tableLayoutPanel1->Location = System::Drawing::Point(6, 9);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 9;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.064807F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.069779F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.069779F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.064807F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.78255F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.91459F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.51302F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.450892F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.069779F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(517, 420);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				47)));
			this->tableLayoutPanel2->Controls->Add(this->button_plus_chapter, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button_clear_list_chapter, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->button_minus_chapter, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->button_chooseChapter, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->tableLayoutPanel2->Location = System::Drawing::Point(33, 119);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.93976F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 65.06024F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(125, 114);
			this->tableLayoutPanel2->TabIndex = 6;
			// 
			// button_chooseChapter
			// 
			this->tableLayoutPanel2->SetColumnSpan(this->button_chooseChapter, 3);
			this->button_chooseChapter->Location = System::Drawing::Point(4, 43);
			this->button_chooseChapter->Margin = System::Windows::Forms::Padding(4);
			this->button_chooseChapter->Name = L"button_chooseChapter";
			this->button_chooseChapter->Size = System::Drawing::Size(117, 36);
			this->button_chooseChapter->TabIndex = 4;
			this->button_chooseChapter->Text = L"Choose Chapter xml files (multiple select)";
			this->button_chooseChapter->UseVisualStyleBackColor = true;
			this->button_chooseChapter->Click += gcnew System::EventHandler(this, &MyForm::button_chooseChapter_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.92593F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.07407F)));
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->button_plus_cluster, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->button_minus_cluster, 1, 1);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->tableLayoutPanel3->Location = System::Drawing::Point(50, 239);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40.57971F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 59.42029F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(108, 56);
			this->tableLayoutPanel3->TabIndex = 7;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.6F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.4F)));
			this->tableLayoutPanel4->Controls->Add(this->button_define_unused_textures, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->button_effects_table, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(164, 349);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(346, 33);
			this->tableLayoutPanel4->TabIndex = 15;
			// 
			// tabPage1
			// 
			this->tabPage1->AllowDrop = true;
			this->tabPage1->Controls->Add(this->tableLayoutPanel6);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(978, 425);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Change value of CH attribute ";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				45.84139F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				54.15861F)));
			this->tableLayoutPanel6->Controls->Add(this->listBox_CH, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel7, 0, 6);
			this->tableLayoutPanel6->Controls->Add(this->button_change_attribute, 1, 6);
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel8, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel11, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel9, 1, 2);
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel10, 1, 3);
			this->tableLayoutPanel6->Controls->Add(this->textBox_ids, 1, 4);
			this->tableLayoutPanel6->Location = System::Drawing::Point(6, 6);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 7;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58.49057F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.50943F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 36)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 117)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 57)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(517, 423);
			this->tableLayoutPanel6->TabIndex = 12;
			// 
			// listBox_CH
			// 
			this->listBox_CH->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox_CH->FormattingEnabled = true;
			this->listBox_CH->Location = System::Drawing::Point(3, 3);
			this->listBox_CH->Name = L"listBox_CH";
			this->tableLayoutPanel6->SetRowSpan(this->listBox_CH, 6);
			this->listBox_CH->Size = System::Drawing::Size(230, 352);
			this->listBox_CH->TabIndex = 1;
			this->listBox_CH->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox_CH_SelectedIndexChanged);
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 3;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				105)));
			this->tableLayoutPanel7->Controls->Add(this->button_tab2_choose_ch, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->button_tab2_clear_ch, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->button_tab2_plus_ch, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->button_tab2_minus_ch, 1, 0);
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 361);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.27586F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.72414F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(171, 58);
			this->tableLayoutPanel7->TabIndex = 15;
			// 
			// button_tab2_choose_ch
			// 
			this->tableLayoutPanel7->SetColumnSpan(this->button_tab2_choose_ch, 3);
			this->button_tab2_choose_ch->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_tab2_choose_ch->Location = System::Drawing::Point(4, 31);
			this->button_tab2_choose_ch->Margin = System::Windows::Forms::Padding(4);
			this->button_tab2_choose_ch->Name = L"button_tab2_choose_ch";
			this->button_tab2_choose_ch->Size = System::Drawing::Size(163, 23);
			this->button_tab2_choose_ch->TabIndex = 14;
			this->button_tab2_choose_ch->Text = L"Choose Chapter xml files (multiple select)";
			this->button_tab2_choose_ch->UseVisualStyleBackColor = true;
			this->button_tab2_choose_ch->Click += gcnew System::EventHandler(this, &MyForm::button_tab2_choose_ch_Click);
			// 
			// button_change_attribute
			// 
			this->button_change_attribute->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_change_attribute->Location = System::Drawing::Point(239, 361);
			this->button_change_attribute->Name = L"button_change_attribute";
			this->button_change_attribute->Size = System::Drawing::Size(275, 59);
			this->button_change_attribute->TabIndex = 13;
			this->button_change_attribute->Text = L"Change attribute";
			this->button_change_attribute->UseVisualStyleBackColor = true;
			this->button_change_attribute->Click += gcnew System::EventHandler(this, &MyForm::button_change_attribute_Click);
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 3;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel8->Controls->Add(this->comboBox_attribute, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->comboBox_znak, 1, 0);
			this->tableLayoutPanel8->Controls->Add(this->textBox_value, 2, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(239, 3);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(275, 33);
			this->tableLayoutPanel8->TabIndex = 18;
			// 
			// comboBox_attribute
			// 
			this->comboBox_attribute->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox_attribute->FormattingEnabled = true;
			this->comboBox_attribute->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"m", L"rand", L"x", L"y", L"zOrder",
					L"iso_uL", L"iso_uR", L"iso_x", L"iso_y", L"iso_z"
			});
			this->comboBox_attribute->Location = System::Drawing::Point(3, 3);
			this->comboBox_attribute->Name = L"comboBox_attribute";
			this->comboBox_attribute->Size = System::Drawing::Size(94, 21);
			this->comboBox_attribute->TabIndex = 7;
			this->comboBox_attribute->Text = L"attribute";
			this->comboBox_attribute->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_attribute_SelectedIndexChanged_1);
			// 
			// comboBox_znak
			// 
			this->comboBox_znak->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox_znak->FormattingEnabled = true;
			this->comboBox_znak->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"+", L"-", L"*", L"/", L"=" });
			this->comboBox_znak->Location = System::Drawing::Point(103, 3);
			this->comboBox_znak->Name = L"comboBox_znak";
			this->comboBox_znak->Size = System::Drawing::Size(94, 21);
			this->comboBox_znak->TabIndex = 6;
			this->comboBox_znak->Text = L"operation";
			this->comboBox_znak->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_znak_SelectedIndexChanged_1);
			// 
			// textBox_value
			// 
			this->textBox_value->Location = System::Drawing::Point(203, 3);
			this->textBox_value->Name = L"textBox_value";
			this->textBox_value->Size = System::Drawing::Size(63, 20);
			this->textBox_value->TabIndex = 8;
			this->textBox_value->Text = L"value";
			this->textBox_value->Click += gcnew System::EventHandler(this, &MyForm::textBox_value_Click);
			this->textBox_value->Leave += gcnew System::EventHandler(this, &MyForm::textBox_value_Leave_1);
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 2;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel11->Controls->Add(this->checkBox_all, 0, 0);
			this->tableLayoutPanel11->Controls->Add(this->checkbox_hash_id, 1, 0);
			this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel11->Location = System::Drawing::Point(239, 42);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(275, 22);
			this->tableLayoutPanel11->TabIndex = 21;
			// 
			// checkBox_all
			// 
			this->checkBox_all->AutoSize = true;
			this->checkBox_all->Location = System::Drawing::Point(3, 3);
			this->checkBox_all->Name = L"checkBox_all";
			this->checkBox_all->Size = System::Drawing::Size(73, 16);
			this->checkBox_all->TabIndex = 10;
			this->checkBox_all->Text = L"all objects";
			this->checkBox_all->UseVisualStyleBackColor = true;
			this->checkBox_all->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_all_CheckedChanged);
			// 
			// checkbox_hash_id
			// 
			this->checkbox_hash_id->AutoSize = true;
			this->checkbox_hash_id->Location = System::Drawing::Point(140, 3);
			this->checkbox_hash_id->Name = L"checkbox_hash_id";
			this->checkbox_hash_id->Size = System::Drawing::Size(63, 16);
			this->checkbox_hash_id->TabIndex = 11;
			this->checkbox_hash_id->Text = L"hash_id";
			this->checkbox_hash_id->UseVisualStyleBackColor = true;
			this->checkbox_hash_id->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkbox_hash_id_CheckedChanged);
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 2;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				2.952029F)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				97.04797F)));
			this->tableLayoutPanel9->Controls->Add(this->comboBox_repair, 1, 0);
			this->tableLayoutPanel9->Controls->Add(this->label_repair, 0, 0);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(239, 70);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(275, 30);
			this->tableLayoutPanel9->TabIndex = 19;
			// 
			// comboBox_repair
			// 
			this->comboBox_repair->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox_repair->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_repair->FormattingEnabled = true;
			this->comboBox_repair->Location = System::Drawing::Point(11, 3);
			this->comboBox_repair->Name = L"comboBox_repair";
			this->comboBox_repair->Size = System::Drawing::Size(261, 21);
			this->comboBox_repair->TabIndex = 16;
			this->comboBox_repair->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_repair_SelectedIndexChanged);
			// 
			// label_repair
			// 
			this->label_repair->AutoSize = true;
			this->label_repair->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_repair->Location = System::Drawing::Point(3, 0);
			this->label_repair->Name = L"label_repair";
			this->label_repair->Size = System::Drawing::Size(2, 30);
			this->label_repair->TabIndex = 17;
			this->label_repair->Text = L"repair";
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 2;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				2.952029F)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				97.04797F)));
			this->tableLayoutPanel10->Controls->Add(this->comboBox_step, 1, 0);
			this->tableLayoutPanel10->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel10->Location = System::Drawing::Point(239, 106);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 1;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(275, 32);
			this->tableLayoutPanel10->TabIndex = 20;
			// 
			// comboBox_step
			// 
			this->comboBox_step->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox_step->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_step->FormattingEnabled = true;
			this->comboBox_step->Location = System::Drawing::Point(11, 3);
			this->comboBox_step->Name = L"comboBox_step";
			this->comboBox_step->Size = System::Drawing::Size(261, 21);
			this->comboBox_step->TabIndex = 17;
			this->comboBox_step->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_step_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(2, 32);
			this->label3->TabIndex = 17;
			this->label3->Text = L"step";
			// 
			// textBox_ids
			// 
			this->textBox_ids->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox_ids->Location = System::Drawing::Point(239, 144);
			this->textBox_ids->Multiline = true;
			this->textBox_ids->Name = L"textBox_ids";
			this->tableLayoutPanel6->SetRowSpan(this->textBox_ids, 2);
			this->textBox_ids->Size = System::Drawing::Size(275, 211);
			this->textBox_ids->TabIndex = 9;
			this->textBox_ids->Text = L"dataids comma separated";
			this->textBox_ids->Click += gcnew System::EventHandler(this, &MyForm::textBox_ids_Click);
			this->textBox_ids->Leave += gcnew System::EventHandler(this, &MyForm::textBox_ids_Leave_1);
			// 
			// textBox_search
			// 
			this->textBox_search->AcceptsReturn = true;
			this->textBox_search->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_search->Location = System::Drawing::Point(4, 4);
			this->textBox_search->Margin = System::Windows::Forms::Padding(4);
			this->textBox_search->Name = L"textBox_search";
			this->textBox_search->Size = System::Drawing::Size(322, 20);
			this->textBox_search->TabIndex = 0;
			this->textBox_search->TabStop = false;
			this->textBox_search->Text = L"words to search by \',\'";
			this->textBox_search->Click += gcnew System::EventHandler(this, &MyForm::textBox_search_Click);
			this->textBox_search->Leave += gcnew System::EventHandler(this, &MyForm::textbox_ProjectPath_Leave);
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 4;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				330)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				80)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				73)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				87)));
			this->tableLayoutPanel5->Controls->Add(this->textBox_search, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->button_find_prev, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->richTextBox_showdata, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->button_search, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->button_find_next, 2, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(542, 26);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.226107F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 92.7739F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(570, 429);
			this->tableLayoutPanel5->TabIndex = 16;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1124, 467);
			this->Controls->Add(this->tableLayoutPanel5);
			this->Controls->Add(this->Tabs);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Location = System::Drawing::Point(15, 398);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyTool";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->Tabs->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->tableLayoutPanel11->ResumeLayout(false);
			this->tableLayoutPanel11->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Boolean CheckFileInFolder(String^ path, String^ filename)
{	


	fs::path root_path = MRSHL_Str_TO_stdstr(path);
	std::string file = MRSHL_Str_TO_stdstr(filename);

	if (!fs::is_directory(root_path) || fs::is_regular_file(root_path))
		return false;

	fs::directory_iterator itr(root_path), end_itr;

	while (itr != end_itr)
	{	
	

		if (fs::is_regular_file(*itr) && itr->path().filename().string() == file)
		{
			
			return true;

		}	
		itr++;
	}


	return false;

}

//формирование путей и т.д.
#pragma region pathes
///////////////////////////пути
private: System::Void MakeGamefieldResPath()
{
	textBox_GamefieldPath->Text = textbox_ProjectPath->Text + "/base_mm/cluster1/Resources.xml";
	std::string file = MRSHL_Str_TO_stdstr(textBox_GamefieldPath->Text);

	if (ExistFile(file))
	{
		path_gamefield_resources = file;
		textBox_GamefieldPath->BackColor = Color::Honeydew;
	}
	else textBox_GamefieldPath->BackColor = Color::MistyRose;

}

private: System::Void MakeRepairPath()
{
	textBox_repairsFolder->Text = textbox_ProjectPath->Text + "/base_mm/repairs";
	std::string folder = MRSHL_Str_TO_stdstr(textBox_repairsFolder->Text);
	path_repair_path = folder;

	if (ExistDirectory(folder))
	{
		GetChapterFiles();
		FillChapterList();
		textBox_repairsFolder->BackColor = Color::Honeydew;
	}
	else
	{	
		textBox_repairsFolder->BackColor = Color::MistyRose;
		listBox_Chapters->Items->Clear();
		listBox_Chapters->BackColor = Color::MistyRose;
		listBox_Chapters->Items->Add("Wrong project folder, set project path");
		
	}
}

private: System::Void FillChapterList()
{
	listBox_Chapters->Items->Clear();

	String^ f_name_for_list;
	for (auto it = CH_files.begin(); it != CH_files.end(); it++)
	{
		f_name_for_list = MRSHL_stdstr_TO_Str(*it);
		listBox_Chapters->Items->Add(f_name_for_list);
	}

	listBox_Chapters->BackColor = Color::Honeydew;
}

private: System::Void MakeTexturesFolderPath()
{
	textBox_textures_folder->Text = textbox_ProjectPath->Text + "/base_mm/textures/Gamefield/static";
	std::string folder = MRSHL_Str_TO_stdstr(textBox_textures_folder->Text);

	if (ExistDirectory(folder))
	{
		path_texture_folder = folder;
		textBox_textures_folder->BackColor = Color::Honeydew;
	}
	else textBox_textures_folder->BackColor = Color::MistyRose;
}

private: System::Void MakeClustersList()
{
	String^ cluster_path = textbox_ProjectPath->Text + "/base_mm";
	std::string  s = MRSHL_Str_TO_stdstr(cluster_path);

	listBox_clusters->Items->Clear();
	cluster_folders.clear();
	ObjLib_files.clear();
	listBox_ObLib->Items->Clear();

	if (ExistDirectory(s))
	{
		path_base_mm = s;
		fs::directory_iterator itr(path_base_mm), itr_end;

		while (itr != itr_end)
		{
			if (fs::is_directory(*itr) && itr->path().stem().string().find("cluster") != -1)
			{
				listBox_clusters->Items->Add(MRSHL_stdstr_TO_Str(itr->path().string()));
				cluster_folders.push_back(itr->path());
			}
			itr++;
		}
		
		GetObjectLibraryFiles();
		MakeOLfilesList();
		listBox_clusters->BackColor = Color::Honeydew;
		listBox_ObLib->BackColor = Color::Honeydew;
	}
	else
	{
	
		listBox_clusters->Items->Add("wrong project path");
		listBox_clusters->BackColor = Color::MistyRose;
		listBox_ObLib->Items->Add("wrong project path");
		listBox_ObLib->BackColor = Color::MistyRose;
	}
}		 


private: System::Void MakeOLfilesList()
{	
	listBox_ObLib->Items->Clear();
	for (auto it = ObjLib_files.begin(); it != ObjLib_files.end(); it++)
	{
		String^ ObLib = MRSHL_stdstr_TO_Str(it->string());
		listBox_ObLib->Items->Add(ObLib);	
	}
}
////////конструирование путей по папке проекта
private: System::Void ConstructPathes()
{	
	MakeGamefieldResPath();
	MakeRepairPath();
	MakeClustersList();
	MakeTexturesFolderPath();
}

//////////////////двойной клик - выбор папки проекта
private: System::Void textbox_ProjectPath_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	textbox_ProjectPath->Text = folderBrowserDialog1->SelectedPath;
	std::string project_folder = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text);

	if (ExistDirectory(project_folder) && CheckFileInFolder(textbox_ProjectPath->Text + "/base_mm/cluster1", "ObjectLibrary.xml"))
	{
		ConstructPathes();
		path_game_folder = project_folder;
		textbox_ProjectPath->BackColor = Color::Honeydew;
		path_base_mm = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text + "/base_mm");

	}
	else 
	{	
		textbox_ProjectPath->BackColor = Color::MistyRose;
		MessageBox::Show("Wrong project folder, set project path");
	}
}

//////////////////двойной клик  - выбор GamefieldResources
private: System::Void textBox_GamefieldPath_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	openFileDialog1->Multiselect = false;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	textBox_GamefieldPath->Text = openFileDialog1->FileName;

	std::string file = MRSHL_Str_TO_stdstr(textBox_GamefieldPath->Text);


	if (file.find("Resources.xml") != -1)
	{
		path_gamefield_resources = file;
		textBox_GamefieldPath->BackColor = Color::Honeydew;
	}
	else
	{
		textBox_GamefieldPath->BackColor = Color::MistyRose;
		MessageBox::Show("Not Resources file");
	}
}


////////////////двойной клик - выбор папки с чаптерами
private: System::Void textBox_repairsFolder_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{

	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	textBox_repairsFolder->Text = folderBrowserDialog1->SelectedPath;
	std::string folder = MRSHL_Str_TO_stdstr(textBox_repairsFolder->Text);

	if (folder.find("repairs")!=-1)
	{
		path_repair_path = folder;
		textBox_repairsFolder->BackColor = Color::Honeydew;
	}
	else
	{
		textBox_repairsFolder->BackColor = Color::MistyRose;
		MessageBox::Show("Not repairs folder");
	}
}
////////////////двойной клик - выбор папки с текстурами
private: System::Void textBox_textures_folder_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	

	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	textBox_textures_folder->Text = folderBrowserDialog1->SelectedPath;
	std::string folder = MRSHL_Str_TO_stdstr(textBox_textures_folder->Text);


	if (folder.find("base_mm/textures") != -1)
	{
		path_texture_folder = folder;
		textBox_textures_folder->BackColor = Color::Honeydew;
	}
	else
	{
		textBox_textures_folder->BackColor = Color::MistyRose;
		MessageBox::Show("Not textures folder");
	}
}

/////////ушли с поля
private: System::Void textbox_ProjectPath_Leave(System::Object^  sender, System::EventArgs^  e) 
{	
	std::string path = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text);
	if (ExistDirectory(path) && CheckFileInFolder(textbox_ProjectPath->Text + "/base_mm/cluster1", "ObjectLibrary.xml"))
	{
		path_game_folder = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text);
		ConstructPathes();
		textbox_ProjectPath->BackColor = Color::Honeydew;

		path_base_mm = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text + "/base_mm");

	}
	else
	{
		textbox_ProjectPath->BackColor = Color::MistyRose;
		ConstructPathes();
	}

	//ConstructPathes();
}

/////////ушли с поля
private: System::Void textBox_GamefieldPath_Leave(System::Object^  sender, System::EventArgs^  e) 
{	
	std::string g_path = MRSHL_Str_TO_stdstr(textBox_GamefieldPath->Text);

	if (ExistFile(g_path) && g_path.find("Resources.xml")!=-1)
	{	
		path_gamefield_resources = g_path;
		textBox_GamefieldPath->BackColor = Color::Honeydew;
	}
	else
	{	
		textBox_GamefieldPath->BackColor = Color::MistyRose;
	}
}

/////////ушли с поля
private: System::Void textBox_repairsFolder_Leave(System::Object^  sender, System::EventArgs^  e) 
{
	std::string repair_path = MRSHL_Str_TO_stdstr(textBox_repairsFolder->Text);

	if (ExistDirectory(repair_path) && repair_path.find("base_mm/repairs") != -1)
	{
		FillChapterList();
		path_repair_path = repair_path;
		textBox_repairsFolder->BackColor = Color::Honeydew;
		listBox_Chapters->BackColor = Color::Honeydew;
	}
	else
	{
		textBox_repairsFolder->BackColor = Color::MistyRose;
		listBox_Chapters->Items->Clear();
		listBox_Chapters->Items->Add("Wrong repair directory");
		listBox_Chapters->BackColor = Color::MistyRose;
	}
}

/////////ушли с поля
private: System::Void textBox_textures_folder_Leave(System::Object^  sender, System::EventArgs^  e)
{
	std::string textures_folder = MRSHL_Str_TO_stdstr(textBox_textures_folder->Text);

	if (ExistDirectory(textures_folder) && textures_folder.find("base_mm/textures") != -1)
	{
		path_texture_folder = textures_folder;
		textBox_textures_folder->BackColor = Color::Honeydew;
	}
	else
	{
		textBox_textures_folder->BackColor = Color::MistyRose;
	}
}


//выбрать файлы чаптеров
private: System::Void button_chooseChapter_Click(System::Object^  sender, System::EventArgs^  e)
{

	openFileDialog1->Multiselect = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	CH_files.clear();
	listBox_Chapters->Items->Clear();

	for each(String^ file in openFileDialog1->FileNames)
	{
		//listBox_Chapters->Items->Add(file);
		std::string filename = MRSHL_Str_TO_stdstr(file);
		if (filename.find("CH_") == -1)
			continue;
		CH_files.push_back(MRSHL_Str_TO_stdstr(file));
	}

	FillChapterList();
	//debug_list();
}

private: System::Void button_minus_chapter_Click(System::Object^  sender, System::EventArgs^  e)
{
	richTextBox_showdata->Text = "";
	if (listBox_Chapters->SelectedItem != nullptr)
	{
		CH_files.remove(MRSHL_Str_TO_stdstr(listBox_Chapters->SelectedItem->ToString()));
		FillChapterList();
	}
	//debug_list();
}

private: System::Void button_plus_chapter_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
	std::string filename = MRSHL_Str_TO_stdstr(openFileDialog1->FileName);
	if (filename.find("CH_") != -1)
	{
		CH_files.push_back(MRSHL_Str_TO_stdstr(openFileDialog1->FileName));
		FillChapterList();
	}
	//debug_list();
}

private: System::Void listBox_Chapters_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox_Chapters->SelectedItem == nullptr) return;
	std::string filename = MRSHL_Str_TO_stdstr(listBox_Chapters->SelectedItem->ToString());
	std::ifstream ifs(filename);
	std::string filetext((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	richTextBox_showdata->Text = MRSHL_stdstr_TO_Str(filetext);
}

private: System::Void button_clear_list_chapter_Click(System::Object^  sender, System::EventArgs^  e)
{
	CH_files.clear();
	FillChapterList();
	//debug_list();
}

//добавить/убрать папку кластера
private: System::Void button_minus_cluster_Click(System::Object^  sender, System::EventArgs^  e)
{

	fs::path p = MRSHL_Str_TO_stdstr(listBox_clusters->SelectedItem->ToString());
	listBox_clusters->Items->Remove(listBox_clusters->SelectedItem);
	cluster_folders.remove(p);

	ObjLib_files.clear();
	GetObjectLibraryFiles();
	MakeOLfilesList();
	//FillChapterList();
}

private: System::Void button_plus_cluster_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	String^ selected_cluster = folderBrowserDialog1->SelectedPath->ToString();

	fs::path p = MRSHL_Str_TO_stdstr(selected_cluster);

	cluster_folders.push_back(p);
	listBox_clusters->Items->Add(selected_cluster);
	ObjLib_files.clear();
	GetObjectLibraryFiles();
	MakeOLfilesList();
}

//ЛОГ ПУТЬ
private: System::Void textBox_LOGFILE_Leave(System::Object^  sender, System::EventArgs^  e)
{
	path_LOG = MRSHL_Str_TO_stdstr(textBox_LOGFILE->Text);

}

#pragma endregion 

//ПОИСК
#pragma region search

private: System::Void textBox_search_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (textBox_search->Text == "words to search by ','")
		textBox_search->Clear();
}

private: System::Void SearchAll()
{	
	searched = true;
	int start = 0;
	int end = richTextBox_showdata->Text->LastIndexOf(textBox_search->Text);
	richTextBox_showdata->SelectAll();
	richTextBox_showdata->SelectionBackColor = Color::White;
	while (start < end)
	{
		if (richTextBox_showdata->Find(textBox_search->Text, start, richTextBox_showdata->TextLength, RichTextBoxFinds::MatchCase) != -1)
			nb_result++;
		richTextBox_showdata->SelectionBackColor = Color::Yellow;
		start = richTextBox_showdata->Text->IndexOf(textBox_search->Text, start) + 1;
	}

	if (nb_result==0) 
		MessageBox::Show("No results");
	
	nb_result = 0;


}

private: System::Void SearchOneReverse()
{	
	if (!searched)
	{
		SearchAll();
		MessageBox::Show("No previous");
		return;
	}

	if (selected_start > 0)
	{
		richTextBox_showdata->SelectionStart = selected_start;
		richTextBox_showdata->SelectionLength = textBox_search->TextLength;
		richTextBox_showdata->SelectionBackColor = Color::Yellow;
	}
	int a = selected_start;
	int end = richTextBox_showdata->TextLength;
	while (end >= textBox_search->TextLength)
	{
		a = richTextBox_showdata->Find(textBox_search->Text, 0, a, RichTextBoxFinds::Reverse);
		if (a != -1)
		{
			if (richTextBox_showdata->Find(textBox_search->Text, a, a + textBox_search->TextLength, RichTextBoxFinds::MatchCase) != -1)
			{
				result_symb = a;
				selected_start = result_symb;
				selected_end = result_symb + textBox_search->TextLength;
				richTextBox_showdata->SelectionBackColor = Color::OrangeRed;
				richTextBox_showdata->Focus();
				end = a;
				break;
			}
			else
			{
				end = a;
			}
		}
		else
		{
			MessageBox::Show("No previous");
			return;
		}

	}
}

private: System::Void SearchOne()
{	
	if (!searched)
	{
		SearchAll();
	}

	int end = richTextBox_showdata->Text->LastIndexOf(textBox_search->Text);

	if (selected_end != 0)
	{
		richTextBox_showdata->SelectionStart = selected_start;
		richTextBox_showdata->SelectionLength = textBox_search->TextLength;
		richTextBox_showdata->SelectionBackColor = Color::Yellow;
	}

	result_symb = richTextBox_showdata->Find(textBox_search->Text, selected_start+textBox_search->TextLength, richTextBox_showdata->TextLength, RichTextBoxFinds::MatchCase);
	if (result_symb != -1)
	{	
		selected_start = result_symb;
		selected_end = result_symb + textBox_search->TextLength;
		nb_result++;
		richTextBox_showdata->SelectionBackColor = Color::OrangeRed;
		richTextBox_showdata->Focus();
		//result_symb++;
	}
	else
		if (nb_result > 0)
		{
			MessageBox::Show("Search complited");
			nb_result = 0;
			result_symb = 0;
		}
		else
		{
			MessageBox::Show("No results");
			nb_result = 0;
			result_symb = 0;
		}
}

private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e) 
{
	SearchAll();
}

private: System::Void button_next_search_Click(System::Object^  sender, System::EventArgs^  e) 
{
	SearchOne();
}

private: System::Void button_find_prev_Click(System::Object^  sender, System::EventArgs^  e) 
{
	SearchOneReverse();
}

#pragma endregion 

//показать xml
#pragma region showXML

		 //////////////////////Показать xml при клике на GamefieldPath
private: System::Void textBox_GamefieldPath_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::string filename = MRSHL_Str_TO_stdstr(textBox_GamefieldPath->Text->ToString());
	std::ifstream ifs(filename);
	std::string filetext((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	richTextBox_showdata->Text = MRSHL_stdstr_TO_Str(filetext);
}

		 //////////////////////Показать xml при клике на ObLib file
private: System::Void listBox_ObLib_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox_ObLib->SelectedItem == nullptr) return;
	std::string filename = MRSHL_Str_TO_stdstr(listBox_ObLib->SelectedItem->ToString());
	std::ifstream ifs(filename);
	std::string filetext((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	richTextBox_showdata->Text = MRSHL_stdstr_TO_Str(filetext);
}

#pragma endregion

// ЗАГРУЗКА
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{	
	this->textbox_ProjectPath->Text = MRSHL_stdstr_TO_Str(path_game_folder);
	
	path_LOG = MRSHL_Str_TO_stdstr(textBox_LOGFILE->Text);

	Clear_LogFile();
	
	String^ time = Convert::ToString(DateTime::Now);
	std::string cpp_time = MRSHL_Str_TO_stdstr(time);
	LOG_IN_FILE(cpp_time);
	this->button_define_unused_textures->BackColor = Color::LimeGreen;
	//this->BackColor = Color::MintCream;

}

private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	std::string path = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text);

	if (ExistDirectory(path) && CheckFileInFolder(textbox_ProjectPath->Text + "/base_mm/cluster1", "ObjectLibrary.xml"))
	{
		path_game_folder = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text);
		ConstructPathes();
		GetChapterFiles();

		textbox_ProjectPath->BackColor = Color::Honeydew;

		path_base_mm = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text + "/base_mm");

		
	}
	else
	{

		ConstructPathes();

		cluster_folders.clear();
		listBox_clusters->Items->Clear();
		listBox_clusters->Items->Add("Wrong project folder, set project path");


		textbox_ProjectPath->SelectionStart = 0;
		textbox_ProjectPath->SelectionLength = textbox_ProjectPath->Text->Length;

		textBox_textures_folder->Select(0, 0);
		textbox_ProjectPath->BackColor = Color::Red;
		MessageBox::Show("Wrong project folder, set project path");

	}
	path_LOG = MRSHL_Str_TO_stdstr(textBox_LOGFILE->Text);
}

private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	Application::Exit();
}

delegate System::Void Del();

//Выявление НЕИСПОЛЬЗУЕМЫХ ТЕКСТУР
private: System::Void button_define_unused_textures_Click(System::Object^  sender, System::EventArgs^  e) 
{	

	if (textbox_ProjectPath->BackColor == Color::MistyRose)
	{
		MessageBox::Show("Wrong project path");
		return;
	}

	if (textBox_GamefieldPath->BackColor == Color::MistyRose)
	{	
		MessageBox::Show("Wrong Resources.xml path");
		return;
	}
	if (CH_files.empty())
	{
		MessageBox::Show("No chapter files was chosen");
		return;
	}

	if (ObjLib_files.empty())
	{
		MessageBox::Show("No ObjectLibrary.xml files was chosen");
		return;
	}

	if (textBox_textures_folder->BackColor == Color::MistyRose)
	{
		MessageBox::Show("Wrong textures path");
		return;
	}


	path_base_mm = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text + "/base_mm");


	if (!collected)
	{
		form3_loading = gcnew MyForm3("texture_table");

		form3_loading->Load += gcnew System::EventHandler(this, &MyTool::MyForm::OnLoadForm3);
		form3_loading->ClosingForm3 += gcnew System::EventHandler(this, &MyTool::MyForm::OnClosingForm3);

		form3_loading->Show();
	}
	else
	{
		this->Hide();
		form3_loading->JustShowTextureTable();
	}
		
}

void MyTool::MyForm::OnLoadForm3(System::Object ^sender, System::EventArgs ^e)
	{
		this->Hide();
	}

void MyTool::MyForm::OnClosingForm3(System::Object ^sender, System::EventArgs ^e)
{
	this->Show();
}

//перезагрузка партикл эффектов
private: System::Void Refresh_Particle_Table()
{	
	
}

//таблица партикл эффектов
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (collected)
	{	
		this->Hide();
		form3_loading->JustShowEffectTable();
	}
	else
	{

		form3_loading = gcnew MyForm3("effect_table");

		form3_loading->Load += gcnew System::EventHandler(this, &MyTool::MyForm::OnLoadForm3);
		form3_loading->ClosingForm3 += gcnew System::EventHandler(this, &MyTool::MyForm::OnClosingForm3);

		form3_loading->Show();
	}
}

//таблица чаптерэдитор
private: System::Void button_chapter_editor_Click(System::Object^  sender, System::EventArgs^  e) 
{
	/*if (!CH_objects.empty())
	{
		chapter_editor^ chap = gcnew chapter_editor;
		chap->Show();
	}
	else
	{*/	
	//	loading^ load = gcnew loading;
	//	load->Show();
	//	if (!static_textures.empty() && )
	//		textures.clear();
	//	load->label1->Text = "Collecting textures...";
	//	load->label1->Update();
	//	GetTextureFiles();

	//	if (GameField_objects.empty())
	//		GameField_objects.clear();
	//	load->label1->Text = "Collecting GamefieldResources...";
	//	load->label1->Update();
	//	Get_GameFieldRes_Info();

	//	if (ObjLib_items.empty())
	//		ObjLib_items.clear();
	//	load->label1->Text = "Collecting ObjectLibrary resources...";
	//	load->label1->Update();
	//	Get_ObjectLibrary_Info();

	//	if (CH_objects.empty())
	//		CH_objects.clear();
	//	load->label1->Text = "Collecting Chapters resources...";
	//	load->label1->Update();
	//	Get_ChapterData_Info();

	//	load->Close();

	//	chapter_editor^ chap = gcnew chapter_editor;
	//	chap->Show();
	///*}*/

}
	

#pragma region tab2

		 //заполнить чаптерлист
private: System::Void FillChapterListT2()
{
	listBox_CH->Items->Clear();

	String^ f_name_for_list;
	for (auto it = CH_files.begin(); it != CH_files.end(); it++)
	{
		f_name_for_list = MRSHL_stdstr_TO_Str(*it);
		listBox_CH->Items->Add(f_name_for_list);
	}

	//listBox_CH->BackColor = Color::Honeydew;
}

		 //получить айдихи из текста
private: System::Void Fill_ids_to_change()
{	
	ch_attrib_ids.clear();
	String^ text = textBox_ids->Text;

	std::string s_text = MRSHL_Str_TO_stdstr(text);

	int length = s_text.length();


	int count = 0;
	for (int i = 0; i != length; i++)
	{
		std::string temp;
		int j = i;
		bool inside = false;
		while (s_text[j] != ',' && j < length)
		{
			if (s_text[j] != ' ')
			{
				temp += s_text[j];
			}
			j++;
			inside = true;
		}
		if (inside)
		{
			ch_attrib_ids.push_back(temp);
			if (j == length)
				break;
			i = j;
		}

	}

	//ch_attrib_change_ids_to_change
}
	 
		 //показать xml
private: System::Void listBox_CH_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox_CH->SelectedItem == nullptr) return;
	std::string filename = MRSHL_Str_TO_stdstr(listBox_CH->SelectedItem->ToString());
	std::ifstream ifs(filename);
	std::string filetext((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	richTextBox_showdata->Text = MRSHL_stdstr_TO_Str(filetext);
}

		////////////////////////////////изменение таба
private: System::Void Tabs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{	
	richTextBox_showdata->Text = "choose file";

	std::string path = MRSHL_Str_TO_stdstr(textbox_ProjectPath->Text);

	switch (Tabs->SelectedIndex)
	{
	case 0:
		if (ExistDirectory(path) && CheckFileInFolder(textbox_ProjectPath->Text + "/base_mm/cluster1", "ObjectLibrary.xml"))
		{
			GetChapterFiles();
			FillChapterList();
			return;
		}
		break;
	case 1:
		if (!CH_files.empty())
		{
			FillChapterListT2();
			FillRepairsAndSteps();
			FillComboRepairs();
			FillComboSteps();
			return;
		}
		break;
	default:
		break;
	}
}

		 //заполнить айдихи
private: System::Void textBox_ids_Leave_1(System::Object^  sender, System::EventArgs^  e) 
{
	if (textBox_ids->Text->Length == 0)
	{	
		if (checkbox_hash_id->CheckState == CheckState::Unchecked)
		{
			textBox_ids->Text = "dataids comma separated";
		}
		else
		{
			textBox_ids->Text = "hashids comma separated (81439eb5, d401b99e, etc.)";
		}
		textBox_ids->BackColor = Color::MistyRose;
		return;
	}
	else
	{
		Fill_ids_to_change();
		textBox_ids->BackColor = Color::White;
	}

}

		 //клик на айди
private: System::Void textBox_ids_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (textBox_ids->Text == "dataids comma separated" || textBox_ids->Text == "hashids comma separated (81439eb5, d401b99e, etc.)")
	textBox_ids->Clear();
}

		 //чекбокс хеш
private: System::Void checkbox_hash_id_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
	if (checkbox_hash_id->CheckState == CheckState::Checked)
	{	
		if (textBox_ids->Text == "dataids comma separated" || textBox_ids->Text == "")
			textBox_ids->Text = "hashids comma separated (81439eb5, d401b99e, etc.)";
		ch_attrib_dataid = false;
		return;
	}
	else if (checkbox_hash_id->CheckState == CheckState::Unchecked)
	{	
		if (textBox_ids->Text == "hashids comma separated (81439eb5, d401b99e, etc.)" || textBox_ids->Text == "")
			textBox_ids->Text = "dataids comma separated";
		ch_attrib_dataid = true;
		return;
	}
}

		 //чекбокс все объекты
private: System::Void checkBox_all_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
	if (checkBox_all->CheckState == CheckState::Checked)
	{	
		textBox_ids->BackColor = Color::White;
		textBox_ids->Enabled = false;
		ch_attrib_all_objects = true;
	}
	else
	{
		textBox_ids->Enabled = true;
		ch_attrib_all_objects = false;
	}
}

private: System::Void textBox_value_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	if (textBox_value->Text == "value")
		textBox_value->Clear();
}

private: System::Void textBox_value_Leave_1(System::Object^  sender, System::EventArgs^  e) 
{
	String^ text = textBox_value->Text;
	Int32 distance;
	if (Int32::TryParse(textBox_value->Text, distance))
	{
		String^ value = Convert::ToString(distance);
		ch_attrib_value = MRSHL_Str_TO_stdstr(value);
		// it's a valid integer => you could use the distance variable here
	}
	else
	{	
		textBox_value->Clear();
		textBox_value->BackColor = Color::MistyRose;
	}
}

		 //знак операции +,-,/,*,=
private: System::Void comboBox_znak_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) 
{
	switch ((this->comboBox_znak->SelectedIndex))
	{
	case 0:
		ch_attrib_operation = '+';
		break;
	case 1:
		ch_attrib_operation = '-';
		break;
	case 2:
		ch_attrib_operation = '*';
		break;
	case 3:
		ch_attrib_operation = '/';
		break;
	case 4:
		ch_attrib_operation = '=';
		break;
	default:
		break;
	}
}

		 //выбор атрибута
private: System::Void comboBox_attribute_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) 
{
	ch_attrib = "";
	ch_attrib_iso = false;
	switch ((this->comboBox_attribute->SelectedIndex))
	{
	case 0:
		ch_attrib = "m";
		ch_attrib_iso = false;
		break;
	case 1:
		ch_attrib = "rand";
		ch_attrib_iso = false;
		break;
	case 2:
		ch_attrib = "x";
		ch_attrib_iso = false;
		break;
	case 3:
		ch_attrib = "y";
		ch_attrib_iso = false;
		break;
	case 4:
		ch_attrib = "zOrder";
		ch_attrib_iso = false;
		break;
	case 5:
		ch_attrib = "uL";
		ch_attrib_iso = true;
		break;
	case 6:
		ch_attrib = "uR";
		ch_attrib_iso = true;
		break;
	case 7:
		ch_attrib = "x";
		ch_attrib_iso = true;
		break;
	case 8:
		ch_attrib = "y";
		ch_attrib_iso = true;
		break;
	case 9:
		ch_attrib = "z";
		ch_attrib_iso = true;
		break;
	default:
		break;
	}
}

		 //////////////////////////////////////изменить аттрибут
private: System::Void button_change_attribute_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (ch_attrib_ids.empty() && !ch_attrib_all_objects)
	{
		MessageBox::Show("no ids inserted");
		return;
	}
	if (textBox_value->Text->Length == 0 || textBox_value->Text == "value")
	{
		MessageBox::Show("no value");
		return;
	}
	if (comboBox_attribute->Text->Length == 0 || comboBox_attribute->Text == "attribute")
	{
		MessageBox::Show("no attribute");
		return;
	}
	if (comboBox_znak->Text->Length == 0 || comboBox_znak->Text == "operation")
	{
		MessageBox::Show("no operation");
		return;
	}

	//std::vector<std::string> result;

	auto& result = ChangeAttribute();

	if (result.size() == 1)
	{
		String^ res = MRSHL_stdstr_TO_Str(result[0]);
		MessageBox::Show(res);
		return;
	}

	std::string text;
	for (int i = 0; i< result.size(); i++)
	{	
		std::string temp = result[i];
		if (temp.find("not_found") != -1)
		{	
			if (i != result.size() - 1)
			{
				text += temp + ", ";
			}
			else text += temp;
		}
	}

	if (text == "")
	{
		MessageBox::Show("all ids was sucsesfully processed");
		return;
	}

	String^ res = MRSHL_stdstr_TO_Str(text);
	MessageBox::Show(res);

	

	

}


		 //выбор чаптеров
private: System::Void button_tab2_plus_ch_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	std::string filename = MRSHL_Str_TO_stdstr(openFileDialog1->FileName);
	if (filename.find("CH_") != -1)
	{
		CH_files.push_back(MRSHL_Str_TO_stdstr(openFileDialog1->FileName));
		FillChapterListT2();
		FillRepairsAndSteps();
		FillComboRepairs();
		FillComboSteps();
	}
}

private: System::Void button_tab2_minus_ch_Click(System::Object^  sender, System::EventArgs^  e)
{
	richTextBox_showdata->Text = "";
	if (listBox_Chapters->SelectedItem != nullptr)
	{
		CH_files.remove(MRSHL_Str_TO_stdstr(listBox_Chapters->SelectedItem->ToString()));
		FillChapterListT2();
		FillRepairsAndSteps();
		FillComboRepairs();
		FillComboSteps();
	}
}

private: System::Void button_tab2_clear_ch_Click(System::Object^  sender, System::EventArgs^  e)
{
	CH_files.clear();
	FillChapterListT2();
	repairs.clear();
	steps.clear();
	comboBox_repair->Items->Clear();
	comboBox_step->Items->Clear();
}

private: System::Void button_tab2_choose_ch_Click(System::Object^  sender, System::EventArgs^  e)
{
	openFileDialog1->Multiselect = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;

	CH_files.clear();
	listBox_CH->Items->Clear();

	for each(String^ file in openFileDialog1->FileNames)
	{
		//listBox_Chapters->Items->Add(file);
		std::string filename = MRSHL_Str_TO_stdstr(file);
		if (filename.find("CH_") == -1)
			continue;
		CH_files.push_back(MRSHL_Str_TO_stdstr(file));
	}

	FillChapterListT2();
	FillRepairsAndSteps();
	FillComboRepairs();
	FillComboSteps();
}


		 //заполнение комбобоксов
private: System::Void FillComboRepairs()
{	
	comboBox_repair->Items->Clear();
	if (!repairs.empty())
	for each(const auto& repair in repairs)
	{	
		String^ temp = MRSHL_stdstr_TO_Str(repair);
		comboBox_repair->Items->Add(temp);
	}
}

private: System::Void FillComboSteps()
{
	comboBox_step->Items->Clear();
	if (!steps.empty())
	for each(const auto& step in steps)
	{
		String^ temp = MRSHL_stdstr_TO_Str(step);
		comboBox_step->Items->Add(temp);
	}
}


		 //выбор рипейра
private: System::Void comboBox_repair_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{	
	String^ text = this->comboBox_repair->Text;

	if (text == "")
	{	
		chosen_repair = "not chosen";
		CutStepsCombobox("all");
		chosen_step = "not chosen";
	}
	else
	{	
		chosen_repair = MRSHL_Str_TO_stdstr(text);
		int pos = chosen_repair.find(" - ");
		chosen_repair = chosen_repair.substr(pos + 3);
		text = text + " - ";
		CutStepsCombobox(text);
	}
}

		 //выбор степа
private: System::Void comboBox_step_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	String^ text_step = this->comboBox_step->Text;
	String^ text_repair = this->comboBox_repair->Text;

	std::string s_text_repair = MRSHL_Str_TO_stdstr(text_repair);

	int repair_length = s_text_repair.length();

	if (text_step == "")
	{
		chosen_step = "not chosen";
	}
	else
	{
		chosen_step = MRSHL_Str_TO_stdstr(text_step);
		chosen_step = chosen_step.substr(repair_length+3);
	}
}

		 //ограничить степы выбранным рипейром
private: System::Void CutStepsCombobox(String^ repair)
{	
	if (repair == "all")
	{
		FillComboSteps();
		return;
	}
	comboBox_step->Items->Clear();
	comboBox_step->Items->Add("");
	std::string s_repair = MRSHL_Str_TO_stdstr(repair);

	for (auto& step : steps)
	{
		if (step.find(s_repair) != -1)
		{
			String^ temp = MRSHL_stdstr_TO_Str(step);
			comboBox_step->Items->Add(temp);
		}
	}

	
}

#pragma endregion tab2

private: System::Void richTextBox_showdata_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
#pragma once

#include <string>
#include <iostream>
#include "tinyxml2.h"
#include <map>
#include <fstream>
#include <algorithm>
#include <boost/filesystem.hpp>
#include <boost/date_time.hpp>
#include <functional>
#include <set>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include "Macro.h"
#include <math.h>
//#include "ChangeCHAttrib.h"



using namespace System;
using namespace System::Windows::Forms;



namespace fs = boost::filesystem;


template<class T>
std::string to_string(const T& t)
{
	std::ostringstream os;
	os << t;
	return os.str();
}


template<class T>
void PrintToLogFile(T begin, T end, std::string log_path);

//////////////////Декларирования


struct TextureData;
struct ChapterData;
struct ObjLibItem;
struct ObjLibLayer;
struct ParticleEffect;
struct ParticleEffectLayer;

struct GameFieldRes
{
	//bool exist_file = false;
	
	std::string  gameFieldRes_id; //используется ObjectLibrary.xml
	std::string gameFieldRes_path_attr; //имя файла

	std::string  gameFieldRes_path; //для удаления записи из геймфилда
	fs::path  gameFieldRes_full_path;
	std::string  gameFieldRes_s_full_path; // для сета
	
	std::string  gameFieldRes_texture_group_atlas; //атлас

	TextureData*  gameFieldRes_TextureData;
	std::vector <ObjLibLayer*>  gameFieldRes_ObjLibLayers; //лейеры которые он составляет
	std::set<ObjLibItem*> gameFieldRes_unique_items; //все объекты, в которых данный GameFieldRes

	bool operator <(const GameFieldRes& other)
	{
		if (this->gameFieldRes_s_full_path < other.gameFieldRes_s_full_path)
		{
			return true;
		}
		else return false;
	}

	bool operator <(const GameFieldRes& other) const
	{
		if (this->gameFieldRes_s_full_path < other.gameFieldRes_s_full_path)
		{
			return true;
		}
		else return false;
	}

	//void operator = (const GameFieldRes& other)
	//{	
	//	this->GR_s_full_path = other.GR_s_full_path;
	//	this->GR_id = other.GR_id;
	//	this->GR_full_path = other.GR_full_path;
	//	this->GR_texture_group_atlas = other.GR_texture_group_atlas;
	//}



};

struct ObjLibLayer //<layer type="texture" name="texture" texture="cl1_flowerbed_porch_var2_flower4" xOffset="-80" yOffset="-30" xMin="-40" yMin="-40" zMin="0" xMax="40" yMax="40" zMax="44" />
{
	std::string objLayer_texture; //texture="cl1_flowerbed_porch_var2_flower4"
	std::string objLayer_type; //type="texture"
	std::string objLayer_zOrder = "-"; //

	GameFieldRes* objLayer_GameFieldRes = nullptr; //
	ObjLibItem* objLayer_item = nullptr; //item где присутствует данный лейер
	ParticleEffect* objItem_ParticleEffect = nullptr; //если лейер - партикловый комплит эффект = type="effect" или type="light"


	bool operator ==(const ObjLibLayer& other)
	{
		if (
			this->objLayer_texture == other.objLayer_texture &&
			this->objLayer_type == other.objLayer_type &&
			this->objLayer_zOrder == other.objLayer_zOrder &&
			this->objLayer_GameFieldRes == other.objLayer_GameFieldRes &&
			this->objLayer_item == other.objLayer_item &&
			this->objItem_ParticleEffect == other.objItem_ParticleEffect
			)
			return true;
		else return false;
	}

	bool operator ==(const ObjLibLayer& other) const
	{
		if (
			this->objLayer_texture == other.objLayer_texture &&
			this->objLayer_type == other.objLayer_type &&
			this->objLayer_zOrder == other.objLayer_zOrder &&
			this->objLayer_GameFieldRes == other.objLayer_GameFieldRes &&
			this->objLayer_item == other.objLayer_item &&
			this->objItem_ParticleEffect == other.objItem_ParticleEffect
			)
			return true;
		else return false;
	}

	bool operator <(const ObjLibLayer& other)
	{
		if (this->objLayer_texture < other.objLayer_texture)
		{
			return true;
		}
		else return false;
	}

	bool operator <(const ObjLibLayer& other) const
	{
		if (this->objLayer_texture < other.objLayer_texture)
		{
			return true;
		}
		else return false;
	}
};

struct ObjLibItem //<item id="flowerbed_porch_var3_flower1" noRedesignDeformation="true">
{	
	std::string objItem_item_id;
	std::string objItem_cluster;
	std::string objItem_instanceClass;
	std::string objItem_zOrder_attr; //??
	std::string objItem_defaultZOrder;
	std::string objItem_isIndoor;
	std::string objItem_noRedesignDeformation;
	std::vector<ObjLibLayer*> objItem_layers; //лейеры из которых состоит item
	std::vector<ChapterData*> objItem_ChapterDatas; //чаптеры где находится айтем
	

	bool operator <(const ObjLibItem& other)
	{
		if (this->objItem_item_id < other.objItem_item_id)
		{
			return true;
		}
		else return false;
	}

	bool operator <(const ObjLibItem& other) const
	{
		if (this->objItem_item_id < other.objItem_item_id)
		{
			return true;
		}
		else return false;
	}

	bool operator ==(const ObjLibItem& other)
	{
		if (
			this->objItem_item_id				== other.objItem_item_id					&&
			this->objItem_cluster				== other.objItem_cluster					&&
			this->objItem_instanceClass			== other.objItem_instanceClass			&&
			this->objItem_zOrder_attr			== other.objItem_zOrder_attr				&&
			this->objItem_defaultZOrder			== other.objItem_defaultZOrder			&&
			this->objItem_isIndoor				== other.objItem_isIndoor				&&
			this->objItem_noRedesignDeformation	== other.objItem_noRedesignDeformation	&&
			this->objItem_layers				== other.objItem_layers &&
			this->objItem_ChapterDatas == other.objItem_ChapterDatas 
			)
			return true;
		else return false;

	}

	bool operator ==(const ObjLibItem& other) const
	{
		if (

			this->objItem_item_id == other.objItem_item_id					&&
			this->objItem_cluster == other.objItem_cluster					&&
			this->objItem_instanceClass == other.objItem_instanceClass			&&
			this->objItem_zOrder_attr == other.objItem_zOrder_attr				&&
			this->objItem_defaultZOrder == other.objItem_defaultZOrder			&&
			this->objItem_isIndoor == other.objItem_isIndoor				&&
			this->objItem_noRedesignDeformation == other.objItem_noRedesignDeformation	&&
			this->objItem_layers == other.objItem_layers  &&
			this->objItem_ChapterDatas == other.objItem_ChapterDatas 
			)
			return true;
		else return false;

	}

};

struct ChapterData
{	
	// сортировка по dataid
	//std::string CH_chapter_id_CH_repair_CH_step_СH_id_CH_dataid; //чаптер + рипейр + степ + хешайди + текст - адская хрень для сортировки в сете
	std::string chData_text_dataid;
	std::string chData_text;
	std::string chData_storyInfo_chapter_id;
	std::string chData_storyInfo_repair;
	std::string chData_storyInfo_step;
	std::string chData_id;
	
	std::string chData_text_iso_uL = "-";
	std::string chData_text_iso_uR = "-";
	std::string chData_text_iso_x = "-";
	std::string chData_text_iso_y = "-";
	std::string chData_text_iso_z = "-";

	std::string chData_text_m;
	std::string chData_text_rand;
	std::string chData_text_x;
	std::string chData_text_y;
	std::string chData_text_zOrder;

	ObjLibItem* chData_ObjLibItem;
	

	bool operator <(const ChapterData& other)
	{
		if (this->chData_text_dataid < other.chData_text_dataid)
		{
			return true;
		}
		else return false;
	}

	bool operator <(const ChapterData& other) const
	{
		if (this->chData_text_dataid < other.chData_text_dataid)
		{
			return true;
		}
		else return false;
	}

	bool operator ==(const ChapterData& other)
	{
		if
			(
				this->chData_text_dataid == other.chData_text_dataid &&
				this->chData_text == other.chData_text &&
				this->chData_storyInfo_chapter_id == other.chData_storyInfo_chapter_id &&
				this->chData_storyInfo_repair == other.chData_storyInfo_repair &&
				this->chData_storyInfo_step == other.chData_storyInfo_step &&
				this->chData_id == other.chData_id &&
				this->chData_text_iso_uL == other.chData_text_iso_uL &&
				this->chData_text_iso_uR == other.chData_text_iso_uR &&
				this->chData_text_iso_x == other.chData_text_iso_x &&
				this->chData_text_iso_y == other.chData_text_iso_y &&
				this->chData_text_iso_z == other.chData_text_iso_z &&

				this->chData_text_m == other.chData_text_m &&
				this->chData_text_rand == other.chData_text_rand &&
				this->chData_text_x == other.chData_text_x &&
				this->chData_text_y == other.chData_text_y &&
				this->chData_text_zOrder == other.chData_text_zOrder &&

				this->chData_ObjLibItem == other.chData_ObjLibItem 

				)
		{
			return true;
		}
		else return false;
	}

	bool operator ==(const ChapterData& other) const
	{
		if
			(
				this->chData_text_dataid == other.chData_text_dataid &&
				this->chData_text == other.chData_text &&
				this->chData_storyInfo_chapter_id == other.chData_storyInfo_chapter_id &&
				this->chData_storyInfo_repair == other.chData_storyInfo_repair &&
				this->chData_storyInfo_step == other.chData_storyInfo_step &&
				this->chData_id == other.chData_id &&
				this->chData_text_iso_uL == other.chData_text_iso_uL &&
				this->chData_text_iso_uR == other.chData_text_iso_uR &&
				this->chData_text_iso_x == other.chData_text_iso_x &&
				this->chData_text_iso_y == other.chData_text_iso_y &&
				this->chData_text_iso_z == other.chData_text_iso_z &&

				this->chData_text_m == other.chData_text_m &&
				this->chData_text_rand == other.chData_text_rand &&
				this->chData_text_x == other.chData_text_x &&
				this->chData_text_y == other.chData_text_y &&
				this->chData_text_zOrder == other.chData_text_zOrder &&

				this->chData_ObjLibItem == other.chData_ObjLibItem 

				)
		{
			return true;
		}
		else return false;
	}

};

struct CH_ParticleEffect
{
	std::string CH_PE_name; // сортировка имя
	std::string CH_PE_chapter;
	std::string CH_PE_repair;
	std::string CH_PE_step;

	bool operator ==(const CH_ParticleEffect& other)
	{
		if (
			this->CH_PE_name == other.CH_PE_name &&
			this->CH_PE_chapter == other.CH_PE_chapter &&
			this->CH_PE_repair == other.CH_PE_repair &&
			this->CH_PE_step == other.CH_PE_step 
			)
			return true;
		else return false;
	}

	bool operator ==(const CH_ParticleEffect& other) const
	{
		if (
			this->CH_PE_name == other.CH_PE_name &&
			this->CH_PE_chapter == other.CH_PE_chapter &&
			this->CH_PE_repair == other.CH_PE_repair &&
			this->CH_PE_step == other.CH_PE_step 
			)
			return true;
		else return false;
	}

	bool operator < (const CH_ParticleEffect& other)
	{
		if (this->CH_PE_name < other.CH_PE_name)
		{
			return true;
		}
		else return false;
	}

	bool operator < (const CH_ParticleEffect& other) const
	{
		if (this->CH_PE_name < other.CH_PE_name)
		{
			return true;
		}
		else return false;
	}

};

struct ParticleEffect
{	
	std::string partEff_name_s; // путь xml файла стринг (для сортировки сета)
	fs::path partEff_name_p; // путь xml файла паз
	std::string partEff_type; // repair, complited or other
	std::string partEff_cluster; // кластер где лежит

	std::string partEff_exist_in_CH="-"; //есть ли на мете
	mutable std::string partEff_dead = "-";
	mutable bool partEff_to_delete = false;
	std::vector<ObjLibLayer*> partEff_ObjLibLayers; //лееры где он есть зачем?
	std::vector<ParticleEffectLayer*>partEff_ParticleEffectLayers; //все слои <ParticleSystem> - текстуры эффекта

	bool operator ==(const ParticleEffect& other)
	{
		if (
			this->partEff_name_s == other.partEff_name_s &&
			this->partEff_name_p == other.partEff_name_p &&
			this->partEff_type == other.partEff_type &&
			this->partEff_cluster == other.partEff_cluster &&
			this->partEff_exist_in_CH == other.partEff_exist_in_CH &&
			this->partEff_dead == other.partEff_dead &&
			this->partEff_to_delete == other.partEff_to_delete &&
			this->partEff_ObjLibLayers == other.partEff_ObjLibLayers &&
			this->partEff_ParticleEffectLayers == other.partEff_ParticleEffectLayers
			)
			return true;
		else return false;
	}

	bool operator ==(const ParticleEffect& other) const
	{
		if (
			this->partEff_name_s == other.partEff_name_s &&
			this->partEff_name_p == other.partEff_name_p &&
			this->partEff_type == other.partEff_type &&
			this->partEff_cluster == other.partEff_cluster &&
			this->partEff_exist_in_CH == other.partEff_exist_in_CH &&
			this->partEff_dead == other.partEff_dead &&
			this->partEff_to_delete == other.partEff_to_delete &&
			this->partEff_ObjLibLayers == other.partEff_ObjLibLayers &&
			this->partEff_ParticleEffectLayers == other.partEff_ParticleEffectLayers
			)
			return true;
		else return false;
	}

	bool operator < (const ParticleEffect& other)
	{
		if (this->partEff_name_s < other.partEff_name_s)
		{
			return true;
		}
		else return false;
	}

	bool operator < (const ParticleEffect& other) const
	{
		if (this->partEff_name_s < other.partEff_name_s)
		{
			return true;
		}
		else return false;
	}

	

	

};

struct ParticleEffectLayer
{
	std::string effectLayer_effectTexture_path_s; //путь текстуры стринг
	fs::path effectLayer_effectTexture_path_p; //путь текстуры паз
	TextureData* effectLayer_TextureData; //ссылка на текстуру
	std::string effectLayer_file_exist = "-"; //существует ли файл текстуры

	bool operator ==(const ParticleEffectLayer& other)
	{
		if (
			this->effectLayer_effectTexture_path_s == other.effectLayer_effectTexture_path_s &&
			this->effectLayer_effectTexture_path_p == other.effectLayer_effectTexture_path_p &&
			this->effectLayer_TextureData == other.effectLayer_TextureData &&
			this->effectLayer_file_exist == other.effectLayer_file_exist
			)
			return true;
		else return false;
	}

	bool operator ==(const ParticleEffectLayer& other) const
	{
		if (
			this->effectLayer_effectTexture_path_s == other.effectLayer_effectTexture_path_s &&
			this->effectLayer_effectTexture_path_p == other.effectLayer_effectTexture_path_p &&
			this->effectLayer_TextureData == other.effectLayer_TextureData &&
			this->effectLayer_file_exist == other.effectLayer_file_exist
			)
			return true;
		else return false;
	}

	bool operator < (const ParticleEffectLayer& other)
	{
		if (this->effectLayer_effectTexture_path_s < other.effectLayer_effectTexture_path_s)
		{
			return true;
		}
		else return false;
	}

	bool operator < (const ParticleEffectLayer& other) const
	{
		if (this->effectLayer_effectTexture_path_s < other.effectLayer_effectTexture_path_s)
		{
			return true;
		}
		else return false;
	}


};

extern std::set<TextureData>			textures;
extern std::multiset<GameFieldRes*>		GameField_objects;
extern std::multiset<ObjLibItem*>		ObjLib_items;
extern std::multiset<ObjLibLayer*>		ObjLib_layers;

void DeleteFromGamefieldResources(TextureData* td);

void DeleteFromObjectLibrary(TextureData* td);

struct TextureData
{	
	std::string TD_s_texture_name; //полный путь файла с именем стринг
	fs::path	TD_texture_name; //путь файла с именем

	//cluster где юзается (ObjectLibrary, где юзается)
	mutable std::string TD_clusters_OL;
	mutable std::string TD_clusters_EF;

	mutable std::set <GameFieldRes*> TD_GRs; //для текстуры только 1 запись в Gamefield_Resources.xml
	mutable std::string TD_exist_in_GR = "-";

	//mutable std::vector<ObjLibItem*> TD_ObjLib_objects; //для одной текстуры может быть множество объектов в ObjectLibrary.xml

	mutable std::string TD_exist_in_OL = "-";
	//mutable std::vector <ChapterIds> TD_Chapter_dataids;

	mutable std::string TD_exist_in_EF = "-";
	mutable std::set <ParticleEffect*> TD_effects;

	mutable std::string TD_exist_in_CH = "-";

	mutable std::string TD_EF_exist_in_CH = "-";
	
	mutable bool TD_problem = false;

	mutable int TD_size; //размер текстуры
	mutable bool TD_to_delete = false;


	bool operator <(const TextureData& other)
	{
		if (this->TD_s_texture_name < other.TD_s_texture_name)
		{
			return true;
		}
		else return false;
	}

	bool operator <(const TextureData& other) const
	{
		if (this->TD_s_texture_name < other.TD_s_texture_name)
		{
			return true;
		}
		else return false;
	}

	bool operator ==(const TextureData& other)
	{
		if 
			(
			this->TD_s_texture_name	==other.TD_s_texture_name
				)
		{
			return true;
		}
		else return false;
	}

	bool operator ==(const TextureData& other) const
	{
		if
			(	
				this->TD_s_texture_name == other.TD_s_texture_name
				)
		{
			return true;
		}
		else return false;
	}
	
	//~TextureData()
	//{
	//	LOG_IN_FILE("деструктор для :" << this << '\t' << this->TD_texture_name.string() << std::endl);
	//	
	//	//texture
	//	//gr
	//	//item
	//	//layers

	//	

	//	
	//}
};


extern std::set<TextureData>			textures;
extern std::multiset<GameFieldRes*>		GameField_objects;
extern std::multiset<ObjLibItem*>		ObjLib_items;
extern std::multiset<ObjLibLayer*>		ObjLib_layers;
extern std::multiset<ChapterData*>		CH_objects;
extern std::set<ParticleEffect*>		particle_effects;

extern std::vector<fs::path>			problem_textures_path;
extern std::multiset<CH_ParticleEffect>meta_particle_repair_effects;

extern std::list<std::string>			CH_files;
extern std::list<fs::path>				cluster_folders;
extern std::vector<fs::path>			ObjLib_files;

extern std::vector<std::string>			repairs;
extern std::vector<std::string>			steps;

extern std::string						chosen_repair;
extern std::string						chosen_step;

extern std::multimap<fs::path, fs::path> texture_particle_effect; //текстура, эффект
extern bool cancelExecution;



//очистить лог
void Clear_LogFile();

void GetTextureFiles();

int Count_GameFieldRes();

int Count_ObjectLibrary();

int Count_ChapterData();

int Count_ParticleEffect();

void Get_GameFieldRes_Info();

void Get_ObjectLibrary_Info();

void Get_ChapterData_Info();

void Get_ParticleEffect_Info();

void DeleteOrNot();

void GetAttributes(ChapterData& ch);

void Get_dead_effects();

void DeleteFromGamefieldResources(TextureData* td);

void DeleteFromObjectLibrary(TextureData* td);

TextureData * FindTexture(fs::path texture_path);

ParticleEffect * FindEffect(fs::path effect_path);

void RemoveProblems();

std::string GetParticleEffectStep(std::string s);

std::string GetParticleName(std::string s);

static std::string GetAttr_CH(std::string text_to_parsing, std::string attribute);

void OL_Clusters_in_one_string();

static std::set<std::string> Compare2Folder(const std::string path1, const std::string path2);

static bool NoBounce(std::string id, std::string attr, std::string attr_value);

bool ExistFile(std::string filePath);

bool ExistDirectory(std::string directoryPath);

void GetChapterFiles();

void GetObjectLibraryFiles();

void DeleteEffectFromCommonFile(fs::path path);

void RemoveEmptyEffectFolder();

void RemoveEmptyFolders();

void FillRepairsAndSteps();


















#pragma once

#include "Core.h"
#include "tinyxml2.h"


namespace MyTool {

	using namespace System;
	using namespace System::Windows::Forms;

	namespace fs = boost::filesystem;

	extern unsigned int texture_deleted;
	extern unsigned int texture_deleted_size;
	extern unsigned int resources_texture_deleted;
	extern unsigned int resources_texture_deleted_size;
	extern unsigned int OL_items_deleted;

	//template<class T>
	//void PrintToLogFile(T begin, T end, std::string log_path);

	/////////////////////////////////
	class TextureData;
	class TextureAura;
	class ChapterData;
	class ObjLibItem;
	class ObjLibLayer;
	class ParticleEffect;
	class ParticleEffectLayer;
	class GameFieldRes;
	class CH_ParticleEffect;


	extern std::set<TextureData*>			static_textures;
	extern std::set<TextureData*>			aura_textures;


	extern std::multiset<GameFieldRes*>		GameField_static_textures;
	extern std::multiset<GameFieldRes*>		GameField_aura_textures;


	extern std::multiset<ObjLibItem*>		ObjLib_items;

	extern std::multiset<ObjLibLayer*>		ObjLib_layer_textures;
	extern std::multiset<ObjLibLayer*>		ObjLib_layer_xml_effects;
	extern std::multiset<ObjLibLayer*>		ObjLib_layer_swl_effects;
	extern std::multiset<ObjLibLayer*>		ObjLib_layer_light_effects;
	extern std::multiset<ObjLibLayer*>		ObjLib_layer_light_aura;
	extern std::multiset<ObjLibLayer*>		ObjLib_layer_lights;
	
	
	
	extern std::multiset<ChapterData*>		CH_objects;
	extern std::multiset<ParticleEffect*>		particle_effects_XML;
	//extern std::multiset<ParticleEffect*>		particle_completed_repair_effects_SWL;
	extern std::set<ParticleEffectLayer*>	particle_effect_layers;


	extern std::vector<fs::path>				problem_textures_path;
	extern std::multiset<CH_ParticleEffect>		meta_particle_repair_effects;

	extern std::multimap<fs::path, fs::path>	texture_particle_effect; //текстура, эффект


	enum class TextureType
	{
		STATIC = 0, AURA
	};

	enum class LayerType
	{
		TEXTURE=0, EFFECT_XML, EFFECT_SWL_OR_SPINE, LIGHT_WITH_EFFECT, LIGHT_WITH_AURA, LIGHT
	};

	enum class ParticleEffectLayerTexture
	{
		PARTICLE = 0, STATIC, AURA, OTHER
	};

	class GameFieldRes
	{
	public:
		
		GameFieldRes::GameFieldRes(std::string&& path, tinyxml2::XMLElement* group_node, tinyxml2::XMLElement* item_node, TextureType type);
		~GameFieldRes();

		
		std::string  gameFieldRes_s_full_path; // для сортировки сета

		TextureType gameFieldRes_type;

		std::string	 gameFieldRes_group; //атлас

		std::string  gameFieldRes_id; //используется ObjectLibrary.xml
		std::string  gameFieldRes_path_attr; //имя файла
		std::string  gameFieldRes_group_path; //для удаления

		bool gameFieldRes_exist_in_OL;
		
		TextureData*  gameFieldRes_TextureData = nullptr;
		std::vector <ObjLibLayer*>  gameFieldRes_ObjLibLayers ; //лейеры которые составляет данный GameFieldRes

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
		bool operator ==(const GameFieldRes& other)
		{	
			if (this->gameFieldRes_s_full_path == other.gameFieldRes_s_full_path)
				return true;
			else return false;
		}
		bool operator ==(const GameFieldRes& other) const
		{
			if (this->gameFieldRes_s_full_path == other.gameFieldRes_s_full_path)
				return true;
			else return false;
		}

	};

	class ObjLibLayer //<layer type="texture" name="texture" texture="cl1_flowerbed_porch_var2_flower4" xOffset="-80" yOffset="-30" xMin="-40" yMin="-40" zMin="0" xMax="40" yMax="40" zMax="44" />
	{	
	public:
		ObjLibLayer(ObjLibItem* obj_item, tinyxml2::XMLElement* layer_node);
		~ObjLibLayer();

		std::string objLayer_texture_attr; //texture="cl1_flowerbed_porch_var2_flower4"

		LayerType objLayer_type; //type="texture"//light//effect

		std::string objLayer_name; //name="texture" || name="spine" || name="clock"

		std::string objLayer_zOrder; //

		std::string objLayer_aura;

		GameFieldRes* objLayer_GameFieldRes; // только если type="texture" или type="effect" и name="spine" или type="light" и есть aura. ParticleEffects(не swl) нет в GameFieldRes
		ObjLibItem* objLayer_item; //item где присутствует данный лейер
		ParticleEffect* objLayer_ParticleEffect; //если type="effect"  или type="light" и есть texture

		bool operator ==(const ObjLibLayer& other)
		{
			if (
				this->objLayer_texture_attr == other.objLayer_texture_attr
				)
				return true;
			else return false;
		}
		bool operator ==(const ObjLibLayer& other) const
		{
			if (
				this->objLayer_texture_attr == other.objLayer_texture_attr
				)
				return true;
			else return false;
		}
		bool operator <(const ObjLibLayer& other)
		{
			if (this->objLayer_texture_attr < other.objLayer_texture_attr)
			{
				return true;
			}
			else return false;
		}
		bool operator <(const ObjLibLayer& other) const
		{
			if (this->objLayer_texture_attr < other.objLayer_texture_attr)
			{
				return true;
			}
			else return false;
		}
	};

	class ObjLibItem //<item id="flowerbed_porch_var3_flower1" noRedesignDeformation="true">
	{	
	public:
		~ObjLibItem();
		//если удаляю - objItem_ChapterDatas пустая

		
		ObjLibItem(fs::path path, tinyxml2::XMLElement* item_node, tinyxml2::XMLElement* objects_node);

		std::string objItem_item_id;
		std::string objItem_instanceClass;
		std::string objItem_defaultZOrder;
		std::string objItem_isIndoor;
		std::string objItem_cluster;
		std::string objItem_noRedesignDeformation;
		std::vector<ObjLibLayer*> objItem_layers; //лейеры из которых состоит item
		std::vector<ChapterData*> objItem_ChapterDatas; //чаптеры где находится айтем

		bool objItem_exist_on_meta;

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
				this->objItem_item_id == other.objItem_item_id					&&
				this->objItem_cluster == other.objItem_cluster					&&
				this->objItem_instanceClass == other.objItem_instanceClass			&&
				this->objItem_defaultZOrder == other.objItem_defaultZOrder			&&
				this->objItem_isIndoor == other.objItem_isIndoor				&&
				this->objItem_noRedesignDeformation == other.objItem_noRedesignDeformation	&&
				this->objItem_layers == other.objItem_layers &&
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

	class ChapterData
	{	
	public:
		~ChapterData() { }

		ChapterData(fs::path ch_file,
			std::string hashid,
			std::string text_node,
			std::string storyInfo_chapter_id,
			std::string storyInfo_repair,
			std::string storyInfo_step);
		// сортировка по dataid
		//std::string CH_chapter_id_CH_repair_CH_step_СH_id_CH_dataid; //чаптер + рипейр + степ + хешайди + текст - адская хрень для сортировки в сете
		fs::path chData_file;
		std::string chData_hashid;
		std::string chData_dataid;
		std::string chData_text_node;
		std::string chData_storyInfo_chapter_id;
		std::string chData_storyInfo_repair;
		std::string chData_storyInfo_step;
		

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

		ObjLibItem* chData_ObjLibItem; //вдруг имена айтемов могут повторяться в разных файлах ObjectLibrary (в разных кластерах)

		bool operator <(const ChapterData& other)
		{
			if (this->chData_dataid < other.chData_dataid)
			{
				return true;
			}
			else return false;
		}
		bool operator <(const ChapterData& other) const
		{
			if (this->chData_dataid < other.chData_dataid)
			{
				return true;
			}
			else return false;
		}
		bool operator ==(const ChapterData& other)
		{
			if
				(	
					this->chData_file == other.chData_file &&
					this->chData_dataid == other.chData_dataid &&
					this->chData_text_node == other.chData_text_node &&
					this->chData_storyInfo_chapter_id == other.chData_storyInfo_chapter_id &&
					this->chData_storyInfo_repair == other.chData_storyInfo_repair &&
					this->chData_storyInfo_step == other.chData_storyInfo_step &&
					this->chData_hashid == other.chData_hashid &&
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
					this->chData_file == other.chData_file &&
					this->chData_dataid == other.chData_dataid &&
					this->chData_text_node == other.chData_text_node &&
					this->chData_storyInfo_chapter_id == other.chData_storyInfo_chapter_id &&
					this->chData_storyInfo_repair == other.chData_storyInfo_repair &&
					this->chData_storyInfo_step == other.chData_storyInfo_step &&
					this->chData_hashid == other.chData_hashid &&
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

	class ParticleEffect
	{	
	public:
		~ParticleEffect() 
		{
			LOG_IN_FILE("ParticleEffect destructor");
		}

		ParticleEffect(std::string&& path, std::string&& name);

		std::string partEff_string_path; // путь xml файла стринг (для сортировки сета)
		std::string partEff_name;
		//fs::path partEff_path; // путь xml файла паз

		std::string partEff_cluster; // кластер где лежит

		bool partEff_exist_on_meta; //есть ли на мете
		bool partEff_exist_in_OL; //есть ли в ObjectLibrary

		mutable std::string partEff_dead;
		mutable bool partEff_to_delete = false;

		std::vector<ParticleEffectLayer*>partEff_ParticleEffectLayers; //все слои <ParticleSystem> - текстуры эффекта
		std::vector<ObjLibLayer*> partEff_ObjLibLayers; //items где он есть зачем?

		static std::string GetClusterName(const std::string& path)
		{
			int pos = path.find("cluster");
			if (pos != -1)
			{
				std::string name;
				
				while (path[pos] != '/' && path[pos] != '\\')
				{
					name += path[pos];
					pos++;
				}
				return name;
			}
			else return "base_mm/effects";
		}

		bool operator ==(const ParticleEffect& other)
		{
			if (
				this->partEff_string_path == other.partEff_string_path										&&
				this->partEff_name == other.partEff_name								  &&
				this->partEff_cluster == other.partEff_cluster								  &&
				this->partEff_exist_on_meta == other.partEff_exist_on_meta						  &&
				this->partEff_dead == other.partEff_dead									  &&
				this->partEff_to_delete == other.partEff_to_delete							  &&
				this->partEff_ObjLibLayers == other.partEff_ObjLibLayers					  &&
				this->partEff_ParticleEffectLayers == other.partEff_ParticleEffectLayers	  
				)
				return true;
			else return false;
		}
		bool operator ==(const ParticleEffect& other) const
		{
			if (
				this->partEff_string_path == other.partEff_string_path										&&
				this->partEff_name == other.partEff_name								  &&
				this->partEff_cluster == other.partEff_cluster								  &&
				this->partEff_exist_on_meta == other.partEff_exist_on_meta						  &&
				this->partEff_dead == other.partEff_dead									  &&
				this->partEff_to_delete == other.partEff_to_delete							  &&
				this->partEff_ObjLibLayers == other.partEff_ObjLibLayers					  &&
				this->partEff_ParticleEffectLayers == other.partEff_ParticleEffectLayers
				)
				return true;
			else return false;
		}
		bool operator < (const ParticleEffect& other)
		{
			if (this->partEff_name < other.partEff_name)
			{
				return true;
			}
			else return false;
		}
		bool operator < (const ParticleEffect& other) const
		{
			if (this->partEff_name < other.partEff_name)
			{
				return true;
			}
			else return false;
		}
	};

	class ParticleEffectLayer
	{
	public:
		~ParticleEffectLayer() {}

		ParticleEffectLayer(std::string&& path, ParticleEffect* effect); //конструктор
			
		std::string effectLayer_path; //путь текстуры стринг
		//fs::path effectLayer_path;
		bool effectLayer_file_exist; //существует ли файл текстуры

		ParticleEffectLayerTexture effectLayer_texture_type;

		ParticleEffect* effectLayer_parent_effect; //эффект-родитель
		TextureData* effectLayer_TextureData; //ссылка на текстуру
		
		bool operator ==(const ParticleEffectLayer& other)
		{
			if (
				this->effectLayer_path == other.effectLayer_path &&
				this->effectLayer_TextureData == other.effectLayer_TextureData &&
				this->effectLayer_file_exist == other.effectLayer_file_exist
				)
				return true;
			else return false;
		}
		bool operator ==(const ParticleEffectLayer& other) const
		{
			if (
				this->effectLayer_path == other.effectLayer_path &&
				this->effectLayer_TextureData == other.effectLayer_TextureData &&
				this->effectLayer_file_exist == other.effectLayer_file_exist
				)
				return true;
			else return false;
		}
		bool operator < (const ParticleEffectLayer& other)
		{
			if (this->effectLayer_path < other.effectLayer_path)
			{
				return true;
			}
			else return false;
		}
		bool operator < (const ParticleEffectLayer& other) const
		{
			if (this->effectLayer_path < other.effectLayer_path)
			{
				return true;
			}
			else return false;
		}
	};

	class TextureData
	{
	public:
		~TextureData();

		TextureData(fs::path path, TextureType type);

		std::string TD_texture_name; //полный путь файла с именем стринг (для сортировки сета)
		fs::path	TD_path; //путь файла с именем

		TextureType TD_type;

		mutable int TD_size; //размер текстуры

		mutable std::string TD_clusters_OL; //cluster где юзается (ObjectLibrary, где юзается)
		mutable std::string TD_clusters_EF;
		mutable bool TD_exist_in_GR;
		mutable bool TD_exist_in_OL;
		mutable bool TD_exist_in_EF;
		mutable bool TD_exist_on_meta;
		mutable bool TD_EF_exist_on_meta;

		mutable bool TD_is_aura;
		mutable bool TD_problem;
		mutable bool TD_to_delete;

		mutable std::multiset <GameFieldRes*> TD_GRs; //TODO ???? почему сет? для текстуры только 1 запись в Gamefield_Resources.xml - не обязательно
		mutable std::set <ParticleEffect*> TD_effects;

		bool operator <(const TextureData& other)
		{
			if (this->TD_texture_name < other.TD_texture_name)
			{
				return true;
			}
			else return false;
		}
		bool operator <(const TextureData& other) const
		{
			if (this->TD_texture_name < other.TD_texture_name)
			{
				return true;
			}
			else return false;
		}
		bool operator ==(const TextureData& other)
		{
			if
				(
					this->TD_texture_name == other.TD_texture_name		&&
					this->TD_path == other.TD_path		&&
					this->TD_clusters_OL == other.TD_clusters_OL			&&
					this->TD_clusters_EF == other.TD_clusters_EF			&&
					this->TD_GRs == other.TD_GRs							&&
					this->TD_exist_in_GR == other.TD_exist_in_GR			&&
					this->TD_exist_in_OL == other.TD_exist_in_OL			&&
					this->TD_exist_in_EF == other.TD_exist_in_EF			&&
					this->TD_effects == other.TD_effects					&&
					this->TD_exist_on_meta == other.TD_exist_on_meta			&&
					this->TD_EF_exist_on_meta == other.TD_EF_exist_on_meta		&&
					this->TD_problem == other.TD_problem					&&
					this->TD_size == other.TD_size							&&
					this->TD_to_delete == other.TD_to_delete
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
					this->TD_texture_name == other.TD_texture_name		&&
					this->TD_path == other.TD_path		&&
					this->TD_clusters_OL == other.TD_clusters_OL			&&
					this->TD_clusters_EF == other.TD_clusters_EF			&&
					this->TD_GRs == other.TD_GRs							&&
					this->TD_exist_in_GR == other.TD_exist_in_GR			&&
					this->TD_exist_in_OL == other.TD_exist_in_OL			&&
					this->TD_exist_in_EF == other.TD_exist_in_EF			&&
					this->TD_effects == other.TD_effects					&&
					this->TD_exist_on_meta == other.TD_exist_on_meta			&&
					this->TD_EF_exist_on_meta == other.TD_EF_exist_on_meta		&&
					this->TD_problem == other.TD_problem					&&
					this->TD_size == other.TD_size							&&
					this->TD_to_delete == other.TD_to_delete
					)
			{
				return true;
			}
			else return false;
		}

	};

	void GetTextureFiles();
	int CountGameFieldRes();
	int CountObjectLibrary();
	int CountChapterData();
	int CountParticleEffect();
	void GetGameFieldResData();
	void GetParticleEffectData();
	void GetObjectLibraryData();
	void GetChapterData();

	

	void DeleteOrNot();

	void GetAttributes(ChapterData& ch);

	void Get_dead_effects();

	void DeleteFromGamefieldResources(GameFieldRes* gr);

	void DeleteFromObjectLibrary(ObjLibItem* td);

	void DeleteNoLayersItem();

	TextureData* FindTexture(const fs::path& texture_path, std::set<TextureData*>& container);
	ParticleEffect* FindEffectByPath(fs::path effect_path, std::multiset<ParticleEffect*>& container);
	ParticleEffect* FindParticleEffectByName(std::string& name, std::multiset<ParticleEffect*>& container);
	GameFieldRes* FindGameFieldResById(std::string id, std::multiset<GameFieldRes*>& container);
	ObjLibItem* FindObjLibItemById(std::string id);

	void RemoveProblems();

	std::string GetParticleEffectStep(std::string s);

	std::string GetParticleName(std::string s);

	std::string GetAttr_CH(std::string text_to_parsing, std::string attribute);

	void OL_Clusters_in_one_string(std::set<TextureData*>&container);

	std::set<std::string> Compare2Folder(const std::string path1, const std::string path2);

	bool NoBounce(std::string id, std::string attr, std::string attr_value);

	bool ExistFile(std::string filePath);

	bool ExistDirectory(std::string directoryPath);

	void GetChapterFiles();

	void GetObjectLibraryFiles();

	void DeleteEffectFromCommonFile(fs::path path);

	void RemoveEmptyEffectFolder();

	void RemoveEmptyFolders();

	void FillRepairsAndSteps();
	void DeleteLayer(ObjLibLayer * layer);
	void DeleteItem(ObjLibItem* item);
	void DeleteGamefieldRes(GameFieldRes* gr);
	void DeleteTexture(TextureData* td);
	ObjLibItem* FindObjLibItemById(std::string id);
	std::pair<int, int> CountTextureFiles();
	std::string& GetLayerNameBeforePoint(std::string& fullname);
	std::string GetParentFolderName(const std::string& path);
	std::wstring s2ws(const std::string& str);
	void DeleteLayerFromObjectLibrary(ObjLibLayer* layer);
}



















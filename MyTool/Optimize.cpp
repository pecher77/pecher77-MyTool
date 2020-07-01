#include "pch.h"
#include "Core.h"
#include "tinyxml2.h"
#include "Optimize.h"
#include "MyForm3.h"


namespace MyTool {

	unsigned int texture_deleted;
	unsigned int texture_deleted_size;
	unsigned int resources_texture_deleted;
	unsigned int resources_texture_deleted_size;
	unsigned int OL_items_deleted;


	std::set<TextureData*>			static_textures;
	std::set<TextureData*>			aura_textures;

	std::multiset<GameFieldRes*>	GameField_static_textures;
	std::multiset<GameFieldRes*>	GameField_aura_textures;

	std::multiset<ObjLibItem*>		ObjLib_items;

	std::multiset<ObjLibLayer*>		ObjLib_layer_textures;
	std::multiset<ObjLibLayer*>		ObjLib_layer_xml_effects;
	std::multiset<ObjLibLayer*>		ObjLib_layer_swl_effects;
	std::multiset<ObjLibLayer*>		ObjLib_layer_light_effects;
	std::multiset<ObjLibLayer*>		ObjLib_layer_light_aura;
	std::multiset<ObjLibLayer*>		ObjLib_layer_lights;
	

	std::multiset<ChapterData*>		CH_objects;

	std::multiset<ParticleEffect*>		particle_effects_XML;
	//std::multiset<ParticleEffect*>		particle_completed_repair_effects_SWL;

	std::set<ParticleEffectLayer*>	particle_effect_layers;

	std::vector<fs::path>				problem_textures_path;
	

	std::multimap<fs::path, fs::path>	texture_particle_effect; //текстура, эффект

//template<class T>
//void PrintToLogFile(T begin, T end, std::string log_path)
//{
//	ofstream ofs_log(log_path);
//
//	for (auto it = begin; it != end; it++)
//	{
//		ofs_log << left << *it << endl;
//	}
//	ofs_log.close();
//}

TextureData::TextureData(fs::path path, TextureType type)
		: TD_texture_name(path.string()), TD_path(path), TD_type(type), TD_size(fs::file_size(path)),
		TD_clusters_OL("-"), TD_clusters_EF("-"), TD_exist_in_GR(false), TD_exist_in_OL(false), TD_exist_in_EF(false),
		TD_exist_on_meta(false), TD_EF_exist_on_meta(false), TD_problem(false), TD_to_delete(false) {}

TextureData::~TextureData()
{
	LOG_IN_FILE(deleting_count << '\t' << "Deleted texture object");

	//if (!TD_effects.empty()) //если есть эффекты - не удаляю
}


GameFieldRes::GameFieldRes(std::string&& path, tinyxml2::XMLElement* group_node, tinyxml2::XMLElement* item_node, TextureType type)
	:	gameFieldRes_s_full_path(std::move(path)),
		gameFieldRes_type(type),
		gameFieldRes_group(group_node->Attribute("group") ? group_node->Attribute("group") : "none"),
		gameFieldRes_id(item_node->Attribute("id")),
		gameFieldRes_path_attr(item_node->Attribute("path")),
		gameFieldRes_group_path(group_node->Attribute("basePath")),
		gameFieldRes_exist_in_OL(false), gameFieldRes_TextureData(nullptr)
{		

		fs::path p_path = gameFieldRes_s_full_path;

		switch (type)
		{
		case MyTool::TextureType::STATIC:
			gameFieldRes_TextureData = MyTool::FindTexture(p_path, static_textures);
			break;
		case MyTool::TextureType::AURA:
			gameFieldRes_TextureData = MyTool::FindTexture(p_path, aura_textures);
			break;
		default:
			break;
		}

	if (!gameFieldRes_TextureData) //если файла текстуры нет
	{
			LOG_IN_FILE("ERROR:: texture from GamefieldResources doesnt exist: " << gameFieldRes_s_full_path); //не может быть или был бы HALT при старте игры
			assert(false && "Static texture from GamefieldResources doesnt exist - check LOGFILE");
	}
	else 
	{
		gameFieldRes_TextureData->TD_GRs.emplace(this); //передаем в текстуру ссылку на gr
		gameFieldRes_TextureData->TD_exist_in_GR = true; //текстура есть в GamefieldResources
	}
}

GameFieldRes::~GameFieldRes()
{
	LOG_IN_FILE(deleting_count << '\t' << "deleted GameFieldRes object");
}


ParticleEffect::ParticleEffect(std::string&& path, std::string&& name)
	: partEff_string_path(std::move(path)), partEff_name(std::move(name)), partEff_cluster(GetClusterName(partEff_name)),
	partEff_exist_on_meta(false), partEff_exist_in_OL(false), partEff_dead("-"), partEff_to_delete(false)
{
}

ParticleEffectLayer::ParticleEffectLayer(std::string&& path, ParticleEffect* effect)
	: effectLayer_path(std::move(path)),
	effectLayer_parent_effect(effect), effectLayer_TextureData(nullptr)
{	

	fs::path path_p = effectLayer_path;
	effectLayer_file_exist = fs::exists(path_p);
	if (!effectLayer_file_exist)
	{
		effectLayer_file_exist = fs::exists(path_p.replace_extension(".jpg"));
		if (effectLayer_file_exist) 
			effectLayer_path = path_p.replace_extension(".jpg").string();
	}
		

	if (effectLayer_path.find("textures/particles/") != -1)
	{
		effectLayer_texture_type = ParticleEffectLayerTexture::PARTICLE;
		if (!effectLayer_file_exist)
		{
			LOG_IN_FILE("Warning :: Particle layer PARTICLE texture file NOT EXIST :" << '\t' << effectLayer_path << '\t' << " of Particle_effect :" << '\t' << effect->partEff_name);
		}
	}
	else

		if (effectLayer_path.find("/static/") != -1)
		{
			effectLayer_texture_type = ParticleEffectLayerTexture::STATIC;
			if (!effectLayer_file_exist)
			{
				LOG_IN_FILE("Warning :: Particle layer STATIC texture file NOT EXIST :" << '\t' << effectLayer_path << '\t' << " of Particle_effect :" << '\t' << effect->partEff_name);
			}
		}
		else
			if (effectLayer_path.find("textures/Gamefield/Night/") != -1)
			{
				effectLayer_texture_type = ParticleEffectLayerTexture::AURA;
				if (!effectLayer_file_exist)
				{
					LOG_IN_FILE("Warning :: Particle layer AURA texture file NOT EXIST :" << '\t' << effectLayer_path << '\t' << " of Particle_effect :" << '\t' << effect->partEff_name);
				}
			}
			else
			{
				effectLayer_texture_type = ParticleEffectLayerTexture::OTHER;
				//LOG_IN_FILE("Warning :: Particle layer uses non-define texture :" << '\t' << effectLayer_path << '\t' << " of Particle_effect :" << '\t' << effect->partEff_name);
			}

	if (effectLayer_file_exist)
	{	
		switch (effectLayer_texture_type)
		{
		case MyTool::ParticleEffectLayerTexture::PARTICLE:
			break;
		case MyTool::ParticleEffectLayerTexture::STATIC:
			effectLayer_TextureData = FindTexture(path_p, static_textures);
			break;
		case MyTool::ParticleEffectLayerTexture::AURA:
			effectLayer_TextureData = FindTexture(path_p, aura_textures);
			break;
		case MyTool::ParticleEffectLayerTexture::OTHER:
			break;
		default:
			break;
		}
	}

	if (effectLayer_TextureData)
	{
		effectLayer_TextureData->TD_effects.emplace(effect); //std::set <ParticleEffect*> TD_effects; эффект не добавится несколько раз
		effectLayer_TextureData->TD_exist_in_EF = true;
	}
}

ObjLibItem::ObjLibItem(fs::path path, tinyxml2::XMLElement* item_node, tinyxml2::XMLElement* Objects_node)
	: objItem_item_id(item_node->Attribute("id")), objItem_instanceClass(Objects_node->Attribute("instanceClass")),
	objItem_defaultZOrder(Objects_node->Attribute("defaultZOrder")? Objects_node->Attribute("defaultZOrder") : "-"),
	objItem_isIndoor(Objects_node->Attribute("isIndoor")? Objects_node->Attribute("isIndoor") : "-"),
	objItem_cluster(path.parent_path().stem().string()),
	objItem_noRedesignDeformation(item_node->Attribute("noRedesignDeformation") ? item_node->Attribute("noRedesignDeformation") : "false"),
	objItem_exist_on_meta(false)
{	
}

ObjLibItem::~ObjLibItem()
{	
	LOG_IN_FILE(OL_items_deleted << '\t' << "deleted ObjLibItem object");

	//ObjLib_items.erase(this);

}

ObjLibLayer::ObjLibLayer(MyTool::ObjLibItem* obj_item, tinyxml2::XMLElement* layer_node)
	:objLayer_item(obj_item), 
	objLayer_texture_attr(layer_node->Attribute("texture")? layer_node->Attribute("texture") : "-"),
	objLayer_name(layer_node->Attribute("name")),
	objLayer_zOrder(layer_node->Attribute("zOrder")? layer_node->Attribute("zOrder"):"-"),
	objLayer_aura(layer_node->Attribute("aura")? layer_node->Attribute("aura") : "-"), objLayer_GameFieldRes(nullptr), objLayer_ParticleEffect(nullptr)
{	

	obj_item->objItem_layers.push_back(this);
	if (to_string(layer_node->Attribute("type")) == "texture")
	{
		objLayer_type = LayerType::TEXTURE;
		objLayer_GameFieldRes = FindGameFieldResById(objLayer_texture_attr, GameField_static_textures);
		if (!objLayer_GameFieldRes)
		{
			LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'texture' doesnt exist in GameFieldResource:" <<'\t'<< objLayer_texture_attr << '\t' << "line in file :" << '\t' << layer_node->GetLineNum());
			//assert(false);
		}
	}
	else if (to_string(layer_node->Attribute("type")) == "effect")
	{
		if (objLayer_texture_attr.find(".") != -1) //в аттрибуте texture есть точка, значит это swl или spine
			objLayer_type = LayerType::EFFECT_SWL_OR_SPINE;
		else
		{
			objLayer_type = LayerType::EFFECT_XML;
			objLayer_ParticleEffect = FindParticleEffectByName(objLayer_texture_attr, particle_effects_XML);
		}
	}
	else if (to_string(layer_node->Attribute("type")) == "light")
		if (objLayer_aura != "-") //если аура
		{	
			objLayer_type = LayerType::LIGHT_WITH_AURA;
			objLayer_texture_attr = objLayer_aura;
			objLayer_GameFieldRes = FindGameFieldResById(objLayer_aura, GameField_aura_textures);
			if (!objLayer_GameFieldRes)
			{
				LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'light' with aura doesnt exist in GameFieldResource auras:" << '\t' << objLayer_aura << '\t' << "line in file :" << '\t' << layer_node->GetLineNum());
			}
		}
		else if (objLayer_name == "texture" && objLayer_texture_attr != "-") //
		{	
			objLayer_type = LayerType::LIGHT_WITH_EFFECT;
			objLayer_ParticleEffect = FindParticleEffectByName(objLayer_texture_attr, particle_effects_XML);
		}
		else
		{	
			objLayer_type = LayerType::LIGHT;
			LOG_IN_FILE("LIGHT WITHOUT AURA OR TEXTURE. ObjectLibrary line :" <<'\t'<< layer_node->GetLineNum());
		}

	if (objLayer_GameFieldRes) //если тип текстура или свет с аурой
	{	
		objLayer_GameFieldRes->gameFieldRes_exist_in_OL = true;
		objLayer_GameFieldRes->gameFieldRes_ObjLibLayers.push_back(this);

		if (!objLayer_GameFieldRes->gameFieldRes_TextureData)
		{
			//LOG_IN_FILE("WARNING::  ObjectLibrary layer type 'texture' placed in non-static folder as layer in object (ObjectLibrary.xml): " << '\t' << objLayer_texture_attr << "line in file :" 
			//	<< layer_node->GetLineNum()); //не может быть GR без существующей текстуры - был бы HALT при запуске
		}
		else
		objLayer_GameFieldRes->gameFieldRes_TextureData->TD_exist_in_OL = true;
	}

	if (objLayer_ParticleEffect) //LayerType::EFFECT_XML или свет с эффектом
	{	
		objLayer_ParticleEffect->partEff_ObjLibLayers.push_back(this);
		objLayer_ParticleEffect->partEff_exist_in_OL = true;

		for (auto& eff_layer : objLayer_ParticleEffect->partEff_ParticleEffectLayers)
		{
			if (eff_layer->effectLayer_TextureData)
				eff_layer->effectLayer_TextureData->TD_exist_in_OL = true;
		}
	}
	else
	{
		if (objLayer_type == LayerType::LIGHT_WITH_EFFECT)
		{
			LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'light' with effect match no one ParticleEffect:" << '\t' << objLayer_texture_attr << '\t' << "line in file :" << '\t' << layer_node->GetLineNum());
		}
		else if (objLayer_type == LayerType::EFFECT_XML)
			LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'effect' match no one ParticleEffect:" << '\t' << objLayer_texture_attr << '\t' << "line in file :" << '\t' << layer_node->GetLineNum());
	}

}

ObjLibLayer::~ObjLibLayer()
{
	LOG_IN_FILE(deleting_count << '\t' << "deleted ObjLibLayer object");

}

ChapterData::ChapterData(fs::path ch_file,
	std::string hashid,
	std::string text_node,
	std::string storyInfo_chapter_id,
	std::string storyInfo_repair,
	std::string storyInfo_step)

	:chData_file(ch_file),
	chData_hashid(hashid),
	chData_text_node(text_node),
	chData_storyInfo_chapter_id(storyInfo_chapter_id),
	chData_storyInfo_repair(storyInfo_repair),
	chData_storyInfo_step(storyInfo_step), chData_ObjLibItem(nullptr)

{
	GetAttributes(*this);
	chData_ObjLibItem = FindObjLibItemById(chData_dataid);
	if (chData_ObjLibItem)
	{
		chData_ObjLibItem->objItem_ChapterDatas.push_back(this);
		chData_ObjLibItem->objItem_exist_on_meta = true;

		for (auto& layer : chData_ObjLibItem->objItem_layers)
		{	
			switch (layer->objLayer_type)
			{
			case LayerType::TEXTURE:
				if (!layer->objLayer_GameFieldRes) //в леере нет ссылки на GameFieldRes - ХАЛТ тольки при включении этого степа
				{
					LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'texture' EXISTED ON META doesnt exist in GamefieldRes" << '\t' << layer->objLayer_texture_attr << '\t' << "of item " << '\t' << layer->objLayer_item->objItem_item_id);
					//assert(false && "texture layer doesnt exist in GamefieldRes - check LOGFILE");
				}
				else
				{
					if (!layer->objLayer_GameFieldRes->gameFieldRes_TextureData) //в GameFieldRes нет ссылки на TextureData - не может быть ХАЛТ при запуске
					{
						LOG_IN_FILE("WARNING:: GamefieldRes path doesnt exist " << '\t' << layer->objLayer_GameFieldRes->gameFieldRes_s_full_path);
						//assert(false && "GamefieldRes path doesnt exist - check LOGFILE");
					}
					else
						layer->objLayer_GameFieldRes->gameFieldRes_TextureData->TD_exist_on_meta = true;
				}
				break;

			case LayerType::EFFECT_XML:
				if (!layer->objLayer_ParticleEffect)
				{
					LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'effect' EXISTED ON META match no one ParticleEffect:" << '\t' << layer->objLayer_texture_attr << '\t' << "of item " << '\t' << layer->objLayer_item->objItem_item_id);
				}
				else
				{
					layer->objLayer_ParticleEffect->partEff_exist_on_meta = true;
					for (auto& eff_layer : layer->objLayer_ParticleEffect->partEff_ParticleEffectLayers)
					{
						if (eff_layer->effectLayer_TextureData)
							eff_layer->effectLayer_TextureData->TD_EF_exist_on_meta = true;
					}
				}
				break;
			case LayerType::LIGHT_WITH_EFFECT:
				if (!layer->objLayer_ParticleEffect)
				{
					LOG_IN_FILE("WARNING:: ObjectLibrary layer type 'light' with effect EXISTED ON META match no one ParticleEffect:" << '\t' << layer->objLayer_texture_attr << '\t' << "of item " << '\t' << layer->objLayer_item->objItem_item_id);
				}
				else
				{
					layer->objLayer_ParticleEffect->partEff_exist_on_meta = true;
					for (auto& eff_layer : layer->objLayer_ParticleEffect->partEff_ParticleEffectLayers)
					{
						if (eff_layer->effectLayer_TextureData)
							eff_layer->effectLayer_TextureData->TD_EF_exist_on_meta = true;
					}
				}
				break;
			case LayerType::LIGHT_WITH_AURA:
				if (layer->objLayer_GameFieldRes)
				{
					if (layer->objLayer_GameFieldRes->gameFieldRes_TextureData)
						layer->objLayer_GameFieldRes->gameFieldRes_TextureData->TD_exist_on_meta = true;
					else
						LOG_IN_FILE("WARNING:: EXISTING ON META item " << chData_ObjLibItem->objItem_item_id << " with light Aura layer " << layer->objLayer_aura << " from GamefieldResources has no existing texture:" << layer->objLayer_GameFieldRes->gameFieldRes_s_full_path);
				}
				else
					LOG_IN_FILE("WARNING:: EXISTING ON META item with light Aura layer " << layer->objLayer_aura << " doesnt exist in GamefieldResources. ON META: "<<'\t'<<"CHAPTER_ID"<<'\t'<<this->chData_storyInfo_chapter_id << '\t' <<"REPAIR:" <<'\t' << this->chData_storyInfo_repair << '\t' <<"STEP:" <<'\t' << this->chData_storyInfo_step << '\t' <<"DATAID:"<<'\t' << this->chData_dataid);
				break;
			case LayerType::LIGHT: //не обрабатываем
				break;
			case LayerType::EFFECT_SWL_OR_SPINE: //не обрабатываем
				break;
			default:
				break;
			}
		}
	}
	else //HALT при запуске
	{
		//LOG_IN_FILE("WARNING:: texture layer doesnt exist in GamefieldRes" << '\t' << layer->objLayer_texture_attr << '\t' << "of item " << '\t' << layer->objLayer_item->objItem_item_id);
		//assert(false && "not found item in ObjectLibrary for dataid in Chapter, check LOGFILE"); //датаайди, которой нет в objectLibrary?? не может быть
	}
}

//пересчет для индикатора загрузки
#pragma region пересчет

std::pair<int,int> CountTextureFiles()
{	
	
	int static_textures = 0;
	int aura_textures = 0;
	
	//из папки
	fs::path path = path_game_folder;
	path /= "/base_mm/textures/Gamefield/static";
	//собираем статические текстуры
	fs::recursive_directory_iterator itr(path), end_itr;
	while (itr != end_itr)
	{
		if (cancelExecution)
			break;
		if (fs::is_regular_file(*itr) && itr->path().extension().string() == ".png")
		{
			static_textures++;
		}
		itr++;
	}

	//собираем ауры
	path = path_game_folder;
	path /= "/base_mm/textures/Gamefield/Night";
	fs::recursive_directory_iterator itr2(path), end_itr2;
	while (itr2 != end_itr2)
	{
		if (cancelExecution)
			break;
		if (fs::is_regular_file(*itr2) && itr2->path().extension().string() == ".png")
		{
			aura_textures++;
		}
		itr2++;
	}

	std::pair<int, int> all_textures(static_textures, aura_textures);

	return  all_textures;
}

int CountGameFieldRes()
{	

	//LOG_IN_FILE("Counting resources in: " << path_gamefield_resources);

	tinyxml2::XMLDocument Gamefield_Resources_doc;
	Gamefield_Resources_doc.LoadFile(path_gamefield_resources.c_str());

	std::string error = Gamefield_Resources_doc.ErrorStr();
	
	if (Gamefield_Resources_doc.Error() != 0)
	{	
		LOG_IN_FILE("ERROR XML STRUCT:: " << '\t' << path_gamefield_resources.c_str() << '\t' << error);
		assert(Gamefield_Resources_doc.Error() == 0 && "struct error of Resources.xml, check LOGFILE");
	}
	//LOG_IN_FILE("OK");

	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();
	int count = 0;

	for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
	{
		
		if (cancelExecution)
			return -1;


		//собираем Spine 
		if (Textures_group->Attribute("basePath") == NULL)
				continue;

		std::string path_t = Textures_group->Attribute("basePath");

		//считаем ауры 
		if (path_t == "textures/Gamefield/Night/")
		{
			for (tinyxml2::XMLElement* id_node = Textures_group->FirstChildElement(); id_node != NULL; id_node = id_node->NextSiblingElement())
			{
				if (cancelExecution)
					return -1;

				count++;
			}
			continue;
		}

		//считаем статику
		if (path_t.find("/static/") != -1)
		{
			for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
			{
				if (cancelExecution)
					return -1;
				count++;
			}
		}
	}
	return count;
}

int CountParticleEffect()
{
	//LOG_IN_FILE("Counting ParticleEffect");

	fs::path p_type;
	std::string exist_texture;
	int count = 0;
	//собираем эффекты из кластеров
	for (auto& cluster_path : cluster_folders)
	{
		if (cancelExecution)
			return -1;
		fs::recursive_directory_iterator itr(cluster_path), itr_end;

		while (itr != itr_end)
		{
			if (cancelExecution)
				return -1;
			if (fs::is_regular_file(*itr) && itr->path().extension().string() == ".xml")
			{

				tinyxml2::XMLDocument EF_doc;
				EF_doc.LoadFile(itr->path().string().c_str());

				std::string error = EF_doc.ErrorStr();

				if (EF_doc.Error() != 0)
				{
					LOG_IN_FILE("ERROR XML STRUCT:: " <<'\t'<< itr->path().string() << '\t' << error);
					assert(EF_doc.Error() == 0 && "struct error of effect.xml, check LOGFILE");
				}


				tinyxml2::XMLElement* Effect = EF_doc.FirstChildElement();
				tinyxml2::XMLElement* ParticleSystem = Effect->FirstChildElement();

				//std::string node_name = to_string(ParticleSystem->Name());
				if (ParticleSystem != NULL && to_string(ParticleSystem->Name()) == "ParticleSystem")
				{
					count++;
				}

			}

			itr++;
		}

	}

	//собираем эффекты из base_mm\effects
	fs::path ef_path = path_base_mm;
	ef_path /= "effects";
	fs::recursive_directory_iterator itr(ef_path), itr_end;
	while (itr != itr_end)
	{
		if (cancelExecution)
			return -1;
		if (fs::is_regular_file(*itr) && itr->path().extension().string() == ".xml")
		{

			tinyxml2::XMLDocument EF_doc;
			EF_doc.LoadFile(itr->path().string().c_str());

			std::string error = EF_doc.ErrorStr();

			if (EF_doc.Error() != 0)
			{
				LOG_IN_FILE("ERROR XML STRUCT:: " << '\t' << itr->path().string() << '\t' << error);
				assert(EF_doc.Error() == 0 && "struct error of effect.xml, check LOGFILE");
			}

			tinyxml2::XMLElement* Effect = EF_doc.FirstChildElement();
			tinyxml2::XMLElement* ParticleSystem = Effect->FirstChildElement();

			//std::string node_name = to_string(ParticleSystem->Name());
			if (ParticleSystem != NULL && to_string(ParticleSystem->Name()) == "ParticleSystem")
			{

				count++;

			}

		}
		itr++;
	}

	return count;
}

int CountObjectLibrary()
{	

	int count = 0;
	for (auto& obj_file : ObjLib_files)
	{
		//LOG_IN_FILE("Counting resources in: " << obj_file.string());

		tinyxml2::XMLDocument ObjectLibrary_doc;
		ObjectLibrary_doc.LoadFile(obj_file.string().c_str());

		std::string error = ObjectLibrary_doc.ErrorStr();

		if (ObjectLibrary_doc.Error() != 0)
		{
			LOG_IN_FILE("ERROR XML STRUCT:: " << '\t' << obj_file.string() << '\t' << error);
			assert(ObjectLibrary_doc.Error() == 0 && " struct error of ObjectLibrary.xml, check LOGFILE");
		}
		//LOG_IN_FILE("OK");


		tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibrary_doc.FirstChildElement();

		for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
		{	
			if (cancelExecution)
				return -1;
			for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
			{
				if (cancelExecution)
					return -1;
				count++;
			}
		}
	}
	return count;
}

int CountChapterData()
{	
	tinyxml2::XMLDocument CH_doc;

	int count = 0;
	for (auto& ch_file : CH_files)
	{	

		//LOG_IN_FILE("Counting resources in: " << ch_file);

		if (cancelExecution)
			return -1;
		CH_doc.LoadFile(ch_file.c_str());
		
		std::string error = CH_doc.ErrorStr();

		if (CH_doc.Error() != 0)
		{
			LOG_IN_FILE("ERROR XML STRUCT:: " << '\t' << ch_file << '\t' << error);
			assert(CH_doc.Error() == 0 && "struct error of chapter.xml structure check LOGFILE");
		}
		//LOG_IN_FILE("OK");


		tinyxml2::XMLElement* group = CH_doc.FirstChildElement();
		
		for (tinyxml2::XMLElement* repair_extension = group->FirstChildElement(); repair_extension != NULL; repair_extension = repair_extension->NextSiblingElement())
		{

			if (to_string(repair_extension->Name()) != "repair") continue;
			for (tinyxml2::XMLElement* steps = repair_extension->FirstChildElement(); steps != NULL; steps = steps->NextSiblingElement())
			{
				if (cancelExecution)
					return -1;
				if (to_string(steps->Name()) != "steps") continue;//могут быть effects
				for (tinyxml2::XMLElement* step = steps->FirstChildElement(); step != NULL; step = step->NextSiblingElement())
				{
					if (cancelExecution)
						return -1;
					if (to_string(step->Name()) != "step") continue;
					for (tinyxml2::XMLElement* object = step->FirstChildElement(); object != NULL; object = object->NextSiblingElement())
					{	
						if (cancelExecution)
							return -1;
						if (to_string(object->Name()) == "object")
						{
							count++;
						}
					}
				}
			}
		}
	}

	return count;
}


#pragma endregion

#pragma region сбор_ресурсов

//получить все текстуры в объекты TextureData, наполнить ими std::set<TextureData>textures;
void GetTextureFiles()
{	
	res_count = 0;
	int local_count = 0;
	//из папки
	fs::path path = path_game_folder;
	path /= "/base_mm/textures/Gamefield/static";

	//собираем статические текстуры
	fs::recursive_directory_iterator itr(path), end_itr;

	while (itr != end_itr)
	{
		if (cancelExecution)
			break;
		if (fs::is_regular_file(*itr) && itr->path().extension().string() == ".png")
		{	
			local_count++;
			res_count++;
			TextureData* texture = new TextureData(itr->path(), TextureType::STATIC);
			static_textures.emplace(texture);
			MyTool::MyForm3::UpdateProgress(res_count, "Collecting static TextureFiles : ", itr->path().string());
		}
		itr++;
	}

	//собираем ауры
	path = path_game_folder;
	path /= "/base_mm/textures/Gamefield/Night";
	
	fs::recursive_directory_iterator itr2(path), end_itr2;
	while (itr2 != end_itr2)
	{	
		if (cancelExecution)
			break;
		if (fs::is_regular_file(*itr2) && itr2->path().extension().string() == ".png")
		{	
			local_count++;
			res_count++;
			TextureData* texture = new TextureData(itr2->path(), TextureType::AURA);
			aura_textures.emplace(texture);
			MyTool::MyForm3::UpdateProgress(res_count, "Collecting aura TextureFiles : ", itr2->path().string());
		}
		itr2++;
	}
	//LOG_IN_FILE("textures local " << local_count);

}

//получить из Gamefield_Resources.xml объекты GameFieldRes (только текстуры из static папки . пример пути: - "basePath="textures/Gamefield/static/FirstGarden/Tutorial">"), наполнить multiset<GameFieldRes>GameField_objects;
void GetGameFieldResData()
{	
	int local_count = 0;
	
	std::string static_text = "/static/";

	tinyxml2::XMLDocument Gamefield_Resources_doc;
	Gamefield_Resources_doc.LoadFile(path_gamefield_resources.c_str());
	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();
	fs::path root_path;


	for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
	{	
		if (cancelExecution)
			return;


		if (Textures_group->Attribute("basePath") == nullptr)
			continue;

		std::string path_t = Textures_group->Attribute("basePath");

		//собираем ауры 
		if (path_t == "textures/Gamefield/Night/")
		{
			for (tinyxml2::XMLElement* id_node = Textures_group->FirstChildElement(); id_node != NULL; id_node = id_node->NextSiblingElement())
			{
				if (cancelExecution)
					return;

				root_path = path_base_mm;
				root_path /= path_t;
				root_path /= id_node->Attribute("path");
				root_path.replace_extension(".png");

				std::string temp_path = root_path.string();
				GameFieldRes* gr = new GameFieldRes(std::move(temp_path), Textures_group, id_node, TextureType::AURA);

				GameField_aura_textures.emplace(gr);

				res_count++;
				MyTool::MyForm3::UpdateProgress(res_count, "Collect from GameFieldResources : ", root_path.string());
			}
			continue;
		}

		//собираем статику
		if (path_t.find("/static/") != -1)
		{
			for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
			{		
				if (cancelExecution)
					return;

				root_path = path_base_mm;
				root_path /= path_t;
				root_path /= sprite->Attribute("path");
				root_path.replace_extension(".png");
				
				std::string temp_path = root_path.string();
				GameFieldRes* gr = new GameFieldRes(std::move(temp_path), Textures_group, sprite, TextureType::STATIC);
				
				GameField_static_textures.emplace(gr);

				local_count++;
				res_count++;
				MyTool::MyForm3::UpdateProgress(res_count, "Collecting data from GameFieldResources : ", root_path.string());
			}
		}
	}
	//LOG_IN_FILE("gamefieldres local " << local_count);
}

std::string GetParentFolderName(const std::string& path)
{
	int length = path.length();
	std::string parent_path;
	while (path[length] != '\\')
	{
		parent_path.insert(0, &path[length], 1);
		length--;
	}
	return parent_path;
}


std::wstring s2ws(const std::string& str)
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}

//получить все particle effects
void GetParticleEffectData()
{	
	int local_count = 0;
	setlocale(LC_ALL, "rus");

	if (cancelExecution)
		return;
	//int count=0;
	fs::path path;
	std::string exist_texture;

	//собираем эффекты из кластеров
	for (auto& cluster_path : cluster_folders)
	{
		if (cancelExecution)
			return;
		fs::recursive_directory_iterator itr(cluster_path), itr_end;

		while (itr != itr_end)
		{
			if (cancelExecution)
				return;

			if (fs::is_regular_file(*itr) && itr->path().extension().string() == ".xml")
			{
				tinyxml2::XMLDocument EF_doc;
				EF_doc.LoadFile(itr->path().string().c_str());
				tinyxml2::XMLElement* Effect = EF_doc.FirstChildElement();
				tinyxml2::XMLElement* ParticleSystem = Effect->FirstChildElement();

				if (ParticleSystem != NULL && to_string(ParticleSystem->Name()) == "ParticleSystem")
				{
					
					std::string file_path = itr->path().string();
					std::string file_name = itr->path().filename().stem().string();

					ParticleEffect* part_eff = new ParticleEffect(std::move(file_path), std::move(file_name));

					for (; ParticleSystem != NULL; ParticleSystem = ParticleSystem->NextSiblingElement()) //определяем лееры эффекта
					{
						if (cancelExecution)
							return;

						path = path_base_mm;

						if (ParticleSystem->Attribute("texture") != NULL)
						{	
							std::string text_path = ParticleSystem->Attribute("texture");
							if (text_path.empty())
								continue;
							std::wstring ss = s2ws(text_path); //если русский путь - перевод в wstring
							path /= ss;  //полный путь к текстуре из леера партиклэффекта
							path.replace_extension(".png"); //+расширение
							text_path = path.string();

							ParticleEffectLayer* part_eff_layer = new ParticleEffectLayer(std::move(text_path), part_eff);

							part_eff->partEff_ParticleEffectLayers.push_back(part_eff_layer);
							particle_effect_layers.emplace(part_eff_layer);
						}
					}

					if (cancelExecution)
						return;

					local_count++;
					res_count++;
					MyTool::MyForm3::UpdateProgress(res_count, "Collecting ParticleEffects from cluster folders: ", part_eff->partEff_name);

					particle_effects_XML.emplace(part_eff);

					itr++;
					continue;
				}
			}
			itr++;
		}

	}
	if (cancelExecution)
		return;

	//собираем эффекты из base_mm\effects
	fs::path ef_path = path_base_mm;
	ef_path /= "effects";
	fs::recursive_directory_iterator itr(ef_path), itr_end;
	while (itr != itr_end)
	{
		if (cancelExecution)
			return;
		if (fs::is_regular_file(*itr) && itr->path().extension().string() == ".xml")
		{

			tinyxml2::XMLDocument EF_doc;
			EF_doc.LoadFile(itr->path().string().c_str());
			tinyxml2::XMLElement* Effect = EF_doc.FirstChildElement();
			tinyxml2::XMLElement* ParticleSystem = Effect->FirstChildElement();

			if (ParticleSystem != NULL && to_string(ParticleSystem->Name()) == "ParticleSystem")
			{
				if (cancelExecution)
					return;

				std::string file_path = itr->path().string();
				std::string file_name = itr->path().filename().stem().string();

				ParticleEffect* part_eff = new ParticleEffect(std::move(file_name),std::move(file_path));

				for (; ParticleSystem != NULL; ParticleSystem = ParticleSystem->NextSiblingElement()) //определяем лееры эффекта
				{
					if (cancelExecution)
						return;

					path = path_base_mm;

					if (ParticleSystem->Attribute("texture") != NULL)
					{	
						std::string text_path = ParticleSystem->Attribute("texture");
						if (text_path.empty())
							continue;
						std::wstring ss = s2ws(text_path); //если русский путь - перевод в wstring
						path /= ss;  //полный путь к текстуре из леера партиклэффекта
						path.replace_extension(".png"); //+расширение
						text_path = path.string();

						ParticleEffectLayer* part_eff_layer = new ParticleEffectLayer(std::move(text_path), part_eff);
						part_eff->partEff_ParticleEffectLayers.push_back(part_eff_layer);
						particle_effect_layers.emplace(part_eff_layer);
					}
				}

				if (cancelExecution)
					return;

				local_count++;
				res_count++;
				MyTool::MyForm3::UpdateProgress(res_count, "Collecting ParticleEffects from base_mm/effects: ", part_eff->partEff_name);

				particle_effects_XML.emplace(part_eff);
				itr++;
				continue;
			}
		}
		itr++;
	}
	//LOG_IN_FILE("effects local " << local_count);
}

//получить из ObjectLibrary.xml
void GetObjectLibraryData()
{	
	int local_count = 0;
	if (cancelExecution)
		return;

	for (auto& obj_file : ObjLib_files) 
	{
		if (cancelExecution)
			return;

		tinyxml2::XMLDocument ObjectLibrary_doc;
		ObjectLibrary_doc.LoadFile(obj_file.string().c_str());
		tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibrary_doc.FirstChildElement();

		for (tinyxml2::XMLElement* objects_node = ObjectLibrarySchemeElement->FirstChildElement(); objects_node != NULL; objects_node = objects_node->NextSiblingElement())
		{	
			if (cancelExecution)
				return;

			for (tinyxml2::XMLElement* item_node = objects_node->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
			{	
				if (cancelExecution)
					return;

				ObjLibItem* obj_item = new ObjLibItem(obj_file, item_node, objects_node);

				for (tinyxml2::XMLElement* layer_node = item_node->FirstChildElement(); layer_node != NULL; layer_node = layer_node->NextSiblingElement())
				{	
					if (cancelExecution)
						return;

					if (to_string(layer_node->Name()) == "layer")
					{
						ObjLibLayer* obj_layer = new ObjLibLayer(obj_item, layer_node);

						switch (obj_layer->objLayer_type)
						{
						case LayerType::TEXTURE:
							ObjLib_layer_textures.emplace(obj_layer);
							break;
						case LayerType::EFFECT_XML:
							ObjLib_layer_xml_effects.emplace(obj_layer);
							break;
						case LayerType::EFFECT_SWL_OR_SPINE:
							ObjLib_layer_swl_effects.emplace(obj_layer);
							break;
						case LayerType::LIGHT_WITH_EFFECT:
							ObjLib_layer_light_effects.emplace(obj_layer);
							break;
						case LayerType::LIGHT_WITH_AURA:
							ObjLib_layer_light_aura.emplace(obj_layer);
							break;
						case LayerType::LIGHT:
							ObjLib_layer_lights.emplace(obj_layer);
							break;
						default:
							break;
						}

						
					}
				}
				local_count++;
				res_count++;
				if (cancelExecution)
					return;
				MyTool::MyForm3::UpdateProgress(res_count, "Collecting items from ObjectLibrary : ", obj_item->objItem_item_id);
				ObjLib_items.emplace(obj_item);
			}
		}

	}
	//LOG_IN_FILE("objectItem local " << local_count);
}

//получить все объекты в файлах Ch
void GetChapterData()
{	
	int local_count = 0;
	if (cancelExecution)
		return;

	tinyxml2::XMLDocument CH_doc;

	for (auto& ch_file : CH_files)
	{
		if (cancelExecution)
			return;
		CH_doc.LoadFile(ch_file.c_str());
		tinyxml2::XMLElement* group = CH_doc.FirstChildElement();


		for (tinyxml2::XMLElement* repair_extension_node = group->FirstChildElement(); repair_extension_node != NULL; repair_extension_node = repair_extension_node->NextSiblingElement())
		{	
			if (cancelExecution)
				return;

			if (to_string(repair_extension_node->Name()) != "repair") continue;

			for (tinyxml2::XMLElement* steps_node = repair_extension_node->FirstChildElement(); steps_node != NULL; steps_node = steps_node->NextSiblingElement())
			{	
				if (cancelExecution)
					return;

				if (to_string(steps_node->Name()) != "steps") continue;//могут быть effects

				for (tinyxml2::XMLElement* step_node = steps_node->FirstChildElement(); step_node != NULL; step_node = step_node->NextSiblingElement())
				{	
					if (cancelExecution)
						return;

					if (to_string(step_node->Name()) != "step") continue;

					for (tinyxml2::XMLElement* object_node = step_node->FirstChildElement(); object_node != NULL; object_node = object_node->NextSiblingElement())
					{	
						if (cancelExecution)
							return;

						if (to_string(object_node->Name()) == "object")
						{	
							fs::path ch_path = ch_file;
							ChapterData* ch_data = new ChapterData(ch_path, object_node->Attribute("id"), object_node->GetText(), repair_extension_node->Attribute("id"), repair_extension_node->Attribute("id"), step_node->Attribute("id"));
							
							res_count++;
							local_count++;
							if (cancelExecution)
								return;
							MyTool::MyForm3::UpdateProgress(res_count, "Collecting object from Chapter files : ", ch_data->chData_storyInfo_chapter_id + " - " + ch_data->chData_storyInfo_repair + " - " + ch_data->chData_storyInfo_step + " - " + ch_data->chData_dataid);
							CH_objects.emplace(ch_data);
						}
					}
				}
			}
		}
	}

	//LOG_IN_FILE("chapterObjects local " << local_count);
}

std::string& GetLayerNameBeforePoint(std::string& fullname)
{	
	std::string name_before_point;
	int i = 0;
	while (fullname[i] != '.')
	{
		name_before_point += fullname[i];
		i++;
	}

	return name_before_point;
}

void DeleteOrNot()
{
	if (cancelExecution)
		return;

	for (auto& texture : static_textures)
	{

		if (!texture->TD_exist_on_meta) //есть в GR
		{	
			if (!texture->TD_exist_in_EF)
				texture->TD_to_delete = true;
			else
				texture->TD_to_delete = false;
		}
	}

	for (auto& texture : aura_textures)
	{

		if (!texture->TD_exist_on_meta) //есть в GR
		{
			if (!texture->TD_exist_in_EF)
				texture->TD_to_delete = true;
			else
				texture->TD_to_delete = false;
		}
	}
}

//атрибуты для ChapterIds
void GetAttributes(ChapterData& ch)
{
	std::string text = ch.chData_text_node;

	std::string dataid_marker = "\"dataId\"";
	int start_dataid = text.find(dataid_marker);
	std::string starting_with_dataid(text, start_dataid, text.length()); //стринг начиная с dataId

	ch.chData_dataid = GetAttr_CH(starting_with_dataid, "\"dataId\":");
	ch.chData_text_m = GetAttr_CH(starting_with_dataid, "\"m\":");
	ch.chData_text_rand = GetAttr_CH(starting_with_dataid, "\"rand\":");
	ch.chData_text_x = GetAttr_CH(starting_with_dataid, "\"x\":");
	ch.chData_text_y = GetAttr_CH(starting_with_dataid, "\"y\":");
	ch.chData_text_zOrder = GetAttr_CH(starting_with_dataid, "\"zOrder\":");

	std::string iso_offset = "\"IsoOffset\":";

	int first_symb_iso = text.find(iso_offset);


	//если нет исо 
	if (first_symb_iso == -1)
	{
		return;
	}

	//если есть исо
	std::string before_data_id(text, 0, start_dataid - 1);

	ch.chData_text_iso_uL = GetAttr_CH(before_data_id, "\"uL\":");
	ch.chData_text_iso_uR = GetAttr_CH(before_data_id, "\"uR\":");
	ch.chData_text_iso_x = GetAttr_CH(before_data_id, "\"x\":");
	ch.chData_text_iso_y = GetAttr_CH(before_data_id, "\"y\":");
	ch.chData_text_iso_z = GetAttr_CH(before_data_id, "\"z\":");
}

#pragma endregion
/////отметить мертвые эффекты
void Get_dead_effects()
{
	int i = 0;
	int size;
	for (auto& eff : particle_effects_XML)
	{
		size = eff->partEff_ParticleEffectLayers.size();
		i = 0;
		for (auto& eff_layer : eff->partEff_ParticleEffectLayers)
		{
			if (!eff_layer->effectLayer_file_exist)
			{
				i++;
			}
		}

		if (i == size && (eff->partEff_name.find("Match3") != -1 || eff->partEff_name.find("Match3") != -1))
		{
			eff->partEff_dead = "Match3 DEAD";
			continue;
		}

		if (i == size)
		{
			eff->partEff_dead = "fully DEAD";
			eff->partEff_to_delete = true;
			continue;
		}

		if (i > 0 && i < size && (eff->partEff_name.find("Match3") != -1 || eff->partEff_name.find("Match3") != -1))
		{
			eff->partEff_dead = "Match3 partially dead";
			continue;
		}

		if (i > 0 && i < size)
		{
			eff->partEff_dead = "partially dead";
			continue;
		}

		if (i == 0 && (eff->partEff_name.find("Match3") != -1 || eff->partEff_name.find("Match3") != -1))
		{
			eff->partEff_dead = "Match3 alive";
			continue;
		}

		if (i == 0)
		{
			eff->partEff_dead = "alive";
			continue;
		}
	}
}

//найти TextureData в контейнере
TextureData* FindTexture(const fs::path& texture_path, std::set<TextureData*>& container)
{
	auto& it_texture = std::find_if(container.begin(), container.end(),
		[&](const TextureData* td)
	{
		return fs::equivalent(texture_path, td->TD_path);
	});

	if (it_texture == container.end())
		return nullptr;
	else
	{	
		TextureData* texture = const_cast<TextureData*>(*it_texture);

		return texture;
	}
		
}

//найти GameFieldRes по Id
GameFieldRes* FindGameFieldResById(std::string id, std::multiset<GameFieldRes*>& container)
{
	auto& it_gr = std::find_if(container.begin(), container.end(),
		[&](const GameFieldRes* gr)
	{
		return  id == gr->gameFieldRes_id;
	});

	if (it_gr == container.end())
		return nullptr;
	else
	{
		GameFieldRes* gr_ = const_cast<GameFieldRes*>(*it_gr);
		return gr_;
	}
}

ParticleEffect* FindParticleEffectByName(std::string& name, std::multiset<ParticleEffect*>& container)
{
	auto it = std::find_if(container.begin(), container.end(),
		[&](const ParticleEffect* ef)
	{	
		return name == ef->partEff_name;
	});
	if (it == container.end())
		return nullptr;
	else
	{
		ParticleEffect* eff = const_cast<ParticleEffect*>(*it);
		return eff;
	}

}

//найти ParticleEffect в контейнере
ParticleEffect* FindEffectByPath(fs::path effect_path, std::multiset<ParticleEffect*>& container)
{
	auto it_p_eff = std::find_if(container.begin(), container.end(),
		[&](const ParticleEffect* ef)
	{	
		fs::path path = ef->partEff_string_path;
		return fs::equivalent(effect_path, path);
	});

	if (it_p_eff == container.end())
		return nullptr;
	else
	{	
		ParticleEffect* eff = const_cast<ParticleEffect*>(*it_p_eff);
		return eff;
	}

}

ObjLibItem* FindObjLibItemById(std::string id)
{
	//по датаайди находим айтем
	auto& it = std::find_if(ObjLib_items.begin(), ObjLib_items.end(),
		[&](const ObjLibItem* obj)
	{
		return id == obj->objItem_item_id;
	});

	if (it == ObjLib_items.end())
	{
		return nullptr;
	}
	else
	{	
		ObjLibItem* ob = const_cast<ObjLibItem*>(*it);
		return ob;
	}
}

ObjLibLayer* FindObjLibLayerByTextureAttr(std::string attribute, std::multiset<ObjLibLayer*>& container)
{
	//по датаайди находим айтем
	auto& it = std::find_if(container.begin(), container.end(),
		[&](const ObjLibLayer* layer)
	{
		return attribute == layer->objLayer_texture_attr;
	});

	if (it == container.end())
	{
		return nullptr;
	}
	else
	{
		ObjLibLayer* layer_ = const_cast<ObjLibLayer*>(*it);
		return layer_;
	}
}

void RemoveProblems()
{
	//for (auto& it_td = textures.begin(); it_td != textures.end(); it_td++)
	//{
	//	it_td->TD_problem = false;
	//}
}


//парсинг  в файле чаптера. Пример: выявление степа var_1 из "var_1:ParticleEffect"
std::string GetParticleEffectStep(std::string s)
{
	std::string step;
	int i = 0;
	while (s[i] != ':' && i < s.length())
	{
		step += s[i];
		i++;
	}
	return step;
}

//парсинг в файле чаптера. Пример:выявление имени эффекта curbstones из "value="curbstones.curbstones""
std::string GetParticleName(std::string s)
{
	std::string name;
	int i = 0;
	while (s[i] != '.' && i<s.length())
	{
		name += s[i];
		i++;
	}
	return name;
}

//получить значение заданного аттрибута из текста объекта в CH_FirstGarden.xml (для работы, Get_CH_Info())
std::string GetAttr_CH(std::string text_to_parsing, std::string attribute)
{
	//std::string attr = '"' + attribute + '"' + ':';
	std::string result;
	int attr_length = attribute.length();
	int first = text_to_parsing.find(attribute);

	if (first == -1)
	{
		//assert("no such attribute");
		//exit(1);
		return "-";
	}

	int j = first + attr_length;

	while (text_to_parsing[j] != '}'&&text_to_parsing[j] != ',')
	{
		result += text_to_parsing[j];
		j++;
	}

	j = 0;

	//убрать кавычки
	std::string result2;

	while (result[j])
	{
		if (result[j] != '"') result2 += result[j];

		j++;
	}
	return result2;
}

//проверка уже не нужна, проверяется в момент Get_GameFieldRes_Info
//bool Check_GR(TextureData& td)
//{
//	std::set<GameFieldRes>::iterator it_GR = std::find_if(GameField_objects.begin(), GameField_objects.end(), [&](const GameFieldRes& gr)
//	{
//		return fs::equivalent(td.TD_texture_name, gr.gameFieldRes_full_path);
//	});
//
//	if (it_GR == GameField_objects.end())
//	{	
//		td.TD_GR = NULL;
//		//LOG_IN_FILE(process_count << '\t' << td.TD_texture_name.stem() << '\t' << td.TD_texture_path << '\t' << td.TD_exist_in_GR << '\t' << td.TD_exist_in_OL << '\t' << td.TD_exist_in_CH << '\t' << td.TD_size);
//		return false;
//	}
//
//	td.TD_exist_in_GR = "+";
//
//	const GameFieldRes *it2 = &(*it_GR);
//	GameFieldRes& it3 = const_cast<GameFieldRes&>(*it2);
//	GameFieldRes* p = &it3;
//	td.TD_GR = p;
//	return true;
//}

void OL_Clusters_in_one_string(std::set<TextureData*>&container)
{	
	std::set<std::string>clusters;

	for (auto& texture : container)
	{
		if (!texture->TD_GRs.empty())
		{	
			for (auto& gr : texture->TD_GRs)
			{
				if (!gr->gameFieldRes_ObjLibLayers.empty())
				{
					for (auto& layer : gr->gameFieldRes_ObjLibLayers)
					{
						clusters.insert(layer->objLayer_item->objItem_cluster);
					}
					for (auto& obj : clusters)
					{
						texture->TD_clusters_OL += obj;
						texture->TD_clusters_OL += " ";
					}
				}
			}
		}
	}
}
/////////////сравнить 2 папки, вернуть файлы(пути) 2 папки, которых нет в первой
std::set<std::string> Compare2Folder(const std::string path1, const std::string path2)
{	
	int path1_length = path1.length();
	int path2_length = path2.length();
	fs::path p_1 = path1;
	fs::path p_2 = path2;

	std::set<std::string> differ_files;
	//сверка файлов второй папки с существованием в первой
	fs::recursive_directory_iterator itr(p_2), end_itr;
	for (;itr != end_itr; itr++)
	{
		if (fs::is_regular_file(*itr))
		{
			std::string pa = itr->path().string();
			pa.erase(0, path2_length);
			fs::path check = path1;
			check /= pa;

			if (fs::exists(check))
				continue;
			differ_files.emplace(itr->path().string());
		}
	}
	return differ_files;
}

//проставить noRedesignDeformation="true" (любой аттрибут в значение)
bool NoBounce(std::string id, std::string attr, std::string attr_value)
{	
	for (auto& obj_file_it : ObjLib_files)
	{

		tinyxml2::XMLDocument ObjectLibrary_doc;
		ObjectLibrary_doc.LoadFile(obj_file_it.string().c_str());
		tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibrary_doc.FirstChildElement();

		std::string item_id;
		std::string texture;

		int count_layers = 0;
		int count = 0;

		for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
		{
			for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
			{
				if (item->Attribute("id") == id)
				{
					item->SetAttribute(attr.c_str(), attr_value.c_str());
					ObjectLibrary_doc.SaveFile(obj_file_it.string().c_str());
					return true;
				}
			}
		}

		return false;
	}
}

bool ExistFile(std::string filePath)
{
	
	fs::path p = filePath;
	

	if (fs::is_regular_file(p)&&fs::exists(p))
	{
		return true;
	}
	return false;
}

bool ExistDirectory(std::string directoryPath)
{
	fs::path p = directoryPath;

	if (fs::is_directory(p) && fs::exists(p))
	{
		return true;
	}
	return false;
}

void GetChapterFiles()
{	
	if (!CH_files.empty()) CH_files.clear();

	fs::path p = path_repair_path;
	fs::directory_iterator itr(p), itr_end;

	for (; itr != itr_end; itr++)
	{
		if (itr->path().string().find("CH_") != -1 && itr->path().extension() == ".xml")
		{
			CH_files.push_back(itr->path().string());
			continue;
		}
	}

}

void GetObjectLibraryFiles()
{
	for (auto& it = cluster_folders.begin(); it != cluster_folders.end(); it++)
	{
		fs::directory_iterator dir_it(*it), dir_it_end;

		while (dir_it != dir_it_end)
		{
			if (fs::is_regular_file(*dir_it) && dir_it->path().filename().string() == "ObjectLibrary.xml")
				ObjLib_files.push_back(*dir_it);

			dir_it++;
		}

	}
}

void DeleteEffectFromCommonFile(fs::path path) //удалить запись об эффекте из common эфекта - передается эффект.xml
{	
	std::string common_effect_name = path.parent_path().stem().string(); //папка удаляемого эффекта = название common эффекта
	common_effect_name += ".xml";
	fs::path common_effect = path.parent_path().parent_path();
	common_effect /= common_effect_name;

	if (fs::exists(common_effect))
	{
		tinyxml2::XMLDocument common_effect_doc;
		common_effect_doc.LoadFile(common_effect.string().c_str());
		tinyxml2::XMLElement* EffectSolution = common_effect_doc.FirstChildElement();

		if (to_string(EffectSolution->Name()) == "EffectSolution")
		{
			tinyxml2::XMLElement* Effect = EffectSolution->FirstChildElement();
			if (Effect != NULL && to_string(Effect->Name()) == "Effect")
				for (; Effect != NULL; Effect = Effect->NextSiblingElement())
				{
					if (Effect->Attribute("path") == path.filename().string())
					{
						EffectSolution->DeleteChild(Effect);
						//LOG_IN_FILE(deleting_count << '\t' << "COMMON_Effect - "<<common_effect.string() << '\t' << "deleted" << '\t' << path.filename().string() << '\t' << path.parent_path().string());
						LOG_IN_FILE(deleting_count << '\t' << "deleted" << '\t' << common_effect.string() << '\t' << "common_effect_line" << '\t' << path.filename().string());
						common_effect_doc.SaveFile(common_effect.string().c_str());
						break;
					}
				}
		}

	}
	




}

void RemoveEmptyEffectFolder()
{	
	std::string common_effect_name;
	fs::path common_effect;
	boost::system::error_code ec;
	fs::path p;

	for (auto cluster_path_it = cluster_folders.begin(); cluster_path_it != cluster_folders.end(); cluster_path_it++)
	{
		//fs::path ef_path = *cluster_path_it;
		fs::recursive_directory_iterator itr(*cluster_path_it), itr_end;
		while (itr != itr_end)
		{	
			//std::string s = itr->path().string();
			//bool a = fs::is_empty(*itr);
			if (fs::is_directory(*itr) && fs::is_empty(*itr))
			{
				common_effect_name = itr->path().stem().string(); //папка удаляемого эффекта = название common эффекта
				common_effect_name += ".xml";
				common_effect = itr->path().parent_path();
				common_effect /= common_effect_name;

				if (fs::exists(common_effect))
				{
					p = itr->path();
					itr++;
					fs::remove(p, ec);
					//LOG_IN_FILE("Num" << '\t' << "deleting_RESULT" << '\t' << "deleting_from" << '\t' << "deleting_what" << '\t' << "deleting_what(name)");
					LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' <<"directory"<< '\t' << "empty_folder" << '\t' << p.string());
					fs::remove(common_effect, ec);
					LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' << "directory" << '\t' << "common_effect" << '\t' << common_effect.string());
					continue;
				}
				else
				{
					p = itr->path();
					itr++;
					fs::remove(p, ec);
					//LOG_IN_FILE("Num" << '\t' << "deleting_RESULT" << '\t' << "deleting_from" << '\t' << "deleting_what" << '\t' << "deleting_what(name)");
					LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' << "directory" << '\t' << "empty_folder" << '\t' << p.string());
					continue;
				}

			}

			itr++;
		}
	}


	fs::path ef_path = path_base_mm;
	ef_path /= "effects";
	fs::recursive_directory_iterator itr(ef_path), itr_end;
	while (itr != itr_end)
	{	
		//std::string s = itr->path().string();
		//bool a = fs::is_empty(*itr);
		if (fs::is_directory(*itr) && fs::is_empty(*itr))
		{
			common_effect_name = itr->path().stem().string(); //папка удаляемого эффекта = название common эффекта
			common_effect_name += ".xml";
			common_effect = itr->path().parent_path();
			common_effect /= common_effect_name;

			if (fs::exists(common_effect))
			{
				p = itr->path();
				itr++;
				fs::remove(p, ec); //удаление папки
				//LOG_IN_FILE("Num" << '\t' << "deleting_RESULT" << '\t' << "deleting_from" << '\t' << "deleting_what" << '\t' << "deleting_what(name)");
				LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' << "directory" << '\t' << "empty_folder" << '\t' << p.string());
				fs::remove(common_effect, ec); //удаление файла
				LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' << "directory" << '\t' << "common_effect" << '\t' << common_effect.string());
				continue;
			}
			else
			{
				p = itr->path();
				itr++;
				fs::remove(p, ec); //удаление файла
				//LOG_IN_FILE("Num" << '\t' << "deleting_RESULT" << '\t' << "deleting_from" << '\t' << "deleting_what" << '\t' << "deleting_what(name)");
				LOG_IN_FILE(deleting_count << '\t' << ec.message() << '\t' << "directory" << '\t' << "empty_folder" << '\t' << p.string());
				continue;
			}

		}

		itr++;
	}


}

void RemoveEmptyFolders()
{
	fs::path texture_path = path_texture_folder;
	fs::recursive_directory_iterator itr(texture_path), end_itr;
	boost::system::error_code ec;
	while (itr != end_itr)
	{	
		if (fs::is_directory(*itr) && fs::exists(*itr) && fs::is_empty(*itr))
		{	
			fs::path p = itr->path();
			itr++;
			fs::remove(p, ec);
			LOG_IN_FILE(deleting_count << '\t' << "Deleted Empty FOLDER" << '\t' << ec.message() << '\t' << "no file" << '\t' << p.string() << '\t' << "-" << '\t' << "-" << '\t' << "-");
		}
		else
			itr++;
	}


}

void FillRepairsAndSteps()
{	
	if (!repairs.empty()) 
		repairs.clear();

	if (!steps.empty())
		steps.clear();

	std::string repair;
	fs::path filename;

	repairs.push_back("");
	steps.push_back("");

	tinyxml2::XMLDocument CH_doc;
	for (auto& ch_file : CH_files)
	{
		CH_doc.LoadFile(ch_file.c_str());
		tinyxml2::XMLElement* group = CH_doc.FirstChildElement();

		filename = ch_file;

		for (tinyxml2::XMLElement* repair_extension = group->FirstChildElement(); repair_extension != NULL; repair_extension = repair_extension->NextSiblingElement())
		{
			if (to_string(repair_extension->Name()) != "repair") continue;

			repair = repair_extension->Attribute("id");
			repairs.push_back(filename.filename().stem().string() + " - " + repair);

			for (tinyxml2::XMLElement* steps_node = repair_extension->FirstChildElement(); steps_node != NULL; steps_node = steps_node->NextSiblingElement())
			{
				if (to_string(steps_node->Name()) != "steps") continue;

				for (tinyxml2::XMLElement* step = steps_node->FirstChildElement(); step != NULL; step = step->NextSiblingElement())
				{
					if (to_string(step->Name()) != "step") continue;

					steps.push_back(filename.filename().stem().string() + " - " + repair + " - " + step->Attribute("id"));
				}
			}

		}
	}
}

void DeleteLayer(ObjLibLayer* layer)
{	
	switch (layer->objLayer_type)
	{
	case LayerType::TEXTURE:
		ObjLib_layer_textures.erase(layer);
		break;
	case LayerType::EFFECT_XML:
		ObjLib_layer_xml_effects.erase(layer);
		break;
	case LayerType::EFFECT_SWL_OR_SPINE:

		break;
	case LayerType::LIGHT_WITH_EFFECT:
		ObjLib_layer_light_effects.erase(layer);
		break;
	case LayerType::LIGHT_WITH_AURA:
		ObjLib_layer_light_aura.erase(layer);
		break;
	case LayerType::LIGHT:

		break;
	default:
		assert(false);
		break;
	}
	delete layer;
	layer = nullptr;
}

void DeleteItem(ObjLibItem* item)
{	
	ObjLib_items.erase(item);
	delete item;
	item = nullptr;
}

void DeleteGamefieldRes(GameFieldRes* gr)
{	
	switch (gr->gameFieldRes_type)
	{
	case TextureType::STATIC:
		GameField_static_textures.erase(gr);
		break;
	case TextureType::AURA:
		GameField_aura_textures.erase(gr);
		break;
	default:
		break;
	}

	delete gr;

	//bool a = true;
	//while (a)
	//{
	//	auto& it = std::find(GameField_objects.begin(), GameField_objects.end(), gr);

	//	if (it == GameField_objects.end())
	//		a = false;
	//	else
	//	{
	//		GameField_objects.erase(it);
	//		delete gr;
	//	}
	//}
}

void DeleteTexture(TextureData* td)
{	
	//проверка есть ли на мете, если да, - то в лог и дальше
	int count_chapter_dataid = 0;
	if (td->TD_exist_on_meta)
	{
		std::string data;
		error_counter++;

		for (auto& gr : td->TD_GRs)
		{
			for (auto& layer : gr->gameFieldRes_ObjLibLayers)
			{
				for (auto& chapter_dobject : layer->objLayer_item->objItem_ChapterDatas)
				{
					data = chapter_dobject->chData_storyInfo_chapter_id + " - " + chapter_dobject->chData_storyInfo_repair + " - " + chapter_dobject->chData_storyInfo_step + " - " + chapter_dobject->chData_hashid + " - " + chapter_dobject->chData_dataid;
					LOG_IN_FILE("Warning::" << deleting_count << '\t' << "canceled - exists on meta: " << data << '\t' << "-" << '\t' << "texture and records" << '\t' << td->TD_texture_name);
				}
			}
		}
		return;
	}

	////проверка есть ли в эффектах, если да, - то в лог и дальше
	if (!td->TD_effects.empty())
	{
		std::string data;
		error_counter++;

		for (auto& effect : td->TD_effects)
		{
			LOG_IN_FILE(deleting_count << '\t' << "Warning:: canceled - exists in effect: " << effect->partEff_string_path << '\t' << "-" << '\t' << "texture and records" << '\t' << td->TD_texture_name);
		}
		return;
	}

	////если не удаляется текстура - дальше из контейнера не удаляем
	boost::system::error_code ec;
	fs::remove(td->TD_texture_name, ec); //удалить файл
	LOG_IN_FILE(deleting_count << '\t' << "Warning:: "<< ec.message() << '\t' << "texture_file" << '\t' << td->TD_texture_name);
	if (ec != 0)
	{
		error_counter++;
		td->TD_problem = true;
		problem_textures_path.push_back(td->TD_texture_name); //TODO
		return;
	}

	texture_deleted++;
	texture_deleted_size += td->TD_size;

	//удалить текстуру из контейнера
	switch (td->TD_type)
	{
	case TextureType::STATIC:
		static_textures.erase(td);
		break;
	case TextureType::AURA:
		aura_textures.erase(td);
		break;
	default:
		break;
	}

	//удалить gr из контейнера и xml,  а также сам объект (а также его лееры)
	if (!td->TD_GRs.empty())
	{

		for (auto& gr : td->TD_GRs)
		{	
			switch (gr->gameFieldRes_type)
			{
			case TextureType::STATIC:
				GameField_static_textures.erase(gr);
				break;
			case TextureType::AURA:
				GameField_aura_textures.erase(gr);
				break;
			default:
				break;
			}

			

			//если есть лееры = есть в ObjectLibrary - удаляем лееры из контейнеров, xml и сами объекты
			if (!gr->gameFieldRes_ObjLibLayers.empty())
			{
				for (auto& layer : gr->gameFieldRes_ObjLibLayers)
				{
					
					switch (layer->objLayer_type) //только удаляем из контейнеров,
					{
					case LayerType::TEXTURE:
						ObjLib_layer_textures.erase(layer);
						break;
					case LayerType::LIGHT_WITH_AURA:
						ObjLib_layer_light_aura.erase(layer);
						break;
					case LayerType::EFFECT_XML:
						ObjLib_layer_xml_effects.erase(layer); //хотя если текстура в эффектах - запрещаем удалять
						break;
					case LayerType::LIGHT_WITH_EFFECT:
						ObjLib_layer_light_effects.erase(layer); //хотя если текстура в эффектах - запрещаем удалять
						break;
					case LayerType::LIGHT:
						break;
					case LayerType::EFFECT_SWL_OR_SPINE:
						break;
					default:
						break;
					}

					DeleteLayerFromObjectLibrary(layer);

					delete layer;
				}
			}

			resources_texture_deleted++;
			resources_texture_deleted_size += td->TD_size;
			DeleteFromGamefieldResources(gr);
			delete gr;
		}
	}
	delete td;	
}

//удалить запись из GamefieldResources по имени текстуры
void DeleteFromGamefieldResources(GameFieldRes* gr)
{
	bool brk = false;
	std::string static_text = "/static/";

	tinyxml2::XMLDocument Gamefield_Resources_doc;
	Gamefield_Resources_doc.LoadFile(path_gamefield_resources.c_str());
	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();

	fs::path	GR_root;
	std::string GR_id;

	switch (gr->gameFieldRes_type)
	{
	case TextureType::STATIC:
			brk = false;
			for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
			{
				if (Textures_group->Attribute("basePath") == NULL) continue;

				std::string path_t = Textures_group->Attribute("basePath");

				if (path_t.find(static_text) != -1)
				{
					for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
					{

						if (gr->gameFieldRes_path_attr == sprite->Attribute("path") && gr->gameFieldRes_group_path == path_t)
						{	
							LOG_IN_FILE(deleting_count << '\t' << "Deleted static sprite id from Resources:: " << sprite->Attribute("id") << '\t' << "from line" << '\t' << sprite->GetLineNum());
							Textures_group->DeleteChild(sprite);
							Gamefield_Resources_doc.SaveFile(path_gamefield_resources.c_str());
							brk = true;
							break;
						}
					}

				}
				if (brk)
					break;
			}
		break;
	case TextureType::AURA:
			brk = false;
			for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
			{
				if (Textures_group->Attribute("basePath") == NULL) continue;

				std::string path_t = Textures_group->Attribute("basePath");

				if (path_t == "textures/Gamefield/Night/")
				{
					for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
					{

						if (gr->gameFieldRes_path_attr == sprite->Attribute("path") && gr->gameFieldRes_group_path == path_t)
						{	
							LOG_IN_FILE(deleting_count << '\t' << "Deleted aura sprite id from Resources:: " << sprite->Attribute("id") << '\t' << "from line" << '\t' << sprite->GetLineNum());
							Textures_group->DeleteChild(sprite);
							Gamefield_Resources_doc.SaveFile(path_gamefield_resources.c_str());
							brk = true;
							break;
						}
					}

				}
				if (brk)
					break;
			}
		break;
	default:
		break;
	}
}

//удалить все лееры данной текстуры (в каждом ObjectLibrary)
void DeleteFromObjectLibrary(ObjLibItem* item)
{
	bool brk = false;
	//удаляем айтемы, которыми владеет GR

				for (auto& obj_file : ObjLib_files)
				{
					brk = false;
					tinyxml2::XMLDocument ObjectLibtary_doc;
					ObjectLibtary_doc.LoadFile(obj_file.string().c_str());

					tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();

					for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
					{
						for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
						{
							if (item_node->Attribute("id") == item->objItem_item_id)
							{
								Objects->DeleteChild(item_node);
								ObjectLibtary_doc.SaveFile(obj_file.string().c_str());
								brk = true;
								break;
							}
						}
						if (brk) break;
					}
				}
}

void DeleteLayerFromObjectLibrary(ObjLibLayer* layer)
{
	bool brk = false;
	//удаляем лееры, которыми владеет GR


	switch (layer->objLayer_type)
	{
	case LayerType::TEXTURE:
		for (auto& obj_file : ObjLib_files)
		{
			bool brk = false;
			int count = 0;
			tinyxml2::XMLDocument ObjectLibtary_doc;
			ObjectLibtary_doc.LoadFile(obj_file.string().c_str());

			tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();

			for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
			{
				for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
				{
					for (tinyxml2::XMLElement* layer_node = item_node->FirstChildElement(); layer_node != NULL; layer_node = layer_node->NextSiblingElement())
					{
						if (to_string(layer_node->Name()) != "layer")
							continue;

						if (layer_node->Attribute("texture") == NULL)
							continue;

						if (layer_node->Attribute("texture") == layer->objLayer_texture_attr)
						{
							brk = true;
							LOG_IN_FILE(deleting_count << '\t' << "Deleted layer from ObjectLibrary with texture attribute:: " << layer->objLayer_texture_attr << '\t' << "from line" << '\t' << layer_node->GetLineNum());
							item_node->DeleteChild(layer_node);
							
							ObjectLibtary_doc.SaveFile(obj_file.string().c_str());

							//рекурсия - пока не удалим все слои
							DeleteLayerFromObjectLibrary(layer);

						}
						if (brk) break;
					}
					if (brk) break;
				}
				if (brk) break;
			}
		}

		break;
	case LayerType::EFFECT_XML: //не удаляем тектуру, если она в эффектах		
		break;
	case LayerType::EFFECT_SWL_OR_SPINE: //не удаляем тектуру, если она в эффектах
		break;
	case LayerType::LIGHT: 
		break;
	case LayerType::LIGHT_WITH_AURA: //можем удалить
		for (auto& obj_file : ObjLib_files)
		{
			bool brk = false;
			int count = 0;
			tinyxml2::XMLDocument ObjectLibtary_doc;
			ObjectLibtary_doc.LoadFile(obj_file.string().c_str());

			tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();

			for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
			{
				for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
				{
					for (tinyxml2::XMLElement* layer_node = item_node->FirstChildElement(); layer_node != NULL; layer_node = layer_node->NextSiblingElement())
					{
						if (to_string(layer_node->Name()) != "layer")
							continue;

						if (layer_node->Attribute("aura") == NULL)
							continue;
						if (layer_node->Attribute("aura") == layer->objLayer_aura)
						{	
							brk = true;
							LOG_IN_FILE(deleting_count << '\t' << "Deleted layer from ObjectLibrary with aura attribute:: " << layer->objLayer_aura << '\t' << "from line" << '\t' << layer_node->GetLineNum());
							item_node->DeleteChild(layer_node);
							ObjectLibtary_doc.SaveFile(obj_file.string().c_str());

							//рекурсия - пока не удалим все слои
							DeleteLayerFromObjectLibrary(layer);

						}
						if (brk) break;
					}
					if (brk) break;
				}
				if (brk) break;
			}
		}

		break;
	case LayerType::LIGHT_WITH_EFFECT:
		break;
	default:
		break;
	}


	
}

//удалить item без лееров (в каждом ObjectLibrary)
void DeleteNoLayersItem()
{
	std::vector<ObjLibItem*> for_deleting;
	for (auto& obj_file : ObjLib_files)
	{	
		bool brk = false;
		tinyxml2::XMLDocument ObjectLibtary_doc;
		ObjectLibtary_doc.LoadFile(obj_file.string().c_str());

		tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();

		for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
		{
			for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
			{
				if (item_node->NoChildren())
				{	
					auto& it_item = std::find_if(ObjLib_items.begin(), ObjLib_items.end(), 
						[&](const ObjLibItem* item)
					{
						if (item->objItem_item_id == item_node->Attribute("id"))
						{	
							ObjLibItem* _item = const_cast<ObjLibItem*>(item);
							for_deleting.push_back(_item);
							return item->objItem_item_id == item_node->Attribute("id");
						}

					});
					
					if (it_item == ObjLib_items.end()) //нет такого айтема?? не может быть
						assert(false && "no such item");
					else
					{
						brk = true;
						ObjLib_items.erase(it_item);

						LOG_IN_FILE(deleting_count << '\t' << "Deleted item from ObjectLibrary :: " << item_node->Attribute("id") << '\t' << "from line" << '\t' << item_node->GetLineNum());
						Objects->DeleteChild(item_node);
						OL_items_deleted++;
						ObjectLibtary_doc.SaveFile(obj_file.string().c_str());

						//рекурсия, пока не удалим все
						DeleteNoLayersItem();
					}
					
				}
				if (brk) break;
			}
			if (brk) break;
		}
		//ObjectLibtary_doc.SaveFile(obj_file.string().c_str());
	}	
	OL_items_deleted = 0;
	for (auto& item : for_deleting)
	{
		delete item;
		OL_items_deleted++;
	}
}
}

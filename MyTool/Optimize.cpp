
#include "Optimize.h"
#include "Macro.h"
#include "MyForm3.h"

std::set<TextureData>		textures;

std::multiset<GameFieldRes*>	GameField_objects;
std::multiset<ObjLibLayer*>		ObjLib_layers;
std::multiset<ObjLibItem*>		ObjLib_items;
std::multiset<ChapterData*>		CH_objects;
std::set<ParticleEffect*>		particle_effects;

std::list<std::string>			CH_files;
std::list<fs::path>				cluster_folders;
std::vector<fs::path>			ObjLib_files;

std::vector<fs::path>			problem_textures_path;

std::vector<std::string>		repairs;
std::vector<std::string>		steps;

std::string chosen_repair = "not chosen";
std::string chosen_step = "not chosen";

std::multiset<CH_ParticleEffect>meta_particle_repair_effects;

std::multimap<fs::path, fs::path> texture_particle_effect; //текстура, эффект

bool cancelExecution = false;
static int count = 0;

template<class T>
void PrintToLogFile(T begin, T end, std::string log_path)
{
	ofstream ofs_log(log_path);

	for (auto it = begin; it != end; it++)
	{
		ofs_log << left << *it << endl;
	}
	ofs_log.close();
}

//очистить лог
void Clear_LogFile()
{

	//fs::path log_path = path_LOG;
	//fs::remove(log_path);
	ofs.open(path_LOG, std::ios::out | std::fstream::trunc);
	ofs.close();
	LOG_IN_FILE("start");

}

void GetAttributes(ChapterData& ch);

//получить все текстуры в объекты TextureData, наполнить ими std::multiset<TextureData>textures;
void GetTextureFiles()
{
	//из папки
	fs::path path = path_texture_folder;
	fs::recursive_directory_iterator itr(path), end_itr;

	while (itr != end_itr)
	{
		if (cancelExecution)
			break;
		if (fs::is_regular_file(*itr))
		{
			TextureData* d = new TextureData;

			d->TD_texture_name = itr->path();
			d->TD_size = fs::file_size(itr->path());
			d->TD_s_texture_name = d->TD_texture_name.string();
			textures.emplace(*d);
		}
		itr++;
	}

	//std::sort(textures.begin(), textures.end());
}

int Count_GameFieldRes()
{
	std::string static_text = "/static/";

	tinyxml2::XMLDocument Gamefield_Resources_doc;
	Gamefield_Resources_doc.LoadFile(path_gamefield_resources.c_str());
	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();
	int count = 0;

	for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
	{
		
		if (Textures_group->Attribute("basePath") == NULL) continue;
		std::string path_t = Textures_group->Attribute("basePath");

		if (path_t.find(static_text) != -1)
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

int Count_ObjectLibrary()
{	
	int count = 0;
	for (auto& obj_file : ObjLib_files)
	{

		tinyxml2::XMLDocument ObjectLibrary_doc;
		ObjectLibrary_doc.LoadFile(obj_file.string().c_str());

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

int Count_ChapterData()
{	

	tinyxml2::XMLDocument CH_doc;

	int count = 0;
	for (auto& ch_file : CH_files)
	{
		if (cancelExecution)
			return -1;
		CH_doc.LoadFile(ch_file.c_str());
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

int Count_ParticleEffect()
{
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

//преобразовать Gamefield_Resources.xml в объекты GameFieldRes (только текстуры из static папки . пример пути: - "basePath="textures/Gamefield/static/FirstGarden/Tutorial">"), наполнить set<GameFieldRes>GameField_objects;
void Get_GameFieldRes_Info()
{	
	count = 0;

	std::string static_text = "/static/";

	tinyxml2::XMLDocument Gamefield_Resources_doc;
	Gamefield_Resources_doc.LoadFile(path_gamefield_resources.c_str());
	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();


	fs::path root_path;
	std::string texture;
	std::string id;
	std::string atlas;

	for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
	{	
		if (cancelExecution)
			return;
		root_path = path_base_mm; //по base mm

		if (Textures_group->Attribute("basePath") == NULL) continue;

		std::string path_t = Textures_group->Attribute("basePath");

		if (Textures_group->Attribute("group") == NULL) atlas = "no atlas";
		else atlas = Textures_group->Attribute("group");

		if (path_t.find(static_text) != -1)
		{
			root_path /= path_t; //
			fs::path all_path;
			for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
			{	
				if (cancelExecution)
					return;
				all_path = root_path;
				GameFieldRes* gr = new GameFieldRes();

				all_path /= sprite->Attribute("path");
				all_path.replace_extension(".png");

				gr->gameFieldRes_full_path = all_path;
				//gr->GR_full_path.replace_extension(".png");
				gr->gameFieldRes_s_full_path = gr->gameFieldRes_full_path.string();
				gr->gameFieldRes_id = sprite->Attribute("id");
				gr->gameFieldRes_path_attr = sprite->Attribute("path");
				gr->gameFieldRes_texture_group_atlas = atlas;
				gr->gameFieldRes_path = path_t;



				gr->gameFieldRes_TextureData = FindTexture(all_path); //не может не найти иначе халты вылазят 


				gr->gameFieldRes_TextureData->TD_GRs.emplace(gr); //передал в текстуру ссылку на gr
				gr->gameFieldRes_TextureData->TD_exist_in_GR = "+";

				count++;
				if (cancelExecution)
					return;
				MyTool::MyForm3::UpdateProgress(count, "Collect from GameFieldResources : ", gr->gameFieldRes_s_full_path);

				GameField_objects.emplace(gr); 
				
			}
		}
	}


}


void Get_ObjectLibrary_Info()
{	
	if (cancelExecution)
		return;
	//int count = 0;
	std::string objItem_instanceClass_temp;
	std::string objItem_defaultZOrder_temp;
	std::string objItem_isIndoor_temp;
	std::vector<ObjLibLayer*> objItem_layers_temp; //лейеры из которых состоит item


	//GameFieldRes* objLayer_GameFieldRes_temp; //
	std::vector<ObjLibItem*> objLayer_items_temp; //items где присутствует данный лейер

	for (auto& obj_file : ObjLib_files)
	{
		if (cancelExecution)
			return;

		tinyxml2::XMLDocument ObjectLibrary_doc;
		ObjectLibrary_doc.LoadFile(obj_file.string().c_str());

		tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibrary_doc.FirstChildElement();


		for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
		{	
			if (cancelExecution)
				return;
			objItem_instanceClass_temp = Objects->Attribute("instanceClass");
			if (Objects->Attribute("defaultZOrder") == NULL)
				objItem_defaultZOrder_temp = "-";
			else
				objItem_defaultZOrder_temp = Objects->Attribute("defaultZOrder");

			if (Objects->Attribute("isIndoor") == NULL)
				objItem_isIndoor_temp = "-";
			else
				objItem_isIndoor_temp = Objects->Attribute("isIndoor");

			for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
			{	
				if (cancelExecution)
					return;
				ObjLibItem* ObjItem = new ObjLibItem;
				ObjItem->objItem_item_id = item_node->Attribute("id");

				if (item_node->Attribute("noRedesignDeformation") == NULL)
					ObjItem->objItem_noRedesignDeformation = "false";
				else
					ObjItem->objItem_noRedesignDeformation = item_node->Attribute("noRedesignDeformation");
				
				ObjItem->objItem_instanceClass = objItem_instanceClass_temp;
				ObjItem->objItem_isIndoor = objItem_isIndoor_temp;
				ObjItem->objItem_defaultZOrder = objItem_defaultZOrder_temp;
				ObjItem->objItem_cluster = obj_file.parent_path().stem().string();

				for (tinyxml2::XMLElement* layer_node = item_node->FirstChildElement(); layer_node != NULL; layer_node = layer_node->NextSiblingElement())
				{	
					if (cancelExecution)
						return;
					if (to_string(layer_node->Name()) == "layer")
					{
						ObjLibLayer* Objlayer = new ObjLibLayer;
						if (layer_node->Attribute("texture") != NULL)
						{
							Objlayer->objLayer_texture = layer_node->Attribute("texture");
						}
						Objlayer->objLayer_type = layer_node->Attribute("type");

						if (layer_node->Attribute("zOrder") != NULL)
							Objlayer->objLayer_zOrder = layer_node->Attribute("zOrder");
						
						//указатель в лейере на GameFieldRes ищем если тип текстура, а не эффект или свет - эффекта или света нет в GR
						if (Objlayer->objLayer_type == "texture")
						{	
							if (cancelExecution)
								return;
							auto& it_GR = std::find_if(GameField_objects.begin(), GameField_objects.end(), 
								[&](GameFieldRes* gr)
							{
								return  Objlayer->objLayer_texture == gr->gameFieldRes_id;
							});

							if (it_GR == GameField_objects.end())
							{
								Objlayer->objLayer_GameFieldRes = nullptr; //type="effect" или type="light" только спайн анимация??
							}
							else
							{

								(*it_GR)->gameFieldRes_ObjLibLayers.push_back(&(*Objlayer));
								(*it_GR)->gameFieldRes_TextureData->TD_exist_in_OL = "+";
								(*it_GR)->gameFieldRes_unique_items.emplace(&(*ObjItem));

								Objlayer->objLayer_GameFieldRes = (*it_GR);
							}
						}

						//ссылка в леере на содержащий лейер айтем 
						Objlayer->objLayer_item = ObjItem;

						//вектор лееров, составляющих item (ссылка из айтема на леер, вектор так как может быть несколько слоев)
						ObjItem->objItem_layers.push_back(Objlayer);
						ObjLib_layers.emplace(Objlayer);
					}
					
					
				}
				count++;
				if (cancelExecution)
					return;
				MyTool::MyForm3::UpdateProgress(count, "Collect items from ObjectLibrary : ", ObjItem->objItem_item_id);
				ObjLib_items.emplace(ObjItem);
			}
		}

	}

}

//получить все объекты в файлах Ch
void Get_ChapterData_Info()
{	
	if (cancelExecution)
		return;
	//int count = 0;
	std::string chData_storyInfo_chapter_id_temp; //
	std::string chData_storyInfo_repair_temp; //
	std::string chData_storyInfo_step_temp; //

	tinyxml2::XMLDocument CH_doc;

	for (auto& ch_file : CH_files)
	{
		if (cancelExecution)
			return;
		CH_doc.LoadFile(ch_file.c_str());
		tinyxml2::XMLElement* group = CH_doc.FirstChildElement();

		chData_storyInfo_chapter_id_temp = group->Attribute("id");

		LOG(chData_storyInfo_chapter_id_temp);
		for (tinyxml2::XMLElement* repair_extension = group->FirstChildElement(); repair_extension != NULL; repair_extension = repair_extension->NextSiblingElement())
		{	
			if (cancelExecution)
				return;
			LOG(repair_extension->Name());
			if (to_string(repair_extension->Name()) != "repair") continue;

			chData_storyInfo_repair_temp = repair_extension->Attribute("id");
			for (tinyxml2::XMLElement* steps = repair_extension->FirstChildElement(); steps != NULL; steps = steps->NextSiblingElement())
			{	
				if (cancelExecution)
					return;
				LOG(steps->Name());


				if (to_string(steps->Name()) != "steps") continue;//могут быть effects

				for (tinyxml2::XMLElement* step = steps->FirstChildElement(); step != NULL; step = step->NextSiblingElement())
				{	
					if (cancelExecution)
						return;
					LOG(step->Name());
					if (to_string(step->Name()) != "step") continue;
					LOG(step->Attribute("id"));

					chData_storyInfo_step_temp = step->Attribute("id");

					for (tinyxml2::XMLElement* object = step->FirstChildElement(); object != NULL; object = object->NextSiblingElement())
					{	
						if (cancelExecution)
							return;
						LOG(object->Name());
						if (to_string(object->Name()) == "object")
						{
							LOG(object->Attribute("id"));
							//собираем чаптеры
							ChapterData* ch = new ChapterData;
							ch->chData_storyInfo_chapter_id = chData_storyInfo_chapter_id_temp;
							ch->chData_storyInfo_repair = chData_storyInfo_repair_temp;
							ch->chData_storyInfo_step = chData_storyInfo_step_temp;

							ch->chData_id = object->Attribute("id");
							ch->chData_text = object->GetText();
							GetAttributes(*ch);
							
							count++;
							//найти item для датаайди (он 1)
							auto& ob_it = std::find_if(ObjLib_items.begin(), ObjLib_items.end(),
								[&](ObjLibItem* obj)
							{
								return obj->objItem_item_id == ch->chData_text_dataid;
							});


							if (ob_it == ObjLib_items.end())
								ch->chData_ObjLibItem = NULL; //датаайди, которой нет в objectLibrary?? не может быть
							else
							{
								/*const ObjLibItem* ch1 = *ob_it;
								ObjLibItem& ch2 = const_cast<ObjLibItem&>(*ch1);*/
								//ObjLibItem *ch3 = &ch3;
								ch->chData_ObjLibItem = *ob_it;
								//ObjLibItem
								ch->chData_ObjLibItem->objItem_ChapterDatas.push_back(ch);
							}

							
							
							for (auto& layer : ch->chData_ObjLibItem->objItem_layers)
							{	
								if (layer->objLayer_type == "texture")
									layer->objLayer_GameFieldRes->gameFieldRes_TextureData->TD_exist_in_CH = "+";

							}
							if (cancelExecution)
								return;
							MyTool::MyForm3::UpdateProgress(count, "Collect object from Chapter files : ", ch->chData_storyInfo_chapter_id + " - " + ch->chData_storyInfo_repair + " - " + ch->chData_storyInfo_step + " - " + ch->chData_text_dataid);
							CH_objects.emplace(ch);
						}
					}
				}
			}
		}
	}


}

//получить все particle effects
void Get_ParticleEffect_Info()
{	
	int count_local = 0;
	if (cancelExecution)
		return;
	//int count=0;
	fs::path p_type;
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

				//std::string node_name = to_string(ParticleSystem->Name());
				if (ParticleSystem != NULL && to_string(ParticleSystem->Name()) == "ParticleSystem")
				{
					ParticleEffect* p = new ParticleEffect();

					int pos = itr->path().string().find("cluster");
					if (pos != -1)
					{
						std::string name;
						std::string path = itr->path().string();
						while (path[pos] != '/' && path[pos] != '\\')
						{
							name += path[pos];
							pos++;
						}
						p->partEff_cluster = name;
					}
					else p->partEff_cluster = "base_mm/effect";
					p->partEff_name_p = itr->path();
					p->partEff_name_s = itr->path().string();

					
					for (; ParticleSystem != NULL; ParticleSystem = ParticleSystem->NextSiblingElement())
					{	
						if (cancelExecution)
							return;
						ParticleEffectLayer* effect_layer = new ParticleEffectLayer;

						p_type = path_base_mm;
						if (ParticleSystem->Attribute("texture") != NULL)
						{
							p_type /= ParticleSystem->Attribute("texture");
							p_type.replace_extension(".png");

							if (fs::exists(p_type))
								effect_layer->effectLayer_file_exist = "+";

							
							effect_layer->effectLayer_effectTexture_path_p = p_type;
							effect_layer->effectLayer_effectTexture_path_s = p_type.string();
							
					
							if (effect_layer->effectLayer_file_exist == "+")
							{
								TextureData* td = FindTexture(p_type);
								if (td != nullptr)
								{
									effect_layer->effectLayer_TextureData = td;
									//если такая текстура есть в наборе текстур, то пушу в сет указатель на эффект
									effect_layer->effectLayer_TextureData->TD_effects.emplace(&(*p));
								}
								
							}
							p->partEff_ParticleEffectLayers.push_back(effect_layer);
						}
					}


					std::string eff_name = itr->path().filename().stem().string();
					if (cancelExecution)
						return;
					//найти леер, передать в него ссылку на эффект
					std::for_each(ObjLib_layers.begin(), ObjLib_layers.end(),
						[&]( ObjLibLayer* layer)
					{	
						
						if (eff_name == layer->objLayer_texture)
						{
							//леер в партикл эффект
							p->partEff_ObjLibLayers.push_back(layer);
							//ссылка в леере на партокловый эффект
							layer->objItem_ParticleEffect = p;
							
							if (!layer->objLayer_item->objItem_ChapterDatas.empty())
							{
								p->partEff_exist_in_CH = "+";
								if (layer->objLayer_type != "light" && layer->objLayer_type != "effect")
									layer->objLayer_GameFieldRes->gameFieldRes_TextureData->TD_EF_exist_in_CH = "+";
							}
						}
					});

					
					

					count++;
					count_local++;
					if (cancelExecution)
						return;
					MyTool::MyForm3::UpdateProgress(count, "Collect ParticleEffects from cluster folders: ", p->partEff_name_s);
					particle_effects.emplace(p);
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
				ParticleEffect* p = new ParticleEffect();
				p->partEff_name_p = itr->path();
				p->partEff_name_s = itr->path().string();
				p->partEff_cluster = "base_mm/effects";

				//лееры в объекты
				for (; ParticleSystem != NULL; ParticleSystem = ParticleSystem->NextSiblingElement())
				{	
					if (cancelExecution)
						return;
					ParticleEffectLayer* effect_layer = new ParticleEffectLayer;

					p_type = path_base_mm;
					if (ParticleSystem->Attribute("texture") != NULL)
					{

						p_type /= ParticleSystem->Attribute("texture");
						p_type.replace_extension(".png");

						effect_layer->effectLayer_effectTexture_path_p = p_type;
						effect_layer->effectLayer_effectTexture_path_s = p_type.string();

						if (fs::exists(p_type))
							effect_layer->effectLayer_file_exist = "+";
						
						/*TextureData *temp = new TextureData;
						temp->TD_texture_name = effect_layer->effectLayer_effectTexture_path_p;*/


						if (effect_layer->effectLayer_file_exist == "+" && p_type.string().find("Gamefield") !=-1 && p_type.string().find("static") != -1)
						{
							TextureData* td = FindTexture(p_type);
							if (td != nullptr)
							{
								effect_layer->effectLayer_TextureData = td;
								//если такая текстура есть в наборе текстур, то пушу в сет указатель на эффект
								effect_layer->effectLayer_TextureData->TD_effects.emplace(&(*p));
							}
						}
						p->partEff_ParticleEffectLayers.push_back(effect_layer);
						//texture_particle_effect.emplace(std::make_pair(p_type, itr->path())); //вставляем текстуру, эффект
					}
				}

				std::string eff_name = itr->path().filename().stem().string();
				if (cancelExecution)
					return;
				//найти леер, передать в него ссылку на эффект
				std::for_each(ObjLib_layers.begin(), ObjLib_layers.end(),
					[&](ObjLibLayer* layer)
				{
					if (layer->objLayer_type == "light" || layer->objLayer_type == "effect")
						if (eff_name == layer->objLayer_texture)
						{
							/*ObjLibLayer* layer2 = layer;
							ObjLibLayer& layer3 = const_cast<ObjLibLayer&>(*layer2);
							ObjLibLayer* layer4 = &layer3;*/
							//леер в партикл эффект
							p->partEff_ObjLibLayers.push_back(layer);
							//ссылка в леере на партокловый эффект
							layer->objItem_ParticleEffect = &(*p);

							if (!layer->objLayer_item->objItem_ChapterDatas.empty())
							{
								p->partEff_exist_in_CH = "+";
								if (layer->objLayer_type != "light" && layer->objLayer_type != "effect")
									layer->objLayer_GameFieldRes->gameFieldRes_TextureData->TD_EF_exist_in_CH = "+";
							}
						}
				});

				count_local++;
				count++;
				if (cancelExecution)
					return;
				MyTool::MyForm3::UpdateProgress(count, "Collect ParticleEffects from base_mm/effects: ", p->partEff_name_s);
				particle_effects.emplace(p);
				itr++;
				continue;

			}

		}
		itr++;
	}

}

void DeleteOrNot()
{	
	if (cancelExecution)
		return;

	bool _delete;;

	for (auto& texture : textures)
	{	
		_delete = false;
		if (!texture.TD_GRs.empty()) //есть в GR
		{	
			int chapters = 0;
			for (auto& gr : texture.TD_GRs)
			{
				if (!gr->gameFieldRes_unique_items.empty()) //есть items
				{
					for (auto& item : gr->gameFieldRes_unique_items)
					{
						chapters += item->objItem_ChapterDatas.size(); //посчитали объекты в чаптерах
					}
				}
			}
			if (chapters == 0) //айтема нет в чаптерах
			{
				texture.TD_exist_in_CH = "-";
				_delete = true;
			}
			else //айтем есть в чаптерах
			{
				texture.TD_exist_in_CH = "+";
			}
		}
		else
		{
			_delete = true;
		}

		if (_delete && texture.TD_effects.empty())
		{
			texture.TD_to_delete = true;
		}

	}
}

//атрибуты для ChapterIds
void GetAttributes(ChapterData& ch)
{
	std::string text = ch.chData_text;

	std::string dataid_marker = "\"dataId\"";
	int start_dataid = text.find(dataid_marker);
	std::string starting_with_dataid(text, start_dataid, text.length()); //стринг начиная с dataId

	ch.chData_text_dataid = GetAttr_CH(starting_with_dataid, "\"dataId\":");
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

	//если есть ИСо
	std::string before_data_id(text, 0, start_dataid - 1);

	ch.chData_text_iso_uL = GetAttr_CH(before_data_id, "\"uL\":");
	ch.chData_text_iso_uR = GetAttr_CH(before_data_id, "\"uR\":");
	ch.chData_text_iso_x = GetAttr_CH(before_data_id, "\"x\":");
	ch.chData_text_iso_y = GetAttr_CH(before_data_id, "\"y\":");
	ch.chData_text_iso_z = GetAttr_CH(before_data_id, "\"z\":");
}

/////отметить мертвые эффекты
void Get_dead_effects()
{
	int i = 0;
	int size;
	for (auto& eff : particle_effects)
	{
		size = eff->partEff_ParticleEffectLayers.size();
		i = 0;
		for (auto& eff_layer : eff->partEff_ParticleEffectLayers)
		{
			if (eff_layer->effectLayer_file_exist == "-")
			{
				i++;
			}
		}

		if (i == size && (eff->partEff_name_s.find("Match3") != -1 || eff->partEff_name_s.find("Match3") != -1))
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

		if (i > 0 && i < size && (eff->partEff_name_s.find("Match3") != -1 || eff->partEff_name_s.find("Match3") != -1))
		{
			eff->partEff_dead = "Match3 partially dead";
			continue;
		}

		if (i > 0 && i < size)
		{
			eff->partEff_dead = "partially dead";
			continue;
		}

		if (i == 0 && (eff->partEff_name_s.find("Match3") != -1 || eff->partEff_name_s.find("Match3") != -1))
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

//удалить запись из GamefieldResources по имени текстуры
void DeleteFromGamefieldResources(TextureData* td)
{	
	bool brk = false;
	std::string static_text = "/static/";

	tinyxml2::XMLDocument Gamefield_Resources_doc;
	Gamefield_Resources_doc.LoadFile(path_gamefield_resources.c_str());
	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();

	fs::path	GR_root;
	std::string GR_id;

	for (auto& gr : td->TD_GRs)
	{	
		brk = false;
		for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
		{
			GR_root = path_base_mm;

			if (Textures_group->Attribute("basePath") == NULL) continue;

			std::string path_t = Textures_group->Attribute("basePath");

			if (path_t.find(static_text) != -1)
			{
				GR_root /= path_t;
				for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
				{
					std::string s = sprite->Attribute("path");
					//удалить запись из Gamefield_Resources
					if (gr->gameFieldRes_path == path_t && gr->gameFieldRes_path_attr == sprite->Attribute("path"))
					{
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
	}
}

//удалить запись из ObjectLibrary по item (в каждом ObjectLibrary)
void DeleteFromObjectLibrary(TextureData* td)
{	
	bool brk = false;
	for (auto& gr : td->TD_GRs)
	{	
		brk = false;
		//все items в которых юзается текстура
		//убрать повторяющиеся леера, оставить уникальные
		std::sort(gr->gameFieldRes_ObjLibLayers.begin(), gr->gameFieldRes_ObjLibLayers.end());
		auto last = std::unique(gr->gameFieldRes_ObjLibLayers.begin(), gr->gameFieldRes_ObjLibLayers.end());

		for (auto& item = gr->gameFieldRes_ObjLibLayers.begin(); item != last; item++)
		{
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

						if ((*item)->objLayer_item->objItem_item_id == item_node->Attribute("id"))
						{
							Objects->DeleteChild(item_node);
							ObjectLibtary_doc.SaveFile(obj_file.string().c_str());
							brk = true;
							break;
						}
						
					}
					if (brk)
						break;
				}
			}
		}
	}
}

//найти TextureData в контейнере
TextureData* FindTexture(fs::path texture_path)
{
	auto& it_td = std::find_if(textures.begin(), textures.end(),
		[&](const TextureData& td)
	{
		return fs::equivalent(texture_path, td.TD_texture_name);
	});

	if (it_td == textures.end())
		return nullptr;
	else
	{
		const TextureData *it2 = &(*it_td);
		TextureData& it3 = const_cast<TextureData&>(*it2);
		TextureData* p = &it3;
		return p;
		//return &(*it_td);
	}
		
}

//найти ParticleEffect в контейнере
ParticleEffect* FindEffect(fs::path effect_path)
{
	auto& it_td = std::find_if(particle_effects.begin(), particle_effects.end(),
		[&](ParticleEffect* ef)
	{
		return fs::equivalent(effect_path, ef->partEff_name_p);
	});

	if (it_td == particle_effects.end())
		return NULL;
	else
	{	
		//const ParticleEffect *it2 = *it_td;
		//ParticleEffect& it3 = const_cast<ParticleEffect&>(*it2);
		//ParticleEffect* p = &it3;
		return *it_td;

	}

}


void RemoveProblems()
{
	for (auto& it_td = textures.begin(); it_td != textures.end(); it_td++)
	{
		it_td->TD_problem = false;
	}
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

void OL_Clusters_in_one_string()
{	
	std::set<std::string>clusters;

	for (auto& texture : textures)
	{
		if (!texture.TD_GRs.empty())
		{	
			for (auto& gr : texture.TD_GRs)
			{
				if (!gr->gameFieldRes_unique_items.empty())
				{
					for (auto& item : gr->gameFieldRes_unique_items)
					{
						clusters.insert(item->objItem_cluster);
					}

					for (auto& obj : clusters)
					{
						texture.TD_clusters_OL += obj;
						texture.TD_clusters_OL += " ";
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
		if (itr->path().string().find("CH_") != -1)
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
			LOG_IN_FILE(deleting_count << '\t' << "Empty FOLDER" << '\t' << ec.message() << '\t' << "no file" << '\t' << p.string() << '\t' << "-" << '\t' << "-" << '\t' << "-");
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








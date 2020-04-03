#include "ChangeCHAttrib.h"
//#include "Optimize.h"
#include <algorithm>
#include "Macro.h"


bool ch_attrib_iso = true;
bool ch_attrib_dataid = true;
bool ch_attrib_skip_iso = false;
bool ch_attrib_all_objects = false;

std::string ch_attrib;
std::string ch_attrib_value;
std::string ch_attrib_repair;
std::string ch_attrib_step;

char ch_attrib_operation;

std::vector<std::string> ch_attrib_ids;

std::vector<std::string>iso_attributes = { "uL" ,"uR" ,"x" ,"y", "z" };
std::vector<std::string>attributes = { "dataId" ,"m" ,"rand","x" ,"y","zOrder" };

std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh;

//std::string path_to_list_layers = "C:/Users/pecherikin-o/Desktop/work/Scripts/for_swings_manual.txt";
//int count_g = 0;
//std::string path_SwingManager = "D:/Projects/Mystery_Garden/base_mm/SwingManager.xml";
//std::string path_SwingManager_save_to = "D:/Projects/Mystery_Garden/base_mm/SwingManager.xml";
//std::string path_save_list_of_all_objects_to = "D:/AllObjectLibraryObjects.txt";
//std::string path_save_list_of_all_complicated_objects_to = "D:/AllObjectLibraryComplObjects.txt";
//std::string path_save_list_of_all_objects_to2 = "D:/AllObject.txt";
////выявить все объекты и слои в ObjectLibrary.xml, записать в документ
//void GetAllObjectsAndLayers()
//{
//	std::string item_id, texture, instanceClass, defaultZOrder;
//
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//	std::ofstream ofs(path_save_list_of_all_objects_to);
//
//	int count_layers = 0;
//	int count = 0;
//
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		instanceClass = Objects->Attribute("instanceClass");
//		if (Objects->Attribute("defaultZOrder") != NULL)
//			defaultZOrder = Objects->Attribute("defaultZOrder");
//		else defaultZOrder = "";
//
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			item_id = item->Attribute("id");
//			for (tinyxml2::XMLElement* layer = item->FirstChildElement(); layer != NULL; layer = layer->NextSiblingElement())
//			{
//				if (to_string(layer->Name()) == "layer")
//				{
//					if (to_string(layer->Attribute("type")) == "light")
//					{
//						texture = "none";
//					}
//					else texture = layer->Attribute("texture");
//
//
//					count++;
//					ofs << count << '\t' << instanceClass << '\t' << item_id << '\t' << texture << '\t' << "defaultZOrder:" << defaultZOrder << endl;
//				}
//			}
//		}
//	}
//	ofs.close();
//}
////выявить все сложные объекты и слои в ObjectLibrary.xml, записать в документ
//void GetAllComplicatedObjectsAndLayers()
//{
//	std::string item_id, texture, instanceClass, defaultZOrder;
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//
//
//	int count_items = 0;
//	int count_layers = 0;
//	int count_all = 0;
//
//	std::ofstream ofs_comp(path_save_list_of_all_complicated_objects_to);
//
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		instanceClass = Objects->Attribute("instanceClass");
//
//		if (Objects->Attribute("defaultZOrder") != NULL)
//			defaultZOrder = Objects->Attribute("defaultZOrder");
//
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			count_items++;
//			count_layers = 0;
//			item_id = item->Attribute("id");
//			for (tinyxml2::XMLElement* layer = item->FirstChildElement(); layer != NULL; layer = layer->NextSiblingElement())
//			{
//				count_layers++;
//				count_all++;
//				if (to_string(layer->Name()) == "layer")
//					if ((layer->NextSiblingElement() != NULL && to_string(layer->NextSiblingElement()->Name()) == "layer")
//						|| (layer->PreviousSiblingElement() != NULL && to_string(layer->PreviousSiblingElement()->Name()) == "layer"))
//					{
//
//						if (to_string(layer->Attribute("type")) == "light")
//							texture = "none";
//						else texture = layer->Attribute("texture");
//
//						//count++;
//						ofs_comp << count_all << '\t' << count_items << '\t' << instanceClass << '\t' << count_layers << '\t' << item_id << '\t' << texture << '\t' << "defZorder:" << defaultZOrder << endl;
//					}
//					else
//					{
//						count_layers--;
//						count_items--;
//						count_all--;
//					}
//			}
//		}
//	}
//	ofs_comp.close();
//}
//Все объекты в ObjectLibrary.xml (только id)
//void GetUniqObjectsFromObjectLibrary()
//{
//	std::string item_id, texture, instanceClass, defaultZOrder;
//
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//	std::ofstream ofs(path_save_list_of_all_objects_to2);
//
//	int count_layers = 0;
//	int count = 0;
//
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		instanceClass = Objects->Attribute("instanceClass");
//		if (Objects->Attribute("defaultZOrder") != NULL)
//			defaultZOrder = Objects->Attribute("defaultZOrder");
//		else defaultZOrder = "";
//
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			count++;
//			item_id = item->Attribute("id");
//			ofs << item_id << std::endl;
//
//		}
//	}
//	ofs.close();
//}
//
///////////////блок для шатания в SwingManager
//
////получить id по текстуре из GamefiledResources
//std::string GetLayerIdFromGamefiledResources(std::string layer_texture)
//{
//	tinyxml2::XMLDocument GamefiledResources_doc;
//	GamefiledResources_doc.LoadFile(path_gamefield_resources.c_str());
//	tinyxml2::XMLElement* Resources = GamefiledResources_doc.FirstChildElement();
//	int count_rows = 0;
//	bool found = false;
//	std::string layer_id_res;
//	std::string texture_path;
//	std::string texture_group;
//	std::ofstream ofs_log;
//	ofs_log.open(path_LOG, std::ios::app);
//
//	for (tinyxml2::XMLElement* Textures = Resources->FirstChildElement(); Textures != NULL; Textures = Textures->NextSiblingElement())
//	{
//		//texture_path = Textures->Attribute("basePath");
//		/*if (Textures->Attribute("group")!=NULL)
//		texture_group = Textures->Attribute("group");*/
//
//
//		count_rows++;
//		for (tinyxml2::XMLElement* texture = Textures->FirstChildElement(); texture != NULL; texture = texture->NextSiblingElement())
//		{
//			count_rows++;
//
//			if (texture->Attribute("id") == layer_texture)
//			{
//				found = true;
//				layer_id_res = texture->Attribute("path");
//				return layer_id_res;
//			}
//		}
//	}
//
//	//cout << layer_id_res << endl;
//	//если нет в gameresources записать в ЛОГ и выйти
//	if (!found)
//	{
//		ofs_log << layer_texture << '\t' << "не найдена в GamefiledResources(неверное имя текстуры)" << endl;
//		ofs_log.close();
//		return "";
//	}
//}
//
////найти и скопировать нужный layer из ObjectLibrary
//void CopyTextureLayerFromCompObject(std::string prefab_item_id, std::string layer_texture, tinyxml2::XMLDocument& clone)
//{
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//
//
//	//XMLDocument* clone;
//	bool found = false;
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			if (item->Attribute("id") == prefab_item_id)
//			{
//				for (tinyxml2::XMLElement* layer = item->FirstChildElement(); layer != NULL; layer = layer->NextSiblingElement())
//				{
//					if (to_string(layer->Name()) == "layer" && layer->Attribute("texture") == layer_texture)
//					{
//						tinyxml2::XMLNode* copy = layer->ShallowClone(&clone);
//						clone.InsertEndChild(copy);
//						//clone.Print();
//						found = true;
//						break;
//					}
//				}
//			}
//			if (found) break;
//		}
//		if (found) break;
//	}
//	std::ofstream ofs_log;
//	ofs_log.open(path_LOG, std::ios::app);
//	//если нет то записать в ЛОГ, выход из программы
//	if (!found)
//	{
//		ofs_log << layer_texture << '\t' << "текстура лейера не найдена в ObjectLbrary" << std::endl;
//		exit(1);
//	}
//	//return clone;
//}
//
////проверить есть ли уже в ObjectLibrary такой item
//bool CheckExistIteminObjectLibrary(std::string layer_id)
//{
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//
//	int count_rows = 1;
//	bool found = false;
//
//	//ofstream ofs_log;
//	//ofs_log.open("D:/Log.txt", ios::app);
//
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		count_rows++;
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			count_rows++;
//			if (item->Attribute("id") == layer_id)
//			{
//				found = true;
//				return true;
//
//			}
//		}
//	}
//	return false;
//}
//
////задать новое имя Id в ObjectLibrary с проверкой на существование
//std::string GetNewItemIdName(std::string layer_id, int index)
//{
//	std::string extracted = "_extracted_";
//	//string extracted_find = "_extracted_";
//
//	if (layer_id.find(extracted) != -1)
//	{
//		index++;
//
//		int first = layer_id.find(extracted);
//		int j = first + 2;
//		while (layer_id[j] != '_')
//		{
//			j++;
//		}
//		int size = layer_id.size();
//		int erase = size - (size - j - 1);
//
//
//		layer_id.erase(erase);
//		//cout << layer_id << endl;
//
//		layer_id = layer_id + to_string(index);
//		if (CheckExistIteminObjectLibrary(layer_id))
//		{
//			layer_id = GetNewItemIdName(layer_id, index);
//			return layer_id;
//		}
//		else
//		{
//			//index = 0;
//			return layer_id;
//		}
//
//	}
//	else
//	{
//
//		layer_id = layer_id + extracted;
//		if (CheckExistIteminObjectLibrary(layer_id))
//		{
//			//index++;
//			layer_id = GetNewItemIdName(layer_id, index);
//			return layer_id;
//		}
//		return layer_id;
//	}
//}
//
////создаем новый элемент следующим в конце Objects откуда его извлекли
//bool InsertNewItemInObjectLibrary(std::string prefab_item_id, std::string layer_id, tinyxml2::XMLDocument& clone)
//{
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//
//	bool inserted = false;
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			if (item->Attribute("id") == prefab_item_id);
//			{
//				//вставляем новый item + слой здесь
//				tinyxml2::XMLDocument full_doc;
//				tinyxml2::XMLElement* new_item = full_doc.NewElement("item");
//				new_item->SetAttribute("id", layer_id.c_str());
//				full_doc.InsertFirstChild(new_item);
//				//full_doc.Print();
//
//				tinyxml2::XMLElement* layer_place = full_doc.FirstChildElement();
//				tinyxml2::XMLNode* clone_for_copy = clone.FirstChildElement();
//				tinyxml2::XMLNode* copy = clone_for_copy->ShallowClone(&full_doc);
//
//				layer_place->InsertFirstChild(copy);
//
//				tinyxml2::XMLNode* clone_full_doc_for_copy = full_doc.FirstChildElement();
//				tinyxml2::XMLNode* full_doc_copy = clone_full_doc_for_copy->DeepClone(&ObjectLibtary_doc);
//
//				Objects->InsertEndChild(full_doc_copy);
//				inserted = true;
//
//				ObjectLibtary_doc.SaveFile(path_ObjectLibrary_to_save.c_str());
//
//				return true;
//				//if (!found) ofs_log << '\t' << "вставлен в ObjectLibrary с айди " << layer_id << endl; //если нет в ЛОГ
//			}
//		}
//	}
//	return false;
//}
//
////вставить новый item в CH_firstGarden - через строки
//bool InsertNewItemInCH_firstGarden(std::string prefab_item_id, std::string layer_id)
//{
//	std::string lineXML;
//	std::fstream fs(path_CH_FirstGarden);
//	std::ofstream ofs_ch(path_CH_FirstGarden_save_to);
//	bool do_it = false;
//	while (!fs.eof())
//	{
//		do_it = false;
//		getline(fs, lineXML);
//
//		int first = lineXML.find("dataId");
//		std::string temp;
//		if (first != -1)
//		{
//			//cout << lineXML << endl;
//			first += 9;
//
//			std::string temp_id;
//			int j = first;
//			while (lineXML[j] != '"')
//			{
//				temp_id += lineXML[j];
//				j++;
//			}
//			//cout << temp_id << endl;
//
//			int length_id = j - first;
//
//			temp = lineXML;
//
//			if (temp_id == prefab_item_id)
//			{
//				//cout << temp << endl;
//				temp.erase(first, length_id); //заменить айди префаба в тексте
//
//				//cout << temp << endl;
//				temp.insert(first, layer_id);
//
//				//cout << temp << endl;
//
//				do_it = true;
//
//			}
//		}
//		//cout << lineXML << endl << temp;
//		ofs_ch << lineXML << std::endl;
//		if (do_it) ofs_ch << temp << std::endl;
//	}
//	return true;
//}
//
////вставить новый item в CH_firstGarden - через XML
//bool InsertNewItemInCH_firstGardenX(std::string prefab_item_id, std::string layer_id)
//{
//
//	std::string prefab_item_id_ = '"' + prefab_item_id + '"';
//	//cout << prefab_item_id_ << endl;
//
//	tinyxml2::XMLDocument CH_FirstGarden_doc;
//	CH_FirstGarden_doc.LoadFile(path_CH_FirstGarden.c_str());
//	tinyxml2::XMLElement* group = CH_FirstGarden_doc.FirstChildElement();
//
//	bool inserted = false;
//	for (tinyxml2::XMLElement* repair_extension = group->FirstChildElement(); repair_extension != NULL; repair_extension = repair_extension->NextSiblingElement())
//	{
//		//cout << repair_extension->Name() << endl;
//		if (to_string(repair_extension->Name()) == "repair")
//			for (tinyxml2::XMLElement* steps = repair_extension->FirstChildElement(); steps != NULL; steps = steps->NextSiblingElement())
//			{
//				//cout << steps->Name() << endl;
//				if (to_string(steps->Name()) == "steps")
//					for (tinyxml2::XMLElement* step = steps->FirstChildElement(); step != NULL; step = step->NextSiblingElement())
//					{
//						//cout << step->Name() << endl;
//						if (to_string(step->Name()) == "step")
//							for (tinyxml2::XMLElement* object = step->FirstChildElement(); object != NULL; object = object->NextSiblingElement())
//							{
//								//cout << object->Name() << endl;
//								if (to_string(object->Name()) == "object")
//								{
//									std::string temp = object->GetText();
//									//cout << temp << endl;
//									std::string copy_temp;
//									int index_first = temp.find(prefab_item_id_);
//									if (index_first != -1)
//									{
//										int j = index_first + 1;
//										while (temp[j] != '"')
//										{
//											j++;
//										}
//
//										int length = j - index_first;
//										temp.erase(index_first + 1, length - 1);
//										//cout << temp << endl;
//
//										temp.insert(index_first + 1, layer_id);
//										//cout << temp << endl;
//										tinyxml2::XMLDocument clone;
//
//										tinyxml2::XMLNode* copy = object->ShallowClone(&clone);
//										clone.InsertEndChild(copy);
//										clone.FirstChildElement()->SetText(temp.c_str());
//										//clone.Print();
//
//
//										tinyxml2::XMLNode* clone_for_copy = clone.FirstChildElement();
//										tinyxml2::XMLNode* full_doc_copy = clone_for_copy->DeepClone(&CH_FirstGarden_doc);
//
//										//XMLNode* clone_full_doc_for_copy = full_doc_copy->FirstChildElement();
//										//XMLNode* full_doc_copy = clone->DeepClone(&CH_FirstGarden_doc);
//
//
//										step->InsertEndChild(full_doc_copy);
//
//
//										CH_FirstGarden_doc.SaveFile(path_CH_FirstGarden_save_to.c_str());
//
//									}
//								}
//							}
//					}
//			}
//	}
//	return true;
//}
//
////удалить слой из префаба из Objectlibrary
//bool DeleteLayerFromPrefabObjectLibrary(std::string prefab_item_id, std::string layer_texture)
//{
//	tinyxml2::XMLDocument ObjectLibtary_doc;
//	ObjectLibtary_doc.LoadFile(path_ObjectLibrary.c_str());
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibtary_doc.FirstChildElement();
//
//	bool deleted = false;
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		for (tinyxml2::XMLElement* item = Objects->FirstChildElement(); item != NULL; item = item->NextSiblingElement())
//		{
//			if (item->Attribute("id") == prefab_item_id)
//			{
//				for (tinyxml2::XMLElement* layer_nopathpoint = item->FirstChildElement(); layer_nopathpoint != NULL; layer_nopathpoint = layer_nopathpoint->NextSiblingElement())
//				{
//					if (to_string(layer_nopathpoint->Name()) == "layer")
//					{
//						if (layer_nopathpoint->Attribute("texture") == layer_texture)
//						{
//							//cout << layer_nopathpoint->Attribute("texture") << '\t' << layer_nopathpoint->GetLineNum() << endl;
//							item->DeleteChild(layer_nopathpoint);
//							ObjectLibtary_doc.SaveFile(path_ObjectLibrary.c_str());
//							return true;
//						}
//					}
//				}
//			}
//		}
//	}
//	return false;
//}
//
////вставить новый item с айди в свинг-менеджер;
//void InsertItemInSwingManager(std::string layer_id, std::string angle, std::string time, std::string nWave)
//{
//	tinyxml2::XMLDocument Swing_doc;
//	Swing_doc.LoadFile(path_SwingManager.c_str());
//	tinyxml2::XMLElement* Swing_items = Swing_doc.FirstChildElement();
//
//	tinyxml2::XMLElement* new_item = Swing_doc.NewElement("item");
//
//	new_item->SetAttribute("id", layer_id.c_str());
//	new_item->SetAttribute("angle", angle.c_str());
//	new_item->SetAttribute("time", time.c_str());
//	new_item->SetAttribute("nWave", nWave.c_str());
//
//	Swing_items->InsertEndChild(new_item);
//
//	Swing_doc.SaveFile(path_SwingManager_save_to.c_str());
//
//
//}
//
////задать слою шатание хаотически
//void MakeItemSwingFromLayerChaotic(std::string path_layer_prefab_list, std::string angle, std::string time, std::string nWave)
//{
//	std::fstream fs(path_layer_prefab_list);
//	std::string prefab_item_id, layer_texture;
//	std::string s1, s2, s3, s4, s7;
//
//
//	while (!fs.eof())
//	{
//		fs >> s1 >> s2 >> s3 >> s4 >> prefab_item_id >> layer_texture >> s7;
//
//		std::string layer_id = GetLayerIdFromGamefiledResources(layer_texture);
//
//		tinyxml2::XMLDocument clone;
//		CopyTextureLayerFromCompObject(prefab_item_id, layer_texture, clone);
//		if (CheckExistIteminObjectLibrary(layer_id))
//		{
//			layer_id = GetNewItemIdName(layer_id, 0);
//			count_g++;
//			//std::cout << count_g << '\t' << "new layer id" << '\t' << layer_id << std::endl;
//		}
//		if (!InsertNewItemInObjectLibrary(prefab_item_id, layer_id, clone))
//		{
//			//std::cout << "error in InsertNewItemInObjectLibrary" << std::endl;
//			return;
//		}
//
//		if (!InsertNewItemInCH_firstGardenX(prefab_item_id, layer_id))
//		{
//			//std::cout << "error in InsertNewItemInCH_firstGarden" << std::endl;
//			return;
//		}
//		if (!DeleteLayerFromPrefabObjectLibrary(prefab_item_id, layer_texture))
//		{
//			//std::cout << "error in DeleteLayerFromPrefabObjectLibrary" << std::endl;
//			return;
//		}
//		InsertItemInSwingManager(layer_id, angle, time, nWave);
//
//		std::ofstream ofs_log;
//		ofs_log.open(path_LOG, std::ios::app);
//		ofs_log << "success for" << layer_texture << " из " << prefab_item_id << std::endl;
//	}
//	fs.close();
//	std::cout << "success" << std::endl;
//	system("pause");
//
//}
//
////
//void MakeItemSwingFromLayerSync(std::string path_layer_list, std::string angle, std::string time, std::string nWave)
//{
//
//	std::fstream fs(path_layer_list);
//	std::string prefab_item_id, layer_texture;
//	std::string s1, s2, s3, s4, s7;
//	std::string all_ids;
//	while (!fs.eof())
//	{
//		fs >> s1 >> s2 >> s3 >> s4 >> prefab_item_id >> layer_texture >> s7;
//		//cout << prefab_id <<'\t'<< texture << endl;
//		//MakeItemSwingFromLayerChaotic(prefab_id, texture, angle, time, nWave);
//		std::string layer_id = GetLayerIdFromGamefiledResources(layer_texture);
//		tinyxml2::XMLDocument clone;
//		CopyTextureLayerFromCompObject(prefab_item_id, layer_texture, clone);
//		if (CheckExistIteminObjectLibrary(layer_id))
//		{
//			layer_id = GetNewItemIdName(layer_id, 0);
//			count_g++;
//			//std::cout << count_g << '\t' << "new layer id" << '\t' << layer_id << std::endl;
//		}
//		if (!InsertNewItemInObjectLibrary(prefab_item_id, layer_id, clone))
//		{
//			//std::cout << "error in InsertNewItemInObjectLibrary" << std::endl;
//			return;
//		}
//		if (!InsertNewItemInCH_firstGardenX(prefab_item_id, layer_id))
//		{
//			//std::cout << "error in InsertNewItemInCH_firstGarden" << std::endl;
//			return;
//		}
//		if (!DeleteLayerFromPrefabObjectLibrary(prefab_item_id, layer_texture))
//		{
//			//std::cout << "error in DeleteLayerFromPrefabObjectLibrary" << std::endl;
//			return;
//		}
//		layer_id = layer_id + ", ";
//		all_ids += layer_id;
//	}
//
//	fs.close();
//
//	//std::cout << all_ids << std::endl;
//	//char ch = all_ids[all_ids.size()-2];
//	//cout << ch << endl;
//	all_ids.erase(all_ids.size() - 2);
//	//std::cout << all_ids << std::endl;
//
//	InsertItemInSwingManager(all_ids, angle, time, nWave);
//
//	std::ofstream ofs_log;
//	ofs_log.open(path_LOG, std::ios::app);
//	ofs_log << "success for" << layer_texture << " из " << prefab_item_id << std::endl;
//}
//
////расшатать список объектов
//void MakeListItemSwing(std::string path_layer_prefab_list, std::string angle, std::string time, std::string nWave)
//{
//	std::fstream fs(path_layer_prefab_list);
//	std::string id;
//
//	while (!fs.eof())
//	{
//		fs >> id;
//		InsertItemInSwingManager(id, angle, time, nWave);
//	}
//	fs.close();
//}
//////////////////////////////////////////////////

//////////////////////скорректировать любой аттрибут в CH_FirstGarden.xml

//рассчитать новый атрибут
double CalculateNewAttribute(double value_attr, char action, std::string value_to_change)
{
	std::istringstream ostr(value_to_change);
	double to_change;
	ostr >> std::fixed >> std::setprecision(2) >> to_change;
	switch (action)
	{
	case '+':
		return value_attr + to_change;
		break;
	case '-':
		return value_attr - to_change;
		break;
	case '/':
		return value_attr / to_change;
		break;
	case '*':
		return value_attr * to_change;
		break;
	case '=':
		return to_change;
		break;
	default:
		return to_change;
		break;
	}
}

//длина аттрибута
int AttributeLength(char* start)
{

	int j = 0;
	while (start[j] != ',' && start[j] != '}')
	{
		//cout << start[j] << endl;
		j++;
	}

	return j;
}

//длина атрибута IsoOffset
int AttributeLengthIso(char* start)
{

	int j = 0;
	while (start[j] != '}')
	{
		//cout << start[j] << endl;
		j++;
	}

	return j;
}

double string_to_double(std::string attr)
{
	double old_attr_value;
	std::stringstream s(attr);

	s >> std::fixed >> std::setprecision(2) >> old_attr_value;

	return old_attr_value;
}

std::string double_to_string(double new_attr)
{
	std::stringstream sss;

	sss << std::setprecision(2) << std::fixed << new_attr;

	std::string new_attr_str;

	sss >> new_attr_str;

	return new_attr_str;
}

//проверка аттрибута
bool valid_attribute(const std::string attribute_to_change)
{
	if (ch_attrib_iso)
	{
		auto it = std::find(iso_attributes.begin(), iso_attributes.end(), attribute_to_change);
		if (it == iso_attributes.end()) return false;
		else
			return true;
	}
	else
	{
		auto it = std::find(attributes.begin(), attributes.end(), attribute_to_change);
		if (it == attributes.end()) return false;
		else
			return true;
	}
}

//вставить исо
void InsertIsoBlock(std::string& text)
{
	std::string iso_block = "\"IsoOffset\":{},";
	text.insert(1, iso_block);
	//cout << text << endl;
}

//впервые вставить исо аттрибут
void InsertIsoAttributeFirstly(std::string& text, std::string attribute_to_change, std::string value_to_change, char action)
{
	std::string new_attr = double_to_string(CalculateNewAttribute(0.00, action, value_to_change));
	std::string s_attr = '"' + attribute_to_change + "\":" + new_attr;

	text.insert(14, s_attr);
	//cout << text << endl;
}

//Вставить отсутствующий аттрибут в блок Исо
std::string InsertNewIsoAttribute(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
{
	std::string new_attr = double_to_string(CalculateNewAttribute(0.00, action, value_to_change));

	std::string s_attr = '"' + attribute_to_change + "\":" + new_attr;
	int attr_length = s_attr.length();

	//vector<string>iso_attributes ={ "uL" ,"uR" ,"x" ,"y", "z"};

	auto it = find(iso_attributes.begin(), iso_attributes.end(), attribute_to_change);
	int dis = distance(iso_attributes.begin(), it); //каким аттрибут должен быть по порядку

	//cout << text << endl;

	//"IsoOffset":{"uL":49.0,"uR":49.0,"x":-11.25,"y":-11.25}

	int prev_start_symb_attr; 	//существует ли предыдущий

	for (int i = dis - 1; i >= 0; i--)
	{
		std::string prev_attr = '"' + iso_attributes[i] + '"' + ':';
		prev_start_symb_attr = text.find(prev_attr); //ищем предыдущий аттрибут
		//cout << iso_attributes[i] << endl;

		if (prev_start_symb_attr != -1) //если есть предыдущий аттрибут
		{
			int prev_attr_length = AttributeLength(&text[prev_start_symb_attr]); //длина предыдущего аттрибута

			if (text[prev_start_symb_attr + prev_attr_length] == ',') //если после аттрибута запятая, значит после вставляемого останется аттрибут, добавим запятую
			{
				s_attr += ',';
				text.insert(prev_start_symb_attr + prev_attr_length + 1, s_attr);
				//cout << text << endl;
				return text;
			}
			else if (text[prev_start_symb_attr + prev_attr_length] == '}') //если после аттрибута закрывающая фиг скобка, значит после вставляемого ничего, добавим запятую перед
			{
				s_attr = ',' + s_attr;
				text.insert(prev_start_symb_attr + prev_attr_length, s_attr);
				//cout << text << endl;
				return text;
			}
		}


	}
	//если ничего, то вставляю первым  c запятой? да, потому что в пустой сразу вставляется аттрибут

	s_attr += ',';
	text.insert(14, s_attr);
	//cout << text << endl;
	return text;
}


//Вставить отсутствующий аттрибут
std::string InsertNewAttribute(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
{
	std::string new_attr;
	if (attribute_to_change == "m") new_attr = value_to_change;
	else
	{
		int new_attr_int = CalculateNewAttribute(0.00, action, value_to_change);
		new_attr = to_string(new_attr_int);
	}

	std::string s_attr = '"' + attribute_to_change + "\":" + new_attr;
	int attr_length = s_attr.length();

	//vector<string>attributes = { "dataId" ,"m" ,"rand","x" ,"y","zOrder" };

	auto it = find(attributes.begin(), attributes.end(), attribute_to_change);
	int dis = distance(attributes.begin(), it); //каким аттрибут должен быть по порядку

	//cout << text << endl;

	int prev_start_symb_attr; 	//существует ли предыдущий

	for (int i = dis - 1; i >= 0; i--)
	{
		//cout << attributes[i] << endl;
		std::string prev_attr = '"' + attributes[i] + '"' + ':';
		prev_start_symb_attr = text.find(prev_attr); //ищем предыдущий аттрибут

		if (prev_start_symb_attr != -1) //если есть предыдущий аттрибут
		{
			int prev_attr_length = AttributeLength(&text[prev_start_symb_attr]); //длина предыдущего аттрибута

			if (text[prev_start_symb_attr + prev_attr_length] == ',') //если после аттрибута запятая, значит после вставляемого останется аттрибут, добавим запятую
			{
				s_attr += ',';
				text.insert(prev_start_symb_attr + prev_attr_length + 1, s_attr);
				//cout << text << endl;
				return text;
			}
			else if (text[prev_start_symb_attr + prev_attr_length] == '}') //если после аттрибута закрывающая фиг скобка, значит после вставляемого ничего, добавим запятую перед
			{
				s_attr = ',' + s_attr;
				text.insert(prev_start_symb_attr + prev_attr_length, s_attr);
				//cout << text << endl;
				return text;
			}
		}
	}
	//если ничего, то вставляю первым  c запятой? да, потому что в пустой сразу вставляется аттрибут

	s_attr += ',';
	text.insert(14, s_attr);
	//cout << text << endl;
	return text;
}

//редактирование аттрибутов IsoOffset
std::string ReplaceInCHObjectTextIso(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
{
	std::string iso_offset = "\"IsoOffset\"";

	int first_symb_iso = text.find(iso_offset);

	//если нет исо и скипаем
	if (first_symb_iso == -1 && ch_attrib_skip_iso)
	{
		return "no_IsoOffset_skipping";
	}

	//если нет исо и создаем новый. сразу вписываем аттрибут 
	if (first_symb_iso == -1 && !ch_attrib_skip_iso)
	{
		InsertIsoBlock(text);
		InsertIsoAttributeFirstly(text, attribute_to_change, value_to_change, action);
		return text;
	}

	//сюда заходим, когда есть блок и хоть 1 атрибут
	//если нет аттрибута, если есть аттрибут
	std::string data_id = "\"dataId\"";
	int start_data = text.find(data_id);

	std::string before_data_id(text, 0, start_data - 1);

	std::string s_attr = '"' + attribute_to_change + "\":";

	int start_attr = before_data_id.find(s_attr);

	if (start_attr == -1) //если такого аттрибута нет
	{
		std::string new_text = InsertNewIsoAttribute(before_data_id, attribute_to_change, value_to_change, action);

		//объединение
		text.erase(0, start_data - 1);
		//cout << text << endl;
		text.insert(0, new_text);
		//cout << text << endl;
		return text;
	}


	//если аттрибут есть
	int attr_length = s_attr.length();

	int length_attr_value = AttributeLength(&before_data_id[start_attr + attr_length]);//длина

	std::string attr(before_data_id, start_attr + attr_length, length_attr_value); //стринг

	double old_attr_value = string_to_double(attr); //в дабл

	double new_attr = CalculateNewAttribute(old_attr_value, action, value_to_change); //посчитать новый

	std::string new_attr_str = double_to_string(new_attr); //перевести в стринг

	//std::cout << before_data_id << endl;

	before_data_id.erase(start_attr + attr_length, length_attr_value);

	//std::cout << before_data_id << endl;

	before_data_id.insert(start_attr + attr_length, new_attr_str);

	//std::cout << before_data_id << endl;

	//std::cout << text << endl;

	text.erase(0, start_data - 1);
	text.insert(0, before_data_id);

	//std::cout << text << endl;



	return text;
}

//заменить все, кроме IsoOffset
std::string ReplaceInCHObjectText(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
{

	std::string s_attr = '"' + attribute_to_change + "\":";

	int attr_length = s_attr.length();
	int start_symb_attr;

	//std::cout << text << endl;

	std::string data_id = "\"dataId\"";
	int start_data = text.find(data_id);
	std::string starting_with_data(text, start_data, text.length()); //стринг

	start_symb_attr = starting_with_data.find(s_attr);

	if (start_symb_attr == -1)
	{
		std::string new_text = InsertNewAttribute(starting_with_data, attribute_to_change, value_to_change, action);

		//объединение
		text.erase(start_data, starting_with_data.length());
		//cout << text << endl;
		text.insert(start_data, new_text);
		//cout << text << endl;
		return text;

		//cerr << "нет аттрибута(неверный)" << endl;//не бывает?//запись в лог
	}
	else
	{


		int length_attr_value = AttributeLength(&starting_with_data[start_symb_attr + attr_length]);//длина

		std::string attr(starting_with_data, start_symb_attr + attr_length, length_attr_value); //стринг

		double old_attr_value = string_to_double(attr); //в дабл
		std::string new_attr_str;
		if (attribute_to_change == "dataId") new_attr_str = '"' + value_to_change + '"';
		else if (attribute_to_change == "m") new_attr_str = value_to_change;
		else
		{
			int new_attr = CalculateNewAttribute(old_attr_value, action, value_to_change); //посчитать новый специально в инт
			new_attr_str = to_string(new_attr); //перевести в стринг
		}

		starting_with_data.erase(start_symb_attr + attr_length, length_attr_value);

		//std::cout << text << endl;

		starting_with_data.insert(start_symb_attr + attr_length, new_attr_str);

		//объединение
		text.erase(start_data, text.length());
		text.insert(text.length(), starting_with_data);

		//std::cout << text << endl;

		return text;
	}
	//РАБОТАЕТ
}

//скорректировать аттрибут в CH_FirstGarden.xml по айди. в function кидается ReplaceInCHObjectTextIso - если заменяется IsoOffset аттрибут
//или ReplaceInCHObjectText - если другой аттрибут
std::string CH_ProcessAttributeBy(std::string id, std::string attribute_to_change, std::string value_to_change, char action, std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh)
{	
	bool done = false;
	for (auto& ch_file : CH_files)
	{
		tinyxml2::XMLDocument CH_FirstGarden_doc;
		CH_FirstGarden_doc.LoadFile(ch_file.c_str());
		tinyxml2::XMLElement* group = CH_FirstGarden_doc.FirstChildElement();


		for (tinyxml2::XMLElement* repair_extension = group->FirstChildElement(); repair_extension != NULL; repair_extension = repair_extension->NextSiblingElement())
		{
			//cout << repair_extension->Name() << endl;
			if (to_string(repair_extension->Name()) != "repair") continue;
			if (chosen_repair != "not chosen")
			{
				if (repair_extension->Attribute("id") != chosen_repair)
					continue;
			}
				for (tinyxml2::XMLElement* steps = repair_extension->FirstChildElement(); steps != NULL; steps = steps->NextSiblingElement())
				{
					//cout << steps->Name() << endl;
					if (to_string(steps->Name()) == "steps")
						for (tinyxml2::XMLElement* step = steps->FirstChildElement(); step != NULL; step = step->NextSiblingElement())
						{
							//cout << step->Name() << endl;
							if (to_string(step->Name()) != "step") continue;
								if (chosen_step != "not chosen")
								{
									if (step->Attribute("id") != chosen_step)
										continue;
								}
								for (tinyxml2::XMLElement* object = step->FirstChildElement(); object != NULL; object = object->NextSiblingElement())
								{
									//cout << object->Name() << endl;
									if (to_string(object->Name()) == "object")
									{
										if (ch_attrib_dataid) //поиск по dataId внутри текста
										{
											std::string temp = object->GetText();
											//cout << temp << endl;
											std::string copy_temp;
											int index_first = temp.find(id);
											if (index_first != -1) //если найден id
											{
												std::string text_new = ReplaceInCh(temp, attribute_to_change, value_to_change, action);
												if (text_new == "no_IsoOffset_skipping")
												{
													break;
												}

												object->SetText(text_new.c_str());
												done = true;
												//CH_FirstGarden_doc.SaveFile(path_CH_FirstGarden_save_to.c_str());

											}
										}
										else //поиск по хеш аттрибуту id типа d597fed3 
										{
											if (object->Attribute("id") == id)
											{
												std::string temp = object->GetText();
												//cout << temp << endl;

												std::string text_new = ReplaceInCh(temp, attribute_to_change, value_to_change, action);
												if (text_new == "no_IsoOffset_skipping")
												{
													break;
												}

												//cout << text_new << endl;
												object->SetText(text_new.c_str());
												done = true;
											}
										}
									}
								}
						}
				}
		}
		CH_FirstGarden_doc.SaveFile(ch_file.c_str());
	}
	if (done)
	{
		return id + " - processed";
	}
	else
		return id + " - not_found";
}

//скорректировать аттрибут в CH_FirstGarden.xml для всех объектов.в function кидается ReplaceInCHObjectTextIso - если заменяется IsoOffset аттрибут
//или ReplaceInCHObjectText - если другой аттрибут
void CH_ProcessAttributeAllObj( std::string attribute_to_change, std::string value_to_change, char action, std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh)
{
	for (auto& ch_file : CH_files)
	{

		tinyxml2::XMLDocument CH_doc;
		CH_doc.LoadFile(ch_file.c_str());
		tinyxml2::XMLElement* group = CH_doc.FirstChildElement();


		for (tinyxml2::XMLElement* repair_extension = group->FirstChildElement(); repair_extension != NULL; repair_extension = repair_extension->NextSiblingElement())
		{
			//cout << repair_extension->Name() << endl;
			if (to_string(repair_extension->Name()) != "repair") continue;
			if (chosen_repair != "not chosen")
			{
				if (repair_extension->Attribute("id") != chosen_repair)
					continue;
			}
				for (tinyxml2::XMLElement* steps = repair_extension->FirstChildElement(); steps != NULL; steps = steps->NextSiblingElement())
				{
					//cout << steps->Name() << endl;
					if (to_string(steps->Name()) != "steps") continue;
						for (tinyxml2::XMLElement* step = steps->FirstChildElement(); step != NULL; step = step->NextSiblingElement())
						{
							//cout << step->Name() << endl;
							if (to_string(step->Name()) != "step") continue;
							if (chosen_step != "not chosen")
							{
								if (step->Attribute("id") != chosen_step)
									continue;
							}
								for (tinyxml2::XMLElement* object = step->FirstChildElement(); object != NULL; object = object->NextSiblingElement())
								{
									if (to_string(object->Name()) == "object")
									{
										//cout << object->Name() << endl;

										std::string temp = object->GetText();
										//cout << temp << endl;

										std::string text_new = ReplaceInCh(temp, attribute_to_change, value_to_change, action);
										if (text_new == "no_IsoOffset_skipping")
										{
											break;
										}

										//cout << text_new << endl;
										object->SetText(text_new.c_str());

									}
								}
						}
				}
		}

		CH_doc.SaveFile(ch_file.c_str());
	}
}

std::vector<std::string> ChangeAttribute()
{	
	std::vector<std::string> result;

	if (!valid_attribute(ch_attrib))
	{
		result.push_back("invalid_attr");
		return result;
	}

	if (ch_attrib_iso)
	{	
		ReplaceInCh = ReplaceInCHObjectTextIso;
	}
	else
		ReplaceInCh = ReplaceInCHObjectText;

	if (ch_attrib_all_objects)
	{
		CH_ProcessAttributeAllObj(ch_attrib, ch_attrib_value, ch_attrib_operation, ReplaceInCh);
		result.push_back("processed");
		return result;
	}
	else
	{	
		for (auto& id : ch_attrib_ids)
		{
			result.push_back(CH_ProcessAttributeBy(id, ch_attrib, ch_attrib_value, ch_attrib_operation, ReplaceInCh));
		}
		return result;
	}

}

//void Get_ObjectLibrary_Info()
//{
//	//int count = 0;
//	std::string objItem_instanceClass_temp;
//	std::string objItem_defaultZOrder_temp;
//	std::string objItem_isIndoor_temp;
//
//	std::multimap<std::string, int> ol_items_ids;
//
//
//	tinyxml2::XMLDocument ObjectLibrary_doc;
//	ObjectLibrary_doc.LoadFile("D:/Projects/Mystery_Garden/base_mm/cluster1/ObjectLibrary.xml");
//
//	tinyxml2::XMLElement* ObjectLibrarySchemeElement = ObjectLibrary_doc.FirstChildElement();
//
//
//	for (tinyxml2::XMLElement* Objects = ObjectLibrarySchemeElement->FirstChildElement(); Objects != NULL; Objects = Objects->NextSiblingElement())
//	{
//		for (tinyxml2::XMLElement* item_node = Objects->FirstChildElement(); item_node != NULL; item_node = item_node->NextSiblingElement())
//		{
//
//
//			ol_items_ids.emplace(item_node->Attribute("id"), 1);
//
//		}
//	}
//
//	int count;
//	for (auto& it : ol_items_ids)
//	{
//		count = 0;
//		std::string s_id = it.first;
//		std::for_each(ol_items_ids.begin(), ol_items_ids.end(), [&](const auto& it2)
//		{
//			if (it2.first == s_id)
//			{
//				count++;
//			}
//		});
//		it.second = count;
//	}
//
//
//	std::ofstream ofs("D:/111.txt");
//	for (auto& it : ol_items_ids)
//	{
//		ofs << it.first << '\t' << it.second << std::endl;
//	}
//
//}
//
//void Get_GameFieldRes_Info()
//{
//
//
//	std::string static_text = "/static/";
//
//	tinyxml2::XMLDocument Gamefield_Resources_doc;
//	Gamefield_Resources_doc.LoadFile("D:/Projects/Mystery_Garden/base_mm/Gamefield_Resources.xml");
//	tinyxml2::XMLElement* resources = Gamefield_Resources_doc.FirstChildElement();
//
//	std::vector<std::tuple <std::string, std::string, int>> grs;
//	std::string path;
//	for (tinyxml2::XMLElement* Textures_group = resources->FirstChildElement(); Textures_group != NULL; Textures_group = Textures_group->NextSiblingElement())
//	{
//		if (Textures_group->Attribute("basePath") != nullptr)
//			path = Textures_group->Attribute("basePath");
//		else path = "none";
//
//		for (tinyxml2::XMLElement* sprite = Textures_group->FirstChildElement(); sprite != NULL; sprite = sprite->NextSiblingElement())
//		{
//
//			grs.push_back(make_tuple(sprite->Attribute("id"), path, 1));
//		}
//
//	}
//	int count;
//	for (auto& it : grs)
//	{
//		count = 0;
//
//		std::string s_id = std::get<0>(it);
//
//		std::for_each(grs.begin(), grs.end(), [&](const auto& it2)
//		{
//			if (get<0>(it2) == s_id)
//			{
//				count++;
//			}
//		});
//		std::get<2>(it) = count;
//	}
//
//
//	std::ofstream ofs("D:/111.txt");
//	ofs << "id" << '\t' << "path" << '\t' << "count" << std::endl;
//	for (auto& it : grs)
//	{
//		ofs << std::get<0>(it) << '\t' << std::get<1>(it) << '\t' << std::get<2>(it) << std::endl;
//	}
//
//}
/////////////////////////////////////////////////////////////////





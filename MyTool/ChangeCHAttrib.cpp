
#include "pch.h"
#include "tinyxml2.h"
#include "ChangeCHAttrib.h"
#include "Core.h"

namespace MyTool 
{
	//////////////////////��������������� ����� �������� � CH_FirstGarden.xml
	std::vector<std::string>iso_attributes = { "uL" ,"uR" ,"x" ,"y", "z" };
	std::vector<std::string>attributes = { "dataId" ,"m" ,"rand","x" ,"y","zOrder" };

	std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh;

	//���������� ����� �������
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

	//����� ���������
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

	//����� �������� IsoOffset
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

	//�������� ���������
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

	//�������� ���
	void InsertIsoBlock(std::string& text)
	{
		std::string iso_block = "\"IsoOffset\":{},";
		text.insert(1, iso_block);
		//cout << text << endl;
	}

	//������� �������� ��� ��������
	void InsertIsoAttributeFirstly(std::string& text, std::string attribute_to_change, std::string value_to_change, char action)
	{
		std::string new_attr = double_to_string(CalculateNewAttribute(0.00, action, value_to_change));
		std::string s_attr = '"' + attribute_to_change + "\":" + new_attr;

		text.insert(14, s_attr);
		//cout << text << endl;
	}

	//�������� ������������� �������� � ���� ���
	std::string InsertNewIsoAttribute(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
	{
		std::string new_attr = double_to_string(CalculateNewAttribute(0.00, action, value_to_change));

		std::string s_attr = '"' + attribute_to_change + "\":" + new_attr;
		int attr_length = s_attr.length();

		//vector<string>iso_attributes ={ "uL" ,"uR" ,"x" ,"y", "z"};

		auto it = find(iso_attributes.begin(), iso_attributes.end(), attribute_to_change);
		int dis = distance(iso_attributes.begin(), it); //����� �������� ������ ���� �� �������

		//cout << text << endl;

		//"IsoOffset":{"uL":49.0,"uR":49.0,"x":-11.25,"y":-11.25}

		int prev_start_symb_attr; 	//���������� �� ����������

		for (int i = dis - 1; i >= 0; i--)
		{
			std::string prev_attr = '"' + iso_attributes[i] + '"' + ':';
			prev_start_symb_attr = text.find(prev_attr); //���� ���������� ��������
			//cout << iso_attributes[i] << endl;

			if (prev_start_symb_attr != -1) //���� ���� ���������� ��������
			{
				int prev_attr_length = AttributeLength(&text[prev_start_symb_attr]); //����� ����������� ���������

				if (text[prev_start_symb_attr + prev_attr_length] == ',') //���� ����� ��������� �������, ������ ����� ������������ ��������� ��������, ������� �������
				{
					s_attr += ',';
					text.insert(prev_start_symb_attr + prev_attr_length + 1, s_attr);
					//cout << text << endl;
					return text;
				}
				else if (text[prev_start_symb_attr + prev_attr_length] == '}') //���� ����� ��������� ����������� ��� ������, ������ ����� ������������ ������, ������� ������� �����
				{
					s_attr = ',' + s_attr;
					text.insert(prev_start_symb_attr + prev_attr_length, s_attr);
					//cout << text << endl;
					return text;
				}
			}


		}
		//���� ������, �� �������� ������  c �������? ��, ������ ��� � ������ ����� ����������� ��������

		s_attr += ',';
		text.insert(14, s_attr);
		//cout << text << endl;
		return text;
	}

	//�������� ������������� ��������
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
		int dis = distance(attributes.begin(), it); //����� �������� ������ ���� �� �������

		//cout << text << endl;

		int prev_start_symb_attr; 	//���������� �� ����������

		for (int i = dis - 1; i >= 0; i--)
		{
			//cout << attributes[i] << endl;
			std::string prev_attr = '"' + attributes[i] + '"' + ':';
			prev_start_symb_attr = text.find(prev_attr); //���� ���������� ��������

			if (prev_start_symb_attr != -1) //���� ���� ���������� ��������
			{
				int prev_attr_length = AttributeLength(&text[prev_start_symb_attr]); //����� ����������� ���������

				if (text[prev_start_symb_attr + prev_attr_length] == ',') //���� ����� ��������� �������, ������ ����� ������������ ��������� ��������, ������� �������
				{
					s_attr += ',';
					text.insert(prev_start_symb_attr + prev_attr_length + 1, s_attr);
					//cout << text << endl;
					return text;
				}
				else if (text[prev_start_symb_attr + prev_attr_length] == '}') //���� ����� ��������� ����������� ��� ������, ������ ����� ������������ ������, ������� ������� �����
				{
					s_attr = ',' + s_attr;
					text.insert(prev_start_symb_attr + prev_attr_length, s_attr);
					//cout << text << endl;
					return text;
				}
			}
		}
		//���� ������, �� �������� ������  c �������? ��, ������ ��� � ������ ����� ����������� ��������

		s_attr += ',';
		text.insert(14, s_attr);
		//cout << text << endl;
		return text;
	}

	//�������������� ���������� IsoOffset
	std::string ReplaceInCHObjectTextIso(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
	{
		std::string iso_offset = "\"IsoOffset\"";

		int first_symb_iso = text.find(iso_offset);

		//���� ��� ��� � �������
		if (first_symb_iso == -1 && ch_attrib_skip_iso)
		{
			return "no_IsoOffset_skipping";
		}

		//���� ��� ��� � ������� �����. ����� ��������� �������� 
		if (first_symb_iso == -1 && !ch_attrib_skip_iso)
		{
			InsertIsoBlock(text);
			InsertIsoAttributeFirstly(text, attribute_to_change, value_to_change, action);
			return text;
		}

		//���� �������, ����� ���� ���� � ���� 1 �������
		//���� ��� ���������, ���� ���� ��������
		std::string data_id = "\"dataId\"";
		int start_data = text.find(data_id);

		std::string before_data_id(text, 0, start_data - 1);

		std::string s_attr = '"' + attribute_to_change + "\":";

		int start_attr = before_data_id.find(s_attr);

		if (start_attr == -1) //���� ������ ��������� ���
		{
			std::string new_text = InsertNewIsoAttribute(before_data_id, attribute_to_change, value_to_change, action);

			//�����������
			text.erase(0, start_data - 1);
			//cout << text << endl;
			text.insert(0, new_text);
			//cout << text << endl;
			return text;
		}


		//���� �������� ����
		int attr_length = s_attr.length();

		int length_attr_value = AttributeLength(&before_data_id[start_attr + attr_length]);//�����

		std::string attr(before_data_id, start_attr + attr_length, length_attr_value); //������

		double old_attr_value = string_to_double(attr); //� ����

		double new_attr = CalculateNewAttribute(old_attr_value, action, value_to_change); //��������� �����

		std::string new_attr_str = double_to_string(new_attr); //��������� � ������

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

	//�������� ���, ����� IsoOffset
	std::string ReplaceInCHObjectText(std::string text, std::string attribute_to_change, std::string value_to_change, char action)
	{

		std::string s_attr = '"' + attribute_to_change + "\":";

		int attr_length = s_attr.length();
		int start_symb_attr;

		//std::cout << text << endl;

		std::string data_id = "\"dataId\"";
		int start_data = text.find(data_id);
		std::string starting_with_data(text, start_data, text.length()); //������

		start_symb_attr = starting_with_data.find(s_attr);

		if (start_symb_attr == -1)
		{
			std::string new_text = InsertNewAttribute(starting_with_data, attribute_to_change, value_to_change, action);

			//�����������
			text.erase(start_data, starting_with_data.length());
			//cout << text << endl;
			text.insert(start_data, new_text);
			//cout << text << endl;
			return text;

			//cerr << "��� ���������(��������)" << endl;//�� ������?//������ � ���
		}
		else
		{


			int length_attr_value = AttributeLength(&starting_with_data[start_symb_attr + attr_length]);//�����

			std::string attr(starting_with_data, start_symb_attr + attr_length, length_attr_value); //������

			double old_attr_value = string_to_double(attr); //� ����
			std::string new_attr_str;
			if (attribute_to_change == "dataId") new_attr_str = '"' + value_to_change + '"';
			else if (attribute_to_change == "m") new_attr_str = value_to_change;
			else
			{
				int new_attr = CalculateNewAttribute(old_attr_value, action, value_to_change); //��������� ����� ���������� � ���
				new_attr_str = to_string(new_attr); //��������� � ������
			}

			starting_with_data.erase(start_symb_attr + attr_length, length_attr_value);

			//std::cout << text << endl;

			starting_with_data.insert(start_symb_attr + attr_length, new_attr_str);

			//�����������
			text.erase(start_data, text.length());
			text.insert(text.length(), starting_with_data);

			//std::cout << text << endl;

			return text;
		}
		//��������
	}

	//��������������� �������� � CH_FirstGarden.xml �� ����. � function �������� ReplaceInCHObjectTextIso - ���� ���������� IsoOffset ��������
	//��� ReplaceInCHObjectText - ���� ������ ��������
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
											if (ch_attrib_dataid) //����� �� dataId ������ ������
											{
												std::string temp = object->GetText();
												//cout << temp << endl;
												std::string copy_temp;
												int index_first = temp.find(id);
												if (index_first != -1) //���� ������ id
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
											else //����� �� ��� ��������� id ���� d597fed3 
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

	//��������������� �������� � CH_FirstGarden.xml ��� ���� ��������.� function �������� ReplaceInCHObjectTextIso - ���� ���������� IsoOffset ��������
	//��� ReplaceInCHObjectText - ���� ������ ��������
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
}


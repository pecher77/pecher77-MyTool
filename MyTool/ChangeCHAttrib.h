#pragma once

namespace MyTool {

	double CalculateNewAttribute(double value_attr, char action, std::string value_to_change);

	int AttributeLength(char* start);

	int AttributeLengthIso(char* start);

	double string_to_double(std::string attr);

	std::string double_to_string(double new_attr);

	bool valid_attribute(std::string attribute_to_change);

	void InsertIsoBlock(std::string& text);

	void InsertIsoAttributeFirstly(std::string& text, std::string attribute_to_change, std::string value_to_change, char action);

	std::string InsertNewIsoAttribute(std::string text, std::string attribute_to_change, std::string value_to_change, char action);

	std::string ReplaceInCHObjectTextIso(std::string text, std::string attribute_to_change, std::string value_to_change, char action);

	std::string InsertNewAttribute(std::string text, std::string attribute_to_change, std::string value_to_change, char action);

	std::string ReplaceInCHObjectText(std::string text, std::string attribute_to_change, std::string value_to_change, char action);

	std::string CH_ProcessAttributeBy(std::string id, std::string attribute_to_change, std::string value_to_change, char action, std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh);

	void CH_ProcessAttributeAllObj(std::string attribute_to_change, std::string value_to_change, char action, std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh);

	std::vector<std::string> ChangeAttribute();

}

#pragma once
#include "Optimize.h"

extern bool ch_attrib_iso;
extern bool ch_attrib_dataid;
extern bool ch_attrib_skip_iso;
extern bool ch_attrib_all_objects;

extern std::string ch_attrib;
extern std::string ch_attrib_value;
extern std::string ch_attrib_repair;
extern std::string ch_attrib_step;

extern char ch_attrib_operation;

extern std::function<std::string(std::string, std::string, std::string, char)> ReplaceInCh;

extern std::vector<std::string> ch_attrib_ids;

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

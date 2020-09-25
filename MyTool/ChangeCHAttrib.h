#pragma once

namespace MyTool {

	class IsoBox
	{
	public:
		int xOffset;
		int yOffset;

		int xMin;
		int yMin;
		int zMin;

		int xMax;
		int yMax;
		int zMax;


		IsoBox(int xOffset_, int yOffset_, int xMin_, int yMin_, int zMin_, int xMax_, int yMax_, int zMax_)
			: xOffset(xOffset_), yOffset(yOffset_),xMin(xMin_), yMin(yMin_), zMin(zMin_), xMax(xMax_), yMax(yMax_), zMax(zMax_)
		{
		}

		//IsoBox(IsoBox& other)
		//	:xMin(other.xMin), yMin(other.yMin), zMin(other.zMin), xMax(other.xMax), yMax(other.yMax), zMax(other.zMax)
		//{
		//}

		bool operator ==(const IsoBox& other)
		{
			if
				(
					this->xMin == other.xMin &&
					this->yMin == other.yMin &&
					this->zMin == other.zMin &&

					this->xMax == other.xMax &&
					this->yMax == other.yMax &&
					this->zMax == other.zMax 
					)
			{
				return true;
			}
			else return false;
		}

		bool operator ==(const IsoBox& other) const
		{
			if
				(
					this->xMin == other.xMin &&
					this->yMin == other.yMin &&
					this->zMin == other.zMin &&

					this->xMax == other.xMax &&
					this->yMax == other.yMax &&
					this->zMax == other.zMax
					)
			{
				return true;
			}
			else return false;
		}


	};

	namespace fs = boost::filesystem;

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

	void ChangeOLOffsetToCHOffset();

	fs::path GetPathByTextureIdResources(std::string id);

	std::string GetLayerIdByObjectId(std::string object_id);

	IsoBox GetOriginalIso(std::string id);

}

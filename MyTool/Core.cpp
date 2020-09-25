#include "pch.h"
#include "Core.h"

namespace MyTool {

	std::string path_LOG;
	std::ofstream ofs;

	std::string path_gamefield_resources;
	std::string path_CH_FirstGarden_save_to;
	std::string path_texture_folder;
	std::string path_game_folder = "D:/Projects/Mystery_Garden";
	std::string path_repair_path;
	std::string project_name;
	std::string path_base_mm;

	bool collected = false;

	int error_counter;
	int deleting_count;
	int process_count;

	std::list<std::string>					CH_files;
	std::list<boost::filesystem::path>		cluster_folders;
	std::vector<boost::filesystem::path>	ObjLib_files;
	std::string chosen_repair = "not chosen";
	std::string chosen_step = "not chosen";
	std::vector<std::string>			repairs;
	std::vector<std::string>			steps;

	std::vector<std::string>			ch_attrib_ids;
	bool ch_attrib_iso = true;
	bool ch_attrib_dataid = true;
	bool ch_attrib_skip_iso = false;
	bool ch_attrib_all_objects = false;
	bool ch_id_mask = false;

	bool reset_isobox = false;
	bool reset_offset = false;

	std::string ch_attrib;
	std::string ch_attrib_value;
	std::string ch_attrib_repair;
	std::string ch_attrib_step;

	char ch_attrib_operation;


	bool cancelExecution = false;
	int res_count; //счетких ресурсов

	//template<class T>
	//std::string to_string(const T& t)
	//{
	//	std::ostringstream os;
	//	os << t;
	//	return os.str();
	//}

	//очистить лог
	void Clear_LogFile()
	{
		//fs::path log_path = path_LOG;
		//fs::remove(log_path);
		ofs.open(path_LOG, std::ios::out | std::fstream::trunc);
		ofs.close();
		LOG_IN_FILE("start");
	}

}
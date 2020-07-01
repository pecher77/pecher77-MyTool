#pragma once


#define BOOST_FILESYSTEM_NO_DEPRECATED
#define _CRT_SECURE_NO_WARNINGS



#define DDDEBAG


#define DEBUG_FILE
#ifdef DEBUG_FILE
#define LOG_IN_FILE(x) ofs.open(path_LOG,std::ios::app); ofs<<std::left<<x<<std::endl; ofs.close()
#else
#define LOG_IN_FILE(x)
#endif

#define DEBUG_CONSOLE
#ifdef DEBUG_CONSOLE
#define LOG(x) std::cout<<x<<std::endl
#else
#define LOG(x)
#endif

#define MRSHL_stdstr_TO_Str(str) msclr::interop::marshal_as<String^>(str)
#define MRSHL_Str_TO_stdstr(Str) msclr::interop::marshal_as<std::string>(Str)

#define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            (_wassert(_CRT_WIDE(message), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0); \
        } \
    } while (false)

#define ASSERT2(expression, message) (void)(                                                       \
            (!!(expression)) ||                                                              \
            (_wassert(_CRT_WIDE(#expression + message), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )


namespace MyTool {


	extern std::string path_LOG;
	extern std::ofstream ofs;

	extern std::string path_gamefield_resources;
	extern std::string path_CH_FirstGarden_save_to;
	extern std::string path_texture_folder;
	extern std::string path_game_folder;
	extern std::string path_repair_path;
	extern std::string project_name;
	extern std::string path_base_mm;

	extern bool collected;

	extern int error_counter;
	extern int deleting_count;
	extern int process_count;

	extern std::list<std::string>					CH_files;
	extern std::list<boost::filesystem::path>		cluster_folders;
	extern std::vector<boost::filesystem::path>		ObjLib_files;
	extern std::string chosen_repair;
	extern std::string chosen_step;
	extern std::vector<std::string> repairs;
	extern std::vector<std::string> steps;

	extern std::vector<std::string>			ch_attrib_ids;
	extern bool ch_attrib_iso;
	extern bool ch_attrib_dataid;
	extern bool ch_attrib_skip_iso;
	extern bool ch_attrib_all_objects;

	extern std::string ch_attrib;
	extern std::string ch_attrib_value;
	extern std::string ch_attrib_repair;
	extern std::string ch_attrib_step;

	extern char ch_attrib_operation;


	extern bool cancelExecution;

	extern int res_count;

	template<class T>
	std::string to_string(const T& t)
	{
		std::ostringstream os;
		os << t;
		return os.str();
	}
	//очистить лог
	void Clear_LogFile();

}
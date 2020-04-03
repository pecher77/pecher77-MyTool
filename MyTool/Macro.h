#pragma once

#define BOOST_FILESYSTEM_NO_DEPRECATED
#define _CRT_SECURE_NO_WARNINGS

//#define LOG_FILE path_LOG


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


extern std::string path_LOG;
extern std::ofstream ofs;

extern std::string path_gamefield_resources;
extern std::string path_CH_FirstGarden_save_to;
extern std::string path_texture_folder;
extern std::string path_game_folder;
extern std::string path_repair_path;
extern std::string project_name;
extern std::string path_base_mm;

extern int error_counter;
extern int deleting_count;
extern int process_count;
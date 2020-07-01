#include "Log.h"


namespace MyTool {

	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{

		//spdlog::set_pattern()
		s_Logger = spdlog::ass("MyTool_App");
		s_Logger->set_level(spdlog::level::trace);

	}
}

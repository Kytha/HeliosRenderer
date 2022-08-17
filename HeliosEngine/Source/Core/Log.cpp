#include "hlpch.h"

#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core/Log.h"

namespace Helios
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%l]: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("PLUTUS");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}
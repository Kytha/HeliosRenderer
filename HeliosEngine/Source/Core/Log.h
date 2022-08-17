#pragma once

#include "Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <stdarg.h>

namespace Helios {
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}

#define HL_TRACE(...)    ::Helios::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HL_DEBUG(...)     ::Helios::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define HL_INFO(...)     ::Helios::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HL_WARN(...)     ::Helios::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HL_ERROR(...)    ::Helios::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HL_CRITICAL(...)    ::Helios::Log::GetCoreLogger()->critical(__VA_ARGS__)


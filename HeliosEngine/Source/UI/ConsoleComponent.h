#pragma once
#include "Core/Log.h"
#include "imgui.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/base_sink.h"
#include "spdlog/details/null_mutex.h"
#include <mutex>

namespace Helios {

    class ConsoleComponent : public spdlog::sinks::base_sink<spdlog::details::null_mutex>
    {
        public:
            ConsoleComponent();

            ~ConsoleComponent();

            void AddLog(const char* fmt,int level, ...) IM_FMTARGS(2);

            void ClearLog();

            void OnRender();
            
        protected:
            void sink_it_(const spdlog::details::log_msg& msg) override;

            void flush_() override ;
        private:

            struct Item
            {
                char* text;
                int level;
            };

            char                  InputBuf[256];
            ImVector<Item>       Items;
            ImVector<const char*> Commands;
            ImVector<char*>       History;
            int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
            ImGuiTextFilter       Filter;
            bool                  AutoScroll;
            bool                  ScrollToBottom;

                // Portable helpers
            static int   Stricmp(const char* s1, const char* s2)         { int d; while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; } return d; }
            static int   Strnicmp(const char* s1, const char* s2, int n) { int d = 0; while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; n--; } return d; }
            static char* Strdup(const char* s)                           { IM_ASSERT(s); size_t len = strlen(s) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)s, len); }
            static void  Strtrim(char* s)                                { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }

    };
}


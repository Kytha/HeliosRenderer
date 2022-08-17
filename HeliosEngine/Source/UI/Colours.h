#pragma once
#include <imgui.h>

#define RGB_UINT8_TO_FLOAT(r,g,b) (r / 255.0f), (g / 255.0f), (b / 255.0f), 1.0f

namespace Colours
{	
	static ImVec4 warn      = ImVec4(RGB_UINT8_TO_FLOAT(0xe1, 0xaa, 0x76));
	static ImVec4 error     = ImVec4(RGB_UINT8_TO_FLOAT(0xee, 0x7a, 0x83));
	static ImVec4 info      = ImVec4(RGB_UINT8_TO_FLOAT(0x71, 0xbf, 0xff));
	static ImVec4 debug     = ImVec4(RGB_UINT8_TO_FLOAT(0xd0, 0xc0, 0xb0));
	static ImVec4 critical  = ImVec4(RGB_UINT8_TO_FLOAT(0xfe, 0x6a, 0x73));
	static ImVec4 text      = ImVec4(RGB_UINT8_TO_FLOAT(0xd0, 0xd0, 0xd0));
	static ImVec4 trace     = ImVec4(RGB_UINT8_TO_FLOAT(0xa8, 0xd3, 0x89));
}
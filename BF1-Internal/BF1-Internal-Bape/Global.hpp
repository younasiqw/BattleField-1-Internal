/* 
* Global.hpp : Contains the global varible class 
*/

#ifndef _GLOBAL_HPP
#define _GLOBAL_HPP

/* Includes for this header */
#include <Windows.h>
#include "Vendors/ImGui/imgui.h"

class Global
{
public:
	bool is_menu_open = true;
	ImColor c_cross_hair = ImColor(1.0f, 0.0f, 0.0f);
};

extern Global* global;

#endif // _GLOBAL_HPP

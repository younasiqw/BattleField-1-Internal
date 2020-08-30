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
	/* General */
	bool is_menu_open = true;
	
	/* Aim */

	/* Visuals */
	bool visuals = false;
	bool visuals_box = false;
	bool visuals_enemy_only = true;
	bool visuals_skeleton = false;
	bool visuals_headcircle = false;
	bool visuals_info = false;

	/* Misc. */
	bool misc_crosshair = true;

	/* Colors */
	ImColor c_cross_hair = ImColor(1.0f, 1.0f, 1.0f);
};

extern Global* global;

#endif // _GLOBAL_HPP

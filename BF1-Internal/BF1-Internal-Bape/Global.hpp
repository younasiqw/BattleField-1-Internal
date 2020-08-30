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
	bool cursor_unlocked = true;
	
	/* Aim */
	bool aim_enabled = false;
	int aim_key = 0x06;

	/* Visuals */
	bool visuals = false;
	bool visuals_box = false;
	bool visuals_enemy_only = true;
	bool visuals_skeleton = false;
	bool visuals_headcircle = false;
	bool visuals_info = false;
	bool visuals_healthbar = false;

	/* Misc. */
	bool misc_crosshair = true;

	/* Colors */
	ImColor c_cross_hair = ImColor(1.0f, 1.0f, 1.0f);
	ImColor c_visuals_skeleton = ImColor(1.0f, 1.0f, 1.0f);
	ImColor c_visuals_headcircle = ImColor(1.0f, 1.0f, 1.0f);
	ImColor c_visuals_info = ImColor(1.0f, 1.0f, 1.0f);
		/* team */
		ImColor c_t_visuals_box = ImColor(1.0f, 1.0f, 1.0f);
		/* enemy */
		ImColor c_e_visuals_box = ImColor(1.0f, 1.0f, 1.0f);
		ImColor c_e_visuals_box_visible = ImColor(1.0f, 1.0f, 1.0f);
};

extern Global* global;

#endif // _GLOBAL_HPP

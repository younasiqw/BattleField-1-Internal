#pragma once 

#include <nlohmann/json.hpp>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <ImGui/imgui.h>
#include "../Global.hpp"

using json = nlohmann::json;

#define GET_VARIABLE_NAME(Variable) (#Variable)

/*
Usage: configuration system, saves all globals into a json file
*/

class Config {
private:
	char path[128];
	std::fstream file;
	json JSON;

	/*
	 Define all variables inside the globals class, since we dont know the names @ runtime.
	*/
	std::vector<bool> vars = {
		/* Aim */
		global->aim_enabled,

		/* Visuals */
		global->visuals,
		global->visuals_box,
		global->visuals_enemy_only,
		global->visuals_skeleton,
		global->visuals_headcircle,
		global->visuals_info,
		global->visuals_healthbar,

		/* Misc. */
		global->misc_crosshair,
	};
	std::vector<ImColor> colors = {
			 global->c_cross_hair,
			 global->c_visuals_skeleton,
			 global->c_visuals_headcircle,
			 global->c_visuals_info,
			 /* team */
			 global->c_t_visuals_box,
			 /* enemy */
			 global->c_e_visuals_box,
			 global->c_e_visuals_box_visible,
	};
public:
	/* constructor */
	Config() {
		/* get env variable and append it with bape.json */
		auto appdataPath = getenv("appdata");
		sprintf(path, "%s%s", appdataPath, "\\bape.json");
	}

	/* read/write config */
	void read();
	void write();
};
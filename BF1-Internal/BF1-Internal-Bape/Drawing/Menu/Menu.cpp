/*
* Menu.cpp : Contains the implementation for the menu drawing function 
*/

/* Includes for this file */
#include "Menu.hpp"
#include "../../Vendors/ImGui/imgui.h"
#include "../../Global.hpp"

namespace Menu
{
	void Draw()
	{
		/* Begin this imgui instance */
		ImGui::Begin("BF1 Internal", &global->is_menu_open);

		/* Debugging to test shit works */
		{
			ImGui::Text("Howdy Nigger");
			ImGui::Button("Beep Boop");
		}

		/* End this imgui */
		ImGui::End();
	}
}
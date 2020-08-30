/*
* Menu.cpp : Contains the implementation for the menu drawing function 
*/

/* Includes for this file */
#include "Menu.hpp"
#include "../../Vendors/ImGui/imgui.h"
#include "../../Global.hpp"
#include "../../Config/Config.hpp"
#include <thread>

namespace Menu
{
	int m_CurrentTab = 1;

	void ApplyStyle() {
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style->WindowPadding = ImVec2(6.f, 0);
		style->WindowRounding = 0.0f;
		style->FramePadding = ImVec2(8, 5);
		style->FrameRounding = 0.0f; // item rounding
		style->ItemSpacing = ImVec2(12, 8);
		style->ItemInnerSpacing = ImVec2(5, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 15.0f;
		style->ScrollbarRounding = 9.0f;
		style->GrabMinSize = 5.0f;
		style->GrabRounding = 3.0f;

		style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
		style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_Border] = ImVec4(0.40f, 0.40f, 0.43f, 0.88f);
		style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
		style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
	}

	void Draw()
	{
		/* Return if menu shouldn't be open */
		if (!global->is_menu_open) return;

		/* Apply style */
		ApplyStyle();

		/* Begin this imgui instance */
		ImGui::Begin("Bape BF1 Internal", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

		/* Set size and pos */
		float menux = 529.f; float menuy = 200.f;
		ImGui::SetWindowSize(ImVec2(menux, menuy), ImGuiCond_Once);
		ImGui::SetWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x / 2) - (menux / 2), (ImGui::GetIO().DisplaySize.y / 2) - (menuy / 2)), ImGuiCond_Once);

		{
			ImGui::Separator();

			/* "Tab" buttons */
			if (ImGui::Button("Aim", ImVec2(126, 25))) m_CurrentTab = 1; 
			ImGui::SameLine(0.0, 4.0f);
			if (ImGui::Button("Visuals", ImVec2(126, 25))) m_CurrentTab = 2;
			ImGui::SameLine(0.0, 4.0f);
			if (ImGui::Button("Misc.", ImVec2(126, 25))) m_CurrentTab = 3;
			ImGui::SameLine(0.0, 4.0f);
			if (ImGui::Button("Colors", ImVec2(126, 25))) m_CurrentTab = 4;

			ImGui::Separator();

			//Config config;

			switch (m_CurrentTab) {
			case 1: /* aimbot */
				ImGui::Checkbox("Aimbot (M5)", &global->aim_enabled);
				ImGui::SameLine();
				ImGui::Text(" (Disable raw input)");
				break;
			case 2: /* visuals */
				ImGui::Checkbox("Visuals ", &global->visuals);
				ImGui::Checkbox("Boxes ", &global->visuals_box);
				ImGui::Checkbox("Head circle ", &global->visuals_headcircle);
				ImGui::Checkbox("Player info ", &global->visuals_info);
				ImGui::Checkbox("Enemy only ", &global->visuals_enemy_only);
				ImGui::Checkbox("Skeleton ", &global->visuals_skeleton);
				ImGui::Checkbox("Health bar", &global->visuals_healthbar);
				break;
			case 3: /* misc */
				ImGui::Checkbox("Crosshair", &global->misc_crosshair);
				//if (ImGui::Button("Save config")) config.write();/*std::thread configThread(&Config::write, Config())*/
				break;
			case 4: /* colors */
				ImGui::ColorEdit4("Crosshair ", (float*)&global->c_cross_hair, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoTooltip);
				ImGui::ColorEdit4("Boxes team ", (float*)&global->c_t_visuals_box, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoTooltip);
				ImGui::ColorEdit4("Boxes enemy ", (float*)&global->c_e_visuals_box, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoTooltip);
				ImGui::ColorEdit4("Boxes visible ", (float*)&global->c_e_visuals_box_visible, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoTooltip);
				ImGui::ColorEdit4("Skeleton ", (float*)&global->c_visuals_skeleton, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoTooltip);
				break;
				
			default: break;
			}
		}

		/* End this imgui */
		ImGui::End();
	}
}
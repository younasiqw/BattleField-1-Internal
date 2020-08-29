/*
* Menu.cpp : Contains the implementation for the menu drawing function 
*/

/* Includes for this file */
#include "Menu.hpp"
#include "../../Vendors/ImGui/imgui.h"
#include "../../Global.hpp"

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

		/* Show the cursor, this doesnt lock game mouse input but its better than nothing */
		ShowCursor(true);

		/* Apply style */
		ApplyStyle();

		/* Begin this imgui instance */
		ImGui::Begin("Bape BF1 Internal", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

		/* Set size and pos */
		float menux = 400.f; float menuy = 200.f;
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

			ImGui::Separator();

			if (m_CurrentTab == 1)
			{
				
			}
			if (m_CurrentTab == 2)
			{
				ImGui::Checkbox("Player ESP", &global->visuals_playeresp);
			}
			if (m_CurrentTab == 3)
			{
				ImGui::Checkbox("Crosshair", &global->misc_crosshair);
			}
		}

		/* End this imgui */
		ImGui::End();
	}
}
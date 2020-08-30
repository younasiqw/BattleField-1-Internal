/*
* Aimbot.cpp : Contains the implementation for the aimbot function
*/

/* Includes for this file */
#include "Aimbot.hpp"
#include "../Global.hpp"
#include "../Vendors/ImGui/imgui.h"
#include "../Vendors/ImGui/imgui_internal.h"
#include "../SDK/sdk.hpp"
#include "../SDK/FrostBite.hpp"
#include "../Utility/Logging/Logging.hpp"
#include <vector>

namespace Aimbot
{
	void Aim()
	{
		for (;;) {
			if (!global->aim_enabled) continue;

			while (GetAsyncKeyState(global->aim_key))
			{
				/* Attempt to get the local player instance */
				ClientPlayer* local_player = GetLocalPlayer();

				/* Check that local player is valid */
				if (!IsValidPtr(local_player)) continue;

				/* Get localplayers soldier */
				ClientSoldierEntity* local_soldier = local_player->clientSoldierEntity;

				/* Check that Client soldier is valid */
				if (!IsValidPtr(local_soldier)) continue;

				/* Create vector of "aimbottable" players */
				std::vector<ClientSoldierEntity*> targets;

				/* Walk the entirety of the player list */
				for (int i = 0; i < 64; i++)
				{
					/* Get this iterations player */
					ClientPlayer* player = GetPlayerById(i);

					/* Check that the player is valid */
					if (!IsValidPtr(player)) continue;

					/* Check that the player isn't the localplayer */
					if (local_player->getId() == player->getId()) continue;
					/* Check that the players team isnt the same as the localplayers team */
					if (player->teamId == local_player->teamId) continue;

					/* Get this iterations soldier */
					ClientSoldierEntity* soldier = player->clientSoldierEntity;

					/* Check that Client soldier is valid */
					if (!IsValidPtr(soldier)) continue;
					/* Check that this player is valid */
					if (soldier->IsDead()) continue;
					/* Check that the player is visible */
					if (soldier->IsVisible()) continue;

					/* Add to targets vector */
					targets.push_back(soldier);
				}

				/* Vec2 of screen center */
				Vec2 center = Vec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);
				/* Create vars to keep track of current target and target info */
				float closestdist = 999.f;
				ClientSoldierEntity* closest = targets[0];
				/* Find the closest player to the center of our screen */
				for (int i = 0; i < targets.size(); i++) {
					/* Set clientsoldierentity to current "target" */
					ClientSoldierEntity* soldier = targets[i];
					/* World to screen the players head positon */
					Vec2 head_screen; if (!W2S(soldier->location + Vec3(soldier->GetAABB().max.x, soldier->GetAABB().max.y, soldier->GetAABB().max.z), head_screen)) continue;
					float distancefromcenter = sqrt(pow(center.x - head_screen.x, 2) + pow(center.y - head_screen.y, 2));
					if (distancefromcenter < closestdist) {
						closest = targets[i];
						closestdist = distancefromcenter;
					}
				}

				if (closest) {
					/* Redo checks incase somehow in the time it takes to get here something changes */

					/* Check that soldier is valid */
					if (!IsValidPtr(closest)) continue;
					/* Check that this player is valid */
					if (closest->IsDead()) continue;
					/* Check that the player is visible */
					if (closest->IsVisible()) continue;
					/* Check if player isnt occluded */
					if (!closest->occluded) continue;

					/* Do another head W2S, calculate differences, and move mouse */
					Vec2 head_screen; if (!W2S(closest->location + Vec3(closest->GetAABB().max.x, closest->GetAABB().max.y, closest->GetAABB().max.z), head_screen)) continue;
					DWORD movex = center.x - head_screen.x;
					DWORD movey = center.y - head_screen.y;
					//std::string debug = "{ X: " + std::to_string(center.x) + " - " + std::to_string(head_screen.x) + ", Y: " + std::to_string(center.y) + " - " + std::to_string(head_screen.y) + " }";
					//std::string debug = "{ X: " + std::to_string((int)movex) + ", Y: " + std::to_string((int)movey) + " }";
					//Log::Debug(debug);
					//if ((int)movex != 0)
						//movex < 0 ? movex = -1 : movex = 1;
					//if ((int)movey != 0)
						//movey < 0 ? movey = -1 : movey = 1;
					SetCursorPos(head_screen.x, head_screen.y);
				}
			}
			Sleep(2);
		}
		Sleep(1); // Hot thread no no!
	}
}
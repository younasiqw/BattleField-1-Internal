/*
* dllmain.cpp : Defines the entry point for this binary and the main thread
*/

/* Includes for this file */
#include <windows.h>
#include <vector>
#include <functional>

#include "Utility/Console/Console.hpp"
#include "Utility/Logging/Logging.hpp"
#include "Hooks/DirectX 11 Hook/DXHook.hpp"
#include "Drawing/Menu/Menu.hpp"
#include "Global.hpp"

/*
* Main thread for this binary, bootstrapped off the API entry point
*/
inline void Main(HMODULE hModule)
{

	/* Allocate a console window to the target process */
	Console::Allocate("Debug Console");
	
	/* Log the creation of the console window */
	Log::Success("Console Allocated");

	/* Initialize the present hook */
	{
		/* Populate this with drawing tasks */
		std::vector<std::function<void()>> task_list = {Menu::Draw};

		/* Init the present hook */
		dx_hook->Init(task_list);
	}

	/* Initiate an infinite loop */
	while (true)
	{
		/* Exit thread if insert is press */
		if (GetAsyncKeyState(VK_DELETE) & 0x8000) break;

		/* Toggle menu status */
		if (GetAsyncKeyState(VK_F9) & 0x8000)
		{
			global->is_menu_open = !global->is_menu_open;

			/* Prevent spam */
			SleepEx(35, true);
		}

		/* Prevent hot looping */
		SleepEx(1, true);
	}

	/* Log that the main threading has been exited */
	Log::Warn("Main thread has been exited. [Deallocating console][Freeing library]");

	/* Remove the present hook */
	dx_hook->Remove();

	/* Deallocate the console window from the target process */
	Console::DeAllocate();

	/* Exit thread and close handle */
	FreeLibraryAndExitThread(hModule, 0);
}

/*
* Entrypoint for the Dynamic link library.
* Will boot strap the main thread
*/
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr));
	}
	else
	{
		/* DLL_PROCESS_DETACH handler here */
	}

	return TRUE;
}

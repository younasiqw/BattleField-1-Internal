#include "Console.hpp"

namespace Console
{
	/*
	* Implementation for the allocate console
	*/
	bool Allocate(LPCSTR name)
	{
		/* Allocate a console window to the target process */
		AllocConsole();

		/* Update console window name */
		SetConsoleTitle(name);

		/* Set the stdout to our allocated console window */
		freopen("CONOUT$", "w", stdout);

		/* Set the stdin to our allocated console window */
		freopen("CONIN$", "r", stdin);

		/* Return everything went well */
		return true;
	}

	/*
	* Implementation console window
	*/
	bool DeAllocate()
	{
		/* Free the console from the target process */
		return FreeConsole();
	}

	/*
	* Implementation for hiding the console window
	*/
	void Hide()
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}

	/*
	* Implementation for showing the console window
	*/
	void Show()
	{
		ShowWindow(GetConsoleWindow(), SW_RESTORE);
	}
}
#ifndef _CONSOLE_HPP
#define _CONSOLE_HPP

/* Includes for this header */
#include <Windows.h>
#include <string>

namespace Console
{
	/*
	* Implementation for the allocate console
	*/
	bool Allocate(LPCSTR name);

	/*
	* Implementation console window
	*/
	bool DeAllocate();

	/*
	* Implementation for hiding the console window
	*/
	void Hide();

	/*
	* Implementation for showing the console window
	*/
	void Show();
}

#endif // _CONSOLE_HPP

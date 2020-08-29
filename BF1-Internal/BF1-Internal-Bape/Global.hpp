/* 
* Global.hpp : Contains the global varible class 
*/

#ifndef _GLOBAL_HPP
#define _GLOBAL_HPP

/* Includes for this header */
#include <Windows.h>

class Global
{
public:
	bool is_menu_open = true;
};

extern Global* global;

#endif // _GLOBAL_HPP

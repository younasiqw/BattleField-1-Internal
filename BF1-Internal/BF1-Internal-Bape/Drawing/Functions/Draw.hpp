/*
* Draw.hpp : Defines the external linkage for the Wrapped ImGui Drawing functions 
*/

#ifndef _DRAW_HPP
#define _DRAW_HPP

/* Includes for this header */
#include <Windows.h>
#include <string>
#include "../../Vendors/ImGui/imgui.h"

/* Flags containing different drawing styles that can be specified */
enum DrawFlags
{
	SOLID = 1 << 0,
	OUTLINE = 1 << 1,
	CENTERED = 1 << 2,
	BOUNDS = 1 << 3,
	NONE = 1 << 4
};
DEFINE_ENUM_FLAG_OPERATORS(DrawFlags);

class Draw
{
public:
	void Rectangle(ImVec2 pt, ImVec2 pb, ImColor col, int thickness, float rounding, ImDrawCornerFlags corner_flags, DrawFlags flags);
	void Circle(ImVec2 pos, ImColor col, int radius, int thickness, int segments, DrawFlags flags);
	void Line(ImVec2 pt, ImVec2 pb, ImColor col, int thickness, DrawFlags flags);
	void Text(ImVec2 pos, ImColor col, std::string str, DrawFlags flags);
	void XCrossHair(ImColor col);
};

extern Draw* draw;

#endif // _DRAW_HPP

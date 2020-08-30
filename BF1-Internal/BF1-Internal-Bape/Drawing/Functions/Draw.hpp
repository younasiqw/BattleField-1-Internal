/*
* Draw.hpp : Defines the external linkage for the Wrapped ImGui Drawing functions 
*/

#ifndef _DRAW_HPP
#define _DRAW_HPP

/* Includes for this header */
#include <Windows.h>
#include <string>
#include "../../Vendors/ImGui/imgui.h"
#include "../../Math/Vec3.hpp"
#include "../../SDK/sdk.hpp"

#define M_PI 3.14159265358979323846264338327950288

/* Flags containing different drawing styles that can be specified */
enum DrawFlags
{
	SOLID = 1 << 0,
	OUTLINE = 1 << 1,
	CENTERED = 1 << 2,
	BOUNDS = 1 << 3,
	NONE = 1 << 4,
	FILLED = 1 << 5
};
DEFINE_ENUM_FLAG_OPERATORS(DrawFlags);

class Draw
{
public:
	void Rectangle(ImVec2 pt, ImVec2 pb, ImColor col, int thickness, float rounding, ImDrawCornerFlags corner_flags, DrawFlags flags);
	void CornerRectangle(ImVec2 pt, ImVec2 pb, ImColor col, float length, int thickness, ImDrawCornerFlags corner_flags, DrawFlags flags);
	void CircleFilled(ImVec2 pos, ImColor col, int radius, int thickness, int segments, DrawFlags flags);
	void Circle(ImVec2 pos, float points, float radius, ImColor color);
	void Line(ImVec2 pt, ImVec2 pb, ImColor col, int thickness, DrawFlags flags);
	void Text(ImVec2 pos, ImColor col, std::string str, DrawFlags flags);
	void XCrossHair(ImColor col);
	void Rectangle3D(Vec3 location, ImColor col);
	void HealthBar(ImVec2 pos, int h, float health, float mHealth);
};

extern Draw* draw;

#endif // _DRAW_HPP

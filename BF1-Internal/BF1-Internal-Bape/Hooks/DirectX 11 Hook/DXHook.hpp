/*
* DXHook.hpp defines the directX hooking class 
*/

#ifndef _DXHOOK_HPP
#define _DXHOOK_HPP

/* Includes for this file */
#include <Windows.h>
#include <d3d11.h>
#include <vector>
#include <functional>


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

/* TypeDefs for the hooked functions */
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

/*
* DirectX hooking class with all the needed functions
*/
class DXHook
{
public: /* Public methods for this class */
	void Remove();
	bool Init(std::vector<std::function<void()>> tasks);
	void InitImGui();

public: /* Public varibles for this class */
	std::vector<std::function<void()>> tasks;
	Present o_present;
	HWND window = NULL;
	WNDPROC o_wndproc;
	ID3D11Device* p_device = NULL;
	ID3D11DeviceContext* p_context = NULL;
	ID3D11RenderTargetView* main_render_target_view;
	bool initialized = false;
};

extern DXHook* dx_hook;

#endif // _DXHOOK_HPP

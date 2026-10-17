#include <windows.h>
void ErasePE(HMODULE hMod) { DWORD old; VirtualProtect(hMod, 4096, PAGE_READWRITE, &old); ZeroMemory(hMod, 4096); VirtualProtect(hMod, 4096, old, &old); }
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) { if (ul_reason_for_call == DLL_PROCESS_ATTACH) { DisableThreadLibraryCalls(hModule); ErasePE(hModule); } return TRUE; }

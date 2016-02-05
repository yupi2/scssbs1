#include <Windows.h>
//#include <iostream>
#include "tier1/interface.h"
#include "cdll_client_int.h"
#include "cdll_client_int.cpp"

#define util_assert(x) if (!(x)) ExitProcess(1);

typedef void * (* CreateInterfaceFn)(const char * pName, int * pReturnCode);

DWORD WINAPI BHOPThreadProc(
	LPVOID pParameter)
{
	(void)pParameter;

	HMODULE clientModule;
	HMODULE engineModule;
	CreateInterfaceFn clientCreateInterface;
	CreateInterfaceFn engineCreateInterface;

	util_assert((clientModule = GetModuleHandleW(L"client.dll")));
	util_assert((engineModule = GetModuleHandleW(L"engine.dll")));

	util_assert((clientCreateInterface = reinterpret_cast<CreateInterfaceFn>(
		GetProcAddress(clientModule, "CreateInterface"))));
	util_assert((engineCreateInterface = reinterpret_cast<CreateInterfaceFn>(
		GetProcAddress(engineModule, "CreateInterface"))));

	auto gHLClient = static_cast<CHLClient *>(
		clientCreateInterface("VClient017", NULL)
	);

	//"VClient017"

	//FrameStageNotify

	// TODO: grab the LocalPlayer class.


	return 0;
}

BOOL setup_bhop()
{
	HANDLE hThread = CreateThread(NULL, 0, BHOPThreadProc,
		NULL, CREATE_SUSPENDED, NULL);

	if (hThread == NULL)
		return FALSE;

	DWORD ret = ResumeThread(hThread);
	(void)CloseHandle(hThread);
	return ret != static_cast<DWORD>(-1);
}

// For more info see link below:
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms682583%28v=vs.85%29.aspx
BOOL WINAPI DllMain(
	HINSTANCE hDLL,
	DWORD     nReason,
	LPVOID    pReserved)
{
	(void)hDLL;
	(void)pReserved;

	switch (nReason)
	{
		case DLL_PROCESS_DETACH:
			// do something
			break;
		case DLL_PROCESS_ATTACH:
			//(void)DisableThreadLibraryCalls(hDLL);
			return setup_bhop();
	}

	return TRUE;
}

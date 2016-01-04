#include <Windows.h>
#include "hack.hpp"
#include "log.hpp"
#include "util.hpp"

using namespace scssbs;

CreateInterfaceFn hack::clientCreateInterface;
CreateInterfaceFn hack::engineCreateInterface;

BYTE * hack::clientBase;
BYTE * hack::engineBase;

DWORD WINAPI BHOPThreadProc(
	LPVOID pParameter)
{
	(void)pParameter;

	util_assert((hack::clientBase =
		reinterpret_cast<BYTE *>(util::get_module_base(L"client.dll"))));
	util_assert((hack::engineBase =
		reinterpret_cast<BYTE *>(util::get_module_base(L"engine.dll"))));

	util_assert((hack::clientCreateInterface =
		reinterpret_cast<CreateInterfaceFn>(GetProcAddress(
		reinterpret_cast<HMODULE>(hack::clientBase), "CreateInterface"))));
	util_assert((hack::engineCreateInterface =
		reinterpret_cast<CreateInterfaceFn>(GetProcAddress(
		reinterpret_cast<HMODULE>(hack::engineBase), "CreateInterface"))));

	//"VClient017"

	// TODO: grab the LocalPlayer class.


	return 0;
}

BOOL hack::start()
{
	HANDLE hThread = CreateThread(NULL, 0, BHOPThreadProc,
		NULL, CREATE_SUSPENDED, NULL);

	if (log::setup())
		log::info(L"BHOPThreadProc handle: $h32$", hThread);

	if (hThread == NULL)
		return FALSE;

	DWORD ret = ResumeThread(hThread);
	(void)CloseHandle(hThread);
	return ret != static_cast<DWORD>(-1);
}

// bool hack::hook_connect(bool should_hook)
// {
	// ConCommand *connect = g_pCVar.FindCommand("connect");

// }

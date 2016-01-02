#include <Windows.h>
#include "hack.hpp"
#include "log.hpp"

using scssbs;

static DWORD MainThread(
	LPVOID pParameter)
{
	BYTE * clientBase;
	BYTE * engineBase;

	assert((clientBase = util::get_module_base(L"client.dll")));
	assert((engineBase = util::get_module_base(L"engine.dll")));

	return 0;
}

BOOL hack::start()
{
	HANDLE hThread = CreateThread(NULL, 0, MainThread, NULL, CREATE_SUSPENDED, NULL);
	
	if (log::setup())
		log::info(L"MainThread handle: $h32$", hThread);
	
	if (hThread == NULL)
		return FALSE;
	
	DWORD ret = ResumeThread(hThread);
	(void)CloseHandle(hThread);
	return ret != (DWORD)-1;
}

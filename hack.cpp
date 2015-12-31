#include <Windows.h>
#include "hack.hpp"
#include "log.hpp"

using scssbs;

static DWORD MainThread(
	LPVOID pParameter)
{
	return 0;
}

BOOL hack::start()
{
	HANDLE hThread = CreateThread(NULL, 0, MainThread, NULL, CREATE_SUSPENDED, NULL);
	
	if (log::setup())
		log::info(L"MainThread handle: $h32$", hThread);
	
	if (hThread)
	{
		DWORD ret = ResumeThread(hThread);
		(void)CloseHandle(hThread);
		return ret != -1;
	}
	
	return FALSE;
}

#include <Windows.h>
#include "log.hpp"
#include "bhop.hpp"
#include "util.hpp"

using scssbs;

static DWORD BHOPThread(
	LPVOID pParameter)
{
	
	return 0;
}

bool bhop::start_thread()
{
	HANDLE hThread = CreateThread(NULL, 0, BHOPThread, NULL, CREATE_SUSPENDED, NULL);

	if (log::setup())
		log::info(L"BHOPThread handle: $h32$", hThread);

	if (hThread == NULL)
		return FALSE;

	DWORD ret = ResumeThread(hThread);
	(void)CloseHandle(hThread);
	return ret != (DWORD)-1;
}

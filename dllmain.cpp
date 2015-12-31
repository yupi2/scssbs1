#include <Windows.h>
//#include <iostream>

#include "logger.hpp"
#include "scssbs.hpp"

static wchar_t const * const reason_strings[] = {
	[DLL_PROCESS_DETACH] = L"process detach",
	[DLL_PROCESS_ATTACH] = L"process attach",
	[DLL_THREAD_ATTACH]  = L"thread attach",
	[DLL_THREAD_DETACH]  = L"thread detach"
};

BOOL ProcessDetach(
	HINSTANCE hDLL,
	LPVOID    Reserved)
{
	// Reserved is NULL if FreeLibrary has been called or the DLL load failed
	// and non-NULL if the process is terminating.

	// Return value is ignored by DllMain.
	return TRUE;
}

BOOL ProcessAttach(
	HINSTANCE hDLL,
	LPVOID    Reserved)
{
	// Reserved is NULL for dynamic loads and non-NULL for static loads.
	
	return scssbs::hack.start();
}

BOOL ThreadAttach(
	HINSTANCE hDLL)
{
	// Return value is ignored by DllMain.
	return TRUE;
}

BOOL ThreadDetach(
	HINSTANCE hDLL)
{
	// Return value is ignored by DllMain.
	return TRUE;
}

BOOL WINAPI DllMain(
	HINSTANCE hDLL,
	DWORD     nReason,
	LPVOID    Reserved)
{
	BOOL bSuccess = TRUE;

	if (!scssbs::log.Setup())
		return FALSE;

	if (nReason <= DLL_THREAD_DETACH)
		scssbs::log.info(L"DllMain called - Reason: $s16$", reason_strings[nReason]);
	else // This branched probably can't be taken.
		scssbs::log.info(L"DllMain called - Reason: $i32$", nReason);

	switch (nReason)
	{
		case DLL_PROCESS_DETACH:
			bSuccess = ProcessDetach(hDLL);
			break;
		case DLL_PROCESS_ATTACH:
			bSuccess = ProcessAttach(hDLL, Reserved);
			break;
		case DLL_THREAD_ATTACH:
			bSuccess = ThreadAttach(hDLL);
			break;
		case DLL_THREAD_DETACH:
			bSuccess = ThreadDetach(hDLL);
			break;
	}

	if (!bSuccess)
	{
		// cleanup
	}

	return bSuccess;
}

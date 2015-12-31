#include <Windows.h>
//#include <iostream>

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

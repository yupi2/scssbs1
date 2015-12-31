#include <Windows.h>
#include "logger.hpp"

using scssbs;

////////////////////////////////////////////////////////////////////
// lock/mutex/whatever-it's-called here.

bool isSetup = false;

HANDLE stdin  = NULL;
HANDLE stdout = NULL;
HANDLE stderr = NULL;
////////////////////////////////////////////////////////////////////

bool handleIsValid(
	HANDLE hHandle)
{
	return hHandle != NULL && hHandle != INVALID_HANDLE_VALUE;
}

void log::cleanup()
{
	(void)FreeConsole();
}

bool log::setup()
{
	if (isSetup)
		return true;

	if (!AllocConsole())
		return false;

	stdin = GetStdHandle(STD_INPUT_HANDLE);
	if (!handleIsValid(stdin))
	{
		(void)FreeConsole();
		return false;
	}

	stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!handleIsValid(stdout))
	{
		(void)FreeConsole();
		return false;
	}

	stderr = GetStdHandle(STD_ERROR_HANDLE);
	if (!handleIsValid(stderr))
	{
		(void)FreeConsole();
		return false;
	}

	isSetup = true;
	return true;
}

void log::info(
	wchar_t const * fmt,
	...)
{
	if (!isSetup)
		return;

	return;
}

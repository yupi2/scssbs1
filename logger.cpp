#include "logger.hpp"

bool handleIsValid(
	HANDLE hHandle)
{
	return hHandle != NULL && hHandle != INVALID_HANDLE_VALUE;
}

Logger::Logger()
{
	isSetup = false;
	stdout  = NULL;
	stderr  = NULL;
	stdin   = NULL;
}

Logger::~Logger()
{
	(void)FreeConsole();
}

bool Logger::Setup()
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

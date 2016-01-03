#include <Windows.h>
#include "log.hpp"
#include <cstdarg>

using namespace scssbs;

////////////////////////////////////////////////////////////////////
// lock/mutex/whatever-it's-called here.
//lock-type lock-name = lockthing;

static bool isSetup = false;

static HANDLE stdin  = NULL;
static HANDLE stdout = NULL;
static HANDLE stderr = NULL;
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

/****
 * The printf stuff below is some code from Bjarne that I'll use
 * as reference whenever I feel like finishing the logging code.
 */

/*
void printf(
	wchar_t const * fmt)
{
	while (s && *s) {
	 	if (*s=='%' && *++s!='%')	// make sure that there wasn't meant to be more arguments
						// %% represents plain % in a format string
	         throw runtime_error("invalid format: missing arguments");
		std::cout << *s++;
	}
}

template<typename T, typename... Args>		// note the "..."
void printf(
	wchar_t const * fmt,
	T value,
	Args... args)	// note the "..."
{
	while (s && *s) {
		if (*s=='%' && *++s!='%') {	// a format specifier (ignore which one it is)
			std::cout << value;		// use first non-format argument
			return printf(++s, args...); 	// ``peel off'' first argument
		}
		std::cout << *s++;
	}
	throw std::runtime error("extra arguments provided to printf");
}
*/

void log::message(
	wchar_t const * prefix,
	wchar_t const * fmt,
	...)
{
	if (!log::setup())
		return;

	if (!prefix || !fmt)
		return;

	//va_list args;
	//va_start(args, fmt);
}

void log::error(
	wchar_t const * fmt,
	...)
{
	va_list args;
	va_start(args, fmt);
	log::message(L"[ERROR]", fmt, args);
	va_end(args);
}

void log::warning(
	wchar_t const * fmt,
	...)
{
	va_list args;
	va_start(args, fmt);
	log::message(L"[WARNING]", fmt, args);
	va_end(args);
}

void log::info(
	wchar_t const * fmt,
	...)
{
	va_list args;
	va_start(args, fmt);
	log::message(L"[INFO]", fmt, args);
	va_end(args);
}

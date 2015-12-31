#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <Windows.h>

class Logger
{
	private:
		// lock/mutex/whatever-it's-called here.
	
		bool isSetup;
		
		HANDLE stdin;
		HANDLE stdout;
		HANDLE stderr;
		
	public:
		Logger();
		~Logger();
		
		bool Setup();
		
		void info(wchar_t const * fmt, ...);
};

Logger Log;

#endif

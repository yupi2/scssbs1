#ifndef __HACK_HPP__
#define __HACK_HPP__

#include <Windows.h>

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

namespace scssbs
{
	namespace hack
	{
		BOOL start();

		extern CreateInterfaceFn clientCreateInterface;
		extern CreateInterfaceFn engineCreateInterface;

		extern BYTE * clientBase;
		extern BYTE * engineBase;
	}
}

#endif

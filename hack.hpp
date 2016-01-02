#ifndef __HACK_HPP__
#define __HACK_HPP__

#include <Windows.h>

namespace scssbs
{
	namespace hack
	{
		BOOL start();
		
		BYTE * clientBase = NULL;
		BYTE * engineBase = NULL;
	}
}

#endif

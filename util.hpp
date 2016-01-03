#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#define util_assert(x) if (!(x)) ExitProcess(1);

namespace scssbs
{
	namespace util
	{
		HMODULE get_module_base(
			wchar_t const * moduleName);
	}
}

#endif

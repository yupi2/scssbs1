#include <Windows.h>
#include "util.hpp"
#include "log.hpp"

using scssbs;

BYTE * util::get_module_base(
	wchar_t const * moduleName)
{
	HMODULE baseAddress = GetModuleHandle(moduleName);

	if (log::setup())
		log::info(L"Module address: $h32$ - \'$s16$\'", baseAddress, moduleName);

	return (BYTE *)baseAddress;
}

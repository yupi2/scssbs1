#include <Windows.h>
#include "util.hpp"
#include "log.hpp"

using namespace scssbs;

HMODULE util::get_module_base(
	wchar_t const * moduleName)
{
	HMODULE baseAddress = GetModuleHandleW(moduleName);

	if (log::setup())
		log::info(L"Module address: $h32$ - \'$s16$\'", baseAddress, moduleName);

	return baseAddress;
}

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

namespace scssbs
{
	namespace log
	{
		bool setup();

		void cleanup();

		void info(wchar_t const * fmt, ...);
	}
}

#endif

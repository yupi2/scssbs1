#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

namespace scssbs
{
	namespace log
	{
		bool setup();

		void cleanup();

		void message(wchar_t const * prefix, wchar_t const * fmt, ...);

		void error(wchar_t const * fmt, ...);

		void warning(wchar_t const * fmt, ...);

		void info(wchar_t const * fmt, ...);
	}
}

#endif

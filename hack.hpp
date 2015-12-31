#ifndef __HACK_HPP__
#define __HACK_HPP__

typedef int BOOL;

namespace scssbs
{

	class Hack
	{
		private:
			// lock/mutex/whatever-it's-called here.

		public:
			Hack();
			~Hack();

			BOOL start();
	};

	Hack hack;

}

#endif

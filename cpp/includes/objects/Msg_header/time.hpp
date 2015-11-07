#ifndef RAPP_OBJECT_TIME
#define RAPP_OBJECT_TIME
#include <string>

namespace rapp {
	namespace object {


		class Time
		{

			public:
			uint32_t sec;
			uint32_t nsec;
			Time(uint32_t sec_, uint32_t nsec_):sec(sec_),nsec(nsec_){}
		};

	}
}
#endif

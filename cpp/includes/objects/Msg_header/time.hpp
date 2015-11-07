#ifndef RAPP_OBJECT_TIME
#define RAPP_OBJECT_TIME
#include <string>

namespace rapp {
	namespace object {


		class Time
		{
			uint32_t seconds;
			uint32_t nseconds;
			
			public:
			Time(uint32_t sec, uint32_t nsec):seconds(sec),nseconds(nsec){}
		};

	}
}
#endif

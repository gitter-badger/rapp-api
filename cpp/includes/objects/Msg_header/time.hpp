#ifndef RAPP_OBJECT_TIME
#define RAPP_OBJECT_TIME
#include <string>

namespace rapp {
	namespace object {


		class Time
		{
			uint32_t sec;
			uint32_t nsec;
			
			public:
			header(uint32_t sec, uint32_t nsec):sec(sec),nsec(nsec),frame(frame){}
		};

	}
}
#endif

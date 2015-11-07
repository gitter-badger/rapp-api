#ifndef RAPP_OBJECT_HEADER
#define RAPP_OBJECT_HEADER
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

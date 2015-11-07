#ifndef RAPP_OBJECT_TIME
#define RAPP_OBJECT_TIME
#include <string>

namespace rapp {
	namespace object {


		class Time
		{

			public:
			uint32_t sec=0;
			uint32_t nsec=0;
			Time(uint32_t sec, uint32_t nsec):sec(sec),nsec(nsec){}
			Time()=default;
		};

	}
}
#endif

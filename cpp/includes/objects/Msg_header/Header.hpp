#ifndef RAPP_OBJECT_HEADER
#define RAPP_OBJECT_HEADER
#include <string>
#include "time.hpp"

namespace rapp {
	namespace object {


		class Header
		{
			int seq;
			Time t;
			std::string frame;
			public:
			header(int seq, Time t, std::string frame):seq(seq),t(t),frame(frame){}
		};

	}
}
#endif

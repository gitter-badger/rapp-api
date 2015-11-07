#ifndef RAPP_OBJECT_HEADER
#define RAPP_OBJECT_HEADER
#include <string>
#include <time>

namespace rapp {
	namespace object {


		class Header
		{
			int seq;
			time t;
			std::string frame;
			public:
			header(int seq, time t, std::string frame):s(s),t(t),frame(frame){}
		};

	}
}
#endif

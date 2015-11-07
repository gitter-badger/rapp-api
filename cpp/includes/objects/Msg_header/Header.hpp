#ifndef RAPP_OBJECT_HEADER
#define RAPP_OBJECT_HEADER
#include <string>
#include "time.hpp"

namespace rapp {
	namespace object {


		class Header
		{
			int sequance;
			Time time;
			std::string frame;
			public:

			Header(int seq, Time stamp, std::string frame_id):sequance(seq),time(stamp),frame(frame_id){}
		};

	}
}
#endif

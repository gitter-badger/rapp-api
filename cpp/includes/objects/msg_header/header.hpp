#ifndef RAPP_OBJECT_HEADER
#define RAPP_OBJECT_HEADER
#include <string>
#include "time.hpp"

namespace rapp {
	namespace object {


		class Header
		{

			public:
			int seq=0;
			Time stamp;
			std::string frame_id="/map";
			Header(int seq, Time stamp, std::string frame_id):seq(seq),stamp(stamp),frame_id(frame_id){}
			Header()=default;
		};

	}
}
#endif

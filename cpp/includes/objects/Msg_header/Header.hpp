#ifndef RAPP_OBJECT_HEADER
#define RAPP_OBJECT_HEADER
#include <string>
#include "time.hpp"

namespace rapp {
	namespace object {


		class Header
		{

			public:
			int seq;
			Time stamp;
			std::string frame_id;
			Header(int seq_, Time stamp_, std::string frame_id_):seq(seq_),stamp(stamp_),frame_id(frame_id_){}
		};

	}
}
#endif

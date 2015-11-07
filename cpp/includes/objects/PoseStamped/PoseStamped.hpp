#ifndef RAPP_OBJECT_POSESTAMPED
#define RAPP_OBJECT_POSESTAMPED

#include "../Pose/Pose.hpp"
#include "../Msg_header/Header.hpp"
namespace rapp {
	namespace object {


		class PoseStamped
		{
			Pose pose_;
			Header header_;
			public:
			PoseStamped(Pose pose, Header header):pose_(pose),header_(header){}
		};

	}
}
#endif

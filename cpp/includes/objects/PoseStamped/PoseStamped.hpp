#ifndef RAPP_OBJECT_POSESTAMPED
#define RAPP_OBJECT_POSESTAMPED

#include "../Pose/Pose.hpp"
#include "../Msg_header/Header.hpp"
namespace rapp {
	namespace object {


		class PoseStamped
		{
			public:
			Pose pose;
			Header header;
			PoseStamped(Pose pose_=pose, Header header_=header):pose(pose_),header(header_){}
			PoseStamped () = default;
		};

	}
}
#endif

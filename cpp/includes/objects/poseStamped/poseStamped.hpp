#ifndef RAPP_OBJECT_POSESTAMPED
#define RAPP_OBJECT_POSESTAMPED

#include "../pose/pose.hpp"
#include "../msg_header/header.hpp"
namespace rapp {
	namespace object {


		class PoseStamped
		{
			public:
			Pose pose;
			Header header;


			PoseStamped(Pose pose, Header header):pose(pose),header(header){}
			PoseStamped () = default;


		};

	}
}
#endif

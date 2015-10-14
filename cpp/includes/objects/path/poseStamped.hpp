#ifndef RAPP_OBJECT_POSE_STAMPED
#define RAPP_OBJECT_POSE_STAMPED
#include "pose.hpp"

namespace rapp {
	namespace object {


		class PoseStamped
		{
			Pose p;
			public:
			PoseStamped(Pose p):p(p){}
		};

	}
}
#endif

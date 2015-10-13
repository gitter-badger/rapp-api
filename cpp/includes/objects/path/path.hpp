#ifndef RAPP_OBJECT_POSE_PATH
#define RAPP_OBJECT_PATH
#include "objects/path/poseStamped.hpp"

namespace rapp {
	namespace object {


		class Path
		{
			PoseStamped p[];
			public:
			Path(PoseStamped[] p):p(p){}
		};

	}	
}
#endif


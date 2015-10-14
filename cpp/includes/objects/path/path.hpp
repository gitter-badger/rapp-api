#ifndef RAPP_OBJECT_POSE_PATH
#define RAPP_OBJECT_PATH
#include "poseStamped.hpp"
#include <vector>
namespace rapp {
	namespace object {


		class Path
		{
			PoseStamped p[];
			public:
			Path(std::vector<PoseStamped> p):p(p){}
		};

	}	
}
#endif


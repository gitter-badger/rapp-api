#ifndef RAPP_OBJECT_POSE
#define RAPP_OBJECT_POSE

#include "point.hpp"
#include "quaternion.hpp"

namespace rapp {
	namespace object {


		class Pose
		{
			Point position_;
			Quaternion orientation_;
			public:
			Pose(Point position, Quaternion orientation):position_(position),orientation_(orientation){}
		};

	}
}
#endif

#ifndef RAPP_OBJECT_POSE
#define RAPP_OBJECT_POSE

#include "point.hpp"
#include "quaternion.hpp"

namespace rapp {
	namespace object {


		class Pose
		{
			
			public:
			Point position;
			Quaternion orientation;
			Pose(Point position, Quaternion orientation):position(position),orientation(orientation){}
			Pose()=default;
		};

	}
}
#endif

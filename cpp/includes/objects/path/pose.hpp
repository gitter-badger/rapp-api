#ifndef RAPP_OBJECT_POSE
#define RAPP_OBJECT_POSE

#include "point.hpp"
#include "quaternion.hpp"

namespace rapp {
	namespace object {


		class Pose
		{
			Point p;
			Quaternion q;
			public:
			Pose(Point p, Quaternion q):p(p),q(q){}
		};

	}
}
#endif

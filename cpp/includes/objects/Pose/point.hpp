#ifndef RAPP_OBJECT_POINT
#define RAPP_OBJECT_POINT

namespace rapp {
	namespace object {


		class Point
		{

			public:
			float x=0, y=0, z=0;
			Point(float x, float y, float z):x(x),y(y),z(z)
			{}
			Point()=default;
		};

	}
}

#endif


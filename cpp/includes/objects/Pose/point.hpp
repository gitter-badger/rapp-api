#ifndef RAPP_OBJECT_POINT
#define RAPP_OBJECT_POINT

namespace rapp {
	namespace object {


		class Point
		{

			public:
			float x, y, z;
			Point(float x, float y, float z):x(x),y(y),z(z)
			{};
		};

	}
}

#endif


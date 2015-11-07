#ifndef RAPP_OBJECT_QUATERNION
#define RAPP_OBJECT_QUATERNION

namespace rapp {
	namespace object {


		class Quaternion
		{

			public:
			float x, y, z, w;
			Quaternion(float x, float y, float z, float w):x(x),y(y),z(z),w(w)
		{};
		};

	}
}


#endif

#ifndef RAPP_OBJECT_QUATERNION
#define RAPP_OBJECT_QUATERNION

namespace rapp {
	namespace object {


		class Quaternion
		{

			public:
			float x=0, y=0, z=0, w=1;
			Quaternion(float x, float y, float z, float w):x(x),y(y),z(z),w(w){}
			Quaternion()=default;
		};

	}
}


#endif

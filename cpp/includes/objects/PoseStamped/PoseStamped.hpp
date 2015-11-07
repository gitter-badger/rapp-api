#ifndef RAPP_OBJECT_POSESTAMPED
#define RAPP_OBJECT_POSESTAMPED

#include "../Pose/Pose.hpp"
#include "../Msg_header/Header.hpp"
namespace rapp {
	namespace object {


		class PoseStamped
		{
			Pose p;
			Header h;
			public:
			PoseStamped(Pose p, Header h):p(p),h(h){}
		};

	}
}
#endif

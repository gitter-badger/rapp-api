#ifndef RAPP_OBJECT_PATH
#define RAPP_OBJECT_PATH
#include "../PoseStamped/PoseStamped.hpp"
#include "../Msg_header/Header.hpp"
#include <vector>
namespace rapp {
	namespace object {


		class Path
		{
			Header h;
			std::vector<PoseStamped> p;
			public:
			Path(Header h,std::vector<PoseStamped> p):h(h),p(p){}
		};

	}	
}
#endif


#ifndef RAPP_OBJECT_PATH
#define RAPP_OBJECT_PATH
#include "../PoseStamped/PoseStamped.hpp"
#include "../Msg_header/Header.hpp"
#include <vector>
namespace rapp {
	namespace object {


		class Path
		{
			Header info;
			std::vector<PoseStamped> poses_;
			public:
			Path(Header header,std::vector<PoseStamped> poses):info(header),poses_(poses){}
		};

	}	
}
#endif


#ifndef RAPP_OBJECT_PATH
#define RAPP_OBJECT_PATH
#include "../PoseStamped/PoseStamped.hpp"
#include "../Msg_header/Header.hpp"
#include <vector>
namespace rapp {
	namespace object {


		class Path
		{

			public:
			Header header;
			std::vector<PoseStamped> poses;
			Path(Header header_,std::vector<PoseStamped> poses_):header(header_),poses(poses_){}
		};

	}	
}
#endif


#ifndef RAPP_OBJECT_PATH
#define RAPP_OBJECT_PATH
#include "../PoseStamped/PoseStamped.hpp"
#include "../Msg_header/Header.hpp"
#include <vector>
namespace rapp {
	namespace object {


		class Path
		{
			std::vector<PoseStamped> p;
			public:
			Header header;
			Path(Header header,std::vector<PoseStamped> p):header(header),p(p){}
		};

	}	
}
#endif


#ifndef RAPP_OBJECT_PATH
#define RAPP_OBJECT_PATH
#include "../PoseStamped/PoseStamped.hpp"
#include <vector>
namespace rapp {
	namespace object {


		class Path
		{
			std::vector<PoseStamped> p;
			public:
			Path(std::vector<PoseStamped> p):p(p){}
		};

	}	
}
#endif


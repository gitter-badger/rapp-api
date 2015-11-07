#ifndef RAPP_OBJECT_POSESTAMPED
#define RAPP_OBJECT_POSESTAMPED

#include "../Pose/Pose.hpp"
#include "../Msg_header/Header.hpp"
namespace rapp {
	namespace object {


		class PoseStamped
		{
			public:
			Header header;
		
			header.seq = 0;
			header.frame_id = "/map";
			header.stamp.sec = 0;
			header.stamp.nsec = 0;
			Pose pose;
			
			pose.header = header;
			pose.pose.position.x = 0;
			pose.pose.position.y = 0;
			pose.pose.position.z = 0;

			pose.pose.orientation.x = 0;
			pose.pose.orientation.y = 0;	
			pose.pose.orientation.z = 0;
			pose.pose.orientation.w = 1;


			PoseStamped(Pose pose, Header header):pose(pose),header(header){}
			PoseStamped () = default;


		};

	}
}
#endif

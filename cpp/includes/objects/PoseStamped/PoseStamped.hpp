#ifndef RAPP_OBJECT_POSESTAMPED
#define RAPP_OBJECT_POSESTAMPED

#include "../Pose/Pose.hpp"
#include "../Msg_header/Header.hpp"
namespace rapp {
	namespace object {


		class PoseStamped
		{
			Header header_def;
		
			header_def.seq = 0;
			header_def.frame_id = "/map";
			header_def.stamp.sec = 0;
			header_def.stamp.nsec = 0;
			Pose pose_def;
			
			pose_def.header = header_def;
			pose_def.pose.position.x = 0;
			pose_def.pose.position.y = 0;
			pose_def.pose.position.z = 0;

			pose_def.pose.orientation.x = 0;
			pose_def.pose.orientation.y = 0;	
			pose_def.pose.orientation.z = 0;
			pose_def.pose.orientation.w = 1;
			public:
			Pose pose;
			Header header;
			PoseStamped(Pose pose_=pose_def, Header header_=header_def):pose(pose_),header(header_){}
			PoseStamped () = default;


		};

	}
}
#endif

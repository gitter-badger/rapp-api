#ifndef RAPP_OBJECT_POSE
#define RAPP_OBJECT_POSE


namespace rapp {
	namespace object {


		class Header
		{
			int seq;
			time t;
			std::string frame;
			public:
			header(int seq, time t, std::string frame):s(s),t(t),frame(frame){}
		};

	}
}
#endif

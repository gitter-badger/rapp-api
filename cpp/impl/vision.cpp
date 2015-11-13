#include <iostream>

#include <robot/vision/vision.hpp>

namespace rapp {
namespace robot {

// placeholder class for vision implementation
class VisionImpl {
};

vision::vision(int argc, char * argv[]) : pimpl(NULL) {
	std::cout << "Initialized placeholder rapp::robot::vision library" << std::endl;
}

vision::~vision() {
	std::cout << "Finished placeholder rapp::robot::vision library" << std::endl;
}

rapp::object::picture::Ptr vision::captureImage (int camera_id, int camera_resolution, const std::string & encoding) {
	std::cout << "vision::captureImage" << std::endl;
	return std::make_shared<rapp::object::picture>(std::vector<rapp::types::byte>(), true);
}

bool vision::setCameraParam(int camera_id, int parameter_id, int new_value) {
	std::cout << "vision::setCameraParam" << std::endl;
	return true;
}

std::map<int, bool> vision::setCameraParams(int camera_id, const std::map<int, int> & params) {
	std::cout << "vision::setCameraParams" << std::endl;
	return std::map<int, bool>();
}

} /* namespace robot */
} /* namespace rapp */

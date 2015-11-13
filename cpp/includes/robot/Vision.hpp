#ifndef RAPP_ROBOT_VISION
#define RAPP_ROBOT_VISION
#include "Includes.ihh"

/**
 * @class Vision
 * @brief Class which defines the interface for Robot vision capabilities (capture Image, camera settings, Image segmentation and basic concept recognition)
 * @date 03-August-2015
 * @author Jan Figat <jan.figat@gmail.com>
 * @note This class uses pimpl pattern to make ABI as stable as possible when deploying new library versions
 */

namespace rapp {
namespace robot {

class VisionImpl;

class Vision
{
  public:
  
    /// Constructor - create instance of VisionImpl here
    Vision(int argc, char * argv[]);
  
    ~Vision();
    
    rapp::object::picture captureImage(int camera_id, int camera_resolution, const std::string & encoding);
	
	bool setCameraParam(int camera_id, int camera_parameter_id, int new_value);
	
	std::vector<uint8_t> setCameraParams(int camera_id, std::vector<uint32_t> camera_parameter_ids, std::vector<uint32_t> new_values);
	
	rapp::object::Matrix2D getTransform(std::string chainName, int space);
    
    
  private:
    VisionImpl * pimpl;
};

} // namespace robot
} // namespace rapp

namespace rappPlatform {
namespace robot {

class VisionDynImpl;

class VisionDyn
{
  public:
  
    /// Constructor - create instance of VisionImpl here
    VisionDyn(int argc, char * argv[]);
  
    ~VisionDyn();
    
	std::vector< std::vector <float> > faceDetect(rapp::object::picture image, int camera_id, int camera_resolution);
    
    rapp::object::QRCode3D qrCodeDetection(rapp::object::picture image, std::vector<std::vector<float>> robotToCameraMatrix, float landmarkTheoreticalSize = 0.16f);
    
  private:
    VisionDynImpl * pimpl;
};

} // namespace robot
} // namespace rappPlatform


#endif // RAPP_ROBOT_VISION

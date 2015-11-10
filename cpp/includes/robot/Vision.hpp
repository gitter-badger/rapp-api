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
    
    rapp::object::picture captureImage(std::string cameraId, int cameraResolution);
	
	bool setCameraParams(int cameraId, int cameraParameterId, int newValue );
	
	cv::Mat getTransform(std::string chainName, int space);
    
    
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
    
	std::vector< std::vector <float> > faceDetect(rapp::object::picture image, std::string cameraId, int cameraResolution);
    
    rapp::object::QRCode3D qrCodeDetection(rapp::object::picture image, cv::Mat &robotToCameraMatrix_, float landmarkTheoreticalSize);
    
  private:
    VisionDynImpl * pimpl;
};

} // namespace robot
} // namespace rappPlatform


#endif // RAPP_ROBOT_VISION

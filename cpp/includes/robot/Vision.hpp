#ifndef RAPP_ROBOT_VISION
#define RAPP_ROBOT_VISION
#include "Includes.ihh"

#include <string>

#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/imgproc/imgproc.hpp>

//#include <vector>

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
    
    cv::Mat captureImage(std::string cameraId, int cameraResolution);
	
	bool setCameraParams(int cameraId, int cameraParameterId, int newValue );
	
	cv::Mat getTransform(std::string chainName, int space);
    
    
  private:
    VisionImpl * pimpl;
};

} // namespace robot
} // namespace rapp


#endif // RAPP_ROBOT_VISION

#ifndef RAPP_ROBOT_NAVIGATION
#define RAPP_ROBOT_NAVIGATION
#include "Includes.ihh"
/**
 * @class Navigation
 * @brief Class which defines the interface for Robot navigation capabilities (movement, localization)
 * @date 10-August-2015
 * @author Wojciech Dudek <wojciechsbox@gmail.com>
 * @note This class uses pimpl pattern to make ABI as stable as possible when deploying new library versions
 */


////
//  CORE AGENT API
////
namespace rapp {
namespace robot {

class NavigationImpl;

class Navigation
{
  public:
  
    /// Constructor - create instance of NavigationImpl here
    Navigation(int argc, char * argv[]);
  
    ~Navigation();
    
    bool moveTo(float x, float y, float theta);

    bool moveVel(float x, float y, float theta);

    bool moveStop();

    bool moveJoint(std::vector<std::string> joint, std::vector<float> angle);

    bool takePredefinedPosture(std::string posture, float speed);

    bool lookAtPoint(float x, float y, float z);

    bool rest(std::string posture);

    bool moveAlongPath(rapp::object::Path path);

    rapp::object::PoseStamped getRobotPose();

    bool setGlobalPose(rapp::object::Pose pose);

    
  private:
    NavigationImpl * pimpl;
};

} // namespace robot
} // namespace rapp

////
//  DYNAMIC AGENT API
////
namespace rappPlatform {
namespace robot {

class Navigation
{
  public:
      rapp::objects::Pose qrCodeLocalization(rapp::object::picture image, rapp::object::QRcodeMap QRmap);
};
} // namespace robot
} // namespace rappPlatform

#endif // RAPP_ROBOT_NAVIGATION

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
    // bool moveHead(float yaw,float pitch);
    bool moveStop();
    bool moveJoint(std::vector<std::string> joint, std::vector<float> angle);
    // bool removeStiffness(std::string joint);
    bool takePredefinedPosture(std::string posture);
    // bool visOdom();
    bool lookAtPoint(float x, float y, float z);
    bool rest();
    bool moveAlongPath(rapp::objects::Path path);
    rapp::objects::Pose getRobotPosition();
    bool globalLocalization(rapp::objects::Pose pose);
    rapp::objects::Path PathPlanner_2D(rapp::objects::Pose start, rapp::objects::Pose goal, rapp::objects::OccupancyGrid map);
    rapp::objects::Pose QRcodeLocalization(cv::Mat image, rapp::objects::QRcodeMap QRmap);
    
  private:
    NavigationImpl * pimpl;
};

} // namespace robot
} // namespace rapp

#endif // RAPP_ROBOT_NAVIGATION

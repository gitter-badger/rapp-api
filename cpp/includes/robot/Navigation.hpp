#ifndef RAPP_ROBOT_NAVIAGTION
#define RAPP_ROBOT_NAVIGATION
#include "Includes.ihh"

#include <string>


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
  
    /// Constructor - create instance of VisionImpl here
    Navigation(int argc, char * argv[]);
  
    ~Navigation();
    
  void Navigation::moveTo(float x, float y, float theta);
  void Navigation::moveVel(float x, float y, float theta);
  void Navigation::moveHead(float yaw,float pitch);
  void Navigation::moveStop();
  void Navigation::moveJoint(std::string joint, float angle);
  void Navigation::removeStiffness(std::string joint);
  void Navigation::takePredefinedPosture(std::string pose);
  void Navigation::visOdom();
  void Navigation::lookAtPoint(float x, float y, float z);
  
    
  private:
    NavigationImpl * pimpl;
};

} // namespace robot
} // namespace rapp

#endif // RAPP_ROBOT_NAVIGATION

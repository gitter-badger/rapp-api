#ifndef RAPP_OBJECT_QRMAP
#define RAPP_OBJECT_QRMAP
#include "Includes.ihh"

namespace rapp {
namespace object {

/**
 * @class qrMap
 * @brief class which should encapsulate a QR code map
 * @version 1
 * @date 27-October-2015
 * @author Wojciech Dudek <wojciechdudek.mail@gmail.com>
 */

class QRcodeMap
{
  std::vector<std::string> labels;
  std::vector<float> x;
  std::vector<float> y;
  std::vector<float> z;
  std::vector<float> orientation_x;
  std::vector<float> orientation_y;
  std::vector<float> orientation_z;
  public:
    
    QRcodeMap ( 
              std::vector<std::string> labels,
              std::vector<float> x,
              std::vector<float> y,
              std::vector<float> z,
              std::vector<float> orientation_x,
              std::vector<float> orientation_y,
              std::vector<float> orientation_z
          )

    : labels(labels),
      x(x),
      y(y),
      z(z),
      orientation_x(orientation_x),
      orientation_y(orientation_y),
      orientation_z(orientation_z)
      {}
};
}
}
#endif

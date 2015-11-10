#ifndef RAPP_OBJECT_QRCODEMAP
#define RAPP_OBJECT_QRCODEMAP
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
  static std::vector<float> DEFAULT_VECTOR;

  std::vector<float> y_def;

  std::vector<float> z_def;

  std::vector<float> orientation_x_def;

  std::vector<float> orientation_y_def;

  std::vector<float> orientation_z_def;

public:
    
    QRcodeMap ( 
              std::vector<std::string> labels,
              std::vector<float> x =DEFAULT_VECTOR,
              std::vector<float> y =DEFAULT_VECTOR,
              std::vector<float> z =DEFAULT_VECTOR,
              std::vector<float> orientation_x=DEFAULT_VECTOR,
              std::vector<float> orientation_y=DEFAULT_VECTOR,
              std::vector<float> orientation_z=DEFAULT_VECTOR
          )

    : labels(labels),
      x(x),
      y(y),
      z(z),
      orientation_x(orientation_x),
      orientation_y(orientation_y),
      orientation_z(orientation_z)
      {}
	QRcodeMap () = default;
};
}
}
#endif

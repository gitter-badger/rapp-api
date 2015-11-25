#ifndef RAPP_ROBOT_VISION
#define RAPP_ROBOT_VISION
#include "Includes.ihh"

namespace rapp {
namespace robot {


class VisionImpl;

/**
 * @class vision
 * @brief Abstract Base Class (ABC) Interface for Vision
 * @version 1
 * @date 20-September-2015
 * @author Alex Gkiokas <a.gkiokas@ortelio.co.uk>
 */
class vision
{
  public:

    /**
     * Create vision module. Implementation object (pimpl) should be created here.
     */
    vision(int argc = 0, char * argv[] = NULL);

    /**
     * Destroy vision module. Implementation object should be destroyed here.
     */
    ~vision();

    /**
     * Capture an image frame from the robot’s camera.
     *
     * @param camera_id ID of the camera to be used
     * @param camera_resolution
     * @param encoding output image encoding type (e.g. "png", "jpg")
     *
     * @return captured image as raw byte stream
     */
    rapp::object::picture::Ptr captureImage (int camera_id, int camera_resolution, const std::string & encoding);

    /**
     * Set camera parameter.
     *
     * @param camera_id ID of the camera to be used
     * @param parameter_id ID of the parameter to be changed
     * @param new_value new value for the selected parameter
     *
     * @return true on success, false otherwise
     */
    bool setCameraParam(int camera_id, int parameter_id, int new_value);

    /**
     * Set multiple camera parameters at once.
     *
     * @param camera_id ID of the camera to be used
     * @param params map of pairs param_id->new_value
     *
     * @return success flag for each parameter
     */
    std::map<int, bool> setCameraParams(int camera_id, const std::map<int, int> & params);
    
    /**
     * Detects faces.
     *
     * @param image for the face detection
     * @param camera_id ID of the camera to be used
     * @param camera_resolution map of pairs param_id->new_value
     *
     * @return vector of informations about the detected face
     */
    std::vector< std::vector <float> > faceDetect(rapp::object::picture image, int camera_id, int camera_resolution);
    
    /**
     * Detects QR-codes.
     *
     * @param image for the QR-code detection
     * @param robotToCameraMatrix transformation matrix from robot to camera framework
     * @param landmarkTheoreticalSize
     * @param camera_matrix
     *
     * @return QR-codes informations
     */
    rapp::object::QRCode3D qrCodeDetection(rapp::object::picture image, std::vector<std::vector<float>> robotToCameraMatrix, double camera_matrix[][3], float landmarkTheoreticalSize = 0.16f);

private:
    VisionImpl * pimpl;
};

} /* namespace robot */
} /* namespace rapp */
#endif

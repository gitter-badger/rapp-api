#ifndef RAPP_OBJECT_QRCODE3D
#define RAPP_OBJECT_QRCODE3D


namespace rapp {
namespace object {

/**
 * @class QRCode3D
 * @brief class which should encapsulate a QR code in camera coordinate system and in robot coordinate system
 * @version 1
 * @date 09-November-2015
 * @author Jan Figat <jfigat@ia.pw.edu.pl>
 */
	//Matrix2<double> matrix_double;

	struct QRCode3D
	{
		bool isQRcodeFound;
		int numberOfQRcodes;//number of detected QRcodes
		std::vector<std::vector<std::vector<double>>> LandmarkInCameraCoordinate;//Transformation matrix from camera to Landmark
		std::vector<std::vector<std::vector<double>>> LandmarkInRobotCoordinate;//Transformation matrix from camera to robot
		std::vector<std::string> QRmessage; //vector for messages from QRcodes

		void clear()
		{
			isQRcodeFound = false;
			numberOfQRcodes = 0;
			LandmarkInCameraCoordinate.clear();
			LandmarkInRobotCoordinate.clear();
			QRmessage.clear();
		}
	};
}
}
#endif

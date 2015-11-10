#ifndef RAPP_OBJECT_MATRIX2D
#define RAPP_OBJECT_MATRIX2D

#include "Includes.ihh"
namespace rapp {
	namespace object {


		struct Matrix2D
		{
			std::vector<std::vector<float>> matrix;
			void clear(){
				matrix.clear();
			}
		};

	}
}
#endif

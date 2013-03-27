/*
 * cube.hpp
 *
 *  Created on: 21.3.2013
 *      Author: akin
 */

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "meshplane.hpp"
#include "CImg.h"
#include <string>

class Cube
{
public:
	enum Side
	{
		TOP = 0,
		BOTTOM = 1,
		LEFT = 2,
		RIGHT = 3,
		FORWARD = 4,
		BACK = 5
	};
private:
	MeshPlane top;
	MeshPlane bottom;
	MeshPlane forward;
	MeshPlane back;
	MeshPlane left;
	MeshPlane right;

	cimg_library::CImg<unsigned char> itop;
	cimg_library::CImg<unsigned char> ibottom;
	cimg_library::CImg<unsigned char> iforward;
	cimg_library::CImg<unsigned char> iback;
	cimg_library::CImg<unsigned char> ileft;
	cimg_library::CImg<unsigned char> iright;
public:
	Cube();
	~Cube();

	bool in( const std::string& path , float complexity = 10 );
	bool out( const std::string& path );

	MeshPlane& get( Cube::Side side );
};

#endif // CUBE_HPP_

/*
 * meshplane.hpp
 *
 *  Created on: 25.3.2013
 *      Author: akin
 */

#ifndef MESHPLANE_HPP_
#define MESHPLANE_HPP_

#include "CImg.h"


class MeshPlane
{
private:
	float complexity;
public:
	MeshPlane();
	~MeshPlane();

	MeshPlane& initialize( float complexity );

	bool generate( const cimg_library::CImg<unsigned char>& buffer );
};

#endif // MESHPLANE_HPP_

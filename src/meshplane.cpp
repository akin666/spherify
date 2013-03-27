/*
 * meshplane.cpp
 *
 *  Created on: 25.3.2013
 *      Author: akin
 */

#include "meshplane.hpp"
#include <TGAImage.h>
#include "stringtools"

MeshPlane::MeshPlane()
: complexity( 0.0f )
{
}

MeshPlane::~MeshPlane()
{
}

MeshPlane& MeshPlane::initialize( float complexity )
{
	this->complexity = complexity;

	return *this;
}

int itt = 0;
bool MeshPlane::generate( const cimg_library::CImg<unsigned char>& buffer )
{
	int colors = buffer.spectrum();

	++itt;

	std::string filename("gen_");
	std::string extension(".tga");

	if( colors == 4 )
	{
		imagesaver::RGBA8Write( filename + stringtools::to_ot<std::string,int>( itt ) + extension  , buffer.width() , buffer.height() , buffer.data() );
	}
	else if( colors == 3 )
	{
		imagesaver::RGB8Write( filename + stringtools::to_ot<std::string,int>( itt ) + extension  , buffer.width() , buffer.height() , buffer.data() );
	}

	return true;
}

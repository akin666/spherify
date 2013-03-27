/*
 * cube.cpp
 *
 *  Created on: 21.3.2013
 *      Author: akin
 */

#include "cube.hpp"
#include "stb_image.h"
#include "TGAImage.h"
#include <vector>

Cube::Cube()
{
}

Cube::~Cube()
{
}

bool Cube::in( const std::string& path , float complexity )
{
	// Load image
	{
		//
		// XEXX
		// ABCD
		// XFXX
		//
		// E top
		// F bottom
		// B forward
		// D back
		// A left
		// C right
		//
		cimg_library::CImg<unsigned char> image;

		// load image data
		{
			int width = 0;
			int height = 0;
			int components = 0;
			unsigned char *data = stbi_load( path.c_str() , &width , &height , &components , 4 );

			// convert RGBARGBA... -> RRR...GGG...BBB...AAA...
			int pixels = width * height;

			std::vector<unsigned char> target;
			target.resize( pixels * components );

			if( components == 4 )
			{
				unsigned char *tr = &target[ 0 ];
				unsigned char *tg = &target[ pixels ];
				unsigned char *tb = &target[ 2 * pixels ];
				unsigned char *ta = &target[ 3 * pixels ];

				for( int i = 0 ; i < pixels ; ++i )
				{
					tr[ i ] = data[ i * 4 + 0 ];
					tg[ i ] = data[ i * 4 + 1 ];
					tb[ i ] = data[ i * 4 + 2 ];
					ta[ i ] = data[ i * 4 + 3 ];
				}
			}
			else if( components == 3 )
			{
				unsigned char *tr = &target[ 0 ];
				unsigned char *tg = &target[ pixels ];
				unsigned char *tb = &target[ 2 * pixels ];

				for( int i = 0 ; i < pixels ; ++i )
				{
					tr[ i ] = data[ i * 4 + 0 ];
					tg[ i ] = data[ i * 4 + 1 ];
					tb[ i ] = data[ i * 4 + 2 ];
				}
			}
			stbi_image_free( data );

			// send data to image.. -> data , x , y , z , channels.
			image.assign( &target[ 0 ] , width , height , 1 , components );

			image.mirror('y');
		}

		int width = image.width();
		int height = image.height();

		// 4x3 assumtion!
		int ftwidth = width / 4;
		int ftheight = height / 3;
		if( (ftwidth * 4) != width || (ftheight * 3) != height || ftwidth != ftheight )
		{
			return false;
		}

		// copy pieces to buffers.
		// TODO! Why the -1 in both dimensions, I dont know. need to solve it later.
		int x = 0;
		int y = 0;
		{
			x = ftwidth;
			y = 0;

			itop = image.get_crop( x , y , 0 , x + ftwidth -1, y + ftheight -1, 0 );
		}
		{
			x = ftwidth;
			y = 2 * ftheight;

			ibottom = image.get_crop( x , y , 0 , x + ftwidth -1, y + ftheight -1, 0 );
		}
		{
			x = ftwidth;
			y = ftheight;

			iforward = image.get_crop( x , y , 0 , x + ftwidth -1, y + ftheight -1, 0 );
		}
		{
			x = 3 * ftwidth;
			y = ftheight;

			iback = image.get_crop( x , y , 0 , x + ftwidth -1, y + ftheight -1, 0 );
		}
		{
			x = 0;
			y = ftheight;

			ileft = image.get_crop( x , y , 0 , x + ftwidth -1, y + ftheight -1, 0 );
		}
		{
			x =  2 * ftwidth;
			y = ftheight;

			iright = image.get_crop( x , y , 0 , x + ftwidth -1, y + ftheight -1, 0 );
		}
	}

	// Load mesh
	{
		if( !top.initialize( complexity ).generate( itop ) )
		{
			return false;
		}
		if( !bottom.initialize( complexity ).generate( ibottom ) )
		{
			return false;
		}
		if( !left.initialize( complexity ).generate( ileft ) )
		{
			return false;
		}
		if( !right.initialize( complexity ).generate( iright ) )
		{
			return false;
		}
		if( !forward.initialize( complexity ).generate( iforward ) )
		{
			return false;
		}
		if( !back.initialize( complexity ).generate( iback ) )
		{
			return false;
		}
	}

	return true;
}

bool Cube::out( const std::string& path )
{
	return true;
}

MeshPlane& Cube::get( Cube::Side side )
{
	switch( side )
	{
		case Cube::LEFT : return left;
		case Cube::RIGHT : return right;
		case Cube::TOP : return top;
		case Cube::BOTTOM : return bottom;
		case Cube::FORWARD : return forward;
		case Cube::BACK : return back;
	}
	return top;
}

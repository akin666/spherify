/*
 * vec3.hpp
 *
 *  Created on: 21.3.2013
 *      Author: akin
 */

#ifndef VEC3_HPP_
#define VEC3_HPP_

template <typename CType>
class vector3
{
public:
	CType x,y,z;

	vector3()
	: x( 0 )
	, y( 0 )
	, z( 0 )
	{
	}
};

typedef vector3<float> vec3;
typedef vector3<float> veci3;

#endif // VEC3_HPP_

//============================================================================
// Name        : Spherify.cpp
// Author      : akin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "argtools.hpp"
#include "cube.hpp"

int main( int argc , char *argv[] )
{
	StringSet args;
	CommandMap commands;
	populateStringSet( argc , argv , args , commands );

	std::string in;
	populateIfSet( args , commands , "in" , in );
	std::string out;
	populateIfSet( args , commands , "out" , out );

	Cube cube;
	if( !in.empty() )
	{
		cube.in( in );
	}
	if( !out.empty() )
	{
		cube.out( out );
	}

	return 0;
}

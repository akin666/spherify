/*
 * argtools.cpp
 *
 *  Created on: 26.3.2013
 *      Author: akin
 */

#include "argtools.hpp"

void populateStringSet( int argc , char *argv[] , StringSet& args , CommandMap& commands )
{
	args.clear();
	args.reserve( argc );
	commands.clear();

	for( size_t i = 0 ; i < argc ; ++i )
	{
		std::string current( argv[i] );
		args.push_back( current );

		if( current.size() > 1 && current[0] == '-' )
		{
			commands[ current.substr( 1 ) ] = i;
		}
	}
}

void populateIfSet( StringSet& args , CommandMap& commands , const std::string& key , std::string& target )
{
	CommandMap::iterator command = commands.find( key );
	if( command != commands.end() )
	{
		int i = command->second + 1;
		if( i < args.size() )
		{
			target = args[ i ];
		}
	}
}

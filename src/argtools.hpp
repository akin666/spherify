/*
 * argtools.hpp
 *
 *  Created on: 26.3.2013
 *      Author: akin
 */

#ifndef ARGTOOLS_HPP_
#define ARGTOOLS_HPP_

#include <stdtypes>

typedef std::map<std::string , int> CommandMap;

void populateStringSet( int argc , char *argv[] , StringSet& args , CommandMap& commands );
void populateIfSet( StringSet& args , CommandMap& commands , const std::string& key , std::string& target );

#endif // ARGTOOLS_HPP_

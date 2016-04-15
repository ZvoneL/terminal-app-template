/*
 * commandLineOptions.cpp
 *
 *  Created on: 11 Apr 2016
 *      Author: zvone
 */
#include "commandLineOptions.h"
#include <iostream>
#include <string.h>

bool CommandLineParser::parse(int argc, char *argv[])
{
	//special case for help
	for(int i = 1; i < argc; i++)
	{			
		if(!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
		{
			helpWanted_ = true;
			return true;
		}
	}
	
	for(std::vector<CommandLineOption*>::iterator optsIter = options_.begin(); optsIter != options_.end(); optsIter++)
	{
		bool found = false;
		for(int i = 1; i < argc; i++)
		{
			if(std::string(argv[i]) == "-" + (*optsIter)->commandShort() ||
			   std::string(argv[i]) == "--" + (*optsIter)->commandLong()  )
		   {
			   found = true;
			   break;
		   }
		}
		if((*optsIter)->isRequired() && !found)
		{
			return false;
		}
	}
	return true;
}

void CommandLineParser::printHelp()
{
	std::cout << description_ << std::endl;
	std::cout << "version: " << version_ << std::endl;
	std::cout << "\ncalling options:\n" << std::endl;
	for(std::vector<CommandLineOption*>::iterator optsIter = options_.begin(); optsIter != options_.end(); optsIter++)
	{
		std::cout << "\t\t-" << (*optsIter)->commandShort() << " --" << (*optsIter)->commandLong() << " " << (*optsIter)->description() << std::endl;
	}
}

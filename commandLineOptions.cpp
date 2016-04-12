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
	for(int i = 1; i < argc; i++)
	{			
		if(!strcmp(argv[i], "-h"))
		{
			helpWanted_ = true;
			return true;
		}
	}
	
	for(std::vector<CommandLineOption*>::iterator optsIter = options_.begin(); optsIter != options_.end(); optsIter++)
	{
		if((*optsIter)->isRequired())
		{
			for(int i = 1; i < argc; i++)
			{
				
			}
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
		std::cout << "\t\t-" << (*optsIter)->commandChar() << " --" << (*optsIter)->commandString() << " " << (*optsIter)->description() << std::endl;
	}
}

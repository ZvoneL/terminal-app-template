/*
 * commandLineOptions.cpp
 *
 *  Created on: 11 Apr 2016
 *      Author: zvone
 */
#include "commandLineOptions.h"
#include <iostream>

bool CommandLineParser::Parse(int argc, char *argv[])
{
	for(std::vector<CommandLineOption*>::iterator optsIter = options_.begin(); optsIter != options_.end(); optsIter++)
	{
		if((*optsIter)->IsRequired())
		{
			for(int i = 1; i < argc; i++)
			{
				if()
			}
			return false;
		}
	}
	return true;
}




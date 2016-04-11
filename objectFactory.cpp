#include "objectFactory.h"
#include "commandLineOptions.h"
#include <iostream>

ObjectFactory ObjectFactory::inst;

int ObjectFactory::Init(int argc, char *argv[])
{
	commandLineParser_ = new CommandLineParser();

	CommandLineOption* helpOption = new CommandLineOption("help", 'h', "help");
	helpOption->SetDescription("Prints this help");

	//if error in parsing command line arguments print message and end program
	if(!commandLineParser_->Parse(argc, argv))
	{
		std::cout << "Error starting program." << std::endl;
		return 1;
	}
	return 0;
}

ObjectFactory& ObjectFactory::Inst()
{
	return inst;
}

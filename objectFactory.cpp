#include "objectFactory.h"
#include "commandLineOptions.h"
#include <iostream>

ObjectFactory ObjectFactory::inst;

int ObjectFactory::Init(int argc, char *argv[])
{
	commandLineParser_ = new CommandLineParser();

	commandLineParser_->setVersion("0.1");
	commandLineParser_->setDescription("Terminal application template");
	
	CommandLineOption* helpOption = new CommandLineOption("help", 'h', "help");
	helpOption->setDescription("Prints this help");
	
	commandLineParser_->addOption(helpOption);

	//if error in parsing command line arguments print message and end program
	if(!commandLineParser_->parse(argc, argv))
	{
		std::cout << "Error starting program." << std::endl;
		return 1;
	}
	if(commandLineParser_->helpWanted())
	{
		commandLineParser_->printHelp();
		return 0;
	}
	return 0;
}

ObjectFactory& ObjectFactory::Inst()
{
	return inst;
}

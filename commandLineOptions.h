#ifndef COMMANDLINEOPTIONS_H
#define COMMANDLINEOPTIONS_H

#include <string>
#include <stdexcept>
#include <vector>

class CommandLineOption
{
public:
	CommandLineOption(std::string name, char commandChar, std::string commandString)
	:type_(boolT),
	 name_(name),
	 commandChar_(commandChar),
	 commandString_(commandString),
     isDataSet_(false),
     hasValue_(false),
     isRequired_(false) {}
	virtual ~CommandLineOption() {}
	void setDescription(std::string description)
	{
		description_ = description;
	}
	bool isRequired(){ return isRequired_;}
	
	std::string value()
	{
		if(!hasValue_)
		{
			throw std::domain_error("This option has no value");
		}
		if(!isDataSet_)
		{
			throw std::domain_error("Value not set");
		}
		return value_;
	}
	
	char commandChar() { return commandChar_;}
	std::string commandString() { return commandString_;}
	std::string description() { return description_;}
	
private:
	enum types
	{
		boolT,
		intT,
		stringT
	} type_;
	std::string name_;
	char commandChar_;
	std::string commandString_;	
	std::string description_;
	std::string value_;
	bool isDataSet_;
	bool hasValue_;
	bool isRequired_;
};

class CommandLineParser
{
public:
	CommandLineParser()
	: helpWanted_(false),
	  version_("N/A"),
	  description_("N/A") {}
	~CommandLineParser() {}
	bool parse(int argc, char *argv[]);
	void addOption(CommandLineOption* option)
	{
		options_.push_back(option);
	}
	void setVersion(std::string valToSet)
	{
		version_ = valToSet;
	}
	void setDescription(std::string valToSet)
	{
		description_ = valToSet;
	}
	bool helpWanted() { return helpWanted_;}
	void printHelp();

private:
	std::vector<CommandLineOption*> options_;
	bool helpWanted_;
	std::string version_;
	std::string description_;
};

#endif

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
	void SetDescription(std::string description)
	{
		description_ = description;
	}
	bool IsRequired(){ return isRequired_;}
	
	std::string Get()
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
	CommandLineParser() {}
	~CommandLineParser() {}
	bool Parse(int argc, char *argv[]);
	void AddOption(CommandLineOption* option)
	{
		options_.push_back(option);
	}

private:
	std::vector<CommandLineOption*> options_;
};

#endif

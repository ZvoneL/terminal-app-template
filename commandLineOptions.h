#ifndef COMMANDLINEOPTIONS_H
#define COMMANDLINEOPTIONS_H

#include <string>

template <typename T>
class CommandLineOption
{
public:
	CommandLineOption(char commandChar, std::string commandString)
	:commandChar_(commandChar),
	 commandString_(commandString),
	 isDataSet_(false)s	 {}
	virtual ~CommandLineOption() {}
	
	T Get() 
	{
		if(!isDataSet_)
		{
			throw domain_error("Value not set");
		}
		return value_;
	}
	
private:
	char commandChar_;
	std::string commandString_;
	
	T value_;
	bool isDataSet_;
};

class CommandLineOptions
{
public:
	CommandLineOptions() {}
	~CommandLineOptions() {}
	enum types
	{
		intT,
		stringT
	} type_;
	union options
	{
		CommandLineOption<int>* intOption;
		CommandLineOption<std::string>* stringOption;
	} option_;
};

#endif

#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_

class ObjectFactory
{
public:
	~ObjectFactory(void);
	int Init();
	static ObjectFactory& Inst();
	
protected:
	ObjectFactory(void);
	static ObjectFactory inst;
}

#endif

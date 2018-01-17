#include <iostream>
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/document.h"

using namespace rapidjson;

#ifndef BASEMODEL_H
#define BASEMODEL_H

class BaseModel 
{
public:
	// template <typename Writer>
	virtual void Serialize(PrettyWriter<StringBuffer>  & writer) const 
	{
	}
};

#endif
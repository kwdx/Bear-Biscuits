#include <iostream>
#pragma once  
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/document.h"

using namespace rapidjson;

class BaseModel 
{
public:
	// template <typename Writer>
	virtual void Serialize(PrettyWriter<StringBuffer>  & writer) const 
	{
	}
};
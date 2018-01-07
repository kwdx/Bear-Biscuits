#include <iostream>
#include "../rapidjson/prettywriter.h"

using namespace rapidjson;

class BaseModel 
{
public:
	template <typename Writer>
 	void Serialize(Writer & writer) const 
	 {
		writer.StartObject();
		writer.EndObject();
	 }
};
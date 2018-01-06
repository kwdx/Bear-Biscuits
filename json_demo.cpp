#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;

int main() 
{
	// 1.把JSON解析成DOM
	const char * json = "{\"project\":\"rapidjson\", \"stars\":10}";
	Document d;
	d.Parse(json);

	// 2.利用DOM作出修改
	Value & s = d["stars"];
	s.SetInt(s.GetInt() + 1);

	// 3.把DOM转换（stringify）成JSON
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

	std::cout << buffer.GetString() << std::endl;
	return 0;
}
#include <iostream>
#include "include/model/ReturnModel.h"
#include "include/model/BBUserModel.h"

using namespace std;

int main() 
{
	ReturnModel returnModel = ReturnModel(200);
	BBUserModel baseModel = BBUserModel(101, "name", "nickname", 1);
	string output;
	returnModel.GetOutput(&output, &baseModel);
	cout << output << endl;
	Document document;
	// document.Parse("{ \"object\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] }");
	document.Parse(output.c_str());
    if (document.HasParseError())
        return 1;
	if (document.HasMember("object")) {
		BBUserModel userModel = BBUserModel(document["object"]);
		cout << userModel << endl;
	}
	return 0;
}
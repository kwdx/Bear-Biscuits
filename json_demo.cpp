#include <iostream>
#include "include/model/ReturnModel.h"

using namespace std;

int main() 
{
	ReturnModel model = ReturnModel(200);
	BaseModel baseModel = BaseModel();
	string output;
	model.GetOutput(&output, &baseModel);
	cout << output << endl;
	
	return 0;
}
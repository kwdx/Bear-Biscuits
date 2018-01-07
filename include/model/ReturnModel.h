#include "BaseModel.h"

class ReturnModel: public BaseModel
{
    public:
	    ReturnModel(int status);
        void GetOutput(std::string * output, BaseModel * model);

private:
    int status; // 状态
};

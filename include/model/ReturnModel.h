#include "BaseModel.h"

#ifndef RETURNMODEL_H
#define RETURNMODEL_H

class ReturnModel: public BaseModel
{
    public:
	    ReturnModel(int status);
        void GetOutput(std::string * output, BaseModel * model);

private:
    int status; // 状态
};

#endif
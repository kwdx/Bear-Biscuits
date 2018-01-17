#include "BaseController.h"

#ifndef HELLOCONTROLLER_H
#define HELLOCONTROLLER_H

class HelloController : public BaseController
{
public:
    // 定义纯虚函数
    virtual void exec(string& action);
    void get();
    void post();
};

#endif

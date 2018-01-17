#include <iostream>
#include <fcgi_stdio.h>
#include "env.h"
#include "constant.h"
#include "urlcode.h"
#include "Request.h"

#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

// #define OBJ_FUNC(action) action()

class BaseController
{
public:
    // 定义纯虚函数
    virtual void exec(string& action);
    virtual void get();
    virtual void post();
};

#endif

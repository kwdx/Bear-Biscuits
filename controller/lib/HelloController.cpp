#include "../include/HelloController.h"

void HelloController::exec(string& action)
{
    if (action == "world")
    {
        get();
    }
    else
    {
        post();
    }
    return;
    if (Request::method() == "GET")
    {
        get();
    } 
    else
    {
        post();
    }
}

void HelloController::get()
{
    FCGI_printf("get请求的完整args: %s %s", UrlDecode(Request::print_args()).c_str(), NL);
}

void HelloController::post()
{
    FCGI_printf("post请求的完整args: %s %s", UrlDecode(Request::print_args()).c_str(), NL);
}

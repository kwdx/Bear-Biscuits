//
//  main.cpp
//  Bear-Biscuits
//
//  Created by warden on 02/01/2018.
//  Copyright © 2018 warden. All rights reserved.
//

#include <iostream>
using namespace std;

#include <fcgi_stdio.h>
#include <time.h>
#include "core/env.h"
#include "core/constant.h"
#include <map>
// 这些不要去include 库里面的内容，到时候提取出来
#include "include/bb_request/Request.h"
#include "include/common/crypt.h"
#include "config/routes.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    while(FCGI_Accept() >= 0)
    {
        FCGI_printf( "Status: 200 OK\r\n" );
        FCGI_printf( "Content-type: text/html; charset=utf-8\r\n\r\n" );
        routes_register();
        const char *path = get_fcgi_env("DOCUMENT_URI").c_str();
        FCGI_printf("请求的接口路径: %s %s", path, NL);
        const char *method = Request::method().c_str();
        FCGI_printf("请求的方法: %s %s", method, NL);
        map<string, string> args = Request::args();
        FCGI_printf("get hello: %s %s", UrlDecode(args["hello"]).c_str(), NL);
        FCGI_printf("get world: %s %s", UrlDecode(args["world"]).c_str(), NL);
        string args_dumps_s = Request::print_args();
        FCGI_printf("get请求的完整args: %s %s", UrlDecode(args_dumps_s).c_str(), NL);
        string path_dumps_s = Request::print_path();
        FCGI_printf("path分解: %s %s", UrlDecode(path_dumps_s).c_str(), NL);
        // 这里有个显示问题，显示<int:name>的时候，会被html解析掉，之后修复
        FCGI_printf("path route match: %s %s", Route::match(Request::path()).c_str(), NL);
    }
    return 0;
}

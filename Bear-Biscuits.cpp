//
//  main.cpp
//  Bear-Biscuits
//
//  Created by warden on 02/01/2018.
//  Copyright © 2018 warden. All rights reserved.
//

#include <iostream>
#include <fcgi_stdio.h>
#include <time.h>
#include <map>
#include "core/env.h"
#include "core/constant.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    while(FCGI_Accept() >= 0)
    {
        FCGI_printf( "Status: 200 OK\r\n" );
        FCGI_printf( "Content-type: text/html; charset=utf-8\r\n\r\n" );
        map<string, string> r;
        get_fcgi_env(r);
        for (int i = 0; i < 19; ++i) {
            FCGI_printf("%s: %s%s",
                fcgi_env[i].c_str(), r[fcgi_env[i]].c_str(), DS);
        }
        const char *path = r["REQUEST_URI"].c_str();
        FCGI_printf("请求的接口路径: %s%s", path, DS);
        const char *d = "/";
        char *p = strtok((char *)path, d);
        FCGI_printf( "分解的接口路径: " );
        while (p) {
            FCGI_printf( " %s ", p );
            p = strtok(NULL, d);
        }
        FCGI_printf("%s", DS);
    }
    return 0;
}

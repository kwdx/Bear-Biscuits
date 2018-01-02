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

int main(int argc, const char * argv[])
{
    // insert code here...
    while(FCGI_Accept() >= 0)
    {
        FCGI_printf( "Status: 200 OK\r\n" );
        FCGI_printf( "Content-type: text/html\r\n\r\n" );
        char *path = getenv( "REQUEST_URI" );
        FCGI_printf( "请求的接口路: %s\n", path );
        const char *d = "/";
        char *p = strtok(path, d);
        FCGI_printf( "分解的接口路径: " );
        while (p) {
            FCGI_printf( " %s ", p );
            p = strtok(NULL, d);
        }
        FCGI_printf( "\n" );
    }
    return 0;
}

#include "include/Route.h"
#include <vector>
#include <map>
// #include "../controller/include/HelloController.h"
#include "include/Factory.h"

using namespace std;

#ifndef ROUTES_H
#define ROUTES_H

int routes_register() {
    // 匹配顺序按从上往下，如都不满足，则使用默认路由
    map<string, string> match;
    match["controller"] = "hello";
    match["action"] = "world_alias";
    vector<string> methods;
    methods.push_back("GET");
    Route::connect("/hello/world", match, methods);

    Route::connect("/hello/world/<int:name>", "hello", "world_alias", 1);
    Route::connect("/hello/world/<float:name>", "hello", "world_alias", 1);
    Route::connect("/hello/world/<string:name>", "hello", "world_alias", 3);
    Route::connect("/hello/world/<name>", "hello", "world_alias", 3);
    
    return 0;
}
// REGCLAS("hello", HelloController);

#endif
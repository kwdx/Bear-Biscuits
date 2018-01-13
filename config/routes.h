#include "../include/bb_request/Route.h"
#include <vector>
#include <map>
using namespace std;

int routes_register() {
    // 匹配顺序按从上往下，如都不满足，则使用默认路由
    map<string, string> match;
    match["controller"] = "hello";
    match["action"] = "world_alias";
    vector<string> methods;
    methods.push_back("GET");
    Route::connect("/hello/world", match, methods);

    Route::connect("/hello/world/<int:name>", "hello", "world_alias", 1);

    Route::connect("/hello/world/<string:name>", "hello", "world_alias", 3);
    return 0;
}

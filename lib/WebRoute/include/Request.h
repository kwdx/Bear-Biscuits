#include <map>
#include <vector>
#include "env.h"
using namespace std;

#ifndef REQUEST_H
#define REQUEST_H

class Request
{
    public:
        // todo 后面可以改成属性而非方法
        // 请求方法：GET、POST等
        static string method();
        // GET参数：返回hash map
        static map<string, string> args();
        // string形式返回GET的结果(供打印)
        static string print_args();
        // 分解url path
        static vector<string> path();
        // string形式返回path(供打印)
        static string print_path();
    private:
        // 静态方法，不允许实例化对象
        Request() {}
        // string形式返回map<string, string>的自定义方法(供打印)
        static string print_ssmap(map<string, string>);
        // string形式返回vector<string>的自定义方法(供打印)
        static string print_svec(vector<string>);
};

#endif
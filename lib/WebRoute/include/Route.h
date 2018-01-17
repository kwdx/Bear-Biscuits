#include <vector>
#include <map>
#include <cctype>
#include <stdlib.h>
#include <string>

using namespace std;

#ifndef ROUTE_H
#define ROUTE_H

typedef struct RouteRule
{
    string rule;
    map<string, string> match;
    vector<string> methods;
} RouteRule, *RR;

class Route
{
    public:
        // 规则的顺序，value=rule
        static vector<string> rule_rank;
        // 规则表，key=rule, value=struct RouteRule。顺序由rule_rank决定
        static map<string, RR> rule_table;
        // 注册路由
        static int connect(
            string rule, map<string, string> match, vector<string> methods
        );
        // 简单参数的版本
        static int connect(
            string rule, string controller, string action, int methods = 1
        );
        // 匹配路由(注意优先顺序)，且有默认路由。与rule拆解的内容同名
        static string match(vector<string> path);
        // 分配到对应的方法中
        static string dispatch(RR rule, map<string, string> params);
    private:
        static int get_bit(int binary, int n);
        static vector<string> path(string document_uri);
};

#endif
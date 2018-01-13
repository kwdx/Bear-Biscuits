#include <vector>
#include <map>
using namespace std;

typedef struct RouteRule
{
    string rule;
    map<string, string> match;
    vector<string> methods;
} RouteRule, *RR;

class Route
{
    public:
        // 规则表，key=rule, value=struct RouteRule
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
    private:
        static int get_bit(int binary, int n);
        static vector<string> path(string document_uri);
};

map<string, RR> Route::rule_table;

int Route::connect(string rule, map<string, string> match, vector<string> methods)
{
    if (match.empty()) {
        return 0;
    }
    if (methods.empty()) {
        methods.push_back("GET");
    }
    // RR是指针变量，需要动态分配
    RR rr = new RouteRule();
    rr->rule = rule;
    rr->match = match;
    rr->methods = methods;
    Route::rule_table[rule] = rr;
    return 1;
}

int Route::connect(string rule, string controller, string action, int methods)
{
    // methods: 1: GET, 2: POST
    vector<string> methods_v;
    if (get_bit(methods, 1)) {
        methods_v.push_back("GET");
    }
    if (get_bit(methods, 2)) {
        methods_v.push_back("POST");
    }
    map<string, string> match;
    match["controller"] = controller;
    match["action"] = action;
    return Route::connect(rule, match, methods_v);
}

string Route::match(vector<string> path)
{
    // 匹配的规则串
    string match = "";
    // 请求的url的分节
    unsigned int psize = path.size();
    map<string, RR> m = Route::rule_table;
    map<string, RR>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        vector<string> rr_path = Route::path(it->first);
        if (rr_path.size() != psize) {
            continue;
        }
        if (psize < 1) {
            return "";
        }
        unsigned int i = 0;
        for( ; i < psize; ++i) {
            unsigned int rr_path_part_size = rr_path[i].size();
            if (rr_path[i][0] == '<' && rr_path[i][rr_path_part_size - 1] == '>') {
                // 变量规则　<type:name>
                string var_type = "";
                string var_name = "";
                int var_ds = 0;
                for (int j = 1; j < rr_path_part_size - 1; ++j) {
                    if (var_ds) {
                        // 已经遍历到分隔符':'　<type:name>
                        var_name.push_back(rr_path[i][j]);
                    } else {
                        if (rr_path[i][j] == ':') {
                            var_ds = 1;
                            continue;
                        }
                        var_type.push_back(rr_path[i][j]);
                    }
                }
                // 缺省type的变量规则，如 <name>，代表 <string:name>
                var_name = var_type;
                var_type = "string";
                // todo check type and convert
                // if not check then break
                ///////// todo
                if (false) {
                    break;
                }
            } else {
                // 字符串
                // if not eq then break
                if (rr_path[i] != path[i]) break;
            }
        }
        // check i == psize for matching, then setval to string 'match' and break
        if (i == psize) {
            match = it->first;
            break;
        }
    }
    // no params and match default rule "controller/action"
    return match;
}

int Route::get_bit(int binary, int n)
{
    if (n < 1) {
        return -1;
    }
    // 获取二进制的右数第n位，如：二进制10010的右数第二位是1
    return binary >> (n - 1) & 1;
}

vector<string> Route::path(string document_uri)
{
    unsigned int ssize = document_uri.size();
    // 不是以 / 结尾的path，加上 /
    if ('/' != document_uri[ssize - 1]) {
        document_uri += "/";
        ++ ssize;
    }
    vector<string> res;
    // 去掉头部的 /
    for(unsigned int i = 1; i < ssize; /* empty oper */)
    {
        unsigned int pos = i;
        unsigned int len = 0;
        while (i < ssize) {
            if ('/' != document_uri[i++]) {
                ++ len;
                continue;
            }
            break;
        }
        string s = document_uri.substr(pos, len);
        res.push_back(s);
    }
    return res;
}

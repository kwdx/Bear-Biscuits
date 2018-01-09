#include <map>
#include <vector>
using namespace std;

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

string Request::method()
{
    return get_fcgi_env("REQUEST_METHOD");
}

map<string, string> Request::args()
{
    string query_string = get_fcgi_env("QUERY_STRING");
    unsigned int ssize = query_string.size();
    map<string, string> res;
    for (unsigned int i = 0; i < ssize; /* empty oper */) {
        string k = "", v = "";
        unsigned int pos = i;
        unsigned int len = 0;
        while (i < ssize) {
            if ('=' != query_string[i++]) {
                ++len;
                continue;
            }
            break;
        }
        k = query_string.substr(pos, len);
        res[k] = "";
        pos = i;
        len = 0;
        while (i < ssize) {
            if ('&' != query_string[i++]) {
                ++len;
                continue;
            }
            break;
        }
        v = query_string.substr(pos, len);
        res[k] = v;
    }
    return res;
}

string Request::print_args()
{
    map<string, string> m = Request::args();
    string sa = Request::print_ssmap(m);
    return sa;
}

string Request::print_ssmap(map<string, string> m) {
    // 迭代器
    map<string, string>::iterator it;
    string res = "";
    for (it = m.begin(); it != m.end(); ++it) {
        res += "[" + it->first + "] => [" + it->second + "], ";
    }
    return res;
}

vector<string> Request::path()
{
    string document_uri = get_fcgi_env("DOCUMENT_URI");
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

string Request::print_path()
{
    vector<string> v = Request::path();
    string sa = Request::print_svec(v);
    return sa;
}

string Request::print_svec(vector<string> v) {
    // 迭代器
    vector<string>::iterator it;
    string res = "";
    for (it = v.begin(); it != v.end(); ++it) {
        res += "[" + (*it) + "], ";
    }
    return res;
}

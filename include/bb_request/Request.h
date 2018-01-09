#include <map>
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
private:
    // 静态方法，不允许实例化对象
    Request() {}
    // string形式返回map<string, string>的自定义方法(供打印)
    static string print_ssmap(map <string, string>);
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

string Request::print_ssmap(map <string, string> m) {
    // 迭代器
    map<string, string>::iterator it;
    string res = "";
    for (it = m.begin(); it != m.end(); ++it) {
        res += "[" + it->first + "] => [" + it->second + "], ";
    }
    return res;
}

#include <stdlib.h>
#include <map>
using namespace std;

string fcgi_env[19] = {
    "SCRIPT_FILENAME",
    "QUERY_STRING",
    "REQUEST_METHOD",
    "CONTENT_TYPE",
    "CONTENT_LENGTH",
    "SCRIPT_NAME",
    "REQUEST_URI",
    "DOCUMENT_URI",
    "DOCUMENT_ROOT",
    "SERVER_PROTOCOL",
    "REQUEST_SCHEME",
    "HTTPS",
    "GATEWAY_INTERFACE",
    "SERVER_SOFTWARE",
    "REMOTE_ADDR",
    "REMOTE_PORT",
    "SERVER_ADDR",
    "SERVER_PORT",
    "SERVER_NAME"
};

/*
 * 环境变量列表
 */
int get_fcgi_env_list(map<string, string> &r)
{
    int i = 0;
    for (int i = 0; i < 19; ++i) {
        const char *fe = fcgi_env[i].c_str();
        char *s = getenv(fe);
        if (s) {
            r[fcgi_env[i]] = s;
        } else {
            r[fcgi_env[i]] = "";
        }
    }
    return 1;
}

/*
 * 根据key获取环境变量
 */
string get_fcgi_env(string key)
{
    char *r = getenv(key.c_str());
    if (r) {
        return r;
    }
    return "";
}

#include "../include/env.h"

using namespace std;

/*
 * 环境变量列表
 */
int get_fcgi_env_list(map<string, string> &r)
{
    // int i = 0;
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

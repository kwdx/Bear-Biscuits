#include <stdlib.h>
#include <map>
#include <string>
#include <fcgi_stdio.h>
#include "constant.h"

using namespace std;

#ifndef ENV_H
#define ENV_H

/*
 * 环境变量列表
 */
int get_fcgi_env_list(map<string, string> &r);

/*
 * 根据key获取环境变量
 */
string get_fcgi_env(string key);

#endif
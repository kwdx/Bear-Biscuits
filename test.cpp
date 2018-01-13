#include <iostream>
#include <map>
#include "core/env.h"
using namespace std;

int main ()
{
    map<string, string> r;
    get_fcgi_env(r);
    cout << r["HTTPS"] << endl;
    //for (int i = 0; i < 19; ++i)
    //{
    //    cout << r[i] << endl;
    //}
    return 0;
}

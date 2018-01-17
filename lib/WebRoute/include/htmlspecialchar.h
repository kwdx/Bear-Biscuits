#include <map>
using namespace std;

#ifndef HTMLSPECIALCHAE_H
#define HTMLSPECIALCHAE_H

/*
Special Character   Escape Sequence Purpose  
&                   &amp;           Ampersand sign 
'                   &apos;          Single quote 
"                   &quot;          Double quote
>                   &gt;            Greater than 
<                   &lt;            Less than
*/

map<char, string> get_escape_set()
{
    map<char, string> escape_set;
    escape_set['&'] = "&amp;";
    escape_set['\''] = "&apos;";
    escape_set['"'] = "&quot;";
    escape_set['>'] = "&gt;";
    escape_set['<'] = "&lt;";
    return escape_set;
}

string htmlspecialchar_escape(string raw)
{
    map<char, string> escape_set = get_escape_set();
    unsigned int raw_len = raw.size();
    string res = "";
    for (int i = 0; i < raw_len; ++i) {
        map<char, string>::iterator it;
        int matched = 0;
        for (it = escape_set.begin(); it != escape_set.end(); ++it) {
            if (raw[i] == it->first) {
                matched = 1;
                res += it->second;
                break;
            }
        }
        if (!matched) {
            res.push_back(raw[i]);
        }
    }
    return res;
}

#endif
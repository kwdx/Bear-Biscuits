#include <ctype.h>
#include <string>
using namespace std;

#ifndef URLCODE_H
#define URLCODE_H

unsigned char ToHex(unsigned char x);

unsigned char FromHex(unsigned char x);

string UrlEncode(const string& str);

string UrlDecode(const string& str);

#endif
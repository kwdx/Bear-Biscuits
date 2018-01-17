#include <iostream>
#include <map>

using namespace std;

#ifndef FACTORY_H
#define FACTORY_H

#define REGCLAS(name, classname)\
    classname* obj_creator_##classname() {\
        return new classname();\
    };\
    RegClass reg((string)name, (VOIDFUNC) obj_creator_##classname)

typedef void* (*VOIDFUNC)();

class Factory
{
private:
    map<string, VOIDFUNC> mp;
    void Reg(const string& name, VOIDFUNC func);
public:
    friend class RegClass;
    void* getControllerByName(string name);
    static Factory &getInstance();
    Factory();
    virtual ~Factory();
};


class RegClass
{
public:
    RegClass(string name, VOIDFUNC func);
};

#endif
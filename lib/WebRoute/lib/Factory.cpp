#include "../include/Factory.h"

Factory::Factory()
{
    cout << "Factory()" << endl;
}

Factory::~Factory()
{
    cout << "~Factory()" << endl;
}

Factory &getInstance()
{
    static Factory f;
    return f;
}

void* Factory::getControllerByName(string name)
{
    map<string, VOIDFUNC>::const_iterator iter;
        iter = mp.find(name);
        if (iter != mp.end())
        {
            VOIDFUNC func = iter->second;
            return func();
        }
        else
        {
            return nullptr;
        }
}

void Factory::Reg(const string& name, VOIDFUNC func)
{
    mp.insert(make_pair(name, func));
}

RegClass::RegClass(string name, VOIDFUNC func)
{
    Factory::getInstance().Reg(name, func);
};
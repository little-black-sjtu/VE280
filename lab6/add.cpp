#include "plugin.h"
#include <iostream>
#include <sstream>
#include <regex>

class Add : public Plugin{
public:
    Add():Plugin(){
        this->name = "add";
        this->author = "Meual";
        this->description = "add two integers";
        this->help = "Usage: add <integer> <integer>";
    }
    
    string response(const string &str) const override{
        stringstream ss(str);
        string buffer;
        int a, b;
        ss >> buffer >> a >> b;
        string result = to_string(a+b);
        return result;
    }

    int matchRule(const string &str) const override{
        std::regex re("^(add)(\\s\\d){2}$");
        return regex_match(str.begin(), str.end(), re);
    }

    string toString() const override {
        string output = " Add operations is great --Meual";
        return output;
    }
};

extern "C" Plugin *create() {
    return new Add();
}

extern "C" int *destroy(Plugin *p) {
    delete p;
    return 0;
}
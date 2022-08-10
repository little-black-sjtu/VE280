#include "plugin.h"
#include <iostream>
#include <sstream>

class Styled : public Plugin{
public:
    Styled():Plugin(){
        this->name = "styled";
        this->author = "Second Lobster";
        this->description = "I don't know how to describe.";
        this->help = "Input \"WhosYourDaddy\" or \"print styled\".";
    }
    
    string response(const string &str) const override{
        return "You are not playing Warcraft 3, guys...";
    }

    int matchRule(const string &str) const override{
        return (str=="WhosYourDaddy");
    }

    string toString() const override {
        string output = "Second Lobster writes styled because he thinks it is fun";
        return output;
    }
};

extern "C" Plugin *create() {
    return new Styled();
}

extern "C" int *destroy(Plugin *p) {
    delete p;
    return 0;
}
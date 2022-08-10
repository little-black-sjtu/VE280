#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    stringstream sstr;
    string line;
    string name;
    int count = 0;
    getline(cin, line);

    size_t found= line.find(",");
    while(found != string::npos){
        line[found] = ' ';
        found = line.find(",",found+1);
    }

    sstr<<line;
    while(sstr>>name){
        cout<<name<<endl;
        count++;
    }
    cout<<count<<endl;
    return 0;
}
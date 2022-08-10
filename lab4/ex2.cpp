#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct{
    string name;
    double price;
    double weight;
} Apple;


int main(int argc, char *argv[]){
    string file_name = argv[1];
    ifstream ifs;
    ifs.open(file_name);
    string line;
    stringstream sstr;
    Apple cheapest;
    Apple temp;
    getline(ifs, line);
    if(ifs){
        sstr<<line;
        sstr>>cheapest.name>>cheapest.price>>cheapest.weight;
    }
    while(getline(ifs, line)){
        sstr.clear();
        if(ifs){
            sstr<<line;
            sstr>>temp.name>>temp.price>>temp.weight;
        }
        if(cheapest.price/cheapest.weight>temp.price/temp.weight){
            cheapest.name = temp.name;
            cheapest.price = temp.price;
            cheapest.weight = temp.weight;
        }
    }
    cout<<setprecision(2)<<fixed<<cheapest.name<<" "<<cheapest.price<<" "<<cheapest.weight<<endl;
    ifs.close();
    return 0;
}
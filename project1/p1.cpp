#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

void print_prompt() {
    cout << "Please enter the integer and the test number: ";
}

void test(int integer, int type){
    int flag=0;
    switch (type)
    {
    case 1:{
        for (int i = 1; i <= integer; i++){
            if (integer==(i*(i+1)*(i+2)/6)){
                flag=1;
                break;
            }
        }
        break;
    }
    case 2:{
        string str = to_string(integer);
        flag=1;
        for(size_t i=0;i< str.length();i++){
            if(str[i] != str[str.length()-i-1]){
                flag=0;
                break;
            }
        }
        break;
    }
    case 3:{
        string str = to_string(integer);
        flag=1;
        for(size_t i=0;i< str.length();i++){
            int a = (int)str[i]-(int)'0';
            if (a==0){
                flag=0;
                break;
            }
            if(fmod(integer, a)!=0){
                flag=0;
                break;
            }
        }
        break;
    }
    case 4:{
        while (true){
            if(fmod(integer, 2)==0)
                integer = integer/2;
            else if(fmod(integer,3)==0)
                integer = integer/3;
            else if(fmod(integer, 5)==0)
                integer = integer/5;
            else {
                if(integer==1)
                    flag=1;
                else 
                    flag=0;
                break;
            }
        }
        break;    
    }
    default:
        break;
    }
    cout<<flag<<endl;
}

int main() {
    //TODO: write your code here
    int integer;
    int type;
    print_prompt();
    cin>>integer;
    cin>>type;
    while (integer<1||integer>10000000||type<1||type>4)
    {
        print_prompt();
        cin>>integer;
        cin>>type;
    }
    test(integer, type);
    return 0;
}
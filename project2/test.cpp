#include<iostream>

int main(){
    char a = -50;
    unsigned char b;
    b = (unsigned char)a;
    std::cout<<a<<" "<<b<<" "<<(int)a<<" "<<(int)b;
    return 0;
}
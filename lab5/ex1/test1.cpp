#include <iostream>
#include "ex1.h"

using namespace std;

bool odd(int elt){
    return elt%2;
}

bool even(int elt){
    return (elt+1)%2;
}

int main(){
    list_t list = list_make();
    list = list_make(1,list);
    list = list_make(2,list);
    list = list_make(4,list);
    list = list_make(4,list);
    list = list_make(2,list);
    list = list_make(1,list);
    list_print(list);
    list_t new_list = filter(list, odd);
    list_print(new_list);
    new_list = filter(list, even);
    list_print(new_list);
    cout<<"Whether the list is palindrome:"<< is_palindrome_list(list)<<endl;
    cout<<"dot product is:"<<dot(list, new_list)<<endl;
    return 0;
}


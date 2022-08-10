/*
 * This is an exercise of VE280 Lab 1, SU2022.
 */

#include <iostream>
using namespace std;


// EFFECTS: return true if the password is a valid one
bool isValidPassword(char password[]){
    // TODO: Implement this function.
    bool alphabetic_flag = false;
    bool numerical_flag = false;
    bool non_flag = false;
    for(int i=0;password[i]!='\0'&&i<50;i++)
    {
        if ((password[i]>=65&&password[i]<=90)||(password[i]>=97&&password[i]<=122))
        alphabetic_flag = true;
        else if(password[i]>=48&&password[i]<=57)
        numerical_flag = true;
        else
        non_flag = true;
    }
    if(alphabetic_flag&&numerical_flag&&non_flag)
    return true;
    else
    return false;
}


int main(){
    char password[50] = {};
    cin >> password;
    cout << isValidPassword(password) << endl;
}

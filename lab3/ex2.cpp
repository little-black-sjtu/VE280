#include <iostream>
#include <limits.h>
#include "ex2.h"

using namespace std;


int fold (int count, int arr[], int (*fn) (int, int), int initial) {
    // EFFECTS: returns the result of the fold function
    // TODO: implement this function recursively
    return fold_help(count, 0, initial, arr, fn);
}

int fold_help(int count, int num, int value, int arr[], int (*fn) (int, int)){
    if (num==count-1)
        return fn(arr[num], value);
    return fold_help(count, num+1, fn(arr[num],value),arr,fn);
}

int fn_add (int a, int b) {
    // TODO: implement this function such that fold(count, arr, fn_add, 0)
    // returns the sum of all the elements in arr
    return a+b;
}


int fn_count_odd (int a, int n) {
    // TODO: implement this function such that fold(n,arr,fn_count_odd, 0)
    // returns the numebr of odd numbers in the array
    if (a%2==1||a%2==-1)
        return n+1;
    else 
        return n;
}

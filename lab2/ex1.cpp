#include <iostream>

using namespace std;

#define RANGE 100000

bool isPrime[RANGE + 1];

// MODIFIES: isPrime[]
// EFFECTS: fill in isPrime[], true for prime, false otherwise
void generateIsPrime() {
    // TODO: implement Eratosthenes Sieve Algorithm
    for(int i=0;i<=RANGE;i++)
        isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;
    int i=2;
    while(i<=RANGE){
        if(!isPrime[i]){
            i++;
            continue;
        }
        int k=2;
        while(k*i<=RANGE){
            isPrime[k*i]=false;
            k++;
        }
        i++;
    }
}

int main() {
    // TODO: generate lookup table
    generateIsPrime();
    int length;
    cin>>length;
    int array[length];
    for (int i=0;i<length;i++) cin>>array[i];
    // TODO: read input and check if each num is prime
    for(int i=0;i<length;i++){
        if(isPrime[array[i]])
            cout<<array[i]<<" ";
    }
    return 0;
}
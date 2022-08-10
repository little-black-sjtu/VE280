#include <iostream>

using namespace std;

const int MAXSIZE = 10;

bool canWin(int count, int arr[], int position) {
    // EFFECTS: return whether the player can win given the start position
    // and the card sequence
    
    if (position<0||position>=count||arr[position]==-1){
        return false;
    }
    if (arr[position]==280)
        return true;
    int v = arr[position];
    arr[position]=-1;
    return (canWin(count,arr,position+v)\
    ||canWin(count,arr,position-v));
    // TODO: implement this function
}

int main() {
    int count;
    cin >> count;
    int arr[MAXSIZE];
    for (int i = 0; i < count; ++i) {
        cin >> arr[i];
    }
    int position;
    cin >> position;
    cout << canWin(count, arr, position);
}


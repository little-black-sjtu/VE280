#include "mylist.h"
#include "mylist_impl.h"
#include <iostream>

using namespace std;

int main(){
    // isLarger
    try{
        List<int> la;
        la.insertBack(9);
        la.insertBack(9);
        la.insertBack(9);

        List<int> lb;
        lb.insertBack(1);
        lb.insertBack(1);
        lb.insertBack(1);

        cout << isLarger(la, lb) << endl; // 0
        la.print();
        lb.print();
        List<int> ld = add(la,lb);
        ld.print();

        List<int> lc;
        la = lc;
        lb = lc;

        la.insertBack(2);
        la.insertBack(1);
        la.insertBack(1);

        lb.insertBack(1);
        lb.insertBack(1);
        lb.insertBack(1);

        cout << isLarger(la, lb) << endl; // 1

        la = lc;
        lb = lc;

        la.insertBack(1);
        la.insertBack(1);
        la.insertBack(1);

        lb.insertBack(1);
        lb.insertBack(1);
        lb.insertBack(1);

        cout << isLarger(la, lb) << endl; // 0

        la = lc;
        lb = lc;
        la.insertBack(1);
        la.insertBack(1);
        la.insertBack(4);

        lb.insertBack(1);
        lb.insertBack(1);
        lb.insertBack(3);

        cout << isLarger(la, lb) << endl; // 1

        la = lc;
        lb = lc;
        la.insertBack(1);
        la.insertBack(1);
        la.insertBack(2);

        lb.insertBack(1);
        lb.insertBack(1);
        lb.insertBack(3);

        cout << isLarger(la, lb) << endl; // 0

        la = lc;
        lb = lc;
        la.insertBack(1);
        la.insertBack(5);
        la.insertBack(2);

        lb.insertBack(1);
        lb.insertBack(3);
        lb.insertBack(2);

        cout << isLarger(la, lb) << endl; // 1

        la = lc;
        lb = lc;
        la.insertBack(1);
        la.insertBack(5);
        la.insertBack(2);

        lb.insertBack(1);
        lb.insertBack(7);
        lb.insertBack(2);

        cout << isLarger(la, lb) << endl; // 0


    }
    catch(EmptyList){
        std::cout << "Remove from empty list!\n";
    }

    return 0;
}
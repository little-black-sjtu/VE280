#include <iostream>
#include <cstdlib>
using namespace std;

// Classes for exception types. They are just dummy types for you to use when
// handling expections.
// TODO: Define needed classes for exception.
typedef struct market_closed{}MARKET_CLOSED;
// EFFECTS: Check whether there is enough flour in market1. If not, throw
//          how much flour you still want.
void buy_flour(int num_pies, float flour_remain)
{
    // TODO:
    if (flour_remain<num_pies*250.0)
        throw (num_pies*250.0-flour_remain);
}

// EFFECTS: Check whether there are enough eggs in market1. If not, throw
//          how many eggs you still want.
void buy_eggs(int num_pies, int eggs_remain)
{
    // TODO:
    if(eggs_remain<num_pies)
        throw num_pies-eggs_remain;
}

// EFFECTS: Check whether there are enough apples in market2. If not, throw
//          how many apples you still want.
void buy_apples(int num_pies, int apples_remain)
{
    // TODO:
    if(apples_remain<num_pies*2)
        throw num_pies*2-apples_remain;
}

// EFFECTS: Check if market1 is open. If it is open, then go on to buy flour 
//          and eggs. If it is closed, throw a "MARKET1_CLOSED" exception.
// NOTE:    For consistency, please first call buy_flour and then buy_eggs 
//          if market1 is open.
void visit_market1(bool market1_status, int num_pies, float flour_remain, int eggs_remain)
{
    if(market1_status){
        buy_flour(num_pies, flour_remain);
        buy_eggs(num_pies, eggs_remain);
    }
    else{
        MARKET_CLOSED MARKET1_CLOSED;
        throw MARKET1_CLOSED;
    }
}

// EFFECTS: Check if market2 is open. If it is open, then go on to buy apples.
//          If it is closed, throw a "MARKET2_CLOSED" exception.
void visit_market2(bool market2_status, int num_pies, int apples_remain)
{
    if(market2_status)
        buy_apples(num_pies, apples_remain);
    else{
        MARKET_CLOSED MARKET2_CLOSED;
        throw MARKET2_CLOSED;
    }
}



int main(int argc, char* argv[])
{
    int num_pies;           // number of pies you want to make.
    bool market1_status;    // whether market1 is open or closed. 1 for open and 0 for closed.
    bool market2_status;    // whether market2 is open or closed. 1 for open and 0 for closed.
    float flour_remain;     // amount of flour remaining in market1 (in grams).
    int eggs_remain;        // number of eggs remaining in market1.
    int apples_remain;      // number of apples remaining in market2.


    //TODO:
    // Read all the above parameters from the program arguments
    if(argc == 7){
        num_pies = atoi(argv[1]);
        market1_status = atoi(argv[2]);
        market2_status = atoi(argv[3]);
        flour_remain = atof(argv[4]);
        eggs_remain = atoi(argv[5]);
        apples_remain = atoi(argv[6]);
    }
    else exit(0);
    
    // If any expception happens, flag will be changed to 0.
    bool flag = 1;

    // You will first visit market1 and then visit market2. If any exception happens, 
    // your buying process will end.
    cout << "You visit market1 first..." << endl;
    try 
    {
        // TODO:
        visit_market1(market1_status, num_pies, flour_remain, eggs_remain);
        cout << "You've bought enough flour and eggs. Then you visit market2..." << endl;
        try
        {
            // TODO:
            visit_market2(market2_status, num_pies, apples_remain);
            cout << "You've also bought enough apples! You can go home and make the pies now!" << endl;
        }
        catch(MARKET_CLOSED)
        {
            cout << "market2 is closed!" << endl;
            flag = 0;
        }
        catch(int apples)
        {
            cout << "Apples in market2 are not enough. You still need " <<  /* TODO: */ apples << " more." << endl;
            flag = 0;
        }  
    }
    catch(MARKET_CLOSED)
    {
        cout << "market1 is closed!" << endl;
        flag = 0;
    }
    catch(double flour)
    {
        cout << "Flour in market1 is not enough. You still need " <<  /* TODO: */  flour<< " grams more." << endl;
        flag = 0;
    }
    catch(int eggs)
    {
        cout << "Eggs in market1 are not enough. You still need " <<  /* TODO: */  eggs<< " more." << endl;
        flag = 0;
    }

    if (!flag)
        cout << "It seems that today is not a good day for making apple pies." << endl;

    return 0;
}

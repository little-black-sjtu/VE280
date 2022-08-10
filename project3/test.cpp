#include <iostream>
#include "deck.h"
#include "card.h"
#include <string>

using namespace std;

int main(){
    int i=0;
    Deck adeck;  
    adeck.shuffle(39);   
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;
    } 
    cout<<"\n\n";
    adeck.shuffle(22);
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;;
    } 
    cout<<"\n\n";
    adeck.shuffle(33);
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;;
    } 
    cout<<"\n\n";
    adeck.shuffle(37);
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;;
    } 
    cout<<"\n\n";
    adeck.shuffle(38);
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;;
    } 
    cout<<"\n\n";
    adeck.shuffle(37);
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;;
    } 
    cout<<"\n\n";
    adeck.shuffle(38);
    for(i=0;i<DeckSize;i++){
        Card card = adeck.deal();
        cout<<SuitNames[card.suit]<<" "<<SpotNames[card.spot]<<endl;;
    } 

    return 0;
}
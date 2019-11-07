#pragma once
#include <stack>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>
#include <iostream>


enum CardType {INFANTRY = 1, CAVALRY = 2, ARTILLERY = 3, NULLCARD = -1};
static int totalExchanges = 0;

class Deck{
    private:
        //could abstract a util method for random ints
        //to be used in dice and card classes
        std::stack<CardType>* cards;
        CardType genCard();

    public: 
        Deck();
        ~Deck();
        //It doesn't make sense to tightly couple map and deck classes, keep separate
        Deck(int mapSize);
        CardType draw();
        int size();
};
class Hand{
    private:
        std::vector<CardType>* cards;
        
    public:
        int exchange();
        Hand();
        ~Hand();
        bool addToHand(CardType card);
        bool removeFromHand(CardType card);
        bool removeFromHand(CardType card, int quantity);
        std::string cardToString(CardType card);


        //test method remove for prod
        void showHand(){
            std::cout<<"Displaying hand..."<<std::endl;
            for(CardType c : (*cards)){
                std::cout<<cardToString(c)<<std::endl;
            }
        }
};
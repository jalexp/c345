#pragma once
#include "dice.h"
#include "map.h"
#include "cards.h"

class Player{

    private:
        std::string* name;
        std::vector<Country>* territories;
        Dice* dice;
        Hand* hand;
        int* armies;
    public: 
        Player();
        Player(std::string name);
        ~Player();
        void reinforce();
        void attack();
        void fortify();
        void showCountries();
        bool addTerritory(Country c);
        bool hasTerritory(Country c);
        void rollDice();
        void showDiceRecord();
        void assignArmies(int x);



};
#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <limits>
#include <algorithm>

class Dice {

    private: 
        //helper function returns random number between 1 and 6
        int roll(); 
        //helper function prompts Player for number of dice to roll, between 1 and 3
        int promptNumRolls();
        //updates rollValueRecord following dice roll(s)
        int pnr();
        void updateRollRecord();

        int* MAX_ROLL;
        int* MIN_ROLL;
        int* SIDES;
        int* totalRolls;
        //consider the difference between int* rollValueRecord and int* rollValueRecord[]. What ultimate difference
        //does this make?
        int* rollValueRecord;
        //a good idea to declare array size in header? versus using a vector
        //even with a vector, you can only use int pointer as per assignment
        std::vector<int>* dicebox;

    public: 
        Dice();
        //Dice(const Dice* dice);
        ~Dice();

        //outputs percentage values rolled in the game until now
        void showRollValuePercentage();
        //returns pointer to sorted container of random values between 1 and 6
        std::vector<int>* playerRoll();
        //print current values in dicebox
        void showDicebox();
        void showTotalRolls();
        void showRollValueRecord();
        void showRollValuePercentage(int i);

        //to be removed
        void TestpromptnumRolls();
        void Testroll(); 
        void TestplayerRoll();
           
        
};


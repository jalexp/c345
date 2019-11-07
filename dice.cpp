#include "dice.h"


//change these for pointer based dynamic initalizations
Dice::Dice(){
    //what happens when this is empty and we try to print dicebox contents? -> nothing is printed, empty vector?
    //versus initializing with MAX_ROLL as an argument for 3 element vector, all defaulted to 0
    //we can avoid the above issue by using push_back() instead of operator[]
    dicebox = new std::vector<int>(); 
    MAX_ROLL = new int(6);
    MIN_ROLL = new int(1);
    SIDES = new int(6);
    rollValueRecord = new int [*SIDES];
    totalRolls = new int(0);
}

Dice::~Dice() { 
    
    (*dicebox).clear();
    delete dicebox;
    delete MAX_ROLL;
    delete MIN_ROLL;
    delete SIDES;
    delete totalRolls;
    delete [] rollValueRecord;
}
void Dice::showRollValueRecord() {
    std::cout <<"Roll Value Record for this die is: "<<std::endl<<"1 ("<<Dice::rollValueRecord[0]<<")"<<std::endl<<"2 ("<<Dice::rollValueRecord[1]<<")"<<std::endl<<"3 ("<<Dice::rollValueRecord[2]<<")"<<std::endl<<"4 ("<<Dice::rollValueRecord[3]<<")"<<std::endl<<"5 ("<<Dice::rollValueRecord[4]<<")"<<std::endl<<"6 ("<<Dice::rollValueRecord[5]<<")"<<std::endl;
}
void Dice::showTotalRolls() {
    std::cout <<"Total rolls for this die is: "<<*totalRolls<<std::endl;
}
//could have returned sorted container, avoiding returning direct reference
//especially unnecessary for int values
void Dice::showDicebox(){
    std::cout <<"Showing dicebox contents"<<std::endl;
    if((*dicebox).empty()) {
        std::cout <<"This dicebox is empty"<<std::endl;
        return;
    }
    std::sort((*dicebox).begin(),(*dicebox).end());
    for(int i = 0; i < (*dicebox).size(); i++){
        std::cout <<"dicebox["<<i<<"] = "<<(*dicebox)[i]<<std::endl;
    }
}
void Dice::updateRollRecord(){
    std::cout <<"Updating roll record..." << std::endl;
    //check if dicebox is empty first
    for (int i = 0; i < (*dicebox).size(); i++){
        switch((*dicebox)[i]){
            case 1: rollValueRecord[0]++;break;
            case 2: rollValueRecord[1]++;break;
            case 3: rollValueRecord[2]++;break;
            case 4: rollValueRecord[3]++;break;
            case 5: rollValueRecord[4]++;break;
            case 6: rollValueRecord[5]++;break;
            default: std::cout<<"updateRollRecord error"; 
        }
    }
}

std::vector<int>* Dice::playerRoll(){
    //if deciding to use push_back, don't forget to clear the vector for each roll
    //if using operator[], only the values must be cleared
    (*dicebox).clear(); 
    //int dice = promptNumRolls();
    //pnr exists for testing until input validation method is complete
    int dice = pnr();
    //check if dicebox is null
    for(int i = 0;i < dice; i++){
        ((*dicebox)).push_back(roll());
        (*totalRolls)++;
    }
    updateRollRecord(); 
    std::sort((*dicebox).begin(), (*dicebox).end());
    //DOESN'T THIS DEFEAT THE PURPOSE OF ENCAPSULATION? Remove, change signature to void for prod
    return dicebox;
}


int Dice::roll(){

    //referenced from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> distribution(1,6);

    return distribution(gen);
}
//test method - replace with promptNumRolls() for production
int Dice:: pnr() {
    std::cout <<"Enter number of dice to roll between 1 and 3, inclusive:"<<std::endl;
    int numRolls;
    std::cin>>numRolls;
    if((numRolls != 1 && numRolls != 2 && numRolls!= 3)){
        return pnr();
    }
    return numRolls;
}
void Dice::showRollValuePercentage(int i){
    if(totalRolls == 0){
        std::cout <<"No rolls yet!"<<std::endl;
        return;
    }
    std::cout <<"Roll Value Percentage of "<<i<<" is..."<<std::endl;
    switch(i){
        case 1:std::cout <<"(1): "<<(((float) rollValueRecord[0]) / *totalRolls)<<std::endl;break;
        case 2:std::cout <<"(2): "<<(((float) rollValueRecord[1]) / *totalRolls)<<std::endl;break;
        case 3:std::cout <<"(3): "<<(((float) rollValueRecord[2]) / *totalRolls)<<std::endl;break;
        case 4:std::cout <<"(4): "<<(((float) rollValueRecord[3]) / *totalRolls)<<std::endl;break;
        case 5:std::cout <<"(5): "<<(((float) rollValueRecord[4]) / *totalRolls)<<std::endl;break;
        case 6:std::cout <<"(6): "<<(((float) rollValueRecord[5]) / *totalRolls)<<std::endl;break;
        default: std::cout <<"Invalid argument :: Must be between 1 and 6"<<std::endl;
    }
}
int Dice::promptNumRolls(){
    
    //separate isValidRoll into its own private function  
    bool isValid = false;
    while(!isValid) {
        int input;
        //replace vals with min max roll constants
        std::cout << "Enter the desired number of dice to be rolled.\nMust be between 1 and 3\n";
        while(!(std::cin >> input) || !isValid) {
            if (input != 1 && input != 2 && input !=3)  {
             std::cout<<"Invalid entry, Must be between 1 and 3.\n";
             std::cin.clear();
             //read api 
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
             isValid = true;
            }
        }
    }
}

void Dice::TestplayerRoll() {
    std::cout << "Testing playerRoll():\n";
    std::cout << "Checking initial values of dicebox...\n";
    showDicebox();
    playerRoll();
    std::cout << "Checking final values of dicebox...\n";
    showDicebox();
}
void Dice::TestpromptnumRolls() {

    std::cout<<"Testing promptNumRolls():\n";
            int r = promptNumRolls();
            std::cout <<"Result of promptNumRolls: "<<r<<std::endl;
}

void Dice::Testroll() {
    int result = roll();
    std::cout <<"Testing result of roll(): "<<result<<std::endl;
}


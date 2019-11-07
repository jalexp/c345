#include "cards.h"

Deck::Deck(){
    cards = new std::stack<CardType>();
}
Deck::~Deck(){
    delete cards;
}
Deck::Deck(int mapSize){
    cards = new std::stack<CardType>();    
    for(int i = 0; i < mapSize; i++){
        (*cards).push(genCard());
    }
}
CardType Deck::draw(){
    CardType card = (*cards).top();
    (*cards).pop();
    return card;
}
CardType Deck::genCard(){
    //referenced from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> distribution(1,3);

    switch(distribution(gen)){
        case 1: return INFANTRY;
        case 2: return CAVALRY;
        case 3: return ARTILLERY;
        default: return NULLCARD;
    }
}
int Deck::size(){
    if((*cards).empty())
        return 0;
    return (*cards).size();
}
Hand::Hand(){
    cards = new std::vector<CardType>();
}
Hand::~Hand(){
    delete cards;
}
bool Hand::addToHand(CardType card){
    if(card != NULLCARD){
        (*cards).push_back(card);
        return true;
    }
    else
    {
        std::cout<<"Error: NULLCARD detected. Aborting..."<<std::endl;
        return false;
    }
    
}
std::string Hand::cardToString(CardType card){
            switch(card){
                case INFANTRY: return "INFANTRY";break;
                case CAVALRY: return "CAVALRY";break;
                case ARTILLERY: return "ARTILLERY";break;
                default : return "ERROR in Card to String conversion";break;
            }
}
bool Hand::removeFromHand(CardType cardToRemove){

    for(int i = 0;i < (*cards).size(); i++){
        //showHand();
        std::cout<<"value of i:"<<i<<std::endl;
        if((*cards)[i] == cardToRemove){
            std::cout<<"(*cards)["<<i<<"]: "<<cardToString((*cards)[i])<<" cardToRemove: "<<cardToString(cardToRemove)<<std::endl;
            std::cout<<"Removing card "<<cardToString((*cards)[i])<<std::endl;            
            (*cards).erase((*cards).begin()+i);
            return true;
        }
    }
    std::cout<<"Card "<<cardToString(cardToRemove)<<" does not exist in hand"<<std::endl;
    return false;
    
}
//removes card [0 - quantity] number of times from hand 
bool Hand::removeFromHand(CardType cardToRemove, int quantity){
    //add a check to make sure its possible before removing
    for(int i = 0; i < quantity; i++){
        removeFromHand(cardToRemove);
    }
}
int Hand::exchange(){
    //refactor into separate private count() method
    //can also be refactored to use a for-loop so that removals are executed 
    //as soon as the first exchange condition is satisfied
    //AREN'T INTEGERS SUPPOSED TO DEFAULT INITIALIZE TO ZERO? int numInf was evaluating to 21049 etc.etc.
    int numInf = 0;
    int numCav = 0;
    int numArt = 0;
    for(CardType card : *cards){
        switch(card){
            case INFANTRY: numInf++;break;
            case CAVALRY: numCav++;break;
            case ARTILLERY: numArt++;break;
            default: std::cout<<"Error in exchange(): invalid card"<<std::endl;exit(1);
        }
    }
    std::cout<<"numInf["<<numInf<<"] numCav["<<numCav<<"] numArt["<<numArt<<"]"<<std::endl;
    if (numInf >= 3){
        removeFromHand(INFANTRY, 3);
    }  
    else if (numCav >= 3){
        removeFromHand(CAVALRY, 3);
    }
    else if (numArt >= 3){
        removeFromHand(ARTILLERY, 3);
    }
    else if(numInf >= 1 && numArt >= 1 && numCav >= 1){
        removeFromHand(INFANTRY);
        removeFromHand(CAVALRY);
        removeFromHand(ARTILLERY);
    }
    else
    {
        std::cout<<"No exchange of cards can be made with this hand"<<std::endl;
        return 0;
    }
    
    int armiesToReturn = 0;
    if(totalExchanges == 0)
        armiesToReturn = 5;
    else
        armiesToReturn = totalExchanges * 5 + 5;
    
    totalExchanges++;
    std::cout<<"["<<totalExchanges<<"] totalExchanges to date"<<std::endl;
    return armiesToReturn;
}
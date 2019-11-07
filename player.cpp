#include "player.h"

Player::Player(){
    name = new std::string("This Player Has No Name");
    territories = new std::vector<Country>();
    dice = new Dice();
    hand = new Hand();
}
Player::Player(std::string name){
    this->name = new std::string(name);
    territories = new std::vector<Country>();
    dice = new Dice(); 
    hand = new Hand();
}
Player::~Player(){
    delete dice;
    delete hand;
    (*territories).clear();
    delete territories;
    delete name;
}
void Player::reinforce(){
    std::cout <<*name<<" is reinforcing!"<<std::endl;
}
void Player::attack(){
    std::cout <<*name<<" is attacking!"<<std::endl;
}

void Player::fortify() {
    std::cout <<*name<<" is fortifying!"<<std::endl;
}

bool Player::addTerritory(Country c){
    if((*this).hasTerritory(c)){
        std::cout <<"Aborting..."<<std::endl;
        return false;
    }
    std::cout <<"Adding country "<<c.getCountryName()<<" to territories of player "<<*name<<std::endl;
    (*territories).push_back(c);
    return true;

}
bool Player::hasTerritory(Country c){
    for(int j =0; j< (*territories).size();j++){
        if(c.getCountryName() == (*territories)[j].getCountryName()){
            std::cout <<"Player "<<*name<<" already has territory "<<c.getCountryName()<<std::endl;
            return true;
        }
    }
    return false;
}
void Player::showCountries(){
    if((*territories).empty()){
        std::cout <<"Player "<<*name<<" owns no territory."<<std::endl;
        return;
    }
    std::cout <<*name<<" current controls territories: "<<std::endl;
    for(int i =0; i < (*territories).size();i++){
        std::cout <<(*territories)[i].getCountryName()<<std::endl;
    }
}
void Player::rollDice(){
    (*dice).playerRoll();
}
void Player::showDiceRecord(){
    std::cout <<"Player "<<*name<<"'s dice record: "<<std::endl;
    (*dice).showRollValueRecord();
}
void Player::assignArmies(int x) {
	int armiesAvailable = x;
	// first put an army in each country.
	while (armiesAvailable > 0) {
		for (Country c : *territories) {
			c.incrementArmies(1);
			--armiesAvailable;
		}
	}
}
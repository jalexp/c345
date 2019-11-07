#include "player.h"

int main() {

    Player p1("Johnny");
    p1.showCountries();
    Country c1("Ireland");
    p1.showCountries();
    p1.addTerritory(c1);
    p1.addTerritory(c1);//add same country twice
    p1.showCountries();
    p1.attack();
    p1.showDiceRecord();
    p1.rollDice();
    p1.showDiceRecord();
}
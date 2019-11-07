#include "dice.h"


int main() {

    Dice d1,d2,d3;
    
    
    //d.TestpromptnumRolls();
    for(int i = 0; i < 5; i++) {
        d1.Testroll();
    }
    d1.TestplayerRoll();
    d1.TestplayerRoll();
    d1.TestplayerRoll();
    d1.showRollValueRecord();
    d1.showDicebox();
    d1.showRollValuePercentage(2);

}
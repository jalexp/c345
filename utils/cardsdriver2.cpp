#include "cards.h"

int main(){

    // Create three hands, add a bunch of cards to each, call exchange on each to verify 
    // the correct cards were removed, and then output the number of armies received from
    // each exchange() call

    Hand h1;
    Hand h2;
    Hand h3;

    h1.addToHand(INFANTRY);
    h1.addToHand(CAVALRY);
    h1.addToHand(INFANTRY);
    h1.addToHand(ARTILLERY);
    h1.addToHand(CAVALRY);
    h1.showHand();
    int armies1 = h1.exchange();
    h1.showHand();
    std::cout<<"["<<armies1<<"] armies returned from exchange()"<<std::endl;

    h2.addToHand(CAVALRY);
    h2.addToHand(CAVALRY);
    h2.addToHand(ARTILLERY);
    h2.addToHand(INFANTRY);
    h2.addToHand(INFANTRY);
    h2.addToHand(ARTILLERY);
    h2.addToHand(CAVALRY);
    h2.showHand();
    int armies2 = h2.exchange();
    h2.showHand();
    std::cout<<"["<<armies2<<"] armies returned from exchange()"<<std::endl;

    h3.addToHand(ARTILLERY);
    h3.addToHand(ARTILLERY);
    h3.addToHand(ARTILLERY);
    h3.addToHand(CAVALRY);
    h3.showHand();
    int armies3 = h3.exchange();
    h3.showHand();
    std::cout<<"["<<armies3<<"] armies returned from exchange()"<<std::endl;

}
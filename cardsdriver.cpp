#include "cards.h"
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    

    // Demonstrate creating a random deck with a uniform card type distribution


    int numCards = 100;
    int possibleResults = 4;
    
    Deck deck(numCards);
    //why does using the possibleResults variable here mess everything up?
    //PRIORITY ASK
    int results[4];
    int initialDeckSize = deck.size();
    cout<<"Initial deck size: "<<initialDeckSize<<endl;
    //don't forget that as you pop elements, deck.size() will change
    for (int i = 0; i < initialDeckSize; i++)
    {
        switch (deck.draw())
        {
        case INFANTRY:
            results[0]++;
            break;
        case CAVALRY:
            results[1]++;
            break;
        case ARTILLERY:
            results[2]++;
            break;
        default:
            results[3]++;
        }
    }
    
    cout <<"#Infantry: "<<results[0]<<endl<< " %Infantry: " << (float)results[0] / numCards << endl;
    cout <<"#Cavalrys: "<<results[1]<<endl<< " %Cavalry: " << (float)results[1] / numCards << endl;
    cout <<"#Artillery: "<<results[2]<<endl<<" %Artillery: " << (float)results[2] / numCards << endl;
    cout <<"#NullCard: "<<results[3]<< endl<<" %NullCard: " << (float)results[3] / numCards << endl;
    
    cout<<"********************************************************************************"<<endl;
    cout<<"********************************************************************************"<<endl;
    
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
    cout<<"["<<armies1<<"] armies returned from exchange()"<<endl;

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
    cout<<"["<<armies2<<"] armies returned from exchange()"<<endl;

    h3.addToHand(ARTILLERY);
    h3.addToHand(ARTILLERY);
    h3.addToHand(ARTILLERY);
    h3.addToHand(CAVALRY);
    h3.showHand();
    int armies3 = h3.exchange();
    h3.showHand();
    cout<<"["<<armies3<<"] armies returned from exchange()"<<endl;

    cout<<"********************************************************************************"<<endl;
    cout<<"********************************************************************************"<<endl;

    // Create a deck, draw cards from the deck into a hand, verify cards drawn are random

    Deck deck2(100);
    Hand hand4;
    hand4.addToHand(deck2.draw());
    hand4.addToHand(deck2.draw());
    hand4.addToHand(deck2.draw());
    hand4.showHand();

}
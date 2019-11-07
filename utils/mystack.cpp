#include <iostream>
#include <stack>
#include <random>
#include <limits>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;

int randomInt(int begin, int end);
enum CardType {INFANTRY=1, ARTILLERY=2, CAVALRY=3};
CardType getCard();

int main(int argc, char* argv[]){

    std::vector<int> vals;
    for(int i = 1; i < 10; i++)
        vals.push_back(i);

    vals.erase(vals.begin() + 4);
    for(int val : vals){
        cout<<val<<" "<<endl;
    }
}

int randomInt(int begin, int end){

    //referenced from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> distribution(begin,end);

    return distribution(gen);
}
CardType getCard(){
    
    switch(randomInt(1,3)){
        case 1: return INFANTRY;
        case 2: return CAVALRY;
        case 3: return ARTILLERY;
        
    }
}
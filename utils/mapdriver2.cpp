#include "map.h"
#include "dice.h"
#include "player.h"


int main(int argc, char* argv[]){

    // Create several countries
    Country c1("Canada");
    Country c2("Mexico");
    Country c3("USA");
    Country c4("Venezuela");
    Country c5("Morocco");
    Country c6("Egypt");
    Country c7("Portugal");
    std::vector<Country> countries;
    countries.push_back(c1);countries.push_back(c2);countries.push_back(c3);countries.push_back(c4);countries.push_back(c5);countries.push_back(c6);countries.push_back(c7);
    
    // Connect certain countries by assigning neighbours, verify
    c1.addNeighbour(c2);
    c2.addNeighbour(c4);
    c2.addNeighbour(c4); //Add country which already exists as a neighbour -->Country rejection
    c3.addNeighbour(c4);
    c5.addNeighbour(c6);
    for(Country &c : countries){
        c.showNeighbours();
    }

    // Create several continents, display contents
    Continent con1("NorthAmerica");
    Continent con2("SouthAmerica");
    Continent con3("Africa");
    Continent con4("Europe");
    con1.addCountry(c1);
    con1.addCountry(c2);
    con1.addCountry(c3);
    con1.addCountry(c2); //Add country that already exists on continent --> Continent rejection
    con2.addCountry(c4);
    con3.addCountry(c5);
    con3.addCountry(c6);
    con4.addCountry(c7);
    con4.addCountry(c6); //Add same country to two continents --> Map rejection
    con1.showCountries();
    con2.showCountries();
    con3.showCountries();
    con4.showCountries();

    // Create map, add continents, display
    Map m;
    m.addContinent(con1);
    m.addContinent(con2);
    m.addContinent(con3);
    m.addContinent(con4);
    m.describeMap();
    std::cout<<"map size: " <<m.size()<<std::endl;

    std::cout<<"*******************************************************"<<std::endl<<std::endl;


}
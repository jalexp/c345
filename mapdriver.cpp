#include "map.h"

int main() {

    Map m1("Map1");
    Continent c1("Europe");
    Continent c2("Europe"); //testing adding the same continent with different variables
    Continent c3("Africa");
    Continent c4("Asia");
    Country country1("France");
    Country country2("Morocco");
    Country country3("Italy");
    Country country4("Switzerland");
    Country country5("Thailand");
    Country country6("China");
    Country country7("Japan");
    c1.addCountry(country1);
    c1.addCountry(country3);
    c1.addCountry(country4);
    c3.addCountry(country2);
    c3.addCountry(country2); //trying to add the same country twice
    c4.addCountry(country5);
    c4.addCountry(country6);//adding same country to multiple continents(wait for final output)
    c4.addCountry(country7);//notice how Asia is not added to map because of duplicate
    c3.addCountry(country7); //testing adding a continent with a country that already exists in the map
    m1.addContinent(c1);
    m1.addContinent(c1);//trying to add the same continent twice
    m1.addContinent(c2); //nice, country verification works regardless of variable
    m1.addContinent(c3);
    m1.addContinent(c4);
    m1.showContinents();
    m1.describeMap();
    std::cout<<"map size: " <<m1.size()<<std::endl;
}
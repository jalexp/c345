#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class Country {

    private:
        int* id;
        std::string* name;
        std::vector<Country>* neighbours;
        int* contId;
        int* countryArmies;
        //Continent* continent;

    public:
        Country();
        //Country(const Country &other);
        //~Country();
        Country(std::string n);
        Country(int id,std::string name);
        Country(int id, std::string name, int continentId);
        bool addNeighbour(Country neighbour);
        bool hasNeighbour(Country n);
        void showNeighbours();
        std::string getCountryName();
        int getCountryId();
        int getCountryContId();
        //may delete :: searches list of countries for an id and if found, returns its index
        //returns -1 if no country with the specified id is found
        static int findCountryWithId(std::vector<Country> countries, int id);
        void incrementArmies();
};
class Continent {

    private:
        int* id;
        std::string* name;
        std::vector<Country>* countryList;
        //std::vector<Continent>* continentNeighbours;
        int* armies;
    public:
        Continent();
        //Continent(const Continent &cont);
        //~Continent();
        Continent(std::string name);
        Continent(int id, std::string name, int numArmies);
        bool addCountry(Country c);
        bool hasCountry(Country c);
        bool hasCountryByName(std::string cName);
        std::string getContinentName();
        int getContinentId();
        int getContinentNumArmies();
        std::vector<std::string> getCountryNames();
        void showCountries();
};

class Map{

    private:
        std::string* name;
        std::vector<Continent>* continentList;
        //feeling dicey returning a pointer hmm
        //watch out for the null pointer reference
        Continent* findContinentById(int id);
    public:

        Map();
        //~Map();
        Map(std::string name);
        int size();
        bool addContinent(Continent c);
        bool hasContinent(Continent c);
        void showContinents();
        void describeMap();
};
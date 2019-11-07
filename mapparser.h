#pragma once
#include "map.h"
#include <sstream>
#include <cctype>
//parses map files based on the loose .map format as seen in examples on SourceForge:Domination game
//necessary formatting must include: 
//[continents]->{name,armies,#implicit_number}, [countries]->{id,name,#continentNum,}, [borders] headers IN THAT ORDER
//Might be worth composing Map objects with their own MapParser member

// This class can be overhauled and converted to static Utils methods(map utils class) as 
// no instance of mapparser is conceivably necessary
class MapParser{

    private:
        //unnecessary, may refactor to use later
        std::string* mapFile;
        std::vector<std::vector<int> > parseBorders(std::vector<std::string> borderStrings);
        std::vector<Country> parseCountries(std::vector<std::string> countryStrings);
        std::vector<Continent> parseContinents(std::vector<std::string> continentStrings);
        std::vector<Continent> parseCont(std::vector<std::string> continentStrings);
        //later split into StringUtils class
        std::vector<std::string> split(std::string);
    public:
        MapParser();
        MapParser(std::string filename);
        Map parseMap(std::string filename);
        //these methods are public for testing purposes. return to private for production 
        std::string promptMapFileString();
        bool hasMapExt(std::string filename);
        bool isAlphaStr(std::string s);
        bool isNumStr(std::string s);
};
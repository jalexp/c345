#include "mapparser.h"
#include <limits>
#include <fstream>
//#include <streamsize>

MapParser::MapParser(){
    mapFile = new std::string("No file provided");
}
//might refactor later
// MapParser::MapParser(std::string filename){
//     mapFile = new std::string(filename);
// }
std::string MapParser::promptMapFileString(){
    std::string filename;
    MapParser mp;

    std::cout <<"Enter the name of a valid *.map file"<<std::endl;
    std::cin >> filename;
    std::cout <<"Validating..."<<std::endl;
    while(!mp.hasMapExt(filename)) {
        std::cout <<"Invalid filename entered. Try again"<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin>>filename;
        std::cout <<"Validating..."<<std::endl;
    }
    std::cout <<"Success!"<<std::endl;
    return filename;   
}
bool MapParser::hasMapExt(std::string filename){
    //make sure filename is long enough, if not 5 char or more, invalid filename
    
    std::string ext = ".map";
    
    std::cout <<"Extension of file: "<<filename.substr(filename.length() - 4)<<std::endl;
    //check last four characters
    return filename.substr(filename.length() - 4) == ext;
}
//change name to reflect allowing underscores?
//check for empty string behaviour
bool MapParser::isAlphaStr(std::string str){
    if(str.empty())
        return false;
    for(int i = 0; i < str.length(); i++){
        if (!(isalpha(str[i]) || str[i] == '_')){
            std::cout <<"Non alpha character "<<str[i]<<" found in "<<str<<std::endl;
            return false;
        }
    }
    return true;
}
bool MapParser::isNumStr(std::string str){
    if (str.empty()){
        std::cout <<"String is empty :: isNumStr()"<<std::endl;
        return false;
    }
    for(int i = 0; i<str.length(); i++){
        if(!(isdigit(str[i]))){
            std::cout <<"Non numeric character "<<str[i]<<" found in "<<str<<std::endl;
            return false;
        }
    }
    //did you really forget to return true?
    //wow. you did.
    //let it be known that it is possible not to return a value with boolean functions
    //or rather, it will default to false
    return true;
}
std::vector<std::string> MapParser::split(std::string s){
    std::vector<std::string> result;
    std::string delim = " ";
    //case for s == ""
    //account for single char string, or string without any spaces
    //note that spaces will be read in as tokens, there needs to be some kind of validation for each value passed to the constructor
    //ie. is alpha(), is isdigit(), no extra spaces etc 
    if(s.find(delim) == std::string::npos) {
        result.push_back(s);
        return result;
    }
    while(s.find(delim) != std::string::npos){
        
        int idx;
        int cursor = 0;
        idx = s.find(delim);
        result.push_back(s.substr(cursor,idx));
        cursor = idx + 1;
        s = s.substr(cursor);
        if(s.find(delim) == std::string::npos){
            result.push_back(s.substr(0));
        }
    }
    return result;
}

std::vector<Continent> MapParser::parseCont(std::vector<std::string> contStrings){

    std::vector<Continent> result;
    std::vector<std::string> tokens;
    //constants, can change to all caps later
    int contNameIndex = 0;
    int contArmiesIndex = 1;
    std::string contName;
    int contArmies;
    
    for(int i = 0;i<contStrings.size();i++){

        tokens = split(contStrings[i]);
        for (int u = 0; u < tokens.size(); u++){
            std::cout <<tokens[u]<<std::endl;
        }

        if(isAlphaStr(tokens[contNameIndex])){
            contName = tokens[contNameIndex];
        }
        else{
            std::cout <<"Error::Invalid Continent Format Exception"<<std::endl;
            std::cout <<"Aborting..."<<std::endl;
            exit(0);}
        
        try {
            contArmies = std::stoi(tokens[contArmiesIndex]);
        }
        catch(const std::invalid_argument& e){
            std::cout <<"Invalid Continent Army Format. Values must be positive integers"<<e.what()<<std::endl;
        }
        Continent c(i+1, contName, contArmies);
        result.push_back(c);
    }
    return result;
}
std::vector<Country> MapParser::parseCountries(std::vector<std::string> countStrings){
    std::vector<Country> result;
    std::vector<std::string> tokens;
    //constants, can change to all caps later
    int countryIdIndex = 0;
    int countryNameIndex = 1;
    int countryContinentIndex = 2;
    int countryId;
    std::string countryName;
    int countryContinent;

    for(int i = 0;i<countStrings.size();i++){

        tokens = split(countStrings[i]);
        for (int u = 0; u < tokens.size(); u++){
            std::cout <<tokens[u]<<std::endl;
        }

        //stoi(int) works for C++11 onwards

        try{ countryId = std::stoi(tokens[countryIdIndex]);}
        catch(const std::invalid_argument e){std::cout <<"Invalid CountryId Format. Values must be positive integers."<<std::endl;}
        
        try{countryContinent = std::stoi(tokens[countryContinentIndex]);}
        catch(const std::invalid_argument e){std::cout <<"Invalid CountryContinentId Format. Values must be positive integers."<<std::endl;}

        if(isAlphaStr(tokens[countryNameIndex])){
            countryName = tokens[countryNameIndex];
        }
        else{
            std::cout <<"Error::Invalid Country Format Exception"<<std::endl;
            std::cout <<"Aborting..."<<std::endl;
            exit(0);
        }
         
        Country c(countryId,countryName,countryContinent);
        result.push_back(c);
    }
    return result;
}

std::vector<std::vector<int> > MapParser::parseBorders(std::vector<std::string> borStrings){
    std::vector<std::string> tokens;
    std::vector<std::vector<int> > result;

    for(int i = 0; i < borStrings.size(); i++){
        std::vector<int> borders;
        tokens = split(borStrings[i]);
        for(int n = 0; n < tokens.size();n++){
            int val;
            try {
                val = std::stoi(tokens[n]);
            }
            catch(const std::invalid_argument& e){
                std::cout <<"Invalid Border Format. Values must be positive integers"<<e.what()<<std::endl;
            }
            if(val < 0){
                std::cout <<"Invalid Border Format. Values must be positive integers.Aborting..."<<std::endl;
                exit(0);
            }
            else
                borders.push_back(val);
        }
        result.push_back(borders);
    }

    return result;
}
    
 


//method should throw map parsing exception if a suitable map cannot be generated
//WATCH OUT FOR CONTINENTS WITH SPACES ie. NORTH AMERICA -->Reject spaces in favor of underscores as per map file specification
Map MapParser::parseMap(std::string filename){
    Map map(filename);
    std::string CONTINENT_FLAG = "[continents]",COUNTRY_FLAG = "[countries]",BORDER_FLAG = "[borders]";
    std::vector<std::string> contVec, countVec, borVec;

    std::string line;
    std::ifstream inStream;
    std::cout <<"Attempting to parse Map: "<<filename<<std::endl;
    inStream.open(filename);
    if(!inStream.is_open()){
        //throw MapLoaderError
        std::cout <<"Error opening map file. Aborting..."<<std::endl;
        exit(0);
    }
    else{
        while(getline(inStream,line)){
            std::cout <<"First getline(): "<<line<<std::endl;
            if(line.find(CONTINENT_FLAG) != std::string::npos){
                while(getline(inStream,line) && line.find_first_not_of("\n\t\v\r") != std::string::npos){
                    // while(line.length() == 0){
                    //     getline(inStream,line);
                    // }
                    std::cout <<"Second getline(): "<<line<<std::endl;
                    contVec.push_back(line);
                }
            }
            if(line.find(COUNTRY_FLAG) != std::string::npos){
                while(getline(inStream,line) && line.find_first_not_of("\n\t\v\r") != std::string::npos){
                    std::cout <<"Third getline(): "<<line<<std::endl;
                    countVec.push_back(line);
                }
            }
            if(line.find(BORDER_FLAG) != std::string::npos){
                while(getline(inStream,line) && line.find_first_not_of("\n\t\v\r") != std::string::npos){
                    std::cout <<"Fourth getline(): "<<line<<std::endl;
                    borVec.push_back(line);
                }
            }
        }
    }

    //replace this with a Map constructor that accepts a vector of continents and replace 
    //std::vector<Continent> continents = parseContinents(contVec);
    //could also add a batch method for adding continents to a Map
    std::vector<Continent> continents = parseCont(contVec);
    for(int h = 0;h<continents.size();h++){
        map.addContinent(continents[h]);
    }

    //When refactoring -->Separate all following methods into MapBuilder class
    //to separate process of parsing map and subsequent building of map
    std::vector<Country> countries = parseCountries(countVec);
    //move to method bundle for prod
    for(Country c : countries){
        for(Continent con : continents){
            if(c.getCountryContId() == con.getContinentId()){
                con.addCountry(c);
            }
        }
    }
    std::vector<std::vector<int> > borders = parseBorders(borVec);
    //check that all countryIds are valid using findCountryWithId and looping 
    for(std::vector<int> border : borders){
        for(int b : border){
            if(Country::findCountryWithId(countries, b) == -1){
                std::cout <<"Border Value Error. No CountryId exists for Border Value: "<<b<<std::endl;
            }
        }
    }
    //remove for prod
    std::cout <<"Displaying border lists:"<<std::endl;
    for(std::vector<int> v : borders){
        std::cout <<"Border Values:"<<std::endl;
        for(int b : v){
            std::cout <<b<<" ";
        }
        std::cout <<std::endl;
    }

    int countryIdIndex = 0;
    //replace with more efficient use of pointer-based --> findById(vector<Country>) methods
    //does this need to be executed before countries are added to continent?
    for(std::vector<int> border : borders){
        //if border->Country has no borders, skip
        if(border.size() == 1)
            continue;
        for(Country c : countries){
            if(border[countryIdIndex] == c.getCountryId()){
                for(int b = countryIdIndex+1; b<border.size();b++){
                    int cIndex = Country::findCountryWithId(countries,border[b]);
                    c.addNeighbour(countries[cIndex]);
                }
            }
        }
    }
    
    inStream.close();
    return map;
}
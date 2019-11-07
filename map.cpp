#include "map.h"

void Country::incrementArmies(){
    (*countryArmies)++;
}
Country::Country() {
    id = new int(0);
    name = new std::string("Nameless Country");
    neighbours = new std::vector<Country>();
    countryArmies = new int(0);
    contId = new int(0);
}
// Country::~Country() {
//     (*neighbours).clear();
//     delete neighbours;
//     delete id;
//     delete contId;
//     delete name;
//     delete countryArmies;
// }
Country::Country(std::string n) {
    id = new int(0);
    name = new std::string(n);
    neighbours = new std::vector<Country>();
    countryArmies = new int(0);
    contId = new int(0);
}
Country::Country(int id, std::string name) {
    this->id = new int(id);
    this->name = new std::string(name);
    this->neighbours = new std::vector<Country>();
    this->contId = new int(0);
    this->countryArmies = new int(0);

}
//remove this constructor? Should not generally be able to set ID. first
//check where it is used
Country::Country(int id, std::string name, int contId){
    this->id = new int(id);
    this->name = new std::string(name);
    this->neighbours = new std::vector<Country>();
    this->contId = new int(contId);
    countryArmies = new int(0);
}
bool Country::hasNeighbour(Country n){
    //check if neighbours is empty
    //was not working because lack of iteration -- updated
    std::string nName = *(n.name);
    for(int i = 0; i < (*neighbours).size(); i++){
        if(nName == *(*neighbours)[i].name) {
            std::cout <<nName<<" is already a neighbour of  "<<*name<<std::endl;
            return true;
        }
    }
    std::cout <<nName<<" is not a neighbour of "<<*name<<std::endl;
    return false;
}
bool Country::addNeighbour(Country n){
    std::string nName = *(n.name);   
    std::cout <<"Neighbour name: "<<nName<<std::endl;
    std::cout <<"Country name: "<<*name<<std::endl;
    //check neighbour does not already exist
    if((*this).hasNeighbour(n))
        return false;
    if (nName == *name) {
            std::cout <<"A country cannot neighbour itself"<<std::endl;
            return false;
    }
    std::cout <<"Adding "<< nName << " to list of "<<*name<<"'s  neighbours"<<std::endl;
    (*neighbours).push_back(n);
    (*(n.neighbours)).push_back(*this);
    return true;
}

void Country::showNeighbours() {
    //size() == 0 is returning strange results. change to empty()
    if((*neighbours).empty()) {
        std::cout <<*name <<" has no neighbours"<<std::endl;
        return;
    }
    std::cout <<"Neighbours of " << *(this->name)<<": "<<std::endl;
    for(int i = 0; i < neighbours->size(); i++){
        std::cout <<i+1<<": "<<*((*neighbours)[i].name)<<std::endl;
    }
}
std::string Country::getCountryName(){
    return *name;
}
int Country::getCountryContId(){
    return *contId;
}
int Country::getCountryId(){
    return *id;
}
//the fear of returning direct references has taken over
//worth discussing when and when not to's
int Country::findCountryWithId(std::vector<Country> countries, int id){
    for(int i = 0; i < countries.size();i++){
        if(id == countries[i].getCountryId())
            return i;
    }
    return -1;
}

Continent::Continent() {
    id = new int(0);
    name = new std::string("Nameless continent");
    countryList = new std::vector<Country>();
    armies = new int(0);
}
Continent::Continent(std::string n) {
    id = new int(0);
    name = new std::string(n);
    countryList = new std::vector<Country>();
    armies = new int(0);
}
// Continent::~Continent(){
//     delete id;
//     delete name;
//     (*countryList).clear();
//     delete countryList;
//     delete armies;
//     //(*continentNeighbours).clear();
//     //delete continentNeighbours;
// }
Continent::Continent(int id, std::string name, int numArmies){
    //why is 'this' required here?
    //is it because of a possible variable name conflict with parameters?
    this->id = new int(id);
    this->name = new std::string(name);
    this->countryList = new std::vector<Country>();
    this->armies = new int(numArmies);
}
//DESTRUCTORS NEED TO BE ADDED FOR CLEANING UP ALL THIS DYNAMIC ALLOCATION
std::string Continent::getContinentName(){
    return *name;
}
std::vector<std::string> Continent::getCountryNames(){
    std::vector<std::string> v;
    for(int i = 0; i < (*countryList).size();i++){
        v.push_back((*countryList)[i].getCountryName());
    }
    return v;
}
bool Continent::hasCountry(Country c){
    //check if continent is empty
    if((*countryList).empty()){
        std::cout <<"Continent "<<*name<<" is empty"<<std::endl;
        return false;
    }
    for(int i = 0;i<(*countryList).size();i++){
        if((*countryList)[i].getCountryName() == c.getCountryName() && (*countryList)[i].getCountryId() == c.getCountryId())
            return true;
    }
    return false;
}
bool Continent::hasCountryByName(std::string cName){
    //check if continent is empty
    if((*countryList).empty()){
        std::cout <<"Continent "<<*name<<" is empty"<<std::endl;
        return false;
    }
    for(int i = 0;i<(*countryList).size();i++){
        if((*countryList)[i].getCountryName() == cName)
            return true;
    }
    return false;
}
bool Continent::addCountry(Country c){
    if((*this).hasCountry(c)){
        std::cout <<"Continent "<<*name<<" already contains country "<<c.getCountryName()<<std::endl<<"Aborting..."<<std::endl;
        return false;
    }
    std::cout <<"Adding country "<<c.getCountryName()<<" to continent "<<*name<<std::endl;
    (*countryList).push_back(c);
}
int Continent::getContinentId(){
    return *id;
}
int Continent::getContinentNumArmies(){
    return *armies;
}
void Continent::showCountries(){
    std::cout<<"Continent: "<<*name<<std::endl;
    for (Country c : *countryList){
        std::cout<<'\t'<<c.getCountryName()<<std::endl;
    }
}

Map::Map(){

    Map::name = new std::string("Nameless Map");
    Map::continentList = new std::vector<Continent>;
}
// Map::~Map(){
//     delete name;
//     (*continentList).clear();
//     delete continentList;
// }
Map::Map(std::string name){
    Map::name = new std::string(name);
    Map::continentList = new std::vector<Continent>();
}
//beware the null pointer reference. make this robust
//if continent not found, throw ContinentDNE Exception?
Continent* Map::findContinentById(int id){
    for(int i = 0; i < (*continentList).size(); i++){
        if((*continentList)[i].getContinentId() == id){
            return &((*continentList)[i]);
        }
    }
    return NULL;
}
void Map::showContinents(){
    std::cout <<"Map "<<*name<<" contains continent(s): "<<std::endl;
    for(int i = 0;i < (*continentList).size(); i++){
        std::cout <<i+1<<": "<<(*continentList)[i].getContinentName()<<std::endl;
    }
}
void Map::describeMap(){
    std::cout <<"Map "<<"\t"<<*name<<std::endl<<"\tContinents "<<std::endl;
    for(int i =0;i<(*continentList).size();i++){
        std::cout <<"\t\t"<<(*continentList)[i].getContinentName()<<" {Armies: "<<(*continentList)[i].getContinentNumArmies()<<"}"<<std::endl;
        std::cout <<"\t\t"<<"Countries "<<std::endl;
        std::vector<std::string> countries = (*continentList)[i].getCountryNames();
        for(int j =0; j<countries.size();j++){
            std::cout <<"\t\t\t"<<countries[j]<<std::endl;
        }
    }
    
}
//see Continent.h notes on getCountryNames()
bool Map::addContinent(Continent c){
   
    //check continent does not already exist
    if((*this).hasContinent(c))
        return false;
    //check continent does not contain an already existing country
    //is it better to have a static continent variable tracking all names of already created continents?
    //having both checks could work too?
    for(int i = 0;i < (*continentList).size(); i++){
        //is a private member function to get pointer to country list bad style? --> this is not possible
        //to be useful the function would have to be public
        //it shouldn't be, as the function will not be accessible to client code(see line above)
        //countries vector will be deleted automatically at the end of member function call
        std::vector<std::string> countries = (*continentList)[i].getCountryNames();
        for(int j = 0; j < countries.size(); j++){
            if(c.hasCountryByName(countries[j])){
                std::cout <<"Continent "<<c.getContinentName()<<" contains country ";
                std::cout <<countries[j]<<" which already exists in continent "<<(*continentList)[i].getContinentName();
                std::cout<<" of this map("<<*name<<")"<<std::endl<<"Aborting add continent operation..."<<std::endl;
                return false;
            }
        }
    }
    std::cout <<"Adding continent "<<c.getContinentName()<<" to map "<<*name<<std::endl;
    (*continentList).push_back(c);
    return true;
}
bool Map::hasContinent(Continent c){
    //check continent list is not empty
    if((*continentList).empty()) {
        std::cout <<"Map "<<*name<<" is empty"<<std::endl;
        return false;
    }

    for(int i = 0; i < (*continentList).size(); i++){
        if(c.getContinentName() == (*continentList)[i].getContinentName()){
            std::cout <<"Map "<<*name<<" already has continent "<<c.getContinentName()<<std::endl;
            return true;
        }
    }
    std::cout <<"Map "<<*name<<" does not have continent "<<c.getContinentName()<<std::endl;
    return false;
}
int Map::size(){
    int sum = 0;
    for(Continent c : (*continentList)){
        sum += (c.getCountryNames()).size();
    }
    return sum;
}
#include "gameengine.h"
using std::cout;
using std::endl;
using namespace boost::filesystem;

GameEngine::GameEngine(){
        MapParser mp;
        std::string mapFile = selectMap();
        int numPlayers = selectPlayers();
        //include a validity check
        *map = mp.parseMap(mapFile);
        deck = new Deck((*map).size());
        players = new std::vector<Player>();
        for (int i = 0; i < numPlayers; i++){
            (*players).push_back(Player());
        }
    }
int GameEngine::selectPlayers(){
    int numPlayers = 0;
    cout<<"Enter a number of players between 2 and 6"<<endl;
    std::cin >> numPlayers;
    if(std::cin.good()) {
        if(numPlayers < 2 || numPlayers > 6)
            return selectPlayers();
        else
            return numPlayers;  
    }
}
std::string GameEngine::selectMap()
{
    std::string mapPath = "maps";
    path p(mapPath);
    std::vector<path> dirs;
    int dirNum = 1;
    int choice = -1;
    try
    {
        if (exists(p)){
           if (is_directory(p)){
                cout << "Printing directory contents..." << endl;
                for (directory_entry &de : directory_iterator(p)){
                    cout << dirNum<<'\t' << de.path() << endl;
                    dirs.push_back(de.path());
                    dirNum++;
                }
            }
            else{
                cout << p << " exists but is not a directory" << endl;
            }
        }
        else
            cout << "Path " << p << " is not a valid path" << endl;
    }
    catch (const filesystem_error &e)
    {
        cout << e.what() << endl;
    }

    cout<<"Please enter the number of your desired map"<<endl;
    std::cin >> choice;
    return dirs[choice-1].string();
}
void GameEngine::playerOrder()
{
	srand(unsigned(time(0)));
	random_shuffle(listOfPlayers->begin(), listOfPlayers->end());
}

void GameEngine::assignCountriesToPlayer(Map m)
{
	vector<Continent> *continentList = m.getContinentList();
	vector<Country>* tempCountryList;
	vector<Country>* countryList;

	//Creates a list of all countries
	for (int i = 0; i < continentList->size(); i++) {
		*tempCountryList = continentList[i]->getCountryList();
		for (int j : *tempCountryList) {
			countryList->push_back(j);
		}
	}
	//add one country to a player at a time until there is no more countries in the list
	while (countryList->size() > 0){
		for (Player* p : *listOfPlayers) {
			p->addTerritory(countryList[0]);
			countryList->erase(countryList->begin());
		}
	}
}

void GameEngine::assignArmiesToPlayer()
{
	int numberOfPlayers = listOfPlayers->size();
	int numberOfArmiesPerPlayer = 0;

	if (numberOfPlayers == 2)
		numberOfArmiesPerPlayer = 40;
	else if (numberOfPlayers == 3)
		numberOfArmiesPerPlayer = 35;
	else if (numberOfPlayers == 4)
		numberOfArmiesPerPlayer = 30;
	else if (numberOfPlayers == 5)
		numberOfArmiesPerPlayer = 25;
	else if (numberOfPlayers == 6)
		numberOfArmiesPerPlayer = 20;

	// assign number of armies to each country 
	for (Player *p : *listOfPlayers) {
		p->assignArmies(numberOfArmiesPerPlayer);
	}

}
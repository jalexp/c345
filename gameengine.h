#include "map.h"
#include "mapparser.h"
#include "cards.h"
#include "player.h"
//don't forget the .hpp
#include <boost/filesystem.hpp>

class GameEngine{
private:
    Map* map;
    Deck* deck;
    std::vector<Player>* players;

public:
    //convert both to nonstatic PRIVATE member functions
    static std::string selectMap();
    static int selectPlayers();
    GameEngine(); 

    std::vector<Country> *listOfCountries;
	void addPlayerToGame(Player p);
	void addCountriesToGame(Country c);
	void playerOrder();
	void assignCountriesToPlayer(Map m);
	void assignArmiesToPlayer();
};
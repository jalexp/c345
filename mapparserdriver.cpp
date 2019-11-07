#include "mapparser.h"

int main(){


    std::string filename = "germany.map";
    MapParser mp;
    Map m;
    m = mp.parseMap(filename);
    m.showContinents();
    m.describeMap();
    // if(mp.hasMapExt(filename)) {
    //     m = mp.parseMap(filename);
    //     m.showContinents();
    //     m.describeMap();
    // }

}
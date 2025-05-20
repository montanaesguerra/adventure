#include "Location.h"

//Default Constructor
// Should just set the name to "?" all neighbors to null and everything else to false.
Location::Location() : name("?"), visited(false), exit(false) {
    for (int i = 0; i < 4; ++i)
        neighbors[i] = nullptr;
}

//Parameterized Constructor
//The two arg constructor should set the name and exit members, setting the rest to null or
//false as appropriate.
Location::Location(const std::string& locName, bool isTheExit)
    : name(locName), visited(false), exit(isTheExit) {
        for (int i = 0; i < 4; ++i)
        neighbors[i] = nullptr;
    }

//getName
//Returns the name of the location
std::string Location::getName() const {
    return name;
}

//isExit
//Return true if this Location is an exit
bool Location::isExit() const {
    return exit;
}
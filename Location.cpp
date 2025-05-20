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

//getDescription
//Returns a string containing the name of the location, a list of the directions you
//leave in and if it has been visited before. The first time we get the description for
//a room, it might say:
//"a deep dark cave. Exits: north east south."
//Or for a different room:
//"a musty passage. You have been here before. Exits: north east south."
std::string Location::getDescription() const {
    std::ostringstream desc;
    desc << name << ". Exits:";

    bool foundExit = false;
    const char* directionNames[] = { "north", "east", "south", "west" };

    for (int i = 0; i < 4; ++i) {
        if (neighbors[i] != nullptr && neighbors[i]->isExit()) {
            if (foundExit) {
                desc << ",";
            }
            desc << " " << directionNames[i];
            foundExit = true;
        }
    }

    if (!foundExit) {
        desc << " none.";
    } else {
        desc << ".";
    }

    return desc.str();
}


//hasNeighbor
//Returns true if there is another location in the specified direction, false if there is
//not (nullptr)
bool Location::hasNeighbor(Direction dir) const {
    return neighbors[dir] != nullptr;
}

//getNeighbor
//Returns a pointer to the neighbor in the indicated direction (or nullptr if there's no neighbor)
Location* Location::getNeighbor(Direction dir) const {
    return neighbors[dir];
}

//setNeighbor
//Stores the indicated Location pointer as the designated neighbor
void Location::setNeighbor(Direction dir, Location* neighborLoc) {
    neighbors[dir] = neighborLoc;
}

//isExit
//Return true if this Location is an exit
bool Location::isExit() const {
    return exit;
}
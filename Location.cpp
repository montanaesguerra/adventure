#include "Location.h"

//Default Constructor
// Should just set the name to "?" all neighbors to null and everything else to false.
Location::Location() : name("?"), visited(false), exit(false) {
    for (int i = 0; i < 4; ++i)
        neighbors[i] = nullptr;
}

//getName
//Returns the name of the location
std::string Location::getName() const {
    return name;
}
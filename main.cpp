//Author: Monty Esguerra
//
//


#include <iostream>
#include <cctype>
#include "Location.h"

using namespace std;

const int NUM_LOCATIONS = 8;

// Create the locations
Location darkCave("a deep, dark cave", false);
Location mustyPassage("a musty passage", false);
Location shaft("a twisting shaft", false);
Location alcove("a dusty alcove", false);
Location cavern("a collapsed cavern", false);
Location lake("the shores of an underground lake", false);
Location surfacePassage("a passage to the surface", false);
Location surface("the surface", true);

void buildMap(Location locations[NUM_LOCATIONS]) {
    locations[0] = darkCave;
    locations[1] = mustyPassage;
    locations[2] = shaft;
    locations[3] = alcove;
    locations[4] = cavern;
    locations[5] = lake;
    locations[6] = surfacePassage;
    locations[7] = surface;

    // Connect pointers using array elements
    locations[0].setNeighbor(NORTH, &locations[1]); // darkCave → mustyPassage
    locations[0].setNeighbor(EAST,  &locations[5]); // darkCave → lake
    locations[0].setNeighbor(SOUTH, &locations[4]); // darkCave → cavern

    locations[1].setNeighbor(SOUTH, &locations[0]); // mustyPassage → darkCave
    locations[1].setNeighbor(EAST,  &locations[2]); // mustyPassage → shaft

    locations[2].setNeighbor(EAST,  &locations[3]); // shaft → alcove
    locations[2].setNeighbor(SOUTH, &locations[5]); // shaft → lake

    locations[3].setNeighbor(SOUTH, &locations[6]); // alcove → surfacePassage

    locations[6].setNeighbor(NORTH, &locations[3]); // surfacePassage → alcove
    locations[6].setNeighbor(WEST,  &locations[7]); // surfacePassage → surface

    locations[5].setNeighbor(NORTH, &locations[2]); // lake → shaft
    locations[5].setNeighbor(WEST,  &locations[0]); // lake → darkCave

    locations[4].setNeighbor(NORTH, &locations[0]); // cavern → darkCave
}

Direction charToDirection(char input) {
    switch (toupper(input)) {
        case 'N': return NORTH;
        case 'E': return EAST;
        case 'S': return SOUTH;
        case 'W': return WEST;
        default:  return NORTH; // fallback, but will block invalid moves later
    }
}

int main()
{
    Location locations[NUM_LOCATIONS];
    buildMap(locations);

    Location* currentLocation = &locations[0]; // Start at dark cave

    cout << "You have 5 minutes to get out or your PP is gone." << endl;

    while (!currentLocation->isExit()) {
        cout << "\nYou are at " << currentLocation->getDescription() << endl;
        cout << "Where would you like to go? (N/S/E/W): ";

        char input;
        cin >> input;

        Direction dir = charToDirection(input);

        if (currentLocation->hasNeighbor(dir)) {
            currentLocation = currentLocation->getNeighbor(dir);
        } else {
            cout << "You can't go that way!" << endl;
        }
    }

    cout << "You emerge safely!" << endl;

    return 0;

}

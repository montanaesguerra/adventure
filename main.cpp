#include <iostream>
#include "Location.h"

using namespace std;

int main()
{

    //Starting Point
    Location darkCave("a deep, dark cave", false);

    Location mustyPassage("a musty passage", false);

    Location shaft("a twisting shaft", false);

    Location alcove("a dusty alcove", false);

    Location cavern("a collapsed cavern", false);

    Location lake("the shores of an underground lake", false);

    Location surfacePassage("a passage to the surface", false);

    //The only Exit
    Location surface("the surface", true);

    //Dark Cave Setup
    darkCave.setNeighbor(NORTH, &mustyPassage);
    darkCave.setNeighbor(EAST, &lake);
    darkCave.setNeighbor(SOUTH, &cavern);

    //Musty Passage Setup
    mustyPassage.setNeighbor(SOUTH, &darkCave);
    mustyPassage.setNeighbor(EAST, &shaft);

    //Shaft Setup
    shaft.setNeighbor(EAST, &alcove);
    shaft.setNeighbor(SOUTH, &lake);
    
    //Alcove Setup
    alcove.setNeighbor(SOUTH, &surfacePassage);

    //surfacePassage Setup
    surfacePassage.setNeighbor(NORTH, &alcove);
    surfacePassage.setNeighbor(WEST, &surface);

    //Lake Setup
    lake.setNeighbor(NORTH, &shaft);
    lake.setNeighbor(WEST, &darkCave);

    //Cavern Setup
    cavern.setNeighbor(NORTH, &darkCave);


    return 0;

}

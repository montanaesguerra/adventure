#ifndef LOCATION_H
#define LOCATION_H

#include <string>

enum Direction {
    NORTH, EAST, SOUTH, WEST
};

class Location {
    public:
        Location();
        Location(const std::string& locName, bool isTheExit);

        std::string getName() const;
        std::string getDescription() const;

        bool hasNeighbor(Direction dir) const;
        Location* getNeighbor(Direction dir) const;
        void setNeighbor(Direction dir, Location* neighborLoc);

        bool isExit() const;
        void visit();
        bool isVisited() const;

    private:
        std::string name;
        bool visited;
        bool exit;
        Location* neighbors[4];

};

#endif
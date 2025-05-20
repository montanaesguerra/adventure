//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using doctest::Approx;

#include <iostream>
using namespace std;

#include "Location.h"

TEST_CASE("Location/NoArgConstructor")
{
  Location testLoc;

  REQUIRE(testLoc.getName() == "?");
  REQUIRE(testLoc.isExit() == false);
}

TEST_CASE("Location/TwoArgConstructor")
{
  Location testLoc("the pool", true);
  Location testLoc2("the lawn", false);

  REQUIRE(testLoc.getName() == "the pool");
  REQUIRE(testLoc.isExit() == true);

  REQUIRE(testLoc2.getName() == "the lawn");
  REQUIRE(testLoc2.isExit() == false);
}

TEST_CASE("Location/Visiting")
{
  Location testLoc;

  REQUIRE(testLoc.isVisited() == false);
  testLoc.visit();
  REQUIRE(testLoc.isVisited() == true);
}

TEST_CASE("Location/HasNoNeighborInitial")
{
  Location testLoc;

  REQUIRE(testLoc.hasNeighbor(NORTH) == false);
  REQUIRE(testLoc.hasNeighbor(SOUTH) == false);
  REQUIRE(testLoc.hasNeighbor(EAST) == false);
  REQUIRE(testLoc.hasNeighbor(WEST) == false);
}

TEST_CASE("Location/SetNeighbor")
{
  Location testLoc;
  Location testLoc2("the end", true);

  testLoc.setNeighbor(EAST, &testLoc2);

  REQUIRE(testLoc.hasNeighbor(NORTH) == false);
  REQUIRE(testLoc.hasNeighbor(SOUTH) == false);
  REQUIRE(testLoc.hasNeighbor(EAST) == true);
  REQUIRE(testLoc.hasNeighbor(WEST) == false);

  testLoc.setNeighbor(NORTH, &testLoc2);

  REQUIRE(testLoc.hasNeighbor(NORTH) == true);
  REQUIRE(testLoc.hasNeighbor(SOUTH) == false);
  REQUIRE(testLoc.hasNeighbor(EAST) == true);
  REQUIRE(testLoc.hasNeighbor(WEST) == false);
}

TEST_CASE("Location/GetNeighbor")
{
  Location testLoc;
  Location testLoc2("the end", true);

  testLoc.setNeighbor(EAST, &testLoc2);

  Location* neighborAddrNorth = testLoc.getNeighbor(NORTH);
  REQUIRE(neighborAddrNorth == nullptr);
  Location* neighborAddrSouth = testLoc.getNeighbor(SOUTH);
  REQUIRE(neighborAddrSouth == nullptr);
  Location* neighborAddrEast = testLoc.getNeighbor(EAST);
  REQUIRE(neighborAddrEast == &testLoc2);
  Location* neighborAddrWest = testLoc.getNeighbor(WEST);
  REQUIRE(neighborAddrWest == nullptr);
}

TEST_CASE("Location/GetName")
{
  Location testLoc;
  Location testLoc2("the end", true);
  REQUIRE(testLoc.getName() == "?");
  REQUIRE(testLoc2.getName() == "the end");
}

TEST_CASE("Location/GetDescription")
{
  Location testLoc("a pleasant glade", false);
  Location testLoc2("the end", true);

  testLoc.setNeighbor(WEST, &testLoc2);
  testLoc.setNeighbor(SOUTH, &testLoc2);

  testLoc2.visit();

  cout << "getDescription not auto-tested, confirm output makes sense:" << endl;
  cout << testLoc.getDescription() << endl;
  cout << testLoc2.getDescription() << endl;
}

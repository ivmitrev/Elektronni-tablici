#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Types/Cell/IntCell.cpp"

TEST_CASE("IntCell constructor sets value correctly", "[IntCell]") 
{
    IntCell cell1(42);
    REQUIRE(cell1.getValueCellString() == "42");

    IntCell cell2(42, true);
    REQUIRE(cell2.getValueCellString() == "+42");
}

TEST_CASE("IntCell getCellSize returns correct size", "[IntCell]") 
{
    IntCell cell1(42);
    REQUIRE(cell1.getCellSize() == 2);

    IntCell cell2(42, true);
    REQUIRE(cell2.getCellSize() == 3); 
}

TEST_CASE("IntCell getValueCellString converts value correctly", "[IntCell]") 
{
    IntCell cell1(42);
    REQUIRE(cell1.getValueCellString() == "42");

    IntCell cell2(0);
    REQUIRE(cell2.getValueCellString() == "0");

    IntCell cell3(-42);
    REQUIRE(cell3.getValueCellString() == "-42");

    IntCell cell4(42, true);
    REQUIRE(cell4.getValueCellString() == "+42");
}

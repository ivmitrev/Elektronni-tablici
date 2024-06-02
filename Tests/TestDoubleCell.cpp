#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Types/Cell/DoubleCell.cpp"

TEST_CASE("DoubleCell constructor sets value correctly", "[DoubleCell]") 
{
    DoubleCell cell1(3.1415);
    REQUIRE(cell1.getValueCellString() == "3.142");

    DoubleCell cell2(3.1415, true);
    REQUIRE(cell2.getValueCellString() == "+3.142");
}

TEST_CASE("DoubleCell getCellSize returns correct size", "[DoubleCell]") 
{
    DoubleCell cell1(3.1415);
    REQUIRE(cell1.getCellSize() == 5); 

    DoubleCell cell2(3.1415, true);
    REQUIRE(cell2.getCellSize() == 6); 

    DoubleCell cell3(-3.1415);
    REQUIRE(cell3.getCellSize() == 6); 
}

TEST_CASE("DoubleCell doubleToString converts value correctly", "[DoubleCell]") 
{
    DoubleCell cell1(3.1415);
    REQUIRE(cell1.getValueCellString() == "3.142");

    DoubleCell cell2(3.1, true);
    REQUIRE(cell2.getValueCellString() == "+3.1");

    DoubleCell cell3(+3.0);
    REQUIRE(cell3.getValueCellString() == "3");
}

TEST_CASE("DoubleCell print prints value correctly", "[DoubleCell]") 
{
    DoubleCell cell1(3.1415);
    CAPTURE(cell1.getValueCellString());
    CAPTURE(cell1.getCellSize());

    DoubleCell cell2(3.1415, true);
    CAPTURE(cell2.getValueCellString());
    CAPTURE(cell2.getCellSize());
}


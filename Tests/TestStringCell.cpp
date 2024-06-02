#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Types/Cell/StringCell.cpp"

TEST_CASE("StringCell constructor sets value correctly", "[StringCell]") 
{
    StringCell cell("\"Hello\"");
    REQUIRE(cell.getValueCellString() == "\"Hello\"");
}

TEST_CASE("StringCell getCellSize returns correct size", "[StringCell]") 
{
    StringCell cell("\"Hello\\nWorld\"");
    REQUIRE(cell.getCellSize() == 11);

    StringCell cell2("\"A\\\"B\"");
    REQUIRE(cell2.getCellSize() == 3); 

    StringCell cell3("\"\"");
    REQUIRE(cell3.getCellSize() == 0); 
}

TEST_CASE("StringCell getValueCellString returns the raw string", "[StringCell]") 
{
    StringCell cell("\"Hello\\nWorld\"");
    REQUIRE(cell.getValueCellString() == "\"Hello\\nWorld\"");

    StringCell cell2("\"A\\\"B\"");
    REQUIRE(cell2.getValueCellString() == "\"A\\\"B\"");

    StringCell cell3("\"\"");
    REQUIRE(cell3.getValueCellString() == "\"\"");
}


#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Types/Cell/FormulaCell.cpp"

TEST_CASE("FormulaCell constructor sets value correctly", "[FormulaCell]") 
{
    FormulaCell cell("= R2C1 + R1C1");
    REQUIRE(cell.getValueCellString() == "= R2C1 + R1C1");
}

TEST_CASE("FormulaCell doubleToString converts value correctly", "[FormulaCell]") 
{
    FormulaCell cell("= 11 + 11");
    REQUIRE(cell.doubleToString(3.1415, 3) == "3.142");
    REQUIRE(cell.doubleToString(3.1000, 3) == "3.1");
    REQUIRE(cell.doubleToString(3.0000, 3) == "3");
}

TEST_CASE("FormulaCell getCellSize returns correct size", "[FormulaCell]") 
{
    FormulaCell cell("= 5 + 6");
    cell.setValueCellAnswerString("11");
    REQUIRE(cell.getCellSize() == 2);

    cell.setValueCellAnswerString("ERROR");
    REQUIRE(cell.getCellSize() == 5);
}

TEST_CASE("FormulaCell getValueCellString returns the formula", "[FormulaCell]") 
{
    FormulaCell cell("= 3 + R2C1");
    REQUIRE(cell.getValueCellString() == "= 3 + R2C1");
}

TEST_CASE("FormulaCell getValueCellAnswerString returns the answer string", "[FormulaCell]") 
{
    FormulaCell cell("");
    cell.setValueCellAnswerString("3.142");
    REQUIRE(cell.getValueCellAnswerString() == "3.142");

    cell.setValueCellAnswerString("ERROR");
    REQUIRE(cell.getValueCellAnswerString() == "ERROR");
}

TEST_CASE("FormulaCell setValueCellAnswerString formats the value correctly", "[FormulaCell]") 
{
    FormulaCell cell("");
    cell.setValueCellAnswerString("3.1415");
    REQUIRE(cell.getValueCellAnswerString() == "3.142");

    cell.setValueCellAnswerString("3.1000");
    REQUIRE(cell.getValueCellAnswerString() == "3.1");

    cell.setValueCellAnswerString("3.0000");
    REQUIRE(cell.getValueCellAnswerString() == "3");

    cell.setValueCellAnswerString("ERROR");
    REQUIRE(cell.getValueCellAnswerString() == "ERROR");
}

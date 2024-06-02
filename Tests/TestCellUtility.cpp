#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Utility/CellUtility.cpp"
#include "../Types/Cell/IntCell.cpp"
#include "../Types/Cell/DoubleCell.cpp"
#include "../Types/Cell/StringCell.cpp"
#include "../Types/Cell/FormulaCell.cpp"

TEST_CASE("CellUtility isInt function should check if a string is actual integer", "[CellUtility]") 
{
    REQUIRE(CellUtility::isInt("123"));
    REQUIRE(CellUtility::isInt("+123"));
    REQUIRE(CellUtility::isInt("-123"));
    REQUIRE(!CellUtility::isInt("12a"));
    REQUIRE(!CellUtility::isInt(""));
}

TEST_CASE("CellUtility isDouble function should check if a string is valid double", "[CellUtility]") 
{
    REQUIRE(CellUtility::isDouble("123.45"));
    REQUIRE(CellUtility::isDouble("+123.45"));
    REQUIRE(CellUtility::isDouble("-123.45"));
    REQUIRE(!CellUtility::isDouble(".45"));
    REQUIRE(!CellUtility::isDouble(""));
}

TEST_CASE("CellUtility isString function checks for valid string value", "[CellUtility]") 
{
    REQUIRE(CellUtility::isString("\"test\""));
    REQUIRE(!CellUtility::isString("test"));
    REQUIRE(!CellUtility::isString(""));
}

TEST_CASE("CellUtility isFormula function checks for valid formula value", "[CellUtility]") 
{
    REQUIRE(CellUtility::isFormula("= R1C1 + R1C2"));
    REQUIRE(CellUtility::isFormula("= 5 + 10"));
    REQUIRE(!CellUtility::isFormula("= 5 + 10a"));
    REQUIRE(!CellUtility::isFormula(""));
}

TEST_CASE("CellUtility checkForValidCell function check if a cell is valid", "[CellUtility]") 
{
    REQUIRE(CellUtility::checkForValidCell("123"));
    REQUIRE(CellUtility::checkForValidCell("123.45"));
    REQUIRE(CellUtility::checkForValidCell("\"test\""));
    REQUIRE(CellUtility::checkForValidCell("= R1C1 + R1C2"));
    REQUIRE(!CellUtility::checkForValidCell("test"));
    REQUIRE(!CellUtility::checkForValidCell("12a"));
    REQUIRE(!CellUtility::checkForValidCell(""));
}

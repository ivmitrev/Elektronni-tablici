#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Types/Table/Table.cpp"
#include "../Types/Row/Row.cpp"
#include "../Types/Cell/IntCell.cpp"
#include "../Types/Cell/DoubleCell.cpp"
#include "../Types/Cell/StringCell.cpp"
#include "../Types/Cell/FormulaCell.cpp"
#include "../Utility/CellUtility.cpp"

TEST_CASE("Table addRow and getRows functionality",  "[Table]") 
{
    Table table;
    Row* row1 = new Row();
    Row* row2 = new Row();

    table.addRow(row1);
    table.addRow(row2);

    REQUIRE(table.getRows().size() == 2);
    REQUIRE(table.getRows()[0] == row1);
    REQUIRE(table.getRows()[1] == row2);
}

// zakomentirani zashtoto v Table class sa private

// TEST_CASE("Table getValueFromRowColumn returns value from Table at certain row and column",  "[Table]") 
// {
//     Table table;
//     Row* row1 = new Row();
//     row1->addCell(new IntCell(10));
//     row1->addCell(new DoubleCell(20.5));
//     Row* row2 = new Row();
//     row2->addCell(new StringCell("Test"));
//     row2->addCell(new IntCell(30));

//     table.addRow(row1);
//     table.addRow(row2);

//     std::ostringstream oss; 
//     table.getValueFromRowColumn(1,1);

//     REQUIRE(table.getValueFromRowColumn(1, 1) == "10");
//     REQUIRE(table.getValueFromRowColumn(1, 2) == "20.5");
//     REQUIRE(table.getValueFromRowColumn(2, 1) == "Test");
//     REQUIRE(table.getValueFromRowColumn(2, 2) == "30");
// }

// TEST_CASE("Table edit should change cell value correctly", "[Table]") 
// {
//     Table table;
//     Row* row1 = new Row();
//     row1->addCell(new IntCell(10));
//     row1->addCell(new DoubleCell(20.5));

//     table.addRow(row1);

//     table.edit(1, 1, "50");
//     REQUIRE(table.getValueFromRowColumn(1, 1) == "50");

//     table.edit(1, 2, "15.75");
//     REQUIRE(table.getValueFromRowColumn(1, 2) == "15.75");
// }

// TEST_CASE("Table pow should get a number to a degree correctly", "[Table]") 
// {
//     Table table;
//     REQUIRE(table.pow(2, 3) == 8);
//     REQUIRE(table.pow(5, 0) == 1);
//     REQUIRE(table.pow(2, 1) == 2);
// }

// TEST_CASE("Table isValidNumber checks if a string is a valid number", "[Table]") 
// {
//     Table table;
//     REQUIRE(table.isValidNumber("123.45"));
//     REQUIRE(table.isValidNumber("0"));
//     REQUIRE(!table.isValidNumber("abc"));
//     REQUIRE(!table.isValidNumber("123abc"));
//     REQUIRE(!table.isValidNumber(""));
// }

// TEST_CASE("Table calculatingFormulasOnlyRc should calculate only formulas with RC", "[Table]") 
// {
//     Table table;
//     Row* row1 = new Row();
//     row1->addCell(new FormulaCell("= R1C2 + R1C3"));
//     row1->addCell(new IntCell(10));
//     row1->addCell(new IntCell(20));

//     table.addRow(row1);
//     table.calculatingFormulas();

//     REQUIRE(table.getValueFromRowColumn(1, 1) == "30");
// }

// TEST_CASE("Table calculatingFormulasNotRc should calculate formulas without RC", "[Table]") 
// {
//     Table table;
//     Row* row1 = new Row();
//     row1->addCell(new FormulaCell("= 5 + 10"));
//     row1->addCell(new IntCell(10));
//     row1->addCell(new IntCell(20));

//     table.addRow(row1);
//     table.calculatingFormulas();

//     REQUIRE(table.getValueFromRowColumn(1, 1) == "15");
// }



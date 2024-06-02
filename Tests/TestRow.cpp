#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Types/Row/Row.cpp"
#include "../Types/Cell/IntCell.cpp"
#include "../Types/Cell/DoubleCell.cpp"
#include "../Types/Cell/StringCell.cpp"
#include "../Types/Cell/FormulaCell.cpp"
#include "../Utility/CellUtility.cpp"
TEST_CASE("Row addCell adds a cell", "[Row]") 
{
    Row row;
    row.addCell(new IntCell(42));
    REQUIRE(row.getSize() == 1);
    REQUIRE(row.getCells().size() == 1);
}

TEST_CASE("Row getSize returns correct size", "[Row]") 
{
    Row row;
    row.addCell(new IntCell(42));
    row.addCell(new DoubleCell(3.14));
    row.addCell(new StringCell("\"Hello\""));
    REQUIRE(row.getSize() == 3);
}

TEST_CASE("Row getCells returns the cells", "[Row]") 
{
    Row row;
    row.addCell(new IntCell(42));
    row.addCell(new DoubleCell(3.14));
    row.addCell(new StringCell("\"Hello\""));

    auto cells = row.getCells();
    REQUIRE(cells.size() == 3);
    REQUIRE(dynamic_cast<IntCell*>(cells[0])->getValueCellString() == "42");
    REQUIRE(dynamic_cast<DoubleCell*>(cells[1])->getValueCellString() == "3.14");
    REQUIRE(dynamic_cast<StringCell*>(cells[2])->getValueCellString() == "\"Hello\"");
}

TEST_CASE("Row editCell edits a cell at the given index", "[Row]") 
{
    Row row;
    row.addCell(new IntCell(42));
    row.addCell(new DoubleCell(3.14));
    row.addCell(new StringCell("\"Hello\""));

    REQUIRE(row.getSize() == 3);

    row.editCell(1, "7.89");
    REQUIRE(dynamic_cast<DoubleCell*>(row.getCells()[1])->getValueCellString() == "7.89");

    row.editCell(0, "84");
    REQUIRE(dynamic_cast<IntCell*>(row.getCells()[0])->getValueCellString() == "84");

    row.editCell(2, "\"World\"");
    REQUIRE(dynamic_cast<StringCell*>(row.getCells()[2])->getValueCellString() == "\"World\"");
}

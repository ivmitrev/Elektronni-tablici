#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Utility/CommandUtility.cpp"
#include "../Types/Row/Row.cpp"
#include "../Types/Table/Table.cpp"
#include "../Types/Cell/IntCell.cpp"
#include "../Types/Cell/DoubleCell.cpp"
#include "../Types/Cell/StringCell.cpp"
#include "../Types/Cell/FormulaCell.cpp"
#include "../Utility/CellUtility.cpp"
#include "../Utility/FileUtility.cpp"


TEST_CASE("CommandUtility ParseCommand function should parse commands correctly", "[CommandUtility]") 
{
    REQUIRE(CommandUtility::ParseCommand("open thisfile") == "open");
    REQUIRE(CommandUtility::ParseCommand("open thisfile daaa") == "");
    REQUIRE(CommandUtility::ParseCommand("") == "");
    REQUIRE(CommandUtility::ParseCommand("close thisfile daaa") == "");
    REQUIRE(CommandUtility::ParseCommand("close") == "close");
    REQUIRE(CommandUtility::ParseCommand("save") == "save");
    REQUIRE(CommandUtility::ParseCommand("saveas") == "");
    REQUIRE(CommandUtility::ParseCommand("saveas thisfile") == "saveas");
    REQUIRE(CommandUtility::ParseCommand("help") == "help");
    REQUIRE(CommandUtility::ParseCommand("exit") == "exit");
    REQUIRE(CommandUtility::ParseCommand("print") == "print");
    REQUIRE(CommandUtility::ParseCommand("edit 1 2 da") == "edit");
}

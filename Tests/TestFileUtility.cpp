#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Utility/FileUtility.cpp"
#include "../Types/Table/Table.cpp"
#include "../Types/Row/Row.cpp"
#include "../Types/Cell/DoubleCell.cpp"
#include "../Types/Cell/StringCell.cpp"
#include "../Types/Cell/FormulaCell.cpp"
#include "../Types/Cell/IntCell.cpp"
#include "../Utility/CellUtility.cpp"


TEST_CASE("FileUtility splitBy function should split by delimeter", "[FileUtility]") 
{
    std::vector<std::string> result = FileUtility::splitBy("10, 20, 30, 40", ", ");
    REQUIRE(result.size() == 4);
    REQUIRE(result[0] == "10");
    REQUIRE(result[1] == "20");
    REQUIRE(result[2] == "30");
    REQUIRE(result[3] == "40");

    result = FileUtility::splitBy("",", ");
    REQUIRE(result.empty());
}

TEST_CASE("FileUtility trim function should remove extra whitespaces on the left and right", "[FileUtility]") 
{
    REQUIRE(FileUtility::trim("hello") == "hello");
    REQUIRE(FileUtility::trim("hello wor                      ") == "hello wor");
    REQUIRE(FileUtility::trim("     hello") == "hello");
    REQUIRE(FileUtility::trim("   ") == "");
    REQUIRE(FileUtility::trim("") == "");

    
}



#include "gtest/gtest.h"
#include "flagParser.hpp"

using namespace ::testing;
using namespace app;

struct FlagParserTest : Test
{
};

TEST_F(FlagParserTest, correctRead_NoFlags)
{
    { // one filename
        char const *argv[2] = {"app", "fileName"};
        auto res = parseFlags(2, argv);
        ASSERT_TRUE(res);
        ASSERT_EQ(res.value().fileNames.size(), 1);
        EXPECT_EQ(res.value().fileNames.at(0), "fileName");
    }
    { // multiple filenames
        char const *argv[3] = {"app", "fileName1", "fileName2"};
        auto res = parseFlags(3, argv);
        ASSERT_TRUE(res);
        ASSERT_EQ(res.value().fileNames.size(), 2);
        EXPECT_EQ(res.value().fileNames.at(0), "fileName1");
        EXPECT_EQ(res.value().fileNames.at(1), "fileName2");
    }
}

TEST_F(FlagParserTest, error_NoFileNames)
{
    {
        char const *argv[1] = {"app"};
        auto res = parseFlags(1, argv);
        ASSERT_FALSE(res);
    }
    { // will do when valid flags appear
    }
}

TEST_F(FlagParserTest, error_UnknownFlag)
{
    char const *argv[3] = {"app", "-u", "fileName"};
    auto res = parseFlags(3, argv);
    ASSERT_FALSE(res);
}

TEST_F(FlagParserTest, error_MalformedFlag)
{
    char const *argv[3] = {"app", "-", "fileName"};
    auto res = parseFlags(3, argv);
    ASSERT_FALSE(res);
}
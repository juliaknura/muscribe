add_executable(
    appTests
    flagParserTest.cpp
)

target_link_libraries(
    appTests
    appLib
    GTest::gtest_main
)

gtest_discover_tests(appTests)
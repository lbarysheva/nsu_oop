cmake_minimum_required(VERSION 3.14)
project(word_count)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(word_count_lib
        src/WordParser.cpp
        src/WordStatistics.cpp
        src/WordStatistics.h
        src/FileReader.cpp
        src/FileReader.h
        src/CsvWriter.cpp
        src/CsvWriter.h
        src/WordParser.cpp
        src/WordParser.cpp
        src/WordParser.h)

target_include_directories(word_count_lib PUBLIC src)
add_executable(word_count src/main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(word_count word_count_lib)
add_executable(word_count_tests test/WordParserTest.cpp
        test/WordStatisticsTest.cpp
)

target_link_libraries(word_count_tests word_count_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(word_count_tests)

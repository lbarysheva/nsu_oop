#include <gtest/gtest.h>
#include "WordStatistics.h"

using namespace std;
//пустая
TEST(WordStatisticsTest, EmptyStatistics) {
    WordStatistics stats;
    EXPECT_EQ(0, stats.getTotal());
    EXPECT_EQ(0, stats.getCount("hello"));
    EXPECT_TRUE(stats.getSortedWords().empty());
}

TEST(WordStatisticsTest, CountsWords) {
    WordStatistics stats;
    stats.addWords({"a", "b", "a"});
    EXPECT_EQ(2, stats.getCount("a"));
    EXPECT_EQ(1, stats.getCount("b"));
    EXPECT_EQ(3, stats.getTotal());
}
//
TEST(WordStatisticsTest, SortedByFrequency) {
    WordStatistics stats;
    stats.addWords({"b", "a", "a", "a", "c", "c"});
    vector<pair<string, int>> expected = {{"a", 3}, {"c", 2}, {"b", 1}};
    EXPECT_EQ(expected, stats.getSortedWords());
}

TEST(WordStatisticsTest, SortedByAlphabet) {
    WordStatistics stats;
    stats.addWords({"beta", "alpha"});
    vector<pair<string, int>> expected = {{"alpha", 1}, {"beta", 1}};
    EXPECT_EQ(expected, stats.getSortedWords());
}


#include <gtest/gtest.h>
#include <list>
#include <string>

#include "WordParser.h"

using namespace std;
//пустая
TEST(WordParserTest, EmptyLine) {
    WordParser parser;
    EXPECT_TRUE(parser.splitIntoWords("").empty());
}

TEST(WordParserTest, SimpleSentence) {
    WordParser parser;
    list<string> expected = {"hello", "world", "hello"};
    EXPECT_EQ(expected, parser.splitIntoWords("hello world hello"));
}

TEST(WordParserTest, PunctuationAndSpaces) {
    WordParser parser;
    list<string> expected = {"hello", "bye"};
    EXPECT_EQ(expected, parser.splitIntoWords("  ...hello,,, \t bye!!!  "));
}

TEST(WordParserTest, Digits) {
    WordParser parser;
    list<string> expected = {"hello123", "27"};
    EXPECT_EQ(expected, parser.splitIntoWords("hello123 27"));
}

TEST(WordParserTest, OnlySeparators) {
    WordParser parser;
    EXPECT_TRUE(parser.splitIntoWords(" ,.;!!? -- ??? ").empty());
}

TEST(WordParserTest, RepeatedWords) {
    WordParser parser;
    list<string> expected = {"a", "a", "b"};
    EXPECT_EQ(expected, parser.splitIntoWords("a a b"));
}

TEST(WordParserTest, Lowercased) {
    WordParser parser;
    list<string> expected = {"hello", "hello"};
    EXPECT_EQ(expected, parser.splitIntoWords("Hello HELLO"));
}

TEST(WordParserTest, HyphenSplit) {
    WordParser parser;
    list<string> expected = {"one", "two"};
    EXPECT_EQ(expected, parser.splitIntoWords("one-two"));
}

TEST(WordParserTest, LastWord) {
    WordParser parser;
    list<string> expected = {"hello"};
    EXPECT_EQ(expected, parser.splitIntoWords("hello"));
}


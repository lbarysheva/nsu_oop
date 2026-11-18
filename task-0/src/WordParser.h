#ifndef WORD_COUNT_WORDPARSER_H
#define WORD_COUNT_WORDPARSER_H

#include <string>
#include <list>

using namespace std;

class WordParser {
public:
    list<string> splitIntoWords(const string& line);
};

#endif //WORD_COUNT_WORDPARSER_H

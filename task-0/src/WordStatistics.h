#ifndef WORD_COUNT_WORDSTATISTICS_H
#define WORD_COUNT_WORDSTATISTICS_H

#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class WordStatistics {
public:
    void addWords(const list<string>& words);
    int getCount(const string& word) const;
    int getTotal() const;
    vector<pair<string, int>> getSortedWords() const;

private:
    map<string, int> counts;
    int total = 0;
};

#endif //WORD_COUNT_WORDSTATISTICS_H

#include "WordStatistics.h"
#include <algorithm>

using namespace std;

// сначала слова с большей частотой
static bool compareWords(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void WordStatistics::addWords(const list<string>& words) {
    for (const string& word : words) {
        counts[word]++;
        total++;
    }
}

int WordStatistics::getCount(const string& word) const {
    if (counts.count(word) == 0) {
        return 0;
    }
    return counts.at(word);
}

int WordStatistics::getTotal() const {
    return total;
}

vector<pair<string, int>> WordStatistics::getSortedWords() const {
    vector<pair<string, int>> result(counts.begin(), counts.end());
    sort(result.begin(), result.end(), compareWords);
    return result;
}


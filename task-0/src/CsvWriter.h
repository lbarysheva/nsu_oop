#ifndef WORD_COUNT_CSVWRITER_H
#define WORD_COUNT_CSVWRITER_H

#include <fstream>
#include <string>
#include "WordStatistics.h"

using namespace std;

class CsvWriter {
public:
    CsvWriter(const string& filename);
    void write(const WordStatistics& statistics) const;

private:
    string filename;
};

#endif //WORD_COUNT_CSVWRITER_H

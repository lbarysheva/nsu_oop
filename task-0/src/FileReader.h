#ifndef WORD_COUNT_FILEREADER_H
#define WORD_COUNT_FILEREADER_H

#include <fstream>
#include <string>

using namespace std;

class FileReader {
public:
    FileReader(const string& filename);
    bool hasNext();
    string next();

private:
    ifstream inputFile;
};

#endif //WORD_COUNT_FILEREADER_H

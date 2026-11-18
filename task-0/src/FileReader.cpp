#include "FileReader.h"
#include <iostream>

FileReader::FileReader(const string& filename) {
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        cerr << "error: can not open " << filename << endl;
    }
}

bool FileReader::hasNext() {
    return inputFile.is_open() && !inputFile.eof();
}

string FileReader::next() {
    string line;
    if (hasNext()) {
        getline(inputFile, line);
    }
    return line;
}


#include "CsvWriter.h"
#include <fstream>
#include <iomanip>
#include <iostream>

CsvWriter::CsvWriter(const string& name) {
    filename = name;
}

void CsvWriter::write(const WordStatistics& statistics) const {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "error: can not open " << filename << endl;
        return;
    }

    int total = statistics.getTotal();
    outputFile << fixed << setprecision(2);
    for (const auto& item : statistics.getSortedWords()) {
        double percent = 100.0 * item.second / total;
        outputFile << item.first << "," << item.second << "," << percent << "\n";
    }
}

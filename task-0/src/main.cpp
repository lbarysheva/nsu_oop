#include <iostream>

#include "CsvWriter.h"
#include "FileReader.h"
#include "WordParser.h"
#include "WordStatistics.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "usage: word_count input.txt output.csv" << endl;
        return 1;
    }

    FileReader reader(argv[1]);
    WordParser parser;
    WordStatistics statistics;

    // читаем файл построчно каждую строку делим на слова
    while (reader.hasNext()) {
        statistics.addWords(parser.splitIntoWords(reader.next()));
    }

    CsvWriter writer(argv[2]);
    writer.write(statistics);
    return 0;
}



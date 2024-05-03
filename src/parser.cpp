#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<int> parseLine(std::string line) {
    std::istringstream streamLine(line);

    int number;
    char comma;
    std::vector<int> row;


    while(streamLine >> number >> comma && comma == ',') {
        row.push_back(number);
    }
    return row;
}

std::vector<std::vector<int> > parse(std::string path) {
    std::ifstream stream(path);
    std::vector<std::vector<int> > board;

    if (stream) {
        std::string line;
        while(getline(stream, line)) {
            std::vector<int> parsedLine = parseLine(line);
            board.push_back(parsedLine);
        }
    }

    return board;
}
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "state.hpp"
#include "parser.h"
#include "pathfind.h"
#include "board_mapper.h"
#include "draw.h"

int main() {
    std::string path = "./maze.board";

    std::cout << "Parsing board to vector!" << std::endl;
    std::vector<std::vector<int> > board = parse(path);

    std::vector<std::vector<int> > boardWithPath = search(board);
    std::vector<std::vector<State> > stateBoard = mapToState(boardWithPath);

    std::cout << "Finished searching the best path from start to goal!" << std::endl;
    drawBoard(stateBoard);
    return 0;
}
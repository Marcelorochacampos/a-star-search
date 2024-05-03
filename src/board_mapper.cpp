#include <vector>
#include "state.hpp"
#include <iostream>

std::vector<std::vector<State> > mapToState(std::vector<std::vector<int> > board) {
    std::vector<std::vector<State> > formatted;
    for (size_t i = 0; i < board.size(); ++i) {
        std::vector<int> row = board[i];
        formatted.push_back(std::vector<State>());
        for(int col : row) {
            switch(col) {
                case 0: formatted[i].push_back(State::kEmpty); break;
                case 1: formatted[i].push_back(State::kObstacle); break;
                case 2: formatted[i].push_back(State::kPath); break;
                default: formatted[i].push_back(State::kEmpty); break;
            }
        }
    }
    return formatted;
}
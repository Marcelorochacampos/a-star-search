#include <iostream>
#include <vector>

#include "state.hpp"

void drawBoard(std::vector<std::vector<State> > board) {
    for(std::vector<State> row : board) {
        for(State col : row) {
            switch (static_cast<int>(col)) {
                case static_cast<int>(State::kEmpty): std::cout << "⬜"; break;
                case static_cast<int>(State::kObstacle): std::cout << "⬛"; break;
                case static_cast<int>(State::kClosed): std::cout << "⬛"; break;
                case static_cast<int>(State::kPath): std::cout << "🟦"; break;
                case static_cast<int>(State::kStart): std::cout << "🟢"; break;
                case static_cast<int>(State::kFinish): std::cout << "🔴"; break;
                default: std::cout << "⬜"; break;
            }
        }
        std::cout << std::endl;
    }
}
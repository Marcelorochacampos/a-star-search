#include <vector>
#include <algorithm>
#include <iostream>

#include "pathfind.h"
#include "node.h"
#include "nodes.hpp"
#include "pathfind.h"

std::vector<std::vector<int> > search(std::vector<std::vector<int> > board) {
    std::vector<Node> openNodes;
    std::vector<std::vector<int> > empty;

    // Distance cost
    int g = 0;
    // Manhattan distance
    int h = heuristic(static_cast<int>(Nodes::startNodeX), static_cast<int>(Nodes::startNodeY), static_cast<int>(Nodes::endNodeX), static_cast<int>(Nodes::endNodeY));

    Node startingNode(static_cast<int>(Nodes::startNodeX), static_cast<int>(Nodes::startNodeY), 0, h);

    openNodes.push_back(startingNode);

    while(openNodes.size() > 0) {
        cellSort(&openNodes);
        Node currentNode = openNodes.back();

        openNodes.pop_back();

        board[currentNode.yPosition][currentNode.xPosition] = 2;

        // std::cout << "Current position! " << currentNode.xPosition << currentNode.yPosition << std::endl;
        if (currentNode.xPosition == static_cast<int>(Nodes::endNodeX) && currentNode.yPosition == static_cast<int>(Nodes::endNodeY)) {
            std::cout << "Reached last position returning board! " << openNodes.size() << std::endl;
            return board;
        }

        expandNeighbors(currentNode, openNodes, board);
    }
    
    std::cout << "Finished searching!" << std::endl;
    return board;
}

// Get the absolute distance between the cells
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

/*
Compare the F-value of two cells ( f = g + h )
g = Distance cost between cells
h = absolute distance between two cells
*/
bool compare(Node aNode, Node bNode) {
    int f1 = aNode.distanceCost + aNode.absoluteDistance;
    int f2 = bNode.distanceCost + bNode.absoluteDistance;
    return f1 > f2;
}

/*
Sort the open cells based on the f-value
*/
void cellSort(std::vector<Node> *v) {
    sort(v->begin(), v->end(), compare);
}

/*
Check if the position is a valid open cell
*/
bool isValidCell(int x, int y, std::vector<std::vector<int> > board) {
    if (
        x < 0 || x >= board[0].size() ||
        y < 0 || y >= board.size()
    ) {
        return false;
    }
    return board[y][x] == 0;
}

void expandNeighbors(Node currentNode, std::vector<Node> &openNodes, std::vector<std::vector<int> > &board) {
    const int delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Clearing the old nodes to prevent the algorithm to revisit closed nodes
    openNodes.clear();

    for(int count = 0; count < 4; count++) {
        int x = currentNode.xPosition + delta[count][0];
        int y = currentNode.yPosition + delta[count][1];

        if (isValidCell(x, y, board)) {
            int g = currentNode.distanceCost + 1;
            int h = heuristic(x, y, static_cast<int>(Nodes::endNodeX), static_cast<int>(Nodes::endNodeY));
            Node neighbor(x, y, g, h);
            openNodes.push_back(neighbor);
            board[y][x] = 9;
        }
    }   
}
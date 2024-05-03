#ifndef PATHFIND_H
#define PATHFIND_H

#include <vector>

#include "node.h"

std::vector<std::vector<int> > search(std::vector<std::vector<int> > board);
int heuristic(int x1, int y1, int x2, int y2);
bool compare(Node aNode, Node bNode);
void cellSort(std::vector<Node> *v);
bool isValidCell(int x, int y, std::vector<std::vector<int> > board);
void expandNeighbors(Node currentNode, std::vector<Node> &openNodes, std::vector<std::vector<int> > &board);

#endif
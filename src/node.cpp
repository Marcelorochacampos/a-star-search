#include "node.h"

Node::Node(int x, int y, int g, int h) {
    xPosition = x;
    yPosition = y;
    distanceCost = g;
    absoluteDistance = h;
}
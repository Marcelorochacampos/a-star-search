#ifndef NODE_H
#define NODE_H

class Node {
public:
    int xPosition;
    int yPosition;
    int distanceCost;
    int absoluteDistance;
    Node(int x, int y, int g, int h);
};

#endif
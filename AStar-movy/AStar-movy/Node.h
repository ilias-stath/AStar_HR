#ifndef NODE_H
#define NODE_H


class Node {
private:
    int x;
    int y;
    double moveCost;
    double heurCost;
    double totalCost;
    Node* parent;

public:
    Node(int x, int y, double c, double h, Node* parent);

    void setParameters(int x, int y, double c, double h, Node* parent);

    double getX();

    double getY();

    double getMoveCost();

    double getTotalCost();

    Node* getParent();

    void printNode();
};


#endif
#ifndef NODE_H
#define NODE_H


class Node {
private:
private:

    unsigned short x;
    unsigned short y;
    float totalCost;
    Node* parent;

public:
    Node(unsigned short x, unsigned short y, float c, float h, Node* parent);

    void setParameters(unsigned short x, unsigned short y, float c, float h, Node* parent);

    unsigned short getX();

    unsigned short getY();

    float getTotalCost();

    Node* getParent();

    /*void printNode();*/
};


#endif

#include <iostream>
#include "Node.h"

using namespace std;


Node::Node(unsigned short x, unsigned short y, float c, float h, Node* parent) {
    this->x = x;
    this->y = y;
    totalCost = c + h;
    this->parent = parent;
}

void Node::setParameters(unsigned short x, unsigned short y, float c, float h, Node* parent) {
    this->x = x;
    this->y = y;
    totalCost = c + h;
    this->parent = parent;
}

unsigned short Node::getX() {
    return x;
}

unsigned short Node::getY() {
    return y;
}

float Node::getTotalCost() {
    return totalCost;
}

Node* Node::getParent() {
    return this->parent;
}

//void Node::printNode() {
//    cout << "x = " << x << " ,  y = " << y << " ,  tot_cost = " << totalCost << " ,  parent = " << parent << endl;
//}

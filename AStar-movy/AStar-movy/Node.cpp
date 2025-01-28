#include <iostream>
#include "Node.h"

using namespace std;


Node::Node(int x, int y, double c, double h, Node* parent) {
    this->x = x;
    this->y = y;
    moveCost = c;
    heurCost = h;
    totalCost = c + h;
    this->parent = parent;
}

void Node::setParameters(int x, int y, double c, double h, Node* parent) {
    this->x = x;
    this->y = y;
    moveCost = c;
    heurCost = h;
    totalCost = c + h;
    this->parent = parent;
}

double Node::getX() {
    return x;
}

double Node::getY() {
    return y;
}

double Node::getMoveCost() {
    return moveCost;
}

double Node::getTotalCost() {
    return totalCost;
}

Node* Node::getParent() {
    return this->parent;
}

void Node::printNode() {
    cout << "x = " << x << " ,  y = " << y << " , cost = " << moveCost << " ,  heur = " << heurCost << " ,  tot_cost = " << totalCost << " ,  parent = " << parent << endl;
}
#ifndef ASTAR_HR_H
#define ASTAR_HR_H


#include "Node.h"
#include <vector>
#include <queue>
#include <stack>


class Astar_HR {
private:
    struct CompareCost {
        bool operator()(Node& n1, Node& n2) {
            return n1.getTotalCost() > n2.getTotalCost(); // lowest cost first
        }
    };

    std::stack<Node*> path;
    std::priority_queue<Node, std::vector<Node>, CompareCost> pq;
    int xs, ys, xg, yg, yMax, xMax, lenPath, lenObs, nodeQty;
    int* obstacles;
    int* xPoints;
    int* yPoints;
    double heuristic(int xn, int yn, int xg, int yg);
    void expandNode(Node* dad);
    void setPath(Node* n);

public:
    Astar_HR(int xs, int ys, int xg, int yg, int xMax, int yMax, int* ob, int lenObs);
    int pathGeneration();
    void getPath(int* x, int* y);

};

#endif

#ifndef ASTAR_HR_H
#define ASTAR_HR_H


#include "Node.h"
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>


class Astar_HR {
private:
    struct CompareCost {
        bool operator()(Node& n1, Node& n2) {
            return n1.getTotalCost() > n2.getTotalCost(); // lowest cost first
        }
    };

    struct MakePair {
        std::size_t operator()(const std::pair<int, int>& p) const {
            return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
        }
    };

    std::stack<Node*> path;
    std::priority_queue<Node, std::vector<Node>, CompareCost> pq;
    std::unordered_set<std::pair<int, int>, MakePair> visited;
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

#ifndef ASTAR_HR_H
#define ASTAR_HR_H


#include "Node.h"
//#include <Arduino.h>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <cmath>


class Astar_HR {
private:
    struct CompareCost {
        bool operator()(Node& n1, Node& n2) {
            return n1.getTotalCost() > n2.getTotalCost(); // lowest cost first
        }
    };

    struct MakePair {
        std::size_t operator()(const std::pair<unsigned short, unsigned short>& p) const {
            return std::hash<unsigned short>()(p.first) ^ (std::hash<unsigned short>()(p.second) << 1);
        }
    };

    struct Vec2 {
        float x, y;
        Vec2() : x(0), y(0) {}
        Vec2(float x, float y) : x(x), y(y) {}
        Vec2 operator+(const Vec2& rhs) const { return Vec2(x + rhs.x, y + rhs.y); }
        Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }
        Vec2& operator+=(const Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
    };

    std::stack<Node*> path;
    std::priority_queue<Node, std::vector<Node>, CompareCost> pq;
    std::unordered_set<std::pair<unsigned short, unsigned short>, MakePair> visited;
    unsigned short xs, ys, xg, yg, yMax, xMax;
    unsigned short nodeQty, lenPath, lenObs, subdivisions;
    unsigned short* obstacles;
    float* xPoints;
    float* yPoints;
    bool bezier;
    std::vector<Vec2> controlPoints;
    std::vector<Vec2> bezierCurve;
    float heuristic(unsigned short xn, unsigned short yn, unsigned short xg, unsigned short yg);
    void expandNode(Node* dad);
    void setPath(Node* n);
    double binomial(unsigned short n, unsigned short k);
    std::vector<Vec2> bezierPath(const std::vector<Vec2>& controlPoints, unsigned short subdivisions);

public:
    Astar_HR(unsigned short xs, unsigned short ys, unsigned short xg, unsigned short yg, unsigned short xMax, unsigned short yMax, unsigned short* ob, unsigned short lenObs, bool bezier);
    unsigned short pathGeneration();
    void getPath(float* x, float* y);

};

#endif

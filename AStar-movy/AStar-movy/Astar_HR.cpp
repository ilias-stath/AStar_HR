#include <iostream>
#include "Astar_HR.h"


using namespace std;

Astar_HR::Astar_HR(unsigned short xs, uint8_t ys, unsigned short xg, uint8_t yg, unsigned short xMax, uint8_t yMax, unsigned short* ob, unsigned short lenObs, bool bezier, uint8_t step) {
    this->xs = xs;
    this->ys = ys;
    this->xg = xg;
    this->yg = yg;
    this->xMax = xMax;
    this->yMax = yMax;
    this->lenPath = 0;
    this->nodeQty = 0;
    this->xPoints = nullptr;
    this->yPoints = nullptr;
    this->lenObs = lenObs;
    this->obstacles = (unsigned short*)malloc(sizeof(unsigned short) * this->lenObs);
    this->bezier = bezier;
    this->step = step;

    memcpy(obstacles, ob, this->lenObs * sizeof(unsigned short));

    //for (int i = 0; i < this->lenObs; i++) {
    //    if (i % 2 == 0) {
    //        //cout << endl;
    //    }
    //    cout << this->obstacles[i] << ",";
    //}
    cout << "ys -> " << ys << endl;
    cout << "yg -> " << yg << endl;
    cout << endl << endl;


}

float Astar_HR::heuristic(unsigned short xn, uint8_t yn, unsigned short xg, uint8_t yg) {
    //return abs(xn - xg) + abs(yn - yg);
    float r = sqrt(pow(xg - xn, 2) + pow(yg - yn, 2));
    return r;
}

double Astar_HR::binomial(unsigned short n, unsigned short k) {
    double res = 1;
    if (k > n - k) k = n - k;
    for (unsigned short i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}


std::vector<Astar_HR::Vec2> Astar_HR::bezierPath(const std::vector<Astar_HR::Vec2>& controlPoints, unsigned short subdivisions) {
    std::vector<Astar_HR::Vec2> curve;
    unsigned short n = controlPoints.size() - 1;
    //cout << "bezierPath" << endl;
    for (unsigned short i = 0; i <= subdivisions; i++) {
        float t = i / static_cast<float>(subdivisions);
        //cout << "t->" << t;
        Astar_HR::Vec2 point(0, 0);
        for (unsigned short j = 0; j <= n; j++) {
            float coeff = binomial(n, j) * pow(t, j) * pow(1 - t, n - j);
            //cout << "coeff->" << coeff << endl;
            point += controlPoints[j] * coeff;
            //cout << "point->" << point.x << endl;
        }
        //cout << "point->" << point.x << endl;
        //cout << endl;
        curve.push_back(point);
    }
    return curve;
}

void Astar_HR::expandNode(Node* dad) {
    Node son(0, 0, 0, 0, nullptr);
    short x = 0; 
    short y = 0;
    bool obFlag = false;

    // Checking the points that are 1 move from the current point. 8 points in total
    // Starting from the top left and ending in the bottom right, moving left to right
    /*if (dad->getX() == 2 && dad->getY() == 10) {
        cout << "-------------------------" << endl;
    }*/
    for (int8_t i = -1; i <= 1; i++) {
        x = dad->getX() + i*step;
        //cout << "X=" << x << endl;
        if (x >= 0 && x <= xMax) {
            for (int8_t j = -1; j <= 1; j++) {
                y = dad->getY() + j*step;
                //cout << "Y=" << y << endl;
                if (i != 0 || j != 0) {
                    if (y >= 0 && y <= yMax) {
                        //cout << "----IN----" << endl;
                        //cout << "IN for-> " << "X=" << x << "Y=" << y << endl;
                        /*for (unsigned short k = 0; k < this->lenObs; k += 2) {
                            if (this->obstacles[k] == x && this->obstacles[k + 1] == y) {
                                obFlag = true;
                            }
                        }*/
                        //int jam;
                        for (unsigned short k = 0; k < this->lenObs; k += 4) {
                            //cout << "Index -> " << lenObs - k << endl;
                            if (lenObs - k == 6) {
                                //cout << "Stage time -> ";
                                //cout << "X:" << x << " ,Y:" << y << endl;
                                //cout << obstacles[k+1] << endl;
                                if ((x >= obstacles[k] && x <= obstacles[k + 4]) && (y >= obstacles[k + 3] && y <= obstacles[k + 1])) {
                                    //cout << "Big -> X:" << x << " ,Y:" << y << endl;
                                    obFlag = true;
                                }
                                else if ((x >= obstacles[k + 4] && x <= obstacles[k + 2]) && (y >= obstacles[k + 5] && y <= obstacles[k + 1])) {
                                    //cout << "Small -> X:" << x << " ,Y:" << y << endl;
                                    obFlag = true;
                                }
                                break;
                            }
                            else if ((x >= obstacles[k] && x <= obstacles[k + 2]) && (y >= obstacles[k + 3] && y <= obstacles[k + 1])) {
                                obFlag = true;
                                //cout << "Obstacle/Enemy -> X:" << x << " ,Y:" << y << endl;
                                //cin >> jam;
                            }
                            
                        }
                        //cin >> jam;

                        if (!obFlag) {
                            if (!(visited.find({ x, y }) != visited.end())) {
                                //To set the diagonals as other cost(not good, do not use)
                                if (abs(i) == 1 && abs(j) == 1) {
                                    //cout << "i=" << i << " ,  j=" << j << endl;
                                    son.setParameters(x, y, dad->getTotalCost() - heuristic(dad->getX(), dad->getY(), this->xg, this->yg) + sqrt(2)*step, heuristic(x, y, this->xg, this->yg), dad);
                                    //cout << "Move cost -> " << dad->getTotalCost() - heuristic(dad->getX(), dad->getY(), this->xg, this->yg) + sqrt(2) << " ,  ";
                                }
                                else {
                                    son.setParameters(x, y, dad->getTotalCost() - heuristic(dad->getX(), dad->getY(), this->xg, this->yg) + 1*step, heuristic(x, y, this->xg, this->yg), dad);
                                    //cout << "Move cost -> " << dad->getTotalCost() - heuristic(dad->getX(), dad->getY(), this->xg, this->yg) + 1 << " ,  ";
                                }
                                //son.setParameters(x, y, dad->getMoveCost() + 1, heuristic(x, y, this->xg, this->yg), dad);
                                //cout << "MoveCost -> " << son.getMoveCost() << endl;
                                pq.push(son);
                                nodeQty++;
                                //cout << "Node " << nodeQty << "  -> ";
                                //son.printNode();
                                //cout << "Memory of Node -> " << sizeof(son) << endl;

                            }
                            else {
                                //cout << "FOUND (" << n->getX() << " , " << n->getY() << ")!!" << endl;
                            }
                        }
                        else {
                            obFlag = false;
                        }
                    }
                }
                y = y - j*step;
            }
        }
        x = x - i*step;
    }
}


void Astar_HR::setPath(Node* n) {
    std::priority_queue<Node, std::vector<Node>, CompareCost> empty_pq;
    pq.swap(empty_pq);

    do {
        //cout << n->getParent() << endl;
        path.push(n);
        n = n->getParent();
        lenPath++;

    } while (n->getParent() != nullptr);

    path.push(n);
    lenPath++;

    visited.clear();
    //lenPath++;

    if (bezier) {
        //controlPoints.push_back(Vec2(xs, ys));
        for (unsigned short i = 0; i < lenPath; i++) {
            n = path.top();
            path.pop();

            controlPoints.push_back(Vec2(n->getX(), n->getY()));
        }
        this->subdivisions = 2*lenPath;
        lenPath = subdivisions;

        bezierCurve = bezierPath(controlPoints, subdivisions);

        lenPath++;

        // Allocate new memory for x and y
        xPoints = (float*)malloc(sizeof(float) * lenPath);
        //xPoints = new int(lenPath);
        yPoints = (float*)malloc(sizeof(float) * lenPath);
        //yPoints = new int(lenPath);

        if (xPoints == nullptr || yPoints == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }

        unsigned short i = 0;
        for (const auto& point : bezierCurve) {
            //cout << point.x * 1 << ", " << point.y * 1 << ", ";
            xPoints[i] = point.x;
            yPoints[i] = point.y;
            i++;
        }
    }
    else {
        // Allocate new memory for x and y
        xPoints = (float*)malloc(sizeof(float) * lenPath);
        //xPoints = new int(lenPath);
        yPoints = (float*)malloc(sizeof(float) * lenPath);
        //yPoints = new int(lenPath);

        if (xPoints == nullptr || yPoints == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }

        //xPoints[0] = xs;
        //yPoints[0] = ys;

        for (unsigned short i = 0; i < lenPath; i++) {
            n = path.top();
            path.pop();

            xPoints[i] = n->getX();
            yPoints[i] = n->getY();

            //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;

        }
    }

}

void Astar_HR::getPath(float* x, float* y) {
    memcpy(x, xPoints, lenPath * sizeof(float));
    memcpy(y, yPoints, lenPath * sizeof(float));
    free(xPoints);
    free(yPoints);
    xPoints = nullptr;
    yPoints = nullptr;
}

unsigned short Astar_HR::pathGeneration() {
    Node* n = new Node(xs, ys, 0, heuristic(xs, ys, xg, yg), nullptr);

    //cout << "Nodes = " << nodeQty << endl;
    while (true) {

        /*cout << "----------" << endl;
        cout << "Selected-> ";
        n->printNode();
        cout << "Node->" << n << endl;
        cout << "----------" << endl;

        cout << "n->getX() -> " << n->getX() << " , xg -> " << xg << " , n->getY() -> " << n->getY() << " , yg -> " << yg << endl;
        cout << "Evaluate 1 -> " << (n->getX() == xg) << " ,  Evaluate 2 -> " << (n->getY() == yg) << endl;
        */

        if (n->getX() == xg && n->getY() == yg) {
            break;
        }

        //cout << "--------------------------Nodes----------------" << endl;
        if (!(visited.find({ n->getX(), n->getY() }) != visited.end())) {
            visited.insert({ n->getX(), n->getY() });
            expandNode(n);

        }
        else {
            //cout << "FOUND (" << n->getX() << " , " << n->getY() << ")!!" << endl;
            delete n;
            n = nullptr;
            nodeQty--;
        }
        //cout << "--------------------------Nodes----------------" << endl;

        n = new Node(pq.top());
        //n->printNode();
        //cout << "Node->" << n << endl;
        pq.pop();

        //cout << "Nodes created = " << nodeQty << endl;

       
    }

    cout << "Memory of Node -> " << sizeof(*n) << endl;
    cout << "Number of elements in pq before -> " << pq.size() << endl;
    cout << "Memory of pq before -> " << pq.size()*sizeof(*n) << endl;
    cout << "Number of elements in visited before -> " << visited.size() << endl;
    cout << "Memory of visited before -> " << visited.size()*sizeof(*n) << endl;
    cout << "Numer of obstacles -> " << lenObs << endl;
    cout << "Memory of obstacles -> " << lenObs * sizeof(unsigned short) << endl;
    
    delete obstacles;
    obstacles = nullptr;
    //printPath();
    setPath(n);
    cout << "Number of elements in pq after -> " << pq.size() << endl;
    cout << "Memory of pq after -> " << pq.size() * sizeof(*n) << endl;
    cout << "Number of elements in visited after -> " << visited.size() << endl;
    cout << "Memory of visited after -> " << visited.size() * sizeof(*n) << endl;
    cout << "Lenght of path -> " << lenPath << endl;
    cout << "Memory of xPoints/yPoints -> " << lenPath * sizeof(float) << endl;
    cout << "Nodes created while deleting the ones that are on visited -> " << nodeQty << endl;

    /*for (int i = 0; i < len; i++) {
        cout << "x=" << (*x)[i] << " , y=" << (*y)[i] << endl;
    }*/

    return lenPath;
}

#include <iostream>
#include "Astar_HR.h"

using namespace std;

Astar_HR::Astar_HR(int xs, int ys, int xg, int yg, int xMax, int yMax, int* ob, int lenObs) {
    this->xs = xs;
    this->ys = ys;
    this->xg = xg;
    this->yg = yg;
    this->xMax = xMax;
    this->yMax = yMax;
    this->lenPath = 0;
    this->xPoints = nullptr;
    this->yPoints = nullptr;
    this->lenObs = lenObs;
    this->obstacles = (int*)malloc(sizeof(int) * this->lenObs);
    this->nodeQty = 0;

    memcpy(obstacles, ob, this->lenObs * sizeof(int));

    for (int i = 0; i < this->lenObs; i++) {
        if (i % 2 == 0) {
            //cout << endl;
        }
        cout << this->obstacles[i] << ",";
    }

    cout << endl << endl;


}

double Astar_HR::heuristic(int xn, int yn, int xg, int yg) {
    //return abs(xn - xg) + abs(yn - yg);
    double r = sqrt(pow(xg - xn, 2) + pow(yg - yn, 2));
    return r;
}

void Astar_HR::expandNode(Node* dad) {
    Node son(0, 0, 0, 0, nullptr);
    int x = 0, y = 0;
    bool obFlag = false;

    // Checking the points that are 1 move from the current point. 8 points in total
    // Starting from the top left and ending in the bottom right, moving left to right
    /*if (dad->getX() == 2 && dad->getY() == 10) {
        cout << "-------------------------" << endl;
    }*/
    for (int i = -1; i <= 1; i++) {
        x = dad->getX() + i;
        //cout << "X=" << x << endl;
        if (x >= 0 && x <= xMax) {
            for (int j = -1; j <= 1; j++) {
                y = dad->getY() + j;
                //cout << "Y=" << y << endl;
                if (i != 0 || j != 0) {
                    if (y >= 0 && y <= yMax) {
                        //cout << "----IN----" << endl;
                        //cout << "IN for-> " << "X=" << x << "Y=" << y << endl;
                        for (int k = 0; k < this->lenObs; k += 2) {
                            if (this->obstacles[k] == x && this->obstacles[k + 1] == y) {
                                obFlag = true;
                            }
                        }
                        if (!obFlag) {
                            nodeQty++;
                            //To set the diagonals as other cost(not good, do not use)
                            if (abs(i) == 1 && abs(j) == 1) {
                                //cout << "i=" << i << " ,  j=" << j << endl;
                                son.setParameters(x, y, dad->getMoveCost() + sqrt(2), heuristic(x, y, this->xg, this->yg), dad);
                            }
                            else {
                                son.setParameters(x, y, dad->getMoveCost() + 1, heuristic(x, y, this->xg, this->yg), dad);
                            }
                            //son.setParameters(x, y, dad->getMoveCost() + 1, heuristic(x, y, this->xg, this->yg), dad);
                            pq.push(son);
                            //cout << "Node " << nodeQty << "  -> ";
                            //son.printNode();
                            //cout << "Memory of Node -> " << sizeof(son) << endl;
                        }
                        else {
                            obFlag = false;
                        }
                    }
                }
                y = y - j;
            }
        }
        x = x - i;
    }
}


void Astar_HR::setPath(Node* n) {
    do {
        //cout << n->getParent() << endl;
        path.push(n);
        n = n->getParent();
        lenPath++;

    } while (n->getParent() != nullptr);

    // Allocate new memory for x and y
    xPoints = (int*)malloc(sizeof(int) * lenPath);
    //xPoints = new int(lenPath);
    yPoints = (int*)malloc(sizeof(int) * lenPath);
    //yPoints = new int(lenPath);

    if (xPoints == nullptr || yPoints == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }


    for (int i = 0; i < lenPath; i++) {
        n = path.top();
        path.pop();

        xPoints[i] = n->getX();
        yPoints[i] = n->getY();

        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;

    }
}

void Astar_HR::getPath(int* x, int* y) {
    memcpy(x, xPoints, lenPath * sizeof(int));
    memcpy(y, yPoints, lenPath * sizeof(int));
}

int Astar_HR::pathGeneration() {
    Node* n = new Node(xs, ys, 0, heuristic(xs, ys, xg, yg), nullptr);

    //cout << "Nodes = " << nodeQty << endl;
    while (true) {

        /*cout << "----------" << endl;
        cout << "Selected-> ";
        n->printNode();
        cout << "Node->" << n << endl;
        cout << "----------" << endl;*/

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
        }
        //cout << "--------------------------Nodes----------------" << endl;

        n = new Node(pq.top());
        //n->printNode();
        //cout << "Node->" << n << endl;
        pq.pop();

    }

    //cout << "Memory of Node -> " << sizeof(n) << endl;
    //printPath();
    setPath(n);
    cout << "Nodes created = " << nodeQty << endl;
    /*for (int i = 0; i < len; i++) {
        cout << "x=" << (*x)[i] << " , y=" << (*y)[i] << endl;
    }*/

    return lenPath;
}

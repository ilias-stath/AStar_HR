#include <iostream>
#include "AStar_HR.h"

using namespace std;


int main()
{
    int* xPoints = nullptr;
    int* yPoints = nullptr;
    int len = 0;
    int lenObstaclePoints = 51;
    int lenObs = 2*lenObstaclePoints;
    int xMax = 300, yMax = 200;
    //bool grid[150][100];
    int* obstacles;

    bool a[10], b[10];

    cout << "Memory of int len -> " << sizeof(len) << endl;
    //cout << "Memory of int -> " << sizeof(xPoints) << endl;

    /*for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            grid[x][y] = 0;
        }
    }*/

    obstacles = (int*)malloc(sizeof(int) * lenObs); 
    for (int i = 0; i <= 100; i+=2) {
        obstacles[i] = 150;
        obstacles[i+1] = 75 + i/2;
    }
    /*obstacles[0] = 3;
    obstacles[1] = 10;*/

    /*obstacles[2] = 150;
    obstacles[3] = 101;

    obstacles[4] = 1;
    obstacles[5] = 2;

    obstacles[6] = 1;
    obstacles[7] = 3;

    obstacles[8] = 2;
    obstacles[9] = 3;*/

    for (int i = 0; i < 1; i += 2) {
        cout << obstacles[i] << ", " << obstacles[i+1] << endl;
    }

    /*for (int i = 0; i < 10; i++) {
        a[i] = 1;
    }*/

    //memcpy(a,b,10*sizeof(int));
    /*copy(a,a+10,b);

    for (int i = 0; i < 10; i++) {
        cout << b[i] << endl;
    }*/

    /*for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            cout << grid[x][y];
        }
        cout << endl;
    }*/

    cout << "Starting" << endl;

    Astar_HR shit(100, 100, 200, 100, xMax, yMax, obstacles, lenObs);
    len = shit.pathGeneration();
    
    xPoints = (int*)malloc(sizeof(int) * len);
    //xPoints = new int(len);
    yPoints = (int*)malloc(sizeof(int) * len);
    //yPoints = new int(len);

    shit.getPath(xPoints, yPoints);

    cout << len << endl;
    for (int i = 0; i < len; i++) {
        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
        cout  << xPoints[i] << ", " << yPoints[i] << ", ";
    }

}

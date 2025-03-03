
#include <iostream>
#include "AStar_HR.h"
#include <set>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;

unsigned short tribObstacles(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl, bool horizontal); // True horizontal, false vertical
unsigned short stageOb(unsigned short** obstacles, bool team, unsigned short xMax, unsigned short yMax); // True blue, false yellow
unsigned short enemyOb(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl);
short constrain(short num, short downLimit, short upLimit);




int main()
{
    float* xPoints = nullptr;
    float* yPoints = nullptr;
    unsigned short len = 0;
    /*int lenObstaclePoints = 51;
    int lenObs = 2 * lenObstaclePoints;*/
    unsigned short lenObs = 0;
    unsigned short TotLenObs = 0;
    unsigned short xMax = 300;
    uint8_t yMax = 200;
    //bool grid[150][100];
    unsigned short* obstacles = nullptr;
    unsigned short* TotObs = nullptr;
    unsigned short* tempObs = nullptr;
    uint8_t xl, yl;
    // 1 -> every 1 cm, 5 -> every 5 cm, 10 -> every 10cm 
    uint8_t step = 5;

    bool a[10], b[10];


    cout << "Memory of int len -> " << sizeof(len) << endl;
    cout << "Memory of size_t -> " << sizeof(size_t) << endl;
    

    short obsStart[20] = { 7, 40, 77, 25, 223, 25, 293, 40, 7, 133, 110, 95, 190, 95, 293, 133, 81, 173, 219, 173 };
    unsigned short k = 0;

    // Tribunes
    xl = 31;
    yl = 16;
    for (unsigned short i = 0; i < 20; i += 2) {
        if (k == 0 || k == 3 || k == 4 || k == 7) {
            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, yl, xl, false);
        }
        else {
            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, xl, yl, true);
        }
        k++;


       tempObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
        if (tempObs == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }

        if (TotLenObs > 0) {
            memcpy(tempObs, TotObs, TotLenObs * sizeof(unsigned short));
            free(TotObs);
        }

        TotLenObs += lenObs;

        TotObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
        if (TotObs == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }

        if (TotLenObs - lenObs > 0) {
            memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(unsigned short));
        }

        memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(unsigned short));

        free(tempObs);

    }


    // Enemy Obstacle
    yl = xl = 42;
    lenObs = enemyOb(&obstacles, 250, 50, xMax, yMax, xl, yl);


    tempObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
    if (tempObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs > 0) {
        memcpy(tempObs, TotObs, TotLenObs * sizeof(unsigned short));
        free(TotObs);
    }

    TotLenObs += lenObs;

    TotObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
    if (TotObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs - lenObs > 0) {
        memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(unsigned short));
    }

    memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(unsigned short));

    free(tempObs);


    // Stage Obstacle
    lenObs = stageOb(&obstacles, true, xMax, yMax);


    tempObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
    if (tempObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs > 0) {
        memcpy(tempObs, TotObs, TotLenObs * sizeof(unsigned short));
        free(TotObs);
    }

    TotLenObs += lenObs;

    TotObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
    if (TotObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs - lenObs > 0) {
        memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(unsigned short));
    }

    memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(unsigned short));

    free(tempObs);



    cout << endl << endl << "END OBSTACLES CREATION" << endl << endl;


    for (int i = 0; i < TotLenObs; i += 2) {
        cout << TotObs[i] << ", " << TotObs[i + 1] << ", ";
    }

    cin >> step;

    cout << endl;

    cout << "Starting" << endl;

    TotObs = (unsigned short*)malloc(sizeof(unsigned short) * 2);
    TotLenObs = 2;
    TotObs[0] = 10;
    TotObs[1] = 10;  

    cout << "Number of Obstacles -> " << TotLenObs << endl;
    cout << "Memory of Obstacles with int -> " << TotLenObs * sizeof(int) << endl;
    cout << "Memory of Obstacles witn short -> " << TotLenObs * sizeof(unsigned short) << endl;


    Astar_HR shit(0, 0, 300, 200, xMax, yMax, TotObs, TotLenObs, true, step);
    cout << "Memory of shit ->" << sizeof(shit) << endl;

    len = shit.pathGeneration();

    cout << "Memory of shit ->" << sizeof(shit) << endl;

    xPoints = (float*)malloc(sizeof(float) * len);
    yPoints = (float*)malloc(sizeof(float) * len);

    shit.getPath(xPoints, yPoints);

    cout << "Memory of shit ->" << sizeof(shit) << endl;

    cout << "---Astar points---" << endl;
    for (unsigned short i = 0; i < len; i++) {
        cout << xPoints[i] << ", " << yPoints[i] << ", ";
    }

    cout << endl << "---X---" << endl;

    for (unsigned short i = 0; i < len; i++) {
        cout << xPoints[i] * 10 << ", ";
    }

    cout << endl << "---Y---" << endl;

    for (unsigned short i = 0; i < len; i++) {
        cout << yPoints[i] * 10 << ", ";
    }

    cout << endl << endl;

}




unsigned short tribObstacles(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl, bool horizontal) {
    short obLen = 8, xtl, ytl, xtr, ytr, xbl, ybl, xbr, ybr;
    unsigned short obs[8];



    //if (horizontal) {
        xtl = xbl = constrain(x - xl, 0, xMax);
        xtr = xbr = constrain(x + xl, 0, xMax);
        ytr = ytl = constrain(y + yl, 0, yMax);
        ybr = ybl = constrain(y - yl, 0, yMax);
    //}
    /*else {
        xtl = xbl = constrain(x - yl, 0, xMax);
        xtr = xbr = constrain(x + yl, 0, xMax);
        ytr = ytl = constrain(y + xl, 0, yMax);
        ybr = ybl = constrain(y - xl, 0, yMax);
    }*/

    obs[0] = xtl;
    obs[1] = ytl;
    obs[2] = xtr;
    obs[3] = ytr;
    obs[4] = xbl;
    obs[5] = ybl;
    obs[6] = xbr;
    obs[7] = ybr;


    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));
    return obLen;
}


unsigned short stageOb(unsigned short** obstacles, bool team, unsigned short xMax, unsigned short yMax) {
    unsigned short obLen = 12, xtl, ytl, xbl, ybl, xbm, ybm, xtm, ytm, xbr, ybr, xtr, ytr;
    uint8_t tol = 22;
    unsigned short obs[12];

    if (team) {
        xtl = 0;
        ytl = yMax;
        xbl = 0;
        ybl = 155 - tol;
        xbm = 195 + tol;
        ybm = 155 - tol;
        xtm = 195 + tol;
        ytm = 180 - tol;
        xbr = 235 + tol;
        ybr = 180 - tol;
        xtr = 235 + tol;
        ytr = yMax;
    }
    else {
        xtr = xMax;
        ytr = yMax;
        xbr = xMax;
        ybr = 155 - tol;
        xbm = xMax - 195 - tol;
        ybm = 155 - tol;
        xtm = xMax - 195 - tol;
        ytm = 180 - tol;
        xbl = xMax - 235 - tol;
        ybl = 180 - tol;
        xtl = xMax - 235 - tol;
        ytl = yMax;
    }

    obs[0] = xtl;
    obs[1] = ytl;
    obs[2] = xtr;
    obs[3] = ytr;
    obs[4] = xbl;
    obs[5] = ybl;
    obs[6] = xbr;
    obs[7] = ybr;
    obs[8] = xtm;
    obs[9] = ytm;
    obs[10] = xbm;
    obs[11] = ybm;


    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));

    return obLen;
}



unsigned short enemyOb(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl) {
    short obLen = 8 , xtl, ytl, xtr, ytr, xbl, ybl, xbr, ybr;
    unsigned short obs[8];
    
    /*xtl = xbl = x - xl;
    xtr = xbr = x + xl;
    ytr = ytl = y + yl;
    ybr = ybl = y - yl;
    cout << xtl << ", " << ytl << ", " << xtr << ", " << ytr << ", " << xbl << ", " << ybl << ", " << xbr << ", " << ybr << endl;*/

    xtl = xbl = constrain(x - xl,0,xMax);
    xtr = xbr = constrain(x + xl, 0, xMax);
    ytr = ytl = constrain(y + yl,0,yMax);
    ybr = ybl = constrain(y - yl, 0, yMax);
    //cout << xtl << ", " << ytl << ", " << xtr << ", " << ytr << ", " << xbl << ", " << ybl << ", " << xbr << ", " << ybr << endl;

    obs[0] = xtl;
    obs[1] = ytl;
    obs[2] = xtr;
    obs[3] = ytr;
    obs[4] = xbl;
    obs[5] = ybl;
    obs[6] = xbr;
    obs[7] = ybr;

    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));

    return obLen;
}


short constrain(short num, short downLimit, short upLimit) {
    if (num > upLimit) {
        return upLimit;
    }
    else if (num < downLimit) {
        return downLimit;
    }
    else {
        return num;
    }

}

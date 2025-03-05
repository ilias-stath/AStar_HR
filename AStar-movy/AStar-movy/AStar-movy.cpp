
#include <iostream>
#include "AStar_HR.h"
#include <set>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;

unsigned short tribObstacles(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl, bool horizontal); // True horizontal, false vertical
unsigned short stageOb(unsigned short** obstacles, bool team, unsigned short xMax, unsigned short yMax, uint8_t tol, uint8_t Rs); // True blue, false yellow
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
    uint8_t xl, yl, step = 2, tol = 2, Rsize = 15;
    // 1 -> every 1 cm, 5 -> every 5 cm, 10 -> every 10cm 

    bool a[10], b[10];

    /*int x;
    int y;

    while (1) {
        cout << "x -> ";
        cin >> x;
        cout << endl << "step -> ";
        cin >> y;
        cout << endl;

        cout << "x%step -> " << x % y << endl;
        x = x + y - x % y;
        cout << "xnew -> " << x << endl;
    }*/
    
    

    cout << "Memory of int len -> " << sizeof(len) << endl;
    cout << "Memory of size_t -> " << sizeof(size_t) << endl;


    short obsStart[20] = { 7, 40, 77, 25, 223, 25, 293, 40, 7, 133, 110, 95, 190, 95, 293, 133, 81, 173, 219, 173 };
    unsigned short k = 0;

    // Tribunes
    xl = 20 + Rsize + tol;
    yl = 5 + Rsize + tol;
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
    yl = xl = 16 + Rsize + tol;
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
    lenObs = stageOb(&obstacles, true, xMax, yMax, tol, Rsize);


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

    int lol = 0;
    for (int i = 0; i < TotLenObs; i += 2) {
        if (TotLenObs - i == 12) {
            lol = 0;
        }
        if (lol%8 == 0) {
            cout << endl;
        }
        cout << TotObs[i] << ", " << TotObs[i + 1] << ", ";
        lol++;
    }


    cout << endl;

    cout << "Starting" << endl;

    /*TotObs = (unsigned short*)malloc(sizeof(unsigned short) * 2);
    TotLenObs = 2;
    TotObs[0] = 10;
    TotObs[1] = 10;*/

    cout << "Number of Obstacles -> " << TotLenObs << endl;
    cout << "Memory of Obstacles with int -> " << TotLenObs * sizeof(int) << endl;
    cout << "Memory of Obstacles witn short -> " << TotLenObs * sizeof(unsigned short) << endl;


    Astar_HR shit(124, 24, 240, 140, xMax, yMax, TotObs, TotLenObs, false, step);
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
    short obLen = 4, xtl, ytl, xtr, ybr;
    unsigned short obs[4];



    //if (horizontal) {
    /*xtl = xbl = constrain(x - xl, 0, xMax);
    xtr = xbr = constrain(x + xl, 0, xMax);
    ytr = ytl = constrain(y + yl, 0, yMax);
    ybr = ybl = constrain(y - yl, 0, yMax);*/
    //}
    /*else {
        xtl = xbl = constrain(x - yl, 0, xMax);
        xtr = xbr = constrain(x + yl, 0, xMax);
        ytr = ytl = constrain(y + xl, 0, yMax);
        ybr = ybl = constrain(y - xl, 0, yMax);
    }*/

    xtl = constrain(x - xl, 0, xMax);
    xtr = constrain(x + xl, 0, xMax);
    ytl = constrain(y + yl, 0, yMax);
    ybr = constrain(y - yl, 0, yMax);
    cout << xtl << ", " << ytl << ", " << xtr << ", " << ytl << ", " << xtl << ", " << ybr << ", " << xtr << ", " << ybr << ", ";


    obs[0] = xtl;
    obs[1] = ytl;
    obs[2] = xtr;
    obs[3] = ybr;


    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));
    return obLen;
}


unsigned short stageOb(unsigned short** obstacles, bool team, unsigned short xMax, unsigned short yMax, uint8_t tol, uint8_t Rs) {
    unsigned short obLen = 6, xtl, ytl, ybl, xtm, ytm, xtr;
    uint8_t Rsize = Rs + tol;
    unsigned short obs[6];

    if (team) {
        xtl = 0;
        ytl = yMax;
        ybl = 155 - Rsize;
        xtm = 195 + Rsize;
        ytm = 180 - Rsize;
        xtr = 235 + Rsize;
    }
    else {
        xtr = xMax;
        xtm = xMax - 195 - Rsize;
        ytm = 180 - Rsize;
        ybl = 180 - Rsize;
        xtl = xMax - 235 - Rsize;
        ytl = yMax;
    }

    obs[0] = xtl;
    obs[1] = ytl;
    obs[2] = xtr;
    obs[3] = ybl;
    obs[4] = xtm;
    obs[5] = ytm;


    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));

    return obLen;
}



unsigned short enemyOb(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl) {
    short obLen = 4, xtl, ytl, xtr, ybr;
    unsigned short obs[4];

    /*xtl = xbl = x - xl;
    xtr = xbr = x + xl;
    ytr = ytl = y + yl;
    ybr = ybl = y - yl;
    cout << xtl << ", " << ytl << ", " << xtr << ", " << ytr << ", " << xbl << ", " << ybl << ", " << xbr << ", " << ybr << endl;*/

    /*xtl = xbl = constrain(x - xl, 0, xMax);
    xtr = xbr = constrain(x + xl, 0, xMax);
    ytr = ytl = constrain(y + yl, 0, yMax);
    ybr = ybl = constrain(y - yl, 0, yMax);*/
    
    xtl = constrain(x - xl, 0, xMax);
    xtr = constrain(x + xl, 0, xMax);
    ytl = constrain(y + yl, 0, yMax);
    ybr = constrain(y - yl, 0, yMax);
    cout << xtl << ", " << ytl << ", " << xtr << ", " << ytl << ", " << xtl << ", " << ybr << ", " << xtr << ", " << ybr << ", ";


    obs[0] = xtl;
    obs[1] = ytl;
    obs[2] = xtr;
    obs[3] = ybr;

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

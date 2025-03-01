
#include <iostream>
#include "AStar_HR.h"
#include <set>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;

unsigned short tribObstacles(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, uint8_t xl, uint8_t yl, bool horizontal); // True horizontal, false vertical
unsigned short stageOb(unsigned short** obstacles, bool team); // True blue, false yellow
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
    /*for (unsigned short i = 0; i < 20; i += 2) {
        if (k == 0 || k == 3 || k == 4 || k == 7) {
            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, false, step);
        }
        else {
            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, true, step);
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

    }*/



    // Stage Obstacle
    /*lenObs = stageOb(&obstacles, true, step);


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

    free(tempObs);*/

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



    cout << endl << endl << "END OBSTACLES CREATION" << endl << endl;


    for (int i = 0; i < TotLenObs; i += 2) {
        cout << TotObs[i] << ", " << TotObs[i + 1] << ", ";
    }

    cout << endl;

    cout << "Starting" << endl;

    /*TotObs = (unsigned short*)malloc(sizeof(unsigned short) * 2);
    TotLenObs = 2;
    TotObs[0] = 10;
    TotObs[1] = 10;  */

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
    short obLen = 0, minusLen = 0;
    unsigned short obs[8];

    if (horizontal) {
        x = x - 31;
        y = y - 16;

        

        
    }
    else {
        x = x - 16;
        y = y - 31;

        
    }


    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));
    return (obLen - minusLen);
}


unsigned short stageOb(unsigned short** obstacles, bool team) {
    unsigned short obLen = 0, x = 0, y = 0;
    unsigned short obs[1296];

    if (team) {
        x = 0;
        y = 155 - 22;

        // First horizontal
        for (unsigned short i = 0; i < 434; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // Second horizontal
        y += 1;
        for (unsigned short i = 0; i < 434; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // First vertical
        x = 195 + 22;
        y = 155 - 22;
        for (unsigned short i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // Second vertical
        x -= 1;
        for (unsigned short i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // First small horizontal
        x = 195 + 22;
        y = 180 - 22;
        for (unsigned short i = 0; i < 80; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // Second small horizontal
        y += 1;
        for (unsigned short i = 0; i < 80; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // First small vertical
        x = 235 + 22;
        y = 180 - 22;
        for (unsigned short i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;

        // Second small vertical
        x -= 1;
        for (unsigned short i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;
    }
    else {
        x = 300;
        y = 155 - 22;

        // First horizontal
        for (unsigned short i = 0; i < 434; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // Second horizontal
        y += 1;
        for (unsigned short i = 0; i < 434; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // First vertical
        x = 300 - 195 - 22;
        y = 155 - 22;
        for (unsigned short i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // Second vertical
        x -= 1;
        for (unsigned short i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // First small horizontal
        x = 300 - 195 - 22;
        y = 180 - 22;
        for (unsigned short i = 0; i < 80; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // Second small horizontal
        y += 1;
        for (unsigned short i = 0; i < 80; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // First small vertical
        x = 300 - 235 - 22;
        y = 180 - 22;
        for (unsigned short i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;

        // Second small vertical
        x -= 1;
        for (unsigned short i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;
    }

    /*for (int i = 0; i < obLen; i += 2) {
        cout << obs[i] << ", " << obs[i + 1] << ", ";
    }
    cout << endl;*/


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


#include <iostream>
#include "AStar_HR.h"
#include <set>

using namespace std;

int tribObstacles(int** obstacles, int x, int y, int xMax, int yMax, bool horizontal); // True horizontal, false vertical
int stageOb(int** obstacles, bool team); // True blue, false yellow
int enemyOb(int** obstacles, int x, int y);
void removeDuplicates(int*& x, int*& y, int& size);

int main()
{
    int* xPoints = nullptr;
    int* yPoints = nullptr;
    int len = 0;
    /*int lenObstaclePoints = 51;
    int lenObs = 2 * lenObstaclePoints;*/
	int lenObs = 0;
    int TotLenObs = 0;
    int xMax = 300, yMax = 200;
    //bool grid[150][100];
    int* obstacles = nullptr;
    int* TotObs = nullptr;
    int* tempObs = nullptr;

    bool a[10], b[10];

    cout << "Memory of int len -> " << sizeof(len) << endl;
    //cout << "Memory of int -> " << sizeof(xPoints) << endl;

    /*for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            grid[x][y] = 0;
        }
    }*/

    /*obstacles = (int*)malloc(sizeof(int) * lenObs);
    for (int i = 0; i <= 100; i += 2) {
        obstacles[i] = 150;
        obstacles[i + 1] = 75 + i / 2;
    }*/
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

    int obsStart[20] = {7, 40, 77, 25, 223, 25, 293, 40, 7, 133, 110, 95, 190, 95, 293, 133, 81, 173, 219, 173};
    int k = 0;

    for (int i = 0; i < 20; i += 2) {
        if (k == 0 || k == 3 || k == 4 || k == 7) {
            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, false);
        }
        else {
            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, true);
        }
        k++;
        

        tempObs = (int*)malloc(TotLenObs * sizeof(int));
        if (tempObs == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }

        if (TotLenObs > 0) {
            memcpy(tempObs, TotObs, TotLenObs * sizeof(int));
            free(TotObs);
        }

		TotLenObs += lenObs;

        TotObs = (int*)malloc(TotLenObs * sizeof(int));
        if (TotObs == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }

        if (TotLenObs - lenObs > 0) {
            memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(int));
        }

        memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(int));

        free(tempObs);

    }



    // Stage Obstacle
    lenObs = stageOb(&obstacles, true);


    tempObs = (int*)malloc(TotLenObs * sizeof(int));
    if (tempObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs > 0) {
        memcpy(tempObs, TotObs, TotLenObs * sizeof(int));
        free(TotObs);
    }

    TotLenObs += lenObs;

    TotObs = (int*)malloc(TotLenObs * sizeof(int));
    if (TotObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs - lenObs > 0) {
        memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(int));
    }

    memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(int));

    free(tempObs);



    // Enemy Obstacle
    lenObs = enemyOb(&obstacles, 240, 60);


    tempObs = (int*)malloc(TotLenObs * sizeof(int));
    if (tempObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs > 0) {
        memcpy(tempObs, TotObs, TotLenObs * sizeof(int));
        free(TotObs);
    }

    TotLenObs += lenObs;

    TotObs = (int*)malloc(TotLenObs * sizeof(int));
    if (TotObs == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    if (TotLenObs - lenObs > 0) {
        memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(int));
    }

    memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(int));

    free(tempObs);



    cout << endl << endl << "END OBSTACLES CREATION" << endl << endl;


    /*for (int i = 0; i < TotLenObs; i += 2) {
        cout << TotObs[i] << ", " << TotObs[i + 1] << ", ";
    }*/

    cout << endl;

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

    
    Astar_HR shit(123, 23, 150, 115, xMax, yMax, TotObs, TotLenObs);
    len = shit.pathGeneration();

    xPoints = (int*)malloc(sizeof(int) * len);
    //xPoints = new int(len);
    yPoints = (int*)malloc(sizeof(int) * len);
    //yPoints = new int(len);

    shit.getPath(xPoints, yPoints);

    cout << len << endl;

    cout << "---Before /10---" << endl;
    for (int i = 0; i < len; i++) {
        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
        cout << xPoints[i] << ", " << yPoints[i] << ", ";
    }

    for (int i = 0; i < len; i++) {
        xPoints[i] = xPoints[i] / 10;
        yPoints[i] = yPoints[i] / 10;
    }

    removeDuplicates(xPoints, yPoints, len);

    cout << endl << "---Modfication---" << endl;

    for (int i = 0; i < len; i++) {
        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
        cout << xPoints[i] << ", " << yPoints[i] << ", ";
    }

    cout << endl << "---X---" << endl;

    for (int i = 0; i < len; i++) {
        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
        cout << xPoints[i]*100.0  << ", ";
    }

    cout << endl << "---Y---" << endl;

    for (int i = 0; i < len; i++) {
        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
        cout << yPoints[i]*100.0 << ", ";
    }

    cout << endl << endl;

    for (int i = 0; i < len; i++) {
        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
        cout << xPoints[i]*10 << ", " << yPoints[i]*10 << ", ";
    }
    
}


void removeDuplicates(int*& x, int*& y, int& size) {
    if (size <= 0) return;

    std::set<std::pair<int, int>> seen;
    int* new_x = new int[size]; // Temporary arrays for filtered results
    int* new_y = new int[size];

    int new_size = 0;
    for (int i = 0; i < size; ++i) {
        std::pair<int, int> point = { x[i], y[i] };
        if (seen.find(point) == seen.end()) {  // If not seen before
            seen.insert(point);
            new_x[new_size] = x[i];
            new_y[new_size] = y[i];
            new_size++;
        }
    }

    // Delete old arrays and update pointers
    delete[] x;
    delete[] y;
    x = new int[new_size];
    y = new int[new_size];

    // Copy filtered results
    for (int i = 0; i < new_size; ++i) {
        x[i] = new_x[i];
        y[i] = new_y[i];
    }

    // Clean up temporary arrays
    delete[] new_x;
    delete[] new_y;

    size = new_size;  // Update size
}

int tribObstacles(int** obstacles, int x, int y, int xMax, int yMax, bool horizontal) {
    int obLen = 0, minusLen = 0;
    int obs[1008];


    if (horizontal) {
        x = x - 31;
        y = y - 16;

        //cout << x << "  " << y << endl;

        // Left-to-right

        // First left vertical
        for (int i = 0; i < 64; i += 2) {
            if ((x < 0 || y + i/2 < 0) || (x > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 64;

        // Second left vertical
        x = x + 1;
        for (int i = 0; i < 64; i += 2) {
            if ((x < 0 || y + i/2 < 0) || (x > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 64;

        // First down horizontal
        x = x + 1;
        for (int i = 0; i < 120; i += 2) {
            if ((x + i/2 < 0 || y < 0) || (x + i/2 > xMax || y > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y;
            }
        }
        obLen += 120;

        // Second down horizontal
        for (int i = 0; i < 120; i += 2) {
            if ((x + i/2 < 0 || y + 1 < 0) || (x + i/2 > xMax || y + 1 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y + 1;
            }
        }
        obLen += 120;

        // First up horizontal
        for (int i = 0; i < 120; i += 2) {
            if ((x + i/2 < 0 || y + 31 < 0) || (x + i/2 > xMax || y + 31 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y + 31;
            }
        }
        obLen += 120;

        // Second up horizontal
        for (int i = 0; i < 120; i += 2) {
            if ((x + i/2 < 0 || y + 30 < 0) || (x + i/2 > xMax || y + 30 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y + 30;
            }
        }
        obLen += 120;

        // Third vertical
        x = x + 58;
        for (int i = 0; i < 64; i += 2) {
            if ((x < 0 || y + i/2 < 0) || (x > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 64;

        // Fourth vertical
        x = x + 1;
        for (int i = 0; i < 64; i += 2) {
            if ((x < 0 || y + i/2 < 0) || (x > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 64;
    }
    else {
        x = x - 16;
        y = y - 31;

        //cout << x << "  " << y << endl;

        // Left-to-right

        // First left vertical
        for (int i = 0; i < 64; i += 2) {
            if ((x + i/2 < 0 || y < 0) || (x + i/2 > xMax || y > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y;
            }
        }
        obLen += 64;
		//cout << minusLen << endl;

        // Second left vertical
        y = y + 1;
        for (int i = 0; i < 64; i += 2) {
            if ((x + i/2 < 0 || y < 0) || (x + i/2 > xMax || y > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y;
            }
        }
        obLen += 64;
        //cout << minusLen << endl;

        // First down horizontal
        y = y + 1;
        for (int i = 0; i < 120; i += 2) {
            if ((x < 0 || y + i/2 < 0) || (x > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 120;
        //cout << minusLen << endl;

        // Second down horizontal
        for (int i = 0; i < 120; i += 2) {
            if ((x + 1 < 0 || y + i/2 < 0) || (x + 1 > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + 1;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 120;
        //cout << minusLen << endl;

        // First up horizontal
        for (int i = 0; i < 120; i += 2) {
            if ((x + 31 < 0 || y + i/2 < 0) || (x + 31 > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + 31;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 120;
        //cout << minusLen << endl;

        // Second up horizontal
        for (int i = 0; i < 120; i += 2) {
            if ((x + 30 < 0 || y + i/2 < 0) || (x + 30 > xMax || y + i/2 > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + 30;
                obs[i + obLen + 1 - minusLen] = y + i/2;
            }
        }
        obLen += 120;
        //cout << minusLen << endl;

        // Third vertical
        y = y + 58;
        for (int i = 0; i < 64; i += 2) {
            if ((x + i/2 < 0 || y < 0) || (x + i/2 > xMax || y > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y;
            }
        }
        obLen += 64;
        //cout << minusLen << endl;

        // Fourth vertical
        y = y + 1;
        for (int i = 0; i < 64; i += 2) {
            if ((x + i/2 < 0 || y < 0) || (x + i/2 > xMax || y > yMax)) {
                minusLen += 2;
            }
            else {
                obs[i + obLen - minusLen] = x + i/2;
                obs[i + obLen + 1 - minusLen] = y;
            }
            //cout << i + obLen + 1 - minusLen << endl;
        }
        obLen += 64;
        //cout << minusLen << endl;
    }
    
	//cout << minusLen << endl;
	//cout << obLen << endl;
    
    /*for (int i = 0; i < obLen; i += 2) {
        cout << obs[i] << ", " << obs[i + 1] << ", ";
    }
    cout << endl;*/

    *obstacles = (int*)malloc((obLen - minusLen) * sizeof(int));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, (obLen - minusLen) * sizeof(int));
    return (obLen - minusLen);
}


int stageOb(int** obstacles, bool team) {
    int obLen = 0, x = 0, y = 0;
    int obs[1296];

    if (team) {
        x = 0;
        y = 155 - 22;

        // First horizontal
        for (int i = 0; i < 434; i+=2) {
            obs[i + obLen] = x + i/2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // Second horizontal
        y += 1;
        for (int i = 0; i < 434; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // First vertical
        x = 195 + 22;
        y = 155 - 22;
        for (int i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // Second vertical
        x -= 1;
        for (int i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // First small horizontal
        x = 195 + 22;
        y = 180 - 22;
        for (int i = 0; i < 80; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // Second small horizontal
        y += 1;
        for (int i = 0; i < 80; i += 2) {
            obs[i + obLen] = x + i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // First small vertical
        x = 235 + 22;
        y = 180 - 22;
        for (int i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;

        // Second small vertical
        x -= 1;
        for (int i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;
    }
    else {
        x = 300;
        y = 155 - 22;

        // First horizontal
        for (int i = 0; i < 434; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // Second horizontal
        y += 1;
        for (int i = 0; i < 434; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 434;

        // First vertical
        x = 300-195 - 22;
        y = 155 - 22;
        for (int i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // Second vertical
        x -= 1;
        for (int i = 0; i < 50; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 50;

        // First small horizontal
        x = 300-195 - 22;
        y = 180 - 22;
        for (int i = 0; i < 80; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // Second small horizontal
        y += 1;
        for (int i = 0; i < 80; i += 2) {
            obs[i + obLen] = x - i / 2;
            obs[i + obLen + 1] = y;
        }
        obLen += 80;

        // First small vertical
        x = 300-235 - 22;
        y = 180 - 22;
        for (int i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;

        // Second small vertical
        x -= 1;
        for (int i = 0; i < 84; i += 2) {
            obs[i + obLen] = x;
            obs[i + obLen + 1] = y + i / 2;
        }
        obLen += 84;
    }

    /*for (int i = 0; i < obLen; i += 2) {
        cout << obs[i] << ", " << obs[i + 1] << ", ";
    }
    cout << endl;*/


    *obstacles = (int*)malloc(obLen * sizeof(int));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(int));

    return obLen;
}



int enemyOb(int** obstacles, int x, int y) {
    int obLen = 0;
    int obs[1328];

    // 21 + 21
    x = x - 42;
    y = y - 42; 

    // First left vertical
    for (int i = 0; i < 168; i += 2) {
        obs[i + obLen] = x;
        obs[i + obLen + 1] = y + i/2;
    }
    obLen += 168;

    // Second left Vertical
    x = x + 1;
    for (int i = 0; i < 168; i += 2) {
        obs[i + obLen] = x;
        obs[i + obLen + 1] = y + i/2;
    }
    obLen += 168;

    // First down horizontal
    x = x + 1;
    for (int i = 0; i < 164; i += 2) {
        obs[i + obLen] = x + i/2;
        obs[i + obLen + 1] = y;
    }
    obLen += 164;

    // Second down horizontal
    for (int i = 0; i < 164; i += 2) {
        obs[i + obLen] = x + i/2;
        obs[i + obLen + 1] = y + 1;
    }
    obLen += 164;

    // First up horizontal
    for (int i = 0; i < 164; i += 2) {
        obs[i + obLen] = x + i/2;
        obs[i + obLen + 1] = y + 83;
    }
    obLen += 164;

    // Second up horizontal
    for (int i = 0; i < 164; i += 2) {
        obs[i + obLen] = x + i/2;
        obs[i + obLen + 1] = y + 82;
    }
    obLen += 164;

    // First right vertical
    x = x + 82;
    for (int i = 0; i < 168; i += 2) {
        obs[i + obLen] = x;
        obs[i + obLen + 1] = y + i / 2;
    }
    obLen += 168;

    // Second right Vertical
    x = x + 1;
    for (int i = 0; i < 168; i += 2) {
        obs[i + obLen] = x;
        obs[i + obLen + 1] = y + i / 2;
    }
    obLen += 168;


    *obstacles = (int*)malloc(obLen * sizeof(int));
    if (*obstacles == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }

    memcpy(*obstacles, obs, obLen * sizeof(int));

    return obLen;
}

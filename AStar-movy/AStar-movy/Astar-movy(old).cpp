
//#include <iostream>
//#include "AStar_HR.h"
//#include <set>
//#include <vector>
//#include <cmath>
//#include <windows.h>
//
//using namespace std;
//
//unsigned short tribObstacles(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, bool horizontal, uint8_t step); // True horizontal, false vertical
//unsigned short stageOb(unsigned short** obstacles, bool team, uint8_t step); // True blue, false yellow
////unsigned short enemyOb(unsigned short** obstacles, short xs, short ys, uint8_t xl, uint8_t yl, uint8_t step);
//unsigned short enemyOb(unsigned short** obstacles, short x, short y, uint8_t xl, uint8_t yl, uint8_t step);
////void removeDuplicates(int*& x, int*& y, int& size);
//
//
//
//int main()
//{
//    float* xPoints = nullptr;
//    float* yPoints = nullptr;
//    unsigned short len = 0;
//    /*int lenObstaclePoints = 51;
//    int lenObs = 2 * lenObstaclePoints;*/
//    unsigned short lenObs = 0;
//    unsigned short TotLenObs = 0;
//    unsigned short xMax = 300;
//    uint8_t yMax = 200;
//    //bool grid[150][100];
//    unsigned short* obstacles = nullptr;
//    unsigned short* TotObs = nullptr;
//    unsigned short* tempObs = nullptr;
//    // 1 -> every 1 cm, 5 -> every 5 cm, 10 -> every 10cm 
//    uint8_t step = 5;
//
//    bool a[10], b[10];
//
//
//    cout << "Memory of int len -> " << sizeof(len) << endl;
//    cout << "Memory of size_t -> " << sizeof(size_t) << endl;
//    //cout << "Memory of int -> " << sizeof(xPoints) << endl;
//
//    /*for (int x = 0; x < xMax; x++) {
//        for (int y = 0; y < yMax; y++) {
//            grid[x][y] = 0;
//        }
//    }*/
//
//    /*obstacles = (int*)malloc(sizeof(int) * lenObs);
//    for (int i = 0; i <= 100; i += 2) {
//        obstacles[i] = 150;
//        obstacles[i + 1] = 75 + i / 2;
//    }*/
//    /*obstacles[0] = 3;
//    obstacles[1] = 10;*/
//
//    /*obstacles[2] = 150;
//    obstacles[3] = 101;
//
//    obstacles[4] = 1;
//    obstacles[5] = 2;
//
//    obstacles[6] = 1;
//    obstacles[7] = 3;
//
//    obstacles[8] = 2;
//    obstacles[9] = 3;*/
//
//    short obsStart[20] = { 7, 40, 77, 25, 223, 25, 293, 40, 7, 133, 110, 95, 190, 95, 293, 133, 81, 173, 219, 173 };
//    unsigned short k = 0;
//
//
//    /*for (uint8_t i = 0; i < 20; i++) {
//        if (obsStart[i] % step > step / 2) {
//            obsStart[i] = obsStart[i] + step - obsStart[i] % step;
//        }
//        else {
//            obsStart[i] = obsStart[i] - obsStart[i] % step;
//        }
//    }*/
//
//    /*for (uint8_t i = 0; i < 20; i++) {
//        cout << obsStart[i] << endl;
//    }
//
//    cin >> k;*/
//
//    for (unsigned short i = 0; i < 20; i += 2) {
//        if (k == 0 || k == 3 || k == 4 || k == 7) {
//            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, false, step);
//        }
//        else {
//            lenObs = tribObstacles(&obstacles, obsStart[i], obsStart[i + 1], xMax, yMax, true, step);
//        }
//        k++;
//
//
//        tempObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
//        if (tempObs == nullptr) {
//            cout << "Memory allocation failed!" << endl;
//            exit(1);
//        }
//
//        if (TotLenObs > 0) {
//            memcpy(tempObs, TotObs, TotLenObs * sizeof(unsigned short));
//            free(TotObs);
//        }
//
//        TotLenObs += lenObs;
//
//        TotObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
//        if (TotObs == nullptr) {
//            cout << "Memory allocation failed!" << endl;
//            exit(1);
//        }
//
//        if (TotLenObs - lenObs > 0) {
//            memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(unsigned short));
//        }
//
//        memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(unsigned short));
//
//        free(tempObs);
//
//    }
//
//
//
//    // Stage Obstacle
//    lenObs = stageOb(&obstacles, true, step);
//
//
//    tempObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
//    if (tempObs == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    if (TotLenObs > 0) {
//        memcpy(tempObs, TotObs, TotLenObs * sizeof(unsigned short));
//        free(TotObs);
//    }
//
//    TotLenObs += lenObs;
//
//    TotObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
//    if (TotObs == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    if (TotLenObs - lenObs > 0) {
//        memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(unsigned short));
//    }
//
//    memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(unsigned short));
//
//    free(tempObs);
//
//
//    uint8_t xl = 42, yl = 42;
//    /*if (xl % step > step / 2) {
//        xl = xl + step - xl % step;
//    }
//    else {
//        xl = xl - xl % step;
//    }
//
//    if (yl % step > step / 2) {
//        yl = yl + step - yl % step;
//    }
//    else {
//        yl = yl - yl % step;
//    }*/
//
//    // Enemy Obstacle
//    lenObs = enemyOb(&obstacles, 250, 50, xl, yl, step);
//
//
//    tempObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
//    if (tempObs == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    if (TotLenObs > 0) {
//        memcpy(tempObs, TotObs, TotLenObs * sizeof(unsigned short));
//        free(TotObs);
//    }
//
//    TotLenObs += lenObs;
//
//    TotObs = (unsigned short*)malloc(TotLenObs * sizeof(unsigned short));
//    if (TotObs == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    if (TotLenObs - lenObs > 0) {
//        memcpy(TotObs, tempObs, (TotLenObs - lenObs) * sizeof(unsigned short));
//    }
//
//    memcpy(TotObs + (TotLenObs - lenObs), obstacles, lenObs * sizeof(unsigned short));
//
//    free(tempObs);
//
//
//
//    cout << endl << endl << "END OBSTACLES CREATION" << endl << endl;
//
//
//    /*for (int i = 0; i < TotLenObs; i += 2) {
//        cout << TotObs[i] << ", " << TotObs[i + 1] << ", ";
//    }*/
//
//    cout << endl;
//
//    /*for (int i = 0; i < 10; i++) {
//        a[i] = 1;
//    }*/
//
//    //memcpy(a,b,10*sizeof(int));
//    /*copy(a,a+10,b);
//
//    for (int i = 0; i < 10; i++) {
//        cout << b[i] << endl;
//    }*/
//
//    /*for (int x = 0; x < xMax; x++) {
//        for (int y = 0; y < yMax; y++) {
//            cout << grid[x][y];
//        }
//        cout << endl;
//    }*/
//
//
//    cout << "Starting" << endl;
//
//    /*TotObs = (unsigned short*)malloc(sizeof(unsigned short) * 2);
//    TotLenObs = 2;
//    TotObs[0] = 10;
//    TotObs[1] = 10;  */
//
//    cout << "Number of Obstacles -> " << TotLenObs << endl;
//    cout << "Memory of Obstacles with int -> " << TotLenObs * sizeof(int) << endl;
//    cout << "Memory of Obstacles witn short -> " << TotLenObs * sizeof(unsigned short) << endl;
//
//
//    Astar_HR shit(0, 0, 300, 200, xMax, yMax, TotObs, TotLenObs, true, step);
//    cout << "Memory of shit ->" << sizeof(shit) << endl;
//
//    len = shit.pathGeneration();
//
//    cout << "Memory of shit ->" << sizeof(shit) << endl;
//
//    xPoints = (float*)malloc(sizeof(float) * len);
//    //xPoints = new int(len);
//    yPoints = (float*)malloc(sizeof(float) * len);
//    //yPoints = new int(len);
//
//    shit.getPath(xPoints, yPoints);
//
//    cout << "Memory of shit ->" << sizeof(shit) << endl;
//
//    //cout << len << endl;
//
//    cout << "---Astar points---" << endl;
//    for (unsigned short i = 0; i < len; i++) {
//        //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
//        cout << xPoints[i] << ", " << yPoints[i] << ", ";
//    }
//
//    /*for (int i = 0; i < len; i++) {
//        xPoints[i] = xPoints[i] / 10;
//        yPoints[i] = yPoints[i] / 10;
//    }
//
//    removeDuplicates(xPoints, yPoints, len);*/
//
//    //cout << endl << "---Modfication---" << endl;
//
//    //for (int i = 0; i < len; i++) {
//    //    //cout << "x=" << xPoints[i] << " ,  y=" << yPoints[i] << endl;
//    //    cout << xPoints[i]*10 << ", " << yPoints[i]*10 << ", ";
//    //}
//
//    cout << endl << "---X---" << endl;
//
//    for (unsigned short i = 0; i < len; i++) {
//        cout << xPoints[i] * 10 << ", ";
//    }
//
//    cout << endl << "---Y---" << endl;
//
//    for (unsigned short i = 0; i < len; i++) {
//        cout << yPoints[i] * 10 << ", ";
//    }
//
//    cout << endl << endl;
//
//
//    //vector<Vec2> controlPoints;
//    //for (int i = 0; i < len; i++) {
//    //    controlPoints.push_back(Vec2(xPoints[i], yPoints[i]));
//    //}
//
//    //cout << endl << "----Control points----" << endl;
//
//    //for (const auto& point : controlPoints) {
//    //    cout << point.x << ", " << point.y << ", ";
//    //}
//
//    //cout << endl << endl;
//
//    //int subdivisions = len; // It gives a good number of points that do not alter the trajectory
//    //                          // You can use =len/2, or len*2, but the second is overkill (The higher the subdivisions numbers the more precise)
//    //
//    //vector<Vec2> bezierCurve = bezierPath(controlPoints, subdivisions);
//
//    //cout << endl << "----Bezier curve points----" << endl;
//
//    //
//
//    //for (const auto& point : bezierCurve) {
//    //    cout << point.x*1 << ", " << point.y*1 << ", ";
//    //}
//
//    //cout << endl << endl;
//
//    //for (const auto& point : bezierCurve) {
//    //    cout << point.x * 1 << ", ";
//    //}
//
//    //cout << endl << endl;
//
//    //for (const auto& point : bezierCurve) {
//    //    cout << point.y * 1 << ", ";
//    //}
//
//    //cout << endl << "len = " << subdivisions + 1 << " (subdivisions + 1)" << endl;
//
//    //cout << endl << endl;
//
//
//    //----To test the coputation time of the 2 binomial function ( It was shown that the chat's was better with some improvements----/
//
//    /*unsigned long long millisStart, fmMillisStop, fcMillisStop;
//    double f_m=0, f_c=0;
//    int n = 100;
//    cout << "tgamma(n) -> " << tgamma(n+1) << endl;
//    for (int i = 0; i < n; i++) {
//        millisStart = GetTickCount64();
//        f_c = binomial(n, i);
//        fmMillisStop = GetTickCount64();
//        f_m = bin(n, i);
//        fcMillisStop = GetTickCount64();
//        cout << "i -> " << i << " , Binomial -> " << f_c << " , Bin -> " << f_m << endl;
//        cout << "           |-> " << fmMillisStop - millisStart << "    |-> " << fcMillisStop - fmMillisStop << endl;
//        cout << "start -> " << millisStart << " , fm -> " << fmMillisStop << " , fc -> " << fcMillisStop << endl;
//    }*/
//}
//
//
////void removeDuplicates(int*& x, int*& y, int& size) {
////    if (size <= 0) return;
////
////    std::set<std::pair<int, int>> seen;
////    int* new_x = new int[size]; // Temporary arrays for filtered results
////    int* new_y = new int[size];
////
////    int new_size = 0;
////    for (int i = 0; i < size; ++i) {
////        std::pair<int, int> point = { x[i], y[i] };
////        if (seen.find(point) == seen.end()) {  // If not seen before
////            seen.insert(point);
////            new_x[new_size] = x[i];
////            new_y[new_size] = y[i];
////            new_size++;
////        }
////    }
////
////    // Delete old arrays and update pointers
////    delete[] x;
////    delete[] y;
////    x = new int[new_size];
////    y = new int[new_size];
////
////    // Copy filtered results
////    for (int i = 0; i < new_size; ++i) {
////        x[i] = new_x[i];
////        y[i] = new_y[i];
////    }
////
////    // Clean up temporary arrays
////    delete[] new_x;
////    delete[] new_y;
////
////    size = new_size;  // Update size
////
////
////}
//
//unsigned short tribObstacles(unsigned short** obstacles, short x, short y, unsigned short xMax, unsigned short yMax, bool horizontal, uint8_t step) {
//    unsigned short obLen = 0, minusLen = 0;
//    unsigned short obs[1008];
//
//    if (horizontal) {
//        x = x - 31;
//        y = y - 16;
//
//
//
//        //cout << x << "  " << y << endl;
//
//        // Left-to-right
//
//        // First left vertical
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x < 0 || y + i / 2 < 0) || (x > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 64;
//
//        // Second left vertical
//        x = x + 1;
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x < 0 || y + i / 2 < 0) || (x > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 64;
//
//        // First down horizontal
//        x = x + 1;
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + i / 2 < 0 || y < 0) || (x + i / 2 > xMax || y > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y;
//            }
//        }
//        obLen += 120;
//
//        // Second down horizontal
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + i / 2 < 0 || y + 1 < 0) || (x + i / 2 > xMax || y + 1 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y + 1;
//            }
//        }
//        obLen += 120;
//
//        // First up horizontal
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + i / 2 < 0 || y + 31 < 0) || (x + i / 2 > xMax || y + 31 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y + 31;
//            }
//        }
//        obLen += 120;
//
//        // Second up horizontal
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + i / 2 < 0 || y + 30 < 0) || (x + i / 2 > xMax || y + 30 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y + 30;
//            }
//        }
//        obLen += 120;
//
//        // Third vertical
//        x = x + 58;
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x < 0 || y + i / 2 < 0) || (x > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 64;
//
//        // Fourth vertical
//        x = x + 1;
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x < 0 || y + i / 2 < 0) || (x > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 64;
//    }
//    else {
//        x = x - 16;
//        y = y - 31;
//
//        //cout << x << "  " << y << endl;
//
//        // Left-to-right
//
//        // First left vertical
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x + i / 2 < 0 || y < 0) || (x + i / 2 > xMax || y > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y;
//            }
//        }
//        obLen += 64;
//        //cout << minusLen << endl;
//
//        // Second left vertical
//        y = y + 1;
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x + i / 2 < 0 || y < 0) || (x + i / 2 > xMax || y > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y;
//            }
//        }
//        obLen += 64;
//        //cout << minusLen << endl;
//
//        // First down horizontal
//        y = y + 1;
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x < 0 || y + i / 2 < 0) || (x > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 120;
//        //cout << minusLen << endl;
//
//        // Second down horizontal
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + 1 < 0 || y + i / 2 < 0) || (x + 1 > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + 1;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 120;
//        //cout << minusLen << endl;
//
//        // First up horizontal
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + 31 < 0 || y + i / 2 < 0) || (x + 31 > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + 31;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 120;
//        //cout << minusLen << endl;
//
//        // Second up horizontal
//        for (unsigned short i = 0; i < 120; i += 2) {
//            if ((x + 30 < 0 || y + i / 2 < 0) || (x + 30 > xMax || y + i / 2 > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + 30;
//                obs[i + obLen + 1 - minusLen] = y + i / 2;
//            }
//        }
//        obLen += 120;
//        //cout << minusLen << endl;
//
//        // Third vertical
//        y = y + 58;
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x + i / 2 < 0 || y < 0) || (x + i / 2 > xMax || y > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y;
//            }
//        }
//        obLen += 64;
//        //cout << minusLen << endl;
//
//        // Fourth vertical
//        y = y + 1;
//        for (unsigned short i = 0; i < 64; i += 2) {
//            if ((x + i / 2 < 0 || y < 0) || (x + i / 2 > xMax || y > yMax)) {
//                minusLen += 2;
//            }
//            else {
//                obs[i + obLen - minusLen] = x + i / 2;
//                obs[i + obLen + 1 - minusLen] = y;
//            }
//            //cout << i + obLen + 1 - minusLen << endl;
//        }
//        obLen += 64;
//        //cout << minusLen << endl;
//    }
//
//    //cout << minusLen << endl;
//    //cout << obLen << endl;
//
//    /*for (int i = 0; i < obLen; i += 2) {
//        cout << obs[i] << ", " << obs[i + 1] << ", ";
//    }
//    cout << endl;*/
//
//    *obstacles = (unsigned short*)malloc((obLen - minusLen) * sizeof(unsigned short));
//    if (*obstacles == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    memcpy(*obstacles, obs, (obLen - minusLen) * sizeof(unsigned short));
//    return (obLen - minusLen);
//}
//
//
//unsigned short stageOb(unsigned short** obstacles, bool team, uint8_t step) {
//    unsigned short obLen = 0, x = 0, y = 0;
//    unsigned short obs[1296];
//
//    if (team) {
//        x = 0;
//        y = 155 - 22;
//
//        // First horizontal
//        for (unsigned short i = 0; i < 434; i += 2) {
//            obs[i + obLen] = x + i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 434;
//
//        // Second horizontal
//        y += 1;
//        for (unsigned short i = 0; i < 434; i += 2) {
//            obs[i + obLen] = x + i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 434;
//
//        // First vertical
//        x = 195 + 22;
//        y = 155 - 22;
//        for (unsigned short i = 0; i < 50; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 50;
//
//        // Second vertical
//        x -= 1;
//        for (unsigned short i = 0; i < 50; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 50;
//
//        // First small horizontal
//        x = 195 + 22;
//        y = 180 - 22;
//        for (unsigned short i = 0; i < 80; i += 2) {
//            obs[i + obLen] = x + i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 80;
//
//        // Second small horizontal
//        y += 1;
//        for (unsigned short i = 0; i < 80; i += 2) {
//            obs[i + obLen] = x + i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 80;
//
//        // First small vertical
//        x = 235 + 22;
//        y = 180 - 22;
//        for (unsigned short i = 0; i < 84; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 84;
//
//        // Second small vertical
//        x -= 1;
//        for (unsigned short i = 0; i < 84; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 84;
//    }
//    else {
//        x = 300;
//        y = 155 - 22;
//
//        // First horizontal
//        for (unsigned short i = 0; i < 434; i += 2) {
//            obs[i + obLen] = x - i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 434;
//
//        // Second horizontal
//        y += 1;
//        for (unsigned short i = 0; i < 434; i += 2) {
//            obs[i + obLen] = x - i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 434;
//
//        // First vertical
//        x = 300 - 195 - 22;
//        y = 155 - 22;
//        for (unsigned short i = 0; i < 50; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 50;
//
//        // Second vertical
//        x -= 1;
//        for (unsigned short i = 0; i < 50; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 50;
//
//        // First small horizontal
//        x = 300 - 195 - 22;
//        y = 180 - 22;
//        for (unsigned short i = 0; i < 80; i += 2) {
//            obs[i + obLen] = x - i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 80;
//
//        // Second small horizontal
//        y += 1;
//        for (unsigned short i = 0; i < 80; i += 2) {
//            obs[i + obLen] = x - i / 2;
//            obs[i + obLen + 1] = y;
//        }
//        obLen += 80;
//
//        // First small vertical
//        x = 300 - 235 - 22;
//        y = 180 - 22;
//        for (unsigned short i = 0; i < 84; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 84;
//
//        // Second small vertical
//        x -= 1;
//        for (unsigned short i = 0; i < 84; i += 2) {
//            obs[i + obLen] = x;
//            obs[i + obLen + 1] = y + i / 2;
//        }
//        obLen += 84;
//    }
//
//    /*for (int i = 0; i < obLen; i += 2) {
//        cout << obs[i] << ", " << obs[i + 1] << ", ";
//    }
//    cout << endl;*/
//
//
//    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
//    if (*obstacles == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));
//
//    return obLen;
//}
//
//
//
////unsigned short enemyOb(unsigned short** obstacles, short xs, short ys, uint8_t xl, uint8_t yl, uint8_t step) {
//unsigned short enemyOb(unsigned short** obstacles, short x, short y, uint8_t xl, uint8_t yl, uint8_t step) {
//    //unsigned short obLen = 8*(xl + yl - 2) ;
//    unsigned short obs[1328];
//    unsigned short obLen = 0, xtl, ytl, xtr, ytr, xbl, ybl, xbr, ybr;
//    //unsigned short* obs;
//
//    /*if (obLen % step != 0) {
//        obLen = obLen/step + 1 ;
//    }
//    else {
//        obLen = obLen / step;
//    } */
//
//    /*cout << obLen << endl;
//    cin >> obLen;*/
//
//    //obs = (unsigned short*)malloc(sizeof(unsigned short) * obLen);
//
//    obLen = 0;
//
//    xtl = xbl = x - xl;
//    xtr = xbr = x + xl;
//    ytr = ytl = y + yl;
//    ybr = ybl = y - yl;
//    cout << xtl << ", " << ytl << ", " << xtr << ", " << ytr << ", " << xbl << ", " << ybl << ", " << xbr << ", " << ybr << endl;
//
//    // 21 + 21
//    x = x - 42;
//    y = y - 42;
//
//    // First left vertical
//    for (unsigned short i = 0; i < 168; i += 2) {
//        obs[i + obLen] = x;
//        obs[i + obLen + 1] = y + i / 2;
//    }
//    obLen += 168;
//
//    // Second left Vertical
//    //x = x + step;
//    /*if (step != 1) {
//        y = y + step;
//    }*/
//    x = x + 1;
//    for (unsigned short i = 0; i < 168; i += 2) {
//        obs[i + obLen] = x;
//        obs[i + obLen + 1] = y + i / 2;
//    }
//    obLen += 168;
//
//
//    // First down horizontal
//    //x = x - step + 1;
//    /*if (step != 1) {
//        y = y - step;
//    }*/
//    x = x + 1;
//    for (unsigned short i = 0; i < 164; i += 2) {
//        obs[i + obLen] = x + i / 2;
//        obs[i + obLen + 1] = y;
//    }
//    obLen += 164;
//
//    // Second down horizontal
//    for (unsigned short i = 0; i < 164; i += 2) {
//        obs[i + obLen] = x + i / 2;
//        obs[i + obLen + 1] = y + 1;
//    }
//    obLen += 164;
//
//    // First up horizontal
//    for (unsigned short i = 0; i < 164; i += 2) {
//        obs[i + obLen] = x + i / 2;
//        obs[i + obLen + 1] = y + 83;
//    }
//    obLen += 164;
//
//    // Second up horizontal
//    for (unsigned short i = 0; i < 164; i += 2) {
//        obs[i + obLen] = x + i / 2;
//        obs[i + obLen + 1] = y + 82;
//    }
//    obLen += 164;
//
//    // First right vertical
//    x = x + 82;
//    for (unsigned short i = 0; i < 168; i += 2) {
//        obs[i + obLen] = x;
//        obs[i + obLen + 1] = y + i / 2;
//    }
//    obLen += 168;
//
//    // Second right Vertical
//    x = x + 1;
//    for (unsigned short i = 0; i < 168; i += 2) {
//        obs[i + obLen] = x;
//        obs[i + obLen + 1] = y + i / 2;
//    }
//    obLen += 168;
//
//
//    for (int i = 0; i < obLen; i += 2) {
//        cout << obs[i] << ", " << obs[i + 1] << ", ";
//    }
//    cout << endl;
//
//    cin >> obLen;
//
//    *obstacles = (unsigned short*)malloc(obLen * sizeof(unsigned short));
//    if (*obstacles == nullptr) {
//        cout << "Memory allocation failed!" << endl;
//        exit(1);
//    }
//
//    memcpy(*obstacles, obs, obLen * sizeof(unsigned short));
//
//    return obLen;
//}

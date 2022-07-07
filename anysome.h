#ifndef ANYSOME_H
#define ANYSOME_H
#include <iostream>
using namespace std;

void showBricks(const int K = 3,const int N = 16){
    //const int K = 3, N = 16;
    for(int n = 0; n < N; n++)
        cout << "+---";
    cout << "+" << endl;
    for(int k = 0; k < K; k++){
        for(int n = 0; n < N; n++)
            cout << "|   ";
        cout << "|" << endl;
        for(int n = 0; n < N; n++)
            cout << "+-+-";
        cout << "+" << endl;
        for(int n = 0; n < N; n++)
            cout << "  | ";
        cout << " " << endl;
        for(int n = 0; n < N; n++)
            cout << "+-+-";
        cout << "+" << endl;
    }
    for(int n = 0; n < N; n++)
        cout << "|   ";
    cout << "|" << endl;
    for(int n = 0; n < N; n++)
        cout << "+---";
    cout << "+" << endl;
}

enum {lurd = 32, LURD = 197,
      lUrD = 179, LuRd = 196,
      lURd = 192, luRD = 218, LurD = 191, LUrd = 217,
      LURd = 193, LUrD = 180, LuRD = 194, lURD = 195};

void showCell(){
        cout << char(luRD) << char(LuRd) << char(LuRD) << char(LuRd) << char(LurD) << endl;
        cout << char(lUrD) << char(lurd) << char(lUrD) << char(lurd) << char(lUrD) << endl;
        cout << char(lURD) << char(LuRd) << char(LURD) << char(LuRd) << char(LUrD) << endl;
        cout << char(lUrD) << char(lurd) << char(lUrD) << char(lurd) << char(lUrD) << endl;
        cout << char(lURd) << char(LuRd) << char(LURd) << char(LuRd) << char(LUrd) << endl;
}

#endif // ANYSOME_H

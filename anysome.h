#ifndef ANYSOME_H
#define ANYSOME_H
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <openssl/md5.h>
#include <QString>

using namespace std;

void getMD5(){
    QString str = "екатерина андреевна ермолина";
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.data(), 26, result);
    for(int k = 0; k < MD5_DIGEST_LENGTH; ++k){
        printf("%02x", result[k]);
        if(k == 3 || k == 5 || k == 7  || k == 9)
            printf("%c", '-');

    }
    std::cout << std::endl;
}

void testFunsString(){
     int ch = getchar();
     putchar('\t');
     char str[200]{"ddd"};
     puts(str);
     strcat(str, "sss");
     puts(str);
     strncat(str, "fff", 1); // concat
     puts(str);
     char* c1 = strchr(str, 's'); // find char from brgin
     cout << c1 << endl;
     char* c2 = strrchr(str, 's'); // find char from end
     cout << c2 << endl;
     cout << strncmp("Abcd", "Abc", 3) << endl; // is equal less or more
     cout << strcspn("abcdef", "df") << endl; // length of subsstring without symbs from string 2
     cout << strlen("abcdefgh") << endl;
     cout << strpbrk("absdefg", "hf") << endl; // any syms from string 2 search in string 1
     cout << strstr("abscefg", "ce") << endl; // searc string in string
     char strs[]{"abcdcef"};
     cout << strtok(strs, "c") << endl;
     double val1 = atof("1212.1");
     int val2 = atoi("12");
     cout << ch << " " << (char)ch << endl;
}

void averSix(){
    const int n = 6;
    int arr[n]{0};
    int sum = 0;
    for(int k = 0; k < 12; k++){
        sum -= arr[k%6];
        arr[k%6] = k;
        sum += arr[k%6];
        cout << sum << "   ";
        for(int m = 0; m < 6; m++){
            cout << arr[m] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void showGraph(){
    double x = 0, y;
    while(x < 10){
        if(x > 0 && abs(log(x)) > 1.0e-6 ){
            y = sin(x) * sin(x) / log(x);
            cout << x << '\t' << y << endl;
        }
        x += 0.1;
    }
}

void testArray(){
    int arr[5]{0, 1, 2, 3, 4};
    int g1 = 122;
    int g2 = 222;
    int g3 = 322;

    for(int k = 0; k < 10; k++){
        cout << arr[k] << " ";
    }
    cout << endl;
}

int GetRandomNumber(int min, int max) {
    srand(time(NULL));
    int num = min + rand() % (max - min +1);
    return num;
}

void romb(){
    const int h = 8, w = 22;
    bool ex;
    cout << endl;
    for(int y = -h; y <= h; y++){
        cout << "   ";
        for(int x = -w; x <= w; x++){
                ex = (y<0)? abs(x*h/w) <= y+h : abs(x*h/w) <= (-y+h);
                cout << (ex? "* " : "  ");
        }
        cout << endl;
    }
    cout << endl;
}

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

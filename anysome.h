#ifndef ANYSOME_H
#define ANYSOME_H
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

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

int game2() {
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    int namber, answer, n = 1;
    namber = GetRandomNumber(1, 500);
    cout << "Мы загадали число от 1 до 500" << endl;
    cout << "Введите это число" << endl;
    cin >> answer;
    while (answer != namber) {
        n++;
        if (answer == 0) {
            cout << "Вы вышли из программы";
            return 0;
        }
        else if (answer < namber) {
            cout << "Упсс, вы не угадали, попробуйте снова" << endl;
            cout << "Подсказка, Ваше число меньше загаданного" << endl;
            cin >> answer;
        }
        else if (answer > namber) {
            cout << "Упсс, вы не угадали, попробуйте снова" << endl;
            cout << "Подсказка, Ваше число больше загаданного" << endl;
            cin >> answer;
        }
    }
    cout << "Поздравляем, Вы угадали!!!" << endl;
    cout << "Количество попыток: " << n << endl;
    cout << "Вы потратили " << clock() / 1000.0 << "секунд" << endl;
}

void game1(){
    cout << "\n\t\t\t\t\t    GUESS THE NUMBER GAME\n\n\t\t\t\t  Input number at 1 to 500(input 0 to exit):\n\t\t\t\t\t\t     ";
        int num = 501;
        int start_time = clock_t();
        cout << start_time;
        int counter = 0;
        srand(time(NULL));
        int r = 200;//1 + rand() % 500;
        while (r != num && num != 0) {
            cin >> num;
            if (num < r) {
                cout << "\t\t\t\t\t     Your number is LESS\n\t\t\t\t\t     Input your number\n\t\t\t\t\t\t     ";
                counter++;

            }
            else if (num > r) {
                cout << "\t\t\t\t\t     Your number is MORE\n\t\t\t\t\t     Input your number\n\t\t\t\t\t\t     ";
                counter++;

            }

            }
            if (num != 0) {
                long stop_time = clock();
                cout << stop_time;
                //int sec = (stop_time - start_time) / 1000 % 60;
                //int min = (stop_time - start_time) / 1000 / 60;
                counter++;
                cout << "\t\t\t\t\t\t\  YOUR WIN\n\n\t\t\t\t\t   Number of attempts - " << counter <<
                    "\n\n\t\t\t\t\t    Yor time - " << "min" << "min:" << stop_time/1000.0 << "sec";
            }
            else
                cout << "\t\t\t\t\t\t    Exit";
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

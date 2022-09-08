#ifndef BRACKETBALANCER_H
#define BRACKETBALANCER_H
#include <iostream>
#include "stack.h"

using namespace std;

class BracketBalacner{
    static bool isOpenBracket(char ch){
        return (ch == '(') || (ch == '[') || (ch == '{') || (ch == '<');
    }

    static bool isCloseBracket(char ch){
        return (ch == ')') || (ch == ']') || (ch == '}') || (ch == '>');
    }

    static bool isPair(char ch1, char ch2){
        if (ch1 > ch2)
            swap(ch1, ch2);
        bool res = ((ch1 == '(') && (ch2 == ')')) ||
                ((ch1 == '[') && (ch2 == ']')) ||
                ((ch1 == '{') && (ch2 == '}')) ||
                ((ch1 == '<') && (ch2 == '>')) ;
        return res;
    }

public:
    static bool execute(string expr) {
        Stack<char> brakets((int)expr.size());
        for(int k = 0; k < (int)expr.size(); k++){
            if(isOpenBracket(expr[k])){
                brakets.push(expr[k]);
            } else if (isCloseBracket(expr[k])){
                if((brakets.size() > 0) && isPair(brakets.top(), expr[k]))
                    brakets.pop();
                else
                    return false;
            }
        }
        return brakets.empty();
    }

    static void testBracketBalacner(){
        cout << "start testBracketBalacner" << endl;
        cout << "Test 1 " << (execute("")                  ?  "GOOD": "BAD") << endl;
        cout << "Test 2 " << (execute("a(b[c{d<e>f}g]h)i") ?  "GOOD": "BAD") << endl;
        cout << "Test 3 " << (execute("a(b[c{d<e>f}g]h)i") ?  "GOOD": "BAD") << endl;
        cout << "Test 4 " << (execute("a(b[c{d<e>f}g]hi")  ?  "BAD" : "GOOD") << endl;
        cout << "Test 5 " << (execute("a(b[c{d<e}f>g]h)i") ?  "BAD" : "GOOD") << endl;
        cout << "Test 6 " << (execute("({x-y-z}*[x+2y]-(z+4x))") ?  "GOOD" : "BAD") << endl;
        cout << "Test 7 " << (execute("([x-y-z}*[x+2y)-{z+4x)]") ?  "BAD" : "GOOD") << endl;
        cout << "end testBracketBalacner" << endl;
    }
};
#endif // BRACKETBALANCER_H

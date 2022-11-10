#include <iostream>
#include <stack>
#include <ctime>
#include <list>

using namespace std;

void test1();

int main() {
    test1();
}

struct Paticipants {
    string name;
    int task;
    int penalty;
};


struct Discipline {
    string name;
    int max_patic;
    list<Paticipants> pats;
};

class DBflyfigure {
    stack<Discipline> disc;
    stack<Paticipants> patisipants;

public:
    DBflyfigure() {};
    void generate_data() {

    }

    void show_finalist() {

    }
};

string* cutStr(string str) {
    int count = 1;
    for (int k = 0; k < str.length(); k++) {
        if (str[k] == ',')
            count++;
    }
    string* res = new string[count];
    count = 0;
    int bg = 0, k;
    for (k = 0; k < str.length(); k++) {
        if (str[k] == ',') {
            res[count] = str.substr(bg, k-bg);
            bg = k+1;
            count++;
        }
    }
    res[count] = str.substr(bg, k - bg);
    return res;
}

void test1() {
    int n;
    cin >> n;
    string str;
    string* arr;
    list<Discipline> discs;
    for (int m = 0; m < n; m++) {
        cin >> str;
        arr = cutStr(str);
        discs.push_back(Discipline{ arr[0], atoi(arr[1].data())});
    }
    int k;
    cin >> k;

    for (int m = 0; m < k; m++) {
        cin >> str;
        arr = cutStr(str);
        for (list<Discipline>::iterator it =  discs.begin(); it != discs.end(); ++it) {
            //cout << arr[0] << " " << arr[1] << " " << it->name;
            if (!arr[1].compare(it->name)){
                it->pats.push_back(Paticipants{arr[0], atoi(arr[2].data()), atoi(arr[3].data())});
                break;
            //cout << " *";
            }
            //cout << endl;
        }
    }

    for (list<Discipline>::iterator it =  discs.begin(); it != discs.end(); ++it) {
            it->pats.sort([](Paticipants p1, Paticipants p2){
                return ((p1.task > p2.task) || (p1.task == p2.task && p1.penalty < p2.penalty));
            });
    }

    cout << "WINNERS: " << endl;
    for (list<Discipline>::iterator it =  discs.begin(); it != discs.end(); ++it) {
        for(int k = 0; k < it->max_patic; k++){
            cout << it->pats.front().name << endl;
            it->pats.pop_front();
        }
    }
}

int main() {
    test1();
}

/*
 2
ear_flying,1
sun_bathing,1
3
cheburashka,ear_flying,11,100
dambo,ear_flying,10,0
crocodile_gena,sun_bathing,11,10

1
ear_flying,1
2
dambo,ear_flying,7,234
cheburahka,ear_flying,7,123

2
cloud_developer,2
cloud_hacker,3
5
anonimus,cloud_hacker,6,0
bs,cloud_developer,6,1
ja,cloud_hacker,5,100500
bg,cloud_developer,3,1
guc,cloud_hacker,2,0 
*/

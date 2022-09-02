#include "phonebook_with_proxy.h"
#include <string>
#include <time.h>

phonebook_with_proxy::phonebook_with_proxy()
{

}

void phonebook_with_proxy::generate_dbfile(int size){
    FILE *fl;
    srand(time(NULL));
    fl = fopen(dbfilename.data(), "w");
    fprintf(fl, "Phone Number      Abonent\n");
    string str = "";
    int num = 1000000;
    int curr_operator = 0;

    const int numNames = 21;
    const string names[numNames]{
        "Marina", "Ivan", "Vasya",
        "Petya", "Sveta", "Masha",
        "Kolya", "Anton", "Igor",
        "Artem", "Lena", "Jim",
        "Sanya", "Diana", "Vera",
        "Artur", "Misha", "Andrey",
        "Sergey", "Kostya", "Valentin"};

    const int numSurNames = 21;
    const string surnames[numNames]{
        "Vitkin", "Pavlov", "Denisov",
        "Kuznecov", "Ershov", "Tihov",
        "Goncharov", "Petrov", "Vasiliev",
        "Vereshagin", "Babat", "Alekseev",
        "Hromyh", "Rudakov", "Saveliev",
        "Lenin", "Nilson", "Kim",
        "Stalin", "Gorbach", "Pedenko"};

    const int numOperator = 5;
    const int operators[numOperator]{928, 961, 950, 951, 988};

    for(int k = 0; k < size; k++){
        str =  "+7";
        num += rand()%600;
        if(num > 9999999){
            num -= 8999999;
            ++curr_operator;
        }
        str += to_string(operators[curr_operator]);
        str += to_string(num);
        str += "      " + names[rand()%numNames];
        str += " " + surnames[rand()%numSurNames] + "\n";
        fprintf(fl, "%s", str.c_str());
    }
    fclose(fl);
}

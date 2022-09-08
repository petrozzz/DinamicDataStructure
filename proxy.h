#ifndef PROXY_H
#define PROXY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Cash{
    string id;
    string date;
    string data;
    bool operator==(string id){
        return (this->id).compare(id);
    }
};

class Proxy
{
private:
    vector<Cash> cash;
    string path;
public:
    Proxy(string path = ""){
        this->path = path;
    }

    string get(string id){
        string data, date;
        if(cash.empty()){
            data = getData(id);
        } else {
            bool is_find = false;
            for(Cash& line: cash){
                if(line.id == id){
                    is_find = true;
                    if(line.date == date){
                        data = line.data;
                    } else {
                        data = getData(id);
                        line.data = data;
                        line.date = date;
                    }
                    break;
                }
            }
            if(!is_find){
                data = getData(id);
                cash.push_back(Cash{id, data, date});
            }
        }
        return data;
    }
private:
    string getData(string id){
        string res;
        return res;
    }

    void changeDate(string path, string newDate){
        string str, str2;
        ifstream in(path);
        if(in.is_open()){
            while(getline(in, str)){
                str2 += str;
                str2 += "\n";
            }
            in.close();
        } else {
            throw "File cannot open.";
        }


    }

};

#endif // PROXY_H

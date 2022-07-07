#ifndef BUSSTATION_H
#define BUSSTATION_H
#include <iostream>
#include "queue.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

const int numNames = 21;
const string names[numNames]{
    "Marina", "Ivan", "Vasya",
    "Petya", "Sveta", "Masha",
    "Kolya", "Anton", "Igor",
    "Artem", "Lena", "Jim",
    "Sanya", "Diana", "Vera",
    "Artur", "Misha", "Andrey",
    "Sergey", "Kostya", "Valentin"};

class Passenger : Man{
private:
    int time;
public:
    Passenger() {}
    Passenger(string name, int time): Man{name}, time(time){
    }
    int getTime() const{
        return time;
    }
    friend ostream& operator <<(ostream& out,  Passenger& passenger) {
        out << passenger.getName() << "(" << passenger.time << ") ";
        return out;
    }
};

class BusStation{
    int minutesFromMN = 0;
    Queue<Passenger> peoples;
    int logPriority = 0;
    int MaxMinutes = 0;
    int timeBusInterval = 0;
    int maxPlaceInBus = 0;
    double probabPas = 0;
    double probabPlace = 0;



public:
    BusStation(int logPriority = 1,
               int timeBusInterval = 10,
               int MaxMinutes = 24 * 60,
               int maxPlaceInBus = 12,
               double probabPas = 0.05,
               double probabPlace = 0.01):peoples(100) {
        this->logPriority = logPriority;
        this->timeBusInterval = timeBusInterval;
        this->MaxMinutes = MaxMinutes;
        this->timeBusInterval = timeBusInterval;
        this->maxPlaceInBus = maxPlaceInBus;
        this->probabPas = probabPas;
        this->probabPlace = probabPlace;
        srand(time(NULL));
    }

    ~BusStation() {
    }

        void start(){
        cout << "time  wait plac left stay  free" << endl;
        int passPeople = 0;
        int passCounter = 0;
        int waiting_time = 0;
        int aver_time = 0;
        int max_time = 0;
        int hour, min;

        int num_people = 0;
        int num_passengers = 0;
        int num_place =0;

        while(minutesFromMN < MaxMinutes ){
            if (rand() % 10000 >= (1 - probabPas) * 10000 ){
                Passenger passenger(names[rand() % numNames], minutesFromMN);
                peoples.push(passenger);
                passPeople++;
                num_people++;
            }

            if((minutesFromMN % timeBusInterval) == 0){
                for(int k = 0; k < maxPlaceInBus; k++ ){
                    if (rand() % 10000 >= (1 - probabPlace) * 10000){
                        num_place++;
                        if(!peoples.empty()){
                            num_passengers++;
                            waiting_time = minutesFromMN - peoples.back().getTime();
                            aver_time += waiting_time;
                            max_time = (waiting_time > max_time)? waiting_time: max_time;
                            passCounter++;
                            peoples.pop();
                        }
                    }
                }
                hour = minutesFromMN / 60;
                min = minutesFromMN % 60;
                cout << ((hour <= 9)? "0": "") << hour  << ":" << ((min <= 9)? "0": "") << min << " ";
                if(logPriority > 0)
                    cout << num_people << "    "  << num_place << "    " << num_passengers << "    "
                         << num_people - num_passengers << "    " << num_place-num_passengers << endl;
                num_people -= num_passengers;
                num_place = 0;
                num_passengers = 0;
            }
            if(logPriority > 1)
                showDataStructure(peoples);
            minutesFromMN++;
        }
        cout << "Came " << passPeople << ". Leave " << passCounter << ". Av. waiting time "
             << (double)aver_time / passCounter << " m. " << " max waiting time " << max_time << " m." <<endl;
    }

    void stop(){

    }

    void refresh(){
        int minutesFromMN = 0;
    }
};

void testBusStation(){
    cout << "start testBusStation" << endl;
    BusStation busstation(/*int logPriority = */ 1,
                             /*int timeBusInterval =*/ 10,
                             /*int MaxMinutes =*/ 24 * 60,
                             /*int maxPlaceInBus =*/ 12,
                             /*double probabPas =*/ 0.1,
                             /*double probabPlace =*/ 0.2);
    busstation.start();
    cout << "end testBusStation" << endl;
}



#endif // BUSSTATION_H

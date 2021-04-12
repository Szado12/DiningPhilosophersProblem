#include <iostream>
#include <conio.h>
#include "Table.h"
using namespace std;
int main()
{
    srand(time(NULL));
    int philosophers, eatingTime, sleepingTime;

    cout << "Set number of philosophers:" << endl;
    cin >> philosophers;
    cout << "Set eating time in ms:" << endl;
    cin >> eatingTime;
    cout << "Set sleeping time in ms:" << endl;
    cin >> sleepingTime;
    Table* table = new Table(philosophers, sleepingTime,eatingTime);
    table->StartSimulation();
    while (_getch() != 'q');
    table->StopSimulation();
    return 0;
}


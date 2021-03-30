#include <iostream>
#include "Table.h"
using namespace std;
int main()
{
    srand(time(NULL));
    Table* table = new Table(20, 2000, 2000);
    table->StartSimulation();
    return 0;
}


#include "Table.h"

Table::Table(int amount, int sleepTime, int eatTime)
{
	philosophers = new vector<Philosopher*>();
	forks = new vector<Fork*>();
	threads = new vector<thread*>();
	NumberOfP = amount;

	for (int i = 0; i < amount; i++) {
		forks->push_back(new Fork(i));
	}
	for (int i = 0; i < amount; i++) {
		philosophers->push_back(new Philosopher(i, eatTime, sleepTime));
		(philosophers->at(i))->setForks(forks->at(i), forks->at((i + 1) % amount));
	}
}
void Table::Print() {
	while (simulation) {
		for (int j = 0; j < 10; j++)
		{
			system("cls");
			for (int i = 0; i < NumberOfP; i++)
			{
				philosophers->at(i)->Print();
			}
			this_thread::sleep_for(chrono::milliseconds(2000));

		}
	}
}
void Table::StartSimulation()
{
	for (int i = 0; i < NumberOfP; i++) 
	{
		threads->push_back(new thread(&Philosopher::Simulate,philosophers->at(i)));
	}
	simulation = true;
	printing = new thread(&Table::Print,this);
}


	for (int i = 0; i < NumberOfP; i++)
	{
		philosophers->at(i)->StopSimulation();
		threads->at(i)->join();
	}
	for (int i = 0; i < NumberOfP; i++)
	{
		philosophers->at(i)->Print();
	}
	simulation = false;
	printing->join();

}


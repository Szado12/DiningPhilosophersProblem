#pragma once
#include "Fork.h"
#include "Philosopher.h"
#include <vector>
#include <thread>
class Table
{
private:
	int NumberOfP;
	bool simulation;
	thread* printing;
	vector<Philosopher*> *philosophers;
	vector<Fork*> *forks;
	vector<thread*> *threads;
public:
	Table(int id, int sleepTime, int eatTime);
	void StartSimulation();
	void StopSimulation();
	void Print();
};


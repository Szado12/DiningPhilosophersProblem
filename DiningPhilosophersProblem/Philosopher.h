#pragma once
#include "Fork.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
class Philosopher
{
private:
	int id;
	string state;
	Fork* forkLeft;
	Fork* forkRight;
	bool hasLeft;
	bool hasRight;
	int meals;
	bool simulateProgress;
	int eatingTime;
	int sleepingtime;

public:
	Philosopher(int id, int eatingTime, int sleepingtime);
	void setForks(Fork* forkLeft, Fork* forkRight);
	bool TakeLeftFork();
	bool TakeRightFork();
	void PutLeftFork();
	void PutRightFork();
	void Print();
	void Simulate();
	void Eat();
	void Sleep();
	void StopSimulation();
};


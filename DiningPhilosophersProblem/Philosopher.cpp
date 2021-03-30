#include "Philosopher.h"

Philosopher::Philosopher(int id, int eatingTime, int sleepingtime)
{
	this->id = id;
	this->state = "waiting";
	this->hasLeft = false;
	this->hasRight = false;
	this->eatingTime = eatingTime;
	this->sleepingtime = sleepingtime;
	this->simulateProgress = true;
	this->meals = 0;
}

void Philosopher::setForks(Fork* forkLeft, Fork* forkRight)
{
	this->forkLeft = forkLeft;
	this->forkRight = forkRight;
}


bool Philosopher::TakeLeftFork()
{
	if (this->forkLeft->mutex.try_lock()) {
		if (this->forkLeft->GetAvaiblity()) {
			this->forkLeft->setAvaiblity(false);
			this->hasLeft = true;
			forkLeft->mutex.unlock();
			return true;
		}
		this->forkLeft->mutex.unlock();
	}
	return false;
}

bool Philosopher::TakeRightFork()
{
	if (this->forkRight->mutex.try_lock()) {
		if (this->forkRight->GetAvaiblity()) {
			this->forkRight->setAvaiblity(false);
			this->hasRight = true;
			this->forkRight->mutex.unlock();
			return true;
		}
		this->forkRight->mutex.unlock();
	}
	return false;
}

void Philosopher::PutLeftFork()
{
	this->forkLeft->mutex.lock();
	this->forkLeft->setAvaiblity(true);
	this->hasLeft = false;
	this->forkLeft->mutex.unlock();
}

void Philosopher::PutRightFork()
{
	this->forkRight->mutex.lock();
	this->forkRight->setAvaiblity(true);
	this->hasRight = false;
	this->forkRight->mutex.unlock();
}

void Philosopher::Print()
{
	string left = ((hasLeft) ? "In use" : "Not avaible");
	string right = ((hasRight) ? "In use" : "Not avaible");

	printf("Philosopher %2d Meals %d State: %10s Left Fork: %12s Right Fork: %12s \n", this->id, this->meals,this->state.c_str(),left.c_str(),right.c_str());
}

void Philosopher::Simulate()
{
	while (this->simulateProgress) {
		if (forkLeft->getId() < forkRight->getId()) {
			if (hasRight) {
				if (TakeLeftFork())
					Eat();
			}
			else if (TakeRightFork()) {
				if(TakeLeftFork())
					Eat();				
			}
			
		}
		else {
			if (hasLeft) {
				if (TakeRightFork())
					Eat();
			}
			else if (TakeLeftFork()) {
				if (TakeRightFork())
					Eat();
			}
		}
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	
}
void Philosopher::Eat()
{
	
	this->meals++;
	this->state = "eating";
	int time= eatingTime + float(20 - rand() % 40)/100 * eatingTime;
	this_thread::sleep_for(chrono::milliseconds(time));
	this->PutLeftFork();
	this->PutRightFork();
	this->Sleep();
}

void Philosopher::Sleep()
{
	state = "sleeping";
	int time = sleepingtime + float(20 - rand() % 40) / 100 * sleepingtime;
	this_thread::sleep_for(chrono::milliseconds(time));
	state = "waiting";
}

void Philosopher::StopSimulation()
{
	this->simulateProgress = false;
}

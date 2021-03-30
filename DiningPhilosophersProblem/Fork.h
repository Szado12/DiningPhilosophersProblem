#pragma once
#include <thread>
#include <mutex>
using namespace std;
class Fork
{
private:
	bool avaible;
	int id;
public:
	mutex mutex;
	bool GetAvaiblity();
	void setAvaiblity(bool avaiblity);
	int getId();
	void setId(int id);
	Fork(int id);
};


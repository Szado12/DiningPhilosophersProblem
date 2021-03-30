#include "Fork.h"

bool Fork::GetAvaiblity()
{
	return this->avaible;
}

void Fork::setAvaiblity(bool avaiblity)
{
	this->avaible = avaiblity;
}

int Fork::getId()
{
	return id;
}

void Fork::setId(int id)
{
	this->id = id;
}

Fork::Fork(int id)
{
	this->id = id;
	this->avaible = true;
}

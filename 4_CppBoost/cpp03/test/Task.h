#include <iostream>
#pragma once
class Task
{
public:
	virtual void process() = 0;
};

class Taskprint
	: public Task
{
	int _task;
public:
	Taskprint(int x)
		: _task(x)
	{}
	void process() {
		std::cout << _task << std::endl;
	}
};


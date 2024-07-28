#pragma once
#include "Task.h"
#include <queue>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;
class TaskQueue
{
	size_t _queSize;
	using ElemType = Task*;
	queue<ElemType> _que;
	mutex _mtx;
	condition_variable _not_full;
	condition_variable _not_empty;
	bool _is_exit = false;

public:
	TaskQueue(size_t size)
		: _queSize(size)
	{}

	void push(ElemType& task) {
		unique_lock<mutex> ul(_mtx);
		while (isFull()) {
			_not_full.wait(ul);
		}
		_que.push(task);
		_not_empty.notify_one();
	}

	ElemType pop() {
		unique_lock<mutex> ul(_mtx);
		while (isEmpty()) {
			if (_is_exit) {
				return nullptr;
			}
			_not_empty.wait(ul);
		}
		auto ret = _que.front();
		_que.pop();
		_not_full.notify_one();
		return ret;
	}

	bool isEmpty() {
		return _que.size() == 0;
	}

	bool isFull() {
		return _que.size() == _queSize;
	}

	void stop() {
		_is_exit = true;
		_not_empty.notify_all();
	}
};


#pragma once
#include "TaskQueue.h"
#include <vector>
class ThreadPool
{
private:
	bool _is_exit = false;
	size_t _thread_num;
	size_t _que_size;
	vector<thread> _threads;
	TaskQueue _task_que;
	
public:
	ThreadPool(size_t thread_num, size_t que_size)
		: _thread_num(thread_num)
		, _que_size(que_size)
		, _task_que(que_size)
	{}

	void start() {
		for (size_t i = 0; i < _thread_num; i++) {
			_threads.emplace_back(&ThreadPool::doTask, this);
		}
	}

	void stop() {
		_is_exit = true;
		_task_que.stop();
		for (auto& t : _threads) {
			t.join();
		}
	}

	void addTask(Task* ptask) {
		_task_que.push(ptask);
	}
private:
	Task* getTask() {
		return _task_que.pop();
	}

	void doTask() {
		while (!_is_exit || !_task_que.isEmpty()) {
			auto task = getTask();
			if (task) {
				task->process();
			}
		}
	}
};


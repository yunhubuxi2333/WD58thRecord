#include <iostream>
#include "ThreadPool.h"
using namespace std;

int main() {
	ThreadPool pool(4, 10);
	pool.start();
	for (int i = 0; i < 20; i++) {
		pool.addTask(new Taskprint(i));
	}
	pool.stop();
}
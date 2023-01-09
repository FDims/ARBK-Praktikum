#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>


class Semaphore {
private:
	std::mutex Mutex;
	std::condition_variable cVar;
	int var;

public:
	Semaphore(int _var = 1) {
		var = _var;
	}

	void post() {
		var++;

		cVar.notify_one();
	}

	void wait() {
		std::unique_lock<std::mutex> lock(Mutex);
		if (var <= 0)
			cVar.wait(lock);
		if (var > 0)
			var-- ;
	}
};

#endif // !SEMAPHORE_H

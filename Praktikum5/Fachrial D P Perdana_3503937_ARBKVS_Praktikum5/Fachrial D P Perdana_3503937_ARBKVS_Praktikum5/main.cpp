<<<<<<< Updated upstream
#include <iostream>
#include <thread>
#include <mutex>
#include "Semaphore.h"

using namespace std;

mutex Mutex;
Semaphore semaphore;

void threadT1() {
	//Mutex.lock();
	for (char i = 'a'; i <= 'z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	//Mutex.unlock();
}

void threadT2() {
	//Mutex.lock();
	for (int i = 0; i <= 32; i++) {
		cout << i << ", ";
	}
	cout << endl;
	//Mutex.unlock();
}

void threadT3() {
	//Mutex.lock();
	for (char i = 'A'; i <= 'Z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	//Mutex.unlock();
}

void MutexThreading() {
	thread T1(threadT1);
	thread T2(threadT2);
	thread T3(threadT3);
	T1.join();
	T2.join();
	T3.join();
}



void threadT1S() {
	semaphore.wait();
	for (char i = 'a'; i <= 'z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	semaphore.post();
}
void threadT2S() {
	semaphore.wait();
	for (int i = 0; i <= 32; i++) {
		cout << i << ", ";
	}
	cout << endl;
	semaphore.post();
}
void threadT3S() {
	semaphore.wait();
	for (char i = 'A'; i <= 'Z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	semaphore.post();
}

void SemaphoreThreading() {
	thread T1(threadT1S);
	thread T2(threadT2S);
	thread T3(threadT3S);
	T1.join();
	T2.join();
	T3.join();
}

int main() {
	//SemaphoreThreading();
	MutexThreading();

	return 0;
=======
#include <iostream>
#include <thread>
#include <mutex>
#include "Semaphore.h"

using namespace std;

mutex Mutex;
Semaphore semaphore;

void threadT1() {
	Mutex.lock();
	for (char i = 'a'; i <= 'z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	Mutex.unlock();
}

void threadT2() {
	Mutex.lock();
	for (int i = 0; i <= 32; i++) {
		cout << i << ", ";
	}
	cout << endl;
	Mutex.unlock();
}

void threadT3() {
	Mutex.lock();
	for (char i = 'A'; i <= 'Z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	Mutex.unlock();
}

void MutexThreading() {
	thread T1(threadT1);
	thread T2(threadT2);
	thread T3(threadT3);
	//T1.join();
	//T2.join();
	//T3.join();
}



void threadT1S() {
	semaphore.wait();
	for (char i = 'a'; i <= 'z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	semaphore.post();
}
void threadT2S() {
	semaphore.wait();
	for (int i = 0; i <= 32; i++) {
		cout << i << ", ";
	}
	cout << endl;
	semaphore.post();
}
void threadT3S() {
	semaphore.wait();
	for (char i = 'A'; i <= 'Z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	semaphore.post();
}

void SemaphoreThreading() {
	thread T1(threadT1S);
	thread T2(threadT2S);
	thread T3(threadT3S);
	T1.join();
	T2.join();
	T3.join();
}

int main() {
	//SemaphoreThreading();
	MutexThreading();

	return 0;
>>>>>>> Stashed changes
}
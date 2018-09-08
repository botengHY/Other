#include <iostream>
#include <thread>
#include <mutex>
using namespace std; 


int sum = 0; 


mutex mtx; 

void add_wrong()
{
	for(int i = 0; i < 1000000; i++)
	{
		sum++;
	}
}

void add()
{
	int loc_sum = 0; 
	for(int i = 0; i < 1000000; i++)
	{
		loc_sum++;
	}

	mtx.lock(); 
	sum += loc_sum;
	mtx.unlock();
}



int main(int argc, char** argv)
{
	thread thread1(add_wrong); 
	thread thread2(add_wrong);
	thread1.join();
	thread2.join();
	cout<<sum<<endl; // < 2000000

	sum = 0; 

	std::thread thread3(add);
	std::thread thread4(add);
	thread3.join(); 
	thread4.join();
	cout<<sum<<endl; // = 1000000
	return 0;
}
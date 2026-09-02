#include "ThreadPool.hpp"
#include <iostream>

int main()
{
	//---Получаем количество доступных аппаратных потоков
	std::size_t threadCount = std::thread::hardware_concurrency(); 

	//---Создаем пул потоков
	ThreadPool pool(threadCount);

	//---Добавляем задачи
	pool.addTask(
		[]()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "Task #1" << std::endl;
		}
	);
	pool.addTask(
		[]()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Task #2" << std::endl;

		}
	);

	return 0;
}



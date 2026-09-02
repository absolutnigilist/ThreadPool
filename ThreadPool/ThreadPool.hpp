#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

//---------------------------------------------------------------------------------------------------------------------------
//		Реализация класса пула потоков (ThreadPool)
//---------------------------------------------------------------------------------------------------------------------------
class ThreadPool 
{
public:

	//---Конструктор
	explicit ThreadPool(std::size_t threadCount);
	
	//---Деструктор
	~ThreadPool();
	
	//---Добавление задачи в пул потоков
	void addTask(std::function<void()> task);

private:

	//---Функция, выполняемая каждым потоком в пуле
	void worker();
	
private:
	std::vector<std::thread> m_workers;			// Вектор потоков
	std::queue<std::function<void()>> m_tasks;	// Очередь задач

	std::mutex m_mutex;							// Мьютекс для синхронизации доступа к очереди задач
	std::condition_variable m_condition;		// Переменная условия для уведомления потоков о наличии задач

	bool m_stop = false;						// Флаг для остановки пула потоков
};
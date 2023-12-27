// 7.2-2-2.cpp : c++17



#include"header.h"
#include<thread>
#include<mutex>


using namespace std::chrono_literals;
consol_parameter cp;

std::mutex m;

void process(int j, int bar_s) {
	std::this_thread::sleep_for(1000ms);

	j += 5;
	Timer t("");

	for (int i = 0; i < bar_s; i++)
	{
		std::unique_lock l{ m };

		cp.SetPosition(15 + i, j);
		std::cout << "_";
		std::this_thread::sleep_for(100ms);
	}

	std::unique_lock l1{ m };

	cp.SetPosition(bar_s + 20, j);
	t.print();// РїРѕР»СѓС‡Р°РµС‚СЃСЏ С‚Р°Р№РјРµСЂ РѕРґРёРЅ РЅР° РІСЃРµС…?
}

int main()
{
	int size_bar;
	int count_thread;
	std::cout << "input size of progress bar: "; std::cin >> size_bar;
	std::cout << "input count of threads: "; std::cin >> count_thread;

	std::cout << "\n\nthread id";

	cp.SetPosition((size_bar + 25) / 2, 4);
	std::cout << "process";

	cp.SetPosition(size_bar + 15, 4);
	std::cout << "\t\ttime\n";

	cp.SetPosition(0, 5);
	std::thread* t = new std::thread[count_thread];
	for (int i = 0; i < count_thread; i++)
	{
		t[i] = std::thread(process, i, size_bar);
		std::cout << t[i].get_id() << std::endl;

	}
	for (int i = 0; i < count_thread; i++)
	{
		t[i].join();
	}
	cp.SetPosition(0, 5 + count_thread);

	return 0;
}

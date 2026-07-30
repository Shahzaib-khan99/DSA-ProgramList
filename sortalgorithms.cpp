
#include <iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<chrono>
#include<ctime>
#include<utility>

std::chrono::microseconds correct_selectionsort(int* arr, int s) {
	auto start{ std::chrono::steady_clock::now() };
	for (int i = 0; i < s - 1; ++i)
	{
		int min = arr[i];
		int minindex = i;
		for (int j = i + 1; j < s; ++j)
		{
			if (arr[j] < min)
			{
				minindex = j;
			}
		}

		if (minindex != i)
		{
			std::swap(arr[minindex], arr[i]);
		}

	}
	auto stop{ std::chrono::steady_clock::now() };
	return std::chrono::duration_cast<std::chrono::microseconds> (stop - start);

}

std::chrono::microseconds wrong_selectionsort(int* arr, int s) {
	auto start{ std::chrono::steady_clock::now() };

	for (int i = 0; i < s - 1; ++i)
	{
		for (int j = i + 1; j < s; ++j)
		{
			if (arr[j] < arr[i])
			{
				std::swap(arr[j], arr[i]);
			}
		}
	}

	auto stop{ std::chrono::steady_clock::now() };
	return std::chrono::duration_cast<std::chrono::microseconds> (stop - start);

}

std::chrono::microseconds bubblesort(int* arr, int s)
{
	auto start{ std::chrono::steady_clock::now() };
	for (int i = 0; i < s - 1; ++i)
	{
		bool swapping = false;
		for (int j = 0; j < s - i - 1; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				std::swap(arr[j], arr[j + 1]);
				swapping = true;
			}
		}
		if (swapping == false)
		{
			auto stop{ std::chrono::steady_clock::now() };
			return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		}
	}

	auto stop{ std::chrono::steady_clock::now() };
	return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

}
std::chrono::microseconds insertionsort(int* arr, int s) {
	auto start{ std::chrono::steady_clock::now() };
	for (int i = 1; i < s; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}
	auto stop{ std::chrono::steady_clock::now() };
	return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

}

int* random_array(int s)
{
	int* arr = new int[s];
	for (int i = 0; i < s; ++i)
	{
		arr[i] = std::rand();
	}
	return arr;
}

int* ascending_array(int s)
{
	int* arr = new int[s];
	for (int i = 0; i < s; ++i)
	{
		arr[i] = i + 1;
	}
	return arr;
}

int* descending_array(int s)
{
	int* arr = new int[s];
	for (int i = 0; i < s; ++i)
	{
		arr[i] = s - i;
	}
	return arr;
}

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		char* csv = argv[2];

		int	s = atoi(argv[1]);

		std::srand(std::time(nullptr));
		std::fstream file(csv, std::ios::app);
		file << "Algorithm ,, Array size,, Array name ,, Average time \n";
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 3; ++j) {
				double total = 0.0;
				for (int k = 0; k < 10; ++k)
				{
					int* arr = nullptr;
					switch (j)
					{
					case(0):
						arr = random_array(s);
						break;
					case(1):
						arr = ascending_array(s);
						break;
					case(2):
						arr = descending_array(s);
						break;
					}
					std::chrono::duration<double, std::micro> times{};
					switch (i) {
					case(0):
						times = correct_selectionsort(arr, s);
						total = total + times.count();
						break;
					case(1):
						times = wrong_selectionsort(arr, s);
						total = total + times.count();
						break;
					case(2):
						times = bubblesort(arr, s);
						total = total + times.count();
						break;
					case(3):
						times = insertionsort(arr, s);
						total = total + times.count();
						break;
					}
					delete[] arr;

				}
				double average = total / 10.0;
				switch (i)
				{
				case(0):
					file << "correctselectionsort,," << s << ",,";
					break;
				case(1):
					file << "wrongselectionsort,," << s << ",,";
					break;
				case(2):
					file << "bubblesort,," << s << ",,";
					break;
				case(3):
					file << "insertionsort,," << s << ",,";
					break;
				}
				switch (j)
				{
				case(0):
					file << "randomarray,," << average << "\n";
					break;
				case(1):
					file << "ascendingarray,," << average << "\n";
					break;
				case(2):
					file << "descendingarray,," << average << "\n";
					break;
				}
			}
		}
		file << "\n";
		file.close();
		std::cout << "program executes successfully and program end \n";
	}
	else
	{
		std::cout << "invalid number of argunments \n";
	}
	return 0;
}

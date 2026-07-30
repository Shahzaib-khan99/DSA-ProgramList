

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
	return std::chrono::duration_cast<std::chrono::microseconds> (stop-start);

}

std::chrono::microseconds wrongselectionsort(int* arr, int s) {
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
	for (int i = 0; i < s ; i++)
	{
		bool swap = false;
		for (int j = 0; j < s - i - 1; ++j)
		{
			if (arr[j+1] < arr[i])
			{
				std::swap(arr[j], arr[j+1]);
				swap = true;
			}
		}
		if (swap = false)
		{
			auto stop{ std::chrono::steady_clock::now() };
			return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		}
	}

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

int* cdes
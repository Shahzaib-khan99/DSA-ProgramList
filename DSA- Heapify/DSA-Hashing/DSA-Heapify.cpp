// DSA-Hashing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

class Heap
{
private:
    int* arr;
    int capacity;
    int size;

public:

    Heap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~Heap()
    {
        delete[] arr;
    }

    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    
    void heapifyDown(int index, int heapSize)
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < heapSize && arr[left] > arr[largest])
            {
                largest = left;
            }

            if (right < heapSize && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }

        arr[size] = value;
        size++;

        heapifyUp(size - 1);
    }

    
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    
    void heapSort()
    {
        // Build Max Heap
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i, size);
        }

        // Move maximum element to the end
        for (int i = size - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);

            heapifyDown(0, i);
        }
    }
};


int main()
{
    Heap h(15);

    h.insert(43);
    h.insert(54);
    h.insert(19);
    h.insert(53);
    h.insert(40);
    h.insert(39);
    h.insert(12);
    h.insert(61);
    h.insert(80);
    h.insert(98);
    h.insert(99);
    h.insert(34);
    h.insert(26);
    h.insert(74);

    cout << "Max Heap: ";
    h.display();

    h.heapSort();

    cout << "After Heap Sort: ";
    h.display();

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int* arr;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << arr[top] << " deleted" << endl;
        top--;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s(100);

    s.push(10);
    s.push(22);
    s.push(77);
    s.push(55);

    cout << "Stack Elements:" << endl;
    s.display();

    s.pop();
    s.pop();

    cout << endl;
    cout << "After Pop:" << endl;
    s.display();

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

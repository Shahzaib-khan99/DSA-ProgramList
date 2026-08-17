
#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void reverseString(string str, int index)
{
    if (index < 0)
    {
        return;
    }

    cout << str[index];

    reverseString(str, index - 1);
}


int main()
{
    
        string str;

        cout << "Enter a string: ";
        cin >> str;

        cout << "Reversed String: ";

        reverseString(str, str.length() - 1);
        cout << endl;
    
    int num;
    cout << "enter the number :" ;
    cin >> num;
    cout << "factorial:" <<factorial(num);
    cout << endl;
    cout << "fibonacci series:" << endl;
    for (int i = 1; i < num; i++)
    {
        cout << fibonacci(i) << " ";
    }
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

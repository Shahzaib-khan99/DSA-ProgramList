#include <iostream>
using namespace std;

class HashTable
{
private:
    int* table;
    int size;

public:

    HashTable(int s)
    {
        size = s;
        table = new int[size];

        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }

    ~HashTable()
    {
        delete[] table;
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void linearProbing(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i) % size;

            if (table[newIndex] == -1)
            {
                table[newIndex] = key;
                return;
            }
        }

        cout << "Hash table is full" << endl;
    }

    void quadraticprobing(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i * i) % size;

            if (table[newIndex] == -1)
            {
                table[newIndex] = key;
                return;
            }
        }

        cout << "Hash table is full" << endl;
    }

    bool searchLinear(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i) % size;

            if (table[newIndex] == key)
            {
                return true;
            }

            if (table[newIndex] == -1)
            {
                return false;
            }
        }

        return false;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " : " << table[i] << endl;
        }
    }
};

int main()
{
    HashTable h(20);

    h.linearProbing(25);
    h.linearProbing(35);
    h.linearProbing(45);
    h.linearProbing(15);
    h.quadraticprobing(50);
    h.quadraticprobing(21);
    h.quadraticprobing(90);
    h.quadraticprobing(29);
    h.display();
    cout << endl;
    h.searchLinear(45);
    h.display();


    return 0;
}
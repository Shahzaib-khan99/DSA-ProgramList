#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node* next;

public:
    node()
    {
        data = 0;
        next = nullptr;
    }

    void setdata(int val)
    {
        data = val;
    }

    int getdata()
    {
        return data;
    }

    void setnext(node* ptr)
    {
        next = ptr;
    }

    node* getnext()
    {
        return next;
    }
};

class linkedlist
{
private:
    node* head;

public:
    linkedlist()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        node* newnode = new node;
        newnode->setdata(val);
        newnode->setnext(nullptr);

        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            node* temp = head;

            while (temp->getnext() != nullptr)
            {
                temp = temp->getnext();
            }

            temp->setnext(newnode);
        }
    }

    void display()
    {
        node* temp = head;

        while (temp != nullptr)
        {
            cout << temp->getdata() << " ";
            temp = temp->getnext();
        }

        cout << endl;
    }

    void selectionSort()
    {
        node* current = head;

        while (current != nullptr)
        {
            node* minNode = current;
            node* temp = current->getnext();

            while (temp != nullptr)
            {
                if (temp->getdata() < minNode->getdata())
                {
                    minNode = temp;
                }

                temp = temp->getnext();
            }

            int value = current->getdata();
            current->setdata(minNode->getdata());
            minNode->setdata(value);

            current = current->getnext();
        }
    }

    void insertionSort()
    {
        if (head == nullptr)
        {
            return;
        }

        node* current = head->getnext();

        while (current != nullptr)
        {
            int key = current->getdata();
            node* temp = head;

            while (temp != current)
            {
                if (temp->getdata() > key)
                {
                    int value = temp->getdata();
                    temp->setdata(key);
                    key = value;
                }

                temp = temp->getnext();
            }

            current->setdata(key);

            current = current->getnext();
        }
    }
};

int main()
{
    linkedlist list;

    list.insert(30);
    list.insert(10);
    list.insert(50);
    list.insert(33);
    list.insert(76);
    list.insert(68);
    list.insert(20);
    list.insert(5);

    cout << "Original List: ";
    list.display();

    list.selectionSort();

    cout << "After Selection Sort: ";
    list.display();

    list.insertionSort();
    cout << "after insertion sort:";
    list.display();

    return 0;
}
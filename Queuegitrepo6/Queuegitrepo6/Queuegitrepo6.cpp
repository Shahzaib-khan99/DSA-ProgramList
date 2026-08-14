#include<iostream>
using namespace std;

class node
{
private:
    int data;
    node* next;
    node* prev;

public:
    node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
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

    void setprev(node* ptr)
    {
        prev = ptr;
    }

    node* getprev()
    {
        return prev;
    }
};

class deque
{
private:
    node* front;
    node* rear;

public:
    deque()
    {
        front = rear = nullptr;
    }

    bool isempty()
    {
        return front == nullptr;
    }

    void insertfront(int val)
    {
        node* newnode = new node();
        newnode->setdata(val);

        if (isempty())
        {
            front = rear = newnode;
            front->setnext(front);
            front->setprev(front);
            return;
        }

        newnode->setnext(front);
        newnode->setprev(rear);

        front->setprev(newnode);
        rear->setnext(newnode);

        front = newnode;
    }

    void insertrear(int val)
    {
        node* newnode = new node();
        newnode->setdata(val);

        if (isempty())
        {
            front = rear = newnode;
            front->setnext(front);
            front->setprev(front);
            return;
        }

        newnode->setnext(front);
        newnode->setprev(rear);

        rear->setnext(newnode);
        front->setprev(newnode);

        rear = newnode;
    }

    void deletefront()
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        node* temp = front;

        if (front == rear)
        {
            cout << temp->getdata() << " deleted\n";
            delete temp;
            front = rear = nullptr;
            return;
        }

        front = front->getnext();

        front->setprev(rear);
        rear->setnext(front);

        cout << temp->getdata() << " deleted\n";

        delete temp;
    }

    void deleterear()
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        node* temp = rear;

        if (front == rear)
        {
            cout << temp->getdata() << " deleted\n";
            delete temp;
            front = rear = nullptr;
            return;
        }

        rear = rear->getprev();

        rear->setnext(front);
        front->setprev(rear);

        cout << temp->getdata() << " deleted\n";

        delete temp;
    }
    void insertatposition(int pos, int val)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            insertfront(val);
            return;
        }

        node* temp = front;
        int count = 1;

        while (count < pos - 1 && temp != rear)
        {
            temp = temp->getnext();
            count++;
        }

        if (count != pos - 1)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (temp == rear)
        {
            insertrear(val);
            return;
        }

        node* newnode = new node();
        newnode->setdata(val);

        node* nextnode = temp->getnext();

        newnode->setnext(nextnode);
        newnode->setprev(temp);

        temp->setnext(newnode);
        nextnode->setprev(newnode);

        cout << val << " Inserted Successfully\n";
    }

    void deleteatposition(int pos)
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            deletefront();
            return;
        }

        node* temp = front;
        int count = 1;

        while (count < pos && temp != rear)
        {
            temp = temp->getnext();
            count++;
        }

        if (count != pos)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (temp == rear)
        {
            deleterear();
            return;
        }

        node* previous = temp->getprev();
        node* nextnode = temp->getnext();

        previous->setnext(nextnode);
        nextnode->setprev(previous);

        cout << temp->getdata() << " deleted\n";

        delete temp;
    }
    void swapvalues(int pos1, int pos2)
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        if (pos1 == pos2)
            return;

        node* first = front;
        node* second = front;

        int count = 1;

        while (count < pos1 && first != rear)
        {
            first = first->getnext();
            count++;
        }

        if (count != pos1)
        {
            cout << "Invalid First Position\n";
            return;
        }

        count = 1;

        while (count < pos2 && second != rear)
        {
            second = second->getnext();
            count++;
        }

        if (count != pos2)
        {
            cout << "Invalid Second Position\n";
            return;
        }

        int temp = first->getdata();
        first->setdata(second->getdata());
        second->setdata(temp);

        cout << "Values Swapped\n";
    }

    void display()
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        node* temp = front;

        cout << "Deque : ";

        do
        {
            cout << temp->getdata() << " ";
            temp = temp->getnext();
        } while (temp != front);

        cout << endl;
    }
};

int main()
{
    deque q;

    q.insertfront(30);
    q.insertfront(20);
    q.insertfront(10);

    q.insertrear(40);
    q.insertrear(50);
    q.insertrear(60);

    q.display();

    q.deleteatposition(4);
    q.display();

    q.deletefront();
    q.display();

    q.insertatposition(1, 99);
    q.display();

    q.deleterear();
    q.display();

    q.deleteatposition(2);
    q.display();

    q.swapvalues(1, 2);
    q.display();

    return 0;
}
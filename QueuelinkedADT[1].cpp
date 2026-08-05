#include <iostream>

template <class T>
class linkedQueue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    linkedQueue() 
    {
        front = nullptr;
        rear = nullptr;
    }

    linkedQueue(const linkedQueue<T>& other) 
    {
        front = nullptr;
        rear = nullptr;

        Node* temp = other.front;
        while (temp != nullptr) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }

    ~linkedQueue() {
        while (front != nullptr) 
        {
            dequeue();
        }
    }


    void enqueue(T value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) 
        {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr)
            return;

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }
    nkedQueue<T>& operator=(const linkedQueue<T>& other) 
    {
        if (this != &other) 
        {

            while (front != nullptr) {
                dequeue();
            }

            Node* temp = other.front;
            while (temp != nullptr) {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    bool operator==(const linkedQueue<T>& other) const
    {
        Node* p = front;
        Node* q = other.front;

        while (p != nullptr && q != nullptr)
        {
            if (p->data != q->data)
                return false;

            p = p->next;
            q = q->next;
        }

        return (p == nullptr && q == nullptr);
    }

    bool operator<(const linkedQueue<T>& other) const 

    {
        Node* p = front;
        Node* q = other.front;

        while (p != nullptr && q != nullptr) 
        {
            if (p->data < q->data)
                return true;

            if (p->data > q->data)
                return false;

            p = p->next;
            q = q->next;
        }

        return (p == nullptr && q != nullptr);
    }

    void display() const
    {

        Node* temp = front;
        while (temp != nullptr) 
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    linkedQueue<int> q1;
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    linkedQueue<int> q2(q1);
    linkedQueue<int> q3;
    q3 = q1;

    q1.display();
    q2.display();
    q3.display();
    if (q1 == q2)
        std::cout << "Equal" << std::endl;

    if (q1 < q3)
        std::cout << "q1 is the smaller" << std::endl;
    else
        std::cout << "Not smaller" << std::endl;

    return 0;
}
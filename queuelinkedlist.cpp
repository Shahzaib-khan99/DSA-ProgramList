
#include <iostream>

template <class T>

class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = 0;
    }

    Queue(const Queue& other) {
        front = rear = 0;
        Node* temp = other.front;
        while (temp != 0) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }

    ~Queue() {
        while (front != 0)
        {
            dequeue();
        }
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            while (front != 0) {
                dequeue();
            }
            Node* temp = other.front;
            while (temp != 0) {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    void enqueue(T value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = 0;

        if (rear == 0) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() 
    {
        if (front == 0) return;

        Node* temp = front;
        front = front->next;

        if (front == 0)
            rear = 0;

        delete temp;
    }

    bool operator==(const Queue& other) const
    {
        Node* p = front;
        Node* q = other.front;

        while (p != 0 && q != 0) {
            if (p->data != q->data)
                return false;
            p = p->next;
            q = q->next;
        }
        return (p == 0 && q == 0);
    }

    bool operator<(const Queue& other) const 
    
    {
        Node* p = front;
        Node* q = other.front;

        while (p != 0 && q != 0)
        
        {
            if (p->data < q->data)
                return true;

            else if (p->data > q->data)
                return false;

            p = p->next;
            q = q->next;
        }
        return (p == 0 && q != 0);
    }

    void display() const {
        Node* temp = front;
        while (temp != 0) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    Queue<int> q2(q1);

    Queue<int> q3;
    q3 = q1;

    q1.display();
    q2.display();
    q3.display();

    if (q1 == q2)
        std::cout << "Equal\n";

    if (q1 < q2)
        std::cout << "q1 is greater than q2\n";

    return 0;
}
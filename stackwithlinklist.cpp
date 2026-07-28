#include<iostream>

template <typename T>
struct node {
    T val;
    node<T>* next;
};

template <typename T>
class stack {
private:
    node<T>* top;
    int n;

public:

    stack() {
        this->top = nullptr;
        n = 0;
    }


    void Push(T v) {
        if (top == nullptr) {
            top = new node<T>;
            top->val = v;
            top->next = nullptr;
        }
        else {
            node<T>* temp;
            temp = new node<T>;
            temp->val = v;
            temp->next = top;
            top = temp;
        }
        ++n;
    }


    void pop() {
        if (top == nullptr) {
            return;
        }

        node<T>* temp;
        temp = top;
        top = top->next;

        delete temp;
        this->n--;
    }


    T TOp() const {
        if (top == nullptr) {
            throw "Stack Underflow";
        }

        return this->top->val;
    }


    int size() const {
        return this->n;
    }


    bool empty() {
        return this->top == nullptr;
    }


    ~stack() {
        while (top != nullptr) {
            pop();
        }
    }
};


int main() {

    stack<int> s;


    s.Push(10);
    s.Push(20);
    s.Push(30);


    std::cout << "Top Element: " << s.TOp() << std::endl;


    std::cout << "Stack Size: " << s.size() << std::endl;


    s.pop();


    std::cout << "Top Element after pop: "
        << s.TOp() << std::endl;


    std::cout << "Stack Size after pop: "
        << s.size() << std::endl;


    if (s.empty()) {
        std::cout << "Stack is Empty" << std::endl;
    }
    else {
        std::cout << "Stack is Not Empty" << std::endl;
    }


    s.pop();
    s.pop();


    if (s.empty()) {
        std::cout << "Stack is Empty Now" << std::endl;
    }

    return 0;
}
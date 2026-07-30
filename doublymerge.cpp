#include <iostream>
#include <algorithm> // For std::swap used in the swap function

// 1. Node Structure (dnode)
template <typename T>
struct dnode {
    dnode<T>* prev;
    dnode<T>* next;
    T val;
};

// 2. List Class
template <typename T>
class list {
private:
    dnode<T>* H; // Dummy Head Node
    int n;       // Size of the list

public:
    // Constructor: Initializes dummy head where prev and next point to itself
    list() {
        this->H = new dnode<T>;
        this->n = 0;
        this->H->prev = this->H;
        this->H->next = this->H;
    }

    // Capacity Functions
    int size() const {
        return this->n;
    }

    bool empty() const {
        return this->H == this->H->next; // Or return n == 0;
    }

    // Element Access
    T front() const {
        return this->H->next->val;
    }

    // Modifiers: Push Front
    void push_front(const T& v) {
        dnode<T>* temp = new dnode<T>;
        temp->val = v;
        temp->next = this->H->next;
        temp->prev = this->H;

        temp->next->prev = temp;
        this->H->next = temp;
        this->n++;
    }

    // Modifiers: Push Back
    void push_back(const T& v) {
        dnode<T>* temp = new dnode<T>;
        temp->val = v;
        temp->next = this->H;
        temp->prev = this->H->prev;

        this->H->prev->next = temp;
        this->H->prev = temp;
        this->n++;
    }

    // Modifiers: Pop Front
    void pop_front() {
        if (empty()) return;
        dnode<T>* temp = this->H->next;
        temp->next->prev = this->H;
        this->H->next = temp->next;
        delete temp;
        this->n--;
    }

    // Modifiers: Pop Back
    void pop_back() {
        if (empty()) return;
        dnode<T>* temp = this->H->prev;
        temp->prev->next = this->H;
        this->H->prev = temp->prev;
        delete temp;
        this->n--;
    }

    // Clear: Removes all elements
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Resize Function
    void resize(int ns, const T& v = T()) {
        if (ns > this->n) {
            int diff = ns - this->n;
            for (int i = 0; i < diff; ++i) {
                push_back(v);
            }
        }
        else if (ns < this->n) {
            int diff = this->n - ns;
            for (int i = 0; i < diff; ++i) {
                pop_back();
            }
        }
    }

    // Swap Function
    void swap(list<T>& other) {
        std::swap(this->H, other.H);
        std::swap(this->n, other.n);
    }

    // Merge Function (Lab Task Logic)
    void merge(list<T>& other) {
        if (this == &other) return;

        dnode<T>* p1 = this->H->next;
        dnode<T>* p2 = other.H->next;

        while (p1 != this->H && p2 != other.H) {
            if (p2->val < p1->val) {
                // Detach p2 from 'other'
                dnode<T>* next_p2 = p2->next;

                // Insert p2 before p1
                p2->next = p1;
                p2->prev = p1->prev;
                p1->prev->next = p2;
                p1->prev = p2;

                p2 = next_p2;
            }
            else {
                p1 = p1->next;
            }
        }

        // If elements remain in 'other', attach them to the end of 'this'
        if (p2 != other.H) {
            dnode<T>* last_other = other.H->prev;
            dnode<T>* last_this = this->H->prev;

            last_this->next = p2;
            p2->prev = last_this;

            last_other->next = this->H;
            this->H->prev = last_other;
        }

        this->n += other.n;

        // Reset 'other' list to empty dummy state
        other.H->next = other.H;
        other.H->prev = other.H;
        other.n = 0;
    }

    // Helper to print the list (for testing)
    void print() {
        dnode<T>* curr = this->H->next;
        while (curr != this->H) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    list<int> l1;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(6);
    l1.push_front(3);
    l1.push_front(8);

    list<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(7);
    l2.push_front(6);
    l2.push_front(9);

    std::cout << "List 1: "; l1.print();
    std::cout << "List 2: "; l2.print();

    l1.merge(l2);
    std::cout << "Merged List: "; l1.print();

    l1.swap(l2);
	std::cout << "After Swap - List 1: "; l1.print();
	std::cout << "After Swap - List 2: "; l2.print();

    
    return 0;
}
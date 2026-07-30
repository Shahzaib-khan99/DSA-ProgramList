 // forwardlistpro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Node structure
template <typename T>
struct node {
    T data;
    node<T>* next;
};

// Forward List class
template <typename T>
class forwardlist {
    node<T>* head;

public:

    // Constructor
    forwardlist() {
        this->head = nullptr;
    }

    // Insert at front
    void push_front(const T& value) {
        node<T>* temp = new node<T>;
        temp->data = value;
        temp->next = this->head;
        this->head = temp;
    }

    // Delete from front
    void pop_front() {
        if (this->head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        node<T>* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    // Display list
    void display() {
        node<T>* temp = this->head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search element
    bool search(const T& key) {
        node<T>* temp = this->head;

        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }

        return false;
    }

    // Destructor
    ~forwardlist() {
        while (this->head != nullptr) {
            pop_front();
        }
    }
};

// Main function with command line
int main(int argc, char* argv[]) {

    forwardlist<int> fl;

    if (argc < 2) {
        cout << "Usage:\n";
        cout << "  insert <value>\n";
        cout << "  delete\n";
        cout << "  search <value>\n";
        return 0;
    }

    int i = 1;

    while (i < argc) {
        string cmd = argv[i];

        // INSERT
        if (cmd == "insert") {
            if (i + 1 < argc) {
                int val = atoi(argv[i + 1]);
                fl.push_front(val);
                i += 2;
            }
            else {
                cout << "Missing value for insert\n";
                break;
            }
        }

        // DELETE
        else if (cmd == "delete") {
            fl.pop_front();
            i += 1;
        }

        
        else if (cmd == "search") {
            if (i + 1 < argc) {
                int val = atoi(argv[i + 1]);

                if (fl.search(val))
                    cout << val << " found in list\n";
                else
                    cout << val << " not found\n";

                i += 2;
            }
            else {
                cout << "Missing value for search\n";
                break;
            }
        }

        else {
            cout << "Unknown command: " << cmd << endl;
            i++;
        }
    }

    cout << "Final List: ";
    fl.display();

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

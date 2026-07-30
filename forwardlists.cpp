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
    // Constructor
    stack() {
        this->top = nullptr;
        n = 0;
    }

    // Push function
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

    // Pop function (Method 2 from your notes)
    void pop() {
        if (top == nullptr) {
            // Usually handled with underflow check
            return;
        }
        …
            

        template <typename T>
        class forward_list {
            node<T>* H;
            int n;

        public:
            // constructor
        public:
            forward_list() {
                this->H = new node<T>;
                this->H->next = nullptr;
                this->n = 0;
            }

            void push_front(const T& v) {
                node<T>* temp;
                temp = new node<T>;
                temp->val = v;
                temp->next = H->next; // (H->next; nullptr)

                this->H->next = temp;
                ++this->n;
            }

            void pop_front() {
                node<T>* temp;
                temp = this->H->next;
                this->H->next = temp->next;
                // // // = H->next->next;
                delete temp;
                --this->n;
            }

            void resize(int ns, const T& v = T()) {
                // ns -> new size
                if (ns > this->n) { // extend the list
                    int nc = ns - this->n;
                    node<T>* last;
                    last = this->H;
                    while (last->next != nullptr) {
                        last = last->next;
                    }

                    for (int i = 0; i < nc; ++i) {
                        last->next = new node<T>;
                        last->next->val = v;
                        last = last->next;
                        ++this->n;
                    }
                    last->next = nullptr;
                }
                else if (ns < this->n) {
                    node<T>* last, * first;
                    first = this->H;

                    for (int i = 0; i < ns; ++i) {
                        first = first->next;
                    }

                    node<T>* temp;
                    while (first != nullptr) {
                        temp = first;
                        first = temp->next; // first->next
                        delete temp;
                        --this->n;
                    }
                    last->next = nullptr;
                }
            }
        };
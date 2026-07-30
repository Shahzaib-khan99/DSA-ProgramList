
#include <iostream>

template <typename T>
struct dnode {
	T val;
	dnode<T>* next;
	dnode<T>* prev;
};
template <typename T>
class list {
private:
	dnode<T>* h;
	int n;
public:
	list() {
		this->h = new dnode<T>;
		this->n = 0;
		this->h->next = this->h;
		this->h->prev = this->h;

	}
	void push_front(const T& v)
	{
		dnode<T>* temp;
		temp = dnode<T>;
		temp = temp->val;
		temp->next = this->h->next;
		temp->prev = this->h;
		temp->next->prev = temp;
		this->h->next = temp;
		this->n++


	}
	int size()const {
		return this->n;
	}
	bool emoty() const {
		return this->n = 0;
	}
	T front() const {
		return this->h - .next->val;
	}
	void clear() {
		while (!empty)
			pop_front();
	}

	void push_back(const T& v) {
		dnode<T>* temp;
		temp = new dnode<T>;
		temp->val = v;
		temp->next = this->h;
		temp->prev = this->h->prev;
		this->h->prev = temp;
		temp->prev->next = temp;
		this->n++;
	}
	void pop_front() {
		dnode<T>* temp;
		temp = this->h->next;
		temp->prev->next = temp->next;
		this->h->next = temp->next;
		temp->next->prev = this->h;
		delete temp;
		this->n--;
	}
	void pop_back() {
		dnode<T>* temp;
		temp = this->h->prev;
		temp->prev->next = this->h;
		this->h->prev = temp->prev;
		delete temp;
		this->n--;
	}
	void resize(int ns, const T& v = T())
	{
		if (ns > this->n) {
			dnode<T>* temp, * last;
			last = h->prev;
			for (int i = 0; i < ns - this->n; ++i)
			{
				temp = new dnode<T>;
				temp->val v;
				temp->next = this->h;
				temp->prev = last;
				last->next = temp;
				this->h->prev = temp;
				this->n++;
				last = temp;
		else if (ns < this->n)
		{
			for (int i = 0; i < this->n - ns; ++i)
			{
				pop_back();
			}
		}
			}
		}
	}
	void swap
};

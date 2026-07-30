// doublyliniterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template<typename T>
struct dnode {
	dnode<T>* prev;
	dnode<T>* next;
	T val;
};

template<typename T>
class list {
private :
	dnode<T>* h;
	int n;
public:
	list()
		{
			this->n = 0;
			this->h = new dnode<T>;
	       this->h->next = this->h;
	       this->h->prev = this->h;
		}

	iterator<T> begin() {
		iterator it;
		it.ptr = this->h->next;
		return it;
	}
	iterator <T> end() {
		iterator it;
		it.ptr = this->h;
		return it; 
	}
	reverse_iterator <T> rbegin() {
		reverse_iterator it;
		it.ptr = this->h->prev;
		return it;
	}
	reverse_iterator<T> rend() {
		reverse_iterator it;
		it.ptr = this->h;
		return it;
	}
	iterator<T> insert(iterator<T> pos, const T& v)
	{
		dnode<T>* temp = new dnode<T>;
		temp->val = v;

		temp->next = pos.ptr;
		temp->prev = pos.ptr->prev;

		pos.ptr->prev->next = temp;
		pos.ptr->prev = temp;

		++this->n;

		iterator<T> it;
		it.ptr = temp;
		return it;
	}
		
	

};
template<typename T>
class iterator {
private:
	dnode <T> *ptr;
public:
	T& operator*() {
		return this->ptr->val;
	}
	T* operator->() {
		return& (this->ptr->val);
	}
	bool operator ==(const iterator& rhs)
	{
		return (this->ptr == rhs.ptr);

	}
	bool operator!=(const iterator& rhs) {
		return ptr != rhs.ptr;
	}
	iterator& operator++() {
		this->ptr = this->ptr->next;
		return *this;
	}
	iterator operator ++(int) {
		iterator old;
		old = *this;
		this->ptr = this->ptr->next;
		return old;
	}
	iterator& operator-- () {
		this->ptr = this->ptr->prev;
		return *this;
	}
	iterator operator--(int) {
		iterator old;
		old = *this;
		this->ptr = this->ptr->prev;
		return old;
	}


};

int main() {
	list<int> l;
	//list<int> :: iterator it;
	l.insert(l.end(),10);
	l.insert(l.end(),29);
	l.insert(l.end(),39);

	auto it = l.begin();
	
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			std::cout << *it << " ";
		}
		cout << endl;

		for (auto it = l.rbegin(); it != l.rend(); --it) {
			std::cout << *it << "";
		}
		cout << endl;
	}




#include <iostream>

template <typename T>
class forwardlist
{
	node<T>* h;
	int n;
	public() :
		forwardlist()
	{
		this->h = new node<T>;
		this->h->next = nullptr;
		this->n = 0;

	}
	void push_front(const T& v)

	{
		node <T>* temp;
		temp = new node <T>;
		temp->val = v;
		temp->next = h->next;
		this->h->next = temp;
		++this->n;
	}

	bool empty()
	{
		return h->next = nullptr;
	}

	T front()
	{
		return h->next->data;
	}

	void  pop_front( )
	{
		node <T>* temp;
		temp = this->++next;
		this->h->next = temp->next;
		delete temp;
		--this->n;
	}

};

int main() {
	forwardlist <int> list;
	list.push_front(22);
	list.push_front(44);
	list.push_front(99);
	list.push_front(55);

}


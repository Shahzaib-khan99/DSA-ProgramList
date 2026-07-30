S// listDSArepo3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;
class node {
private:
	int data;
	node* next;
public:
	node() {
		next = nullptr;
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
};
class list {
private:
	node* head;
	node* position;
	int  size;
public:
	list()
	{
		size = 0;
		head = nullptr;
		position = nullptr;
	}
	void insert(int val)
	{
		node* newnode = new node();
		newnode->setdata(val);
		newnode->setnext(nullptr);
		if (head == nullptr)
		{
			head = newnode;
			position = newnode;
			newnode->setnext(head); // for the circular list
		}
		else {
			newnode->setnext(position->getnext());
			position->setnext(newnode);
			position = newnode;
		}
		size++;
	}

	bool search(int val)
	{
		position = head;

		for (int i = 0; i < size; i++)
		{
			if (position->getdata() == val)
			{
				cout << "Your search value " << val << " is found." << endl;
				return true;
			}

			position = position->getnext();
		}

		cout << "Value is not found." << endl;
		return false;
	}
	bool remove(int val)
	{
		node* lastposition = head;

		if (!search(val))
		{
			cout << "Value is not found." << endl;
			return false;
		}

		while (lastposition->getnext() != position)
		{
			lastposition = lastposition->getnext();
		}
	d

		if (head == position && size == 1)
		{
			delete head;
			head = nullptr;
			position = nullptr;
		}
		else if (position == head)
		{
			head = head->getnext();
			lastposition->setnext(head);
			delete position;
			position = head;
		}
		else
		{
			lastposition->setnext(position->getnext());
			delete position;
			position = lastposition->getnext();
		}

		size--;
		cout << "Value deleted successfully." << endl;
		return true;
	} 
	void display() {
		node* temp = head;
		for (int i = 0; i < size; i++)
		{
			cout << temp->getdata() << " ";
			temp = temp->getnext();
		}
		cout << endl;
	}
	void update(int oldval, int newval)
	{
		position = head;

		for (int i = 0; i < size; i++)
		{
			if (position->getdata() == oldval)
			{
				position->setdata(newval);
				cout << "Value updated successfully." << endl;
				return;
			}

			position = position->getnext();
		}

		cout << "Value not found." << endl;
	}
};

	int main() {
		list li;
		li.insert(32);
		li.insert(31);
		li.insert(90);
		li.insert(99);
		li.insert(400);
		li.insert(222);
		li.insert(75);
		li.insert(72);
		li.insert(97);
		li.display();
		li.search(98);
		li.search(31);
		li.search(400);
		li.search(91);
		li.search(44);
		li.search(1);
		li.display();
		li.update(75, 77);
		li.update(32, 111);
		li.update(97, 500);
		li.display();
		li.remove(400);
		li.display(); 


	}

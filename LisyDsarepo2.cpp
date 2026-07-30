

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
	node* head = nullptr;
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

	void display()
	{
		node* temp = head;

		for (int i = 0; i < size; i++)
		{
			cout << temp->getdata() << " ";
			temp = temp->getnext();
		}
	}
	bool empty()
	{
		return size == 0;
	}
	void remove(int val)
	{
		// If list is empty
		if (head == nullptr)
		{
			cout << "List is empty\n";
			return;
		}
		// Case 1: Only one node exists
		if (head == position)
		{
			if (head->getdata() == val)
			{
				delete head;
				head = nullptr;
				position = nullptr;
				size--;
				cout << "Node deleted\n";
			}
			else
			{
				cout << "Value not found\n";
			}
			return;
		}
		// Case 2: More than one node exists
		node* current = head;
		node* previous = position;
		for (int i = 0; i < size; i++)
		{
			if (current->getdata() == val)
			{
				// Delete first node
				if (current == head)
				{
					head = head->getnext();
					position->setnext(head);
				}
				// Delete last node
				else if (current == position)
				{
					position = previous;
					position->setnext(head);
				}

				// Delete middle node
				else
				{
					previous->setnext(current->getnext());
				}

				delete current;
				size--;
				cout << endl;
				cout << "Node deleted\n";
				return;
			}

			previous = current;
			current = current->getnext();
		}


		cout << "Value not found\n";
	}
	void search(int val)
	{
		if (head == nullptr)
		{
			cout << "List is empty." << endl;
			return;
		}
		node* temp = head;
		for (int i = 0; i < size; i++)
		{
			if (temp->getdata() == val)
			{
				cout << endl;
				cout << "Value " << val
					<< " found at index " << i << "." << endl;
				return;
			}
			temp = temp->getnext();
		}
		cout << endl;
		cout << "Value not found." << endl;
	}
	void update(int oldval,int  newval)
	{
		if (head == nullptr)
		{
			cout << " list is empty" << endl;
			return;
		}
		node* temp = head;
		for (int i = 0; i < size; i++)
		{
			if (temp->getdata() == oldval)
			{
				temp->setdata(newval);
					cout << endl;
				cout << " data updated successfully" << endl;
				return;
			}
			temp = temp->getnext();
		}
		cout << endl;
		cout << "value not found \n";

	}
};
int main()
{
	list li;
	li.insert(22);
	li.insert(76);
	li.insert(65);
	li.insert(73);
	li.insert(62);
	li.insert(11);
	li.display();
	li.remove(65);
	li.display();
	li.search(55);
	li.search(11);
	cout << endl;
	li.display();
	li.remove(11);
	li.display();
	li.update(22, 100);
	li.display();
	li.search(73);
	li.display();
	li.update(73, 200);
	li.display();


}

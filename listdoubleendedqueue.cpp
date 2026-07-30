#include<iostream>
using namespace std;
class node {
private:
	int data;
	node* next;
	node* prev;
public:
	node() {
		next = nullptr;
		prev = nullptr;
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
	void setprev(node* ptr)
	{
		prev = ptr;
	}
	node* getprev()
	{
		return prev;
	}
};
class queue
{
private:
	node* front;
	node* rear;
public:
	queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	bool isempty()
	{
		return front == nullptr;
	}
	void insertfront(int val)
	{
		node* newnode = new node();
		newnode->setdata(val);
		if (isempty())
		{
			front = rear = newnode;
		}
		newnode->setnext(front);
		front->setprev(newnode);
		front = newnode;
		cout << val << " ";
	}
	void insertrear(int val)
	{
		node* newnode = new node();
		newnode->setdata(val);
		if (isempty())
		{
			front = rear = newnode;
		}
		newnode->setnext(rear);
		rear->setprev(newnode);
		rear = newnode;
		cout << val << " ";
	}
	void deletefront()
	{
		if (isempty())
		{
			cout << "queue is empty" << endl;
			return;
		}
		node* temp = front;
		cout << temp->getdata() << "front data deleted successfully" << endl;
		if (front == rear)
		{
			front = rear = nullptr;
         }
		front = front->getnext();
		front->setprev(nullptr);

		delete temp;
	}
	void deleterear()
	{
		if (isempty())
		{
			cout << "queue is empty" << endl;
		}
		node* temp = rear;
		cout << temp->getdata() << "rear dat deleted" << endl;
		if (front == rear)
		{
			front = rear = nullptr;
		}
		rear = rear->getprev();
		rear->setnext(nullptr);
		delete temp;
	}
	void display()
	{
		node* temp = front;
		while (temp != nullptr)
		{
			cout << temp->getdata();
			temp->getnext();
			return;
		}
	}
};
int main()
{
	queue q;
	q.insertfront(23);
	q.insertfront(34);
	q.insertfront(76);
	q.insertfront(22);
	q.display();
	q.insertrear(88);
	q.insertrear(65);
	q.insertrear(11);
	q.insertrear(17);
	q.display();
	q.deletefront();
	q.deletefront();
	q.deletefront();
	q.display();
	q.deleterear();
	q.deleterear();
	q.deleterear();
	q.display();
}
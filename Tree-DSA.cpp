#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node* right;
    node* left;

public:

    node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    void setdata(int val)
    {
        data = val;
    }

    int getdata()
    {
        return data;
    }

    void setright(node* ptr)
    {
        right = ptr;
    }

    node* getright()
    {
        return right;
    }

    void setleft(node* ptr)
    {
        left = ptr;
    }

    node* getleft()
    {
        return left;
    }
};


class BST
{
private:

    node* root;


    void inorder(node* current)
    {
        if (current != nullptr)
        {
            inorder(current->getleft());
            cout << current->getdata() << " ";
            inorder(current->getright());
        }
    }


    void preorder(node* current)
    {
        if (current != nullptr)
        {
            cout << current->getdata() << " ";
            preorder(current->getleft());
            preorder(current->getright());
        }
    }


    void postorder(node* current)
    {
        if (current != nullptr)
        {
            postorder(current->getleft());
            postorder(current->getright());
            cout << current->getdata() << " ";
        }
    }


public:

    BST()
    {
        root = nullptr;
    }


    void insert(int val)
    {
        node* parent = root;
        node* child = root;

        node* newnode = new node();
        newnode->setdata(val);


        if (root == nullptr)
        {
            root = newnode;
            return;
        }


        while (child != nullptr)
        {
            parent = child;

            if (val < child->getdata())
            {
                child = child->getleft();
            }

            else if (val > child->getdata())
            {
                child = child->getright();
            }

            else
            {
                cout << "Duplicate value" << endl;
                delete newnode;
                return;
            }
        }


        if (val < parent->getdata())
        {
            parent->setleft(newnode);
        }

        else
        {
            parent->setright(newnode);
        }
    }



    void inorder()
    {
        inorder(root);
    }


    void preorder()
    {
        preorder(root);
    }


    void postorder()
    {
        postorder(root);
    }

};



int main()
{
    BST bs;


    bs.insert(43);
    bs.insert(54);
    bs.insert(19);
    bs.insert(53);
    bs.insert(40);
    bs.insert(39);
    bs.insert(12);
    bs.insert(61);
    bs.insert(80);
    bs.insert(98);
    bs.insert(99);
    bs.insert(34);
    bs.insert(26);
    bs.insert(74);



    cout << "::Inorder Traversal:: ";
    bs.inorder();


    cout << endl;


    cout << "::Preorder Traversal:: ";
    bs.preorder();


    cout << endl;


    cout << "::Postorder Traversal:: ";
    bs.postorder();


    return 0;
}
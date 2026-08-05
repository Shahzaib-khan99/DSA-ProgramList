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
    bool search(int val)
    {
        node* temp = root;
        while (temp != nullptr)
        {
            if (val == temp->getdata())
                return true;
        }
        else if (val < temp->getdata())
        {
            temp = temp->getleft();
            }
        else
        {
            temp = temp->getright();
            }
            return false;
    }
      
    void remove(int val)
    {
        node* parent = nullptr;
        node* current = root;
        while (current != nullptr && current->getdata() != val)
        {
            parent = current;
            if (val < current->getdata())
            {
                current = current->getleft();
            }
            else {
                current = current->getright();
            }
        }
        if (current == nullptr)
        {
            cout << "value not found " << endl;
            return;
        }
        if (current->getleft() == nullptr && current->getright() == nullptr)
        {
            if (current == root)
                root = nullptr;
            else if (parent ->getleft() == current)
                parent->setleft(nullptr);
            else
                parent->setright(nullptr);
            delete current;
        }
        else if (current->getleft() != nullptr && current->getright() == nullptr)
        {
            if (current == root)
            {
                root = current->getleft();
            }
            else if (parent->getleft() == current)
            {
                parent->setleft(current->getleft());
            }
            else {
                parent->setright(current->getleft());
                delete current;
            }
        }
        else if (current->getright() != nullptr && current->getleft() == nullptr)
        {
            if (root == current)
            {
                root = current->getright();
            }
            else if (parent->getleft() == current)
            {
                parent->setleft(current->getright());
            }
            else
            {
                parent->setright(current->getright())
                    delete current;
            }
        }
        else
        {
            node* successorparent = current;
            node* successor = current ->getright();
            while (successor->getleft() != nullptr)
            {
                successorparent = successor;
                successor = successor->getleft();
            }
            current->setdata(successor->getdata());
            if (successorparent->getleft() == successor)
            {
                successorparent->setleft(successor ->getright());
            }
            else {
                successorparent->setright(successor->getright());
                delete successor;
            }
        }
        else {
            node* preparent = current;
            node* pre = current->getleft();
            while (pre->getright() != nullptr)
            {
                preparent = pre;
                pre = pre->getright();
            }
            current->setdata(pre->getdata());
            if (preparent->getright() == pre)
            {
                preparent->setright(pre->getleft();
            else {
                preparent->setleft(pre->getleft());
                delete pre;
            }
            }
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

    cout << ":: search value::";
    if (bs.search(80));
    {
        cout << " value found" << endl;
    }
    else 
    cout << "value not found";

    cout << "\nBefore Delete : ";
    bs.inorder();

    bs.remove(40);

    cout << "\nAfter Delete : ";
    bs.inorder();

    return 0;
}
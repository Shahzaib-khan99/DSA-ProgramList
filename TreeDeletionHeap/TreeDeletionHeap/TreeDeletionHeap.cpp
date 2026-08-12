#include <iostream>
using namespace std;

class node
{
private:
    int data;
    int height;
    node* right;
    node* left;

public:

    node()
    {
        data = 0;
        height = 1;
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

    void setheight(int val)
    {
        height = val;
    }

    int getheight()
    {
        return height;
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


class AVL
{
private:

    node* root;


    int height(node* current)
    {
        if (current == nullptr)
            return 0;

        return current->getheight();
    }


    int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }


    int getBalance(node* current)
    {
        if (current == nullptr)
            return 0;

        return height(current->getleft()) - height(current->getright());
            
    }


    void updateHeight(node* current)
    {
        if (current != nullptr)
        {
            current->setheight(1 + max(
                    height(current->getleft()),
                    height(current->getright())
                )
            );
        }
    }


    node* rightRotate(node* current)
    {
        node* leftChild = current->getleft();
        node* temp = leftChild->getright();

        leftChild->setright(current);
        current->setleft(temp);

        updateHeight(current);
        updateHeight(leftChild);

        return leftChild;
    }


    node* leftRotate(node* current)
    {
        node* rightChild = current->getright();
        node* temp = rightChild->getleft();

        rightChild->setleft(current);
        current->setright(temp);

        updateHeight(current);
        updateHeight(rightChild);

        return rightChild;
    }


    node* insert(node* current, int val)
    {
        if (current == nullptr)
        {
            node* newnode = new node();
            newnode->setdata(val);
            return newnode;
        }


        if (val < current->getdata())
        {
            current->setleft(
                insert(current->getleft(), val)
            );
        }
        else if (val > current->getdata())
        {
            current->setright(
                insert(current->getright(), val)
            );
        }
        else
        {
            cout << "Duplicate value" << endl;
            return current;
        }


        updateHeight(current);

        int balance = getBalance(current);


        if (balance > 1 &&
            val < current->getleft()->getdata())
        {
            return rightRotate(current);
        }


        if (balance < -1 &&
            val > current->getright()->getdata())
        {
            return leftRotate(current);
        }


        if (balance > 1 &&
            val > current->getleft()->getdata())
        {
            current->setleft(
                leftRotate(current->getleft())
            );

            return rightRotate(current);
        }


        if (balance < -1 &&
            val < current->getright()->getdata())
        {
            current->setright(
                rightRotate(current->getright())
            );

            return leftRotate(current);
        }


        return current;
    }


    node* minValueNode(node* current)
    {
        node* temp = current;

        while (temp->getleft() != nullptr)
        {
            temp = temp->getleft();
        }

        return temp;
    }


    node* remove(node* current, int val)
    {
        if (current == nullptr)
        {
            return nullptr;
        }


        if (val < current->getdata())
        {
            current->setleft(
                remove(current->getleft(), val)
            );
        }
        else if (val > current->getdata())
        {
            current->setright(
                remove(current->getright(), val)
            );
        }
        else
        {
            if (current->getleft() == nullptr &&
                current->getright() == nullptr)
            {
                delete current;
                return nullptr;
            }


            else if (current->getleft() == nullptr)
            {
                node* temp = current->getright();

                delete current;

                return temp;
            }


            else if (current->getright() == nullptr)
            {
                node* temp = current->getleft();

                delete current;

                return temp;
            }


            else
            {
                node* temp =
                    minValueNode(current->getright());

                current->setdata(
                    temp->getdata()
                );

                current->setright(
                    remove(
                        current->getright(),
                        temp->getdata()
                    )
                );
            }
        }


        updateHeight(current);

        int balance = getBalance(current);


        if (balance > 1 &&
            getBalance(current->getleft()) >= 0)
        {
            return rightRotate(current);
        }


        if (balance > 1 &&
            getBalance(current->getleft()) < 0)
        {
            current->setleft(
                leftRotate(current->getleft())
            );

            return rightRotate(current);
        }


        if (balance < -1 &&
            getBalance(current->getright()) <= 0)
        {
            return leftRotate(current);
        }


        if (balance < -1 &&
            getBalance(current->getright()) > 0)
        {
            current->setright(
                rightRotate(current->getright())
            );

            return leftRotate(current);
        }


        return current;
    }


    bool balanced(node* current)
    {
        if (current == nullptr)
        {
            return true;
        }

        int balance = getBalance(current);

        if (balance > 1 || balance < -1)
        {
            return false;
        }

        return balanced(current->getleft()) &&
            balanced(current->getright());
    }


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

    AVL()
    {
        root = nullptr;
    }


    void insert(int val)
    {
        root = insert(root, val);
    }


    void remove(int val)
    {
        root = remove(root, val);
    }


    int height()
    {
        return height(root);
    }


    bool balanced()
    {
        return balanced(root);
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
    AVL avl;

    avl.insert(43);
    avl.insert(54);
    avl.insert(19);
    avl.insert(53);
    avl.insert(48);
    avl.insert(39);
    avl.insert(12);
    avl.insert(61);
    avl.insert(80);
    avl.insert(58);
    avl.insert(99);
    avl.insert(100);
    avl.insert(30);
    avl.insert(26);
    avl.insert(74);


    cout << ":: Inorder Traversal :: ";
    avl.inorder();

    cout << endl;


    cout << ":: Preorder Traversal :: ";
    avl.preorder();

    cout << endl;


    cout << ":: Postorder Traversal :: ";
    avl.postorder();

    cout << endl;


    cout << ":: Height :: ";
    cout << avl.height();

    cout << endl;


    cout << ":: Balanced :: ";

    if (avl.balanced())
        cout << "Yes";
    else
        cout << "No";

    cout << endl;


    cout << "\nBefore Delete : ";
    avl.inorder();


    avl.remove(48);
    avl.remove(61);
    avl.remove(99);
    avl.remove(39);
    avl.remove(66);
    avl.remove(101);

    cout << "\nAfter Delete : ";
    avl.inorder();

    cout << endl;


    cout << ":: Height After Delete :: ";
    cout << avl.height();

    cout << endl;


    cout << ":: Balanced After Delete :: ";

    if (avl.balanced())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
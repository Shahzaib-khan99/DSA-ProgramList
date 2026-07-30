#include<iostream> 

template<typename T>
std::pair<iterator, bool> insert(const T& v) {
    tnode<T>* temp, * nn;

    
    temp = this->H->P;

    
    while (temp != this->H) {
        if (v < temp->val) {
            if (temp->L == this->H)
                break;
            else
                temp = temp->L;
        }
        else if (v > temp->val) {
            if (temp->R == this->H)
                break;
            else
                temp = temp->R;
        }
        else {
          
            return std::make_pair(iterator(temp), false);
        }
    }

    
    nn = new tnode<T>();
    nn->val = v;
    nn->P = temp;
    nn->L = nn->R = this->H; 

    
    if (temp == this->H) {
       
        this->H->P = nn;
    }
    else if (v < temp->val) {
        temp->L = nn;
    }
    else {
        temp->R = nn;
    }

    
    ++this->n;

    
    return std::make_pair(iterator(nn), true);
}
int size() const {
    return n;
}
bool empty() const {
    return root == null;
}
bool full() const {
    tnode<T>* ptr;
    ptr = new bnode<T>;
    if (ptr == null)
    {
        return true;
    }
    else {
        delete ptr;
        return false;
    }
}
iterator erase(iterator pos) {
    tnode<T>* to_del;
    to_del = pos.ptr;
    if (to_del->left == to_del->right)
    {

        to_del->left == this->h && to_del->right == this->h
    }
    if (to_del->val < to_del->parent->val)
    {
        to->del->parent->left = this->h;
    }
    else{
        to_del->parent->right = this->h;
    delete to_del;
    --this->n;
    return pos;
}
}
// delete node which have one child 
    else if (to - del->left != this->h && to_del->right == this->h) {
        to_del->parent->right = to_del->left;
        to_del->left->parent = to_del->parent;
        delete to_del;
    }
    else if (to_del->left == this->h && to_del->right != this->h)
    {
        to_del->right->parent = to_del->parent;
        delete to_del;

    }
    
        pred = to_del->left;
        while (prd->right != this->h)
            pred = pred->right;
        if (pred == to_del->left)
            pred->parent = to_del->parent;
        pred->right = to_del->right;
        to_del->right->parent = pred;
        // if to_del is the root node 
        if(to_del == this->h->parent
            this->h->parent=pred;
        else if (to_del == to_del->parent->left)
            to_del->parent->left =pred;
        else 
            to_del->parent->right =pred;
       // condition for when the predecessor is left of its parent
        else
        
            pred->parent->right = pred->left;
            if (pred->left != this->h)
            {
                pred->left->parent = pred->parent;
                pred->left = to_del->left;
                pred->right = to_del->right;
                pred->parent = to_del->parent;
                to_del->left->parent = pred;
                to_del->right->parent = pred;
                if (to_del_parent = this->h)
                {
                    this->h->parent = pred;

                }
                else if (to_del == to_del_parent->left)
                {
                    to_del->parent_left = pred;
                }
                else (to_del == to_del->parent->right)
                    to_del ->parent->right = pred;
                delete to_del;
                --this->n;
                return pos;

                     

            }
        
}


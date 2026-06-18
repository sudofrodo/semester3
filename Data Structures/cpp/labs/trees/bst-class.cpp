#include <iostream>
using namespace std;


class BST{
    public:
    int val;
    BST* left = NULL;
    BST* right = NULL;
    BST* parent = NULL;
    BST(int val ) {
        this -> val = val;
    }

    BST(int val , BST* par){
        this -> val = val;
        parent = par;
    }
    

    void insert(int val) {
        if (val < this -> val) {
            if (this -> left == NULL)
                this -> left = new BST(val, this);
            else
                this -> left -> insert(val);
        } else {
            if (this -> right == NULL)
                this -> right = new BST(val, this);
            else
                this -> right -> insert(val);
        }
    }


    void print() {
        cout << this -> val << endl;
        if(this -> left) {
            this -> left -> print();
        }
       
        if(this -> right) {
            this -> right -> print();
        }
    }

    BST* find_min(){
        BST* min_node = this;
        if (this -> left != NULL) {
            min_node = this -> left -> find_min();
        }
        return min_node;
    }

    BST* find_root(){
        BST* root = this;
        if(this -> parent != NULL) {
            root = this -> parent -> find_root();
        }
        return root;
    }
    void set_for_parent(BST* new_ref=NULL) {
        if (this -> parent == NULL)
            return;
        if (this -> parent -> right == this)
            this -> parent -> right = new_ref;
        if (this -> parent -> left == this)
            this -> parent -> left = new_ref;
    }

    BST* remove(int val) {
        if (this -> parent == NULL && this -> right == NULL and this -> left == NULL)
            return NULL;
        if (this -> val == val) {
            if (this -> right == NULL && this -> left == NULL) {
                     if (this -> parent -> right == this)
                        this -> parent -> right = NULL;
                     if (this -> parent -> left == this)
                        this -> parent -> left = NULL;
                    delete(this);
            }
        }

        if (val < this -> val){
            if (this -> left != NULL) 
                return this -> left -> remove(val);
            else {
                return this -> find_root();
            }
        } else {
            if(this -> right != NULL)
                return this -> right -> remove(val);
            else {
                return this -> find_root();
            }
        }

    }


};


int main() {
    BST b(5);
    b.insert(3);
    b.insert(7);
    b.insert(9);
    b.insert(4);
    // cout << b.val << endl;
    // cout << b.left -> val << endl;
    // cout << b.right -> val << endl;
    b.print();
    b.remove(9);
    cout << endl;
    b.print();
    return 0;
}
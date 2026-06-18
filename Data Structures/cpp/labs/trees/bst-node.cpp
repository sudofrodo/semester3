#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* createNode(int data) {
    node* new_node = new node;
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    
    return new_node;
}

node* InsertIntoTree(node* root, int data) {
    node* temp = createNode(data);
    //this is for iteration
    node* curr = new node;
    curr = root;

    if(root == NULL) {
        //say when tree is empty
        root = temp;
        
    } else {
        while(curr != NULL) {
        if(data > curr -> data) {
            if(curr -> right == NULL) {
                curr -> right = temp;
                break;
            }

                curr = curr -> right;
        } else if (data < curr -> data) {
                if(curr -> left == NULL){
                    curr -> left = temp;
                    break;
                }

                curr = curr -> left;
        }
    }
    }
    return root;
}

void print(node* root) {
    if(root == NULL) return;
    cout << root -> data << endl;
    print(root -> left);
    print(root -> right);
}

int main() {
    node* tree = NULL;
    tree = InsertIntoTree(tree, 5);
    print(tree);
    return 0;
}

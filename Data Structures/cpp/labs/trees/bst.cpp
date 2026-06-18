#include<iostream>
 
using namespace std;
 
// A structure representing a node of a tree.
struct node
{
	int data;
	node *left;
	node *right;
};
 
// A function creating new node of the tree and assigning the data.
node* CreateNode(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
 
	return newnode;
}
 
// A function creating binary search tree.
node* InsertIntoTree(node* root, int data)
{
	// Create node using data from argument list.
	node *temp = CreateNode(data);
	node *curr = new node;
	curr = root;
 
	// If root is null, assign it to the node created.
	if(root == NULL)
		root = temp;
	else	
	{
		// Find the position for the new node to be inserted.
		while(curr != NULL)
		{
			if(data > curr -> data )
			{
				if(curr->right == NULL)
				{
					// If current node is NULL then insert the node.
					curr->right = temp;
					break;
				}
				// Shift pointer to the left.
				curr = curr->right;
			}
 
			else if(data < curr -> data)
			{
				if(curr->left == NULL)
				{
					// If current node is NULL then insert the node.
					curr->left = temp;
					break;
				}
				// Shift pointer to the left.	
				curr = curr->left;
			}
		}
	}
	return root;
}



int main() {
    node* tree;
    InsertIntoTree(tree , 5);
    print(tree);
    return 0;
}
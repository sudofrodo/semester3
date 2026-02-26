#include <iostream>
using namespace std;
struct node{
int val;
node *next;
};
node* create_node(node *current , int val) {
node *n;
 n = new node;
n -> val = val;
n -> next = NULL;

current -> next = n;
return n;

}
void output_list(node *head) {
node *current = head;
cout << "[ ";
while (current != NULL) {
    cout << current -> val << "   ";
    current = current -> next;
}
cout << " ]" << endl;
}
void delete_after_node(node *current) {
    node* temp = current -> next;
    current->next = current -> next -> next;
    delete temp;
}
node* unshift(node *head) {
node *del = head;
head = head -> next;
delete del;
return head;
}

void delete_node(int num , node *head) {
node *current = head;
node *previous = NULL;
node *link = NULL;
node *del = NULL;

while (current -> val != num) {
    previous = current;
    current = current -> next;
}
current = head;

while (current != NULL) {
    if (current -> val == num ) {

    link = current -> next;
    del = current;
    }
    current = current -> next;
}
previous -> next = link;
delete del;

} //this should link the previous node with the next node;

int main() {
node *h ;
h = new node;
h -> val = 1;
h -> next = NULL;
node *current = h;

current = create_node(current, 2);
current = create_node(current, 3);
current = create_node(current, 4);
current = create_node(current, 5);

current = h -> next;
output_list(h);
h = unshift(h);

//delete_after_node(h);
cout << "Modified list " << endl;
output_list(h);
return 0;
}


/* TODO : Make Remove functions */
#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

class List{
    
    node* head;
    public:
    void insertFront(int x);
    void insertEnd(int x);
    void insertAfter(int val , int x);
    void removeEnd();
    void removeFront();
    
    node* getLast();

    void printList();
};


node* List::getLast() {
    if(this -> head == NULL) {
        return NULL;
    }
    node* temp = this -> head -> next;
    while(temp -> next != this -> head) {
        temp = temp -> next;
    }
    return temp;
}


void List::insertEnd(int x){
    node* temp = new node;
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        temp->next = head;
        return;
    }

    node* last = this -> getLast();
    last -> next = temp;
    temp -> next = this -> head;
}

void List::insertFront(int x){
    node* temp = new node;
    node* last = this -> getLast();
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        temp->next = head;
        return;
    }
    temp -> next = this->head;
    this -> head = temp;
    last -> next = temp;
}

void List::insertAfter(int val, int x){
    node* temp = new node;
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        return;
    }
    node* search = this -> head;
    while(search -> next != this -> head){
        if(search->val == val){
            break;
        }
        search = search -> next;
    }
    if(search -> val == val){
    temp->next = search->next;
    search->next = temp;
    } else {
        cout << "Value not found." << endl;
    }
}

void List::removeEnd() {
    if(this -> head == NULL ) {
        cout << "Empty list" << endl;
        return;
    }
    node* last = this -> getLast();
    cout << "Removed Value: " <<  last -> val << endl;
    node* temp = this -> head;
    while(temp -> next != last) {
        temp = temp -> next;
    }
    temp -> next = this -> head;
    delete(last);
}

// void List::removeFront() {
//     if(this -> head == NULL ) {
//         cout << "Empty list" << endl;
//         return;
//     }
//     node* first = this -> head;
//     this -> head = this -> head -> next;
//     this -> getLast() -> next = head;
//     cout << "Removed Value: " <<  first -> val << endl;
//     delete(first);

    
// }


void List::printList(){
    node* temp = this -> head;
    while(temp != NULL) {
        cout << temp -> val << "  ";
        temp = temp -> next;
        if (temp == this -> head)
            return;
    }
}

int main() {
    List l;
   
    l.insertEnd(1);

    l.insertEnd(2);
    l.insertFront(3);
    l.insertAfter(1,5);
    l.insertAfter(2,6);
    l.insertAfter(1,7);
    l.printList();
    cout << endl;
    l.removeEnd();
    l.printList();
    cout << endl;
    // l.removeFront();
    // cout << endl;
    // l.printList();
    // cout << endl;
    //cout << l.getLast() -> next -> val << endl;
    return 0;
}

//p = (struct node*)malloc(sizeof(struct node))
// void* ptr = NULL;
//     if(ptr) {
//         cout << "not null";
//     }
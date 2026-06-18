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
    void insertBefore(int val, int x);

    int removeFront();
    int removeEnd();
    int removeAfter(int val);
    int removeBefore(int val);


    void printList();
};

void List::insertEnd(int x){
    node* temp = new node;
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        return;
    }
    node* last = this->head;
    while(last -> next != NULL) {
        last = last -> next;
    }
    last -> next = temp;
}

void List::insertFront(int x){
    node* temp = new node;
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        return;
    }
    temp -> next = this->head;
    this->head = temp;
}

void List::insertAfter(int val, int x){
    node* temp = new node;
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        return;
    }
    node* search = head;
    while(search != NULL){
        if(search->val == val){
            break;
        }
        search = search -> next;
    }
    if(search){
    temp->next = search->next;
    search->next = temp;
    } else {
        cout << "Value not found." << endl;
    }
}

void List::insertBefore(int val, int x){
    node* temp = new node;
    temp -> val = x;
    if(this->head == NULL) {
        this->head = temp;
        return;
    }
    if(head -> val == val){
        temp -> next = head;
        head = temp;
        return;
    }
    node* search = head;
    node* prev = head;
    while(search != NULL){
        if(search -> val == val){
            break;
        }
        prev = search;
        search = search -> next;
    }
    if(search){
    prev -> next = temp;
    temp->next = search;
    } else {
        cout << "Value not found." << endl;
    }
}

void List::printList(){
    node* end = this -> head;
    if(end == NULL) {
        cout << "List is Empty." << endl;
        return;
    }
    while(end != NULL) {
        cout << end -> val << "  ";
        end = end -> next;
    }
    cout << endl;
}

int List::removeFront() {
    int ret;
    if(this -> head == NULL) {
        throw underflow_error("List is Empty. Can't Remove");
    }
    ret = this -> head -> val;
    node* temp = this -> head;
    this -> head = this -> head -> next;
    delete(temp);
    return ret;
}

int List::removeEnd() {
    int ret;
    node* last = this->head;

    if(last == NULL) {
        throw underflow_error("List is Empty. Can't Remove");
    }

    if (last -> next == NULL) {
        ret = last -> val; 
        this -> head = NULL;
        delete(last);
        return ret;
    }

    node* secondLast = this->head;
    while(last -> next != NULL) {
        secondLast = last;
        last = last -> next;
    }

    secondLast -> next = NULL;
    ret = last -> val;  
    delete(last);
    return ret;
}

int List::removeAfter(int val) {
    int ret;
    if(this->head == NULL) {
        throw underflow_error("List is Empty. Can't Remove");
    }

    if(this -> head -> next == NULL){
        throw underflow_error("Only one value. Can't Remove After");
    }

    node* search = this -> head;
    while(search != NULL){
        if(search -> val == val){
            break;
        }
        search = search -> next;
    }
    
    if(search){
        if(search -> next == NULL && search -> val == val) {
        throw out_of_range("Cant remove after last value.");
        }

        node* temp = search -> next;
        ret = temp -> val;
        search -> next = temp -> next;
        delete(temp);

    } else {
        throw invalid_argument("Value not found.");
    }
    return ret;
}

int List::removeBefore(int val){
    int ret;
    if(this->head == NULL) {
        throw underflow_error("List is Empty. Can't Remove");
    }

    if(this -> head -> next == NULL){
        throw underflow_error("Only one value. Can't Remove Before");
    }

    if(this -> head -> val == val){
        throw underflow_error("Can't Remove Before Head");
    }

    node* search = head;
    node* prev = head;
    while(search->next != NULL){
        if(search-> next -> val == val){
            break;
        }
        prev = search;
        search = search -> next;
    }
    if(search){
        if(search == this -> head) {
            ret = search -> val;
            this -> head = search -> next;
            delete(search);
            return ret;
        }
      //  if(search -> next == NULL )
        ret = search -> val;
        prev -> next = search -> next;
        delete(search);
        
    } else {
       throw invalid_argument("Value not found.");
    }
    return ret;
}

int main() {
    List l;
    l.insertEnd(4);
    l.insertEnd(5);
    l.insertEnd(6);
    l.insertFront(2);
    l.insertFront(1);
    l.insertAfter(2,3);
    l.insertAfter(6,7);
    l.printList();
    l.insertBefore(2,0);
    l.insertBefore(1,10);
    l.insertBefore(7,11);
  // l.insertBefore(99,0);
 //   l.insertBefore(100,0);
    l.insertBefore(0,100);
  //  l.insertEnd(12);
    l.printList();

    // cout << l.removeFront() << endl;
    // l.printList();
    
    // cout << l.removeEnd() << endl;
    // l.printList();

    // cout << l.removeAfter(100) << endl;
    // l.printList();

    // cout << l.removeAfter(1) << endl;
    // l.printList();

    // cout << l.removeAfter(11) << endl;
    // l.printList();

    
  // cout << l.removeAfter(7) << endl;
  //  cout << l.removeAfter(123) << endl;

    // cout << l.removeBefore(12) << endl;
    // l.printList();

    // List l1;
    // l1.insertEnd(1);
  //  l1.removeEnd();
   //l1.removeFront();
  // l1.removeAfter(0);
  // l1.printList();
    return 0;
}

//p = (struct node*)malloc(sizeof(struct node))
// void* ptr = NULL;
//     if(ptr) {
//         cout << "not null";
//     }
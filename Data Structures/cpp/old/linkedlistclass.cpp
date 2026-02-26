#include <iostream>
using namespace std;

template <class T>
class List
{
    struct node
    {
        T val;
        node *next;
    };

    node *head , *last;

    void delete_after_node(node *current);

public:
    List();
    void push(T val);
    T pop();
    void print_list();
};
template <class T>
List<T>::List()
{
    last = head = NULL;
}
template <class T>
void List<T>::push(T val)
{
    node *temp = new node;
    temp->val = val;
    temp->next = NULL;

    if (last == NULL) // if list is empty
    {
        head = temp;
        last = temp;
    } else {
    last -> next = temp;
    last = last -> next;
    }
}
template <class T>
T List<T>::pop()
{
    T val;

    if (head -> next == NULL) //only one element in list
    {
        val = last -> val;
        delete head;
        head = NULL;
        last = NULL;
    } else {
    val = last -> val;
    node *current = head;
    while(current -> next != last) {
    current = current -> next;
    }
    delete_after_node(current);
    last = current;
    }
    return val;
}
template <class T>
void List<T>::delete_after_node(node *current)
{
    node* temp = current->next;
    current -> next = current ->next->next;
}
template <class T>
void List<T>::print_list() {
    node *current = head;
    cout << "[  ";
    while (current != NULL) {
        cout << current -> val << "   ";
        current = current -> next;
    }
    cout << "]" << endl;
}
int main()
{
    cout << "helloo\n";
    List<int>l;
    l.push(5);
    l.push(10);
    l.print_list();
    cout << endl;
    l.pop();
    l.print_list();
}

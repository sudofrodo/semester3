#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
private:
int arr[SIZE] = {0};
int front = 0; //deletion
int rear = -1; //insertion

public:
void enqueue(int x) {
    if(rear == SIZE - 1) {
       throw overflow_error("Que is full. Can't enqueue");
    } else {
        arr[++rear] = x;
    }
}

int dequeue() {
    if(front == rear + 1) {
        throw underflow_error("Que is empty. cannot dequeue");
    } else {
        return arr[front++];
    }
}

void print() {
    for(int i = front; i <= rear ; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
};
int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    
    q.print();
    cout << q.dequeue() << endl;
    q.print();
    //q.enqueue(10);
    
    return 0;
}
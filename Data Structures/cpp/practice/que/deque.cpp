#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
private:
int arr[SIZE] = {0};
int front = 0; //deletion
int rear = -1; //insertion
int count = 0;

public:
void enqueueRear(int x) {
    if(count == SIZE) {
       throw overflow_error("Que is full. Can't enqueue");
    } else {
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }
}

void enqueueFront(int x) {
    if (count == SIZE) {
        throw overflow_error("Que is full. Can't enqueue");
    } else {
        if(front == 0)
            front = SIZE - 1;
        else
            front = front - 1;
        arr[front] = x;
        count++;
    }
}

int dequeueRear() {
    if (count == 0) {
        throw overflow_error("Que is full. Can't enqueue");
    } else {
        int temp = arr[rear];
        count--;
        if(rear == 0)
            rear = SIZE - 1;
        else
            rear = rear - 1;
        
        return temp;
    }
}

int dequeueFront() {
    if(count == 0) {
        throw underflow_error("Que is empty. cannot dequeue");
    } else {
        int temp = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return temp;
    }
}

void print() {
    if(count == 0) {
        cout << "Queue is empty" << endl;
        return;
    } else {
    for(int i = 0; i < count ; i++) {
        int index = (front + i) % SIZE;
        cout << arr[index] << "  ";
    }
    }
    cout << endl;
}
};

int main() {

    Queue q;

    q.enqueueFront(10);
    q.enqueueFront(20);
    q.enqueueFront(30);
    q.enqueueRear(40);
    q.enqueueRear(50);
    q.print();

  // q.enqueueFront(60);

    q.dequeueFront();
    q.dequeueRear();
    q.print();

    // q.enqueue(60);
    // q.enqueue(70);
    // q.print();

    return 0;
}
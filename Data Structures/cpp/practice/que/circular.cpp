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
void enqueue(int x) {
    if(count == SIZE) {
       throw overflow_error("Que is full. Can't enqueue");
    } else {
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }
}

int dequeue() {
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

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.print();

   // q.enqueue(60);

    q.dequeue();
    q.dequeue();
    q.print();

    q.enqueue(60);
    q.enqueue(70);
    q.print();

    return 0;
}
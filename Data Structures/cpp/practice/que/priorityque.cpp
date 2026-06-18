#include <iostream>
using namespace std;

#define SIZE 5

class Queue 
{
    private:
        int arr[SIZE][SIZE];
        int count;
    public:
        Queue();
        void insertWithPriority(int p , int x);
        int getNext();
};

Queue::Queue() 
{
    count = 0;
    for(int i = 0 ; i < SIZE ; i++) {
        arr[i][1] = -1;
    }

}

void Queue::insertWithPriority(int p , int x) {
    int i;
    if(count == SIZE) {
        throw overflow_error("Que is full. Can't enqueue");
    } else {
        for(i = 0 ; i < SIZE ; i++) {
            if(arr[i][1] == -1)
                break;
        }
    }
    arr[i][0] = x;
    arr[i][1] = p;

    count++;
}

int Queue::getNext() {
    int i;
    int max , pos = 0;
    if(count == 0) {
        throw underflow_error("Que is empty. cannot dequeue");
    } else {
        max = arr[0][1];
        for(i = 1 ; i < SIZE; i++) {
            if(max < arr[i][1]) {
                pos = i;
                max = arr[i][1];
            }
        }
        int temp = arr[pos][0];
        arr[pos][1] = -1;
        count--;
        return temp;
    }
}

int main() {
    cout << "Priority Queue" << endl;

    Queue q;
    q.insertWithPriority(3,34);
    q.insertWithPriority(4,43);
    q.insertWithPriority(5,12);
    cout << q.getNext() << endl;
    return 0;
}
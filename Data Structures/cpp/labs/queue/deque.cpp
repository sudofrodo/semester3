#include <iostream>
using namespace std;
#define MAX 5

class Deque {
    private:
        int front;
        int rear;
        int count;
        int ele[MAX];

    public:
        Deque();
        int isFull();
        int isEmpty();
        void insertRear(int item);
        int  deleteFront();
        void insertFront(int item);
        int  deleteRear();
};

Deque::Deque()
{
    front = 0;
    rear = -1;
    count = 0;
}

int Deque::isFull()
{
    int full = 0;
    if (count == MAX) {
        full = 1;
    } 
    return full;
}

int Deque::isEmpty()
{
    int empty = 0;
    if (count == 0)
        empty == 1;
    return empty;
}

void Deque::insertRear(int item)
{
    if( isFull() )
    {
        cout << "\nQueue Overflow";
        return;
    }

    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;
}

void Deque::insertFront(int item)
{
    if( isFull())
    {
        cout << "\nQueue Overflow";
        return;
    }

    //front from the opposite side
    if(front == 0)
        front = MAX - 1;
    else
        front = front - 1;
    ele[front] = item;

    count++;
}


int Deque::deleteFront(){
    if( isEmpty())
    {
        cout << "\nQueue underflow";
        return -1;
    }
    int ret;
    ret = ele[front];
    front = (front + 1) % MAX;
    
    count--;
    return ret;
}

int Deque::deleteRear(){
    if( isEmpty())
    {
        cout << "\nQueue underflow";
        return -1;
    }

    int ret;
    ret = ele[rear];
    
    if(rear == 0)
        rear == MAX - 1;
    else
        rear = rear - 1;

    count--;
    return ret;

}

int main()
{
    int  item;
    Deque q = Deque();
 
    q.insertRear(10);
    q.insertRear(20);
    q.insertRear(30);
    q.insertFront(40);
    q.insertFront(50);
   // q.insertFront(60);
 
    cout << q.deleteFront() << endl;
    cout << q.deleteRear() << endl;
    return 0;
}

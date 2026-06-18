#include <iostream>
#include "Deque.h"
using namespace std;
int main() {
    Deque<int, 10> q;
    q.enqueueRear(0);
    q.enqueueRear(1);

    int a = 0;
    int b = 1;
    int sum = 0;
    for(int i = 2 ; i < 10 ; i++) {
        sum = a + b;
        q.enqueueRear(sum);
        a = b;
        b = sum;
       
    }

  q.print();

    return 0;
}

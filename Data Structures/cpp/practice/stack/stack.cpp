#include <iostream>
#include <exception>
using namespace std;
#define SIZE 5

struct stack {
    int arr[SIZE] = {0};
    int top = -1;
};

void push(int n , stack* stk) {
    if(stk -> top == SIZE - 1) {
        throw overflow_error("Stack is full.");
    }
    stk -> top++;
    stk -> arr[stk -> top] = n;
}

int peek(stack* stk) {
    if(stk -> top == -1) {
        throw underflow_error("Stack is Empty");
    }
    return stk -> arr[stk -> top];
}

int pop(stack* stk) {
    if(stk -> top == -1) {
        throw underflow_error("Stack is Empty");
    }
    int temp =  stk -> arr[stk -> top];  
    stk -> top--;
    return temp; 
}




int main() {
   stack stk;
   push(5,&stk);
   push(6,&stk);
   push(7,&stk);
   push(8,&stk);
   push(9,&stk);
  // push(10,&stk);
   cout <<  pop(&stk);
   cout <<  pop(&stk);
   cout << peek(&stk);

   cout <<  pop(&stk);
   cout <<  pop(&stk);
   cout <<  pop(&stk);
  // pop(&stk);



    return 0;
}

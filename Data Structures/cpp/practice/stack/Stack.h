#ifndef STACK_H
#define STACK_H

#include <stdexcept>

#define SIZE 50

template <typename T>
class Stack {
private:
    T arr[SIZE]; // Now an array of type T
    int top = -1;

public:
    void push(T n) {
        if (top == SIZE - 1) {
            throw std::overflow_error("Stack is full.");
        }
        top++;
        arr[top] = n;
    }

    T peek() {
        if (top == -1) {
            throw std::underflow_error("Stack is Empty");
        }
        return arr[top];
    }

    T pop() {
        if (top == -1) {
            throw std::underflow_error("Stack is Empty");
        }
        T temp = arr[top];
        top--;
        return temp;
    }

    bool isEmpty() {
        return top == -1;
    }

    int getMin() {
        int min = arr[0];
        for(int i = 0 ; i <= top  ; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
};

#endif
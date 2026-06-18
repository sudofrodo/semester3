#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

template <typename T, int SIZE = 5>
class Deque {
private:
    T arr[SIZE];
    int front = 0;
    int rear = -1;
    int count = 0;

public:
    Deque() {
        // Initialize array if necessary, though T's default constructor handles this
    }

    void enqueueRear(T x) {
        if (count == SIZE) {
            throw std::overflow_error("Deque is full.");
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    void enqueueFront(T x) {
        if (count == SIZE) {
            throw std::overflow_error("Deque is full.");
        }
        front = (front == 0) ? (SIZE - 1) : (front - 1);
        arr[front] = x;
        count++;
    }

    T dequeueRear() {
        if (count == 0) {
            throw std::underflow_error("Deque is empty.");
        }
        T temp = arr[rear];
        rear = (rear == 0) ? (SIZE - 1) : (rear - 1);
        count--;
        return temp;
    }

    T dequeueFront() {
        if (count == 0) {
            throw std::underflow_error("Deque is empty.");
        }
        T temp = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return temp;
    }

    int size() {
        return count;
    }
    
    void print() const {
        if (count == 0) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            int index = (front + i) % SIZE;
            std::cout << arr[index] << "  ";
        }
        std::cout << std::endl;
    }

    int size() const { return count; }
};

#endif
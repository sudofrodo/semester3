#include <iostream>
using namespace std;

typedef struct{
    int top = -1;
    char vec[10];
} Stack;

inline bool is_Full(Stack* stack){
    return stack->top >= 9;
}

inline bool is_Empty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, char c) {
    if(is_Full(stack)){
        return;
    }
    stack->top++;
    stack->vec[stack->top] = c;
}

char pop(Stack* stack){
    if(is_Empty(stack)){
        return -1;
    } 
    char temp = stack->vec[stack->top];
    stack->top--;
    return temp;
}

char peek(Stack* stack){
    if(is_Empty(stack)){
        return -1;
    }
    return stack->vec[stack->top];
}

int main() {
    cout << "working" << endl;
    Stack s1;
    push(&s1, 'a');
    push(&s1, 'b');
    cout << pop(&s1) << endl;
    cout << peek(&s1) << endl;
}
#include <iostream>
using namespace std;

#define SIZE 10
int score = 0;
int attempts = 0;
int platesnum = 0;
bool stackCollapsed = false;


struct stack {
    int arr[SIZE] = {0};
    int top = -1;
};

bool isEmpty(stack* stk){
    if(stk -> top == -1){
        return true;
    }
    return false;
}

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


void viewStack(stack* stk){
    cout << "===================" << endl;
    cout << "Plate Stack" << endl << endl;
    for(int i = 0 ; i < platesnum; i++){
        cout << stk -> arr[i] << endl;
    }
    cout << endl;
}

void removePlate(stack* stk){
    platesnum--;
    attempts++;
    cout << "\nPlate with weight " << pop(stk) << " is removed." << endl;
    cout << "\nNow stack is : " << endl;
    viewStack(stk);
}

void addPlate(int w, stack* stk){
    if(!isEmpty(stk) && w > peek(stk)){
        cout << "You pushed the wrong plate." << endl;
        cout << "Game Over" << endl;
        cout << "Your score: " << score << endl;
        stackCollapsed = true;
        return;
    }

        cout << "Alright , your plate's pushed. Move on." << endl;
        cout << "Score added." << endl;
        score +=2;
        push(w,stk);
        platesnum++;
    
       attempts++;
}



int main() {
    stack* plateStack = new stack();
    while(platesnum <= 5 && attempts <= 10){
        cout << "\nWhat do you want to do" << endl;
        cout << "1: Push Plate\n2: Remove Plate" << endl;
        int choice;
        cin >> choice;
        if(choice == 1){
            cout << "Please enter your weight: " << endl;
            int weight;
            cin >> weight;
            addPlate(weight,plateStack);
            if(stackCollapsed){
                break;
            }
        }
        if(choice == 2){
            removePlate(plateStack);
        }
    }
    if(!stackCollapsed){
        if(attempts >= 10){
            cout << "\nYou ran out of attempts.";
            cout << "Your score is: ";
            cout << score << endl;
        }
        if(platesnum >= 5){
            cout << "\nYou won " << endl;
            cout << "Your score is ";
            cout << score << endl;
        }
    }

    return 0;
}
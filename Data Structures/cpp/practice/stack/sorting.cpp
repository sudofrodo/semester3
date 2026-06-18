/*TODO : Sort an unordered stack in ascending order (largest on top) by using another stack.
SOLUTION: Make the Auxiliary stack in descending order (smallest on top) and then push that stack
completely back to original.
*/

#include <iostream>
#include <limits>
#include "Stack.h"

using namespace std;

void printStack(Stack<int> ver){
    cout << "Printing stack: " << endl;
    while(!ver.isEmpty()){
        cout << ver.pop() << endl;
    }
    cout << endl;
}

Stack<int> sortStack(Stack<int> original) {
    Stack<int> auxiliary;
    
    while(!original.isEmpty()){
        int temp = original.pop();
        //if this condition is true it means temp is bigger and it should go deeper than 
        //current level so we have to pop from auxiliary till temp is its right place.
        //if this condition is false i.e temp is smaller it is fine to pushed at this level , as goal 
        //is to bring smallest value on top.
        while(!auxiliary.isEmpty() && auxiliary.peek() < temp){
            original.push(auxiliary.pop());
        }
        auxiliary.push(temp);
    }
    while(!auxiliary.isEmpty()) {
        original.push(auxiliary.pop());
    }

    return original;
}

int main() {
    
    Stack<int> stk;
    stk.push(2);
    stk.push(4);
    stk.push(1);
    stk.push(0);

     cout << stk.getMin() << endl;
    stk = sortStack(stk);

   
    printStack(stk);
   
    
    return 0;
}


// bool isSorted(Stack<int> stk){
//     bool result = true;
//     int firstVal = stk.peek();
//     while(!stk.isEmpty()){
//         if(stk.peek() < firstVal) {
//             result = false;
//             break;
//         }
//         firstVal = stk.pop();
//     }
//     return result;
// }
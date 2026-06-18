#include <iostream>
#include "Stack.h"

using namespace std;

char match(char c){
    char ret;
    if(c == '(') {
        ret = ')';
    }
    else if (c == '{'){
        ret = '}';
    }
    else if (c == '['){
        ret = ']';
    }
    return ret;
}

bool isOpenBracket(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosingBracket(char c){
    return c == ')' || c == '}' || c == ']';
}

bool validExpression(string exp){
    Stack<char> stk;
    bool result = true;

    for(char c : exp) {
        if(isOpenBracket(c)){
            stk.push(match(c));
        } else if(isClosingBracket(c)) {
            if(stk.isEmpty() || stk.peek() != c) {
                result = false;
                break;
            } else {
                stk.pop();
            }
        }
    }

    if(!stk.isEmpty())
        result = false;

    return result;
    
}

int main(){

    string s = "{(44)}";
    cout << validExpression(s);
    cout << endl;
    return 0;
    
}


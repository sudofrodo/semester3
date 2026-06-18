#include <iostream>
#include "Stack.h"
using namespace std;


int priority(char c) {
    if (c == '^')                        return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-')            return 1;
    return 0;
}

bool isOpenBracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isCloseBracket(char c) {
    return (c == ')' || c == '}' || c == ']');
}


string convertToPostfix(string exp) {
    Stack<char> stk;
    string ret = "";

    for(char c : exp) {
        if(isalpha(c) || isdigit(c)) {
                ret.push_back(c);

        } else if(isOpenBracket(c)) {
                stk.push(c);

        } else if(isCloseBracket(c)) {
                while(!stk.isEmpty() && !isOpenBracket(stk.peek())) {
                    ret.push_back(stk.pop());
                }
                stk.pop();

        } else {
                if (c == '^') {
                    stk.push(c);
                } else {
                while(!stk.isEmpty() && priority(stk.peek()) >= priority(c) ) {
                    ret.push_back(stk.pop());
                }
                stk.push(c);
            }
        }
    }
    
    while(!stk.isEmpty()) {
        ret.push_back(stk.pop());
    }
    return ret;
}

int main() {
    string s = "A+(B*C-(D/E^F)*G)*H";
    string s2 = "a+b-c*d+(e^f)*g/h/i*j+k";
    cout << convertToPostfix(s) << endl;
    return 0;
}
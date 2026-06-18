#include <iostream>
#include "Stack.h"
#include <cmath>
using namespace std;

int perform_operation(char oper, int oprnd1, int oprnd2) {
    int result;
    switch(oper) {
        case '+':
            result = oprnd1 + oprnd2;
            break;
        case '-':
            result = oprnd1 - oprnd2;
            break;
        case '*':
            result = oprnd1 * oprnd2;
            break;
        case '/':
            if (oprnd2 == 0) throw std::runtime_error("Division by zero");
            result = oprnd1 / oprnd2;
            break;
        case '%':
            if (oprnd2 == 0) throw std::runtime_error("Modulo by zero");
            result = oprnd1 % oprnd2;
            break;
        case '^':
            // pow returns double, so we cast to int
            result = static_cast<int>(pow(oprnd1, oprnd2));
            break;
        default:
            throw std::invalid_argument("Invalid operator encountered");
    }
    return result;
}

int evaluatePostfix(string s){
    Stack<int> stk;
    for (char c : s) {
        if(isdigit(c)) {
            stk.push(c - '0');
        } else {
            int result , a , b;
            if(!stk.isEmpty()) {
            a = stk.pop();
            b = stk.pop();
            result = perform_operation(c,b,a);
            }
            stk.push(result);
        }
    }
    return stk.pop();
}

int main() {
    string s = "53+82/*";
    cout << evaluatePostfix(s) << endl;
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

#include <iostream>
#include <stdexcept>
#include <cmath> // For the pow() function

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

int evaluate_postfix(string exp){
    stack<int> stk;
    int a,b,t;
    for(char c : exp){
        if(isOperator(c)){
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            t = perform_operation(c,b,a);
            stk.push(t);        
        } else {
            stk.push(c - '0');
        }
    }
    return stk.top();
}

int main() {
    string s = "53+82/*";
    int result = evaluate_postfix(s);
    cout << result << endl;
    return 0;
}
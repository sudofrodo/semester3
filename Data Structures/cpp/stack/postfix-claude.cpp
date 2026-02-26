#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '^')                        return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-')            return 1;
    return 0; // for '(' and others
}

bool isOpenBracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isCloseBracket(char c) {
    return (c == ')' || c == '}' || c == ']');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

string postfix(string exp) {
    stack<char> stk;
    string ret = "";

    for (char c : exp) {
        if (isalpha(c) || isdigit(c)) {
            // Operand: add directly to output
            ret.push_back(c);

        } else if (isOpenBracket(c)) {
            // Open bracket: always push
            stk.push(c);

        } else if (isCloseBracket(c)) {
            // Close bracket: pop until matching open bracket
            while (!stk.empty() && !isOpenBracket(stk.top())) {
                ret.push_back(stk.top());
                stk.pop();
            }
            if (!stk.empty()) stk.pop(); // pop the open bracket itself

        } else if (isOperator(c)) {
            // Operator: pop while top has greater or equal priority
            // (for right-associative '^', use strictly greater only)
            while (!stk.empty() 
                   && !isOpenBracket(stk.top()) 
                   && (c == '^' ? priority(stk.top()) > priority(c)
                                : priority(stk.top()) >= priority(c))) {
                ret.push_back(stk.top());
                stk.pop();
            }
            stk.push(c);
        }
    }

    // Pop remaining operators
    while (!stk.empty()) {
        if (!isOpenBracket(stk.top())) {
            ret.push_back(stk.top());
        }
        stk.pop();
    }

    return ret;
}

int main() {
    string exp = "a+b-c*d+(e^f)*g/h/i*j+k";
    cout << "Infix:   " << exp << endl;
    cout << "Postfix: " << postfix(exp) << endl;
    return 0;
}


// **Output:**
// ```
// Infix:   a+b-c*d+(e^f)*g/h/i*j+k
// Postfix: ab+cd*-ef^g*h/i/j*+k+
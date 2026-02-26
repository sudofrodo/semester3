#include <iostream>
#include <stack>
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

bool validExpression(string exp){
    stack<char> stk;
    bool result = true;
    for (char c : exp){
        if(c == '(' || c == '{' || c == '[' ){
            stk.push(match(c));
        } else if(c == ')' || c == '}' || c == ']'){
            if(stk.empty() || stk.top() != c){
                result = false;
                break;
            } else {
                stk.pop();
            }
        } else {
            continue;
        }
    }
    if(!stk.empty())
        result = false;
    return result;
}



int main() {
    string s = "{[[]]{()}}";
    cout << validExpression(s) << endl;;
    return 0;
}
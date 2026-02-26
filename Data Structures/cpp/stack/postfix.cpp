#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

void printStack(stack<char> ver){
    while(!ver.empty()){
        cout << ver.top();
        ver.pop();
    }
    cout << endl;
}

int priority(char c){
    int ret;
    if(c == '^'){
        ret = 3;
    } else if(c == '*' || c == '/' || c == '%'){
        ret = 2;
    } else if(c == '+' || c == '-'){
        ret = 1;
    }
    return ret;
}

bool isBracket(char c){
    return (c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']' );
}

stack<char> shunt(stack<char> stk, char c){
    while(!stk.empty()){
        char temp = stk.top();
        if(priority(temp) < priority(c)){
            stk.push(c);
            return stk;
        }
        if(priority(temp) >= priority(c)){
            stk.pop();
        }
    }
    stk.push(c);
    return stk;
}

string postfix(string exp){

    stack<char> stk;
    char temp;
    string ret = "";
    for(char c: exp){
        if(isalpha(c)){
            ret.push_back(c);
        } else{
            if(stk.empty()){
                stk.push(c);
            } else {
                temp = stk.top();
                if(isBracket(c) || isBracket(temp) || priority(c) > priority(temp)){
                    stk.push(c);
                } else if (priority(c) <= priority(temp)){
                    ret.push_back(temp);
                    stk.pop();
                    stk.push(c);
                }
        }
        } 
        printStack(stk);
    }
    
    while(!stk.empty()){
        if(!isBracket(stk.top())){
        ret.push_back(stk.top());
        }
        stk.pop();
    }
    return ret;
}



int main(){
    string exp =  "a+b-c*d+(e^f)*g/h/i*j+k";
   cout << postfix(exp);
    stack<char> stk;
    stk.push('*');
    stk.push('+');
    stk.push('+');
    stk.push('*');
    stk.push('-');
    
    stk = shunt(stk,'-');
    printStack(stk);
    cout << endl;
    return 0;
}



// while (!stk.empty() && !isBracket(stk.top()) && priority(stk.top()) >= priority(c)) {
//                     ret.push_back(stk.top());
//                     stk.pop();
//                     }
//                     stk.push(c);
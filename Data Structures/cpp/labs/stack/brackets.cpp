#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool validExpression(string exp){
    
    bool result = true;
    map<char, char> symbols = {{'(' , ')'} , {'{' , '}'}, {'[' , ']'} };
    stack<char> stk;
    bool flag = true;
    for(char c: exp){
        for(auto p : symbols){
            if(c == p.first){
                stk.push(p.second);
            }
            else if(c == p.second){
                if(stk.empty() || stk.top() != c){        
                    result = false;
                    break;
                } else {
                     stk.pop();
                }
            }
            else
                continue;
        }
    }
    if(!stk.empty())
        result = false;
    return result;
}


int main(){
string s = "][]]]]p]";
cout << validExpression(s) << endl;
return 0;
}
#include <iostream>
#include <stack>
using namespace std;

stack<int> to_binary(int dec){
    int num = dec;
    stack<int> con;
    while(dec > 0){
        con.push(dec % 2);
        dec = dec / 2;
    }  
    return con;
}

void printBinary(stack<int> ver){
    while(!ver.empty()){
        cout << ver.top();
        ver.pop();
    }
    cout << endl;
}

int main() {
    stack<int> bin = to_binary(101);
    printBinary(bin);
    return 0;
}
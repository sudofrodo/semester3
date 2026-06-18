#include <iostream>
#include "Deque.h"

using namespace std;

bool palChecker(string s) {
    Deque<char> que;

    for(char ch: s) {
        que.enqueueRear(ch);
    }

    bool areMatched = true;
    while(que.size() > 1 && areMatched) {
        if(que.dequeueFront() != que.dequeueRear())
                areMatched = false;
    }
    return areMatched;
}

int main() {
    string word = "abcd";
    palChecker(word) == 1 ? cout << "Yes\n"  : cout <<  "No\n"; 
    return 0;
}
#include <iostream>
#include <stdexcept>
using namespace std;


class Que{
public:
    static const int size = 5;
    int q[size] = {0};
    int ins_idx = 0;
    int del_idx = 0;

    bool is_empty = true;
    bool is_full = false;

    
    int inc(int val){
        if (val + 1 == size)
            return 0;
        return val + 1;
    }

    void insert(int x){
        if (is_full)
            throw overflow_error("Queue is full , can't insert.");

        q[ins_idx] = x;

        ins_idx = inc(ins_idx);

        if (ins_idx == del_idx) 
            is_full = true;

        is_empty = false;
    }

    int remove(){
        if(is_empty)
            throw underflow_error("Queue is empty , can't delete");

        int ret = q[del_idx];

        del_idx = inc(del_idx);

        if(del_idx == ins_idx)
            is_empty = true;

        is_full = false;
        
        return ret;
    }

    void print(){

        if(is_empty){
            cout << "Que is empty." << endl;
            return;
        }
        int i = del_idx;
        do {
            cout << q[i] << "  ";
            i = inc(i);
        } while (i != ins_idx);
        cout << endl;
    }
};

int main(){
    Que x;
    x.insert(19);
    x.insert(39);
    x.insert(45);
    x.insert(20);
    x.insert(39);

    //x.print();

    x.remove();
    x.insert(10);
    x.print();
    return 0;


   // checking overflow
    x.insert(44);

    //checking underflow
    for(int i = 0 ; i < 6 ; i++){
        x.remove();
    }
    

    
}




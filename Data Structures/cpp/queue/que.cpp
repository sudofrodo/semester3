#include <iostream>
#include <stdexcept>
using namespace std;


class Que{
public:
    static const int size = 5;
    int q[size] = {0};
    int ins_idx = 0;
    int del_idx = 0;

    bool is_empty() {
        return ins_idx == del_idx;
    }
    bool is_full(){
        return ins_idx == size;
    }

    void insert(int x){
        if(is_full())
           throw overflow_error("Queue is full , can't insert.");
        
        q[ins_idx] = x;

        ins_idx++;
    }

    int remove(){

        if(is_empty())
           throw underflow_error("Queue is empty , can't delete");

        int ret = q[del_idx];
        del_idx++;

        return ret;
    }

    void print(){
        if(is_empty()){
            cout << "Que is empty." << endl;
            return;
        }

        for(int i = del_idx; i < ins_idx ; i++){
            cout << q[i] << "  ";
        }
        cout << endl;
    }
};

int main(){
    Que x;
    x.insert(19);
    x.insert(39);
    x.insert(45);
    x.insert(20);
    x.insert(40);
    x.print();
    // x.remove();
    // x.remove();
    // x.remove();
    // x.remove();
    cout << x.remove() << endl;

  //  x.insert(10);
    x.print();
   // x.remove();
   

    // x.print();

    // x.insert(10);
    // x.insert(20);
    // x.print();

    // x.remove();
    // x.print();
   // cout << x.remove() << endl;

    return 0;


   // checking overflow
    x.insert(44);

    //checking underflow
    for(int i = 0 ; i < 6 ; i++){
        x.remove();
    }
    

    
}




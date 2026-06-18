#include <iostream>

using namespace std;


int main() {
    
    string gates_que[] = {"", "North" , "East" , "South" , "West"}; 
    //one empty string just to make division easy
    int index = 1;
    int cycles;

    cout << "Parking Managment System.\n" <<endl;
    cout << "How many cars: " << endl;
    cin >> cycles;
    cout << endl;
   
    int limit = cycles;
    for(int i = 1 ; i <= limit; i++){
        cout << "Car is entrering through Gate: " << gates_que[index] << endl;
        index++;
        if(i % 4 == 0){
            cout << endl;
            index = 1;
        }
    }
    return 0;

}
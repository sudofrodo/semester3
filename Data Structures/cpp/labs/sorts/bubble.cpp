/*Bubble Sort in C++ is a simple sorting algorithm that repeatedly compares adjacent elements in a list 
and swaps them if they are in the wrong order. It continues this process until the entire list is sorted.*/
#include <iostream>
using namespace std; 

void bubbleSort(int arr[] , int size){
    //i indicates pass
    for(int i = 0 ; i < size - 1 ; i++) {
    //subtracting i from size means , this many elements are sorted hence no need to go over them again.
    //subtracting 1 to save from going out of bounds at the last element
        for(int j = 0 ; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int a[5] = {10,9,8,7,6};
    bubbleSort(a,5);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < 5 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}


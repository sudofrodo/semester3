#include <iostream>
using namespace std;

void quicksort(int arr[], int start , int end) {
    if(start >= end) {
        return;
    }
    int pivot = arr[start];
    int i = start; //move it up until it finds the value bigger then pivot
    int j = end;  //move it down until it finds the value smaller than pivot
    while( i <= j) { 
    while(arr[i] < pivot) {i++;}
    while(arr[j] > pivot) {j--;}
    if(i <= j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; //now if we have found these both values , swap them so that all the values left of pivot are smaller than pivot and all the values right of pivot are bigger than it.
        i++; j--; //to see next values.
    }
    }
    
    quicksort(arr,start,j);
    quicksort(arr,i,end);
    
}

int main() {
    int a[] = {10,9,8,7,6};
    quicksort(a,0,4);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < 5 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

// create a pivot
//
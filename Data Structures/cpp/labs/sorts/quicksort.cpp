#include <iostream>
using namespace std;

void quicksort(int arr[], int start , int end) {
    if(start >= end) {
        return;
    }
    int pivot = arr[start];
    cout << "Pivot : " << pivot << endl;
    int i = start; //move it up until it finds the value bigger then pivot
    cout << "Down: " << start;
    int j = end;  //move it down until it finds the value smaller than pivot
    cout << "Up" << end << endl;
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
    int a[] = {5,9,2,4,1,8,6,0,3,7};
    quicksort(a,0,9);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < 10 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

// create a pivot
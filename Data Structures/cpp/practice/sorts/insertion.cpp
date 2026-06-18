/*Insertion Sort in C++ is a simple sorting algorithm that works by dividing the list into sorted and unsorted portions. 
It repeatedly picks a value from the unsorted portion and inserts it into its correct position in the sorted portion of the list.*/
#include <iostream>
using namespace std;

void insertionSort(int arr[] , int size) {
    int key, j;
    for(int i = 1 ; i < size ; i++) {
        key = arr[i];
        //start comparing in the left direction
        j = i - 1;
        //if the key  is less than j val it means this is the right postion of key , hence we make space for the key , by pushing. j val right.
        while(j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        //as we decremented j earlier , now we have to add 1 for right index.
        arr[j + 1] = key;
    }
}

int main() {
    int a[5] = {10,9,8,7,6};
    insertionSort(a,5);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < 5 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

/**/
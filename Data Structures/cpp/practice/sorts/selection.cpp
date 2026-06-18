/*Selection sort in C++ is a simple sorting algorithm that repeatedly finds the minimum element from the 
unsorted portion of an array and places it at the beginning, resulting in a sorted array.*/
#include <iostream>
using namespace std;

void selectionSort(int arr[] , int size) {
    int min_idx, min_val;
    for(int i = 0  ; i < size - 1 ; i++) {
        min_idx = i;
        min_val = arr[i];
        for(int j = i + 1 ; j < size ; j++) {
            if(arr[j] < min_val) {
                min_idx = j;
                min_val = arr[j];
            }
        }
        arr[min_idx] = arr[i];
        arr[i] = min_val;
    }
}
int main() {

    int a[5] = {10,9,8,7,6};
    selectionSort(a,5);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < 5 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
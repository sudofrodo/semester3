#include <iostream>
using namespace std; 


int* combineSorted(int arr1[], int arr2[], int size1 , int size2) {
    int size3 = size1 + size2;
    int* arr3 = new int[size3];
    int i = 0, j = 0, k = 0;

    while(i < size1  && j < size2) {
        if(arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1) {
        arr3[k] = arr1[i];
        i++; k++;
    }
    while(j < size2) {
        arr3[k] = arr2[j];
        j++; k++;
    }

    return arr3;
}

void mergeSort(int arr[], int size) {
    if(size <= 1) {
        return;
    }
    
    int m = size / 2;
    
    // Create left array
    int left[m];
    for(int i = 0; i < m; i++) {
        left[i] = arr[i];
    }
    
    // Create right array
    int right[size - m];
    for(int i = 0; i < size - m; i++) {
        right[i] = arr[m + i];
    }
    
    // Recursively sort both halves
    mergeSort(left, m);
    mergeSort(right, size - m);
    
    // Merge sorted halves using combineSorted
    int* merged = combineSorted(left, right, m, size - m);
    for(int i = 0; i < size; i++) {
        arr[i] = merged[i];
    }
    delete[] merged;
}

int main() {
    int a[] = {10,9,8,7,6};
    mergeSort(a,5);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < 5 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
    
    return 0;
}
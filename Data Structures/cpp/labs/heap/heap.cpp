#include <iostream>
#include <cmath>
using namespace std;


//root ,largest ,left ,right are indexes, root is where the heapify process would begin.
//heapify three nodes
void heapify(int arr[] , int size , int root) {
    int largest = root; //this is a max heap.
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != root) {
        
       
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr,size,largest);

    }
}

//build heap tree from list
void build_heap(int arr[] , int size){
    //this is heapifying from bottom
    int start = size / 2 - 1;
    for(int i = start ; i >= 0 ; i--){
        heapify(arr,size,i);
    }
}

void insert_heap(int arr[] , int size , int val){
    arr[size] = val;
    int idx = size;
    while(idx > 0) {
        int parent = (idx - 1) / 2;
        if(val > arr[parent]) {
            arr[idx] = arr[parent];
            idx = parent;
        } else {
            break;
        }
    }
    arr[idx] = val;
}

int delete_heap(int arr[] , int size) {
    int temp = arr[0];
    arr[0] = arr[size - 1];
    heapify(arr,size - 1 , 0);
    return temp;
}

void heap_sort(int arr[], int size){
    build_heap(arr, size);
    //build max heap , swap first element (largest in heap tree) with last element of heap
    //heapify the rest of tree , so next max would come up , put it before previous max by i.
    for(int i = size - 1 ; i >= 0 ; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}



int main() {
    int lst[] = {100,5,3,2,8,15,6};
    build_heap(lst,7);
    // insert_heap(lst,7,1);
    // insert_heap(lst,8,105);
    delete_heap(lst,7);
    for(int i = 0 ; i < 6 ; i++){
        cout << lst[i] << " ";
    }
    cout << endl;
}


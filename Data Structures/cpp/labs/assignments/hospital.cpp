#include <iostream>
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

void heapify_min(int arr[] , int size , int root) {
    int smallest = root; //this is a min heap.
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }
    
    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if(smallest != root) {
        
       
        int temp = arr[root];
        arr[root] = arr[smallest];
        arr[smallest] = temp;

        heapify(arr,size,smallest);

    }
}

//build heap tree from list
void build_heap(int arr[] , int size, bool max){
    //this is heapifying from bottom
    int start = size / 2 - 1;
    if(max){
    for(int i = start ; i >= 0 ; i--){
        heapify(arr,size,i);
    }
    } else {
        for(int i = start ; i >= 0 ; i--){
        heapify_min(arr,size,i);
    }
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

void insert_heap_min(int arr[] , int size , int val){
    arr[size] = val;
    int idx = size;
    while(idx > 0) {
        int parent = (idx - 1) / 2;
        if(val < arr[parent]) {
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





int main()
{
    int lst[] = {100,5,3,2,8,15,6};
    build_heap(lst,7,false);
    insert_heap_min(lst,7,1);
    for(int i = 0 ; i < 8 ; i++){
        cout << lst[i] << " ";
    }
    return 0;
}
#include <iostream>
using namespace std;

void quicksort(int arr[], int start, int end) {
    if (start >= end) {
        cout << "[BASE CASE] start=" << start << " >= end=" << end << ", returning." << endl;
        return;
    }

    int pivot = arr[start];
    cout << "\n[CALL] quicksort(start=" << start << ", end=" << end << ") | pivot=" << pivot << endl;

    int i = start;
    int j = end;

    cout << "[INIT] i=" << i << ", j=" << j << endl;

    while (i <= j) {
        while (arr[i] < pivot) {
            cout << "  [SCAN LEFT]  arr[" << i << "]=" << arr[i] << " < pivot=" << pivot << ", moving i right." << endl;
            i++;
        }
        while (arr[j] > pivot) {
            cout << "  [SCAN RIGHT] arr[" << j << "]=" << arr[j] << " > pivot=" << pivot << ", moving j left." << endl;
            j--;
        }

        if (i <= j) {
            cout << "  [SWAP] arr[" << i << "]=" << arr[i] << " <-> arr[" << j << "]=" << arr[j] << endl;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
            cout << "  [AFTER SWAP] i=" << i << ", j=" << j << endl;
        }
    }

    cout << "[PARTITION DONE] Pivot=" << pivot << " | Left subarray: [" << start << ".." << j << "] | Right subarray: [" << i << ".." << end << "]" << endl;

    // Print current array state after partition
    cout << "[ARRAY STATE] ";
    for (int k = start; k <= end; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    cout << "[RECURSE LEFT]  quicksort(" << start << ", " << j << ")" << endl;
    quicksort(arr, start, j);

    cout << "[RECURSE RIGHT] quicksort(" << i << ", " << end << ")" << endl;
    quicksort(arr, i, end);
}

int main() {
    int a[] = {5, 9, 2, 4, 1, 8, 6, 0, 3, 7};

    cout << "=== QUICKSORT TRACE ===" << endl;
    cout << "Initial Array: ";
    for (int i = 0; i < 10; i++) cout << a[i] << " ";
    cout << "\n" << endl;

    quicksort(a, 0, 9);

    cout << "\n=== RESULT ===" << endl;
    cout << "Sorted Array: ";
    for (int i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
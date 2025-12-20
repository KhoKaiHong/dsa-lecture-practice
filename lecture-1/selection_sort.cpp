#include <iostream>
using namespace std;

// This is my implementation of selection sort, using normal swap
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Initially store the index where the minimum occurs at i
        int minIdx = i;
        // For each element after arr[i], perform comparison and update minimum
        // accordingly to find the index where minimum element occurs
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // If minimum is not at the initial index, swap it with the index where
        // minimum occurs
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main() {
    int arr[] = {6, 1, 7, 4, 2, 9, 8, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    cout << "Sorted array using selection sort: \n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n" << endl;

    return 0;
}

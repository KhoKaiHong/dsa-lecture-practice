#include <iostream>
using namespace std;

// This is my implementation based on the course, using normal swap
void insertionSortNorm(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int cmp = i - 1;
        while (cmp >= 0 && arr[cmp] > arr[cmp + 1]) {
            int temp = arr[cmp];
            arr[cmp] = arr[cmp + 1];
            arr[cmp + 1] = temp;
            cmp--;
        }
    }
}

// This is my implementation based on the course, using arithmetic swap
void insertionSortArithmetic(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int cmp = i - 1;
        while (cmp >= 0 && arr[cmp] > arr[cmp + 1]) {
            // At this point, arr[cmp] is addition of smaller and larger value
            arr[cmp] = arr[cmp] + arr[cmp + 1];
            // Now, arr[cmp + 1] is the larger value as the smaller value is
            // subtracted from the sum
            arr[cmp + 1] = arr[cmp] - arr[cmp + 1];
            // Now, arr[cmp] is the smaller value as the larger value is
            // subtracted from the sum
            arr[cmp] = arr[cmp] - arr[cmp + 1];
            cmp--;
        }
    }
}

// This is my implementation based on the course, using XOR swap
void insertionSortXor(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int cmp = i - 1;
        while (cmp >= 0 && arr[cmp] > arr[cmp + 1]) {
            // At this point, arr[cmp] is XOR of smaller and larger value
            arr[cmp] = arr[cmp] ^ arr[cmp + 1];
            // Now, arr[cmp + 1] is the larger value as the XORed value is XORed
            // against the smaller value again
            arr[cmp + 1] = arr[cmp] ^ arr[cmp + 1];
            // Now, arr[cmp] is the smaller value as the XORed value is XORed
            // against the larger value again
            arr[cmp] = arr[cmp] ^ arr[cmp + 1];
            cmp--;
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test 1: Normal swap
    int arr1[n];
    copy(arr, arr + n, arr1);
    insertionSortNorm(arr1, n);
    cout << "Sorted array using Normal swap: \n";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\n" << endl;

    // Test 2: Arithmetic swap
    int arr2[n];
    copy(arr, arr + n, arr2);
    insertionSortArithmetic(arr2, n);
    cout << "Sorted array using Arithmetic swap: \n";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\n" << endl;

    // Test 3: XOR swap
    int arr3[n];
    copy(arr, arr + n, arr3);
    insertionSortXor(arr3, n);
    cout << "Sorted array using XOR swap: \n";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << "\n" << endl;

    return 0;
}

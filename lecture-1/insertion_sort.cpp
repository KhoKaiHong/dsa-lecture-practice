#include <iostream>
using namespace std;

// This is my implementation based on the course, using normal swap
void insertionSortNorm(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        // Since we are accessing arr[j - 1], j has to be > 0, not >= 0
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

// This is my implementation based on the course, using arithmetic swap
void insertionSortArithmetic(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            // At this point, arr[j] is addition of smaller and larger value
            arr[j] = arr[j] + arr[j - 1];
            // Now, arr[j - 1] is the smaller value as the larger value is
            // subtracted from the sum
            arr[j - 1] = arr[j] - arr[j - 1];
            // Now, arr[j] is the larger value as the smaller value is
            // subtracted from the sum
            arr[j] = arr[j] - arr[j - 1];
            j--;
        }
    }
}

// This is my implementation based on the course, using XOR swap
void insertionSortXor(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            // At this point, arr[j] is XOR of smaller and larger value
            arr[j] = arr[j] ^ arr[j - 1];
            // Now, arr[j - 1] is the smaller value as the XORed value is XORed
            // against the larger value again
            arr[j - 1] = arr[j] ^ arr[j - 1];
            // Now, arr[j] is the smaller value as the XORed value is XORed
            // against the smaller value again
            arr[j] = arr[j] ^ arr[j - 1];
            j--;
        }
    }
}

// This is my implementation based on the shifting method for insertion sort
void insertionSortShift(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        int temp = arr[i];
        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {6, 1, 7, 4, 2, 9, 8, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Normal swap
    int arr1[n];
    copy(arr, arr + n, arr1);
    insertionSortNorm(arr1, n);
    cout << "Sorted array using Normal swap: \n";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\n" << endl;

    // Arithmetic swap
    int arr2[n];
    copy(arr, arr + n, arr2);
    insertionSortArithmetic(arr2, n);
    cout << "Sorted array using Arithmetic swap: \n";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\n" << endl;

    // XOR swap
    int arr3[n];
    copy(arr, arr + n, arr3);
    insertionSortXor(arr3, n);
    cout << "Sorted array using XOR swap: \n";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << "\n" << endl;

    // Shifting method
    int arr4[n];
    copy(arr, arr + n, arr4);
    insertionSortShift(arr4, n);
    cout << "Sorted array using shifting method: \n";
    for (int i = 0; i < n; i++) cout << arr4[i] << " ";
    cout << "\n" << endl;

    return 0;
}

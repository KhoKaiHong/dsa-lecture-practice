#include <iostream>
using namespace std;

// This is my implementation of the merge function based on the course
int* mergeNaive(int a[], int asize, int b[], int bsize) {
    int csize = asize + bsize;
    int* c = new int[csize];

    int i = 0, j = 0, k = 0;
    // Loop goes on as long as i and j does not exceed their respective array
    // limit
    while (i < asize || j < bsize) {
        if (j == bsize || (i < asize && a[i] < b[j])) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    return c;
}
// As this merge function returns a pointer to the first element of the new
// array based on 2 separate sorted arrays, it only works if it is run once,
// thus is not used in the divide and conquer method for mergesort where it
// needs to be run multiple times

void merge(int arr[], int left, int mid, int right) {}

// This is the implementation of the sort function based on the course
int* sort(int arr[], int len) {
    if (len < 2) return arr;
    int mid = len / 2;
    int a[] = arr[0..mid - 1];
    int b[] = arr[mid..len - 1];
    int asize = sizeof(a) / sizeof(a[0]);
    int bsize = sizeof(b) / sizeof(b[0]);
    a = sort(a, asize);
    b = sort(b, bsize);
    merge(a, b)
}

int main() {
    int arr1[] = {1, 4, 7, 6};
    int arr2[] = {2, 3, 5, 8, 9};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    int* arr3 = merge(arr1, arr1Size, arr2, arr2Size);
    int arr3Size = arr1Size + arr2Size;
    cout << "Sorted array: \n";
    for (int i = 0; i < arr3Size; i++) cout << arr3[i] << " ";
    cout << "\n" << endl;
    return 0;
}

#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int *arr, int n) {
    int min_index;
    for (int i = 0; i < n-1; i++) {
        min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main() {
    int arr[] = {3, 5, 2, 3, 7, 4, 2, 12, 10, 14, 18, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
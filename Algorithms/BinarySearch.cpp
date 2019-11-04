#include <algorithm>
#include <iostream>
using namespace std;

int BinarySearch(int *arr, int s, int e, int key) {
    int mid = (s + e) / 2;
    if (key == arr[mid]) {
        return mid;
    }
    if (s >= e) {
        return -1;
    }

    if (key < arr[mid]) {
        BinarySearch(arr, s, mid - 1, key);
    }
    if (key > arr[mid]) {
        BinarySearch(arr, mid + 1, e, key);
    }
}

int main() {
    int size;
    cout << "Enter Size of Array" << endl;
    cin >> size;

    int *arr;
    arr = new int[size];
    cout << "Input Array" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter Key to Search" << endl;
    cin >> key;

    sort(arr, arr + size);
    cout << "Sorted Array : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = BinarySearch(arr, 0, size, key);
    cout << "Key found at index " << index;

    return 0;
}

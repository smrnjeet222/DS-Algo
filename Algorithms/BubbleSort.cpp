#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\n";
    return;
}
void recurciveBbSort(int arr[], int n) {
    if (n == 1) return;

    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
    recurciveBbSort(arr, n - 1);
}

int main() {
    int n = 10;
    int arr[n] = {5, 4, 6, 2, 1, 3, 9, 0, 8, 7};

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // BubbleSort(arr, n);
    recurciveBbSort(arr, n);
    cout << "\nBubble Sort : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
#include <cmath>
#include <iostream>
using namespace std;

int JumpSearch(int* arr, int x, int n) {
    int m = sqrt(n);
    int prev = 0;

    while (arr[min(n, m) - 1] < x) {
        prev = m;
        m += m;
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(m, n)) {
            return -1;
        }
    }
    if (arr[prev] == x)
        return prev;
    return -1;
}

int main() {
    int key;
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610, 823};
    int n = sizeof(arr) / sizeof(*arr);

    cin >> key;

    int index = JumpSearch(arr, key, n);

    cout << key << " is at index : " << index;

    return 0;
}
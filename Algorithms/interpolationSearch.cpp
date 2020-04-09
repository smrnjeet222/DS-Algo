#include <iostream>
using namespace std;

int ipolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = (n - 1);

    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) return arr[lo] == x ? lo : -1;

        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x) return pos;

        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 58, 10, 13, 16, 17, 20, 23, 25, 29, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = ipolationSearch(arr, n, 16);

    index != -1 ? cout << "INDEX: " << index : cout << "Not Found";

    return 0;
}
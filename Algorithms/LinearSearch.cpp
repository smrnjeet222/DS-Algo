#include <iostream>
using namespace std;

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

    int flag = 0;

    for (int i = 0; i < size; i++) {
        if (key == arr[i]) {
            cout << key << " is found at index " << i << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "Key not Found" << endl;
    }

    return 0;
}
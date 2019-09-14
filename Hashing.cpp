#include <bits\stdc++.h>
using namespace std;
#define TableSize 13
#define prime 7

class DoubleHash {
private:
    int* hash;
    int curr_size;

public:
    DoubleHash() {
        hash = new int[TableSize];
        curr_size = 0;
        for (int i = 0; i < TableSize; i++) {
            hash[i] = -1;
        }
    }
    bool isFull() {
        return (curr_size == TableSize);
    }
    int hash1(int key) {
        return (key % TableSize);
    }
    int hash2(int key) {
        return (prime - key % prime);
    }
    void Insert(int d) {
        if (isFull())
            return;
        int index = hash1(d);
        if (hash[index] != -1) {
            int index2 = hash2(d);
            int i = 1;
            while (true) {
                int new_index = (index + i*i* index2) % TableSize;

                if (hash[new_index] == -1) {
                    hash[new_index] = d;
                    break;
                }
                i++;
            }
        } else {
            hash[index] = d;
        }
        curr_size++;
    }
    void Display() {
        for (int i = 0; i < TableSize; i++) {
            if (hash[i] != -1) {
                cout << i << "-->" << hash[i] << endl;
            } else {
                cout << i << endl;
            }
        }
    }
};

int main() {
    int arr[] = {19, 27, 36, 10, 64, 19, 32, 49, 81};
    int n = sizeof(arr) / sizeof(arr[0]);

    DoubleHash H;
    for (int i = 0; i < n; i++) {
        H.Insert(arr[i]);
    }

    H.Display();

    return 0;
}
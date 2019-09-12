#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int *arr;
    int capacity;
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int Lchild(int i) {
        return 2 * i + 1;
    }
    int Rchild(int i) {
        return 2 * i + 2;
    }
    bool isLeaf(int i) {
        if (Lchild(i) > size)
            return true;
        else
            return false;
    }
    void ShiftUp(int i) {
        if (i == 0)
            return;
        int p_index = parent(i);

        if (arr[p_index] < arr[i]) {
            swap(arr[p_index], arr[i]);
            ShiftUp(p_index);
        }
    }
    void ShiftDown(int i) {
        if (isLeaf(i))
            return;

        int l = Lchild(i);
        int r = Rchild(i);

        int max_index = max(l, r);

        if (arr[max_index] > arr[i]) {
            swap(arr[max_index], arr[i]);
            ShiftDown(max_index);
        }
    }

public:
    MaxHeap(int c) {
        arr = new int[c];
        this->capacity = c;
        this->size = 0;
    }
    void EnsureSize() {
        if (size == capacity) {
            capacity *= 2;
            return;
        }
    }
    int GetSize() {
        return size;
    }
    int GetMax() {
        for(int i = 0 ; i<size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return arr[0];
    }
    void Insert(int k) {
        EnsureSize();
        arr[size] = k;
        ShiftUp(size);
        size++;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int extractMax() {
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        ShiftDown(0);
        return max;
    }
    int DeleteAt(int k) {
        int r = arr[k];
        arr[k] = arr[size - 1];
        size--;
        int p = parent(k);
        if(k==0 || arr[k] < arr[p])
            ShiftDown(k);
        else 
            ShiftUp(k);
        
        return r;
    }
};

int main() {
    MaxHeap H(5);
    H.Insert(2);
    H.Insert(13);
    H.Insert(8);
    H.Insert(1);
    H.Insert(5);
    H.Insert(10);
    H.Insert(4);

    H.DeleteAt(0);

    H.GetMax();

    return 0;
}
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int j,key;
    for(int i=1 ; i<n ; i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    return ;
}

void recurciveInsSort(int arr[], int n){
    if (n<=1) return ;

    recurciveInsSort(arr,n-1);
    int last = arr[n-1];
    int j = n-2;

    while(j>=0 && arr[j]>last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main(){

    int arr[] = {3, 5, 2, 3, 7, 4, 2, 12, 10, 14, 18, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    // insertionSort(arr,n);
    recurciveInsSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
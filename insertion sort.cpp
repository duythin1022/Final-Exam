#include<iostream>
using namespace std;

void insertion(int arr[], int size){
    int key, j;
    for(int i = 1; i < size; i++){
        key = arr[i];
        j= i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {4,2,6,2,87,2,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion(arr, size);
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
}
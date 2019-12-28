#include<iostream>
using namespace std;

void selectionSort(int arr[], int size){
    int min_index;
    for(int i = 0 ; i < size - 1; i++){
        min_index = i;
        for(int k = i + 1; k < size; k++){
            if(arr[k] < arr[min_index]){
                min_index = k;
                swap(arr[min_index], arr[i]);
            } 

        }
    }
}
int main(){
    int arr[] = {4,2,6,2,87,2,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
}
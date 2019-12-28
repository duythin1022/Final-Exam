#include<iostream>
using namespace std;

void heaptify(int arr[], int pos, int size){
    int largest = pos;
    int l = 2*pos+ 1;
    int r = 2*pos +2;
    if(l < size && arr[l] > arr[largest]){
        largest = l;
    }
        if(r < size && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != pos){
        swap(arr[largest], arr[pos]);
        heaptify(arr, largest, size);
    }   
}

void sort(int arr[], int pos, int size){
    for(int i = size/2 - 1; i >= 0; i--){
        heaptify(arr, i, size);
    }
    for(int i = size - 1; i>= 0; i++){
        heaptify(arr,0, i);
    }
}


int main(){
    int arr[] = {1,2,3,4,5};
    sort(arr, 0, 5);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}
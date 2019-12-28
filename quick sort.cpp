#include<iostream>
using namespace std;

void swap(int&a, int&b){
  int temp = a;
  a = b;
  b = temp;
}
int partition(int arr[], int pos, int lastPos){
    int low = pos;
    int high = lastPos - 1;
    int pivot = arr[lastPos];
    while(true){
      //Tat ca truong hop deu co dau "BANG" =
        while(low <= high && arr[low] < pivot) low++;
        while(low <= high && arr[high] > pivot) high--;
        
        if(low >= high) break;
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
    swap(arr[low], arr[lastPos]);
    return low;
}

void quickSort(int arr[],int pos, int lastPos){
    if(pos < lastPos){
        int pi = partition(arr, pos, lastPos);
        quickSort(arr, pos, pi -1 ); //cho nay la pi-1
        quickSort(arr, pi+ 1, lastPos); //pi + 1
    }
}
void print(int arr[], int size){
    for(int i= 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {9,1,8,2,7,3,6,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    print(arr, size);
}


#include<iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if(low>high)
        return;

    int pivot = arr[high];
    int i = low;

    for (int j = low; j<high; j++){
        if(arr[j]<pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    quickSort(arr, low, i-1);
    quickSort(arr, i+1, high);
}

int main(){
    int arr[] = {64,34,25,12,22,11,90,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

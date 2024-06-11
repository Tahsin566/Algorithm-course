
#include<iostream>

using namespace std;
void insertionSort(int arr[], int n){

    //loop for traversing the array from index 1
     for(int i=1;i<n;i++){
        int key=arr[i];  
        int j=i-1;  

        while(j>=0&& key<arr[j]){
            arr[j+1]=arr[j];   
            j--;
            //Shifting rightward when condition satisfies and continues for each i untill j>=0
        }
        arr[j+1]=key;  //places the value of key where the condition becomes false

     }


}

int main(){

int arr[]={7, 5, 1, 3, 11};
int n= sizeof(arr)/sizeof(arr[0]);

insertionSort(arr, n);
//printArray(arr)
for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}
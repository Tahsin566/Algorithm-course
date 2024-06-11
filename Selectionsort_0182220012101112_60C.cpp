
#include<iostream>

using namespace std;

void selectionSort(int arr[], int n){

     for(int i=0;i<n-1;i++){
        int minn=i;  //consider the element at i index as minimum
        for(int j=i+1;j<n;j++){  //Checks for other elements at right 
            if(arr[j]<arr[minn]){
                minn=j;       //if there is a new minimum,initialize the index at minn
            }

        }
        swap(arr[i],arr[minn]);  //swap the arr[i] with arr at minn index
     }

}


int main(){
int arr[]={7,5, 1, 3, 11};
int n= sizeof(arr)/sizeof(arr[0]);

selectionSort(arr, n);
//printArray(arr)
for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


return 0;
}
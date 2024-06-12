
#include<bits/stdc++.h>

using namespace std;

int arr[] = {1,3,7,2,4,5,8,9};

int n = sizeof(arr)/sizeof(int);

void bubblesort(){

    int temp;

    //for iterating through the array values
    for(int i = 0;i<n;i++){
        //for comparing elements
        for(int j = 0;j<n-i-1;j++){  
            //With each iteration,the largest unsorted value gets at the end which results in reduction of traversal range by an index

            if(arr[j] > arr[j+1]){

                temp = arr[j];         //swap value bwtween an index and next index
                arr[j] = arr[j+1];
                arr[j+1] = temp;
        
            }

        }
    }

}

int main(){

    bubblesort();

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
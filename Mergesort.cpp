

#include <iostream>

using namespace std;

int a[10] = {10, 14, 33, 35, 42, 44, 19, 26, 27, 31};
int b[10];
int n = 10;

void mergee(int low, int mid, int high)
{

    int i,l1,l2;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid, l2 <= high; i++)
    {
        // filling the array with minimum values between index l1 and l2

        if (a[l1] < a[l2])
        {
            b[i] = a[l1]; 
            l1++;
        }
        else if (a[l2] <= a[l1])
        {
            b[i] = a[l2]; //
            l2++;
        }
    }

    while (l1 <= mid)
    { 
        b[i++] = a[l1++];  //Filling the remaining values from 1st sub-array
    }
    
    while (l2 <= high)
    {
        b[i++] = a[l2++];  //Filling the remaining values from 2nd sub array
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i]; // Copy the contents of array b to array a
    }
}

void mergesort(int low, int high)
{

    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);      // divide the left sub-array
        mergesort(mid + 1, high); // divide the right sub-array
        mergee(low, mid, high);   // merge the left and right sub-array
    }
    else
    {
        return;    //when low==high
    }
}

int main()
{

    mergesort(0, n);

    printf("\nList after sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
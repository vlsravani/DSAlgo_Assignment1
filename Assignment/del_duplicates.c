#include <stdio.h>

// function for removing duplicates
void removeDuplicate(int arr[], int n) 
{
    int j = 0;
    int temp[n];
    
    // traverse elements of arr. 
    for (int i = 0; i < n-1; i++) 
    {
    	// if ith element is not equal to (i+1)th element of arr, then store ith value in temp
        if (arr[i] != arr[i+1]) 
        {
            temp[j] = arr[i];
            j++;
        }
    }

    // store last value of arr in temp
    temp[j++] = arr[n-1];

    // make array arr equal to temp
    for (int i = 0; i < j; i++)
    {
    	arr[i] = temp[i];
    }
    
    // print final array arr
    for (int i = 0; i < j; i++)
    {
        printf("%d ", arr[i]);
    }

}

int main() 
{
    int arr[] = {1, 3, 5, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // calling function when number of elements in array is greater than 1
    if (n > 1)
    {
        removeDuplicate(arr, n);
    }
    return 0;
}
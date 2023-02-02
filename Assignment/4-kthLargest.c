#include <stdio.h>

// This function swaps values pointed by xp and yp
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// picks up last element between start and end
int partition(int a[], int start, int end)
{
	// Selecting the pivot element
	int pivot = a[end];
	// Initially partition-index will be at starting
	int pIndex = start;
	for (int i = start; i < end; i++) {
		// If an element is lesser than pivot, swap it.
		if (a[i] <= pivot) {
			swap(&a[i], &a[pIndex]);
			// Incrementing pIndex for further swapping.
			pIndex++;
		}
	}

	// Lastly swapping or the correct position of pivot
	swap(&a[pIndex], &a[end]);
	return pIndex;
}

// function to find KthLargest element in array
int KthLargest(int arr[], int n,int k)
{
    if (n == 1) {
    return arr[0];
  }

  int l = 0;
  int h = n - 1;
  int kth = n-k;

  while (l <= h)
    {
        int pivot = partition(arr, l, h);
        if (pivot < kth)
        {        // to the right side
            l = pivot + 1;
        }
        else if (pivot > kth) {  // to the left side
        h = pivot - 1;
        }
        else {            // pivot is equal to the target, return value
        return arr[pivot];
    }
  }
    return -1;
}


// Driver Code
int main()
{
    int arr[30], N, i, K;

    printf("Enter no. of elements in an array: ");
    scanf("%d", &N);

    printf("\nEnter elements:\n");

    for ( i = 0; i < N; i++)
        scanf("%d",&arr[i]);

    printf("\nEnter the value of kth position : ");
    scanf("%d", &K);

    int y = KthLargest(arr, N, K);
	printf("The maximum element with position %d is %d", K, y);

	return 0;
}

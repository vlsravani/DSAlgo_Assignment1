#include <stdio.h>

void lims(int arr[], int n)
{
	int max = 1, len = 1, maxIndex = 0;

	// traverse the array from the 2nd element
	for (int i=1; i<n; i++)
	{
		if (arr[i] > arr[i-1])
			len++;
		else {
			if (max < len)  {
				max = len;
				maxIndex = i - max;
			}
			len = 1;
		}
	}

	// comparing the length of the last increasing subarray with 'max'
	if (max < len) {
		max = len;
		maxIndex = n - max;
	}

     printf("length of monotonically increasing sequence = %d", max);

	for (int i=maxIndex; i<max+maxIndex; i++)                  // Print size, element and index of elements of longest increasing contiguous subarray
        printf("\n Element = %d  Index = %d ",arr[i], i );
}

int main()
{
    int arr[30], n, i;
    printf("Enter no. of elements in the array:");
    scanf("%d", &n);
    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);

	lims(arr, n);

	return 0;
}

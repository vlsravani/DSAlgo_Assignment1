#include <stdio.h>
#include <stdlib.h>

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

void kthSmallest(int arr[], int l, int r, int K, int N)
{
	// If k is smaller than number of elements in array
	if (K > 0 && K <= r - l + 1) {

		// Partition the array around last element and get
		// position of pivot element in sorted array
		int pos = partition(arr, l, r);

		// If position is same as k
		if (pos - l == K - 1)
			return;

		// If position is more, recur
		// for left subarray
		else if (pos - l > K - 1)
			return kthSmallest(arr, l, pos - 1, K, N);

		// Else recur for right subarray
		else
			return kthSmallest(arr, pos + 1, r,
							K - pos + l - 1, N);
	}

	// If k is more than number of elements in array
	printf("Invalid value of K");
}

void KthLargest(int arr[], int l, int r, int K, int N)
{
	// This function arranges k Largest elements in last k
	// positions It means it arranges N-K-1 smallest
	// elements from starting

	kthSmallest(arr, l, r, N - K - 1, N);
}

// Driver Code
int main()
{

	int arr[]
		= { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int N = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	// Function call

	// For Smallest
	kthSmallest(arr, 0, N - 1, k, N);

	// Print KSmallest no.
	if (k >= 1 && k <= N) {
		printf("%d smallest elements are : ", k);
		for (int i = 0; i < k; i++)
			printf("%d ", arr[i]);
	}
	printf("\n");

	// For Largest
	KthLargest(arr, 0, N - 1, k, N);

	// // Print KLargest no.
	if (k >= 1 && k <= N) {
		printf("%d largest elements are : ", k);
		for (int i = N - 1; i >= N - k; i--)
			printf("%d ", arr[i]);
	}
	return 0;
}

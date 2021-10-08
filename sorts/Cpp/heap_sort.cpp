/*
Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements.*/

/*
A complete binary tree/heap is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible
*/


// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int> &arr, int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(vector<int> &arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}


// Driver code
int main()
{
	int n;
cin>>n;

	vector<int> arr(n);

  	for (int i = 0; i < n; ++i)
        cin>>arr[i];

	heapSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

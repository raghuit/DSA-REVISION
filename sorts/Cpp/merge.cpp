#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void MergeSortedIntervals(vector<int>& arr, int s, int m, int e) {
	vector<int> temp;
	int i = s, j = m + 1;
	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) {
			temp.push_back(arr[i]);
			++i;
		}
		else {
			temp.push_back(arr[j]);
			++j;
		}
	}
	while (i <= m) {
		temp.push_back(arr[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(arr[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		arr[i] = temp[i - s];
}

void MergeSort(vector<int>& arr, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(arr, s, m);
		MergeSort(arr, m + 1, e);
		MergeSortedIntervals(arr, s, m, e);
	}
}

bool chechAlgo(vector<int> arr) {
    vector<int> temp;
    for (int x: arr)
        temp.push_back(x);
    MergeSort(arr, 0, arr.size() - 1);
    sort(temp.begin(), temp.end());
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != temp[i])
            return false;
    }
    return true;
}

int main() {
    vector<int> arr;
    for(int i = 0; i < 50; i++)
        arr.push_back(rand());
    cout << chechAlgo(arr) << "\n";
    MergeSort(arr, 0, arr.size() - 1);
    for (int x: arr) 
        cout << x << " ";
    cout << "\n";
    return 0;
}
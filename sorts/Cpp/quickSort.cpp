#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int Partition(vector<int> &v, int start, int end) {
	int pivot = end;
	int j = start;
	for(int i = start; i < end; ++i){
		if(v[i] < v[pivot]) {
			swap(v[i], v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
}

void Quicksort(vector<int> &v, int start, int end ) {
	if(start<end) {
		int p = Partition(v, start, end);
		Quicksort(v, start, p - 1);
		Quicksort(v, p + 1, end);
	}
}

bool chechAlgo(vector<int> arr) {
    vector<int> temp;
    for (int x: arr)
        temp.push_back(x);
    Quicksort(arr, 0, arr.size() - 1);
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
	Quicksort(arr, 0, arr.size() - 1);
    for (int x: arr)
        cout << x << " ";
    cout << "\n";
    return 0;
}
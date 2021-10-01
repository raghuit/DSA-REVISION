#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &arr) {
    int i, key, j, n = arr.size();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr;
    for(int i = 0; i < 50; i++)
        arr.push_back(rand());
    insertionSort(arr);
    for (int x: arr)
        cout << x << " ";
    cout << "\n";
    return 0;
}
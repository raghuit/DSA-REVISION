//This is not an efficient sorting algo as it has T.C. in all cases as O(n^2) but space complexity of O(1) but it is esy to understand for beginners.

//places where it can be used is to sort an array of strings lexicographically where input of strings is not large

/*this is not a stable sorting algo as it does not preserve the original position of two same elements with respect to each other.
But it can be made stable.
// It can also be used to check if input is already sorted or not // if it is almost sorted then slection sort will take ;less time compared to others.

/*THEREFORE I AM WRITING HERE STABLE SELECTION SORT:)*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> inp)
{
  int n=inp.size();

  for(int i=0;i<n-1;i++)
  {
    int min_idx=i;//assuming minimum index
    for(int j=i+1;j<n;j++)
    {
        if(inp[min_idx]>inp[j])
        {/*finding minimum number in rest un sorted array*/
          min_idx=j;
        }
    }

    int key=inp[min_idx];//preservving minimum element found in un sorted array

    while(min_idx>i)
    {
      inp[min_idx]=inp[min_idx-1];
      min_idx--;
      //shifting elements to right one by one and making space for minimum element( found) in starting
    }

    inp[min_idx]=key;//storing the minimum element in array


  }

    for (int i = 0; i < n; i++)
        cout << inp[i] << " ";
    cout<<"\n";

}
int main()
{
  ios_base::sync_with_stdio();
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cout<<"Enter the size of array:"<<"\n";
  cin>>n;
  vector<int> a(n);

  cout<<"Now enter the elements separated by space:"<<"\n";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }

  selection_sort(a);
}
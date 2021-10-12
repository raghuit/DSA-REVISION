PROBLEM STATEMENT:Allocate minimum number of pages

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. There can
be many ways or permutations to do so. In each permutation, one of 
the M students will be allocated the maximum number of pages. 
Out of all these permutations, the task is to find that particular 
permutation in which the maximum number of pages allocated to a 
student is minimum of those in all the other permutations and
print this minimum value. Each book will be allocated to 
exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and 
allotment should be in contiguous order.


CODE SOLUTION IN C++:

class Solution {
  public:
    bool solve(int arr[],int n,int mid,int m){
        int sum=0;
        int stu=1;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) return false;
            if(sum + arr[i] > mid){
                stu++;
                sum=arr[i];
                if(stu > m) return false;
            }
            else sum+= arr[i];
        }
        return true;
    }
        
    int findPages(int arr[], int n, int m) {
        int lb=0;
        int s=0; //sum of array elements
        int ans=0;
        for(int i=0;i<n;i++) s+= arr[i];
        int ub=s;
        while(lb<=ub){
            int mid=(lb+ub)/2;
            if(solve(arr,n,mid,m)){
                ans=mid;
                ub=mid-1;
            }
            else{
                lb=mid+1;
            }
            
        }
        return ans;
        
    }
};
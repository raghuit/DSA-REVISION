PROBLEM STATEMENT:Trapping Rain Water 

Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped 
between the blocks during the rainy season. 

CODE SOLUTION IN C++:

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int lmax[n];  lmax[0]=arr[0];
        for(int i=1;i<n;i++){
            int temp = max(arr[i],lmax[i-1]);
            lmax[i]=temp;
        }
        int rmax[n]; rmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            int temp = max(arr[i],rmax[i+1]);
            rmax[i]=temp;
        }
        
        int water=0;
        for(int i=1;i<n-1;i++){
            water=water + min(lmax[i],rmax[i])-arr[i];
        }
        
        
        return water;
    
        
        
    }
    
};
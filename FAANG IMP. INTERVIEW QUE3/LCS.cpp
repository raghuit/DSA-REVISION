PROBLEM STATEMENT: Longest Common Subsequence
Given two sequences, find the length of longest subsequence present in both of them. 
Both the strings are of uppercase.

LANGUAGE USED:C++
CODE SOLUTION:
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        
        int dp[2][y+1]; 
       
        for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 or j==0)
                dp[i%2][j] =0;
            else if(s1[i-1]==s2[j-1]){ 
                dp[i%2][j] = 1 + dp[(i+1)%2][j-1];
            }
            else{
                dp[i%2][j] = max(dp[i%2][j-1],dp[(i+1)%2][j]);
            }
        }
    }
    return dp[x%2][y];
    }
};
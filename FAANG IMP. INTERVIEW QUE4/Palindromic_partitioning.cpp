PROBLEM STATEMENT:Palindromic patitioning 
Given a string str, a partitioning of the string is a palindrome partitioning if 
every sub-string of the partition is a palindrome. Determine the fewest cuts needed 
for palindrome partitioning of given string.

CODE SOLUTION IN C++:
class Solution{
public:
bool check_palindrome(int st,int en,string str)
{
    while(en>st)
    {
        if(str[en]!=str[st])
        {
            return false;
        }
        st++;
        en--;
    }
    return true;
}

int dpsol(int st,string str,int dp[1000])
{
    int k=1000;
    if(dp[st]!=-1)
    {
        return dp[st];
    }
    for(int i=st;i<str.size();i++)
    {
        if(check_palindrome(st,i,str) )
        {
            if(i==str.size()-1)
            {
                k=0;
                dp[st]=0;
                return 0;
            }
            else
            {
                 k=min(k,1+dpsol(i+1,str,dp));
            }
        }
    }
    dp[st]=k;
    return k;
}
    int palindromicPartition(string str)
    {
         int dp[1000];
    for(int i=0;i<1000;i++)
    {
        dp[i]=-1;
    }
    return dpsol(0,str,dp);
    }
};
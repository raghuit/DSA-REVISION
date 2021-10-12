PROBLEM STATEMENT:Wildcard Pattern Matching 

Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,
You have to print '1' if the wildcard pattern is matched with str else print '0' .
The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)
Note: The matching should cover the entire str (not partial str).


CODE SOLUTION IN C++:

int dp[1001][1001];
int solve(string p,string s, int i,int j){
    if(i==-1 and j==-1) return 1;
    if(j==-1){
        for(int k=0;k<i;k++){
            if(p[k]!='*') return 0;
        }
        return 1;
    }
    if(i==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[i]==s[j] or p[i]=='?') return dp[i][j] = solve(p,s,i-1,j-1);
    if(p[i]=='*'){
        int op1= solve(p,s,i-1,j);
        int op2= solve(p,s,i,j-1);
        return dp[i][j] =op1 or op2;
        
    }
    return dp[i][j] =0;
}
int wildCard(string pattern,string str)
{
    
   int i= pattern.length()-1;
   int j= str.length()-1;
    memset(dp,-1,sizeof(dp));
    return solve(pattern,str,i,j);
    
}
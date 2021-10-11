PROBLEM STATEMENT:   Alien Dictionary (ASKED IN FAANG INTERVIEW QUESTIONS)

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language. Note: Many orders may be possible for a particular test 
case,thus you may return any valid order and output will be 1 if the order of string returned by the function 
is correct else 0 denoting incorrect string returned.

LANGUAGE USED : C++

CODE SOLUTION :
class Solution{
    public:
    void dfs(int src,vector<vector<int> > &g,vector<int> &vis,string &ans ){
        vis[src]=1;
        for(auto x: g[src]){
            if(!vis[x]){
                dfs(x,g,vis,ans);
            }
        }
        char ch = src + 'a';
        ans = ch+ ans;
    }
    string findOrder(string dict[], int N, int K) {
        vector<vector<int> > g(K);
        for(int i=0;i<N-1;i++){
            string w1 = dict[i];
            string w2 = dict[i+1];
            
            for(int j=0;j<min(w1.length(),w2.length());j++){
                if(w1[j]!=w2[j]){
                    g[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }
        }
    vector<int> vis(K,0);
    string ans= "";
    for(int i=0;i<K;i++){
        if(!vis[i]){
            dfs(i,g,vis,ans);
        }
    }
    return ans;
    }
    
   
};
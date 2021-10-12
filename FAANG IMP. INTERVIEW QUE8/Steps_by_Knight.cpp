PROBLEM STATEMENT:Steps_by_Knight

Given a square chessboard, the initial position of Knight and position of a target. 
Find out the minimum steps a Knight will take to reach the target position.
Note:The initial and the target position co-ordinates of 
Knight have been given accoring to 1-base indexing.


CODE SOLUTION IN C++:

class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    int a[1001][1001];
	    if(x1==x2 and y1==y2){
	        return 0;
	    }
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            a[i][j]=0;
	        }
	    }
	    
	    queue<pair<int,int>  > q;
	    q.push(make_pair(x1-1,y1-1));
	    while(!q.empty()){
	        auto cur = q.front();
	        int i = cur.first;
	        int j = cur.second;
	        q.pop();
	        
	            if((i+1)>=0 and (i+1)<N and (j+2)>=0 and (j+2)<N and a[i+1][j+2]==0){
	                a[i+1][j+2]=a[i][j]+1;
	                q.push(make_pair(i+1,j+2));
	            }
	            if((i-1)>=0 and (i-1)<N and (j+2)>=0 and (j+2)<N and a[i-1][j+2]==0){
	                a[i-1][j+2]=a[i][j]+1;
	                q.push(make_pair(i-1,j+2));
	            }
	            if((i-2)>=0 and (i-2)<N and (j+1)>=0 and (j+1)<N and a[i-2][j+1]==0){
	                a[i-2][j+1]=a[i][j]+1;
	                q.push(make_pair(i-2,j+1));
	            }
	            if((i+2)>=0 and (i+2)<N and (j+1)>=0 and (j+1)<N and a[i+2][j+1]==0){
	                a[i+2][j+1]=a[i][j]+1;
	                q.push(make_pair(i+2,j+1));
	            }
	            if((i-1)>=0 and (i-1)<N and (j-2)>=0 and (j-2)<N and a[i-1][j-2]==0){
	                a[i-1][j-2]=a[i][j]+1;
	                q.push(make_pair(i-1,j-2));
	            }
	            if((i+1)>=0 and (i+1)<N and (j-2)>=0 and (j-2)<N and a[i+1][j-2]==0){
	                a[i+1][j-2]=a[i][j]+1;
	                q.push(make_pair(i+1,j-2));
	            }
	            if((i-2)>=0 and (i-2)<N and (j-1)>=0 and (j-1)<N and a[i-2][j-1]==0){
	                a[i-2][j-1]=a[i][j]+1;
	                q.push(make_pair(i-2,j-1));
	            }
	            if((i+2)>=0 and (i+2)<N and (j-1)>=0 and (j-1)<N and a[i+2][j-1]==0){
	                a[i+2][j-1]=a[i][j]+1;
	                q.push(make_pair(i+2,j-1));
	            }
	    }
	    return a[x2-1][y2-1]; // que is 1 based index so minus to make 0 based index
	    
	    
	}
};
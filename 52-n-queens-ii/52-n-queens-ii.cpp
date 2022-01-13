class Solution {
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&left,vector<int>&up,vector<int>&down){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && up[n-1+(col-row)]==0 && down[row+col]==0){
                board[row][col]='Q';
                left[row]=1;
                up[n-1+col-row]=1;
                down[row+col]=1;
                solve(col+1,board,ans,n,left,up,down);
                board[row][col]='.';
                left[row]=0;
                up[n-1+col-row]=0;
                down[row+col]=0;
            }
        }
    }
    int totalNQueens(int n) {
       vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        
        vector<int>left(n,0);
        vector<int>up((2*n-1),0);
        vector<int>down((2*n-1),0);
        solve(0,board,ans,n,left,up,down);
        return ans.size(); 
    }
};
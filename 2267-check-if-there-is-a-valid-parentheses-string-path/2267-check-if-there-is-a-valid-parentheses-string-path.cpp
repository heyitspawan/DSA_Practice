class Solution {
public:
    bool sol(int i, int j, int c,vector<vector<char>>& grid,vector<vector<vector<int>>>&dp) {
        int n = grid.size();
        int m = grid[0].size();
         if(grid[i][j]=='('){
            c++;
         }
         else{
            c--;
         }
         if(c<0){
            return false;
         }
       
         if(i==n-1&&j==m-1){
            if(c==0){
                return true;
            }else{
                return false;
            }
          }
        if(dp[i][j][c]!=-1){
            return dp[i][j][c];
        }
          bool right=false;
          if(j+1<m){
            right=sol(i,j+1,c,grid, dp);
          }
          bool down=false;
          if(i+1<n){
            down=sol(i+1,j,c,grid,dp);
          }
          return dp[i][j][c]= right||down;
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       // stack<char> st;
        // if((m+n)%2==0){
        //     return false;
        // }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m, vector<int>(m+n+1,-1)));
        bool res = sol(0, 0,0, grid,dp);
        return res;
    }
};
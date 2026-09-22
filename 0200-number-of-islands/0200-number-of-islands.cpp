class Solution {
private:
    void bfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 1;
         int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while (!q.empty()) {
            int oi = q.front().first;
            int oj=q.front().second;
            q.pop();
            int dr[]={0,-1,0,+1};
            int dc[]={-1,0,+1,0};
            for(int k=0;k<4;k++){
                int ni=oi+dr[k];
                int nj=oj+dc[k];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]=='1'&&vis[ni][nj]!=1){
                    vis[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
           
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<int> adj[n];
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (grid[i][j] == '1') {
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        vector<vector<int>> vis(n, vector<int>(m,-1));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for(int j=0;j<m;j++){

            
            if (vis[i][j] == -1 && grid[i][j]=='1') {
                res++;
                bfs(i, j,grid, vis);
            }
        }}
        return res;
    }

}
;
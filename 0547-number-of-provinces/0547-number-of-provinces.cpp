class Solution {
    private:
     void bfs(int i,vector<int> adj[],vector<int>&vis){
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
     }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,-1);
        int res=0;
        for(int i=0;i<n;i++){
           if(vis[i]==-1){
            res++;
            bfs(i,adj,vis);
           }
        }
        return res;
    }
};
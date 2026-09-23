class Solution {
    private:
    int dfs(int i,int p,vector<int>adjls[], vector<int>& vis){
        vis[i]=1;
        int c=0;
        for(auto it :adjls[i]){
            if(vis[it]!=1){
             c+=dfs(it,i,adjls,vis);
            }else{
                 if(it!=p){
                c++;
            } 
            }
         
        }
        return c;
    }
public:
    int makeConnected(int n, vector<vector<int>>& cm) {
        int c=0;
        vector<int>adjls[n];
        for(int i=0;i<cm.size();i++){
            adjls[cm[i][0]].push_back(cm[i][1]);
            adjls[cm[i][1]].push_back(cm[i][0]);
        }
        vector<int>vis(n,0);
        int l=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                c++;
                l+=dfs(i,-1,adjls,vis);
            }
        }
        if(c<=l){
            return c-1;
        }else if(c==1){
            return 0;
        } else return -1;
    }
};
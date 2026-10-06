class Solution {
public:
    int solve(vector<vector<int>>& m, int pre, int i, vector<vector<int>>& dp) {
        if (i >= m.size()) {
            return 0;
        }
        if (dp[i][pre + 1] != -1) {
            return dp[i][pre + 1];
        }
        if (pre == -1 || m[i][0] >= m[pre][1]) {
            int pick = m[i][2] + solve(m, i, i + 1, dp);
          
            int  npick = solve(m, pre, i + 1, dp);
            return dp[i][pre + 1] = max(pick, npick);
        } else {
            return dp[i][pre + 1] = solve(m, pre, i + 1, dp);
        }
    }

    int binarysearch(vector<vector<int>>&m,int i){
        int l=0;
        int r=i-1;
        int res=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(m[mid][0]<=m[i][1]){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<vector<int>> m;
        for (int i = 0; i < startTime.size(); i++) {
            m.push_back({endTime[i],startTime[i], profit[i]});
        }
        sort(m.begin(), m.end());
        int n=m.size();
        vector<int>dp(n,-1);
    
        dp[0]=m[0][2];
        for(int i=1;i<n;i++){
            int ind=binarysearch(m,i);
     
              if(ind!=-1){
                dp[i]=max(m[i][2]+dp[ind],dp[i-1]);
              }else{
                dp[i]=max(dp[i-1],m[i][2]);
              }
        }
        return dp[n-1];
    }
};
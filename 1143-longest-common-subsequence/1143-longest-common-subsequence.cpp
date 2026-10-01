class Solution {
public:
    int sol(int i, int j, string& s, string& t,vector<vector<int>>& dp) {
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            int res = 0;
            if (i + 1 < s.size() && j + 1 < t.size()) {
                res = sol(i + 1, j + 1, s, t,dp);
            }
            return dp[i][j]= 1 + res;
        }
        int a = 0;
        if (i + 1 < s.size()) {
            a = sol(i + 1, j, s, t,dp);
        }
        int b = 0;
        if (j + 1 < t.size()) {
            b = sol(i, j + 1, s, t,dp);
        }
        return dp[i][j]=max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return sol(0, 0, text1, text2,dp);
    }
};
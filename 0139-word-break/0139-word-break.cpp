class Solution {
public:
    bool sol(int ind,string s, unordered_set<string>& st,vector<int>&dp){
        if(ind==s.size()){
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        string t="";
        for(int i=ind;i<s.size();i++){
            t+=s[i];
            if(st.find(t)!=st.end()){
                if(sol(i+1,s,st,dp)){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(n,-1);
        return sol(0,s,st,dp);
    }
};
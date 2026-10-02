class Solution {
public:
    int sol(string s, map<string,char>& mp, int i, vector<int>&dp) {
        if (i == s.size()) {
            return 1;
        }
        if(i>s.size()){
            return 0;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        string t={s[i]};
        int res = 0;
        if (mp.find(t) != mp.end()) {
            res += sol(s, mp, i + 1,dp);
        }
        if (i + 1 < s.size()) {
            t += s[i + 1];
            if (mp.find(t) != mp.end()) {
                res += sol(s, mp, i + 2,dp);
            }
        }
        return dp[i]=res;
    }
    int numDecodings(string s) {
        map<string,char > mp;
        int j = 1;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            mp[to_string(j)] = ch;
            j++;
        }
        vector<int>dp(s.size(),-1);
        return sol(s, mp, 0,dp);
    }
};
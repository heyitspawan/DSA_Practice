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
        int n=s.size();
        int pre2=0;
        int pre1=1;
        //int c;
        if(n==1){
            if(s[0]!='0')
            return 1;
            else return 0;
        }
         for (int i = n - 1; i >= 0; i--) {
            int result{0};
            if (s[i] != '0') result += pre1;
            if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) result += pre2;
            pre2=pre1;
            pre1=result;
          
        }
        return pre1;
        // map<string,char > mp;
        // int j = 1;
        // for (char ch = 'A'; ch <= 'Z'; ch++) {
        //     mp[to_string(j)] = ch;
        //     j++;
        // }
        // vector<int>dp(s.size(),-1);
        // return sol(s, mp, 0,dp);

    }
};
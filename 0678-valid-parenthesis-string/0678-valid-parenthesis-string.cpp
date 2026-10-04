class Solution {
public:
bool sol(string &s, int i, int c,vector<vector<int>>&dp){
        if(c<0){
        return false;
        }
         if(c==0 && i==s.size()){
            return true;
         }
         if(i==s.size()&&c!=0){
            return false;
         }
         if(dp[i][c]!=-1){
            return dp[i][c];
         }
         if(s[i]=='('){
           return dp[i][c]=sol(s,i+1,c+1,dp);
         }else if(s[i]==')'){
            return dp[i][c]=sol(s,i+1,c-1,dp);
         }else{
            return dp[i][c]=( sol(s,i+1,c+1,dp)||
             sol(s,i+1,c,dp)||
              sol(s,i+1,c-1,dp));
         }
}
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
       return sol(s,0,0,dp);
    }
};
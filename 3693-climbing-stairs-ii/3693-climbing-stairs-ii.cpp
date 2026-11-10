class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<long long >res(n+1,0);
    
        res[1]=cost[0]+1;
        if(n==1){
            return res[1];
        }
        res[2]=min(res[1]+cost[1]+1,res[0]+cost[1]+4);
        if(n==2){
            return res[2];
        }
        res[3]=cost[2]+min({res[2]+1,res[1]+4,res[0]+9});
        if(n==3){
            return res[3];
        }
        for(int i=4;i<=n;i++){
            res[i]=cost[i-1]+min({res[i-1]+1,res[i-2]+4,res[i-3]+9});
        }
         return (int)res[n]; 
    }
};
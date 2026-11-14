class Solution {
public:
    long long sol(int x,int cost1, int cost2, int costBoth, int need1, int need2){
        long long cost=(long long)x*costBoth+(long long)max(0,(need1-x))*cost1+(long long)max(0,(need2-x))*cost2;
        return cost;
    }
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res=LLONG_MAX;
        int x1=0;
        int x2=min(need1,need2);
        int x3=max(need1,need2);
        res=min(res,sol(x1,cost1,cost2,costBoth,need1,need2)); 
        res=min(res,sol(x2,cost1,cost2,costBoth,need1,need2));
        res=min(res,sol(x3,cost1,cost2,costBoth,need1,need2));
        return res;

    }
};
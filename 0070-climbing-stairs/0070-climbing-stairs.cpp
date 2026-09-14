class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2) return n;
        int pre=1;
        int c=2;
        for(int i=2;i<n;i++){
            int t=c+pre;
            pre=c;
            c=t;
        }
        return c;
    }
};
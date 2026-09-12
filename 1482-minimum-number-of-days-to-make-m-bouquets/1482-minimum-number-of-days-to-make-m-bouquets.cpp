class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int r = INT_MIN;
        int ans;
        for (int i = 0; i < bloomDay.size(); i++) {
            r = max(bloomDay[i], r);
        }
        int l = 1;
        if (bloomDay.size() <(long long) m * k)
            return -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int c = 0;
            int res = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    c++;
                    if (c == k) {
                        res++;
                        c=0;
                    }
                } else {
                    c = 0;
                }
            }
            if(res>=m){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
           
        }
        return ans;
    }
};
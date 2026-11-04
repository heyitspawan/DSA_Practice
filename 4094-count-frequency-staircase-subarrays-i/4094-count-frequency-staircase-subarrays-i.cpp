class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(100001, 0);
        vector<int> targ(100001, 0);
        int ans = 0;
        vector<int> v;
       // v.reserve(320);
        for (int i = 0; i < n; i++) {
            v.clear();
            int b = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (mp[x] == 0) {
                    v.push_back(x);
                    int d = v.size();
                 
                    if (i + d * (d + 1) / 2 > n) {
                        break;
                    }
                       targ[x]=d;
                }
                mp[x]++;
                if (mp[x] == targ[x]) {
                    b++;
                } else if (mp[x] > targ[x]) {
                    break;
                }
                int d = v.size();
                int l = j - i + 1;
                if (l == d * (d + 1) / 2 && b == d) {
                    ans++;
                }
            }
            for(int x:v){
                mp[x]=0;
            }
        }
        return ans;
    }
};
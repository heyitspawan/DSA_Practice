class Solution {
public:
    bool check(vector<int>& nums, int i, int j, map<int, int>& mp) {
        unordered_set<int> c;

        for (int k = j; k < i; k++) {
            int d = nums[i] - nums[k];
            int s = nums[i] + nums[k];

            if (mp.find(s) != mp.end()) {
                return true;
            }

            if (c.find(nums[k]) != c.end()) {
                return true;
            }

            c.insert(d);
        }

        return false;
    }

    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int res = 0;
        int j = 0;

        map<int, int> mp;

        for (int i = 0; i < n; i++) {

            while (j < i && check(nums, i, j, mp)) {
                mp[nums[j]]--;

                if (mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                }

                j++;
            }

            mp[nums[i]]++;

            res = max(res, i - j + 1);
        }

        return res;
    }
};
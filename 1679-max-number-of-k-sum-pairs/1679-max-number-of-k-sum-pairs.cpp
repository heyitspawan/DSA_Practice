class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                mp[nums[i]]++;
            }
        }
        for (auto [i, v] : mp) {
            int a = i;
            if ((k - a) == a) {
                count += (v) / 2;
                mp[i] = 0;
            } else {
                if (mp.find(k - a) != mp.end()) {
                    count += min(mp[a], mp[k - a]);
                    mp[i] = 0;
                    mp[k - i] = 0;
                }
            }
        }

        return count;
    }
};
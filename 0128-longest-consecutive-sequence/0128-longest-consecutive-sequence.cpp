class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        for (auto i = mp.begin(); i!= mp.end(); i++) {
            int j = i->first;
            //int k=j-1;
            if (!mp.count(j-1)) {
                int c = 0;
                while (mp.count(j)) {
                    c++;
                    j++;
                }
              mx=max(mx,c);
            }
        }
        return mx;
    }
};
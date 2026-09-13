class Solution {
public:
    bool check(int capacity, vector<int>& nums, int days) {
        int usedDays = 1;
        int sum = 0;

        for (int weight : nums) {
            if (sum + weight <= capacity) {
                sum += weight;
            } else {
                usedDays++;
                sum = weight;
            }
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());

        int r = 0;
        for (int weight : weights) {
            r += weight;
        }

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, weights, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

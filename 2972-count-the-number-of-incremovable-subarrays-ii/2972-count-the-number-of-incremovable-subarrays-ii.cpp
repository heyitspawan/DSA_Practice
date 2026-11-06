class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& arr) {
        int n = arr.size();

        // 1. Find the starting index of the longest strictly increasing suffix
        int suffix = n - 1;
        while (suffix > 0 && arr[suffix - 1] < arr[suffix]) {
            suffix--;
        }

        // If the whole array is strictly increasing
        if (suffix == 0) {
            return 1LL * n * (n + 1) / 2;
        }

        // 2. Find the ending index of the longest strictly increasing prefix
        int prefix = 0;
        while (prefix < n - 1 && arr[prefix] < arr[prefix + 1]) {
            prefix++;
        }

        // 3. Case 1: Keep no elements from prefix (remove everything before suffix)
        long long ans = n - suffix + 1;

        // 4. Case 2: Two-pointer check to join prefix arr[0...i] with suffix arr[j...n-1]
        int j = suffix;
        for (int i = 0; i <= prefix; i++) {
            while (j < n && arr[i] >= arr[j]) {
                j++;
            }
            ans += (n - j + 1);
        }

        return ans;
    }
};
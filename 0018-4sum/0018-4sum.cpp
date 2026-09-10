class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> result;
        vector<vector<int>> res;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        if (nums[0] > target && nums[0] > 0) {
            return res;
        }
        for (int i = 0; i < n - 3; i++) {
            // while ( i + 1 < n - 3 && nums[i] == nums[i + 1] ) {
            //     i++;
        
            // }
            for (int j = i + 1; j < n - 2; j++) {
                // while ( j + 1 < n - 2&&nums[j] == nums[j + 1] ) {
                //     j++;
                    
                // }

                for (int k = j + 1; k < n - 1; ++k) {
                    // while (k + 1 < n - 1&&nums[k] == nums[k + 1]  ) {
                    //     k++;
                        
                    // }
                    for (int l = k + 1; l < n; ++l) {
                        while ( l + 1 < n&&nums[l] == nums[l + 1] ) {
                            l++;
                            continue;
                        }
                        if ((long long)nums[i] + (long long)nums[j] +
                                (long long)nums[k] + (long long)nums[l] ==
                            target) {
                            result.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        for (auto it : result) {
            res.push_back(it);
        }
        //    for(int k=0;k<n-3;k++){
        //     for (int i = k+1; i < n - 2; ++i) {
        //         // Step 2: Skip duplicates for the fixed element
        //         if (i > 0 && nums[i] == nums[i - 1]) continue;

        //         // // Early exit if the smallest element is > 0
        //         // if (nums[i] > 0) break;

        //         int left = i + 1;
        //         int right = n - 1;

        //         while (left < right) {
        //             int sum = nums[k]+nums[i] + nums[left] + nums[right];

        //             if (sum == target) {
        //                 result.push_back({nums[k],nums[i], nums[left],
        //                 nums[right]});

        //                 // Skip duplicates for the left and right
        //                 pointers while (left < right && nums[left] ==
        //                 nums[left + 1]) left++; while (left < right &&
        //                 nums[right] == nums[right - 1]) right--;

        //                 left++;
        //                 right--;
        //             } else if (sum < target) {
        //                 left++; // Need a larger sum
        //             } else {
        //                 right--; // Need a smaller sum
        //             }
        //         }
        //     }}

        return res;
    }
};
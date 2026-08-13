class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int >a;
        int s=nums.size();
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
               int v=nums[i]+nums[j];
               if(v==target)
               {a.push_back(i);
               a.push_back(j);
              }
            }
        }
    return a; }
};
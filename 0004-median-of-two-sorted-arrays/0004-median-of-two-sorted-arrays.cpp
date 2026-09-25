class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> s;
        for(int i=0;i<n;i++){
            s.push_back(nums1[i]);
            }
         for(int i=0;i<m;i++){
            s.push_back(nums2[i]);
            }
           
            sort(s.begin(),s.end());
     
        
      int p=s.size();  
        
        return p%2?s[p/2]:(s[p/2-1]+s[p/2])/2.0;
        
    }
};
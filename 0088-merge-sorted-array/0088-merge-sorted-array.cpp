class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> p;
        vector<int> q;
         for(int i=0;i<m;i++){
                   p.push_back(nums1[i]);}
        for(int i=0;i<n;i++){
                   q.push_back(nums2[i]);}
         for(int i=0;i<q.size();i++){
                   p.push_back(q[i]);}
         sort(p.begin(),p.end());
        for(int i=0;i<nums1.size();i++){
                  nums1.clear();}
        for(int i=0;i<p.size();i++){
                   nums1.push_back(p[i]);}
    }
};
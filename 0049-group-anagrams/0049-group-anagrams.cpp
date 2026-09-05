class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};// here we used hash map so that we look the word fast in the map 
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res={{strs[0]}};

//         for (int i = 1; i < strs.size(); i++) {
//             int flag=0;
//             string s = strs[i];
//             sort(s.begin(),s.end());
//             for (int j = 0; j < res.size(); j++) {
//                 string t = res[j][0];
//                 if(t.size()==s.size()){
//                 sort(t.begin(), t.end());
//                 if (s == t)
//                  {   res[j].push_back(strs[i]);
//                  flag=1;
//                     break;}}
//             }
//             if(flag==0){
//                 res.push_back({strs[i]});
//               //  c++;
//             }
//         }
//         return res;
//     }
// };